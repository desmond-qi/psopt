#include <vector>
#include <string.h>
#include <RobotConf.h>
#include <Tools.hpp>

namespace qhx{
Robot::Robot()
{
	m_sState.Iw[1] = 1.4; //！固有惯量的值
	m_dTime_Old = .0;
	CycTime = 0.001;
    sdinit();
}

Robot::~Robot()
{

}

double Robot::Calcu_NumPartDeriv(double f_plus, double f_minus, double delt_q)
{
	double Output;
	Output = (f_plus - f_minus) / (2.0 * delt_q);

	return Output;
}

void Robot::GetState(adouble *state)
{
	for (int i = 0; i < TOF; i++)
	{
		m_q[i] = state[i].getValue();
		m_dq[i] = state[TOF+i].getValue();
		m_ddq[i] = state[2*TOF+i].getValue();
	}
    sdstate(.0, m_q, m_dq);
    sdsys(&m_sState.MTOT, m_sState.CoMPos, m_sState.ICoM);  
    sdfrcmat(m_sState.H);
    sdmassmat(m_sState.M);
	for (int i = 0; i < 3; i++) m_sState.Ir[i] = m_sState.ICoM[i][i] - m_sState.Iw[i];
}

void Robot::GetState(VectorXd state)
{
	for (int i = 0; i < TOF; i++)
	{
		m_q[i] = state(i);
		m_dq[i] = state(i+TOF);
		m_ddq[i] = state(i+2*TOF);
	}
    sdstate(.0, m_q, m_dq);
    sdsys(&m_sState.MTOT, m_sState.CoMPos, m_sState.ICoM);  
    sdfrcmat(m_sState.H);
    sdmassmat(m_sState.M);
	for (int i = 0; i < 3; i++) m_sState.Ir[i] = m_sState.ICoM[i][i] - m_sState.Iw[i];
}

void Robot::GetState(VectorXd state, MatrixXd &Ir, int Counter)
{
	Ir.resize(Counter+1, 3);
	for (int i = 0; i < TOF; i++)
	{
		m_q[i] = state(i);
		m_dq[i] = state(i+TOF);
		m_ddq[i] = state(i+2*TOF);
	}
    sdstate(.0, m_q, m_dq);
    sdsys(&m_sState.MTOT, m_sState.CoMPos, m_sState.ICoM);  
    sdfrcmat(m_sState.H);
    sdmassmat(m_sState.M);
	for (int i = 0; i < 3; i++) Ir(Counter, i) = m_sState.ICoM[i][i] - m_sState.Iw[i];
}

void Robot::Calcu_IR_Jaco()
{
	double q_Err[TOF], pt[3] = { .0 }, MTOT_, ICom_plus[3][3], ICom_minus[3][3];
	double BodyComPos_plus[NOL][3], BodyComPos_minus[NOL][3];
	double deltR_plus[3], deltR_minus[3];
	double ComPos_plus[3], ComPos_minus[3];
	int handle[NOL] = { Trunk, RThigh, RCalf, RFoot, LThigh, LCalf, LFoot, RArm, LArm };

	memcpy(q_Err, m_sState.JointAng, sizeof(q_Err));
	for (int i = 0; i < TOF; i++)
	{
		q_Err[i] += 1e-5;
		sdstate(0, q_Err, m_sState.JointVel);
		sdsys(&MTOT_, ComPos_plus, ICom_plus);
		q_Err[i] -= 2e-5;
		sdstate(0, q_Err, m_sState.JointVel);
		sdsys(&MTOT_, ComPos_minus, ICom_minus);
		m_sState.Ir_Matrix[1][i] = Calcu_NumPartDeriv(ICom_plus[1][1], ICom_minus[1][1], 1e-5);
		q_Err[i] += 1e-5;
	}
}

void Robot::Calcu_AngMom_Jaco()
{
	double dq_Err[TOF];
	double LMom_plus[3], AMom_plus[3], LMom_minus[3], AMom_minus[3], KEom;
	memcpy(dq_Err, m_sState.JointVel, sizeof(dq_Err));
	for (int i = 0; i < TOF; i++)
	{
		dq_Err[i] += 1e-5;
		sdstate(0, m_sState.JointAng, dq_Err);
		sdmom(LMom_plus, AMom_plus, &KEom);
		dq_Err[i] -= 2e-5;
		sdstate(0, m_sState.JointAng, dq_Err);
		sdmom(LMom_minus, AMom_minus, &KEom);
		for (int j = 0; j < 3; j++) m_sState.AM_Matrix[j][i] = Calcu_NumPartDeriv(AMom_plus[j], AMom_minus[j], 1e-5);
		dq_Err[i] += 1e-5;
	}
}

void Robot::Calcu_FloatDyn(double Dyn[3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < TOF; j++) Dyn[i] += m_sState.M[i][j]*m_ddq[j];
		Dyn[i] -= m_sState.H[i];
	}
}

void Robot::Calcu_FloatDyn(MatrixXd &Dyn, int Counter)
{
	Dyn.resize(Counter+1, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < TOF; j++) Dyn(Counter, i) += m_sState.M[i][j]*m_ddq[j];
		Dyn(Counter, i) -= m_sState.H[i];
	}
}

    
}
