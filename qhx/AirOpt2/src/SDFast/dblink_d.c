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


ROADMAP (dblink.sd)

Bodies        Inb
No  Name      body Joint type  Coords q
--- --------- ---- ----------- ----------------
 -1 $ground                                    
  0 bar1       -1  Planar        0   1   2     
  1 bar2        0  Pin           3             
  2 bar3        1  Pin           4             
  3 bar4        2  Pin           5             
  4 bar5        0  Pin           6             
  5 bar6        4  Pin           7             
  6 bar7        5  Pin           8             
  7 bar8        0  Pin           9             
  8 bar9        0  Pin          10             

*/
#include <math.h>
#include <stdio.h>

typedef struct {
    int ground_,nbod_,ndof_,ncons_,nloop_,nldof_,nloopc_,nball_,nlball_,npres_,
      nuser_;
    int jtype_[9],inb_[9],outb_[9],njntdof_[9],njntc_[9],njntp_[9],firstq_[9],
      ballq_[9],firstm_[9],firstp_[9];
    int trans_[11];
} sdgtopo_t;
#define ground (sdgtopo.ground_)
#define nbod (sdgtopo.nbod_)
#define ndof (sdgtopo.ndof_)
#define ncons (sdgtopo.ncons_)
#define nloop (sdgtopo.nloop_)
#define nldof (sdgtopo.nldof_)
#define nloopc (sdgtopo.nloopc_)
#define nball (sdgtopo.nball_)
#define nlball (sdgtopo.nlball_)
#define npres (sdgtopo.npres_)
#define nuser (sdgtopo.nuser_)
#define jtype (sdgtopo.jtype_)
#define inb (sdgtopo.inb_)
#define outb (sdgtopo.outb_)
#define njntdof (sdgtopo.njntdof_)
#define njntc (sdgtopo.njntc_)
#define njntp (sdgtopo.njntp_)
#define firstq (sdgtopo.firstq_)
#define ballq (sdgtopo.ballq_)
#define firstm (sdgtopo.firstm_)
#define firstp (sdgtopo.firstp_)
#define trans (sdgtopo.trans_)

typedef struct {
    double grav_[3],mk_[9],ik_[9][3][3],pin_[11][3];
    double rk_[9][3],ri_[9][3],pres_[11],stabvel_,stabpos_;
    int mfrcflg_,roustate_,vpkflg_,inerflg_,mmflg_,mmlduflg_,wwflg_,ltauflg_,
      fs0flg_,ii_,mmap_[11];
    int gravq_[3],mkq_[9],ikq_[9][3][3],pinq_[11][3],rkq_[9][3],riq_[9][3],
      presq_[11],stabvelq_,stabposq_;
    double mtot_,psmkg_,rhead_[9][3],rcom_[9][3],mkrcomt_[9][3][3],psikg_[3][3],
      psrcomg_[3],psrkg_[3],psrig_[3],psmk_[11],psik_[11][3][3],psrcom_[11][3],
      psrk_[11][3],psri_[11][3];
} sdginput_t;
#define grav (sdginput.grav_)
#define mk (sdginput.mk_)
#define ik (sdginput.ik_)
#define pin (sdginput.pin_)
#define rk (sdginput.rk_)
#define ri (sdginput.ri_)
#define pres (sdginput.pres_)
#define stabvel (sdginput.stabvel_)
#define stabpos (sdginput.stabpos_)
#define rhead (sdginput.rhead_)
#define rcom (sdginput.rcom_)
#define psrcomg (sdginput.psrcomg_)
#define psrcom (sdginput.psrcom_)
#define mkrcomt (sdginput.mkrcomt_)
#define psmk (sdginput.psmk_)
#define psik (sdginput.psik_)
#define psrk (sdginput.psrk_)
#define psri (sdginput.psri_)
#define psmkg (sdginput.psmkg_)
#define psikg (sdginput.psikg_)
#define psrkg (sdginput.psrkg_)
#define psrig (sdginput.psrig_)
#define mtot (sdginput.mtot_)
#define mfrcflg (sdginput.mfrcflg_)
#define roustate (sdginput.roustate_)
#define vpkflg (sdginput.vpkflg_)
#define inerflg (sdginput.inerflg_)
#define mmflg (sdginput.mmflg_)
#define mmlduflg (sdginput.mmlduflg_)
#define wwflg (sdginput.wwflg_)
#define ltauflg (sdginput.ltauflg_)
#define fs0flg (sdginput.fs0flg_)
#define ii (sdginput.ii_)
#define mmap (sdginput.mmap_)
#define gravq (sdginput.gravq_)
#define mkq (sdginput.mkq_)
#define ikq (sdginput.ikq_)
#define pinq (sdginput.pinq_)
#define rkq (sdginput.rkq_)
#define riq (sdginput.riq_)
#define presq (sdginput.presq_)
#define stabvelq (sdginput.stabvelq_)
#define stabposq (sdginput.stabposq_)

typedef struct {
    double curtim_,q_[11],qn_[11],u_[11],cnk_[11][3][3],cnb_[9][3][3];
    double rnk_[11][3],vnk_[11][3],wk_[11][3],rnb_[9][3],vnb_[9][3],wb_[9][3],
      wbrcom_[9][3],com_[3],rnkg_[3];
    double Cik_[11][3][3],rikt_[11][3][3],Iko_[11][3][3],mkrk_[11][3][3],Cib_[9
      ][3][3];
    double Wkk_[11][3],Vkk_[11][3],dik_[11][3],rpp_[11][3],rpk_[11][3],rik_[11][
      3],rik2_[11][3];
    double rpri_[11][3],Wik_[11][3],Vik_[11][3],Wirk_[11][3],rkWkk_[11][3],
      Wkrpk_[11][3],VikWkr_[11][3];
    double perr_[1],verr_[1],aerr_[1],mult_[1],ufk_[9][3],utk_[9][3],mfk_[9][3],
      mtk_[9][3];
    double utau_[11],mtau_[11],uacc_[11],uvel_[11],upos_[11];
    double s2_,c2_,s3_,c3_,s4_,c4_,s5_,c5_,s6_,c6_,s7_,c7_,s8_,c8_,s9_,c9_,s10_,
      c10_;
} sdgstate_t;
#define curtim (sdgstate.curtim_)
#define q (sdgstate.q_)
#define qn (sdgstate.qn_)
#define u (sdgstate.u_)
#define cnk (sdgstate.cnk_)
#define cnb (sdgstate.cnb_)
#define rnkg (sdgstate.rnkg_)
#define rnk (sdgstate.rnk_)
#define rnb (sdgstate.rnb_)
#define vnk (sdgstate.vnk_)
#define vnb (sdgstate.vnb_)
#define wk (sdgstate.wk_)
#define wb (sdgstate.wb_)
#define com (sdgstate.com_)
#define Cik (sdgstate.Cik_)
#define Cib (sdgstate.Cib_)
#define rikt (sdgstate.rikt_)
#define Iko (sdgstate.Iko_)
#define mkrk (sdgstate.mkrk_)
#define Wkk (sdgstate.Wkk_)
#define Vkk (sdgstate.Vkk_)
#define dik (sdgstate.dik_)
#define rpp (sdgstate.rpp_)
#define rpk (sdgstate.rpk_)
#define rik (sdgstate.rik_)
#define rik2 (sdgstate.rik2_)
#define rpri (sdgstate.rpri_)
#define Wik (sdgstate.Wik_)
#define Vik (sdgstate.Vik_)
#define Wirk (sdgstate.Wirk_)
#define rkWkk (sdgstate.rkWkk_)
#define Wkrpk (sdgstate.Wkrpk_)
#define VikWkr (sdgstate.VikWkr_)
#define wbrcom (sdgstate.wbrcom_)
#define perr (sdgstate.perr_)
#define verr (sdgstate.verr_)
#define aerr (sdgstate.aerr_)
#define mult (sdgstate.mult_)
#define ufk (sdgstate.ufk_)
#define utk (sdgstate.utk_)
#define utau (sdgstate.utau_)
#define mfk (sdgstate.mfk_)
#define mtk (sdgstate.mtk_)
#define mtau (sdgstate.mtau_)
#define uacc (sdgstate.uacc_)
#define uvel (sdgstate.uvel_)
#define upos (sdgstate.upos_)
#define s2 (sdgstate.s2_)
#define c2 (sdgstate.c2_)
#define s3 (sdgstate.s3_)
#define c3 (sdgstate.c3_)
#define s4 (sdgstate.s4_)
#define c4 (sdgstate.c4_)
#define s5 (sdgstate.s5_)
#define c5 (sdgstate.c5_)
#define s6 (sdgstate.s6_)
#define c6 (sdgstate.c6_)
#define s7 (sdgstate.s7_)
#define c7 (sdgstate.c7_)
#define s8 (sdgstate.s8_)
#define c8 (sdgstate.c8_)
#define s9 (sdgstate.s9_)
#define c9 (sdgstate.c9_)
#define s10 (sdgstate.s10_)
#define c10 (sdgstate.c10_)

typedef struct {
    double fs0_[11],qdot_[11],Otk_[11][3],Atk_[11][3],AiOiWi_[11][3],Fstar_[11][
      3];
    double Tstar_[11][3],Fstark_[11][3],Tstark_[11][3],IkWk_[11][3],WkIkWk_[11][
      3],gk_[11][3],IkbWk_[9][3],WkIkbWk_[9][3];
    double w0w0_[9],w1w1_[9],w2w2_[9],w0w1_[9],w0w2_[9],w1w2_[9];
    double w00w11_[9],w00w22_[9],w11w22_[9],ww_[1][1],qraux_[1];
    double mm_[11][11],mlo_[11][11],mdi_[11],IkWpk_[11][11][3],works_[11],
      workss_[11][11];
    double Wpk_[11][11][3],Vpk_[11][11][3],VWri_[11][11][3];
    int wmap_[1],multmap_[1],jpvt_[1],wsiz_,wrank_;
} sdglhs_t;
#define qdot (sdglhs.qdot_)
#define Otk (sdglhs.Otk_)
#define Atk (sdglhs.Atk_)
#define AiOiWi (sdglhs.AiOiWi_)
#define Fstar (sdglhs.Fstar_)
#define Tstar (sdglhs.Tstar_)
#define fs0 (sdglhs.fs0_)
#define Fstark (sdglhs.Fstark_)
#define Tstark (sdglhs.Tstark_)
#define IkWk (sdglhs.IkWk_)
#define IkbWk (sdglhs.IkbWk_)
#define WkIkWk (sdglhs.WkIkWk_)
#define WkIkbWk (sdglhs.WkIkbWk_)
#define gk (sdglhs.gk_)
#define w0w0 (sdglhs.w0w0_)
#define w1w1 (sdglhs.w1w1_)
#define w2w2 (sdglhs.w2w2_)
#define w0w1 (sdglhs.w0w1_)
#define w0w2 (sdglhs.w0w2_)
#define w1w2 (sdglhs.w1w2_)
#define w00w11 (sdglhs.w00w11_)
#define w00w22 (sdglhs.w00w22_)
#define w11w22 (sdglhs.w11w22_)
#define ww (sdglhs.ww_)
#define qraux (sdglhs.qraux_)
#define mm (sdglhs.mm_)
#define mlo (sdglhs.mlo_)
#define mdi (sdglhs.mdi_)
#define IkWpk (sdglhs.IkWpk_)
#define works (sdglhs.works_)
#define workss (sdglhs.workss_)
#define Wpk (sdglhs.Wpk_)
#define Vpk (sdglhs.Vpk_)
#define VWri (sdglhs.VWri_)
#define wmap (sdglhs.wmap_)
#define multmap (sdglhs.multmap_)
#define jpvt (sdglhs.jpvt_)
#define wsiz (sdglhs.wsiz_)
#define wrank (sdglhs.wrank_)

typedef struct {
    double fs_[11],udot_[11],tauc_[11],dyad_[9][3][3],fc_[11][3],tc_[11][3];
    double ank_[11][3],onk_[11][3],Onkb_[11][3],AOnkri_[11][3],Ankb_[11][3],
      AnkAtk_[11][3],anb_[9][3],onb_[9][3],dyrcom_[9][3];
    double ffk_[11][3],ttk_[11][3],fccikt_[11][3],ffkb_[9][3],ttkb_[9][3];
} sdgrhs_t;
#define fs (sdgrhs.fs_)
#define udot (sdgrhs.udot_)
#define ank (sdgrhs.ank_)
#define anb (sdgrhs.anb_)
#define onk (sdgrhs.onk_)
#define onb (sdgrhs.onb_)
#define Onkb (sdgrhs.Onkb_)
#define AOnkri (sdgrhs.AOnkri_)
#define Ankb (sdgrhs.Ankb_)
#define AnkAtk (sdgrhs.AnkAtk_)
#define dyrcom (sdgrhs.dyrcom_)
#define ffk (sdgrhs.ffk_)
#define ttk (sdgrhs.ttk_)
#define fccikt (sdgrhs.fccikt_)
#define ffkb (sdgrhs.ffkb_)
#define ttkb (sdgrhs.ttkb_)
#define dyad (sdgrhs.dyad_)
#define fc (sdgrhs.fc_)
#define tc (sdgrhs.tc_)
#define tauc (sdgrhs.tauc_)

typedef struct {
    double temp_[3000],tmat1_[3][3],tmat2_[3][3],tvec1_[3],tvec2_[3],tvec3_[3],
      tvec4_[3],tvec5_[3];
    double tsc1_,tsc2_,tsc3_;
} sdgtemp_t;
#define temp (sdgtemp.temp_)
#define tmat1 (sdgtemp.tmat1_)
#define tmat2 (sdgtemp.tmat2_)
#define tvec1 (sdgtemp.tvec1_)
#define tvec2 (sdgtemp.tvec2_)
#define tvec3 (sdgtemp.tvec3_)
#define tvec4 (sdgtemp.tvec4_)
#define tvec5 (sdgtemp.tvec5_)
#define tsc1 (sdgtemp.tsc1_)
#define tsc2 (sdgtemp.tsc2_)
#define tsc3 (sdgtemp.tsc3_)

