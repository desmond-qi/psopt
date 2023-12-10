#pragma once
#ifndef ROBOTCONF_
#define ROBOTCONF_

#include <adolc/adouble.h>
#include <math.h>
#include "Base.h"

extern "C"
{
    #include "SDFast/sdfastdefs.h"
}

namespace qhx{
class Robot
{
private:
    double m_q[TOF], m_dq[TOF], m_ddq[TOF];

public:
    struct RobotState
    {
        double MTOT, CoMPos[3], CoMAng[3], ICoM[3][3], AMom[3], LMom[3], Ir[3], Iw[3], dIr[3], Ir_Old[3];
        double JointAng[TOF], JointVel[TOF];
        double M[TOF][TOF], H[TOF];
        double AM_Matrix[3][TOF], dAM_Matrix[3][TOF], AM_Matrix_Old[3][TOF];
        double Ir_Matrix[3][TOF], dIr_Matrix[3][TOF], Ir_Matrix_Old[3][TOF];
    }m_sState;
    double CycTime;
    double m_dTime_Old;

    Robot();
    ~Robot();

    void GetState(adouble *state);
    void arr2ssm(double Input[3], double Output[3][3]);
    double Calcu_NumPartDeriv(double f_plus, double f_minus, double delt_q);
    void Calcu_IR_Jaco();
    void Calcu_AngMom_Jaco();
    adouble *Calcu_FloatDyn();

};
}

#endif