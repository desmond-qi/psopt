#include "psopt.h"
#include <RobotConf.h>
#include <DataProcess.h>

using namespace PSOPT;
using namespace qhx;

Robot JumpRobot;
DataProcess JumpData;

void oe2rv(MatrixXd& oe, double mu, MatrixXd* ri, MatrixXd* vi);

void rv2oe(adouble* rv, adouble* vv, double mu, adouble* oe);

struct Constants {
  MatrixXd* omega_matrix;
  double mu;
  double cd;
  double sa;
  double rho0;
  double H;
  double Re;
  double g0;
  double thrust_srb;
  double thrust_first;
  double thrust_second;
  double ISP_srb;
  double ISP_first;
  double ISP_second;
};

typedef struct Constants Constants_;

adouble endpoint_cost(adouble* initial_states, adouble* final_states,
                      adouble* parameters,adouble& t0, adouble& tf,
                      adouble* xad, int iphase, Workspace* workspace)
{
    adouble retval = 1.0/tf;

    return retval;
}

adouble integrand_cost(adouble* states, adouble* controls, adouble* parameters,
                     adouble& time, adouble* xad, int iphase, Workspace* workspace)

{
    adouble L1, L2;
    adouble u;
    adouble L;

    JumpRobot.GetState(states);
    
    double t = time.getValue();
    int seq = floor(t/JumpRobot.CycTime);
    L1.setValue(JumpRobot.m_sState.Ir[1] - JumpData.m_sTraj.JumpTraj[5][seq]); //！轨迹的序号
    L2.setValue((JumpRobot.m_sState.Ir[1] - JumpRobot.m_sState.Ir_Old[1])/(t - JumpRobot.m_dTime_Old));
    for (int i = 0; i < TOF; i++) u += controls[i]*controls[i];
    
    JumpRobot.m_dTime_Old = t;
    JumpRobot.m_sState.Ir_Old[1] = JumpRobot.m_sState.Ir[1];

    L = 1e6*L1*L1 + 1e4*L2*L2 + u;

    return  L;
}

void dae(adouble* derivatives, adouble* path, adouble* states,
         adouble* controls, adouble* parameters, adouble& time,
         adouble* xad, int iphase, Workspace* workspace)
{
    for (int i = 0; i < TOF; i++)
    {
        derivatives[i] = states[TOF+i];
        derivatives[TOF+i] = states[2*TOF+i];
        derivatives[2*TOF+i] = controls[i];
    }

    adouble *Dyn;
    JumpRobot.GetState(states);
    Dyn = JumpRobot.Calcu_FloatDyn();

    path[0] = Dyn[0]; path[1] = Dyn[1]; path[2] = Dyn[2];
    path[3] = states[4] - states[7];
    path[4] = states[5] - states[8];
    path[5] = states[6] - states[9];
    path[6] = states[10] - states[11];
}

void events(adouble* e, adouble* initial_states, adouble* final_states,
            adouble* parameters,adouble& t0, adouble& tf, adouble* xad,
            int iphase, Workspace* workspace)
{

}

void linkages( adouble* linkages, adouble* xad, Workspace* workspace)
{

}

