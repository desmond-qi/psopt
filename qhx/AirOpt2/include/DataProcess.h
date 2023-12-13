#pragma once
#ifndef DATAPROCESS_
#define DATAPROCESS_

#include <vector>
#include <stdio.h>
#include <Eigen/Dense>
#include "Base.h"

extern "C"
{
    #include "SDFast/sdfastdefs.h"
}

using namespace std;
using namespace Eigen;

namespace qhx{
class DataProcess
{
private:
    
public:
    struct Traj
    {
        vector<double> JumpTraj[JUMPTRAJLENGTH];
        vector<double> JointTraj[JOINTTRAJLENGTH];
        vector<double> Guess_Time;
        vector<double> Guess_State[3*TOF];
        vector<double> Guess_Control[TOF];
    }m_sTraj;
    struct Solution
    {
        int Time_Counter, State_Counter, Control_Counter;
        MatrixXd Time;
        MatrixXd State;
        MatrixXd Control;
        MatrixXd Ir;
    }m_sSolutionPlot;
    
    int m_iJump_time, m_iJointTraj_time;
    
    DataProcess();
    ~DataProcess();

    void ReadJumpTraj();
    void ReadJointTraj();
    void ReadGuess();
    void ReadSolution();
};

}

#endif