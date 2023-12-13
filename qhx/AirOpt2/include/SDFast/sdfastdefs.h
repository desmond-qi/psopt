 //
//	SD/Fast headers
//
//	John Nagle		May, 1996
//
//��ͷ�ļ�������sdfast����������ʹ��

#pragma once
#ifndef SDFASTDEFS					// "pragma once" would be better
#define SDFASTDEFS
#pragma once

#define TOF 11
#define TOJ 8
#define NOL	11

typedef double sdvector3[3];			// 3D vector

extern void sdinit();
extern void sdrel2cart(int coord, int body, double point[3], double linchg[3], double rotchg[3]);
extern void sdstate(double timein, double qin[TOF], double uin[TOF]);//���Լ���������
extern void sdpos(int body, double point[3], double position[3]);
extern void sdtrans(int inbody, double invector[3], int outbody, double outvector[3]);
extern void sdfrcmat(double F[TOF]);//LYL
extern void sdsys(double *MTOT, double CM[3], double ICM[3][3]);
extern void sdacc(int body, double point[3], double acc[3]);
extern void sdvel(int body, double point[3], double vel[3]);
extern void sdcomptrq(double udotin[TOF], double trqout[TOF]);
extern void sdfulltrq(double udotin[TOF], double multin[1], double trqout[TOF]);
extern void sdmassmat(double mmat[TOF][TOF]);
extern void sdmom(double LMom[3], double AMom[3], double *KEom);
extern void sdgetmass(int body, double *massout);
extern void sdangvel(int body, double avel[3]);
extern void sdorient(int body, double ori[3][3]);
extern void sdgetiner(int body, double iner[3][3]);

extern void Calcu_Pos(double u[TOF], double Com[3], double Link_Com[11][3]);
extern void Calcu_ddCom_Complex(double u[TOF], double du[TOF], double ddCom_A[3][TOF], double ddCom_B[3][1]);
extern void sduforce(double t, double q[], double u[]);

typedef enum {
	Trunk = 0,
	RHipp = 1,
	RThigh = 2,
	RCalf = 3,
	RFoot = 4,
	LHipp = 5,
	LThigh = 6,
	LCalf = 7,
	LFoot = 8,
	RArm = 9,
	LArm = 10
}BodyInfo;

typedef enum {
	xTrunk = 0,
	zTrunk = 1,
	qyTrunk = 2,
	RSway = 3,//2 joint
	RHip = 4,
	RKnee = 5,
	RAnkle = 6,
	LSway = 7,//2 joint
	LHip = 8,
	LKnee = 9,
	LAnkle = 10,
	RShoudler = 11,
	LShoudler = 12,
}JointInfo;

typedef enum {						// indices into sdinfo reply array
	kInfoGROUNDED = 0,				// 1 if system is grounded, 0 if free flying
	kInfoNBOD = 1,					// number of bodies (and tree joints)
	kInfoNDOF = 2,					// number of tree hinge DOFs
	kInfoNC = 3,					// number of constraints
	kInfoNLOOP = 4,					// number of loop joints
	kInfoNLDOF = 5,					// number of loop hinge DOFs
	kInfoNLC = 6,					// number of loop constraints (ign. pres)
	kInfoNB = 7,					// number of 6DOF and ball joints in tree
	kInfoNLB = 8,					// number of 6DOF and ball joints in loop
	kInfoNPRESC = 9,				// number of prescribed motion constraints
	kInfoNUSERC = 10,				// number of user constraints
	kInfoRANK = 11 }				// number of constraints not obv. redundant.
	kSDInfo;
// user provides this
//}

#endif // SDFASTDEFS
