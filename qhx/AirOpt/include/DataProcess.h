#pragma once
#ifndef DATAPROCESS_
#define DATAPROCESS_

#include <vector>
#include <stdio.h>
#include "Base.h"

namespace qhx{
class DataProcess
{
private:
    
public:
    struct Traj
    {
        std::vector<double> JumpTraj[JUMPTRAJLENGTH];
        std::vector<double> JointTraj[JOINTTRAJLENGTH];
    }m_sTraj;
    int m_iJump_time, m_iJointTraj_time;
    
    DataProcess();
    ~DataProcess();

    void ReadJumpTraj();
    void ReadJointTraj();
};

}

#endif