int main(void)
{
    Alg  algorithm;
    Sol  solution;
    Prob problem;

    JumpData.ReadJointTraj();
    JumpData.ReadJumpTraj();
    
    problem.name                = "AirOpt";
    problem.outfilename         = "AirOpt.txt";

    // Constants_ CONSTAINS;

    // problem.user_data = (void*) &CONSTAINS;

    problem.nphases   = 1;
    problem.nlinkages = 0;

    psopt_level1_setup(problem);

    problem.phases(1).nstates   = 3*TOF;
    problem.phases(1).ncontrols = TOF;
    problem.phases(1).nevents   = 0;
    problem.phases(1).npath     = 7;
    problem.phases(1).nodes     << 100;

    psopt_level2_setup(problem, algorithm);

    double JumpHeight = 0.5;
    double JumpVelocity = sqrt(2*9.8*JumpHeight);    
    Eigen::Matrix <double, TOF, 1> q_max, q_min, dq_max, dq_min, ddq_max, ddq_min, dddq_max, dddq_min;
    q_max << 5.0, 3.4,  60.0*D2R,    .0*D2R, 110.0*D2R,  50.0*D2R-90.0*D2R,    .0*D2R, 110.0*D2R,  50.0*D2R-90.0*D2R,     .0*D2R,     .0*D2R;
    q_min << 0.0, 0.4, -20.0*D2R, -95.0*D2R,  10.0*D2R, -55.0*D2R-90.0*D2R, -95.0*D2R,  10.0*D2R, -55.0*D2R-90.0*D2R, -140.0*D2R, -140.0*D2R;
    dq_max <<  100.0,  100.0,  100.0,  20.0,  20.0,  50.0,  20.0,  20.0,  50.0,  20.0,  20.0;
    dq_min << -100.0, -100.0, -100.0, -20.0, -20.0, -50.0, -20.0, -20.0, -50.0, -20.0, -20.0;
    ddq_max <<  5e3,  5e3,  5e3,  5e3,  5e3,  5e3,  5e3,  5e3,  5e3,  5e3,  5e3;
    ddq_min << -5e3, -5e3, -5e3, -5e3, -5e3, -5e3, -5e3, -5e3, -5e3, -5e3, -5e3;
    dddq_max <<  1e5,  1e5,  1e5,  1e5,  1e5,  1e5,  1e5,  1e5,  1e5,  1e5,  1e5;
    dddq_min << -1e5, -1e5, -1e5, -1e5, -1e5, -1e5, -1e5, -1e5, -1e5, -1e5, -1e5;

    double t0 = .0, tf = 1.5;

    problem.phases(1).bounds.lower.states.block(    0, 0, TOF, 1) = q_min;
    problem.phases(1).bounds.lower.states.block(  TOF, 0, TOF, 1) = dq_min;
    problem.phases(1).bounds.lower.states.block(2*TOF, 0, TOF, 1) = ddq_min;
    problem.phases(1).bounds.upper.states.block(    0, 0, TOF, 1) = q_max;
    problem.phases(1).bounds.upper.states.block(  TOF, 0, TOF, 1) = dq_max;
    problem.phases(1).bounds.upper.states.block(2*TOF, 0, TOF, 1) = ddq_max;

    problem.phases(1).bounds.lower.controls = dddq_min;
    problem.phases(1).bounds.upper.controls = dddq_max;

    problem.phases(1).bounds.lower.StartTime = t0;
    problem.phases(1).bounds.upper.StartTime = t0;

    problem.phases(1).bounds.lower.EndTime   = t0;
    problem.phases(1).bounds.upper.EndTime   = tf;

    problem.integrand_cost = &integrand_cost;
    problem.endpoint_cost  = &endpoint_cost;
    problem.dae            = &dae;
    problem.events         = &events;
    problem.linkages       = &linkages;

    #pragma region --------------------Guess--------------------------------
    MatrixXd state_guess(3,2), control_guess(1,2), param_guess, time_guess(1,2);
   
    // state_guess  << CoM_init, CoM_init,
    //                 dCoM_init, dCoM_term,
    //                 ddCoM_init, ddCoM_term;
    // control_guess << 0.0, 0.0; 
    // time_guess << 0.0, 0.1;

    auto_phase_guess(problem, control_guess, state_guess, param_guess, time_guess);
    #pragma endregion

    #pragma region ------------------Algorithm Option------------------------
    algorithm.nlp_iter_max      = 1000;
    algorithm.nlp_tolerance     = 1.e-4;
    algorithm.nlp_method        = "IPOPT";
    algorithm.scaling           = "automatic";
    algorithm.derivatives       = "automatic";
    algorithm.defect_scaling    = "jacobian-based";
//    algorithm.collocation_method         = "trapezoidal";
//    algorithm.mesh_refinement            = "automatic";
//    algorithm.ode_tolerance              = 1.e-5	;
//    algorithm.mr_max_iterations          = 3;
    #pragma endregion

    psopt(solution, problem, algorithm);

    MatrixXd x, u, t, xi, ui, ti;
    x = solution.get_states_in_phase(1);
    u = solution.get_controls_in_phase(1);
    t = solution.get_time_in_phase(1);

    Save(x, "x.dat");
    Save(u, "u.dat");
    Save(t, "t.dat");

    plot(t,x.row(0),problem.name,"time (s)","x");
}