sdgtopo_t sdgtopo = {
/*  Topological information
*/
    /* ground */ 1,
    /* nbod */ 9,
    /* ndof */ 11,
    /* ncons */ 0,
    /* nloop */ 0,
    /* nldof */ 0,
    /* nloopc */ 0,
    /* nball */ 0,
    /* nlball */ 0,
    /* npres */ 0,
    /* nuser */ 0,
    /* jtype[0] */ 8,
    /* jtype[1] */ 1,
    /* jtype[2] */ 1,
    /* jtype[3] */ 1,
    /* jtype[4] */ 1,
    /* jtype[5] */ 1,
    /* jtype[6] */ 1,
    /* jtype[7] */ 1,
    /* jtype[8] */ 1,
    /* inb[0] */ -1,
    /* inb[1] */ 0,
    /* inb[2] */ 1,
    /* inb[3] */ 2,
    /* inb[4] */ 0,
    /* inb[5] */ 4,
    /* inb[6] */ 5,
    /* inb[7] */ 0,
    /* inb[8] */ 0,
    /* outb[0] */ 0,
    /* outb[1] */ 1,
    /* outb[2] */ 2,
    /* outb[3] */ 3,
    /* outb[4] */ 4,
    /* outb[5] */ 5,
    /* outb[6] */ 6,
    /* outb[7] */ 7,
    /* outb[8] */ 8,
    /* njntdof[0] */ 3,
    /* njntdof[1] */ 1,
    /* njntdof[2] */ 1,
    /* njntdof[3] */ 1,
    /* njntdof[4] */ 1,
    /* njntdof[5] */ 1,
    /* njntdof[6] */ 1,
    /* njntdof[7] */ 1,
    /* njntdof[8] */ 1,
    /* njntc[0] */ 0,
    /* njntc[1] */ 0,
    /* njntc[2] */ 0,
    /* njntc[3] */ 0,
    /* njntc[4] */ 0,
    /* njntc[5] */ 0,
    /* njntc[6] */ 0,
    /* njntc[7] */ 0,
    /* njntc[8] */ 0,
    /* njntp[0] */ 0,
    /* njntp[1] */ 0,
    /* njntp[2] */ 0,
    /* njntp[3] */ 0,
    /* njntp[4] */ 0,
    /* njntp[5] */ 0,
    /* njntp[6] */ 0,
    /* njntp[7] */ 0,
    /* njntp[8] */ 0,
    /* firstq[0] */ 0,
    /* firstq[1] */ 3,
    /* firstq[2] */ 4,
    /* firstq[3] */ 5,
    /* firstq[4] */ 6,
    /* firstq[5] */ 7,
    /* firstq[6] */ 8,
    /* firstq[7] */ 9,
    /* firstq[8] */ 10,
    /* ballq[0] */ -104,
    /* ballq[1] */ -104,
    /* ballq[2] */ -104,
    /* ballq[3] */ -104,
    /* ballq[4] */ -104,
    /* ballq[5] */ -104,
    /* ballq[6] */ -104,
    /* ballq[7] */ -104,
    /* ballq[8] */ -104,
    /* firstm[0] */ -1,
    /* firstm[1] */ -1,
    /* firstm[2] */ -1,
    /* firstm[3] */ -1,
    /* firstm[4] */ -1,
    /* firstm[5] */ -1,
    /* firstm[6] */ -1,
    /* firstm[7] */ -1,
    /* firstm[8] */ -1,
    /* firstp[0] */ -1,
    /* firstp[1] */ -1,
    /* firstp[2] */ -1,
    /* firstp[3] */ -1,
    /* firstp[4] */ -1,
    /* firstp[5] */ -1,
    /* firstp[6] */ -1,
    /* firstp[7] */ -1,
    /* firstp[8] */ -1,
    /* trans[0] */ 1,
    /* trans[1] */ 1,
    /* trans[2] */ 0,
    /* trans[3] */ 0,
    /* trans[4] */ 0,
    /* trans[5] */ 0,
    /* trans[6] */ 0,
    /* trans[7] */ 0,
    /* trans[8] */ 0,
    /* trans[9] */ 0,
    /* trans[10] */ 0,
};
sdginput_t sdginput = {
/* Model parameters from the input file */

/* gravity */
    /* grav[0] */ 0.,
    /* grav[1] */ 0.,
    /* grav[2] */ -9.8,

/* mass */
    /* mk[0] */ 24.56,
    /* mk[1] */ 3.32,
    /* mk[2] */ 3.3,
    /* mk[3] */ .2,
    /* mk[4] */ 3.32,
    /* mk[5] */ 3.3,
    /* mk[6] */ .2,
    /* mk[7] */ 2.,
    /* mk[8] */ 2.,

/* inertia */
    /* ik[0][0][0] */ 1.2769,
    /* ik[0][0][1] */ 0.,
    /* ik[0][0][2] */ 0.,
    /* ik[0][1][0] */ 0.,
    /* ik[0][1][1] */ 1.0181,
    /* ik[0][1][2] */ 0.,
    /* ik[0][2][0] */ 0.,
    /* ik[0][2][1] */ 0.,
    /* ik[0][2][2] */ .50336,
    /* ik[1][0][0] */ .042892,
    /* ik[1][0][1] */ 0.,
    /* ik[1][0][2] */ 0.,
    /* ik[1][1][0] */ 0.,
    /* ik[1][1][1] */ .048025,
    /* ik[1][1][2] */ 0.,
    /* ik[1][2][0] */ 0.,
    /* ik[1][2][1] */ 0.,
    /* ik[1][2][2] */ .000784,
    /* ik[2][0][0] */ .062328,
    /* ik[2][0][1] */ 0.,
    /* ik[2][0][2] */ 0.,
    /* ik[2][1][0] */ 0.,
    /* ik[2][1][1] */ .062664,
    /* ik[2][1][2] */ 0.,
    /* ik[2][2][0] */ 0.,
    /* ik[2][2][1] */ 0.,
    /* ik[2][2][2] */ .004592,
    /* ik[3][0][0] */ .000167,
    /* ik[3][0][1] */ 0.,
    /* ik[3][0][2] */ 0.,
    /* ik[3][1][0] */ 0.,
    /* ik[3][1][1] */ .000167,
    /* ik[3][1][2] */ 0.,
    /* ik[3][2][0] */ 0.,
    /* ik[3][2][1] */ 0.,
    /* ik[3][2][2] */ 1e-5,
    /* ik[4][0][0] */ .042892,
    /* ik[4][0][1] */ 0.,
    /* ik[4][0][2] */ 0.,
    /* ik[4][1][0] */ 0.,
    /* ik[4][1][1] */ .048025,
    /* ik[4][1][2] */ 0.,
    /* ik[4][2][0] */ 0.,
    /* ik[4][2][1] */ 0.,
    /* ik[4][2][2] */ .000784,
    /* ik[5][0][0] */ .062328,
    /* ik[5][0][1] */ 0.,
    /* ik[5][0][2] */ 0.,
    /* ik[5][1][0] */ 0.,
    /* ik[5][1][1] */ .062664,
    /* ik[5][1][2] */ 0.,
    /* ik[5][2][0] */ 0.,
    /* ik[5][2][1] */ 0.,
    /* ik[5][2][2] */ .004592,
    /* ik[6][0][0] */ .000167,
    /* ik[6][0][1] */ 0.,
    /* ik[6][0][2] */ 0.,
    /* ik[6][1][0] */ 0.,
    /* ik[6][1][1] */ .000167,
    /* ik[6][1][2] */ 0.,
    /* ik[6][2][0] */ 0.,
    /* ik[6][2][1] */ 0.,
    /* ik[6][2][2] */ 1e-5,
    /* ik[7][0][0] */ .0815,
    /* ik[7][0][1] */ 0.,
    /* ik[7][0][2] */ 0.,
    /* ik[7][1][0] */ 0.,
    /* ik[7][1][1] */ .0818,
    /* ik[7][1][2] */ 0.,
    /* ik[7][2][0] */ 0.,
    /* ik[7][2][1] */ 0.,
    /* ik[7][2][2] */ .0029,
    /* ik[8][0][0] */ .0815,
    /* ik[8][0][1] */ 0.,
    /* ik[8][0][2] */ 0.,
    /* ik[8][1][0] */ 0.,
    /* ik[8][1][1] */ .0818,
    /* ik[8][1][2] */ 0.,
    /* ik[8][2][0] */ 0.,
    /* ik[8][2][1] */ 0.,
    /* ik[8][2][2] */ .0029,

/* tree hinge axis vectors */
    /* pin[0][0] */ 1.,
    /* pin[0][1] */ 0.,
    /* pin[0][2] */ 0.,
    /* pin[1][0] */ 0.,
    /* pin[1][1] */ 0.,
    /* pin[1][2] */ 1.,
    /* pin[2][0] */ 0.,
    /* pin[2][1] */ 1.,
    /* pin[2][2] */ 0.,
    /* pin[3][0] */ 0.,
    /* pin[3][1] */ 1.,
    /* pin[3][2] */ 0.,
    /* pin[4][0] */ 0.,
    /* pin[4][1] */ 1.,
    /* pin[4][2] */ 0.,
    /* pin[5][0] */ 0.,
    /* pin[5][1] */ 1.,
    /* pin[5][2] */ 0.,
    /* pin[6][0] */ 0.,
    /* pin[6][1] */ 1.,
    /* pin[6][2] */ 0.,
    /* pin[7][0] */ 0.,
    /* pin[7][1] */ 1.,
    /* pin[7][2] */ 0.,
    /* pin[8][0] */ 0.,
    /* pin[8][1] */ 1.,
    /* pin[8][2] */ 0.,
    /* pin[9][0] */ 0.,
    /* pin[9][1] */ 1.,
    /* pin[9][2] */ 0.,
    /* pin[10][0] */ 0.,
    /* pin[10][1] */ 1.,
    /* pin[10][2] */ 0.,

/* tree bodytojoint vectors */
    /* rk[0][0] */ 0.,
    /* rk[0][1] */ 0.,
    /* rk[0][2] */ .25,
    /* rk[1][0] */ 0.,
    /* rk[1][1] */ 0.,
    /* rk[1][2] */ .211,
    /* rk[2][0] */ 0.,
    /* rk[2][1] */ 0.,
    /* rk[2][2] */ .23,
    /* rk[3][0] */ 0.,
    /* rk[3][1] */ 0.,
    /* rk[3][2] */ .05,
    /* rk[4][0] */ 0.,
    /* rk[4][1] */ 0.,
    /* rk[4][2] */ .211,
    /* rk[5][0] */ 0.,
    /* rk[5][1] */ 0.,
    /* rk[5][2] */ .23,
    /* rk[6][0] */ 0.,
    /* rk[6][1] */ 0.,
    /* rk[6][2] */ .05,
    /* rk[7][0] */ 0.,
    /* rk[7][1] */ 0.,
    /* rk[7][2] */ .2,
    /* rk[8][0] */ 0.,
    /* rk[8][1] */ 0.,
    /* rk[8][2] */ .2,

/* tree inbtojoint vectors */
    /* ri[0][0] */ 0.,
    /* ri[0][1] */ 0.,
    /* ri[0][2] */ 0.,
    /* ri[1][0] */ 0.,
    /* ri[1][1] */ -.1,
    /* ri[1][2] */ -.25,
    /* ri[2][0] */ 0.,
    /* ri[2][1] */ 0.,
    /* ri[2][2] */ -.239,
    /* ri[3][0] */ 0.,
    /* ri[3][1] */ 0.,
    /* ri[3][2] */ -.22,
    /* ri[4][0] */ 0.,
    /* ri[4][1] */ .1,
    /* ri[4][2] */ -.25,
    /* ri[5][0] */ 0.,
    /* ri[5][1] */ 0.,
    /* ri[5][2] */ -.239,
    /* ri[6][0] */ 0.,
    /* ri[6][1] */ 0.,
    /* ri[6][2] */ -.22,
    /* ri[7][0] */ 0.,
    /* ri[7][1] */ -.1,
    /* ri[7][2] */ .15,
    /* ri[8][0] */ 0.,
    /* ri[8][1] */ .1,
    /* ri[8][2] */ .15,

/* tree prescribed motion */
    /* pres[0] */ 0.,
    /* pres[1] */ 0.,
    /* pres[2] */ 0.,
    /* pres[3] */ 0.,
    /* pres[4] */ 0.,
    /* pres[5] */ 0.,
    /* pres[6] */ 0.,
    /* pres[7] */ 0.,
    /* pres[8] */ 0.,
    /* pres[9] */ 0.,
    /* pres[10] */ 0.,

/* stabilization parameters */
    /* stabvel */ 0.,
    /* stabpos */ 0.,

/* miscellaneous */
    /* mfrcflg */ 0,
    /* roustate */ 0,
    /* vpkflg */ 0,
    /* inerflg */ 0,
    /* mmflg */ 0,
    /* mmlduflg */ 0,
    /* wwflg */ 0,
    /* ltauflg */ 0,
    /* fs0flg */ 0,
    /* ii */ 0,
    /* mmap[0] */ 0,
    /* mmap[1] */ 1,
    /* mmap[2] */ 2,
    /* mmap[3] */ 3,
    /* mmap[4] */ 4,
    /* mmap[5] */ 5,
    /* mmap[6] */ 6,
    /* mmap[7] */ 7,
    /* mmap[8] */ 8,
    /* mmap[9] */ 9,
    /* mmap[10] */ 10,

/* Which parameters were "?" (1) or "<nominal>?" (3) */
    /* gravq[0] */ 0,
    /* gravq[1] */ 0,
    /* gravq[2] */ 0,
    /* mkq[0] */ 0,
    /* mkq[1] */ 0,
    /* mkq[2] */ 0,
    /* mkq[3] */ 0,
    /* mkq[4] */ 0,
    /* mkq[5] */ 0,
    /* mkq[6] */ 0,
    /* mkq[7] */ 0,
    /* mkq[8] */ 0,
    /* ikq[0][0][0] */ 0,
    /* ikq[0][0][1] */ 0,
    /* ikq[0][0][2] */ 0,
    /* ikq[0][1][0] */ 0,
    /* ikq[0][1][1] */ 0,
    /* ikq[0][1][2] */ 0,
    /* ikq[0][2][0] */ 0,
    /* ikq[0][2][1] */ 0,
    /* ikq[0][2][2] */ 0,
    /* ikq[1][0][0] */ 0,
    /* ikq[1][0][1] */ 0,
    /* ikq[1][0][2] */ 0,
    /* ikq[1][1][0] */ 0,
    /* ikq[1][1][1] */ 0,
    /* ikq[1][1][2] */ 0,
    /* ikq[1][2][0] */ 0,
    /* ikq[1][2][1] */ 0,
    /* ikq[1][2][2] */ 0,
    /* ikq[2][0][0] */ 0,
    /* ikq[2][0][1] */ 0,
    /* ikq[2][0][2] */ 0,
    /* ikq[2][1][0] */ 0,
    /* ikq[2][1][1] */ 0,
    /* ikq[2][1][2] */ 0,
    /* ikq[2][2][0] */ 0,
    /* ikq[2][2][1] */ 0,
    /* ikq[2][2][2] */ 0,
    /* ikq[3][0][0] */ 0,
    /* ikq[3][0][1] */ 0,
    /* ikq[3][0][2] */ 0,
    /* ikq[3][1][0] */ 0,
    /* ikq[3][1][1] */ 0,
    /* ikq[3][1][2] */ 0,
    /* ikq[3][2][0] */ 0,
    /* ikq[3][2][1] */ 0,
    /* ikq[3][2][2] */ 0,
    /* ikq[4][0][0] */ 0,
    /* ikq[4][0][1] */ 0,
    /* ikq[4][0][2] */ 0,
    /* ikq[4][1][0] */ 0,
    /* ikq[4][1][1] */ 0,
    /* ikq[4][1][2] */ 0,
    /* ikq[4][2][0] */ 0,
    /* ikq[4][2][1] */ 0,
    /* ikq[4][2][2] */ 0,
    /* ikq[5][0][0] */ 0,
    /* ikq[5][0][1] */ 0,
    /* ikq[5][0][2] */ 0,
    /* ikq[5][1][0] */ 0,
    /* ikq[5][1][1] */ 0,
    /* ikq[5][1][2] */ 0,
    /* ikq[5][2][0] */ 0,
    /* ikq[5][2][1] */ 0,
    /* ikq[5][2][2] */ 0,
    /* ikq[6][0][0] */ 0,
    /* ikq[6][0][1] */ 0,
    /* ikq[6][0][2] */ 0,
    /* ikq[6][1][0] */ 0,
    /* ikq[6][1][1] */ 0,
    /* ikq[6][1][2] */ 0,
    /* ikq[6][2][0] */ 0,
    /* ikq[6][2][1] */ 0,
    /* ikq[6][2][2] */ 0,
    /* ikq[7][0][0] */ 0,
    /* ikq[7][0][1] */ 0,
    /* ikq[7][0][2] */ 0,
    /* ikq[7][1][0] */ 0,
    /* ikq[7][1][1] */ 0,
    /* ikq[7][1][2] */ 0,
    /* ikq[7][2][0] */ 0,
    /* ikq[7][2][1] */ 0,
    /* ikq[7][2][2] */ 0,
    /* ikq[8][0][0] */ 0,
    /* ikq[8][0][1] */ 0,
    /* ikq[8][0][2] */ 0,
    /* ikq[8][1][0] */ 0,
    /* ikq[8][1][1] */ 0,
    /* ikq[8][1][2] */ 0,
    /* ikq[8][2][0] */ 0,
    /* ikq[8][2][1] */ 0,
    /* ikq[8][2][2] */ 0,
    /* pinq[0][0] */ 0,
    /* pinq[0][1] */ 0,
    /* pinq[0][2] */ 0,
    /* pinq[1][0] */ 0,
    /* pinq[1][1] */ 0,
    /* pinq[1][2] */ 0,
    /* pinq[2][0] */ 0,
    /* pinq[2][1] */ 0,
    /* pinq[2][2] */ 0,
    /* pinq[3][0] */ 0,
    /* pinq[3][1] */ 0,
    /* pinq[3][2] */ 0,
    /* pinq[4][0] */ 0,
    /* pinq[4][1] */ 0,
    /* pinq[4][2] */ 0,
    /* pinq[5][0] */ 0,
    /* pinq[5][1] */ 0,
    /* pinq[5][2] */ 0,
    /* pinq[6][0] */ 0,
    /* pinq[6][1] */ 0,
    /* pinq[6][2] */ 0,
    /* pinq[7][0] */ 0,
    /* pinq[7][1] */ 0,
    /* pinq[7][2] */ 0,
    /* pinq[8][0] */ 0,
    /* pinq[8][1] */ 0,
    /* pinq[8][2] */ 0,
    /* pinq[9][0] */ 0,
    /* pinq[9][1] */ 0,
    /* pinq[9][2] */ 0,
    /* pinq[10][0] */ 0,
    /* pinq[10][1] */ 0,
    /* pinq[10][2] */ 0,
    /* rkq[0][0] */ 0,
    /* rkq[0][1] */ 0,
    /* rkq[0][2] */ 0,
    /* rkq[1][0] */ 0,
    /* rkq[1][1] */ 0,
    /* rkq[1][2] */ 0,
    /* rkq[2][0] */ 0,
    /* rkq[2][1] */ 0,
    /* rkq[2][2] */ 0,
    /* rkq[3][0] */ 0,
    /* rkq[3][1] */ 0,
    /* rkq[3][2] */ 0,
    /* rkq[4][0] */ 0,
    /* rkq[4][1] */ 0,
    /* rkq[4][2] */ 0,
    /* rkq[5][0] */ 0,
    /* rkq[5][1] */ 0,
    /* rkq[5][2] */ 0,
    /* rkq[6][0] */ 0,
    /* rkq[6][1] */ 0,
    /* rkq[6][2] */ 0,
    /* rkq[7][0] */ 0,
    /* rkq[7][1] */ 0,
    /* rkq[7][2] */ 0,
    /* rkq[8][0] */ 0,
    /* rkq[8][1] */ 0,
    /* rkq[8][2] */ 0,
    /* riq[0][0] */ 0,
    /* riq[0][1] */ 0,
    /* riq[0][2] */ 0,
    /* riq[1][0] */ 0,
    /* riq[1][1] */ 0,
    /* riq[1][2] */ 0,
    /* riq[2][0] */ 0,
    /* riq[2][1] */ 0,
    /* riq[2][2] */ 0,
    /* riq[3][0] */ 0,
    /* riq[3][1] */ 0,
    /* riq[3][2] */ 0,
    /* riq[4][0] */ 0,
    /* riq[4][1] */ 0,
    /* riq[4][2] */ 0,
    /* riq[5][0] */ 0,
    /* riq[5][1] */ 0,
    /* riq[5][2] */ 0,
    /* riq[6][0] */ 0,
    /* riq[6][1] */ 0,
    /* riq[6][2] */ 0,
    /* riq[7][0] */ 0,
    /* riq[7][1] */ 0,
    /* riq[7][2] */ 0,
    /* riq[8][0] */ 0,
    /* riq[8][1] */ 0,
    /* riq[8][2] */ 0,
    /* presq[0] */ 0,
    /* presq[1] */ 0,
    /* presq[2] */ 0,
    /* presq[3] */ 0,
    /* presq[4] */ 0,
    /* presq[5] */ 0,
    /* presq[6] */ 0,
    /* presq[7] */ 0,
    /* presq[8] */ 0,
    /* presq[9] */ 0,
    /* presq[10] */ 0,
    /* stabvelq */ 3,
    /* stabposq */ 3,

/* End of values from input file */

};
sdgstate_t sdgstate;
sdglhs_t sdglhs;
sdgrhs_t sdgrhs;
sdgtemp_t sdgtemp;


void sdinit(void)
{
/*
Initialization routine


 This routine must be called before the first call to sdstate(), after
 supplying values for any `?' parameters in the input.
*/
    double sumsq,norminv;
    int i,j,k;


/* Check that all `?' parameters have been assigned values */

    for (k = 0; k < 3; k++) {
        if (gravq[k] == 1) {
            sdseterr(7,25);
        }
    }
    for (k = 0; k < 9; k++) {
        if (mkq[k] == 1) {
            sdseterr(7,26);
        }
        for (i = 0; i < 3; i++) {
            if (rkq[k][i] == 1) {
                sdseterr(7,29);
            }
            if (riq[k][i] == 1) {
                sdseterr(7,30);
            }
            for (j = 0; j < 3; j++) {
                if (ikq[k][i][j] == 1) {
                    sdseterr(7,27);
                }
            }
        }
    }
    for (k = 0; k < 11; k++) {
        for (i = 0; i < 3; i++) {
            if (pinq[k][i] == 1) {
                sdseterr(7,28);
            }
        }
    }

/* Normalize pin vectors if necessary */


/* Zero out Vpk and Wpk */

    for (i = 0; i < 11; i++) {
        for (j = i; j <= 10; j++) {
            for (k = 0; k < 3; k++) {
                Vpk[i][j][k] = 0.;
                Wpk[i][j][k] = 0.;
            }
        }
    }

/* Compute pseudobody-related constants */

    rcom[0][0] = 0.;
    rcom[0][1] = 0.;
    rcom[0][2] = 0.;
    rcom[1][0] = 0.;
    rcom[1][1] = 0.;
    rcom[1][2] = 0.;
    rcom[2][0] = 0.;
    rcom[2][1] = 0.;
    rcom[2][2] = 0.;
    rcom[3][0] = 0.;
    rcom[3][1] = 0.;
    rcom[3][2] = 0.;
    rcom[4][0] = 0.;
    rcom[4][1] = 0.;
    rcom[4][2] = 0.;
    rcom[5][0] = 0.;
    rcom[5][1] = 0.;
    rcom[5][2] = 0.;
    rcom[6][0] = 0.;
    rcom[6][1] = 0.;
    rcom[6][2] = 0.;
    rcom[7][0] = 0.;
    rcom[7][1] = 0.;
    rcom[7][2] = 0.;
    rcom[8][0] = 0.;
    rcom[8][1] = 0.;
    rcom[8][2] = 0.;

/* Compute mass properties-related constants */

    mtot = 42.2;
    sdserialno(&i);
    if (i != 30123) {
        sdseterr(7,41);
    }
    roustate = 1;
}

/* Convert state to form using 1-2-3 Euler angles for ball joints. */

void sdst2ang(double st[11],
    double stang[11])
{
    int i;

    for (i = 0; i < 11; i++) {
        stang[i] = st[i];
    }
}

/* Convert 1-2-3 form of state back to Euler parameters for ball joints. */

void sdang2st(double stang[11],
    double st[11])
{
    int i;

    for (i = 0; i < 11; i++) {
        st[i] = stang[i];
    }
}

/* Normalize Euler parameters in state. */

void sdnrmsterr(double st[11],
    double normst[11],
    int routine)
{
    int i;

    for (i = 0; i < 11; i++) {
        normst[i] = st[i];
    }
}

void sdnormst(double st[11],
    double normst[11])
{

    sdnrmsterr(st,normst,0);
}

