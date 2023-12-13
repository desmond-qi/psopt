/*
Generated 26-May-1995 11:15:27 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
#include <math.h>

void sduforce(double t, double q[], double u[])
{

}

void sdumotion(double time, double q[], double u[])
{

}

/* These routines are passed to sdroot. */

void sdposfunc(double vars[11],
    double param[1],
    double resid[1])
{
    int i;
    double pos[11],vel[11];

    for (i = 0; i < 11; i++) {
        vel[i] = 0.;
    }
    sdang2st(vars,pos);
    sdstate(param[0],pos,vel);
    sdperr(resid);
}

void sdvelfunc(double vars[11],
    double param[12],
    double resid[1])
{

    sdstate(param[11],param,vars);
    sdverr(resid);
}

void sdstatfunc(double vars[11],
    double param[12],
    double resid[11])
{
    double pos[11],qdotdum[11];

    sdang2st(vars,pos);
    sdstate(param[11],pos,param);
    sduforce(param[11],pos,param);
    sdperr(resid);
    sdderiv(qdotdum,&resid[0]);
}

void sdstdyfunc(double vars[22],
    double param[1],
    double resid[11])
{
    double pos[11],qdotdum[11];

    sdang2st(vars,pos);
    sdstate(param[0],pos,&vars[11]);
    sduforce(param[0],pos,&vars[11]);
    sdperr(resid);
    sdverr(&resid[0]);
    sdderiv(qdotdum,&resid[0]);
}

/* This routine is passed to the integrator. */

void sdmotfunc(double time,
    double state[22],
    double dstate[22],
    double param[1],
    int *status)
{

    sdstate(time,state,&state[11]);
    sduforce(time,state,&state[11]);
    sdderiv(dstate,&dstate[11]);
    *status = 0;
}

/* This routine performs assembly analysis. */

void sdassemble(double time,
    double state[22],
    int lock[11],
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double perrs[1],param[1];
    int i;

    sdgentime(&i);
    if (i != 111527) {
        sdseterr(50,42);
    }
    param[0] = time;
    *err = 0;
    *fcnt = 0;
    sdposfunc(state,param,perrs);
    *fcnt = *fcnt+1;
}

/* This routine performs initial velocity analysis. */

void sdinitvel(double time,
    double state[22],
    int lock[11],
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double verrs[1],param[12];
    int i;

    sdgentime(&i);
    if (i != 111527) {
        sdseterr(51,42);
    }
    for (i = 0; i < 11; i++) {
        param[i] = state[i];
    }
    param[11] = time;
    *err = 0;
    *fcnt = 0;
    sdvelfunc(&state[11],param,verrs);
    *fcnt = *fcnt+1;
}

/* This routine performs static analysis. */

void sdstatic(double time,
    double state[22],
    int lock[11],
    double ctol,
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double resid[11],param[12],jw[121],dw[968],rw[176];
    int iw[88],rooterr,i;

    sdgentime(&i);
    if (i != 111527) {
        sdseterr(52,42);
    }
    for (i = 0; i < 11; i++) {
        param[i] = state[11+i];
    }
    param[11] = time;
    sdroot(sdstatfunc,state,param,11,11,11,lock,
      ctol,tol,maxevals,jw,dw,rw,iw,resid,fcnt,&rooterr);
    sdstatfunc(state,param,resid);
    *fcnt = *fcnt+1;
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs steady motion analysis. */

void sdsteady(double time,
    double state[22],
    int lock[22],
    double ctol,
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double resid[11],param[1];
    double jw[242],dw[2178],rw[275];
    int iw[132],rooterr,i;

    sdgentime(&i);
    if (i != 111527) {
        sdseterr(53,42);
    }
    param[0] = time;
    sdroot(sdstdyfunc,state,param,11,22,11,lock,
      ctol,tol,maxevals,jw,dw,rw,iw,resid,fcnt,&rooterr);
    sdstdyfunc(state,param,resid);
    *fcnt = *fcnt+1;
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs state integration. */

void sdmotion(double *time,
    double state[22],
    double dstate[22],
    double dt,
    double ctol,
    double tol,
    int *flag,
    int *err)
{
    static double step;
    double work[132],ttime,param[1];
    int vintgerr,which,ferr,i;

    sdgentime(&i);
    if (i != 111527) {
        sdseterr(54,42);
    }
    param[0] = ctol;
    ttime = *time;
    if (*flag != 0) {
        sdmotfunc(ttime,state,dstate,param,&ferr);
        step = dt;
        *flag = 0;
    }
    if (step <= 0.) {
        step = dt;
    }
    sdvinteg(sdmotfunc,&ttime,state,dstate,param,dt,&step,22,tol,work,&vintgerr,
      &which);
    *time = ttime;
    *err = vintgerr;
}

/* This routine performs state integration with a fixed-step integrator. */

void sdfmotion(double *time,
    double state[22],
    double dstate[22],
    double dt,
    double ctol,
    int *flag,
    double *errest,
    int *err)
{
    double work[88],ttime,param[1];
    int ferr,i;

    sdgentime(&i);
    if (i != 111527) {
        sdseterr(55,42);
    }
    param[0] = ctol;
    *err = 0;
    ttime = *time;
    if (*flag != 0) {
        sdmotfunc(ttime,state,dstate,param,&ferr);
        *flag = 0;
    }
    sdfinteg(sdmotfunc,&ttime,state,dstate,param,dt,22,work,errest,&ferr);
    if (ferr != 0) {
        *err = 1;
    }
    *time = ttime;
}
