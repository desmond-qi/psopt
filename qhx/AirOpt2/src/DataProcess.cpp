#include <DataProcess.h>
#include <stdio.h>

namespace qhx{
DataProcess::DataProcess()
{
    m_sSolutionPlot.Time_Counter = m_sSolutionPlot.State_Counter = m_sSolutionPlot.Control_Counter = 0;
}

DataProcess::~DataProcess()
{
}

void DataProcess::ReadJumpTraj()
{
    FILE *fp1;
    char filename[] = "../../../qhx/AirOpt/Traj/FarTraj_H0.25_F1.dat";
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
    FILE *fp1;
    char filename[] = "../../../qhx/AirOpt/Traj/JointTraj.dat";
    int file_flag;
    double nn;
    m_iJointTraj_time = 0;

    fp1 = fopen64(filename, "r");
    if(fp1 == nullptr) 
        printf("\nError - Joint traj can't open.\n");
    else
    {
        while(1)
        {
            for(int i = 0; i < JOINTTRAJLENGTH; i++)
            {
                file_flag = fscanf(fp1, "%lf", &nn);
                m_sTraj.JointTraj[i].push_back(nn);
            }
            if(file_flag != 1) break;
            m_iJointTraj_time++;
        }
        fclose(fp1);
    }
}

void DataProcess::ReadGuess()
{
    FILE *fp1, *fp2, *fp3;
    char filename1[] = "../../../qhx/AirOpt/Traj/Guess_Time.dat";
    char filename2[] = "../../../qhx/AirOpt/Traj/Guess_State.dat";
    char filename3[] = "../../../qhx/AirOpt/Traj/Guess_Control.dat";
    int file_flag;
    double nn;

    fp1 = fopen64(filename1, "r");
    if(fp1 == nullptr) 
        printf("\nError - Guess Time traj can't open.\n");
    else
    {
        while(1)
        {
            file_flag = fscanf(fp1, "%lf", &nn);
            if(file_flag != 1) break;
            m_sTraj.Guess_Time.push_back(nn);
        }
        fclose(fp1);
    }

    fp2 = fopen64(filename2, "r");
    if(fp2 == nullptr) 
        printf("\nError - Guess State traj can't open.\n");
    else
    {
        while(1)
        {
            for(int i = 0; i < 3*TOF; i++)
            {
                file_flag = fscanf(fp2, "%lf", &nn);
                if(file_flag != 1) break;
                m_sTraj.Guess_State[i].push_back(nn);
            }
            if(file_flag != 1) break;
        }
        fclose(fp2);
    }

    fp3 = fopen64(filename3, "r");
    if(fp3 == nullptr) 
        printf("\nError - Guess Control traj can't open.\n");
    else
    {
        while(1)
        {
            for(int i = 0; i < TOF; i++)
            {
                file_flag = fscanf(fp3, "%lf", &nn);
                if(file_flag != 1) break;
                m_sTraj.Guess_Control[i].push_back(nn);
            }
            if(file_flag != 1) break;
        }
        fclose(fp3);
    }
}

void DataProcess::ReadSolution()
{
    FILE *fp1, *fp2, *fp3;
    char filename1[] = "../../../qhx/AirOpt/Traj/t.dat";
    char filename2[] = "../../../qhx/AirOpt/Traj/x.dat";
    char filename3[] = "../../../qhx/AirOpt/Traj/u.dat";
    int file_flag;
    double nn;

    fp1 = fopen64(filename1, "r");
    if(fp1 == nullptr) 
        printf("\nError - Time traj can't open.\n");
    else
    {
        while(1)
        {
            file_flag = fscanf(fp1, "%lf", &nn);
            if(file_flag != 1) break;
            m_sSolutionPlot.Time.resize(m_sSolutionPlot.Time_Counter+1, 1);
            m_sSolutionPlot.Time(m_sSolutionPlot.Time_Counter, 0) = nn;
            m_sSolutionPlot.Time_Counter++;
        }
        fclose(fp1);
    }

    fp2 = fopen64(filename2, "r");
    if(fp2 == nullptr) 
        printf("\nError - State traj can't open.\n");
    else
    {
        while(1)
        {
            for(int i = 0; i < 3*TOF; i++)
            {
                file_flag = fscanf(fp2, "%lf", &nn);
                if(file_flag != 1) break;
                m_sSolutionPlot.State.resize(m_sSolutionPlot.State_Counter+1, 3*TOF);
                m_sSolutionPlot.State(m_sSolutionPlot.State_Counter, i) = nn;
                m_sSolutionPlot.State_Counter++;
            }
            if(file_flag != 1) break;
        }
        fclose(fp2);
    }

    fp3 = fopen64(filename3, "r");
    if(fp3 == nullptr) 
        printf("\nError - Control traj can't open.\n");
    else
    {
        while(1)
        {
            for(int i = 0; i < TOF; i++)
            {
                file_flag = fscanf(fp3, "%lf", &nn);
                if(file_flag != 1) break;
                m_sSolutionPlot.Control.resize(m_sSolutionPlot.Control_Counter+1, TOF);
                m_sSolutionPlot.Control(m_sSolutionPlot.Control_Counter, i);
                m_sSolutionPlot.Control_Counter++;
            }
            if(file_flag != 1) break;
        }
        fclose(fp3);
    }
}

}