void sdstate(double timein,
    double qin[11],
    double uin[11])
{
/*
Compute kinematic information and store it in sdgstate.

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
    int i,j,qchg,uchg;

    if ((roustate != 1) && (roustate != 2) && (roustate != 3)) {
        sdseterr(8,22);
        return;
    }
    if (roustate == 1) {
        for (i = 0; i < 11; i++) {
            if (presq[i] == 1) {
                sdseterr(8,31);
            }
        }
    }
/*
See if time or any qs have changed since last call
*/
    if ((roustate != 1) && (timein == curtim)) {
        qchg = 0;
        for (i = 0; i < 11; i++) {
            if (qin[i] != q[i]) {
                qchg = 1;
                break;
            }
        }
    } else {
        qchg = 1;
    }
/*
If time and qs are unchanged, check us
*/
    if (qchg == 0) {
        uchg = 0;
        for (i = 0; i < 11; i++) {
            if (uin[i] != u[i]) {
                uchg = 1;
                break;
            }
        }
    } else {
        uchg = 1;
    }
    curtim = timein;
    roustate = 2;
    if (qchg == 0) {
        goto skipqs;
    }
/*
Position-related variables need to be computed
*/
    vpkflg = 0;
    mmflg = 0;
    mmlduflg = 0;
    wwflg = 0;
    for (i = 0; i < 11; i++) {
        q[i] = qin[i];
    }
/*
Compute sines and cosines of q
*/
    s2 = sin(q[2]);
    c2 = cos(q[2]);
    s3 = sin(q[3]);
    c3 = cos(q[3]);
    s4 = sin(q[4]);
    c4 = cos(q[4]);
    s5 = sin(q[5]);
    c5 = cos(q[5]);
    s6 = sin(q[6]);
    c6 = cos(q[6]);
    s7 = sin(q[7]);
    c7 = cos(q[7]);
    s8 = sin(q[8]);
    c8 = cos(q[8]);
    s9 = sin(q[9]);
    c9 = cos(q[9]);
    s10 = sin(q[10]);
    c10 = cos(q[10]);
/*
Compute across-axis direction cosines Cik
*/
/*
Compute across-joint direction cosines Cib
*/
/*
Compute gravity
*/
    gk[3][0] = (9.8*((s2*c3)+(s3*c2)));
    gk[3][2] = (9.8*((s2*s3)-(c2*c3)));
    gk[4][0] = ((gk[3][0]*c4)-(gk[3][2]*s4));
    gk[4][2] = ((gk[3][0]*s4)+(gk[3][2]*c4));
    gk[5][0] = ((gk[4][0]*c5)-(gk[4][2]*s5));
    gk[5][2] = ((gk[4][0]*s5)+(gk[4][2]*c5));
    gk[6][0] = (9.8*((s2*c6)+(s6*c2)));
    gk[6][2] = (9.8*((s2*s6)-(c2*c6)));
    gk[7][0] = ((gk[6][0]*c7)-(gk[6][2]*s7));
    gk[7][2] = ((gk[6][0]*s7)+(gk[6][2]*c7));
    gk[8][0] = ((gk[7][0]*c8)-(gk[7][2]*s8));
    gk[8][2] = ((gk[7][0]*s8)+(gk[7][2]*c8));
    gk[9][0] = (9.8*((s2*c9)+(s9*c2)));
    gk[9][2] = (9.8*((s2*s9)-(c2*c9)));
    gk[10][0] = (9.8*((s2*c10)+(s10*c2)));
    gk[10][2] = (9.8*((s2*s10)-(c2*c10)));
/*
Compute cnk & cnb (direction cosines in N)
*/
    cnk[3][0][0] = ((c2*c3)-(s2*s3));
    cnk[3][0][2] = ((s2*c3)+(s3*c2));
    cnk[3][2][0] = -((s2*c3)+(s3*c2));
    cnk[3][2][2] = ((c2*c3)-(s2*s3));
    cnk[4][0][0] = ((cnk[3][0][0]*c4)-(cnk[3][0][2]*s4));
    cnk[4][0][2] = ((cnk[3][0][0]*s4)+(cnk[3][0][2]*c4));
    cnk[4][2][0] = ((cnk[3][2][0]*c4)-(cnk[3][2][2]*s4));
    cnk[4][2][2] = ((cnk[3][2][0]*s4)+(cnk[3][2][2]*c4));
    cnk[5][0][0] = ((cnk[4][0][0]*c5)-(cnk[4][0][2]*s5));
    cnk[5][0][2] = ((cnk[4][0][0]*s5)+(cnk[4][0][2]*c5));
    cnk[5][2][0] = ((cnk[4][2][0]*c5)-(cnk[4][2][2]*s5));
    cnk[5][2][2] = ((cnk[4][2][0]*s5)+(cnk[4][2][2]*c5));
    cnk[6][0][0] = ((c2*c6)-(s2*s6));
    cnk[6][0][2] = ((s2*c6)+(s6*c2));
    cnk[6][2][0] = -((s2*c6)+(s6*c2));
    cnk[6][2][2] = ((c2*c6)-(s2*s6));
    cnk[7][0][0] = ((cnk[6][0][0]*c7)-(cnk[6][0][2]*s7));
    cnk[7][0][2] = ((cnk[6][0][0]*s7)+(cnk[6][0][2]*c7));
    cnk[7][2][0] = ((cnk[6][2][0]*c7)-(cnk[6][2][2]*s7));
    cnk[7][2][2] = ((cnk[6][2][0]*s7)+(cnk[6][2][2]*c7));
    cnk[8][0][0] = ((cnk[7][0][0]*c8)-(cnk[7][0][2]*s8));
    cnk[8][0][2] = ((cnk[7][0][0]*s8)+(cnk[7][0][2]*c8));
    cnk[8][2][0] = ((cnk[7][2][0]*c8)-(cnk[7][2][2]*s8));
    cnk[8][2][2] = ((cnk[7][2][0]*s8)+(cnk[7][2][2]*c8));
    cnk[9][0][0] = ((c2*c9)-(s2*s9));
    cnk[9][0][2] = ((s2*c9)+(s9*c2));
    cnk[9][2][0] = -((s2*c9)+(s9*c2));
    cnk[9][2][2] = ((c2*c9)-(s2*s9));
    cnk[10][0][0] = ((c2*c10)-(s2*s10));
    cnk[10][0][2] = ((s2*c10)+(s10*c2));
    cnk[10][2][0] = -((s2*c10)+(s10*c2));
    cnk[10][2][2] = ((c2*c10)-(s2*s10));
    cnb[0][0][0] = c2;
    cnb[0][0][1] = 0.;
    cnb[0][0][2] = s2;
    cnb[0][1][0] = 0.;
    cnb[0][1][1] = 1.;
    cnb[0][1][2] = 0.;
    cnb[0][2][0] = -s2;
    cnb[0][2][1] = 0.;
    cnb[0][2][2] = c2;
    cnb[1][0][0] = cnk[3][0][0];
    cnb[1][0][1] = 0.;
    cnb[1][0][2] = cnk[3][0][2];
    cnb[1][1][0] = 0.;
    cnb[1][1][1] = 1.;
    cnb[1][1][2] = 0.;
    cnb[1][2][0] = cnk[3][2][0];
    cnb[1][2][1] = 0.;
    cnb[1][2][2] = cnk[3][2][2];
    cnb[2][0][0] = cnk[4][0][0];
    cnb[2][0][1] = 0.;
    cnb[2][0][2] = cnk[4][0][2];
    cnb[2][1][0] = 0.;
    cnb[2][1][1] = 1.;
    cnb[2][1][2] = 0.;
    cnb[2][2][0] = cnk[4][2][0];
    cnb[2][2][1] = 0.;
    cnb[2][2][2] = cnk[4][2][2];
    cnb[3][0][0] = cnk[5][0][0];
    cnb[3][0][1] = 0.;
    cnb[3][0][2] = cnk[5][0][2];
    cnb[3][1][0] = 0.;
    cnb[3][1][1] = 1.;
    cnb[3][1][2] = 0.;
    cnb[3][2][0] = cnk[5][2][0];
    cnb[3][2][1] = 0.;
    cnb[3][2][2] = cnk[5][2][2];
    cnb[4][0][0] = cnk[6][0][0];
    cnb[4][0][1] = 0.;
    cnb[4][0][2] = cnk[6][0][2];
    cnb[4][1][0] = 0.;
    cnb[4][1][1] = 1.;
    cnb[4][1][2] = 0.;
    cnb[4][2][0] = cnk[6][2][0];
    cnb[4][2][1] = 0.;
    cnb[4][2][2] = cnk[6][2][2];
    cnb[5][0][0] = cnk[7][0][0];
    cnb[5][0][1] = 0.;
    cnb[5][0][2] = cnk[7][0][2];
    cnb[5][1][0] = 0.;
    cnb[5][1][1] = 1.;
    cnb[5][1][2] = 0.;
    cnb[5][2][0] = cnk[7][2][0];
    cnb[5][2][1] = 0.;
    cnb[5][2][2] = cnk[7][2][2];
    cnb[6][0][0] = cnk[8][0][0];
    cnb[6][0][1] = 0.;
    cnb[6][0][2] = cnk[8][0][2];
    cnb[6][1][0] = 0.;
    cnb[6][1][1] = 1.;
    cnb[6][1][2] = 0.;
    cnb[6][2][0] = cnk[8][2][0];
    cnb[6][2][1] = 0.;
    cnb[6][2][2] = cnk[8][2][2];
    cnb[7][0][0] = cnk[9][0][0];
    cnb[7][0][1] = 0.;
    cnb[7][0][2] = cnk[9][0][2];
    cnb[7][1][0] = 0.;
    cnb[7][1][1] = 1.;
    cnb[7][1][2] = 0.;
    cnb[7][2][0] = cnk[9][2][0];
    cnb[7][2][1] = 0.;
    cnb[7][2][2] = cnk[9][2][2];
    cnb[8][0][0] = cnk[10][0][0];
    cnb[8][0][1] = 0.;
    cnb[8][0][2] = cnk[10][0][2];
    cnb[8][1][0] = 0.;
    cnb[8][1][1] = 1.;
    cnb[8][1][2] = 0.;
    cnb[8][2][0] = cnk[10][2][0];
    cnb[8][2][1] = 0.;
    cnb[8][2][2] = cnk[10][2][2];
/*
Compute q-related auxiliary variables
*/
    rik[3][2] = -(.211+(.25*c3));
    rik[4][2] = -(.23+(.239*c4));
    rik[5][2] = -(.05+(.22*c5));
    rik[6][2] = -(.211+(.25*c6));
    rik[7][2] = -(.23+(.239*c7));
    rik[8][2] = -(.05+(.22*c8));
    rik[9][2] = ((.15*c9)-.2);
    rik[10][2] = ((.15*c10)-.2);
/*
Compute rnk & rnb (mass center locations in N)
*/
    rnk[2][0] = (q[0]-(.25*s2));
    rnk[2][2] = (q[1]-(.25*c2));
    rnk[3][0] = ((rnk[2][0]-(.25*s2))-(.211*cnk[3][0][2]));
    rnk[3][2] = ((rnk[2][2]-(.25*c2))-(.211*cnk[3][2][2]));
    rnk[4][0] = ((rnk[3][0]-(.239*cnk[3][0][2]))-(.23*cnk[4][0][2]));
    rnk[4][2] = ((rnk[3][2]-(.239*cnk[3][2][2]))-(.23*cnk[4][2][2]));
    rnk[5][0] = ((rnk[4][0]-(.22*cnk[4][0][2]))-(.05*cnk[5][0][2]));
    rnk[5][2] = ((rnk[4][2]-(.22*cnk[4][2][2]))-(.05*cnk[5][2][2]));
    rnk[6][0] = ((rnk[2][0]-(.25*s2))-(.211*cnk[6][0][2]));
    rnk[6][2] = ((rnk[2][2]-(.25*c2))-(.211*cnk[6][2][2]));
    rnk[7][0] = ((rnk[6][0]-(.239*cnk[6][0][2]))-(.23*cnk[7][0][2]));
    rnk[7][2] = ((rnk[6][2]-(.239*cnk[6][2][2]))-(.23*cnk[7][2][2]));
    rnk[8][0] = ((rnk[7][0]-(.22*cnk[7][0][2]))-(.05*cnk[8][0][2]));
    rnk[8][2] = ((rnk[7][2]-(.22*cnk[7][2][2]))-(.05*cnk[8][2][2]));
    rnk[9][0] = ((rnk[2][0]+(.15*s2))-(.2*cnk[9][0][2]));
    rnk[9][2] = ((rnk[2][2]+(.15*c2))-(.2*cnk[9][2][2]));
    rnk[10][0] = ((rnk[2][0]+(.15*s2))-(.2*cnk[10][0][2]));
    rnk[10][2] = ((rnk[2][2]+(.15*c2))-(.2*cnk[10][2][2]));
    rnb[0][0] = rnk[2][0];
    rnb[0][1] = 0.;
    rnb[0][2] = rnk[2][2];
    rnb[1][0] = rnk[3][0];
    rnb[1][1] = -.1;
    rnb[1][2] = rnk[3][2];
    rnb[2][0] = rnk[4][0];
    rnb[2][1] = -.1;
    rnb[2][2] = rnk[4][2];
    rnb[3][0] = rnk[5][0];
    rnb[3][1] = -.1;
    rnb[3][2] = rnk[5][2];
    rnb[4][0] = rnk[6][0];
    rnb[4][1] = .1;
    rnb[4][2] = rnk[6][2];
    rnb[5][0] = rnk[7][0];
    rnb[5][1] = .1;
    rnb[5][2] = rnk[7][2];
    rnb[6][0] = rnk[8][0];
    rnb[6][1] = .1;
    rnb[6][2] = rnk[8][2];
    rnb[7][0] = rnk[9][0];
    rnb[7][1] = -.1;
    rnb[7][2] = rnk[9][2];
    rnb[8][0] = rnk[10][0];
    rnb[8][1] = .1;
    rnb[8][2] = rnk[10][2];
/*
Compute com (system mass center location in N)
*/
    com[0] = (.023696682464455*((2.*rnk[10][0])+((2.*rnk[9][0])+((.2*rnk[8][0])+
      ((3.3*rnk[7][0])+((3.32*rnk[6][0])+((.2*rnk[5][0])+((3.3*rnk[4][0])+((3.32
      *rnk[3][0])+(24.56*rnk[2][0]))))))))));
    com[1] = 0.;
    com[2] = (.023696682464455*((2.*rnk[10][2])+((2.*rnk[9][2])+((.2*rnk[8][2])+
      ((3.3*rnk[7][2])+((3.32*rnk[6][2])+((.2*rnk[5][2])+((3.3*rnk[4][2])+((3.32
      *rnk[3][2])+(24.56*rnk[2][2]))))))))));
    skipqs: ;
    if (uchg == 0) {
        goto skipus;
    }
/*
Velocity-related variables need to be computed
*/
    inerflg = 0;
    for (i = 0; i < 11; i++) {
        u[i] = uin[i];
    }
/*
Compute u-related auxiliary variables
*/
/*
Compute wk & wb (angular velocities)
*/
    wk[3][1] = (u[2]+u[3]);
    wk[4][1] = (u[4]+wk[3][1]);
    wk[5][1] = (u[5]+wk[4][1]);
    wk[6][1] = (u[2]+u[6]);
    wk[7][1] = (u[7]+wk[6][1]);
    wk[8][1] = (u[8]+wk[7][1]);
    wk[9][1] = (u[2]+u[9]);
    wk[10][1] = (u[2]+u[10]);
    wb[0][0] = 0.;
    wb[0][1] = u[2];
    wb[0][2] = 0.;
    wb[1][0] = 0.;
    wb[1][1] = wk[3][1];
    wb[1][2] = 0.;
    wb[2][0] = 0.;
    wb[2][1] = wk[4][1];
    wb[2][2] = 0.;
    wb[3][0] = 0.;
    wb[3][1] = wk[5][1];
    wb[3][2] = 0.;
    wb[4][0] = 0.;
    wb[4][1] = wk[6][1];
    wb[4][2] = 0.;
    wb[5][0] = 0.;
    wb[5][1] = wk[7][1];
    wb[5][2] = 0.;
    wb[6][0] = 0.;
    wb[6][1] = wk[8][1];
    wb[6][2] = 0.;
    wb[7][0] = 0.;
    wb[7][1] = wk[9][1];
    wb[7][2] = 0.;
    wb[8][0] = 0.;
    wb[8][1] = wk[10][1];
    wb[8][2] = 0.;
/*
Compute auxiliary variables involving wk
*/
/*
Compute temporaries for use in SDRHS
*/
    w1w1[0] = (u[2]*u[2]);
    w1w1[1] = (wk[3][1]*wk[3][1]);
    w1w1[2] = (wk[4][1]*wk[4][1]);
    w1w1[3] = (wk[5][1]*wk[5][1]);
    w1w1[4] = (wk[6][1]*wk[6][1]);
    w1w1[5] = (wk[7][1]*wk[7][1]);
    w1w1[6] = (wk[8][1]*wk[8][1]);
    w1w1[7] = (wk[9][1]*wk[9][1]);
    w1w1[8] = (wk[10][1]*wk[10][1]);
/*
Compute vnk & vnb (mass center linear velocities in N)
*/
    vnk[2][0] = (u[0]-(.25*(u[2]*c2)));
    vnk[2][2] = (u[1]+(.25*(u[2]*s2)));
    vnk[3][0] = ((vnk[2][0]-(.25*(u[2]*c2)))-(.211*(cnk[3][0][0]*wk[3][1])));
    vnk[3][2] = ((vnk[2][2]+(.25*(u[2]*s2)))-(.211*(cnk[3][2][0]*wk[3][1])));
    vnk[4][0] = ((vnk[3][0]-(.239*(cnk[3][0][0]*wk[3][1])))-(.23*(cnk[4][0][0]*
      wk[4][1])));
    vnk[4][2] = ((vnk[3][2]-(.239*(cnk[3][2][0]*wk[3][1])))-(.23*(cnk[4][2][0]*
      wk[4][1])));
    vnk[5][0] = ((vnk[4][0]-(.22*(cnk[4][0][0]*wk[4][1])))-(.05*(cnk[5][0][0]*
      wk[5][1])));
    vnk[5][2] = ((vnk[4][2]-(.22*(cnk[4][2][0]*wk[4][1])))-(.05*(cnk[5][2][0]*
      wk[5][1])));
    vnk[6][0] = ((vnk[2][0]-(.25*(u[2]*c2)))-(.211*(cnk[6][0][0]*wk[6][1])));
    vnk[6][2] = ((vnk[2][2]+(.25*(u[2]*s2)))-(.211*(cnk[6][2][0]*wk[6][1])));
    vnk[7][0] = ((vnk[6][0]-(.239*(cnk[6][0][0]*wk[6][1])))-(.23*(cnk[7][0][0]*
      wk[7][1])));
    vnk[7][2] = ((vnk[6][2]-(.239*(cnk[6][2][0]*wk[6][1])))-(.23*(cnk[7][2][0]*
      wk[7][1])));
    vnk[8][0] = ((vnk[7][0]-(.22*(cnk[7][0][0]*wk[7][1])))-(.05*(cnk[8][0][0]*
      wk[8][1])));
    vnk[8][2] = ((vnk[7][2]-(.22*(cnk[7][2][0]*wk[7][1])))-(.05*(cnk[8][2][0]*
      wk[8][1])));
    vnk[9][0] = ((vnk[2][0]+(.15*(u[2]*c2)))-(.2*(cnk[9][0][0]*wk[9][1])));
    vnk[9][2] = ((vnk[2][2]-(.15*(u[2]*s2)))-(.2*(cnk[9][2][0]*wk[9][1])));
    vnk[10][0] = ((vnk[2][0]+(.15*(u[2]*c2)))-(.2*(cnk[10][0][0]*wk[10][1])));
    vnk[10][2] = ((vnk[2][2]-(.15*(u[2]*s2)))-(.2*(cnk[10][2][0]*wk[10][1])));
    vnb[0][0] = vnk[2][0];
    vnb[0][1] = 0.;
    vnb[0][2] = vnk[2][2];
    vnb[1][0] = vnk[3][0];
    vnb[1][1] = 0.;
    vnb[1][2] = vnk[3][2];
    vnb[2][0] = vnk[4][0];
    vnb[2][1] = 0.;
    vnb[2][2] = vnk[4][2];
    vnb[3][0] = vnk[5][0];
    vnb[3][1] = 0.;
    vnb[3][2] = vnk[5][2];
    vnb[4][0] = vnk[6][0];
    vnb[4][1] = 0.;
    vnb[4][2] = vnk[6][2];
    vnb[5][0] = vnk[7][0];
    vnb[5][1] = 0.;
    vnb[5][2] = vnk[7][2];
    vnb[6][0] = vnk[8][0];
    vnb[6][1] = 0.;
    vnb[6][2] = vnk[8][2];
    vnb[7][0] = vnk[9][0];
    vnb[7][1] = 0.;
    vnb[7][2] = vnk[9][2];
    vnb[8][0] = vnk[10][0];
    vnb[8][1] = 0.;
    vnb[8][2] = vnk[10][2];
/*
Compute qdot (kinematical equations)
*/
    qdot[0] = u[0];
    qdot[1] = u[1];
    qdot[2] = u[2];
    qdot[3] = u[3];
    qdot[4] = u[4];
    qdot[5] = u[5];
    qdot[6] = u[6];
    qdot[7] = u[7];
    qdot[8] = u[8];
    qdot[9] = u[9];
    qdot[10] = u[10];
    skipus: ;
/*
Initialize applied forces and torques to zero
*/
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            ufk[i][j] = 0.;
            utk[i][j] = 0.;
        }
    }
    for (i = 0; i < 11; i++) {
        utau[i] = 0.;
    }
    ltauflg = 0;
    fs0flg = 0;
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  159 adds/subtracts/negates
                    243 multiplies
                      0 divides
                    372 assignments
*/
}

void sdqdot(double oqdot[11])
{
/*
Return position coordinate derivatives for tree joints.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(63,23);
        return;
    }
    for (i = 0; i <= 10; i++) {
        oqdot[i] = qdot[i];
    }
}

void sdu2qdot(double uin[11],
    double oqdot[11])
{
/*
Convert velocities to qdots.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(64,23);
        return;
    }
    for (i = 0; i <= 10; i++) {
        oqdot[i] = uin[i];
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     11 assignments
*/
}

void sdpsstate(double lqin[1])
{

    if (roustate != 2) {
        sdseterr(9,23);
        return;
    }
}

