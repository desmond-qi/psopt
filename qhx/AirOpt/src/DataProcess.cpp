#include <DataProcess.h>
#include <stdio.h>

namespace qhx{
DataProcess::DataProcess()
{
}

DataProcess::~DataProcess()
{
}

void DataProcess::ReadJumpTraj()
{
    FILE *fp1;
    char filename[] = "home/Package/psopt/qhx/AirOpt/Traj/JumpTrajLF_H0.25.dat";
    int file_flag;
    double nn;
    m_iJump_time = 0;

    fp1 = fopen64(filename, "r");
    if(fp1 == nullptr) 
        printf("\nError - Jump traj can't open.\n");
    else
    {
        while(1)
        {
            for(int i = 0; i < JUMPTRAJLENGTH; i++)
            {
                file_flag = fscanf(fp1, "%lf", &nn);
                m_sTraj.JumpTraj[i].push_back(nn);
            }
            if(file_flag != 1) break;
            m_iJump_time++;
        }
        fclose(fp1);
    }

}

void DataProcess::ReadJointTraj()
{

}

}

