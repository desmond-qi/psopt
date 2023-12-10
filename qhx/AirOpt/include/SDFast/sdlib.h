#ifndef __SDLIB__H__					// "#pragma once" would be better
#define __SDLIB__H__

extern void sdseterr(int routine,  int errnum);
extern void sdserialno(int *serno);
extern void sderror(int *routine,   int *errnum);
extern void sdldudcomp(int n,
    int na,
    int map[],
    double tol,
    double ld[],
    double sum[],
    double m[],
    double l[],
    double d[]);
extern void sdldubslv(int n,
    int na,
    int map[],
    double work[],
    double l[],
    double d[],
    double b[],
    double x[]);
extern void sdvcopy(double ivec[3],    double ovec[3]);
extern void sdvset(double sclr1,
    double sclr2,
    double sclr3,
    double ovec[3]);
	
extern void sdvcross(double ivec1[3],
    double ivec2[3],
    double ovec[3]);
extern void sdvadd(double ivec1[3],
    double ivec2[3],
    double ovec[3]);
#endif