void sddovpk(void)
{

    if (vpkflg == 0) {
/*
Compute Wpk (partial angular velocities)
*/
        Wpk[2][2][1] = 1.;
        Wpk[2][3][1] = 1.;
        Wpk[2][4][1] = 1.;
        Wpk[2][5][1] = 1.;
        Wpk[2][6][1] = 1.;
        Wpk[2][7][1] = 1.;
        Wpk[2][8][1] = 1.;
        Wpk[2][9][1] = 1.;
        Wpk[2][10][1] = 1.;
        Wpk[3][3][1] = 1.;
        Wpk[3][4][1] = 1.;
        Wpk[3][5][1] = 1.;
        Wpk[4][4][1] = 1.;
        Wpk[4][5][1] = 1.;
        Wpk[5][5][1] = 1.;
        Wpk[6][6][1] = 1.;
        Wpk[6][7][1] = 1.;
        Wpk[6][8][1] = 1.;
        Wpk[7][7][1] = 1.;
        Wpk[7][8][1] = 1.;
        Wpk[8][8][1] = 1.;
        Wpk[9][9][1] = 1.;
        Wpk[10][10][1] = 1.;
/*
Compute Vpk (partial velocities)
*/
        Vpk[0][0][0] = 1.;
        Vpk[0][1][0] = 1.;
        Vpk[0][2][0] = c2;
        Vpk[0][2][2] = s2;
        Vpk[0][3][0] = ((c2*c3)-(s2*s3));
        Vpk[0][3][2] = ((s2*c3)+(s3*c2));
        Vpk[0][4][0] = ((Vpk[0][3][0]*c4)-(Vpk[0][3][2]*s4));
        Vpk[0][4][2] = ((Vpk[0][3][0]*s4)+(Vpk[0][3][2]*c4));
        Vpk[0][5][0] = ((Vpk[0][4][0]*c5)-(Vpk[0][4][2]*s5));
        Vpk[0][5][2] = ((Vpk[0][4][0]*s5)+(Vpk[0][4][2]*c5));
        Vpk[0][6][0] = ((c2*c6)-(s2*s6));
        Vpk[0][6][2] = ((s2*c6)+(s6*c2));
        Vpk[0][7][0] = ((Vpk[0][6][0]*c7)-(Vpk[0][6][2]*s7));
        Vpk[0][7][2] = ((Vpk[0][6][0]*s7)+(Vpk[0][6][2]*c7));
        Vpk[0][8][0] = ((Vpk[0][7][0]*c8)-(Vpk[0][7][2]*s8));
        Vpk[0][8][2] = ((Vpk[0][7][0]*s8)+(Vpk[0][7][2]*c8));
        Vpk[0][9][0] = ((c2*c9)-(s2*s9));
        Vpk[0][9][2] = ((s2*c9)+(s9*c2));
        Vpk[0][10][0] = ((c2*c10)-(s2*s10));
        Vpk[0][10][2] = ((s2*c10)+(s10*c2));
        Vpk[1][1][2] = 1.;
        Vpk[1][2][0] = -s2;
        Vpk[1][2][2] = c2;
        Vpk[1][3][0] = -((s2*c3)+(s3*c2));
        Vpk[1][3][2] = ((c2*c3)-(s2*s3));
        Vpk[1][4][0] = ((Vpk[1][3][0]*c4)-(Vpk[1][3][2]*s4));
        Vpk[1][4][2] = ((Vpk[1][3][0]*s4)+(Vpk[1][3][2]*c4));
        Vpk[1][5][0] = ((Vpk[1][4][0]*c5)-(Vpk[1][4][2]*s5));
        Vpk[1][5][2] = ((Vpk[1][4][0]*s5)+(Vpk[1][4][2]*c5));
        Vpk[1][6][0] = -((s2*c6)+(s6*c2));
        Vpk[1][6][2] = ((c2*c6)-(s2*s6));
        Vpk[1][7][0] = ((Vpk[1][6][0]*c7)-(Vpk[1][6][2]*s7));
        Vpk[1][7][2] = ((Vpk[1][6][0]*s7)+(Vpk[1][6][2]*c7));
        Vpk[1][8][0] = ((Vpk[1][7][0]*c8)-(Vpk[1][7][2]*s8));
        Vpk[1][8][2] = ((Vpk[1][7][0]*s8)+(Vpk[1][7][2]*c8));
        Vpk[1][9][0] = -((s2*c9)+(s9*c2));
        Vpk[1][9][2] = ((c2*c9)-(s2*s9));
        Vpk[1][10][0] = -((s2*c10)+(s10*c2));
        Vpk[1][10][2] = ((c2*c10)-(s2*s10));
        Vpk[2][2][0] = -.25;
        Vpk[2][3][0] = -(.211+(.5*c3));
        Vpk[2][3][2] = -(.5*s3);
        VWri[2][4][0] = (Vpk[2][3][0]-.239);
        Vpk[2][4][0] = (((.5*(s3*s4))+(VWri[2][4][0]*c4))-.23);
        Vpk[2][4][2] = ((VWri[2][4][0]*s4)-(.5*(s3*c4)));
        VWri[2][5][0] = (Vpk[2][4][0]-.22);
        Vpk[2][5][0] = (((VWri[2][5][0]*c5)-(Vpk[2][4][2]*s5))-.05);
        Vpk[2][5][2] = ((Vpk[2][4][2]*c5)+(VWri[2][5][0]*s5));
        Vpk[2][6][0] = -(.211+(.5*c6));
        Vpk[2][6][2] = -(.5*s6);
        VWri[2][7][0] = (Vpk[2][6][0]-.239);
        Vpk[2][7][0] = (((.5*(s6*s7))+(VWri[2][7][0]*c7))-.23);
        Vpk[2][7][2] = ((VWri[2][7][0]*s7)-(.5*(s6*c7)));
        VWri[2][8][0] = (Vpk[2][7][0]-.22);
        Vpk[2][8][0] = (((VWri[2][8][0]*c8)-(Vpk[2][7][2]*s8))-.05);
        Vpk[2][8][2] = ((Vpk[2][7][2]*c8)+(VWri[2][8][0]*s8));
        Vpk[2][9][0] = -(.2+(.1*c9));
        Vpk[2][9][2] = -(.1*s9);
        Vpk[2][10][0] = -(.2+(.1*c10));
        Vpk[2][10][2] = -(.1*s10);
        Vpk[3][3][0] = -.211;
        Vpk[3][4][0] = -(.23+(.45*c4));
        Vpk[3][4][2] = -(.45*s4);
        VWri[3][5][0] = (Vpk[3][4][0]-.22);
        Vpk[3][5][0] = (((.45*(s4*s5))+(VWri[3][5][0]*c5))-.05);
        Vpk[3][5][2] = ((VWri[3][5][0]*s5)-(.45*(s4*c5)));
        Vpk[4][4][0] = -.23;
        Vpk[4][5][0] = -(.05+(.45*c5));
        Vpk[4][5][2] = -(.45*s5);
        Vpk[5][5][0] = -.05;
        Vpk[6][6][0] = -.211;
        Vpk[6][7][0] = -(.23+(.45*c7));
        Vpk[6][7][2] = -(.45*s7);
        VWri[6][8][0] = (Vpk[6][7][0]-.22);
        Vpk[6][8][0] = (((.45*(s7*s8))+(VWri[6][8][0]*c8))-.05);
        Vpk[6][8][2] = ((VWri[6][8][0]*s8)-(.45*(s7*c8)));
        Vpk[7][7][0] = -.23;
        Vpk[7][8][0] = -(.05+(.45*c8));
        Vpk[7][8][2] = -(.45*s8);
        Vpk[8][8][0] = -.05;
        Vpk[9][9][0] = -.2;
        Vpk[10][10][0] = -.2;
        vpkflg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   85 adds/subtracts/negates
                    112 multiplies
                      0 divides
                    105 assignments
*/
}

void sddoltau(void)
{

/*
Compute effect of loop hinge torques
*/
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                      0 assignments
*/
}

void sddoiner(void)
{

/*
Compute inertial accelerations and related temps
*/
    if (inerflg == 0) {
/*
Compute Otk (inertial angular acceleration)
*/
/*
Compute Atk (inertial linear acceleration)
*/
        Atk[2][2] = (.25*(u[2]*u[2]));
        AiOiWi[3][2] = (Atk[2][2]+(.25*(u[2]*u[2])));
        Atk[3][0] = -(AiOiWi[3][2]*s3);
        Atk[3][2] = ((.211*(wk[3][1]*wk[3][1]))+(AiOiWi[3][2]*c3));
        AiOiWi[4][2] = (Atk[3][2]+(.239*(wk[3][1]*wk[3][1])));
        Atk[4][0] = ((Atk[3][0]*c4)-(AiOiWi[4][2]*s4));
        Atk[4][2] = ((.23*(wk[4][1]*wk[4][1]))+((AiOiWi[4][2]*c4)+(Atk[3][0]*s4)
          ));
        AiOiWi[5][2] = (Atk[4][2]+(.22*(wk[4][1]*wk[4][1])));
        Atk[5][0] = ((Atk[4][0]*c5)-(AiOiWi[5][2]*s5));
        Atk[5][2] = ((.05*(wk[5][1]*wk[5][1]))+((AiOiWi[5][2]*c5)+(Atk[4][0]*s5)
          ));
        AiOiWi[6][2] = (Atk[2][2]+(.25*(u[2]*u[2])));
        Atk[6][0] = -(AiOiWi[6][2]*s6);
        Atk[6][2] = ((.211*(wk[6][1]*wk[6][1]))+(AiOiWi[6][2]*c6));
        AiOiWi[7][2] = (Atk[6][2]+(.239*(wk[6][1]*wk[6][1])));
        Atk[7][0] = ((Atk[6][0]*c7)-(AiOiWi[7][2]*s7));
        Atk[7][2] = ((.23*(wk[7][1]*wk[7][1]))+((AiOiWi[7][2]*c7)+(Atk[6][0]*s7)
          ));
        AiOiWi[8][2] = (Atk[7][2]+(.22*(wk[7][1]*wk[7][1])));
        Atk[8][0] = ((Atk[7][0]*c8)-(AiOiWi[8][2]*s8));
        Atk[8][2] = ((.05*(wk[8][1]*wk[8][1]))+((AiOiWi[8][2]*c8)+(Atk[7][0]*s8)
          ));
        AiOiWi[9][2] = (Atk[2][2]-(.15*(u[2]*u[2])));
        Atk[9][0] = -(AiOiWi[9][2]*s9);
        Atk[9][2] = ((.2*(wk[9][1]*wk[9][1]))+(AiOiWi[9][2]*c9));
        AiOiWi[10][2] = (Atk[2][2]-(.15*(u[2]*u[2])));
        Atk[10][0] = -(AiOiWi[10][2]*s10);
        Atk[10][2] = ((.2*(wk[10][1]*wk[10][1]))+(AiOiWi[10][2]*c10));
        inerflg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   28 adds/subtracts/negates
                     58 multiplies
                      0 divides
                     25 assignments
*/
}

void sddofs0(void)
{

/*
Compute effect of all applied loads
*/
    if (fs0flg == 0) {
        sddoltau();
        sddoiner();
/*
Compute Fstar (forces)
*/
        Fstar[2][0] = -(ufk[0][0]+(240.688*s2));
        Fstar[2][2] = ((24.56*(Atk[2][2]+(9.8*c2)))-ufk[0][2]);
        Fstar[3][0] = ((3.32*(Atk[3][0]-gk[3][0]))-ufk[1][0]);
        Fstar[3][2] = ((3.32*(Atk[3][2]-gk[3][2]))-ufk[1][2]);
        Fstar[4][0] = ((3.3*(Atk[4][0]-gk[4][0]))-ufk[2][0]);
        Fstar[4][2] = ((3.3*(Atk[4][2]-gk[4][2]))-ufk[2][2]);
        Fstar[5][0] = ((.2*(Atk[5][0]-gk[5][0]))-ufk[3][0]);
        Fstar[5][2] = ((.2*(Atk[5][2]-gk[5][2]))-ufk[3][2]);
        Fstar[6][0] = ((3.32*(Atk[6][0]-gk[6][0]))-ufk[4][0]);
        Fstar[6][2] = ((3.32*(Atk[6][2]-gk[6][2]))-ufk[4][2]);
        Fstar[7][0] = ((3.3*(Atk[7][0]-gk[7][0]))-ufk[5][0]);
        Fstar[7][2] = ((3.3*(Atk[7][2]-gk[7][2]))-ufk[5][2]);
        Fstar[8][0] = ((.2*(Atk[8][0]-gk[8][0]))-ufk[6][0]);
        Fstar[8][2] = ((.2*(Atk[8][2]-gk[8][2]))-ufk[6][2]);
        Fstar[9][0] = ((2.*(Atk[9][0]-gk[9][0]))-ufk[7][0]);
        Fstar[9][2] = ((2.*(Atk[9][2]-gk[9][2]))-ufk[7][2]);
        Fstar[10][0] = ((2.*(Atk[10][0]-gk[10][0]))-ufk[8][0]);
        Fstar[10][2] = ((2.*(Atk[10][2]-gk[10][2]))-ufk[8][2]);
/*
Compute Tstar (torques)
*/
/*
Compute fs0 (RHS ignoring constraints)
*/
        sddovpk();
        temp[0] = (((Fstar[8][0]*Vpk[0][8][0])+(Fstar[8][2]*Vpk[0][8][2]))+(((
          Fstar[7][0]*Vpk[0][7][0])+(Fstar[7][2]*Vpk[0][7][2]))+(((Fstar[6][0]*
          Vpk[0][6][0])+(Fstar[6][2]*Vpk[0][6][2]))+(((Fstar[5][0]*Vpk[0][5][0])
          +(Fstar[5][2]*Vpk[0][5][2]))+(((Fstar[4][0]*Vpk[0][4][0])+(Fstar[4][2]
          *Vpk[0][4][2]))+(((Fstar[2][0]*c2)+(Fstar[2][2]*s2))+((Fstar[3][0]*
          Vpk[0][3][0])+(Fstar[3][2]*Vpk[0][3][2]))))))));
        fs0[0] = (utau[0]-(((Fstar[10][0]*Vpk[0][10][0])+(Fstar[10][2]*
          Vpk[0][10][2]))+(((Fstar[9][0]*Vpk[0][9][0])+(Fstar[9][2]*Vpk[0][9][2]
          ))+temp[0])));
        temp[0] = (((Fstar[8][0]*Vpk[1][8][0])+(Fstar[8][2]*Vpk[1][8][2]))+(((
          Fstar[7][0]*Vpk[1][7][0])+(Fstar[7][2]*Vpk[1][7][2]))+(((Fstar[6][0]*
          Vpk[1][6][0])+(Fstar[6][2]*Vpk[1][6][2]))+(((Fstar[5][0]*Vpk[1][5][0])
          +(Fstar[5][2]*Vpk[1][5][2]))+(((Fstar[4][0]*Vpk[1][4][0])+(Fstar[4][2]
          *Vpk[1][4][2]))+(((Fstar[2][2]*c2)-(Fstar[2][0]*s2))+((Fstar[3][0]*
          Vpk[1][3][0])+(Fstar[3][2]*Vpk[1][3][2]))))))));
        fs0[1] = (utau[1]-(((Fstar[10][0]*Vpk[1][10][0])+(Fstar[10][2]*
          Vpk[1][10][2]))+(((Fstar[9][0]*Vpk[1][9][0])+(Fstar[9][2]*Vpk[1][9][2]
          ))+temp[0])));
        temp[0] = ((((Fstar[7][0]*Vpk[2][7][0])+(Fstar[7][2]*Vpk[2][7][2]))-
          utk[5][1])+((((Fstar[6][0]*Vpk[2][6][0])-(.5*(Fstar[6][2]*s6)))-
          utk[4][1])+((((Fstar[5][0]*Vpk[2][5][0])+(Fstar[5][2]*Vpk[2][5][2]))-
          utk[3][1])+((((Fstar[4][0]*Vpk[2][4][0])+(Fstar[4][2]*Vpk[2][4][2]))-
          utk[2][1])+((((Fstar[3][0]*Vpk[2][3][0])-(.5*(Fstar[3][2]*s3)))-
          utk[1][1])-(utk[0][1]+(.25*Fstar[2][0])))))));
        fs0[2] = (utau[2]-((((Fstar[10][0]*Vpk[2][10][0])-(.1*(Fstar[10][2]*s10)
          ))-utk[8][1])+((((Fstar[9][0]*Vpk[2][9][0])-(.1*(Fstar[9][2]*s9)))-
          utk[7][1])+((((Fstar[8][0]*Vpk[2][8][0])+(Fstar[8][2]*Vpk[2][8][2]))-
          utk[6][1])+temp[0]))));
        fs0[3] = (utau[3]-((((Fstar[5][0]*Vpk[3][5][0])+(Fstar[5][2]*
          Vpk[3][5][2]))-utk[3][1])+((((Fstar[4][0]*Vpk[3][4][0])-(.45*(
          Fstar[4][2]*s4)))-utk[2][1])-(utk[1][1]+(.211*Fstar[3][0])))));
        fs0[4] = (utau[4]-((((Fstar[5][0]*Vpk[4][5][0])-(.45*(Fstar[5][2]*s5)))-
          utk[3][1])-(utk[2][1]+(.23*Fstar[4][0]))));
        fs0[5] = (utau[5]+(utk[3][1]+(.05*Fstar[5][0])));
        fs0[6] = (utau[6]-((((Fstar[8][0]*Vpk[6][8][0])+(Fstar[8][2]*
          Vpk[6][8][2]))-utk[6][1])+((((Fstar[7][0]*Vpk[6][7][0])-(.45*(
          Fstar[7][2]*s7)))-utk[5][1])-(utk[4][1]+(.211*Fstar[6][0])))));
        fs0[7] = (utau[7]-((((Fstar[8][0]*Vpk[7][8][0])-(.45*(Fstar[8][2]*s8)))-
          utk[6][1])-(utk[5][1]+(.23*Fstar[7][0]))));
        fs0[8] = (utau[8]+(utk[6][1]+(.05*Fstar[8][0])));
        fs0[9] = (utau[9]+(utk[7][1]+(.2*Fstar[9][0])));
        fs0[10] = (utau[10]+(utk[8][1]+(.2*Fstar[10][0])));
        fs0flg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  132 adds/subtracts/negates
                    100 multiplies
                      0 divides
                     32 assignments
*/
}

void sddomm(int routine)
{
    int dumroutine,errnum;
    int i;

    if (mmflg == 0) {
/*
Compute mass matrix (MM)
*/
        sddovpk();
        temp[0] = ((3.3*((Vpk[0][7][0]*Vpk[0][7][0])+(Vpk[0][7][2]*Vpk[0][7][2])
          ))+((3.32*((Vpk[0][6][0]*Vpk[0][6][0])+(Vpk[0][6][2]*Vpk[0][6][2])))+(
          (.2*((Vpk[0][5][0]*Vpk[0][5][0])+(Vpk[0][5][2]*Vpk[0][5][2])))+((3.3*(
          (Vpk[0][4][0]*Vpk[0][4][0])+(Vpk[0][4][2]*Vpk[0][4][2])))+(24.56+(3.32
          *((Vpk[0][3][0]*Vpk[0][3][0])+(Vpk[0][3][2]*Vpk[0][3][2]))))))));
        mm[0][0] = ((2.*((Vpk[0][10][0]*Vpk[0][10][0])+(Vpk[0][10][2]*
          Vpk[0][10][2])))+((2.*((Vpk[0][9][0]*Vpk[0][9][0])+(Vpk[0][9][2]*
          Vpk[0][9][2])))+((.2*((Vpk[0][8][0]*Vpk[0][8][0])+(Vpk[0][8][2]*
          Vpk[0][8][2])))+temp[0])));
        temp[0] = ((3.3*((Vpk[0][7][0]*Vpk[1][7][0])+(Vpk[0][7][2]*Vpk[1][7][2])
          ))+((3.32*((Vpk[0][6][0]*Vpk[1][6][0])+(Vpk[0][6][2]*Vpk[1][6][2])))+(
          (.2*((Vpk[0][5][0]*Vpk[1][5][0])+(Vpk[0][5][2]*Vpk[1][5][2])))+((3.3*(
          (Vpk[0][4][0]*Vpk[1][4][0])+(Vpk[0][4][2]*Vpk[1][4][2])))+(3.32*((
          Vpk[0][3][0]*Vpk[1][3][0])+(Vpk[0][3][2]*Vpk[1][3][2])))))));
        mm[0][1] = ((2.*((Vpk[0][10][0]*Vpk[1][10][0])+(Vpk[0][10][2]*
          Vpk[1][10][2])))+((2.*((Vpk[0][9][0]*Vpk[1][9][0])+(Vpk[0][9][2]*
          Vpk[1][9][2])))+((.2*((Vpk[0][8][0]*Vpk[1][8][0])+(Vpk[0][8][2]*
          Vpk[1][8][2])))+temp[0])));
        temp[0] = ((3.3*((Vpk[0][7][0]*Vpk[2][7][0])+(Vpk[0][7][2]*Vpk[2][7][2])
          ))+((3.32*((Vpk[0][6][0]*Vpk[2][6][0])-(.5*(Vpk[0][6][2]*s6))))+((.2*(
          (Vpk[0][5][0]*Vpk[2][5][0])+(Vpk[0][5][2]*Vpk[2][5][2])))+((3.3*((
          Vpk[0][4][0]*Vpk[2][4][0])+(Vpk[0][4][2]*Vpk[2][4][2])))+((3.32*((
          Vpk[0][3][0]*Vpk[2][3][0])-(.5*(Vpk[0][3][2]*s3))))-(6.14*c2))))));
        mm[0][2] = ((2.*((Vpk[0][10][0]*Vpk[2][10][0])-(.1*(Vpk[0][10][2]*s10)))
          )+((2.*((Vpk[0][9][0]*Vpk[2][9][0])-(.1*(Vpk[0][9][2]*s9))))+((.2*((
          Vpk[0][8][0]*Vpk[2][8][0])+(Vpk[0][8][2]*Vpk[2][8][2])))+temp[0])));
        mm[0][3] = ((.2*((Vpk[0][5][0]*Vpk[3][5][0])+(Vpk[0][5][2]*Vpk[3][5][2])
          ))+((3.3*((Vpk[0][4][0]*Vpk[3][4][0])-(.45*(Vpk[0][4][2]*s4))))-(
          .70052*Vpk[0][3][0])));
        mm[0][4] = ((.2*((Vpk[0][5][0]*Vpk[4][5][0])-(.45*(Vpk[0][5][2]*s5))))-(
          .759*Vpk[0][4][0]));
        mm[0][5] = -(.01*Vpk[0][5][0]);
        mm[0][6] = ((.2*((Vpk[0][8][0]*Vpk[6][8][0])+(Vpk[0][8][2]*Vpk[6][8][2])
          ))+((3.3*((Vpk[0][7][0]*Vpk[6][7][0])-(.45*(Vpk[0][7][2]*s7))))-(
          .70052*Vpk[0][6][0])));
        mm[0][7] = ((.2*((Vpk[0][8][0]*Vpk[7][8][0])-(.45*(Vpk[0][8][2]*s8))))-(
          .759*Vpk[0][7][0]));
        mm[0][8] = -(.01*Vpk[0][8][0]);
        mm[0][9] = -(.4*Vpk[0][9][0]);
        mm[0][10] = -(.4*Vpk[0][10][0]);
        temp[0] = ((3.3*((Vpk[1][7][0]*Vpk[1][7][0])+(Vpk[1][7][2]*Vpk[1][7][2])
          ))+((3.32*((Vpk[1][6][0]*Vpk[1][6][0])+(Vpk[1][6][2]*Vpk[1][6][2])))+(
          (.2*((Vpk[1][5][0]*Vpk[1][5][0])+(Vpk[1][5][2]*Vpk[1][5][2])))+((3.3*(
          (Vpk[1][4][0]*Vpk[1][4][0])+(Vpk[1][4][2]*Vpk[1][4][2])))+(24.56+(3.32
          *((Vpk[1][3][0]*Vpk[1][3][0])+(Vpk[1][3][2]*Vpk[1][3][2]))))))));
        mm[1][1] = ((2.*((Vpk[1][10][0]*Vpk[1][10][0])+(Vpk[1][10][2]*
          Vpk[1][10][2])))+((2.*((Vpk[1][9][0]*Vpk[1][9][0])+(Vpk[1][9][2]*
          Vpk[1][9][2])))+((.2*((Vpk[1][8][0]*Vpk[1][8][0])+(Vpk[1][8][2]*
          Vpk[1][8][2])))+temp[0])));
        temp[0] = ((3.3*((Vpk[1][7][0]*Vpk[2][7][0])+(Vpk[1][7][2]*Vpk[2][7][2])
          ))+((3.32*((Vpk[1][6][0]*Vpk[2][6][0])-(.5*(Vpk[1][6][2]*s6))))+((.2*(
          (Vpk[1][5][0]*Vpk[2][5][0])+(Vpk[1][5][2]*Vpk[2][5][2])))+((3.3*((
          Vpk[1][4][0]*Vpk[2][4][0])+(Vpk[1][4][2]*Vpk[2][4][2])))+((3.32*((
          Vpk[1][3][0]*Vpk[2][3][0])-(.5*(Vpk[1][3][2]*s3))))+(6.14*s2))))));
        mm[1][2] = ((2.*((Vpk[1][10][0]*Vpk[2][10][0])-(.1*(Vpk[1][10][2]*s10)))
          )+((2.*((Vpk[1][9][0]*Vpk[2][9][0])-(.1*(Vpk[1][9][2]*s9))))+((.2*((
          Vpk[1][8][0]*Vpk[2][8][0])+(Vpk[1][8][2]*Vpk[2][8][2])))+temp[0])));
        mm[1][3] = ((.2*((Vpk[1][5][0]*Vpk[3][5][0])+(Vpk[1][5][2]*Vpk[3][5][2])
          ))+((3.3*((Vpk[1][4][0]*Vpk[3][4][0])-(.45*(Vpk[1][4][2]*s4))))-(
          .70052*Vpk[1][3][0])));
        mm[1][4] = ((.2*((Vpk[1][5][0]*Vpk[4][5][0])-(.45*(Vpk[1][5][2]*s5))))-(
          .759*Vpk[1][4][0]));
        mm[1][5] = -(.01*Vpk[1][5][0]);
        mm[1][6] = ((.2*((Vpk[1][8][0]*Vpk[6][8][0])+(Vpk[1][8][2]*Vpk[6][8][2])
          ))+((3.3*((Vpk[1][7][0]*Vpk[6][7][0])-(.45*(Vpk[1][7][2]*s7))))-(
          .70052*Vpk[1][6][0])));
        mm[1][7] = ((.2*((Vpk[1][8][0]*Vpk[7][8][0])-(.45*(Vpk[1][8][2]*s8))))-(
          .759*Vpk[1][7][0]));
        mm[1][8] = -(.01*Vpk[1][8][0]);
        mm[1][9] = -(.4*Vpk[1][9][0]);
        mm[1][10] = -(.4*Vpk[1][10][0]);
        temp[0] = ((.2*((Vpk[2][8][0]*Vpk[2][8][0])+(Vpk[2][8][2]*Vpk[2][8][2]))
          )+((3.3*((Vpk[2][7][0]*Vpk[2][7][0])+(Vpk[2][7][2]*Vpk[2][7][2])))+((
          3.32*((.25*(s6*s6))+(Vpk[2][6][0]*Vpk[2][6][0])))+((.2*((Vpk[2][5][0]*
          Vpk[2][5][0])+(Vpk[2][5][2]*Vpk[2][5][2])))+((3.3*((Vpk[2][4][0]*
          Vpk[2][4][0])+(Vpk[2][4][2]*Vpk[2][4][2])))+(3.32*((.25*(s3*s3))+(
          Vpk[2][3][0]*Vpk[2][3][0]))))))));
        mm[2][2] = (2.938412+((2.*((.01*(s10*s10))+(Vpk[2][10][0]*Vpk[2][10][0])
          ))+((2.*((.01*(s9*s9))+(Vpk[2][9][0]*Vpk[2][9][0])))+temp[0])));
        mm[2][3] = (.110856+((.2*((Vpk[2][5][0]*Vpk[3][5][0])+(Vpk[2][5][2]*
          Vpk[3][5][2])))+((3.3*((Vpk[2][4][0]*Vpk[3][4][0])-(.45*(Vpk[2][4][2]*
          s4))))-(.70052*Vpk[2][3][0]))));
        mm[2][4] = (.062831+((.2*((Vpk[2][5][0]*Vpk[4][5][0])-(.45*(Vpk[2][5][2]
          *s5))))-(.759*Vpk[2][4][0])));
        mm[2][5] = (.000167-(.01*Vpk[2][5][0]));
        mm[2][6] = (.110856+((.2*((Vpk[2][8][0]*Vpk[6][8][0])+(Vpk[2][8][2]*
          Vpk[6][8][2])))+((3.3*((Vpk[2][7][0]*Vpk[6][7][0])-(.45*(Vpk[2][7][2]*
          s7))))-(.70052*Vpk[2][6][0]))));
        mm[2][7] = (.062831+((.2*((Vpk[2][8][0]*Vpk[7][8][0])-(.45*(Vpk[2][8][2]
          *s8))))-(.759*Vpk[2][7][0])));
        mm[2][8] = (.000167-(.01*Vpk[2][8][0]));
        mm[2][9] = (.0818-(.4*Vpk[2][9][0]));
        mm[2][10] = (.0818-(.4*Vpk[2][10][0]));
        mm[3][3] = (.25866572+((.2*((Vpk[3][5][0]*Vpk[3][5][0])+(Vpk[3][5][2]*
          Vpk[3][5][2])))+(3.3*((.2025*(s4*s4))+(Vpk[3][4][0]*Vpk[3][4][0])))));
        mm[3][4] = (.062831+((.2*((Vpk[3][5][0]*Vpk[4][5][0])-(.45*(Vpk[3][5][2]
          *s5))))-(.759*Vpk[3][4][0])));
        mm[3][5] = (.000167-(.01*Vpk[3][5][0]));
        mm[3][6] = 0.;
        mm[3][7] = 0.;
        mm[3][8] = 0.;
        mm[3][9] = 0.;
        mm[3][10] = 0.;
        mm[4][4] = (.237401+(.2*((.2025*(s5*s5))+(Vpk[4][5][0]*Vpk[4][5][0]))));
        mm[4][5] = (.000167-(.01*Vpk[4][5][0]));
        mm[4][6] = 0.;
        mm[4][7] = 0.;
        mm[4][8] = 0.;
        mm[4][9] = 0.;
        mm[4][10] = 0.;
        mm[5][5] = .000667;
        mm[5][6] = 0.;
        mm[5][7] = 0.;
        mm[5][8] = 0.;
        mm[5][9] = 0.;
        mm[5][10] = 0.;
        mm[6][6] = (.25866572+((.2*((Vpk[6][8][0]*Vpk[6][8][0])+(Vpk[6][8][2]*
          Vpk[6][8][2])))+(3.3*((.2025*(s7*s7))+(Vpk[6][7][0]*Vpk[6][7][0])))));
        mm[6][7] = (.062831+((.2*((Vpk[6][8][0]*Vpk[7][8][0])-(.45*(Vpk[6][8][2]
          *s8))))-(.759*Vpk[6][7][0])));
        mm[6][8] = (.000167-(.01*Vpk[6][8][0]));
        mm[6][9] = 0.;
        mm[6][10] = 0.;
        mm[7][7] = (.237401+(.2*((.2025*(s8*s8))+(Vpk[7][8][0]*Vpk[7][8][0]))));
        mm[7][8] = (.000167-(.01*Vpk[7][8][0]));
        mm[7][9] = 0.;
        mm[7][10] = 0.;
        mm[8][8] = .000667;
        mm[8][9] = 0.;
        mm[8][10] = 0.;
        mm[9][9] = .1618;
        mm[9][10] = 0.;
        mm[10][10] = .1618;
/*
Check for singular mass matrix
*/
        for (i = 0; i < 11; i++) {
            if (mm[i][i] < 1e-13) {
                sdseterr(routine,47);
            }
        }
        sderror(&dumroutine,&errnum);
        if (errnum == 0) {
            mmflg = 1;
        }
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  169 adds/subtracts/negates
                    284 multiplies
                      0 divides
                     72 assignments
*/
}

void sddommldu(int routine)
{
    int i;
    int dumroutine,errnum;

    if (mmlduflg == 0) {
        sddomm(routine);
/*
Numerically decompose the mass matrix
*/
        sdldudcomp(11,11,mmap,1e-13,workss,works,mm,mlo,mdi);
/*
Check for singular mass matrix
*/
        for (i = 0; i < 11; i++) {
            if (mdi[i] <= 1e-13) {
                sdseterr(routine,47);
            }
        }
        sderror(&dumroutine,&errnum);
        if (errnum == 0) {
            mmlduflg = 1;
        }
    }
}

void sdlhs(int routine)
{
/* Compute all remaining state- and force-dependent quantities
*/

    roustate = 2;
    sddommldu(routine);
    sddofs0();
}

void sdmfrc(double imult[1])
{

}

void sdequivht(double tau[11])
{
/* Compute tree hinge torques to match effect of applied loads
*/
    double fstareq[11][3],tstareq[11][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(56,23);
        return;
    }
/*
Compute fstareq (forces)
*/
    fstareq[2][0] = -(ufk[0][0]+(240.688*s2));
    fstareq[2][2] = ((240.688*c2)-ufk[0][2]);
    fstareq[3][0] = -(ufk[1][0]+(3.32*gk[3][0]));
    fstareq[3][2] = -(ufk[1][2]+(3.32*gk[3][2]));
    fstareq[4][0] = -(ufk[2][0]+(3.3*gk[4][0]));
    fstareq[4][2] = -(ufk[2][2]+(3.3*gk[4][2]));
    fstareq[5][0] = -(ufk[3][0]+(.2*gk[5][0]));
    fstareq[5][2] = -(ufk[3][2]+(.2*gk[5][2]));
    fstareq[6][0] = -(ufk[4][0]+(3.32*gk[6][0]));
    fstareq[6][2] = -(ufk[4][2]+(3.32*gk[6][2]));
    fstareq[7][0] = -(ufk[5][0]+(3.3*gk[7][0]));
    fstareq[7][2] = -(ufk[5][2]+(3.3*gk[7][2]));
    fstareq[8][0] = -(ufk[6][0]+(.2*gk[8][0]));
    fstareq[8][2] = -(ufk[6][2]+(.2*gk[8][2]));
    fstareq[9][0] = -(ufk[7][0]+(2.*gk[9][0]));
    fstareq[9][2] = -(ufk[7][2]+(2.*gk[9][2]));
    fstareq[10][0] = -(ufk[8][0]+(2.*gk[10][0]));
    fstareq[10][2] = -(ufk[8][2]+(2.*gk[10][2]));
/*
Compute tstareq (torques)
*/
/*
Compute taus (RHS ignoring constraints and inertial forces)
*/
    sddovpk();
    temp[0] = (((fstareq[8][0]*Vpk[0][8][0])+(fstareq[8][2]*Vpk[0][8][2]))+(((
      fstareq[7][0]*Vpk[0][7][0])+(fstareq[7][2]*Vpk[0][7][2]))+(((fstareq[6][0]
      *Vpk[0][6][0])+(fstareq[6][2]*Vpk[0][6][2]))+(((fstareq[5][0]*Vpk[0][5][0]
      )+(fstareq[5][2]*Vpk[0][5][2]))+(((fstareq[4][0]*Vpk[0][4][0])+(
      fstareq[4][2]*Vpk[0][4][2]))+(((fstareq[2][0]*c2)+(fstareq[2][2]*s2))+((
      fstareq[3][0]*Vpk[0][3][0])+(fstareq[3][2]*Vpk[0][3][2]))))))));
    tau[0] = (utau[0]-(((fstareq[10][0]*Vpk[0][10][0])+(fstareq[10][2]*
      Vpk[0][10][2]))+(((fstareq[9][0]*Vpk[0][9][0])+(fstareq[9][2]*Vpk[0][9][2]
      ))+temp[0])));
    temp[0] = (((fstareq[8][0]*Vpk[1][8][0])+(fstareq[8][2]*Vpk[1][8][2]))+(((
      fstareq[7][0]*Vpk[1][7][0])+(fstareq[7][2]*Vpk[1][7][2]))+(((fstareq[6][0]
      *Vpk[1][6][0])+(fstareq[6][2]*Vpk[1][6][2]))+(((fstareq[5][0]*Vpk[1][5][0]
      )+(fstareq[5][2]*Vpk[1][5][2]))+(((fstareq[4][0]*Vpk[1][4][0])+(
      fstareq[4][2]*Vpk[1][4][2]))+(((fstareq[2][2]*c2)-(fstareq[2][0]*s2))+((
      fstareq[3][0]*Vpk[1][3][0])+(fstareq[3][2]*Vpk[1][3][2]))))))));
    tau[1] = (utau[1]-(((fstareq[10][0]*Vpk[1][10][0])+(fstareq[10][2]*
      Vpk[1][10][2]))+(((fstareq[9][0]*Vpk[1][9][0])+(fstareq[9][2]*Vpk[1][9][2]
      ))+temp[0])));
    temp[0] = ((((fstareq[7][0]*Vpk[2][7][0])+(fstareq[7][2]*Vpk[2][7][2]))-
      utk[5][1])+((((fstareq[6][0]*Vpk[2][6][0])-(.5*(fstareq[6][2]*s6)))-
      utk[4][1])+((((fstareq[5][0]*Vpk[2][5][0])+(fstareq[5][2]*Vpk[2][5][2]))-
      utk[3][1])+((((fstareq[4][0]*Vpk[2][4][0])+(fstareq[4][2]*Vpk[2][4][2]))-
      utk[2][1])+((((fstareq[3][0]*Vpk[2][3][0])-(.5*(fstareq[3][2]*s3)))-
      utk[1][1])-(utk[0][1]+(.25*fstareq[2][0])))))));
    tau[2] = (utau[2]-((((fstareq[10][0]*Vpk[2][10][0])-(.1*(fstareq[10][2]*s10)
      ))-utk[8][1])+((((fstareq[9][0]*Vpk[2][9][0])-(.1*(fstareq[9][2]*s9)))-
      utk[7][1])+((((fstareq[8][0]*Vpk[2][8][0])+(fstareq[8][2]*Vpk[2][8][2]))-
      utk[6][1])+temp[0]))));
    tau[3] = (utau[3]-((((fstareq[5][0]*Vpk[3][5][0])+(fstareq[5][2]*
      Vpk[3][5][2]))-utk[3][1])+((((fstareq[4][0]*Vpk[3][4][0])-(.45*(
      fstareq[4][2]*s4)))-utk[2][1])-(utk[1][1]+(.211*fstareq[3][0])))));
    tau[4] = (utau[4]-((((fstareq[5][0]*Vpk[4][5][0])-(.45*(fstareq[5][2]*s5)))-
      utk[3][1])-(utk[2][1]+(.23*fstareq[4][0]))));
    tau[5] = (utau[5]+(utk[3][1]+(.05*fstareq[5][0])));
    tau[6] = (utau[6]-((((fstareq[8][0]*Vpk[6][8][0])+(fstareq[8][2]*
      Vpk[6][8][2]))-utk[6][1])+((((fstareq[7][0]*Vpk[6][7][0])-(.45*(
      fstareq[7][2]*s7)))-utk[5][1])-(utk[4][1]+(.211*fstareq[6][0])))));
    tau[7] = (utau[7]-((((fstareq[8][0]*Vpk[7][8][0])-(.45*(fstareq[8][2]*s8)))-
      utk[6][1])-(utk[5][1]+(.23*fstareq[7][0]))));
    tau[8] = (utau[8]+(utk[6][1]+(.05*fstareq[8][0])));
    tau[9] = (utau[9]+(utk[7][1]+(.2*fstareq[9][0])));
    tau[10] = (utau[10]+(utk[8][1]+(.2*fstareq[10][0])));
/*
Op counts below do not include called subroutines
*/
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  131 adds/subtracts/negates
                     99 multiplies
                      0 divides
                     32 assignments
*/
}

void sdfs0(void)
{

/*
Compute Fs (ignoring multiplier forces)
*/
    fs[0] = fs0[0];
    fs[1] = fs0[1];
    fs[2] = fs0[2];
    fs[3] = fs0[3];
    fs[4] = fs0[4];
    fs[5] = fs0[5];
    fs[6] = fs0[6];
    fs[7] = fs0[7];
    fs[8] = fs0[8];
    fs[9] = fs0[9];
    fs[10] = fs0[10];
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     11 assignments
*/
}

void sdfsmult(void)
{
    int i;

/*
Compute Fs (multiplier-generated forces only)
*/
    for (i = 0; i < 11; i++) {
        fs[i] = 0.;
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     11 assignments
*/
}

void sdfsfull(void)
{

/*
Compute Fs (including all forces)
*/
    sdfsmult();
    fs[0] = (fs[0]+fs0[0]);
    fs[1] = (fs[1]+fs0[1]);
    fs[2] = (fs[2]+fs0[2]);
    fs[3] = (fs[3]+fs0[3]);
    fs[4] = (fs[4]+fs0[4]);
    fs[5] = (fs[5]+fs0[5]);
    fs[6] = (fs[6]+fs0[6]);
    fs[7] = (fs[7]+fs0[7]);
    fs[8] = (fs[8]+fs0[8]);
    fs[9] = (fs[9]+fs0[9]);
    fs[10] = (fs[10]+fs0[10]);
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   11 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     11 assignments
*/
}

void sdfsgenmult(void)
{
    int i;

/*
Compute Fs (generic multiplier-generated forces)
*/
    for (i = 0; i < 11; i++) {
        fs[i] = 0.;
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     11 assignments
*/
}

void sdfsgenfull(void)
{

/*
Compute Fs (incl generic mult & other forces)
*/
    sdfsgenmult();
    fs[0] = (fs[0]+fs0[0]);
    fs[1] = (fs[1]+fs0[1]);
    fs[2] = (fs[2]+fs0[2]);
    fs[3] = (fs[3]+fs0[3]);
    fs[4] = (fs[4]+fs0[4]);
    fs[5] = (fs[5]+fs0[5]);
    fs[6] = (fs[6]+fs0[6]);
    fs[7] = (fs[7]+fs0[7]);
    fs[8] = (fs[8]+fs0[8]);
    fs[9] = (fs[9]+fs0[9]);
    fs[10] = (fs[10]+fs0[10]);
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   11 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     11 assignments
*/
}

void sdfulltrq(double udotin[11],
    double multin[1],
    double trqout[11])
{
/* Compute hinge torques which would produce indicated udots
*/
    double fstarr[11][3],tstarr[11][3],Otkr[11][3],Atir[11][3],Atkr[11][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(61,23);
        return;
    }
/*
Account for inertial accelerations and supplied udots
*/
    Otkr[3][1] = (udotin[2]+udotin[3]);
    Otkr[4][1] = (Otkr[3][1]+udotin[4]);
    Otkr[5][1] = (Otkr[4][1]+udotin[5]);
    Otkr[6][1] = (udotin[2]+udotin[6]);
    Otkr[7][1] = (Otkr[6][1]+udotin[7]);
    Otkr[8][1] = (Otkr[7][1]+udotin[8]);
    Otkr[9][1] = (udotin[2]+udotin[9]);
    Otkr[10][1] = (udotin[2]+udotin[10]);
    Atkr[2][0] = (((udotin[0]*c2)-(udotin[1]*s2))-(.25*udotin[2]));
    Atkr[2][2] = ((.25*(u[2]*u[2]))+((udotin[0]*s2)+(udotin[1]*c2)));
    Atir[3][0] = (Atkr[2][0]-(.25*udotin[2]));
    Atir[3][2] = (Atkr[2][2]+(.25*(u[2]*u[2])));
    Atkr[3][0] = (((Atir[3][0]*c3)-(Atir[3][2]*s3))-(.211*Otkr[3][1]));
    Atkr[3][2] = ((.211*(wk[3][1]*wk[3][1]))+((Atir[3][0]*s3)+(Atir[3][2]*c3)));
    Atir[4][0] = (Atkr[3][0]-(.239*Otkr[3][1]));
    Atir[4][2] = (Atkr[3][2]+(.239*(wk[3][1]*wk[3][1])));
    Atkr[4][0] = (((Atir[4][0]*c4)-(Atir[4][2]*s4))-(.23*Otkr[4][1]));
    Atkr[4][2] = ((.23*(wk[4][1]*wk[4][1]))+((Atir[4][0]*s4)+(Atir[4][2]*c4)));
    Atir[5][0] = (Atkr[4][0]-(.22*Otkr[4][1]));
    Atir[5][2] = (Atkr[4][2]+(.22*(wk[4][1]*wk[4][1])));
    Atkr[5][0] = (((Atir[5][0]*c5)-(Atir[5][2]*s5))-(.05*Otkr[5][1]));
    Atkr[5][2] = ((.05*(wk[5][1]*wk[5][1]))+((Atir[5][0]*s5)+(Atir[5][2]*c5)));
    Atir[6][0] = (Atkr[2][0]-(.25*udotin[2]));
    Atir[6][2] = (Atkr[2][2]+(.25*(u[2]*u[2])));
    Atkr[6][0] = (((Atir[6][0]*c6)-(Atir[6][2]*s6))-(.211*Otkr[6][1]));
    Atkr[6][2] = ((.211*(wk[6][1]*wk[6][1]))+((Atir[6][0]*s6)+(Atir[6][2]*c6)));
    Atir[7][0] = (Atkr[6][0]-(.239*Otkr[6][1]));
    Atir[7][2] = (Atkr[6][2]+(.239*(wk[6][1]*wk[6][1])));
    Atkr[7][0] = (((Atir[7][0]*c7)-(Atir[7][2]*s7))-(.23*Otkr[7][1]));
    Atkr[7][2] = ((.23*(wk[7][1]*wk[7][1]))+((Atir[7][0]*s7)+(Atir[7][2]*c7)));
    Atir[8][0] = (Atkr[7][0]-(.22*Otkr[7][1]));
    Atir[8][2] = (Atkr[7][2]+(.22*(wk[7][1]*wk[7][1])));
    Atkr[8][0] = (((Atir[8][0]*c8)-(Atir[8][2]*s8))-(.05*Otkr[8][1]));
    Atkr[8][2] = ((.05*(wk[8][1]*wk[8][1]))+((Atir[8][0]*s8)+(Atir[8][2]*c8)));
    Atir[9][0] = (Atkr[2][0]+(.15*udotin[2]));
    Atir[9][2] = (Atkr[2][2]-(.15*(u[2]*u[2])));
    Atkr[9][0] = (((Atir[9][0]*c9)-(Atir[9][2]*s9))-(.2*Otkr[9][1]));
    Atkr[9][2] = ((.2*(wk[9][1]*wk[9][1]))+((Atir[9][0]*s9)+(Atir[9][2]*c9)));
    Atir[10][0] = (Atkr[2][0]+(.15*udotin[2]));
    Atir[10][2] = (Atkr[2][2]-(.15*(u[2]*u[2])));
    Atkr[10][0] = (((Atir[10][0]*c10)-(Atir[10][2]*s10))-(.2*Otkr[10][1]));
    Atkr[10][2] = ((.2*(wk[10][1]*wk[10][1]))+((Atir[10][0]*s10)+(Atir[10][2]*
      c10)));
/*
Accumulate all forces and torques
*/
    fstarr[2][0] = (ufk[0][0]+(24.56*((9.8*s2)-Atkr[2][0])));
    fstarr[2][2] = (ufk[0][2]-(24.56*(Atkr[2][2]+(9.8*c2))));
    fstarr[3][0] = (ufk[1][0]+(3.32*(gk[3][0]-Atkr[3][0])));
    fstarr[3][2] = (ufk[1][2]+(3.32*(gk[3][2]-Atkr[3][2])));
    fstarr[4][0] = (ufk[2][0]+(3.3*(gk[4][0]-Atkr[4][0])));
    fstarr[4][2] = (ufk[2][2]+(3.3*(gk[4][2]-Atkr[4][2])));
    fstarr[5][0] = (ufk[3][0]+(.2*(gk[5][0]-Atkr[5][0])));
    fstarr[5][2] = (ufk[3][2]+(.2*(gk[5][2]-Atkr[5][2])));
    fstarr[6][0] = (ufk[4][0]+(3.32*(gk[6][0]-Atkr[6][0])));
    fstarr[6][2] = (ufk[4][2]+(3.32*(gk[6][2]-Atkr[6][2])));
    fstarr[7][0] = (ufk[5][0]+(3.3*(gk[7][0]-Atkr[7][0])));
    fstarr[7][2] = (ufk[5][2]+(3.3*(gk[7][2]-Atkr[7][2])));
    fstarr[8][0] = (ufk[6][0]+(.2*(gk[8][0]-Atkr[8][0])));
    fstarr[8][2] = (ufk[6][2]+(.2*(gk[8][2]-Atkr[8][2])));
    fstarr[9][0] = (ufk[7][0]+(2.*(gk[9][0]-Atkr[9][0])));
    fstarr[9][2] = (ufk[7][2]+(2.*(gk[9][2]-Atkr[9][2])));
    fstarr[10][0] = (ufk[8][0]+(2.*(gk[10][0]-Atkr[10][0])));
    fstarr[10][2] = (ufk[8][2]+(2.*(gk[10][2]-Atkr[10][2])));
    tstarr[2][1] = (utk[0][1]-(1.0181*udotin[2]));
    tstarr[3][1] = (utk[1][1]-(.048025*Otkr[3][1]));
    tstarr[4][1] = (utk[2][1]-(.062664*Otkr[4][1]));
    tstarr[5][1] = (utk[3][1]-(.000167*Otkr[5][1]));
    tstarr[6][1] = (utk[4][1]-(.048025*Otkr[6][1]));
    tstarr[7][1] = (utk[5][1]-(.062664*Otkr[7][1]));
    tstarr[8][1] = (utk[6][1]-(.000167*Otkr[8][1]));
    tstarr[9][1] = (utk[7][1]-(.0818*Otkr[9][1]));
    tstarr[10][1] = (utk[8][1]-(.0818*Otkr[10][1]));
/*
Now calculate the torques
*/
    sddovpk();
    temp[0] = (((fstarr[8][0]*Vpk[0][8][0])+(fstarr[8][2]*Vpk[0][8][2]))+(((
      fstarr[7][0]*Vpk[0][7][0])+(fstarr[7][2]*Vpk[0][7][2]))+(((fstarr[6][0]*
      Vpk[0][6][0])+(fstarr[6][2]*Vpk[0][6][2]))+(((fstarr[5][0]*Vpk[0][5][0])+(
      fstarr[5][2]*Vpk[0][5][2]))+(((fstarr[4][0]*Vpk[0][4][0])+(fstarr[4][2]*
      Vpk[0][4][2]))+(((fstarr[2][0]*c2)+(fstarr[2][2]*s2))+((fstarr[3][0]*
      Vpk[0][3][0])+(fstarr[3][2]*Vpk[0][3][2]))))))));
    trqout[0] = -(utau[0]+(((fstarr[10][0]*Vpk[0][10][0])+(fstarr[10][2]*
      Vpk[0][10][2]))+(((fstarr[9][0]*Vpk[0][9][0])+(fstarr[9][2]*Vpk[0][9][2]))
      +temp[0])));
    temp[0] = (((fstarr[8][0]*Vpk[1][8][0])+(fstarr[8][2]*Vpk[1][8][2]))+(((
      fstarr[7][0]*Vpk[1][7][0])+(fstarr[7][2]*Vpk[1][7][2]))+(((fstarr[6][0]*
      Vpk[1][6][0])+(fstarr[6][2]*Vpk[1][6][2]))+(((fstarr[5][0]*Vpk[1][5][0])+(
      fstarr[5][2]*Vpk[1][5][2]))+(((fstarr[4][0]*Vpk[1][4][0])+(fstarr[4][2]*
      Vpk[1][4][2]))+(((fstarr[2][2]*c2)-(fstarr[2][0]*s2))+((fstarr[3][0]*
      Vpk[1][3][0])+(fstarr[3][2]*Vpk[1][3][2]))))))));
    trqout[1] = -(utau[1]+(((fstarr[10][0]*Vpk[1][10][0])+(fstarr[10][2]*
      Vpk[1][10][2]))+(((fstarr[9][0]*Vpk[1][9][0])+(fstarr[9][2]*Vpk[1][9][2]))
      +temp[0])));
    temp[0] = ((tstarr[7][1]+((fstarr[7][0]*Vpk[2][7][0])+(fstarr[7][2]*
      Vpk[2][7][2])))+((tstarr[6][1]+((fstarr[6][0]*Vpk[2][6][0])-(.5*(
      fstarr[6][2]*s6))))+((tstarr[5][1]+((fstarr[5][0]*Vpk[2][5][0])+(
      fstarr[5][2]*Vpk[2][5][2])))+((tstarr[4][1]+((fstarr[4][0]*Vpk[2][4][0])+(
      fstarr[4][2]*Vpk[2][4][2])))+((tstarr[2][1]-(.25*fstarr[2][0]))+(
      tstarr[3][1]+((fstarr[3][0]*Vpk[2][3][0])-(.5*(fstarr[3][2]*s3)))))))));
    trqout[2] = -(utau[2]+((tstarr[10][1]+((fstarr[10][0]*Vpk[2][10][0])-(.1*(
      fstarr[10][2]*s10))))+((tstarr[9][1]+((fstarr[9][0]*Vpk[2][9][0])-(.1*(
      fstarr[9][2]*s9))))+((tstarr[8][1]+((fstarr[8][0]*Vpk[2][8][0])+(
      fstarr[8][2]*Vpk[2][8][2])))+temp[0]))));
    trqout[3] = -(utau[3]+((tstarr[5][1]+((fstarr[5][0]*Vpk[3][5][0])+(
      fstarr[5][2]*Vpk[3][5][2])))+((tstarr[3][1]-(.211*fstarr[3][0]))+(
      tstarr[4][1]+((fstarr[4][0]*Vpk[3][4][0])-(.45*(fstarr[4][2]*s4)))))));
    trqout[4] = -(utau[4]+((tstarr[4][1]-(.23*fstarr[4][0]))+(tstarr[5][1]+((
      fstarr[5][0]*Vpk[4][5][0])-(.45*(fstarr[5][2]*s5))))));
    trqout[5] = -(utau[5]+(tstarr[5][1]-(.05*fstarr[5][0])));
    trqout[6] = -(utau[6]+((tstarr[8][1]+((fstarr[8][0]*Vpk[6][8][0])+(
      fstarr[8][2]*Vpk[6][8][2])))+((tstarr[6][1]-(.211*fstarr[6][0]))+(
      tstarr[7][1]+((fstarr[7][0]*Vpk[6][7][0])-(.45*(fstarr[7][2]*s7)))))));
    trqout[7] = -(utau[7]+((tstarr[7][1]-(.23*fstarr[7][0]))+(tstarr[8][1]+((
      fstarr[8][0]*Vpk[7][8][0])-(.45*(fstarr[8][2]*s8))))));
    trqout[8] = -(utau[8]+(tstarr[8][1]-(.05*fstarr[8][0])));
    trqout[9] = -(utau[9]+(tstarr[9][1]-(.2*fstarr[9][0])));
    trqout[10] = -(utau[10]+(tstarr[10][1]-(.2*fstarr[10][0])));
/*
Op counts below do not include called subroutines
*/
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  212 adds/subtracts/negates
                    197 multiplies
                      0 divides
                     83 assignments
*/
}

void sdcomptrq(double udotin[11],
    double trqout[11])
{
/* Compute hinge torques to produce these udots, ignoring constraints
*/
    double multin[1];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(60,23);
        return;
    }
    sdfulltrq(udotin,multin,trqout);
}

void sdmulttrq(double multin[1],
    double trqout[11])
{
/* Compute hinge trqs which would be produced by these mults.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(65,23);
        return;
    }
    for (i = 0; i < 11; i++) {
        trqout[i] = 0.;
    }
}

void sdrhs(void)
{
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

/*
Compute hinge torques for tree hinges
*/
    tauc[0] = utau[0];
    tauc[1] = utau[1];
    tauc[2] = utau[2];
    tauc[3] = utau[3];
    tauc[4] = utau[4];
    tauc[5] = utau[5];
    tauc[6] = utau[6];
    tauc[7] = utau[7];
    tauc[8] = utau[8];
    tauc[9] = utau[9];
    tauc[10] = utau[10];
    sddoiner();
/*
Compute onk & onb (angular accels in N)
*/
    Onkb[3][1] = (udot[2]+udot[3]);
    Onkb[4][1] = (Onkb[3][1]+udot[4]);
    Onkb[5][1] = (Onkb[4][1]+udot[5]);
    Onkb[6][1] = (udot[2]+udot[6]);
    Onkb[7][1] = (Onkb[6][1]+udot[7]);
    Onkb[8][1] = (Onkb[7][1]+udot[8]);
    Onkb[9][1] = (udot[2]+udot[9]);
    Onkb[10][1] = (udot[2]+udot[10]);
    onb[0][0] = 0.;
    onb[0][1] = udot[2];
    onb[0][2] = 0.;
    onb[1][0] = 0.;
    onb[1][1] = Onkb[3][1];
    onb[1][2] = 0.;
    onb[2][0] = 0.;
    onb[2][1] = Onkb[4][1];
    onb[2][2] = 0.;
    onb[3][0] = 0.;
    onb[3][1] = Onkb[5][1];
    onb[3][2] = 0.;
    onb[4][0] = 0.;
    onb[4][1] = Onkb[6][1];
    onb[4][2] = 0.;
    onb[5][0] = 0.;
    onb[5][1] = Onkb[7][1];
    onb[5][2] = 0.;
    onb[6][0] = 0.;
    onb[6][1] = Onkb[8][1];
    onb[6][2] = 0.;
    onb[7][0] = 0.;
    onb[7][1] = Onkb[9][1];
    onb[7][2] = 0.;
    onb[8][0] = 0.;
    onb[8][1] = Onkb[10][1];
    onb[8][2] = 0.;
/*
Compute acceleration dyadics
*/
    dyad[0][0][0] = -w1w1[0];
    dyad[0][0][1] = 0.;
    dyad[0][0][2] = udot[2];
    dyad[0][1][0] = 0.;
    dyad[0][1][1] = 0.;
    dyad[0][1][2] = 0.;
    dyad[0][2][0] = -udot[2];
    dyad[0][2][1] = 0.;
    dyad[0][2][2] = -w1w1[0];
    dyad[1][0][0] = -w1w1[1];
    dyad[1][0][1] = 0.;
    dyad[1][0][2] = Onkb[3][1];
    dyad[1][1][0] = 0.;
    dyad[1][1][1] = 0.;
    dyad[1][1][2] = 0.;
    dyad[1][2][0] = -Onkb[3][1];
    dyad[1][2][1] = 0.;
    dyad[1][2][2] = -w1w1[1];
    dyad[2][0][0] = -w1w1[2];
    dyad[2][0][1] = 0.;
    dyad[2][0][2] = Onkb[4][1];
    dyad[2][1][0] = 0.;
    dyad[2][1][1] = 0.;
    dyad[2][1][2] = 0.;
    dyad[2][2][0] = -Onkb[4][1];
    dyad[2][2][1] = 0.;
    dyad[2][2][2] = -w1w1[2];
    dyad[3][0][0] = -w1w1[3];
    dyad[3][0][1] = 0.;
    dyad[3][0][2] = Onkb[5][1];
    dyad[3][1][0] = 0.;
    dyad[3][1][1] = 0.;
    dyad[3][1][2] = 0.;
    dyad[3][2][0] = -Onkb[5][1];
    dyad[3][2][1] = 0.;
    dyad[3][2][2] = -w1w1[3];
    dyad[4][0][0] = -w1w1[4];
    dyad[4][0][1] = 0.;
    dyad[4][0][2] = Onkb[6][1];
    dyad[4][1][0] = 0.;
    dyad[4][1][1] = 0.;
    dyad[4][1][2] = 0.;
    dyad[4][2][0] = -Onkb[6][1];
    dyad[4][2][1] = 0.;
    dyad[4][2][2] = -w1w1[4];
    dyad[5][0][0] = -w1w1[5];
    dyad[5][0][1] = 0.;
    dyad[5][0][2] = Onkb[7][1];
    dyad[5][1][0] = 0.;
    dyad[5][1][1] = 0.;
    dyad[5][1][2] = 0.;
    dyad[5][2][0] = -Onkb[7][1];
    dyad[5][2][1] = 0.;
    dyad[5][2][2] = -w1w1[5];
    dyad[6][0][0] = -w1w1[6];
    dyad[6][0][1] = 0.;
    dyad[6][0][2] = Onkb[8][1];
    dyad[6][1][0] = 0.;
    dyad[6][1][1] = 0.;
    dyad[6][1][2] = 0.;
    dyad[6][2][0] = -Onkb[8][1];
    dyad[6][2][1] = 0.;
    dyad[6][2][2] = -w1w1[6];
    dyad[7][0][0] = -w1w1[7];
    dyad[7][0][1] = 0.;
    dyad[7][0][2] = Onkb[9][1];
    dyad[7][1][0] = 0.;
    dyad[7][1][1] = 0.;
    dyad[7][1][2] = 0.;
    dyad[7][2][0] = -Onkb[9][1];
    dyad[7][2][1] = 0.;
    dyad[7][2][2] = -w1w1[7];
    dyad[8][0][0] = -w1w1[8];
    dyad[8][0][1] = 0.;
    dyad[8][0][2] = Onkb[10][1];
    dyad[8][1][0] = 0.;
    dyad[8][1][1] = 0.;
    dyad[8][1][2] = 0.;
    dyad[8][2][0] = -Onkb[10][1];
    dyad[8][2][1] = 0.;
    dyad[8][2][2] = -w1w1[8];
/*
Compute ank & anb (mass center linear accels in N)
*/
    Ankb[2][0] = (((udot[0]*c2)-(udot[1]*s2))-(.25*udot[2]));
    Ankb[2][2] = ((udot[0]*s2)+(udot[1]*c2));
    AOnkri[3][0] = (Ankb[2][0]-(.25*udot[2]));
    Ankb[3][0] = (((AOnkri[3][0]*c3)-(Ankb[2][2]*s3))-(.211*Onkb[3][1]));
    Ankb[3][2] = ((Ankb[2][2]*c3)+(AOnkri[3][0]*s3));
    AOnkri[4][0] = (Ankb[3][0]-(.239*Onkb[3][1]));
    Ankb[4][0] = (((AOnkri[4][0]*c4)-(Ankb[3][2]*s4))-(.23*Onkb[4][1]));
    Ankb[4][2] = ((Ankb[3][2]*c4)+(AOnkri[4][0]*s4));
    AOnkri[5][0] = (Ankb[4][0]-(.22*Onkb[4][1]));
    Ankb[5][0] = (((AOnkri[5][0]*c5)-(Ankb[4][2]*s5))-(.05*Onkb[5][1]));
    Ankb[5][2] = ((Ankb[4][2]*c5)+(AOnkri[5][0]*s5));
    AOnkri[6][0] = (Ankb[2][0]-(.25*udot[2]));
    Ankb[6][0] = (((AOnkri[6][0]*c6)-(Ankb[2][2]*s6))-(.211*Onkb[6][1]));
    Ankb[6][2] = ((Ankb[2][2]*c6)+(AOnkri[6][0]*s6));
    AOnkri[7][0] = (Ankb[6][0]-(.239*Onkb[6][1]));
    Ankb[7][0] = (((AOnkri[7][0]*c7)-(Ankb[6][2]*s7))-(.23*Onkb[7][1]));
    Ankb[7][2] = ((Ankb[6][2]*c7)+(AOnkri[7][0]*s7));
    AOnkri[8][0] = (Ankb[7][0]-(.22*Onkb[7][1]));
    Ankb[8][0] = (((AOnkri[8][0]*c8)-(Ankb[7][2]*s8))-(.05*Onkb[8][1]));
    Ankb[8][2] = ((Ankb[7][2]*c8)+(AOnkri[8][0]*s8));
    AOnkri[9][0] = (Ankb[2][0]+(.15*udot[2]));
    Ankb[9][0] = (((AOnkri[9][0]*c9)-(Ankb[2][2]*s9))-(.2*Onkb[9][1]));
    Ankb[9][2] = ((Ankb[2][2]*c9)+(AOnkri[9][0]*s9));
    AOnkri[10][0] = (Ankb[2][0]+(.15*udot[2]));
    Ankb[10][0] = (((AOnkri[10][0]*c10)-(Ankb[2][2]*s10))-(.2*Onkb[10][1]));
    Ankb[10][2] = ((Ankb[2][2]*c10)+(AOnkri[10][0]*s10));
    AnkAtk[2][2] = (Ankb[2][2]+Atk[2][2]);
    ank[2][0] = ((AnkAtk[2][2]*s2)+(Ankb[2][0]*c2));
    ank[2][2] = ((AnkAtk[2][2]*c2)-(Ankb[2][0]*s2));
    AnkAtk[3][0] = (Ankb[3][0]+Atk[3][0]);
    AnkAtk[3][2] = (Ankb[3][2]+Atk[3][2]);
    ank[3][0] = ((AnkAtk[3][0]*cnk[3][0][0])+(AnkAtk[3][2]*cnk[3][0][2]));
    ank[3][2] = ((AnkAtk[3][0]*cnk[3][2][0])+(AnkAtk[3][2]*cnk[3][2][2]));
    AnkAtk[4][0] = (Ankb[4][0]+Atk[4][0]);
    AnkAtk[4][2] = (Ankb[4][2]+Atk[4][2]);
    ank[4][0] = ((AnkAtk[4][0]*cnk[4][0][0])+(AnkAtk[4][2]*cnk[4][0][2]));
    ank[4][2] = ((AnkAtk[4][0]*cnk[4][2][0])+(AnkAtk[4][2]*cnk[4][2][2]));
    AnkAtk[5][0] = (Ankb[5][0]+Atk[5][0]);
    AnkAtk[5][2] = (Ankb[5][2]+Atk[5][2]);
    ank[5][0] = ((AnkAtk[5][0]*cnk[5][0][0])+(AnkAtk[5][2]*cnk[5][0][2]));
    ank[5][2] = ((AnkAtk[5][0]*cnk[5][2][0])+(AnkAtk[5][2]*cnk[5][2][2]));
    AnkAtk[6][0] = (Ankb[6][0]+Atk[6][0]);
    AnkAtk[6][2] = (Ankb[6][2]+Atk[6][2]);
    ank[6][0] = ((AnkAtk[6][0]*cnk[6][0][0])+(AnkAtk[6][2]*cnk[6][0][2]));
    ank[6][2] = ((AnkAtk[6][0]*cnk[6][2][0])+(AnkAtk[6][2]*cnk[6][2][2]));
    AnkAtk[7][0] = (Ankb[7][0]+Atk[7][0]);
    AnkAtk[7][2] = (Ankb[7][2]+Atk[7][2]);
    ank[7][0] = ((AnkAtk[7][0]*cnk[7][0][0])+(AnkAtk[7][2]*cnk[7][0][2]));
    ank[7][2] = ((AnkAtk[7][0]*cnk[7][2][0])+(AnkAtk[7][2]*cnk[7][2][2]));
    AnkAtk[8][0] = (Ankb[8][0]+Atk[8][0]);
    AnkAtk[8][2] = (Ankb[8][2]+Atk[8][2]);
    ank[8][0] = ((AnkAtk[8][0]*cnk[8][0][0])+(AnkAtk[8][2]*cnk[8][0][2]));
    ank[8][2] = ((AnkAtk[8][0]*cnk[8][2][0])+(AnkAtk[8][2]*cnk[8][2][2]));
    AnkAtk[9][0] = (Ankb[9][0]+Atk[9][0]);
    AnkAtk[9][2] = (Ankb[9][2]+Atk[9][2]);
    ank[9][0] = ((AnkAtk[9][0]*cnk[9][0][0])+(AnkAtk[9][2]*cnk[9][0][2]));
    ank[9][2] = ((AnkAtk[9][0]*cnk[9][2][0])+(AnkAtk[9][2]*cnk[9][2][2]));
    AnkAtk[10][0] = (Ankb[10][0]+Atk[10][0]);
    AnkAtk[10][2] = (Ankb[10][2]+Atk[10][2]);
    ank[10][0] = ((AnkAtk[10][0]*cnk[10][0][0])+(AnkAtk[10][2]*cnk[10][0][2]));
    ank[10][2] = ((AnkAtk[10][0]*cnk[10][2][0])+(AnkAtk[10][2]*cnk[10][2][2]));
    anb[0][0] = ank[2][0];
    anb[0][1] = 0.;
    anb[0][2] = ank[2][2];
    anb[1][0] = ank[3][0];
    anb[1][1] = 0.;
    anb[1][2] = ank[3][2];
    anb[2][0] = ank[4][0];
    anb[2][1] = 0.;
    anb[2][2] = ank[4][2];
    anb[3][0] = ank[5][0];
    anb[3][1] = 0.;
    anb[3][2] = ank[5][2];
    anb[4][0] = ank[6][0];
    anb[4][1] = 0.;
    anb[4][2] = ank[6][2];
    anb[5][0] = ank[7][0];
    anb[5][1] = 0.;
    anb[5][2] = ank[7][2];
    anb[6][0] = ank[8][0];
    anb[6][1] = 0.;
    anb[6][2] = ank[8][2];
    anb[7][0] = ank[9][0];
    anb[7][1] = 0.;
    anb[7][2] = ank[9][2];
    anb[8][0] = ank[10][0];
    anb[8][1] = 0.;
    anb[8][2] = ank[10][2];
    roustate = 3;
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  105 adds/subtracts/negates
                     89 multiplies
                      0 divides
                    215 assignments
*/
}

void sdmassmat(double mmat[11][11])
{
/* Return the system mass matrix (LHS)
*/
    int i,j;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(57,23);
        return;
    }
    sddomm(57);
    for (i = 0; i < 11; i++) {
        for (j = i; j <= 10; j++) {
            mmat[i][j] = mm[i][j];
            mmat[j][i] = mm[i][j];
        }
    }
}

void sdfrcmat(double fmat[11])
{
/* Return the system force matrix (RHS), excluding constraints
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(58,23);
        return;
    }
    sddofs0();
    for (i = 0; i < 11; i++) {
        fmat[i] = fs0[i];
    }
}

void sdpseudo(double lqout[1],
    double luout[1])
{
/*
Return pseudo-coordinates for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void sdpsqdot(double lqdout[1])
{
/*
Return pseudo-coordinate derivatives for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void sdpsudot(double ludout[1])
{
/*
Return pseudo-coordinate accelerations for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void sdperr(double errs[1])
{

}

void sdverr(double errs[1])
{

}

void sdaerr(double errs[1])
{

}
int 
sdchkbnum(int routine,
    int bnum)
{

    if ((bnum < -1) || (bnum > 8)) {
        sdseterr(routine,15);
        return 1;
    }
    return 0;
}
int 
sdchkjnum(int routine,
    int jnum)
{

    if ((jnum < 0) || (jnum > 8)) {
        sdseterr(routine,16);
        return 1;
    }
    return 0;
}
int 
sdchkucnum(int routine,
    int ucnum)
{

    if ((ucnum < 0) || (ucnum > -1)) {
        sdseterr(routine,21);
        return 1;
    }
    return 0;
}
int 
sdchkjaxis(int routine,
    int jnum,
    int axnum)
{
    int maxax;

    if (sdchkjnum(routine,jnum) != 0) {
        return 1;
    }
    if ((axnum < 0) || (axnum > 6)) {
        sdseterr(routine,17);
        return 1;
    }
    maxax = njntdof[jnum]-1;
    if ((jtype[jnum] == 4) || (jtype[jnum] == 6) || (jtype[jnum] == 21)) {
        maxax = maxax+1;
    }
    if (axnum > maxax) {
        sdseterr(routine,18);
        return 1;
    }
    return 0;
}
int 
sdchkjpin(int routine,
    int jnum,
    int pinno)
{
    int maxax,pinok;

    if (sdchkjnum(routine,jnum) != 0) {
        return 1;
    }
    if ((pinno < 0) || (pinno > 5)) {
        sdseterr(routine,17);
        return 1;
    }
    if (njntdof[jnum] >= 3) {
        maxax = 2;
    } else {
        maxax = njntdof[jnum]-1;
    }
    if (jtype[jnum] == 4) {
        maxax = -1;
    }
    if (jtype[jnum] == 7) {
        maxax = 0;
    }
    pinok = 0;
    if (pinno <= maxax) {
        pinok = 1;
    }
    if (pinok == 0) {
        sdseterr(routine,18);
        return 1;
    }
    return 0;
}
int 
sdindx(int joint,
    int axis)
{
    int offs,gotit;

    if (sdchkjaxis(36,joint,axis) != 0) {
        return 0;
    }
    gotit = 0;
    if (jtype[joint] == 4) {
        if (axis == 3) {
            offs = ballq[joint];
            gotit = 1;
        }
    } else {
        if ((jtype[joint] == 6) || (jtype[joint] == 21)) {
            if (axis == 6) {
                offs = ballq[joint];
                gotit = 1;
            }
        }
    }
    if (gotit == 0) {
        offs = firstq[joint]+axis;
    }
    return offs;
}

void sdpresacc(int joint,
    int axis,
    double prval)
{

}

void sdpresvel(int joint,
    int axis,
    double prval)
{

}

void sdprespos(int joint,
    int axis,
    double prval)
{

}

void sdgetht(int joint,
    int axis,
    double *torque)
{

    if (sdchkjaxis(30,joint,axis) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(30,24);
        return;
    }
    *torque = tauc[sdindx(joint,axis)];
}

void sdhinget(int joint,
    int axis,
    double torque)
{

    if (sdchkjaxis(10,joint,axis) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(10,23);
        return;
    }
    if (mfrcflg != 0) {
        mtau[sdindx(joint,axis)] = mtau[sdindx(joint,axis)]+torque;
    } else {
        fs0flg = 0;
        utau[sdindx(joint,axis)] = utau[sdindx(joint,axis)]+torque;
    }
}

void sdpointf(int body,
    double point[3],
    double force[3])
{
    double torque[3];

    if (sdchkbnum(11,body) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(11,23);
        return;
    }
    if (body == -1) {
        return;
    }
    torque[0] = point[1]*force[2]-point[2]*force[1];
    torque[1] = point[2]*force[0]-point[0]*force[2];
    torque[2] = point[0]*force[1]-point[1]*force[0];
    if (mfrcflg != 0) {
        mfk[body][0] = mfk[body][0]+force[0];
        mtk[body][0] = mtk[body][0]+torque[0];
        mfk[body][1] = mfk[body][1]+force[1];
        mtk[body][1] = mtk[body][1]+torque[1];
        mfk[body][2] = mfk[body][2]+force[2];
        mtk[body][2] = mtk[body][2]+torque[2];
    } else {
        fs0flg = 0;
        ufk[body][0] = ufk[body][0]+force[0];
        utk[body][0] = utk[body][0]+torque[0];
        ufk[body][1] = ufk[body][1]+force[1];
        utk[body][1] = utk[body][1]+torque[1];
        ufk[body][2] = ufk[body][2]+force[2];
        utk[body][2] = utk[body][2]+torque[2];
    }
}

void sdbodyt(int body,
    double torque[3])
{

    if (sdchkbnum(12,body) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(12,23);
        return;
    }
    if (body == -1) {
        return;
    }
    if (mfrcflg != 0) {
        mtk[body][0] = mtk[body][0]+torque[0];
        mtk[body][1] = mtk[body][1]+torque[1];
        mtk[body][2] = mtk[body][2]+torque[2];
    } else {
        fs0flg = 0;
        utk[body][0] = utk[body][0]+torque[0];
        utk[body][1] = utk[body][1]+torque[1];
        utk[body][2] = utk[body][2]+torque[2];
    }
}

void sddoww(int routine)
{

    roustate = 2;
    if (wwflg == 0) {
        wwflg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                      0 assignments
*/
}

void sdxudot0(int routine,
    double oudot0[11])
{
/*
Compute unconstrained equations
*/
    int i;

    sdlhs(routine);
/*
Solve equations for udots
*/
    sdfs0();
    sdldubslv(11,11,mmap,works,mlo,mdi,fs,udot);
    for (i = 0; i <= 10; i++) {
        oudot0[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     11 assignments
*/
}

void sdudot0(double oudot0[11])
{

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(66,23);
        return;
    }
    sdxudot0(66,oudot0);
}

void sdsetudot(double iudot[11])
{
/*
Assign udots and advance to stage Dynamics Ready
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(68,23);
        return;
    }
    for (i = 0; i <= 10; i++) {
        udot[i] = iudot[i];
    }
    sdrhs();
}

void sdxudotm(int routine,
    double imult[1],
    double oudotm[11])
{
/*
Compute udots due only to multipliers
*/
    int i;

    sdlhs(routine);
    for (i = 0; i <= 10; i++) {
        udot[i] = 0.;
    }
    for (i = 0; i <= 10; i++) {
        oudotm[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     22 assignments
*/
}

void sdudotm(double imult[1],
    double oudotm[11])
{

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(67,23);
        return;
    }
    sdxudotm(67,imult,oudotm);
}

void sdderiv(double oqdot[11],
    double oudot[11])
{
/*
This is the derivative section for a 9-body ground-based
system with 11 hinge degree(s) of freedom.
*/
    int i;
    double udot0[11],udot1[11];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(17,23);
        return;
    }
    if (stabvelq == 1) {
        sdseterr(17,32);
    }
    if (stabposq == 1) {
        sdseterr(17,33);
    }
    wsiz = 0;
/*
Compute unconstrained equations
*/
    sdxudot0(17,udot0);
    sdrhs();
    wrank = 0;
    for (i = 0; i <= 10; i++) {
        oqdot[i] = qdot[i];
    }
    for (i = 0; i <= 10; i++) {
        oudot[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     22 assignments
*/
}
/*
Compute residuals for use with DAE integrator
*/

void sdresid(double eqdot[11],
    double eudot[11],
    double emults[1],
    double resid[22])
{
    int i;
    double uderrs[11];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(16,23);
        return;
    }
    if (stabposq == 1) {
        sdseterr(16,33);
    }
    sdfulltrq(eudot,emults,uderrs);
    for (i = 0; i < 11; i++) {
        resid[i] = eqdot[i]-qdot[i];
    }
    for (i = 0; i < 11; i++) {
        resid[11+i] = uderrs[i];
    }
    for (i = 0; i < 11; i++) {
        udot[i] = eudot[i];
    }
    sdrhs();
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   11 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     33 assignments
*/
}

void sdmult(double omults[1],
    int *owrank,
    int omultmap[1])
{

    if (roustate != 3) {
        sdseterr(34,24);
        return;
    }
    *owrank = wrank;
}

void sdreac(double force[9][3],
    double torque[9][3])
{
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

    if (roustate != 3) {
        sdseterr(31,24);
        return;
    }
/*
Compute reaction forces for non-weld tree joints
*/
    fc[10][0] = ((2.*(AnkAtk[10][0]-gk[10][0]))-ufk[8][0]);
    fc[10][1] = -ufk[8][1];
    fc[10][2] = ((2.*(AnkAtk[10][2]-gk[10][2]))-ufk[8][2]);
    tc[10][0] = -(utk[8][0]-(.2*fc[10][1]));
    tc[10][1] = ((.0818*Onkb[10][1])-(utk[8][1]+(.2*fc[10][0])));
    tc[10][2] = -utk[8][2];
    fccikt[10][0] = ((fc[10][0]*c10)+(fc[10][2]*s10));
    fccikt[10][1] = fc[10][1];
    fccikt[10][2] = ((fc[10][2]*c10)-(fc[10][0]*s10));
    ffk[2][0] = (ufk[0][0]-fccikt[10][0]);
    ffk[2][1] = (ufk[0][1]-fccikt[10][1]);
    ffk[2][2] = (ufk[0][2]-fccikt[10][2]);
    ttk[2][0] = (utk[0][0]-(((.1*fccikt[10][2])-(.15*fccikt[10][1]))+((tc[10][0]
      *c10)+(tc[10][2]*s10))));
    ttk[2][1] = (utk[0][1]-(tc[10][1]+(.15*fccikt[10][0])));
    ttk[2][2] = (utk[0][2]-(((tc[10][2]*c10)-(tc[10][0]*s10))-(.1*fccikt[10][0])
      ));
    fc[9][0] = ((2.*(AnkAtk[9][0]-gk[9][0]))-ufk[7][0]);
    fc[9][1] = -ufk[7][1];
    fc[9][2] = ((2.*(AnkAtk[9][2]-gk[9][2]))-ufk[7][2]);
    tc[9][0] = -(utk[7][0]-(.2*fc[9][1]));
    tc[9][1] = ((.0818*Onkb[9][1])-(utk[7][1]+(.2*fc[9][0])));
    tc[9][2] = -utk[7][2];
    fccikt[9][0] = ((fc[9][0]*c9)+(fc[9][2]*s9));
    fccikt[9][1] = fc[9][1];
    fccikt[9][2] = ((fc[9][2]*c9)-(fc[9][0]*s9));
    ffk[2][0] = (ffk[2][0]-fccikt[9][0]);
    ffk[2][1] = (ffk[2][1]-fccikt[9][1]);
    ffk[2][2] = (ffk[2][2]-fccikt[9][2]);
    ttk[2][0] = (ttk[2][0]-(((tc[9][0]*c9)+(tc[9][2]*s9))-((.1*fccikt[9][2])+(
      .15*fccikt[9][1]))));
    ttk[2][1] = (ttk[2][1]-(tc[9][1]+(.15*fccikt[9][0])));
    ttk[2][2] = (ttk[2][2]-((.1*fccikt[9][0])+((tc[9][2]*c9)-(tc[9][0]*s9))));
    fc[8][0] = ((.2*(AnkAtk[8][0]-gk[8][0]))-ufk[6][0]);
    fc[8][1] = -ufk[6][1];
    fc[8][2] = ((.2*(AnkAtk[8][2]-gk[8][2]))-ufk[6][2]);
    tc[8][0] = -(utk[6][0]-(.05*fc[8][1]));
    tc[8][1] = ((.000167*Onkb[8][1])-(utk[6][1]+(.05*fc[8][0])));
    tc[8][2] = -utk[6][2];
    fccikt[8][0] = ((fc[8][0]*c8)+(fc[8][2]*s8));
    fccikt[8][1] = fc[8][1];
    fccikt[8][2] = ((fc[8][2]*c8)-(fc[8][0]*s8));
    ffk[7][0] = (ufk[5][0]-fccikt[8][0]);
    ffk[7][1] = (ufk[5][1]-fccikt[8][1]);
    ffk[7][2] = (ufk[5][2]-fccikt[8][2]);
    ttk[7][0] = (utk[5][0]-((.22*fccikt[8][1])+((tc[8][0]*c8)+(tc[8][2]*s8))));
    ttk[7][1] = (utk[5][1]-(tc[8][1]-(.22*fccikt[8][0])));
    ttk[7][2] = (utk[5][2]-((tc[8][2]*c8)-(tc[8][0]*s8)));
    fc[7][0] = ((3.3*(AnkAtk[7][0]-gk[7][0]))-ffk[7][0]);
    fc[7][1] = -ffk[7][1];
    fc[7][2] = ((3.3*(AnkAtk[7][2]-gk[7][2]))-ffk[7][2]);
    tc[7][0] = -(ttk[7][0]-(.23*fc[7][1]));
    tc[7][1] = ((.062664*Onkb[7][1])-(ttk[7][1]+(.23*fc[7][0])));
    tc[7][2] = -ttk[7][2];
    fccikt[7][0] = ((fc[7][0]*c7)+(fc[7][2]*s7));
    fccikt[7][1] = fc[7][1];
    fccikt[7][2] = ((fc[7][2]*c7)-(fc[7][0]*s7));
    ffk[6][0] = (ufk[4][0]-fccikt[7][0]);
    ffk[6][1] = (ufk[4][1]-fccikt[7][1]);
    ffk[6][2] = (ufk[4][2]-fccikt[7][2]);
    ttk[6][0] = (utk[4][0]-((.239*fccikt[7][1])+((tc[7][0]*c7)+(tc[7][2]*s7))));
    ttk[6][1] = (utk[4][1]-(tc[7][1]-(.239*fccikt[7][0])));
    ttk[6][2] = (utk[4][2]-((tc[7][2]*c7)-(tc[7][0]*s7)));
    fc[6][0] = ((3.32*(AnkAtk[6][0]-gk[6][0]))-ffk[6][0]);
    fc[6][1] = -ffk[6][1];
    fc[6][2] = ((3.32*(AnkAtk[6][2]-gk[6][2]))-ffk[6][2]);
    tc[6][0] = -(ttk[6][0]-(.211*fc[6][1]));
    tc[6][1] = ((.048025*Onkb[6][1])-(ttk[6][1]+(.211*fc[6][0])));
    tc[6][2] = -ttk[6][2];
    fccikt[6][0] = ((fc[6][0]*c6)+(fc[6][2]*s6));
    fccikt[6][1] = fc[6][1];
    fccikt[6][2] = ((fc[6][2]*c6)-(fc[6][0]*s6));
    ffk[2][0] = (ffk[2][0]-fccikt[6][0]);
    ffk[2][1] = (ffk[2][1]-fccikt[6][1]);
    ffk[2][2] = (ffk[2][2]-fccikt[6][2]);
    ttk[2][0] = (ttk[2][0]-(((.1*fccikt[6][2])+(.25*fccikt[6][1]))+((tc[6][0]*c6
      )+(tc[6][2]*s6))));
    ttk[2][1] = (ttk[2][1]-(tc[6][1]-(.25*fccikt[6][0])));
    ttk[2][2] = (ttk[2][2]-(((tc[6][2]*c6)-(tc[6][0]*s6))-(.1*fccikt[6][0])));
    fc[5][0] = ((.2*(AnkAtk[5][0]-gk[5][0]))-ufk[3][0]);
    fc[5][1] = -ufk[3][1];
    fc[5][2] = ((.2*(AnkAtk[5][2]-gk[5][2]))-ufk[3][2]);
    tc[5][0] = -(utk[3][0]-(.05*fc[5][1]));
    tc[5][1] = ((.000167*Onkb[5][1])-(utk[3][1]+(.05*fc[5][0])));
    tc[5][2] = -utk[3][2];
    fccikt[5][0] = ((fc[5][0]*c5)+(fc[5][2]*s5));
    fccikt[5][1] = fc[5][1];
    fccikt[5][2] = ((fc[5][2]*c5)-(fc[5][0]*s5));
    ffk[4][0] = (ufk[2][0]-fccikt[5][0]);
    ffk[4][1] = (ufk[2][1]-fccikt[5][1]);
    ffk[4][2] = (ufk[2][2]-fccikt[5][2]);
    ttk[4][0] = (utk[2][0]-((.22*fccikt[5][1])+((tc[5][0]*c5)+(tc[5][2]*s5))));
    ttk[4][1] = (utk[2][1]-(tc[5][1]-(.22*fccikt[5][0])));
    ttk[4][2] = (utk[2][2]-((tc[5][2]*c5)-(tc[5][0]*s5)));
    fc[4][0] = ((3.3*(AnkAtk[4][0]-gk[4][0]))-ffk[4][0]);
    fc[4][1] = -ffk[4][1];
    fc[4][2] = ((3.3*(AnkAtk[4][2]-gk[4][2]))-ffk[4][2]);
    tc[4][0] = -(ttk[4][0]-(.23*fc[4][1]));
    tc[4][1] = ((.062664*Onkb[4][1])-(ttk[4][1]+(.23*fc[4][0])));
    tc[4][2] = -ttk[4][2];
    fccikt[4][0] = ((fc[4][0]*c4)+(fc[4][2]*s4));
    fccikt[4][1] = fc[4][1];
    fccikt[4][2] = ((fc[4][2]*c4)-(fc[4][0]*s4));
    ffk[3][0] = (ufk[1][0]-fccikt[4][0]);
    ffk[3][1] = (ufk[1][1]-fccikt[4][1]);
    ffk[3][2] = (ufk[1][2]-fccikt[4][2]);
    ttk[3][0] = (utk[1][0]-((.239*fccikt[4][1])+((tc[4][0]*c4)+(tc[4][2]*s4))));
    ttk[3][1] = (utk[1][1]-(tc[4][1]-(.239*fccikt[4][0])));
    ttk[3][2] = (utk[1][2]-((tc[4][2]*c4)-(tc[4][0]*s4)));
    fc[3][0] = ((3.32*(AnkAtk[3][0]-gk[3][0]))-ffk[3][0]);
    fc[3][1] = -ffk[3][1];
    fc[3][2] = ((3.32*(AnkAtk[3][2]-gk[3][2]))-ffk[3][2]);
    tc[3][0] = -(ttk[3][0]-(.211*fc[3][1]));
    tc[3][1] = ((.048025*Onkb[3][1])-(ttk[3][1]+(.211*fc[3][0])));
    tc[3][2] = -ttk[3][2];
    fccikt[3][0] = ((fc[3][0]*c3)+(fc[3][2]*s3));
    fccikt[3][1] = fc[3][1];
    fccikt[3][2] = ((fc[3][2]*c3)-(fc[3][0]*s3));
    ffk[2][0] = (ffk[2][0]-fccikt[3][0]);
    ffk[2][1] = (ffk[2][1]-fccikt[3][1]);
    ffk[2][2] = (ffk[2][2]-fccikt[3][2]);
    ttk[2][0] = (ttk[2][0]-(((.25*fccikt[3][1])-(.1*fccikt[3][2]))+((tc[3][0]*c3
      )+(tc[3][2]*s3))));
    ttk[2][1] = (ttk[2][1]-(tc[3][1]-(.25*fccikt[3][0])));
    ttk[2][2] = (ttk[2][2]-((.1*fccikt[3][0])+((tc[3][2]*c3)-(tc[3][0]*s3))));
    fc[2][0] = ((24.56*(Ankb[2][0]-(9.8*s2)))-ffk[2][0]);
    fc[2][1] = -ffk[2][1];
    fc[2][2] = ((24.56*(AnkAtk[2][2]+(9.8*c2)))-ffk[2][2]);
    tc[2][0] = -(ttk[2][0]-(.25*fc[2][1]));
    tc[2][1] = ((1.0181*udot[2])-(ttk[2][1]+(.25*fc[2][0])));
    tc[2][2] = -ttk[2][2];
    fccikt[2][0] = ((fc[2][0]*c2)+(fc[2][2]*s2));
    fccikt[2][1] = fc[2][1];
    fccikt[2][2] = ((fc[2][2]*c2)-(fc[2][0]*s2));
    ffk[1][0] = -fccikt[2][0];
    ffk[1][1] = -fccikt[2][1];
    ffk[1][2] = -fccikt[2][2];
    ttk[1][0] = -((tc[2][0]*c2)+(tc[2][2]*s2));
    ttk[1][1] = -tc[2][1];
    ttk[1][2] = -((tc[2][2]*c2)-(tc[2][0]*s2));
    fc[1][0] = -ffk[1][0];
    fc[1][1] = -ffk[1][1];
    fc[1][2] = -ffk[1][2];
    tc[1][0] = -ttk[1][0];
    tc[1][1] = -ttk[1][1];
    tc[1][2] = -ttk[1][2];
    fccikt[1][0] = fc[1][0];
    fccikt[1][1] = fc[1][1];
    fccikt[1][2] = fc[1][2];
    ffk[0][0] = -fccikt[1][0];
    ffk[0][1] = -fccikt[1][1];
    ffk[0][2] = -fccikt[1][2];
    ttk[0][0] = -(tc[1][0]-(fccikt[1][1]*q[1]));
    ttk[0][1] = -(tc[1][1]+(fccikt[1][0]*q[1]));
    ttk[0][2] = -tc[1][2];
    fc[0][0] = -ffk[0][0];
    fc[0][1] = -ffk[0][1];
    fc[0][2] = -ffk[0][2];
    tc[0][0] = -ttk[0][0];
    tc[0][1] = -ttk[0][1];
    tc[0][2] = -ttk[0][2];
    force[0][0] = fc[2][0];
    torque[0][0] = tc[2][0];
    force[0][1] = fc[2][1];
    torque[0][1] = tc[2][1];
    force[0][2] = fc[2][2];
    torque[0][2] = tc[2][2];
    force[1][0] = fc[3][0];
    torque[1][0] = tc[3][0];
    force[1][1] = fc[3][1];
    torque[1][1] = tc[3][1];
    force[1][2] = fc[3][2];
    torque[1][2] = tc[3][2];
    force[2][0] = fc[4][0];
    torque[2][0] = tc[4][0];
    force[2][1] = fc[4][1];
    torque[2][1] = tc[4][1];
    force[2][2] = fc[4][2];
    torque[2][2] = tc[4][2];
    force[3][0] = fc[5][0];
    torque[3][0] = tc[5][0];
    force[3][1] = fc[5][1];
    torque[3][1] = tc[5][1];
    force[3][2] = fc[5][2];
    torque[3][2] = tc[5][2];
    force[4][0] = fc[6][0];
    torque[4][0] = tc[6][0];
    force[4][1] = fc[6][1];
    torque[4][1] = tc[6][1];
    force[4][2] = fc[6][2];
    torque[4][2] = tc[6][2];
    force[5][0] = fc[7][0];
    torque[5][0] = tc[7][0];
    force[5][1] = fc[7][1];
    torque[5][1] = tc[7][1];
    force[5][2] = fc[7][2];
    torque[5][2] = tc[7][2];
    force[6][0] = fc[8][0];
    torque[6][0] = tc[8][0];
    force[6][1] = fc[8][1];
    torque[6][1] = tc[8][1];
    force[6][2] = fc[8][2];
    torque[6][2] = tc[8][2];
    force[7][0] = fc[9][0];
    torque[7][0] = tc[9][0];
    force[7][1] = fc[9][1];
    torque[7][1] = tc[9][1];
    force[7][2] = fc[9][2];
    torque[7][2] = tc[9][2];
    force[8][0] = fc[10][0];
    torque[8][0] = tc[10][0];
    force[8][1] = fc[10][1];
    torque[8][1] = tc[10][1];
    force[8][2] = fc[10][2];
    torque[8][2] = tc[10][2];
/*
Compute reaction forces for tree weld joints
*/
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  224 adds/subtracts/negates
                    145 multiplies
                      0 divides
                    210 assignments
*/
}

void sdmom(double lm[3],
    double am[3],
    double *ke)
{
/*
Compute system linear and angular momentum, and kinetic energy.

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
    double lk[9][3],hnk[9][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(19,23);
        return;
    }
    lm[0] = ((2.*vnk[10][0])+((2.*vnk[9][0])+((.2*vnk[8][0])+((3.3*vnk[7][0])+((
      3.32*vnk[6][0])+((.2*vnk[5][0])+((3.3*vnk[4][0])+((3.32*vnk[3][0])+(24.56*
      vnk[2][0])))))))));
    lm[1] = 0.;
    lm[2] = ((2.*vnk[10][2])+((2.*vnk[9][2])+((.2*vnk[8][2])+((3.3*vnk[7][2])+((
      3.32*vnk[6][2])+((.2*vnk[5][2])+((3.3*vnk[4][2])+((3.32*vnk[3][2])+(24.56*
      vnk[2][2])))))))));
    am[0] = ((.2*vnk[10][2])+(((.02*vnk[8][2])+((.33*vnk[7][2])+((.332*vnk[6][2]
      )-((.02*vnk[5][2])+((.33*vnk[4][2])+(.332*vnk[3][2]))))))-(.2*vnk[9][2])))
      ;
    temp[0] = (((.048025*wk[6][1])+(3.32*((rnk[6][2]*vnk[6][0])-(rnk[6][0]*
      vnk[6][2]))))+(((.000167*wk[5][1])+(.2*((rnk[5][2]*vnk[5][0])-(rnk[5][0]*
      vnk[5][2]))))+(((.062664*wk[4][1])+(3.3*((rnk[4][2]*vnk[4][0])-(rnk[4][0]*
      vnk[4][2]))))+(((.048025*wk[3][1])+(3.32*((rnk[3][2]*vnk[3][0])-(rnk[3][0]
      *vnk[3][2]))))+((1.0181*u[2])+(24.56*((rnk[2][2]*vnk[2][0])-(rnk[2][0]*
      vnk[2][2]))))))));
    am[1] = ((((.0818*wk[10][1])+(2.*((rnk[10][2]*vnk[10][0])-(rnk[10][0]*
      vnk[10][2]))))+(((.0818*wk[9][1])+(2.*((rnk[9][2]*vnk[9][0])-(rnk[9][0]*
      vnk[9][2]))))+(((.000167*wk[8][1])+(.2*((rnk[8][2]*vnk[8][0])-(rnk[8][0]*
      vnk[8][2]))))+(((.062664*wk[7][1])+(3.3*((rnk[7][2]*vnk[7][0])-(rnk[7][0]*
      vnk[7][2]))))+temp[0]))))-((com[2]*lm[0])-(com[0]*lm[2])));
    am[2] = (((.2*vnk[9][0])+(((((.02*vnk[5][0])+((.33*vnk[4][0])+(.332*
      vnk[3][0])))-(.332*vnk[6][0]))-(.33*vnk[7][0]))-(.02*vnk[8][0])))-(.2*
      vnk[10][0]));
    temp[0] = (((.000167*(wk[5][1]*wk[5][1]))+(.2*((vnk[5][0]*vnk[5][0])+(
      vnk[5][2]*vnk[5][2]))))+(((.062664*(wk[4][1]*wk[4][1]))+(3.3*((vnk[4][0]*
      vnk[4][0])+(vnk[4][2]*vnk[4][2]))))+(((.048025*(wk[3][1]*wk[3][1]))+(3.32*
      ((vnk[3][0]*vnk[3][0])+(vnk[3][2]*vnk[3][2]))))+((1.0181*(u[2]*u[2]))+(
      24.56*((vnk[2][0]*vnk[2][0])+(vnk[2][2]*vnk[2][2])))))));
    temp[1] = (((.0818*(wk[9][1]*wk[9][1]))+(2.*((vnk[9][0]*vnk[9][0])+(
      vnk[9][2]*vnk[9][2]))))+(((.000167*(wk[8][1]*wk[8][1]))+(.2*((vnk[8][0]*
      vnk[8][0])+(vnk[8][2]*vnk[8][2]))))+(((.062664*(wk[7][1]*wk[7][1]))+(3.3*(
      (vnk[7][0]*vnk[7][0])+(vnk[7][2]*vnk[7][2]))))+(((.048025*(wk[6][1]*
      wk[6][1]))+(3.32*((vnk[6][0]*vnk[6][0])+(vnk[6][2]*vnk[6][2]))))+temp[0]))
      ));
    *ke = (.5*(((.0818*(wk[10][1]*wk[10][1]))+(2.*((vnk[10][0]*vnk[10][0])+(
      vnk[10][2]*vnk[10][2]))))+temp[1]));
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   84 adds/subtracts/negates
                    118 multiplies
                      0 divides
                     10 assignments
*/
}

void sdsys(double *mtoto,
    double cm[3],
    double icm[3][3])
{
/*
Compute system total mass, and instantaneous center of mass and
inertia matrix.

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
    double ikcnkt[11][3][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(20,23);
        return;
    }
    *mtoto = 42.2;
    cm[0] = com[0];
    cm[1] = 0.;
    cm[2] = com[2];
    temp[0] = (((3.3*(.01+(rnk[4][2]*rnk[4][2])))+((.004592*(cnk[4][0][2]*
      cnk[4][0][2]))+(.062328*(cnk[4][0][0]*cnk[4][0][0]))))+(((.77354*(c2*c2))+
      (24.56*(rnk[2][2]*rnk[2][2])))+((3.32*(.01+(rnk[3][2]*rnk[3][2])))+((
      .000784*(cnk[3][0][2]*cnk[3][0][2]))+(.042892*(cnk[3][0][0]*cnk[3][0][0]))
      ))));
    temp[1] = (((3.3*(.01+(rnk[7][2]*rnk[7][2])))+((.004592*(cnk[7][0][2]*
      cnk[7][0][2]))+(.062328*(cnk[7][0][0]*cnk[7][0][0]))))+(((3.32*(.01+(
      rnk[6][2]*rnk[6][2])))+((.000784*(cnk[6][0][2]*cnk[6][0][2]))+(.042892*(
      cnk[6][0][0]*cnk[6][0][0]))))+(((.2*(.01+(rnk[5][2]*rnk[5][2])))+((1e-5*(
      cnk[5][0][2]*cnk[5][0][2]))+(.000167*(cnk[5][0][0]*cnk[5][0][0]))))+
      temp[0])));
    icm[0][0] = (.50336+((((2.*(.01+(rnk[10][2]*rnk[10][2])))+((.0029*(
      cnk[10][0][2]*cnk[10][0][2]))+(.0815*(cnk[10][0][0]*cnk[10][0][0]))))+(((
      2.*(.01+(rnk[9][2]*rnk[9][2])))+((.0029*(cnk[9][0][2]*cnk[9][0][2]))+(
      .0815*(cnk[9][0][0]*cnk[9][0][0]))))+(((.2*(.01+(rnk[8][2]*rnk[8][2])))+((
      1e-5*(cnk[8][0][2]*cnk[8][0][2]))+(.000167*(cnk[8][0][0]*cnk[8][0][0]))))+
      temp[1])))-(42.2*(com[2]*com[2]))));
    icm[0][1] = (((.2*rnk[9][0])+(((((.02*rnk[5][0])+((.33*rnk[4][0])+(.332*
      rnk[3][0])))-(.332*rnk[6][0]))-(.33*rnk[7][0]))-(.02*rnk[8][0])))-(.2*
      rnk[10][0]));
    temp[0] = ((((1e-5*(cnk[5][0][2]*cnk[5][2][2]))+(.000167*(cnk[5][0][0]*
      cnk[5][2][0])))-(.2*(rnk[5][0]*rnk[5][2])))+((((.004592*(cnk[4][0][2]*
      cnk[4][2][2]))+(.062328*(cnk[4][0][0]*cnk[4][2][0])))-(3.3*(rnk[4][0]*
      rnk[4][2])))+((((.000784*(cnk[3][0][2]*cnk[3][2][2]))+(.042892*(
      cnk[3][0][0]*cnk[3][2][0])))-(3.32*(rnk[3][0]*rnk[3][2])))-((.77354*(s2*c2
      ))+(24.56*(rnk[2][0]*rnk[2][2]))))));
    temp[1] = ((((1e-5*(cnk[8][0][2]*cnk[8][2][2]))+(.000167*(cnk[8][0][0]*
      cnk[8][2][0])))-(.2*(rnk[8][0]*rnk[8][2])))+((((.004592*(cnk[7][0][2]*
      cnk[7][2][2]))+(.062328*(cnk[7][0][0]*cnk[7][2][0])))-(3.3*(rnk[7][0]*
      rnk[7][2])))+((((.000784*(cnk[6][0][2]*cnk[6][2][2]))+(.042892*(
      cnk[6][0][0]*cnk[6][2][0])))-(3.32*(rnk[6][0]*rnk[6][2])))+temp[0])));
    icm[0][2] = ((42.2*(com[0]*com[2]))+((((.0029*(cnk[10][0][2]*cnk[10][2][2]))
      +(.0815*(cnk[10][0][0]*cnk[10][2][0])))-(2.*(rnk[10][0]*rnk[10][2])))+((((
      .0029*(cnk[9][0][2]*cnk[9][2][2]))+(.0815*(cnk[9][0][0]*cnk[9][2][0])))-(
      2.*(rnk[9][0]*rnk[9][2])))+temp[1])));
    icm[1][0] = icm[0][1];
    temp[0] = ((.2*((rnk[8][0]*rnk[8][0])+(rnk[8][2]*rnk[8][2])))+((3.3*((
      rnk[7][0]*rnk[7][0])+(rnk[7][2]*rnk[7][2])))+((3.32*((rnk[6][0]*rnk[6][0])
      +(rnk[6][2]*rnk[6][2])))+((.2*((rnk[5][0]*rnk[5][0])+(rnk[5][2]*rnk[5][2])
      ))+((3.3*((rnk[4][0]*rnk[4][0])+(rnk[4][2]*rnk[4][2])))+((3.32*((rnk[3][0]
      *rnk[3][0])+(rnk[3][2]*rnk[3][2])))+(24.56*((rnk[2][0]*rnk[2][0])+(
      rnk[2][2]*rnk[2][2])))))))));
    icm[1][1] = (1.403412+(((2.*((rnk[10][0]*rnk[10][0])+(rnk[10][2]*rnk[10][2])
      ))+((2.*((rnk[9][0]*rnk[9][0])+(rnk[9][2]*rnk[9][2])))+temp[0]))-(42.2*((
      com[0]*com[0])+(com[2]*com[2])))));
    icm[1][2] = (((.2*rnk[9][2])+(((((.02*rnk[5][2])+((.33*rnk[4][2])+(.332*
      rnk[3][2])))-(.332*rnk[6][2]))-(.33*rnk[7][2]))-(.02*rnk[8][2])))-(.2*
      rnk[10][2]));
    icm[2][0] = icm[0][2];
    icm[2][1] = icm[1][2];
    temp[0] = (((3.3*(.01+(rnk[4][0]*rnk[4][0])))+((.004592*(cnk[4][2][2]*
      cnk[4][2][2]))+(.062328*(cnk[4][2][0]*cnk[4][2][0]))))+(((.77354*(s2*s2))+
      (24.56*(rnk[2][0]*rnk[2][0])))+((3.32*(.01+(rnk[3][0]*rnk[3][0])))+((
      .000784*(cnk[3][2][2]*cnk[3][2][2]))+(.042892*(cnk[3][2][0]*cnk[3][2][0]))
      ))));
    temp[1] = (((3.3*(.01+(rnk[7][0]*rnk[7][0])))+((.004592*(cnk[7][2][2]*
      cnk[7][2][2]))+(.062328*(cnk[7][2][0]*cnk[7][2][0]))))+(((3.32*(.01+(
      rnk[6][0]*rnk[6][0])))+((.000784*(cnk[6][2][2]*cnk[6][2][2]))+(.042892*(
      cnk[6][2][0]*cnk[6][2][0]))))+(((.2*(.01+(rnk[5][0]*rnk[5][0])))+((1e-5*(
      cnk[5][2][2]*cnk[5][2][2]))+(.000167*(cnk[5][2][0]*cnk[5][2][0]))))+
      temp[0])));
    icm[2][2] = (.50336+((((2.*(.01+(rnk[10][0]*rnk[10][0])))+((.0029*(
      cnk[10][2][2]*cnk[10][2][2]))+(.0815*(cnk[10][2][0]*cnk[10][2][0]))))+(((
      2.*(.01+(rnk[9][0]*rnk[9][0])))+((.0029*(cnk[9][2][2]*cnk[9][2][2]))+(
      .0815*(cnk[9][2][0]*cnk[9][2][0]))))+(((.2*(.01+(rnk[8][0]*rnk[8][0])))+((
      1e-5*(cnk[8][2][2]*cnk[8][2][2]))+(.000167*(cnk[8][2][0]*cnk[8][2][0]))))+
      temp[1])))-(42.2*(com[0]*com[0]))));
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  130 adds/subtracts/negates
                    208 multiplies
                      0 divides
                     20 assignments
*/
}

void sdpos(int body,
    double pt[3],
    double loc[3])
{
/*
Return inertial frame location of a point on a body.

*/
    double pv[3];

    if (sdchkbnum(21,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(21,23);
        return;
    }
    if (body  ==  -1) {
        loc[0] = pt[0];
        loc[1] = pt[1];
        loc[2] = pt[2];
    } else {
        pv[0] = rnb[body][0]+pt[0]*cnb[body][0][0]+pt[1]*cnb[body][0][1]+pt[2]*
          cnb[body][0][2];
        pv[1] = rnb[body][1]+pt[0]*cnb[body][1][0]+pt[1]*cnb[body][1][1]+pt[2]*
          cnb[body][1][2];
        pv[2] = rnb[body][2]+pt[0]*cnb[body][2][0]+pt[1]*cnb[body][2][1]+pt[2]*
          cnb[body][2][2];
        loc[0] = pv[0];
        loc[1] = pv[1];
        loc[2] = pv[2];
    }
}

void sdvel(int body,
    double pt[3],
    double velo[3])
{
/*
Return inertial frame velocity of a point on a body.

*/
    double pv[3];

    if (sdchkbnum(22,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(22,23);
        return;
    }
    if (body  ==  -1) {
        velo[0] = 0.;
        velo[1] = 0.;
        velo[2] = 0.;
    } else {
        pv[0] = wb[body][1]*pt[2]-wb[body][2]*pt[1];
        pv[1] = wb[body][2]*pt[0]-wb[body][0]*pt[2];
        pv[2] = wb[body][0]*pt[1]-wb[body][1]*pt[0];
        velo[0] = vnb[body][0]+pv[0]*cnb[body][0][0]+pv[1]*cnb[body][0][1]+pv[2]
          *cnb[body][0][2];
        velo[1] = vnb[body][1]+pv[0]*cnb[body][1][0]+pv[1]*cnb[body][1][1]+pv[2]
          *cnb[body][1][2];
        velo[2] = vnb[body][2]+pv[0]*cnb[body][2][0]+pv[1]*cnb[body][2][1]+pv[2]
          *cnb[body][2][2];
    }
}

void sdorient(int body,
    double dircos[3][3])
{
/*
Return orientation of body w.r.t. ground frame.

*/

    if (sdchkbnum(23,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(23,23);
        return;
    }
    if (body == -1) {
        dircos[0][0] = 1.;
        dircos[0][1] = 0.;
        dircos[0][2] = 0.;
        dircos[1][0] = 0.;
        dircos[1][1] = 1.;
        dircos[1][2] = 0.;
        dircos[2][0] = 0.;
        dircos[2][1] = 0.;
        dircos[2][2] = 1.;
    } else {
        dircos[0][0] = cnb[body][0][0];
        dircos[0][1] = cnb[body][0][1];
        dircos[0][2] = cnb[body][0][2];
        dircos[1][0] = cnb[body][1][0];
        dircos[1][1] = cnb[body][1][1];
        dircos[1][2] = cnb[body][1][2];
        dircos[2][0] = cnb[body][2][0];
        dircos[2][1] = cnb[body][2][1];
        dircos[2][2] = cnb[body][2][2];
    }
}

void sdangvel(int body,
    double avel[3])
{
/*
Return angular velocity of the body.

*/

    if (sdchkbnum(24,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(24,23);
        return;
    }
    if (body == -1) {
        avel[0] = 0.;
        avel[1] = 0.;
        avel[2] = 0.;
    } else {
        avel[0] = wb[body][0];
        avel[1] = wb[body][1];
        avel[2] = wb[body][2];
    }
}

void sdtrans(int frbod,
    double ivec[3],
    int tobod,
    double ovec[3])
{
/*
Transform ivec from frbod frame to tobod frame.

*/
    double pv[3];

    if (sdchkbnum(25,frbod) != 0) {
        return;
    }
    if (sdchkbnum(25,tobod) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(25,23);
        return;
    }
    if (frbod == tobod) {
        sdvcopy(ivec,ovec);
        return;
    }
    if (frbod == -1) {
        sdvcopy(ivec,pv);
        ovec[0] = pv[0]*cnb[tobod][0][0]+pv[1]*cnb[tobod][1][0]+pv[2]*cnb[tobod
          ][2][0];
        ovec[1] = pv[0]*cnb[tobod][0][1]+pv[1]*cnb[tobod][1][1]+pv[2]*cnb[tobod
          ][2][1];
        ovec[2] = pv[0]*cnb[tobod][0][2]+pv[1]*cnb[tobod][1][2]+pv[2]*cnb[tobod
          ][2][2];
        return;
    }
    if (tobod == -1) {
        sdvcopy(ivec,pv);
        ovec[0] = pv[0]*cnb[frbod][0][0]+pv[1]*cnb[frbod][0][1]+pv[2]*cnb[frbod
          ][0][2];
        ovec[1] = pv[0]*cnb[frbod][1][0]+pv[1]*cnb[frbod][1][1]+pv[2]*cnb[frbod
          ][1][2];
        ovec[2] = pv[0]*cnb[frbod][2][0]+pv[1]*cnb[frbod][2][1]+pv[2]*cnb[frbod
          ][2][2];
        return;
    }
    pv[0] = ivec[0]*cnb[frbod][0][0]+ivec[1]*cnb[frbod][0][1]+ivec[2]*cnb[frbod
      ][0][2];
    pv[1] = ivec[0]*cnb[frbod][1][0]+ivec[1]*cnb[frbod][1][1]+ivec[2]*cnb[frbod
      ][1][2];
    pv[2] = ivec[0]*cnb[frbod][2][0]+ivec[1]*cnb[frbod][2][1]+ivec[2]*cnb[frbod
      ][2][2];
    ovec[0] = pv[0]*cnb[tobod][0][0]+pv[1]*cnb[tobod][1][0]+pv[2]*cnb[tobod][2][
      0];
    ovec[1] = pv[0]*cnb[tobod][0][1]+pv[1]*cnb[tobod][1][1]+pv[2]*cnb[tobod][2][
      1];
    ovec[2] = pv[0]*cnb[tobod][0][2]+pv[1]*cnb[tobod][1][2]+pv[2]*cnb[tobod][2][
      2];
}

void sdrel2cart(int coord,
    int body,
    double point[3],
    double linchg[3],
    double rotchg[3])
{
/* Return derivative of pt loc and body orient w.r.t. hinge rate
*/
    int x,i,gnd;
    double lin[3],pv[3];

    if ((coord < 0) || (coord > 10)) {
        sdseterr(59,45);
        return;
    }
    if (sdchkbnum(59,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(59,23);
        return;
    }
    gnd = -1;
    if (body == gnd) {
        x = -1;
    } else {
        x = firstq[body]+njntdof[body]-1;
    }
    if (x < coord) {
        sdvset(0.,0.,0.,linchg);
        sdvset(0.,0.,0.,rotchg);
        return;
    }
    sddovpk();
    for (i = 0; i < 3; i++) {
        rotchg[i] = Wpk[coord][x][i];
        lin[i] = Vpk[coord][x][i];
    }
    if (body == gnd) {
        sdvcopy(point,pv);
    } else {
        pv[0] = rcom[body][0]+point[0];
        pv[1] = rcom[body][1]+point[1];
        pv[2] = rcom[body][2]+point[2];
    }
    sdvcross(rotchg,pv,linchg);
    sdvadd(linchg,lin,linchg);
}

void sdacc(int body,
    double pt[3],
    double accel[3])
{
/*
Return linear acceleration a point of the specified body.

*/
    double pv[3];

    if (sdchkbnum(32,body) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(32,24);
        return;
    }
    if (body  ==  -1) {
        accel[0] = 0.;
        accel[1] = 0.;
        accel[2] = 0.;
    } else {
        pv[0] = pt[0]*dyad[body][0][0]+pt[1]*dyad[body][0][1]+pt[2]*dyad[body][0
          ][2];
        pv[1] = pt[0]*dyad[body][1][0]+pt[1]*dyad[body][1][1]+pt[2]*dyad[body][1
          ][2];
        pv[2] = pt[0]*dyad[body][2][0]+pt[1]*dyad[body][2][1]+pt[2]*dyad[body][2
          ][2];
        accel[0] = anb[body][0]+pv[0]*cnb[body][0][0]+pv[1]*cnb[body][0][1]+pv[2
          ]*cnb[body][0][2];
        accel[1] = anb[body][1]+pv[0]*cnb[body][1][0]+pv[1]*cnb[body][1][1]+pv[2
          ]*cnb[body][1][2];
        accel[2] = anb[body][2]+pv[0]*cnb[body][2][0]+pv[1]*cnb[body][2][1]+pv[2
          ]*cnb[body][2][2];
    }
}

void sdangacc(int body,
    double aacc[3])
{
/*
Return angular acceleration of the body.

*/

    if (sdchkbnum(33,body) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(33,24);
        return;
    }
    if (body == -1) {
        aacc[0] = 0.;
        aacc[1] = 0.;
        aacc[2] = 0.;
    } else {
        aacc[0] = onb[body][0];
        aacc[1] = onb[body][1];
        aacc[2] = onb[body][2];
    }
}

void sdgrav(double gravin[3])
{

    sdseterr(1,19);
    roustate = 0;
}

void sdmass(int body,
    double massin)
{

    if (sdchkbnum(2,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(2,15);
        return;
    }
    if (mkq[body] != 0) {
        mk[body] = massin;
        mkq[body] = 3;
    } else {
        sdseterr(2,19);
    }
    roustate = 0;
}

void sdiner(int body,
    double inerin[3][3])
{
    int anyques;

    if (sdchkbnum(3,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(3,15);
        return;
    }
    anyques = 0;
    if (ikq[body][0][0]  !=  0) {
        ik[body][0][0] = inerin[0][0];
        ikq[body][0][0] = 3;
        anyques = 1;
    }
    if (ikq[body][0][1]  !=  0) {
        ik[body][0][1] = inerin[0][1];
        ikq[body][0][1] = 3;
        ik[body][1][0] = inerin[0][1];
        ikq[body][1][0] = 3;
        anyques = 1;
    }
    if (ikq[body][0][2]  !=  0) {
        ik[body][0][2] = inerin[0][2];
        ikq[body][0][2] = 3;
        ik[body][2][0] = inerin[0][2];
        ikq[body][2][0] = 3;
        anyques = 1;
    }
    if (ikq[body][1][1]  !=  0) {
        ik[body][1][1] = inerin[1][1];
        ikq[body][1][1] = 3;
        anyques = 1;
    }
    if (ikq[body][1][2]  !=  0) {
        ik[body][1][2] = inerin[1][2];
        ikq[body][1][2] = 3;
        ik[body][2][1] = inerin[1][2];
        ikq[body][2][1] = 3;
        anyques = 1;
    }
    if (ikq[body][2][2]  !=  0) {
        ik[body][2][2] = inerin[2][2];
        ikq[body][2][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(3,19);
    }
    roustate = 0;
}

void sdbtj(int joint,
    double btjin[3])
{
    int anyques;

    if (sdchkjnum(4,joint) != 0) {
        return;
    }
    anyques = 0;
    if (rkq[joint][0]  !=  0) {
        rk[joint][0] = btjin[0];
        rkq[joint][0] = 3;
        anyques = 1;
    }
    if (rkq[joint][1]  !=  0) {
        rk[joint][1] = btjin[1];
        rkq[joint][1] = 3;
        anyques = 1;
    }
    if (rkq[joint][2]  !=  0) {
        rk[joint][2] = btjin[2];
        rkq[joint][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(4,19);
    }
    roustate = 0;
}

void sditj(int joint,
    double itjin[3])
{
    int anyques;

    if (sdchkjnum(5,joint) != 0) {
        return;
    }
    anyques = 0;
    if (riq[joint][0]  !=  0) {
        ri[joint][0] = itjin[0];
        riq[joint][0] = 3;
        anyques = 1;
    }
    if (riq[joint][1]  !=  0) {
        ri[joint][1] = itjin[1];
        riq[joint][1] = 3;
        anyques = 1;
    }
    if (riq[joint][2]  !=  0) {
        ri[joint][2] = itjin[2];
        riq[joint][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(5,19);
    }
    roustate = 0;
}

void sdpin(int joint,
    int pinno,
    double pinin[3])
{
    int anyques,offs;

    if (sdchkjpin(6,joint,pinno) != 0) {
        return;
    }
    anyques = 0;
    offs = firstq[joint]+pinno;
    if (jtype[joint] == 21) {
        offs = offs+3;
    }
    if (jtype[joint] == 11) {
        offs = offs+1;
    }
    if (pinq[offs][0]  !=  0) {
        pin[offs][0] = pinin[0];
        pinq[offs][0] = 3;
        anyques = 1;
    }
    if (pinq[offs][1]  !=  0) {
        pin[offs][1] = pinin[1];
        pinq[offs][1] = 3;
        anyques = 1;
    }
    if (pinq[offs][2]  !=  0) {
        pin[offs][2] = pinin[2];
        pinq[offs][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(6,19);
    }
    roustate = 0;
}

void sdpres(int joint,
    int axis,
    int presin)
{
    int anyques;

    if (sdchkjaxis(37,joint,axis) != 0) {
        return;
    }
    if ((presin != 0) && (presin != 1)) {
        sdseterr(37,20);
    }
    anyques = 0;
    if (presq[sdindx(joint,axis)]  !=  0) {
        if (presin  !=  0) {
            pres[sdindx(joint,axis)] = 1.;
        } else {
            pres[sdindx(joint,axis)] = 0.;
        }
        presq[sdindx(joint,axis)] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(37,19);
    }
    wwflg = 0;
}

void sdconschg(void)
{

    wwflg = 0;
}

void sdstab(double velin,
    double posin)
{

    stabvel = velin;
    stabvelq = 3;
    stabpos = posin;
    stabposq = 3;
}

void sdgetgrav(double gravout[3])
{

    gravout[0] = grav[0];
    gravout[1] = grav[1];
    gravout[2] = grav[2];
}

void sdgetmass(int body,
    double *massout)
{

    if (sdchkbnum(40,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(40,15);
        return;
    }
    *massout = mk[body];
}

void sdgetiner(int body,
    double inerout[3][3])
{

    if (sdchkbnum(41,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(41,15);
        return;
    }
    inerout[0][0] = ik[body][0][0];
    inerout[0][1] = ik[body][0][1];
    inerout[0][2] = ik[body][0][2];
    inerout[1][0] = ik[body][1][0];
    inerout[1][1] = ik[body][1][1];
    inerout[1][2] = ik[body][1][2];
    inerout[2][0] = ik[body][2][0];
    inerout[2][1] = ik[body][2][1];
    inerout[2][2] = ik[body][2][2];
}

void sdgetbtj(int joint,
    double btjout[3])
{

    if (sdchkjnum(42,joint) != 0) {
        return;
    }
    btjout[0] = rk[joint][0];
    btjout[1] = rk[joint][1];
    btjout[2] = rk[joint][2];
}

void sdgetitj(int joint,
    double itjout[3])
{

    if (sdchkjnum(43,joint) != 0) {
        return;
    }
    itjout[0] = ri[joint][0];
    itjout[1] = ri[joint][1];
    itjout[2] = ri[joint][2];
}

void sdgetpin(int joint,
    int pinno,
    double pinout[3])
{
    int offs;

    if (sdchkjpin(44,joint,pinno) != 0) {
        return;
    }
    offs = firstq[joint]+pinno;
    if (jtype[joint] == 21) {
        offs = offs+3;
    }
    if (jtype[joint] == 11) {
        offs = offs+1;
    }
    pinout[0] = pin[offs][0];
    pinout[1] = pin[offs][1];
    pinout[2] = pin[offs][2];
}

void sdgetpres(int joint,
    int axis,
    int *presout)
{

    if (sdchkjaxis(45,joint,axis) != 0) {
        return;
    }
    if (pres[sdindx(joint,axis)]  !=  0.) {
        *presout = 1;
    } else {
        *presout = 0;
    }
}

void sdgetstab(double *velout,
    double *posout)
{

    *velout = stabvel;
    *posout = stabpos;
}

void sdinfo(int info[50])
{

    info[0] = ground;
    info[1] = nbod;
    info[2] = ndof;
    info[3] = ncons;
    info[4] = nloop;
    info[5] = nldof;
    info[6] = nloopc;
    info[7] = nball;
    info[8] = nlball;
    info[9] = npres;
    info[10] = nuser;
    info[11] = 0;
/* info entries from 12-49 are reserved */
}

void sdjnt(int joint,
    int info[50],
    int tran[6])
{
    int i,offs;

    if (sdchkjnum(48,joint) != 0) {
        return;
    }
    info[0] = jtype[joint];
    info[1] = 0;
    offs = 0;
    info[2] = inb[joint];
    info[3] = outb[joint];
    info[4] = njntdof[joint];
    info[5] = njntc[joint];
    info[6] = njntp[joint];
    info[7] = firstq[joint];
    info[8] = ballq[joint];
    info[9] = firstm[joint];
    info[10] = firstp[joint];
/* info entries from 11-49 are reserved */

    for (i = 0; i <= 5; i++) {
        if (i  <  njntdof[joint]) {
            tran[i] = trans[offs+firstq[joint]+i];
        } else {
            tran[i] = -1;
        }
    }
}

void sdcons(int consno,
    int info[50])
{

    if (sdchkucnum(49,consno) != 0) {
        return;
    }
/* There are no user constraints in this problem. */
}

void sdgentime(int *gentm)
{

    *gentm = 111527;
}
/*
Done. CPU seconds used: 0.03  Memory used: 1744896 bytes.
Equation complexity:
  sdstate:   159 adds   243 multiplies     0 divides   372 assignments
  sdderiv:   860 adds  1050 multiplies    11 divides  1250 assignments
  sdresid:   413 adds   398 multiplies     0 divides   436 assignments
  sdreac:    224 adds   145 multiplies     0 divides   210 assignments
  sdmom:      84 adds   118 multiplies     0 divides    10 assignments
  sdsys:     130 adds   208 multiplies     0 divides    20 assignments
*/
