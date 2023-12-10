#include "psopt.h"

using namespace PSOPT;

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
    adouble x1 = states[2];
    adouble u  = controls[0];
    adouble L;

    L = x1*x1 + u*u;

    return  L;
}

void dae(adouble* derivatives, adouble* path, adouble* states,
         adouble* controls, adouble* parameters, adouble& time,
         adouble* xad, int iphase, Workspace* workspace)
{
    adouble* x = states;
    adouble* u = controls;

    adouble x1dot, x2dot, x3dot;
    x1dot = x[1]; x2dot = x[2]; x3dot = u[0];

    derivatives[0] = x1dot;
    derivatives[1] = x2dot;
    derivatives[2] = x3dot;
}

void events(adouble* e, adouble* initial_states, adouble* final_states,
            adouble* parameters,adouble& t0, adouble& tf, adouble* xad,
            int iphase, Workspace* workspace)
{
    // adouble *initial_controls, *final_controls;
    // get_initial_controls(initial_controls, xad, 1, workspace);
    // get_final_controls(final_controls, xad, 1, workspace);

    e[0] = initial_states[0]; e[1] = initial_states[1]; e[2] = initial_states[2]; e[3] = final_states[1]; e[4] = final_states[2];
}

void linkages( adouble* linkages, adouble* xad, Workspace* workspace)
{

}

int main(void)
{
    Alg  algorithm;
    Sol  solution;
    Prob problem;

    problem.name                = "qhx_test";
    problem.outfilename         = "qhx_test.txt";

    // Constants_ CONSTAINS;

    // problem.user_data = (void*) &CONSTAINS;

    problem.nphases   = 1;
    problem.nlinkages = 0;

    psopt_level1_setup(problem);

    problem.phases(1).nstates   = 3;
    problem.phases(1).ncontrols = 1;
    problem.phases(1).nevents   = 5;
    problem.phases(1).npath     = 0;
    problem.phases(1).nodes     << 100;

    psopt_level2_setup(problem, algorithm);

    double JumpHeight = 0.5;
    double JumpVelocity = sqrt(2*9.8*JumpHeight);
    double CoM_init = 0.585;
    double dCoM_init = .0, dCoM_term = JumpVelocity;
    double ddCoM_init = .0, ddCoM_term = -9.8;
    
    double CoM_min = 0.56, CoM_max = 0.78;
    double dCoM_min = -0.5, dCoM_max = 3*JumpVelocity;
    double ddCoM_min = -10.0, ddCoM_max = 50.0;
    double dddCoM_min = -1000.0, dddCoM_max = 1000.0;

    double t0 = .0, tf = 1.5;

    problem.phases(1).bounds.lower.states(0) = CoM_min;
    problem.phases(1).bounds.lower.states(1) = dCoM_min;
    problem.phases(1).bounds.lower.states(2) = ddCoM_min;

    problem.phases(1).bounds.upper.states(0) = CoM_max;
    problem.phases(1).bounds.upper.states(1) = dCoM_max;
    problem.phases(1).bounds.upper.states(2) = ddCoM_max;

    problem.phases(1).bounds.lower.controls(0) = dddCoM_min;
    problem.phases(1).bounds.upper.controls(0) = dddCoM_max;

    problem.phases(1).bounds.lower.events(0) = CoM_init;
    problem.phases(1).bounds.lower.events(1) = dCoM_init;
    problem.phases(1).bounds.lower.events(2) = ddCoM_init;
    problem.phases(1).bounds.lower.events(3) = dCoM_term;
    problem.phases(1).bounds.lower.events(4) = ddCoM_term;

    problem.phases(1).bounds.upper.events(0) = CoM_init;
    problem.phases(1).bounds.upper.events(1) = dCoM_init;
    problem.phases(1).bounds.upper.events(2) = ddCoM_init;
    problem.phases(1).bounds.upper.events(3) = dCoM_term;
    problem.phases(1).bounds.upper.events(4) = ddCoM_term;

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
   
    state_guess  << CoM_init, CoM_init,
                    dCoM_init, dCoM_term,
                    ddCoM_init, ddCoM_term;
    control_guess << 0.0, 0.0; 
    time_guess << 0.0, 0.1;

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

    plot(t,x,problem.name,"time (s)","x");
}

