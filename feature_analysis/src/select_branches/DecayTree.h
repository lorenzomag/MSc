//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Aug 14 21:07:13 2021 by ROOT version 6.24/02
// from TTree DecayTree/DecayTree
// found on file: /home/loren/MSc/datasets/MC_2016_LcMVA.root
//////////////////////////////////////////////////////////

#ifndef DecayTree_h
#define DecayTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class DecayTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxXicst_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxXicst_OWNPV_COV = 1;
   static constexpr Int_t kMaxLc_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxLc_OWNPV_COV = 1;
   static constexpr Int_t kMaxLc_ORIVX_COV = 1;
   static constexpr Int_t kMaxLc_p_OWNPV_COV = 1;
   static constexpr Int_t kMaxLc_p_ORIVX_COV = 1;
   static constexpr Int_t kMaxLc_Km_OWNPV_COV = 1;
   static constexpr Int_t kMaxLc_Km_ORIVX_COV = 1;
   static constexpr Int_t kMaxLc_pip_OWNPV_COV = 1;
   static constexpr Int_t kMaxLc_pip_ORIVX_COV = 1;
   static constexpr Int_t kMaxpibach_OWNPV_COV = 1;
   static constexpr Int_t kMaxpibach_ORIVX_COV = 1;
   static constexpr Int_t kMaxKbach_OWNPV_COV = 1;
   static constexpr Int_t kMaxKbach_ORIVX_COV = 1;

   // Declaration of leaf types
   Double_t        Xicst_ENDVERTEX_X;
   Double_t        Xicst_ENDVERTEX_Y;
   Double_t        Xicst_ENDVERTEX_Z;
   Double_t        Xicst_ENDVERTEX_XERR;
   Double_t        Xicst_ENDVERTEX_YERR;
   Double_t        Xicst_ENDVERTEX_ZERR;
   Double_t        Xicst_ENDVERTEX_CHI2;
   Int_t           Xicst_ENDVERTEX_NDOF;
   Float_t         Xicst_ENDVERTEX_COV_[3][3];
   Double_t        Xicst_OWNPV_X;
   Double_t        Xicst_OWNPV_Y;
   Double_t        Xicst_OWNPV_Z;
   Double_t        Xicst_OWNPV_XERR;
   Double_t        Xicst_OWNPV_YERR;
   Double_t        Xicst_OWNPV_ZERR;
   Double_t        Xicst_OWNPV_CHI2;
   Int_t           Xicst_OWNPV_NDOF;
   Float_t         Xicst_OWNPV_COV_[3][3];
   Double_t        Xicst_IP_OWNPV;
   Double_t        Xicst_IPCHI2_OWNPV;
   Double_t        Xicst_FD_OWNPV;
   Double_t        Xicst_FDCHI2_OWNPV;
   Double_t        Xicst_DIRA_OWNPV;
   Double_t        Xicst_P;
   Double_t        Xicst_PT;
   Double_t        Xicst_PE;
   Double_t        Xicst_PX;
   Double_t        Xicst_PY;
   Double_t        Xicst_PZ;
   Double_t        Xicst_MM;
   Double_t        Xicst_MMERR;
   Double_t        Xicst_M;
   Int_t           Xicst_BKGCAT;
   Int_t           Xicst_TRUEID;
   Int_t           Xicst_MC_MOTHER_ID;
   Int_t           Xicst_MC_MOTHER_KEY;
   Int_t           Xicst_MC_GD_MOTHER_ID;
   Int_t           Xicst_MC_GD_MOTHER_KEY;
   Int_t           Xicst_MC_GD_GD_MOTHER_ID;
   Int_t           Xicst_MC_GD_GD_MOTHER_KEY;
   Double_t        Xicst_TRUEP_E;
   Double_t        Xicst_TRUEP_X;
   Double_t        Xicst_TRUEP_Y;
   Double_t        Xicst_TRUEP_Z;
   Double_t        Xicst_TRUEPT;
   Double_t        Xicst_TRUEORIGINVERTEX_X;
   Double_t        Xicst_TRUEORIGINVERTEX_Y;
   Double_t        Xicst_TRUEORIGINVERTEX_Z;
   Double_t        Xicst_TRUEENDVERTEX_X;
   Double_t        Xicst_TRUEENDVERTEX_Y;
   Double_t        Xicst_TRUEENDVERTEX_Z;
   Bool_t          Xicst_TRUEISSTABLE;
   Double_t        Xicst_TRUETAU;
   Int_t           Xicst_ID;
   Double_t        Xicst_DTF_LcPDG_DTF_CHI2;
   Double_t        Xicst_DTF_LcPDG_DTF_NDOF;
   Double_t        Xicst_DTF_LcPDG_Lc_M;
   Double_t        Xicst_DTF_LcPDG_Lc_PT;
   Double_t        Xicst_DTF_LcPDG_M;
   Double_t        Xicst_DTF_LcPDG_M12;
   Double_t        Xicst_DTF_LcPDG_PT;
   Double_t        Xicst_DTF_PV_DTF_CHI2;
   Double_t        Xicst_DTF_PV_DTF_NDOF;
   Double_t        Xicst_DTF_PV_Lc_M;
   Double_t        Xicst_DTF_PV_Lc_PT;
   Double_t        Xicst_DTF_PV_M;
   Double_t        Xicst_DTF_PV_M12;
   Double_t        Xicst_DTF_PV_PT;
   Double_t        Xicst_DTF_PV_LcPDG_DTF_CHI2;
   Double_t        Xicst_DTF_PV_LcPDG_DTF_NDOF;
   Double_t        Xicst_DTF_PV_LcPDG_Lc_M;
   Double_t        Xicst_DTF_PV_LcPDG_Lc_PT;
   Double_t        Xicst_DTF_PV_LcPDG_M;
   Double_t        Xicst_DTF_PV_LcPDG_M12;
   Double_t        Xicst_DTF_PV_LcPDG_PT;
   Double_t        Xicst_BPVIPCHI2;
   Double_t        Xicst_BPVVDCHI2;
   Double_t        Xicst_DOCA12;
   Double_t        Xicst_DOCA13;
   Double_t        Xicst_DOCA23;
   Double_t        Xicst_DOCACHI2MAX;
   Double_t        Xicst_DOCAMAX;
   Double_t        Xicst_DOCAMIN;
   Double_t        Xicst_ETA;
   Double_t        Xicst_M12;
   Double_t        Xicst_M13;
   Double_t        Xicst_M23;
   Double_t        Xicst_SUM_PT;
   Double_t        Xicst_Y;
   Double_t        Lc_ENDVERTEX_X;
   Double_t        Lc_ENDVERTEX_Y;
   Double_t        Lc_ENDVERTEX_Z;
   Double_t        Lc_ENDVERTEX_XERR;
   Double_t        Lc_ENDVERTEX_YERR;
   Double_t        Lc_ENDVERTEX_ZERR;
   Double_t        Lc_ENDVERTEX_CHI2;
   Int_t           Lc_ENDVERTEX_NDOF;
   Float_t         Lc_ENDVERTEX_COV_[3][3];
   Double_t        Lc_OWNPV_X;
   Double_t        Lc_OWNPV_Y;
   Double_t        Lc_OWNPV_Z;
   Double_t        Lc_OWNPV_XERR;
   Double_t        Lc_OWNPV_YERR;
   Double_t        Lc_OWNPV_ZERR;
   Double_t        Lc_OWNPV_CHI2;
   Int_t           Lc_OWNPV_NDOF;
   Float_t         Lc_OWNPV_COV_[3][3];
   Double_t        Lc_IP_OWNPV;
   Double_t        Lc_IPCHI2_OWNPV;
   Double_t        Lc_FD_OWNPV;
   Double_t        Lc_FDCHI2_OWNPV;
   Double_t        Lc_DIRA_OWNPV;
   Double_t        Lc_ORIVX_X;
   Double_t        Lc_ORIVX_Y;
   Double_t        Lc_ORIVX_Z;
   Double_t        Lc_ORIVX_XERR;
   Double_t        Lc_ORIVX_YERR;
   Double_t        Lc_ORIVX_ZERR;
   Double_t        Lc_ORIVX_CHI2;
   Int_t           Lc_ORIVX_NDOF;
   Float_t         Lc_ORIVX_COV_[3][3];
   Double_t        Lc_FD_ORIVX;
   Double_t        Lc_FDCHI2_ORIVX;
   Double_t        Lc_DIRA_ORIVX;
   Double_t        Lc_P;
   Double_t        Lc_PT;
   Double_t        Lc_PE;
   Double_t        Lc_PX;
   Double_t        Lc_PY;
   Double_t        Lc_PZ;
   Double_t        Lc_MM;
   Double_t        Lc_MMERR;
   Double_t        Lc_M;
   Int_t           Lc_BKGCAT;
   Int_t           Lc_TRUEID;
   Int_t           Lc_MC_MOTHER_ID;
   Int_t           Lc_MC_MOTHER_KEY;
   Int_t           Lc_MC_GD_MOTHER_ID;
   Int_t           Lc_MC_GD_MOTHER_KEY;
   Int_t           Lc_MC_GD_GD_MOTHER_ID;
   Int_t           Lc_MC_GD_GD_MOTHER_KEY;
   Double_t        Lc_TRUEP_E;
   Double_t        Lc_TRUEP_X;
   Double_t        Lc_TRUEP_Y;
   Double_t        Lc_TRUEP_Z;
   Double_t        Lc_TRUEPT;
   Double_t        Lc_TRUEORIGINVERTEX_X;
   Double_t        Lc_TRUEORIGINVERTEX_Y;
   Double_t        Lc_TRUEORIGINVERTEX_Z;
   Double_t        Lc_TRUEENDVERTEX_X;
   Double_t        Lc_TRUEENDVERTEX_Y;
   Double_t        Lc_TRUEENDVERTEX_Z;
   Bool_t          Lc_TRUEISSTABLE;
   Double_t        Lc_TRUETAU;
   Int_t           Lc_ID;
   Double_t        Lc_BPVIPCHI2;
   Double_t        Lc_BPVVDCHI2;
   Double_t        Lc_DOCA12;
   Double_t        Lc_DOCA13;
   Double_t        Lc_DOCA23;
   Double_t        Lc_DOCACHI2MAX;
   Double_t        Lc_DOCAMAX;
   Double_t        Lc_DOCAMIN;
   Double_t        Lc_ETA;
   Double_t        Lc_M12;
   Double_t        Lc_M13;
   Double_t        Lc_M23;
   Double_t        Lc_SUM_PT;
   Double_t        Lc_Y;
   Double_t        Lc_p_MC12TuneV2_ProbNNe;
   Double_t        Lc_p_MC12TuneV2_ProbNNmu;
   Double_t        Lc_p_MC12TuneV2_ProbNNpi;
   Double_t        Lc_p_MC12TuneV2_ProbNNk;
   Double_t        Lc_p_MC12TuneV2_ProbNNp;
   Double_t        Lc_p_MC12TuneV2_ProbNNghost;
   Double_t        Lc_p_MC12TuneV3_ProbNNe;
   Double_t        Lc_p_MC12TuneV3_ProbNNmu;
   Double_t        Lc_p_MC12TuneV3_ProbNNpi;
   Double_t        Lc_p_MC12TuneV3_ProbNNk;
   Double_t        Lc_p_MC12TuneV3_ProbNNp;
   Double_t        Lc_p_MC12TuneV3_ProbNNghost;
   Double_t        Lc_p_MC12TuneV4_ProbNNe;
   Double_t        Lc_p_MC12TuneV4_ProbNNmu;
   Double_t        Lc_p_MC12TuneV4_ProbNNpi;
   Double_t        Lc_p_MC12TuneV4_ProbNNk;
   Double_t        Lc_p_MC12TuneV4_ProbNNp;
   Double_t        Lc_p_MC12TuneV4_ProbNNghost;
   Double_t        Lc_p_MC15TuneV1_ProbNNe;
   Double_t        Lc_p_MC15TuneV1_ProbNNmu;
   Double_t        Lc_p_MC15TuneV1_ProbNNpi;
   Double_t        Lc_p_MC15TuneV1_ProbNNk;
   Double_t        Lc_p_MC15TuneV1_ProbNNp;
   Double_t        Lc_p_MC15TuneV1_ProbNNghost;
   Double_t        Lc_p_OWNPV_X;
   Double_t        Lc_p_OWNPV_Y;
   Double_t        Lc_p_OWNPV_Z;
   Double_t        Lc_p_OWNPV_XERR;
   Double_t        Lc_p_OWNPV_YERR;
   Double_t        Lc_p_OWNPV_ZERR;
   Double_t        Lc_p_OWNPV_CHI2;
   Int_t           Lc_p_OWNPV_NDOF;
   Float_t         Lc_p_OWNPV_COV_[3][3];
   Double_t        Lc_p_IP_OWNPV;
   Double_t        Lc_p_IPCHI2_OWNPV;
   Double_t        Lc_p_ORIVX_X;
   Double_t        Lc_p_ORIVX_Y;
   Double_t        Lc_p_ORIVX_Z;
   Double_t        Lc_p_ORIVX_XERR;
   Double_t        Lc_p_ORIVX_YERR;
   Double_t        Lc_p_ORIVX_ZERR;
   Double_t        Lc_p_ORIVX_CHI2;
   Int_t           Lc_p_ORIVX_NDOF;
   Float_t         Lc_p_ORIVX_COV_[3][3];
   Double_t        Lc_p_P;
   Double_t        Lc_p_PT;
   Double_t        Lc_p_PE;
   Double_t        Lc_p_PX;
   Double_t        Lc_p_PY;
   Double_t        Lc_p_PZ;
   Double_t        Lc_p_M;
   Int_t           Lc_p_TRUEID;
   Int_t           Lc_p_MC_MOTHER_ID;
   Int_t           Lc_p_MC_MOTHER_KEY;
   Int_t           Lc_p_MC_GD_MOTHER_ID;
   Int_t           Lc_p_MC_GD_MOTHER_KEY;
   Int_t           Lc_p_MC_GD_GD_MOTHER_ID;
   Int_t           Lc_p_MC_GD_GD_MOTHER_KEY;
   Double_t        Lc_p_TRUEP_E;
   Double_t        Lc_p_TRUEP_X;
   Double_t        Lc_p_TRUEP_Y;
   Double_t        Lc_p_TRUEP_Z;
   Double_t        Lc_p_TRUEPT;
   Double_t        Lc_p_TRUEORIGINVERTEX_X;
   Double_t        Lc_p_TRUEORIGINVERTEX_Y;
   Double_t        Lc_p_TRUEORIGINVERTEX_Z;
   Double_t        Lc_p_TRUEENDVERTEX_X;
   Double_t        Lc_p_TRUEENDVERTEX_Y;
   Double_t        Lc_p_TRUEENDVERTEX_Z;
   Bool_t          Lc_p_TRUEISSTABLE;
   Double_t        Lc_p_TRUETAU;
   Int_t           Lc_p_ID;
   Double_t        Lc_p_PIDe;
   Double_t        Lc_p_PIDmu;
   Double_t        Lc_p_PIDK;
   Double_t        Lc_p_PIDp;
   Double_t        Lc_p_PIDd;
   Double_t        Lc_p_ProbNNe;
   Double_t        Lc_p_ProbNNk;
   Double_t        Lc_p_ProbNNp;
   Double_t        Lc_p_ProbNNpi;
   Double_t        Lc_p_ProbNNmu;
   Double_t        Lc_p_ProbNNd;
   Double_t        Lc_p_ProbNNghost;
   Bool_t          Lc_p_hasMuon;
   Bool_t          Lc_p_isMuon;
   Bool_t          Lc_p_hasRich;
   Bool_t          Lc_p_UsedRichAerogel;
   Bool_t          Lc_p_UsedRich1Gas;
   Bool_t          Lc_p_UsedRich2Gas;
   Bool_t          Lc_p_RichAboveElThres;
   Bool_t          Lc_p_RichAboveMuThres;
   Bool_t          Lc_p_RichAbovePiThres;
   Bool_t          Lc_p_RichAboveKaThres;
   Bool_t          Lc_p_RichAbovePrThres;
   Bool_t          Lc_p_hasCalo;
   Int_t           Lc_p_TRACK_Type;
   Int_t           Lc_p_TRACK_Key;
   Double_t        Lc_p_TRACK_CHI2NDOF;
   Double_t        Lc_p_TRACK_PCHI2;
   Double_t        Lc_p_TRACK_MatchCHI2;
   Double_t        Lc_p_TRACK_GhostProb;
   Double_t        Lc_p_TRACK_CloneDist;
   Double_t        Lc_p_TRACK_Likelihood;
   Double_t        Lc_Km_MC12TuneV2_ProbNNe;
   Double_t        Lc_Km_MC12TuneV2_ProbNNmu;
   Double_t        Lc_Km_MC12TuneV2_ProbNNpi;
   Double_t        Lc_Km_MC12TuneV2_ProbNNk;
   Double_t        Lc_Km_MC12TuneV2_ProbNNp;
   Double_t        Lc_Km_MC12TuneV2_ProbNNghost;
   Double_t        Lc_Km_MC12TuneV3_ProbNNe;
   Double_t        Lc_Km_MC12TuneV3_ProbNNmu;
   Double_t        Lc_Km_MC12TuneV3_ProbNNpi;
   Double_t        Lc_Km_MC12TuneV3_ProbNNk;
   Double_t        Lc_Km_MC12TuneV3_ProbNNp;
   Double_t        Lc_Km_MC12TuneV3_ProbNNghost;
   Double_t        Lc_Km_MC12TuneV4_ProbNNe;
   Double_t        Lc_Km_MC12TuneV4_ProbNNmu;
   Double_t        Lc_Km_MC12TuneV4_ProbNNpi;
   Double_t        Lc_Km_MC12TuneV4_ProbNNk;
   Double_t        Lc_Km_MC12TuneV4_ProbNNp;
   Double_t        Lc_Km_MC12TuneV4_ProbNNghost;
   Double_t        Lc_Km_MC15TuneV1_ProbNNe;
   Double_t        Lc_Km_MC15TuneV1_ProbNNmu;
   Double_t        Lc_Km_MC15TuneV1_ProbNNpi;
   Double_t        Lc_Km_MC15TuneV1_ProbNNk;
   Double_t        Lc_Km_MC15TuneV1_ProbNNp;
   Double_t        Lc_Km_MC15TuneV1_ProbNNghost;
   Double_t        Lc_Km_OWNPV_X;
   Double_t        Lc_Km_OWNPV_Y;
   Double_t        Lc_Km_OWNPV_Z;
   Double_t        Lc_Km_OWNPV_XERR;
   Double_t        Lc_Km_OWNPV_YERR;
   Double_t        Lc_Km_OWNPV_ZERR;
   Double_t        Lc_Km_OWNPV_CHI2;
   Int_t           Lc_Km_OWNPV_NDOF;
   Float_t         Lc_Km_OWNPV_COV_[3][3];
   Double_t        Lc_Km_IP_OWNPV;
   Double_t        Lc_Km_IPCHI2_OWNPV;
   Double_t        Lc_Km_ORIVX_X;
   Double_t        Lc_Km_ORIVX_Y;
   Double_t        Lc_Km_ORIVX_Z;
   Double_t        Lc_Km_ORIVX_XERR;
   Double_t        Lc_Km_ORIVX_YERR;
   Double_t        Lc_Km_ORIVX_ZERR;
   Double_t        Lc_Km_ORIVX_CHI2;
   Int_t           Lc_Km_ORIVX_NDOF;
   Float_t         Lc_Km_ORIVX_COV_[3][3];
   Double_t        Lc_Km_P;
   Double_t        Lc_Km_PT;
   Double_t        Lc_Km_PE;
   Double_t        Lc_Km_PX;
   Double_t        Lc_Km_PY;
   Double_t        Lc_Km_PZ;
   Double_t        Lc_Km_M;
   Int_t           Lc_Km_TRUEID;
   Int_t           Lc_Km_MC_MOTHER_ID;
   Int_t           Lc_Km_MC_MOTHER_KEY;
   Int_t           Lc_Km_MC_GD_MOTHER_ID;
   Int_t           Lc_Km_MC_GD_MOTHER_KEY;
   Int_t           Lc_Km_MC_GD_GD_MOTHER_ID;
   Int_t           Lc_Km_MC_GD_GD_MOTHER_KEY;
   Double_t        Lc_Km_TRUEP_E;
   Double_t        Lc_Km_TRUEP_X;
   Double_t        Lc_Km_TRUEP_Y;
   Double_t        Lc_Km_TRUEP_Z;
   Double_t        Lc_Km_TRUEPT;
   Double_t        Lc_Km_TRUEORIGINVERTEX_X;
   Double_t        Lc_Km_TRUEORIGINVERTEX_Y;
   Double_t        Lc_Km_TRUEORIGINVERTEX_Z;
   Double_t        Lc_Km_TRUEENDVERTEX_X;
   Double_t        Lc_Km_TRUEENDVERTEX_Y;
   Double_t        Lc_Km_TRUEENDVERTEX_Z;
   Bool_t          Lc_Km_TRUEISSTABLE;
   Double_t        Lc_Km_TRUETAU;
   Int_t           Lc_Km_ID;
   Double_t        Lc_Km_PIDe;
   Double_t        Lc_Km_PIDmu;
   Double_t        Lc_Km_PIDK;
   Double_t        Lc_Km_PIDp;
   Double_t        Lc_Km_PIDd;
   Double_t        Lc_Km_ProbNNe;
   Double_t        Lc_Km_ProbNNk;
   Double_t        Lc_Km_ProbNNp;
   Double_t        Lc_Km_ProbNNpi;
   Double_t        Lc_Km_ProbNNmu;
   Double_t        Lc_Km_ProbNNd;
   Double_t        Lc_Km_ProbNNghost;
   Bool_t          Lc_Km_hasMuon;
   Bool_t          Lc_Km_isMuon;
   Bool_t          Lc_Km_hasRich;
   Bool_t          Lc_Km_UsedRichAerogel;
   Bool_t          Lc_Km_UsedRich1Gas;
   Bool_t          Lc_Km_UsedRich2Gas;
   Bool_t          Lc_Km_RichAboveElThres;
   Bool_t          Lc_Km_RichAboveMuThres;
   Bool_t          Lc_Km_RichAbovePiThres;
   Bool_t          Lc_Km_RichAboveKaThres;
   Bool_t          Lc_Km_RichAbovePrThres;
   Bool_t          Lc_Km_hasCalo;
   Int_t           Lc_Km_TRACK_Type;
   Int_t           Lc_Km_TRACK_Key;
   Double_t        Lc_Km_TRACK_CHI2NDOF;
   Double_t        Lc_Km_TRACK_PCHI2;
   Double_t        Lc_Km_TRACK_MatchCHI2;
   Double_t        Lc_Km_TRACK_GhostProb;
   Double_t        Lc_Km_TRACK_CloneDist;
   Double_t        Lc_Km_TRACK_Likelihood;
   Double_t        Lc_pip_MC12TuneV2_ProbNNe;
   Double_t        Lc_pip_MC12TuneV2_ProbNNmu;
   Double_t        Lc_pip_MC12TuneV2_ProbNNpi;
   Double_t        Lc_pip_MC12TuneV2_ProbNNk;
   Double_t        Lc_pip_MC12TuneV2_ProbNNp;
   Double_t        Lc_pip_MC12TuneV2_ProbNNghost;
   Double_t        Lc_pip_MC12TuneV3_ProbNNe;
   Double_t        Lc_pip_MC12TuneV3_ProbNNmu;
   Double_t        Lc_pip_MC12TuneV3_ProbNNpi;
   Double_t        Lc_pip_MC12TuneV3_ProbNNk;
   Double_t        Lc_pip_MC12TuneV3_ProbNNp;
   Double_t        Lc_pip_MC12TuneV3_ProbNNghost;
   Double_t        Lc_pip_MC12TuneV4_ProbNNe;
   Double_t        Lc_pip_MC12TuneV4_ProbNNmu;
   Double_t        Lc_pip_MC12TuneV4_ProbNNpi;
   Double_t        Lc_pip_MC12TuneV4_ProbNNk;
   Double_t        Lc_pip_MC12TuneV4_ProbNNp;
   Double_t        Lc_pip_MC12TuneV4_ProbNNghost;
   Double_t        Lc_pip_MC15TuneV1_ProbNNe;
   Double_t        Lc_pip_MC15TuneV1_ProbNNmu;
   Double_t        Lc_pip_MC15TuneV1_ProbNNpi;
   Double_t        Lc_pip_MC15TuneV1_ProbNNk;
   Double_t        Lc_pip_MC15TuneV1_ProbNNp;
   Double_t        Lc_pip_MC15TuneV1_ProbNNghost;
   Double_t        Lc_pip_OWNPV_X;
   Double_t        Lc_pip_OWNPV_Y;
   Double_t        Lc_pip_OWNPV_Z;
   Double_t        Lc_pip_OWNPV_XERR;
   Double_t        Lc_pip_OWNPV_YERR;
   Double_t        Lc_pip_OWNPV_ZERR;
   Double_t        Lc_pip_OWNPV_CHI2;
   Int_t           Lc_pip_OWNPV_NDOF;
   Float_t         Lc_pip_OWNPV_COV_[3][3];
   Double_t        Lc_pip_IP_OWNPV;
   Double_t        Lc_pip_IPCHI2_OWNPV;
   Double_t        Lc_pip_ORIVX_X;
   Double_t        Lc_pip_ORIVX_Y;
   Double_t        Lc_pip_ORIVX_Z;
   Double_t        Lc_pip_ORIVX_XERR;
   Double_t        Lc_pip_ORIVX_YERR;
   Double_t        Lc_pip_ORIVX_ZERR;
   Double_t        Lc_pip_ORIVX_CHI2;
   Int_t           Lc_pip_ORIVX_NDOF;
   Float_t         Lc_pip_ORIVX_COV_[3][3];
   Double_t        Lc_pip_P;
   Double_t        Lc_pip_PT;
   Double_t        Lc_pip_PE;
   Double_t        Lc_pip_PX;
   Double_t        Lc_pip_PY;
   Double_t        Lc_pip_PZ;
   Double_t        Lc_pip_M;
   Int_t           Lc_pip_TRUEID;
   Int_t           Lc_pip_MC_MOTHER_ID;
   Int_t           Lc_pip_MC_MOTHER_KEY;
   Int_t           Lc_pip_MC_GD_MOTHER_ID;
   Int_t           Lc_pip_MC_GD_MOTHER_KEY;
   Int_t           Lc_pip_MC_GD_GD_MOTHER_ID;
   Int_t           Lc_pip_MC_GD_GD_MOTHER_KEY;
   Double_t        Lc_pip_TRUEP_E;
   Double_t        Lc_pip_TRUEP_X;
   Double_t        Lc_pip_TRUEP_Y;
   Double_t        Lc_pip_TRUEP_Z;
   Double_t        Lc_pip_TRUEPT;
   Double_t        Lc_pip_TRUEORIGINVERTEX_X;
   Double_t        Lc_pip_TRUEORIGINVERTEX_Y;
   Double_t        Lc_pip_TRUEORIGINVERTEX_Z;
   Double_t        Lc_pip_TRUEENDVERTEX_X;
   Double_t        Lc_pip_TRUEENDVERTEX_Y;
   Double_t        Lc_pip_TRUEENDVERTEX_Z;
   Bool_t          Lc_pip_TRUEISSTABLE;
   Double_t        Lc_pip_TRUETAU;
   Int_t           Lc_pip_ID;
   Double_t        Lc_pip_PIDe;
   Double_t        Lc_pip_PIDmu;
   Double_t        Lc_pip_PIDK;
   Double_t        Lc_pip_PIDp;
   Double_t        Lc_pip_PIDd;
   Double_t        Lc_pip_ProbNNe;
   Double_t        Lc_pip_ProbNNk;
   Double_t        Lc_pip_ProbNNp;
   Double_t        Lc_pip_ProbNNpi;
   Double_t        Lc_pip_ProbNNmu;
   Double_t        Lc_pip_ProbNNd;
   Double_t        Lc_pip_ProbNNghost;
   Bool_t          Lc_pip_hasMuon;
   Bool_t          Lc_pip_isMuon;
   Bool_t          Lc_pip_hasRich;
   Bool_t          Lc_pip_UsedRichAerogel;
   Bool_t          Lc_pip_UsedRich1Gas;
   Bool_t          Lc_pip_UsedRich2Gas;
   Bool_t          Lc_pip_RichAboveElThres;
   Bool_t          Lc_pip_RichAboveMuThres;
   Bool_t          Lc_pip_RichAbovePiThres;
   Bool_t          Lc_pip_RichAboveKaThres;
   Bool_t          Lc_pip_RichAbovePrThres;
   Bool_t          Lc_pip_hasCalo;
   Int_t           Lc_pip_TRACK_Type;
   Int_t           Lc_pip_TRACK_Key;
   Double_t        Lc_pip_TRACK_CHI2NDOF;
   Double_t        Lc_pip_TRACK_PCHI2;
   Double_t        Lc_pip_TRACK_MatchCHI2;
   Double_t        Lc_pip_TRACK_GhostProb;
   Double_t        Lc_pip_TRACK_CloneDist;
   Double_t        Lc_pip_TRACK_Likelihood;
   Double_t        pibach_MC12TuneV2_ProbNNe;
   Double_t        pibach_MC12TuneV2_ProbNNmu;
   Double_t        pibach_MC12TuneV2_ProbNNpi;
   Double_t        pibach_MC12TuneV2_ProbNNk;
   Double_t        pibach_MC12TuneV2_ProbNNp;
   Double_t        pibach_MC12TuneV2_ProbNNghost;
   Double_t        pibach_MC12TuneV3_ProbNNe;
   Double_t        pibach_MC12TuneV3_ProbNNmu;
   Double_t        pibach_MC12TuneV3_ProbNNpi;
   Double_t        pibach_MC12TuneV3_ProbNNk;
   Double_t        pibach_MC12TuneV3_ProbNNp;
   Double_t        pibach_MC12TuneV3_ProbNNghost;
   Double_t        pibach_MC12TuneV4_ProbNNe;
   Double_t        pibach_MC12TuneV4_ProbNNmu;
   Double_t        pibach_MC12TuneV4_ProbNNpi;
   Double_t        pibach_MC12TuneV4_ProbNNk;
   Double_t        pibach_MC12TuneV4_ProbNNp;
   Double_t        pibach_MC12TuneV4_ProbNNghost;
   Double_t        pibach_MC15TuneV1_ProbNNe;
   Double_t        pibach_MC15TuneV1_ProbNNmu;
   Double_t        pibach_MC15TuneV1_ProbNNpi;
   Double_t        pibach_MC15TuneV1_ProbNNk;
   Double_t        pibach_MC15TuneV1_ProbNNp;
   Double_t        pibach_MC15TuneV1_ProbNNghost;
   Double_t        pibach_OWNPV_X;
   Double_t        pibach_OWNPV_Y;
   Double_t        pibach_OWNPV_Z;
   Double_t        pibach_OWNPV_XERR;
   Double_t        pibach_OWNPV_YERR;
   Double_t        pibach_OWNPV_ZERR;
   Double_t        pibach_OWNPV_CHI2;
   Int_t           pibach_OWNPV_NDOF;
   Float_t         pibach_OWNPV_COV_[3][3];
   Double_t        pibach_IP_OWNPV;
   Double_t        pibach_IPCHI2_OWNPV;
   Double_t        pibach_ORIVX_X;
   Double_t        pibach_ORIVX_Y;
   Double_t        pibach_ORIVX_Z;
   Double_t        pibach_ORIVX_XERR;
   Double_t        pibach_ORIVX_YERR;
   Double_t        pibach_ORIVX_ZERR;
   Double_t        pibach_ORIVX_CHI2;
   Int_t           pibach_ORIVX_NDOF;
   Float_t         pibach_ORIVX_COV_[3][3];
   Double_t        pibach_P;
   Double_t        pibach_PT;
   Double_t        pibach_PE;
   Double_t        pibach_PX;
   Double_t        pibach_PY;
   Double_t        pibach_PZ;
   Double_t        pibach_M;
   Int_t           pibach_TRUEID;
   Int_t           pibach_MC_MOTHER_ID;
   Int_t           pibach_MC_MOTHER_KEY;
   Int_t           pibach_MC_GD_MOTHER_ID;
   Int_t           pibach_MC_GD_MOTHER_KEY;
   Int_t           pibach_MC_GD_GD_MOTHER_ID;
   Int_t           pibach_MC_GD_GD_MOTHER_KEY;
   Double_t        pibach_TRUEP_E;
   Double_t        pibach_TRUEP_X;
   Double_t        pibach_TRUEP_Y;
   Double_t        pibach_TRUEP_Z;
   Double_t        pibach_TRUEPT;
   Double_t        pibach_TRUEORIGINVERTEX_X;
   Double_t        pibach_TRUEORIGINVERTEX_Y;
   Double_t        pibach_TRUEORIGINVERTEX_Z;
   Double_t        pibach_TRUEENDVERTEX_X;
   Double_t        pibach_TRUEENDVERTEX_Y;
   Double_t        pibach_TRUEENDVERTEX_Z;
   Bool_t          pibach_TRUEISSTABLE;
   Double_t        pibach_TRUETAU;
   Int_t           pibach_ID;
   Double_t        pibach_PIDe;
   Double_t        pibach_PIDmu;
   Double_t        pibach_PIDK;
   Double_t        pibach_PIDp;
   Double_t        pibach_PIDd;
   Double_t        pibach_ProbNNe;
   Double_t        pibach_ProbNNk;
   Double_t        pibach_ProbNNp;
   Double_t        pibach_ProbNNpi;
   Double_t        pibach_ProbNNmu;
   Double_t        pibach_ProbNNd;
   Double_t        pibach_ProbNNghost;
   Bool_t          pibach_hasMuon;
   Bool_t          pibach_isMuon;
   Bool_t          pibach_hasRich;
   Bool_t          pibach_UsedRichAerogel;
   Bool_t          pibach_UsedRich1Gas;
   Bool_t          pibach_UsedRich2Gas;
   Bool_t          pibach_RichAboveElThres;
   Bool_t          pibach_RichAboveMuThres;
   Bool_t          pibach_RichAbovePiThres;
   Bool_t          pibach_RichAboveKaThres;
   Bool_t          pibach_RichAbovePrThres;
   Bool_t          pibach_hasCalo;
   Int_t           pibach_TRACK_Type;
   Int_t           pibach_TRACK_Key;
   Double_t        pibach_TRACK_CHI2NDOF;
   Double_t        pibach_TRACK_PCHI2;
   Double_t        pibach_TRACK_MatchCHI2;
   Double_t        pibach_TRACK_GhostProb;
   Double_t        pibach_TRACK_CloneDist;
   Double_t        pibach_TRACK_Likelihood;
   Double_t        Kbach_MC12TuneV2_ProbNNe;
   Double_t        Kbach_MC12TuneV2_ProbNNmu;
   Double_t        Kbach_MC12TuneV2_ProbNNpi;
   Double_t        Kbach_MC12TuneV2_ProbNNk;
   Double_t        Kbach_MC12TuneV2_ProbNNp;
   Double_t        Kbach_MC12TuneV2_ProbNNghost;
   Double_t        Kbach_MC12TuneV3_ProbNNe;
   Double_t        Kbach_MC12TuneV3_ProbNNmu;
   Double_t        Kbach_MC12TuneV3_ProbNNpi;
   Double_t        Kbach_MC12TuneV3_ProbNNk;
   Double_t        Kbach_MC12TuneV3_ProbNNp;
   Double_t        Kbach_MC12TuneV3_ProbNNghost;
   Double_t        Kbach_MC12TuneV4_ProbNNe;
   Double_t        Kbach_MC12TuneV4_ProbNNmu;
   Double_t        Kbach_MC12TuneV4_ProbNNpi;
   Double_t        Kbach_MC12TuneV4_ProbNNk;
   Double_t        Kbach_MC12TuneV4_ProbNNp;
   Double_t        Kbach_MC12TuneV4_ProbNNghost;
   Double_t        Kbach_MC15TuneV1_ProbNNe;
   Double_t        Kbach_MC15TuneV1_ProbNNmu;
   Double_t        Kbach_MC15TuneV1_ProbNNpi;
   Double_t        Kbach_MC15TuneV1_ProbNNk;
   Double_t        Kbach_MC15TuneV1_ProbNNp;
   Double_t        Kbach_MC15TuneV1_ProbNNghost;
   Double_t        Kbach_OWNPV_X;
   Double_t        Kbach_OWNPV_Y;
   Double_t        Kbach_OWNPV_Z;
   Double_t        Kbach_OWNPV_XERR;
   Double_t        Kbach_OWNPV_YERR;
   Double_t        Kbach_OWNPV_ZERR;
   Double_t        Kbach_OWNPV_CHI2;
   Int_t           Kbach_OWNPV_NDOF;
   Float_t         Kbach_OWNPV_COV_[3][3];
   Double_t        Kbach_IP_OWNPV;
   Double_t        Kbach_IPCHI2_OWNPV;
   Double_t        Kbach_ORIVX_X;
   Double_t        Kbach_ORIVX_Y;
   Double_t        Kbach_ORIVX_Z;
   Double_t        Kbach_ORIVX_XERR;
   Double_t        Kbach_ORIVX_YERR;
   Double_t        Kbach_ORIVX_ZERR;
   Double_t        Kbach_ORIVX_CHI2;
   Int_t           Kbach_ORIVX_NDOF;
   Float_t         Kbach_ORIVX_COV_[3][3];
   Double_t        Kbach_P;
   Double_t        Kbach_PT;
   Double_t        Kbach_PE;
   Double_t        Kbach_PX;
   Double_t        Kbach_PY;
   Double_t        Kbach_PZ;
   Double_t        Kbach_M;
   Int_t           Kbach_TRUEID;
   Int_t           Kbach_MC_MOTHER_ID;
   Int_t           Kbach_MC_MOTHER_KEY;
   Int_t           Kbach_MC_GD_MOTHER_ID;
   Int_t           Kbach_MC_GD_MOTHER_KEY;
   Int_t           Kbach_MC_GD_GD_MOTHER_ID;
   Int_t           Kbach_MC_GD_GD_MOTHER_KEY;
   Double_t        Kbach_TRUEP_E;
   Double_t        Kbach_TRUEP_X;
   Double_t        Kbach_TRUEP_Y;
   Double_t        Kbach_TRUEP_Z;
   Double_t        Kbach_TRUEPT;
   Double_t        Kbach_TRUEORIGINVERTEX_X;
   Double_t        Kbach_TRUEORIGINVERTEX_Y;
   Double_t        Kbach_TRUEORIGINVERTEX_Z;
   Double_t        Kbach_TRUEENDVERTEX_X;
   Double_t        Kbach_TRUEENDVERTEX_Y;
   Double_t        Kbach_TRUEENDVERTEX_Z;
   Bool_t          Kbach_TRUEISSTABLE;
   Double_t        Kbach_TRUETAU;
   Int_t           Kbach_ID;
   Double_t        Kbach_PIDe;
   Double_t        Kbach_PIDmu;
   Double_t        Kbach_PIDK;
   Double_t        Kbach_PIDp;
   Double_t        Kbach_PIDd;
   Double_t        Kbach_ProbNNe;
   Double_t        Kbach_ProbNNk;
   Double_t        Kbach_ProbNNp;
   Double_t        Kbach_ProbNNpi;
   Double_t        Kbach_ProbNNmu;
   Double_t        Kbach_ProbNNd;
   Double_t        Kbach_ProbNNghost;
   Bool_t          Kbach_hasMuon;
   Bool_t          Kbach_isMuon;
   Bool_t          Kbach_hasRich;
   Bool_t          Kbach_UsedRichAerogel;
   Bool_t          Kbach_UsedRich1Gas;
   Bool_t          Kbach_UsedRich2Gas;
   Bool_t          Kbach_RichAboveElThres;
   Bool_t          Kbach_RichAboveMuThres;
   Bool_t          Kbach_RichAbovePiThres;
   Bool_t          Kbach_RichAboveKaThres;
   Bool_t          Kbach_RichAbovePrThres;
   Bool_t          Kbach_hasCalo;
   Int_t           Kbach_TRACK_Type;
   Int_t           Kbach_TRACK_Key;
   Double_t        Kbach_TRACK_CHI2NDOF;
   Double_t        Kbach_TRACK_PCHI2;
   Double_t        Kbach_TRACK_MatchCHI2;
   Double_t        Kbach_TRACK_GhostProb;
   Double_t        Kbach_TRACK_CloneDist;
   Double_t        Kbach_TRACK_Likelihood;
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLT1TCK;
   UInt_t          HLT2TCK;
   ULong64_t       GpsTime;
   Short_t         Polarity;
   Int_t           nPV;
   Float_t         PVX[100];   //[nPV]
   Float_t         PVY[100];   //[nPV]
   Float_t         PVZ[100];   //[nPV]
   Float_t         PVXERR[100];   //[nPV]
   Float_t         PVYERR[100];   //[nPV]
   Float_t         PVZERR[100];   //[nPV]
   Float_t         PVCHI2[100];   //[nPV]
   Float_t         PVNDOF[100];   //[nPV]
   Float_t         PVNTRACKS[100];   //[nPV]
   Float_t         Lc_bdtg;

   // List of branches
   TBranch        *b_Xicst_ENDVERTEX_X;   //!
   TBranch        *b_Xicst_ENDVERTEX_Y;   //!
   TBranch        *b_Xicst_ENDVERTEX_Z;   //!
   TBranch        *b_Xicst_ENDVERTEX_XERR;   //!
   TBranch        *b_Xicst_ENDVERTEX_YERR;   //!
   TBranch        *b_Xicst_ENDVERTEX_ZERR;   //!
   TBranch        *b_Xicst_ENDVERTEX_CHI2;   //!
   TBranch        *b_Xicst_ENDVERTEX_NDOF;   //!
   TBranch        *b_Xicst_ENDVERTEX_COV_;   //!
   TBranch        *b_Xicst_OWNPV_X;   //!
   TBranch        *b_Xicst_OWNPV_Y;   //!
   TBranch        *b_Xicst_OWNPV_Z;   //!
   TBranch        *b_Xicst_OWNPV_XERR;   //!
   TBranch        *b_Xicst_OWNPV_YERR;   //!
   TBranch        *b_Xicst_OWNPV_ZERR;   //!
   TBranch        *b_Xicst_OWNPV_CHI2;   //!
   TBranch        *b_Xicst_OWNPV_NDOF;   //!
   TBranch        *b_Xicst_OWNPV_COV_;   //!
   TBranch        *b_Xicst_IP_OWNPV;   //!
   TBranch        *b_Xicst_IPCHI2_OWNPV;   //!
   TBranch        *b_Xicst_FD_OWNPV;   //!
   TBranch        *b_Xicst_FDCHI2_OWNPV;   //!
   TBranch        *b_Xicst_DIRA_OWNPV;   //!
   TBranch        *b_Xicst_P;   //!
   TBranch        *b_Xicst_PT;   //!
   TBranch        *b_Xicst_PE;   //!
   TBranch        *b_Xicst_PX;   //!
   TBranch        *b_Xicst_PY;   //!
   TBranch        *b_Xicst_PZ;   //!
   TBranch        *b_Xicst_MM;   //!
   TBranch        *b_Xicst_MMERR;   //!
   TBranch        *b_Xicst_M;   //!
   TBranch        *b_Xicst_BKGCAT;   //!
   TBranch        *b_Xicst_TRUEID;   //!
   TBranch        *b_Xicst_MC_MOTHER_ID;   //!
   TBranch        *b_Xicst_MC_MOTHER_KEY;   //!
   TBranch        *b_Xicst_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Xicst_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Xicst_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Xicst_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Xicst_TRUEP_E;   //!
   TBranch        *b_Xicst_TRUEP_X;   //!
   TBranch        *b_Xicst_TRUEP_Y;   //!
   TBranch        *b_Xicst_TRUEP_Z;   //!
   TBranch        *b_Xicst_TRUEPT;   //!
   TBranch        *b_Xicst_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Xicst_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Xicst_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Xicst_TRUEENDVERTEX_X;   //!
   TBranch        *b_Xicst_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Xicst_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Xicst_TRUEISSTABLE;   //!
   TBranch        *b_Xicst_TRUETAU;   //!
   TBranch        *b_Xicst_ID;   //!
   TBranch        *b_Xicst_DTF_LcPDG_DTF_CHI2;   //!
   TBranch        *b_Xicst_DTF_LcPDG_DTF_NDOF;   //!
   TBranch        *b_Xicst_DTF_LcPDG_Lc_M;   //!
   TBranch        *b_Xicst_DTF_LcPDG_Lc_PT;   //!
   TBranch        *b_Xicst_DTF_LcPDG_M;   //!
   TBranch        *b_Xicst_DTF_LcPDG_M12;   //!
   TBranch        *b_Xicst_DTF_LcPDG_PT;   //!
   TBranch        *b_Xicst_DTF_PV_DTF_CHI2;   //!
   TBranch        *b_Xicst_DTF_PV_DTF_NDOF;   //!
   TBranch        *b_Xicst_DTF_PV_Lc_M;   //!
   TBranch        *b_Xicst_DTF_PV_Lc_PT;   //!
   TBranch        *b_Xicst_DTF_PV_M;   //!
   TBranch        *b_Xicst_DTF_PV_M12;   //!
   TBranch        *b_Xicst_DTF_PV_PT;   //!
   TBranch        *b_Xicst_DTF_PV_LcPDG_DTF_CHI2;   //!
   TBranch        *b_Xicst_DTF_PV_LcPDG_DTF_NDOF;   //!
   TBranch        *b_Xicst_DTF_PV_LcPDG_Lc_M;   //!
   TBranch        *b_Xicst_DTF_PV_LcPDG_Lc_PT;   //!
   TBranch        *b_Xicst_DTF_PV_LcPDG_M;   //!
   TBranch        *b_Xicst_DTF_PV_LcPDG_M12;   //!
   TBranch        *b_Xicst_DTF_PV_LcPDG_PT;   //!
   TBranch        *b_Xicst_BPVIPCHI2;   //!
   TBranch        *b_Xicst_BPVVDCHI2;   //!
   TBranch        *b_Xicst_DOCA12;   //!
   TBranch        *b_Xicst_DOCA13;   //!
   TBranch        *b_Xicst_DOCA23;   //!
   TBranch        *b_Xicst_DOCACHI2MAX;   //!
   TBranch        *b_Xicst_DOCAMAX;   //!
   TBranch        *b_Xicst_DOCAMIN;   //!
   TBranch        *b_Xicst_ETA;   //!
   TBranch        *b_Xicst_M12;   //!
   TBranch        *b_Xicst_M13;   //!
   TBranch        *b_Xicst_M23;   //!
   TBranch        *b_Xicst_SUM_PT;   //!
   TBranch        *b_Xicst_Y;   //!
   TBranch        *b_Lc_ENDVERTEX_X;   //!
   TBranch        *b_Lc_ENDVERTEX_Y;   //!
   TBranch        *b_Lc_ENDVERTEX_Z;   //!
   TBranch        *b_Lc_ENDVERTEX_XERR;   //!
   TBranch        *b_Lc_ENDVERTEX_YERR;   //!
   TBranch        *b_Lc_ENDVERTEX_ZERR;   //!
   TBranch        *b_Lc_ENDVERTEX_CHI2;   //!
   TBranch        *b_Lc_ENDVERTEX_NDOF;   //!
   TBranch        *b_Lc_ENDVERTEX_COV_;   //!
   TBranch        *b_Lc_OWNPV_X;   //!
   TBranch        *b_Lc_OWNPV_Y;   //!
   TBranch        *b_Lc_OWNPV_Z;   //!
   TBranch        *b_Lc_OWNPV_XERR;   //!
   TBranch        *b_Lc_OWNPV_YERR;   //!
   TBranch        *b_Lc_OWNPV_ZERR;   //!
   TBranch        *b_Lc_OWNPV_CHI2;   //!
   TBranch        *b_Lc_OWNPV_NDOF;   //!
   TBranch        *b_Lc_OWNPV_COV_;   //!
   TBranch        *b_Lc_IP_OWNPV;   //!
   TBranch        *b_Lc_IPCHI2_OWNPV;   //!
   TBranch        *b_Lc_FD_OWNPV;   //!
   TBranch        *b_Lc_FDCHI2_OWNPV;   //!
   TBranch        *b_Lc_DIRA_OWNPV;   //!
   TBranch        *b_Lc_ORIVX_X;   //!
   TBranch        *b_Lc_ORIVX_Y;   //!
   TBranch        *b_Lc_ORIVX_Z;   //!
   TBranch        *b_Lc_ORIVX_XERR;   //!
   TBranch        *b_Lc_ORIVX_YERR;   //!
   TBranch        *b_Lc_ORIVX_ZERR;   //!
   TBranch        *b_Lc_ORIVX_CHI2;   //!
   TBranch        *b_Lc_ORIVX_NDOF;   //!
   TBranch        *b_Lc_ORIVX_COV_;   //!
   TBranch        *b_Lc_FD_ORIVX;   //!
   TBranch        *b_Lc_FDCHI2_ORIVX;   //!
   TBranch        *b_Lc_DIRA_ORIVX;   //!
   TBranch        *b_Lc_P;   //!
   TBranch        *b_Lc_PT;   //!
   TBranch        *b_Lc_PE;   //!
   TBranch        *b_Lc_PX;   //!
   TBranch        *b_Lc_PY;   //!
   TBranch        *b_Lc_PZ;   //!
   TBranch        *b_Lc_MM;   //!
   TBranch        *b_Lc_MMERR;   //!
   TBranch        *b_Lc_M;   //!
   TBranch        *b_Lc_BKGCAT;   //!
   TBranch        *b_Lc_TRUEID;   //!
   TBranch        *b_Lc_MC_MOTHER_ID;   //!
   TBranch        *b_Lc_MC_MOTHER_KEY;   //!
   TBranch        *b_Lc_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Lc_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Lc_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Lc_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Lc_TRUEP_E;   //!
   TBranch        *b_Lc_TRUEP_X;   //!
   TBranch        *b_Lc_TRUEP_Y;   //!
   TBranch        *b_Lc_TRUEP_Z;   //!
   TBranch        *b_Lc_TRUEPT;   //!
   TBranch        *b_Lc_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Lc_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Lc_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Lc_TRUEENDVERTEX_X;   //!
   TBranch        *b_Lc_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Lc_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Lc_TRUEISSTABLE;   //!
   TBranch        *b_Lc_TRUETAU;   //!
   TBranch        *b_Lc_ID;   //!
   TBranch        *b_Lc_BPVIPCHI2;   //!
   TBranch        *b_Lc_BPVVDCHI2;   //!
   TBranch        *b_Lc_DOCA12;   //!
   TBranch        *b_Lc_DOCA13;   //!
   TBranch        *b_Lc_DOCA23;   //!
   TBranch        *b_Lc_DOCACHI2MAX;   //!
   TBranch        *b_Lc_DOCAMAX;   //!
   TBranch        *b_Lc_DOCAMIN;   //!
   TBranch        *b_Lc_ETA;   //!
   TBranch        *b_Lc_M12;   //!
   TBranch        *b_Lc_M13;   //!
   TBranch        *b_Lc_M23;   //!
   TBranch        *b_Lc_SUM_PT;   //!
   TBranch        *b_Lc_Y;   //!
   TBranch        *b_Lc_p_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_Lc_p_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_Lc_p_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_Lc_p_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_Lc_p_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_Lc_p_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_Lc_p_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_Lc_p_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_Lc_p_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_Lc_p_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_Lc_p_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_Lc_p_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_Lc_p_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_Lc_p_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_Lc_p_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_Lc_p_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_Lc_p_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_Lc_p_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_Lc_p_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_Lc_p_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_Lc_p_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_Lc_p_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_Lc_p_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_Lc_p_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_Lc_p_OWNPV_X;   //!
   TBranch        *b_Lc_p_OWNPV_Y;   //!
   TBranch        *b_Lc_p_OWNPV_Z;   //!
   TBranch        *b_Lc_p_OWNPV_XERR;   //!
   TBranch        *b_Lc_p_OWNPV_YERR;   //!
   TBranch        *b_Lc_p_OWNPV_ZERR;   //!
   TBranch        *b_Lc_p_OWNPV_CHI2;   //!
   TBranch        *b_Lc_p_OWNPV_NDOF;   //!
   TBranch        *b_Lc_p_OWNPV_COV_;   //!
   TBranch        *b_Lc_p_IP_OWNPV;   //!
   TBranch        *b_Lc_p_IPCHI2_OWNPV;   //!
   TBranch        *b_Lc_p_ORIVX_X;   //!
   TBranch        *b_Lc_p_ORIVX_Y;   //!
   TBranch        *b_Lc_p_ORIVX_Z;   //!
   TBranch        *b_Lc_p_ORIVX_XERR;   //!
   TBranch        *b_Lc_p_ORIVX_YERR;   //!
   TBranch        *b_Lc_p_ORIVX_ZERR;   //!
   TBranch        *b_Lc_p_ORIVX_CHI2;   //!
   TBranch        *b_Lc_p_ORIVX_NDOF;   //!
   TBranch        *b_Lc_p_ORIVX_COV_;   //!
   TBranch        *b_Lc_p_P;   //!
   TBranch        *b_Lc_p_PT;   //!
   TBranch        *b_Lc_p_PE;   //!
   TBranch        *b_Lc_p_PX;   //!
   TBranch        *b_Lc_p_PY;   //!
   TBranch        *b_Lc_p_PZ;   //!
   TBranch        *b_Lc_p_M;   //!
   TBranch        *b_Lc_p_TRUEID;   //!
   TBranch        *b_Lc_p_MC_MOTHER_ID;   //!
   TBranch        *b_Lc_p_MC_MOTHER_KEY;   //!
   TBranch        *b_Lc_p_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Lc_p_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Lc_p_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Lc_p_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Lc_p_TRUEP_E;   //!
   TBranch        *b_Lc_p_TRUEP_X;   //!
   TBranch        *b_Lc_p_TRUEP_Y;   //!
   TBranch        *b_Lc_p_TRUEP_Z;   //!
   TBranch        *b_Lc_p_TRUEPT;   //!
   TBranch        *b_Lc_p_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Lc_p_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Lc_p_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Lc_p_TRUEENDVERTEX_X;   //!
   TBranch        *b_Lc_p_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Lc_p_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Lc_p_TRUEISSTABLE;   //!
   TBranch        *b_Lc_p_TRUETAU;   //!
   TBranch        *b_Lc_p_ID;   //!
   TBranch        *b_Lc_p_PIDe;   //!
   TBranch        *b_Lc_p_PIDmu;   //!
   TBranch        *b_Lc_p_PIDK;   //!
   TBranch        *b_Lc_p_PIDp;   //!
   TBranch        *b_Lc_p_PIDd;   //!
   TBranch        *b_Lc_p_ProbNNe;   //!
   TBranch        *b_Lc_p_ProbNNk;   //!
   TBranch        *b_Lc_p_ProbNNp;   //!
   TBranch        *b_Lc_p_ProbNNpi;   //!
   TBranch        *b_Lc_p_ProbNNmu;   //!
   TBranch        *b_Lc_p_ProbNNd;   //!
   TBranch        *b_Lc_p_ProbNNghost;   //!
   TBranch        *b_Lc_p_hasMuon;   //!
   TBranch        *b_Lc_p_isMuon;   //!
   TBranch        *b_Lc_p_hasRich;   //!
   TBranch        *b_Lc_p_UsedRichAerogel;   //!
   TBranch        *b_Lc_p_UsedRich1Gas;   //!
   TBranch        *b_Lc_p_UsedRich2Gas;   //!
   TBranch        *b_Lc_p_RichAboveElThres;   //!
   TBranch        *b_Lc_p_RichAboveMuThres;   //!
   TBranch        *b_Lc_p_RichAbovePiThres;   //!
   TBranch        *b_Lc_p_RichAboveKaThres;   //!
   TBranch        *b_Lc_p_RichAbovePrThres;   //!
   TBranch        *b_Lc_p_hasCalo;   //!
   TBranch        *b_Lc_p_TRACK_Type;   //!
   TBranch        *b_Lc_p_TRACK_Key;   //!
   TBranch        *b_Lc_p_TRACK_CHI2NDOF;   //!
   TBranch        *b_Lc_p_TRACK_PCHI2;   //!
   TBranch        *b_Lc_p_TRACK_MatchCHI2;   //!
   TBranch        *b_Lc_p_TRACK_GhostProb;   //!
   TBranch        *b_Lc_p_TRACK_CloneDist;   //!
   TBranch        *b_Lc_p_TRACK_Likelihood;   //!
   TBranch        *b_Lc_Km_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_Lc_Km_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_Lc_Km_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_Lc_Km_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_Lc_Km_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_Lc_Km_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_Lc_Km_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_Lc_Km_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_Lc_Km_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_Lc_Km_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_Lc_Km_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_Lc_Km_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_Lc_Km_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_Lc_Km_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_Lc_Km_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_Lc_Km_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_Lc_Km_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_Lc_Km_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_Lc_Km_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_Lc_Km_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_Lc_Km_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_Lc_Km_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_Lc_Km_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_Lc_Km_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_Lc_Km_OWNPV_X;   //!
   TBranch        *b_Lc_Km_OWNPV_Y;   //!
   TBranch        *b_Lc_Km_OWNPV_Z;   //!
   TBranch        *b_Lc_Km_OWNPV_XERR;   //!
   TBranch        *b_Lc_Km_OWNPV_YERR;   //!
   TBranch        *b_Lc_Km_OWNPV_ZERR;   //!
   TBranch        *b_Lc_Km_OWNPV_CHI2;   //!
   TBranch        *b_Lc_Km_OWNPV_NDOF;   //!
   TBranch        *b_Lc_Km_OWNPV_COV_;   //!
   TBranch        *b_Lc_Km_IP_OWNPV;   //!
   TBranch        *b_Lc_Km_IPCHI2_OWNPV;   //!
   TBranch        *b_Lc_Km_ORIVX_X;   //!
   TBranch        *b_Lc_Km_ORIVX_Y;   //!
   TBranch        *b_Lc_Km_ORIVX_Z;   //!
   TBranch        *b_Lc_Km_ORIVX_XERR;   //!
   TBranch        *b_Lc_Km_ORIVX_YERR;   //!
   TBranch        *b_Lc_Km_ORIVX_ZERR;   //!
   TBranch        *b_Lc_Km_ORIVX_CHI2;   //!
   TBranch        *b_Lc_Km_ORIVX_NDOF;   //!
   TBranch        *b_Lc_Km_ORIVX_COV_;   //!
   TBranch        *b_Lc_Km_P;   //!
   TBranch        *b_Lc_Km_PT;   //!
   TBranch        *b_Lc_Km_PE;   //!
   TBranch        *b_Lc_Km_PX;   //!
   TBranch        *b_Lc_Km_PY;   //!
   TBranch        *b_Lc_Km_PZ;   //!
   TBranch        *b_Lc_Km_M;   //!
   TBranch        *b_Lc_Km_TRUEID;   //!
   TBranch        *b_Lc_Km_MC_MOTHER_ID;   //!
   TBranch        *b_Lc_Km_MC_MOTHER_KEY;   //!
   TBranch        *b_Lc_Km_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Lc_Km_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Lc_Km_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Lc_Km_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Lc_Km_TRUEP_E;   //!
   TBranch        *b_Lc_Km_TRUEP_X;   //!
   TBranch        *b_Lc_Km_TRUEP_Y;   //!
   TBranch        *b_Lc_Km_TRUEP_Z;   //!
   TBranch        *b_Lc_Km_TRUEPT;   //!
   TBranch        *b_Lc_Km_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Lc_Km_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Lc_Km_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Lc_Km_TRUEENDVERTEX_X;   //!
   TBranch        *b_Lc_Km_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Lc_Km_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Lc_Km_TRUEISSTABLE;   //!
   TBranch        *b_Lc_Km_TRUETAU;   //!
   TBranch        *b_Lc_Km_ID;   //!
   TBranch        *b_Lc_Km_PIDe;   //!
   TBranch        *b_Lc_Km_PIDmu;   //!
   TBranch        *b_Lc_Km_PIDK;   //!
   TBranch        *b_Lc_Km_PIDp;   //!
   TBranch        *b_Lc_Km_PIDd;   //!
   TBranch        *b_Lc_Km_ProbNNe;   //!
   TBranch        *b_Lc_Km_ProbNNk;   //!
   TBranch        *b_Lc_Km_ProbNNp;   //!
   TBranch        *b_Lc_Km_ProbNNpi;   //!
   TBranch        *b_Lc_Km_ProbNNmu;   //!
   TBranch        *b_Lc_Km_ProbNNd;   //!
   TBranch        *b_Lc_Km_ProbNNghost;   //!
   TBranch        *b_Lc_Km_hasMuon;   //!
   TBranch        *b_Lc_Km_isMuon;   //!
   TBranch        *b_Lc_Km_hasRich;   //!
   TBranch        *b_Lc_Km_UsedRichAerogel;   //!
   TBranch        *b_Lc_Km_UsedRich1Gas;   //!
   TBranch        *b_Lc_Km_UsedRich2Gas;   //!
   TBranch        *b_Lc_Km_RichAboveElThres;   //!
   TBranch        *b_Lc_Km_RichAboveMuThres;   //!
   TBranch        *b_Lc_Km_RichAbovePiThres;   //!
   TBranch        *b_Lc_Km_RichAboveKaThres;   //!
   TBranch        *b_Lc_Km_RichAbovePrThres;   //!
   TBranch        *b_Lc_Km_hasCalo;   //!
   TBranch        *b_Lc_Km_TRACK_Type;   //!
   TBranch        *b_Lc_Km_TRACK_Key;   //!
   TBranch        *b_Lc_Km_TRACK_CHI2NDOF;   //!
   TBranch        *b_Lc_Km_TRACK_PCHI2;   //!
   TBranch        *b_Lc_Km_TRACK_MatchCHI2;   //!
   TBranch        *b_Lc_Km_TRACK_GhostProb;   //!
   TBranch        *b_Lc_Km_TRACK_CloneDist;   //!
   TBranch        *b_Lc_Km_TRACK_Likelihood;   //!
   TBranch        *b_Lc_pip_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_Lc_pip_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_Lc_pip_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_Lc_pip_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_Lc_pip_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_Lc_pip_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_Lc_pip_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_Lc_pip_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_Lc_pip_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_Lc_pip_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_Lc_pip_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_Lc_pip_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_Lc_pip_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_Lc_pip_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_Lc_pip_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_Lc_pip_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_Lc_pip_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_Lc_pip_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_Lc_pip_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_Lc_pip_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_Lc_pip_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_Lc_pip_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_Lc_pip_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_Lc_pip_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_Lc_pip_OWNPV_X;   //!
   TBranch        *b_Lc_pip_OWNPV_Y;   //!
   TBranch        *b_Lc_pip_OWNPV_Z;   //!
   TBranch        *b_Lc_pip_OWNPV_XERR;   //!
   TBranch        *b_Lc_pip_OWNPV_YERR;   //!
   TBranch        *b_Lc_pip_OWNPV_ZERR;   //!
   TBranch        *b_Lc_pip_OWNPV_CHI2;   //!
   TBranch        *b_Lc_pip_OWNPV_NDOF;   //!
   TBranch        *b_Lc_pip_OWNPV_COV_;   //!
   TBranch        *b_Lc_pip_IP_OWNPV;   //!
   TBranch        *b_Lc_pip_IPCHI2_OWNPV;   //!
   TBranch        *b_Lc_pip_ORIVX_X;   //!
   TBranch        *b_Lc_pip_ORIVX_Y;   //!
   TBranch        *b_Lc_pip_ORIVX_Z;   //!
   TBranch        *b_Lc_pip_ORIVX_XERR;   //!
   TBranch        *b_Lc_pip_ORIVX_YERR;   //!
   TBranch        *b_Lc_pip_ORIVX_ZERR;   //!
   TBranch        *b_Lc_pip_ORIVX_CHI2;   //!
   TBranch        *b_Lc_pip_ORIVX_NDOF;   //!
   TBranch        *b_Lc_pip_ORIVX_COV_;   //!
   TBranch        *b_Lc_pip_P;   //!
   TBranch        *b_Lc_pip_PT;   //!
   TBranch        *b_Lc_pip_PE;   //!
   TBranch        *b_Lc_pip_PX;   //!
   TBranch        *b_Lc_pip_PY;   //!
   TBranch        *b_Lc_pip_PZ;   //!
   TBranch        *b_Lc_pip_M;   //!
   TBranch        *b_Lc_pip_TRUEID;   //!
   TBranch        *b_Lc_pip_MC_MOTHER_ID;   //!
   TBranch        *b_Lc_pip_MC_MOTHER_KEY;   //!
   TBranch        *b_Lc_pip_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Lc_pip_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Lc_pip_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Lc_pip_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Lc_pip_TRUEP_E;   //!
   TBranch        *b_Lc_pip_TRUEP_X;   //!
   TBranch        *b_Lc_pip_TRUEP_Y;   //!
   TBranch        *b_Lc_pip_TRUEP_Z;   //!
   TBranch        *b_Lc_pip_TRUEPT;   //!
   TBranch        *b_Lc_pip_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Lc_pip_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Lc_pip_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Lc_pip_TRUEENDVERTEX_X;   //!
   TBranch        *b_Lc_pip_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Lc_pip_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Lc_pip_TRUEISSTABLE;   //!
   TBranch        *b_Lc_pip_TRUETAU;   //!
   TBranch        *b_Lc_pip_ID;   //!
   TBranch        *b_Lc_pip_PIDe;   //!
   TBranch        *b_Lc_pip_PIDmu;   //!
   TBranch        *b_Lc_pip_PIDK;   //!
   TBranch        *b_Lc_pip_PIDp;   //!
   TBranch        *b_Lc_pip_PIDd;   //!
   TBranch        *b_Lc_pip_ProbNNe;   //!
   TBranch        *b_Lc_pip_ProbNNk;   //!
   TBranch        *b_Lc_pip_ProbNNp;   //!
   TBranch        *b_Lc_pip_ProbNNpi;   //!
   TBranch        *b_Lc_pip_ProbNNmu;   //!
   TBranch        *b_Lc_pip_ProbNNd;   //!
   TBranch        *b_Lc_pip_ProbNNghost;   //!
   TBranch        *b_Lc_pip_hasMuon;   //!
   TBranch        *b_Lc_pip_isMuon;   //!
   TBranch        *b_Lc_pip_hasRich;   //!
   TBranch        *b_Lc_pip_UsedRichAerogel;   //!
   TBranch        *b_Lc_pip_UsedRich1Gas;   //!
   TBranch        *b_Lc_pip_UsedRich2Gas;   //!
   TBranch        *b_Lc_pip_RichAboveElThres;   //!
   TBranch        *b_Lc_pip_RichAboveMuThres;   //!
   TBranch        *b_Lc_pip_RichAbovePiThres;   //!
   TBranch        *b_Lc_pip_RichAboveKaThres;   //!
   TBranch        *b_Lc_pip_RichAbovePrThres;   //!
   TBranch        *b_Lc_pip_hasCalo;   //!
   TBranch        *b_Lc_pip_TRACK_Type;   //!
   TBranch        *b_Lc_pip_TRACK_Key;   //!
   TBranch        *b_Lc_pip_TRACK_CHI2NDOF;   //!
   TBranch        *b_Lc_pip_TRACK_PCHI2;   //!
   TBranch        *b_Lc_pip_TRACK_MatchCHI2;   //!
   TBranch        *b_Lc_pip_TRACK_GhostProb;   //!
   TBranch        *b_Lc_pip_TRACK_CloneDist;   //!
   TBranch        *b_Lc_pip_TRACK_Likelihood;   //!
   TBranch        *b_pibach_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_pibach_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_pibach_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_pibach_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_pibach_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_pibach_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_pibach_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_pibach_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_pibach_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_pibach_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_pibach_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_pibach_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_pibach_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_pibach_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_pibach_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_pibach_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_pibach_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_pibach_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_pibach_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_pibach_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_pibach_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_pibach_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_pibach_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_pibach_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_pibach_OWNPV_X;   //!
   TBranch        *b_pibach_OWNPV_Y;   //!
   TBranch        *b_pibach_OWNPV_Z;   //!
   TBranch        *b_pibach_OWNPV_XERR;   //!
   TBranch        *b_pibach_OWNPV_YERR;   //!
   TBranch        *b_pibach_OWNPV_ZERR;   //!
   TBranch        *b_pibach_OWNPV_CHI2;   //!
   TBranch        *b_pibach_OWNPV_NDOF;   //!
   TBranch        *b_pibach_OWNPV_COV_;   //!
   TBranch        *b_pibach_IP_OWNPV;   //!
   TBranch        *b_pibach_IPCHI2_OWNPV;   //!
   TBranch        *b_pibach_ORIVX_X;   //!
   TBranch        *b_pibach_ORIVX_Y;   //!
   TBranch        *b_pibach_ORIVX_Z;   //!
   TBranch        *b_pibach_ORIVX_XERR;   //!
   TBranch        *b_pibach_ORIVX_YERR;   //!
   TBranch        *b_pibach_ORIVX_ZERR;   //!
   TBranch        *b_pibach_ORIVX_CHI2;   //!
   TBranch        *b_pibach_ORIVX_NDOF;   //!
   TBranch        *b_pibach_ORIVX_COV_;   //!
   TBranch        *b_pibach_P;   //!
   TBranch        *b_pibach_PT;   //!
   TBranch        *b_pibach_PE;   //!
   TBranch        *b_pibach_PX;   //!
   TBranch        *b_pibach_PY;   //!
   TBranch        *b_pibach_PZ;   //!
   TBranch        *b_pibach_M;   //!
   TBranch        *b_pibach_TRUEID;   //!
   TBranch        *b_pibach_MC_MOTHER_ID;   //!
   TBranch        *b_pibach_MC_MOTHER_KEY;   //!
   TBranch        *b_pibach_MC_GD_MOTHER_ID;   //!
   TBranch        *b_pibach_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_pibach_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_pibach_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_pibach_TRUEP_E;   //!
   TBranch        *b_pibach_TRUEP_X;   //!
   TBranch        *b_pibach_TRUEP_Y;   //!
   TBranch        *b_pibach_TRUEP_Z;   //!
   TBranch        *b_pibach_TRUEPT;   //!
   TBranch        *b_pibach_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_pibach_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_pibach_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_pibach_TRUEENDVERTEX_X;   //!
   TBranch        *b_pibach_TRUEENDVERTEX_Y;   //!
   TBranch        *b_pibach_TRUEENDVERTEX_Z;   //!
   TBranch        *b_pibach_TRUEISSTABLE;   //!
   TBranch        *b_pibach_TRUETAU;   //!
   TBranch        *b_pibach_ID;   //!
   TBranch        *b_pibach_PIDe;   //!
   TBranch        *b_pibach_PIDmu;   //!
   TBranch        *b_pibach_PIDK;   //!
   TBranch        *b_pibach_PIDp;   //!
   TBranch        *b_pibach_PIDd;   //!
   TBranch        *b_pibach_ProbNNe;   //!
   TBranch        *b_pibach_ProbNNk;   //!
   TBranch        *b_pibach_ProbNNp;   //!
   TBranch        *b_pibach_ProbNNpi;   //!
   TBranch        *b_pibach_ProbNNmu;   //!
   TBranch        *b_pibach_ProbNNd;   //!
   TBranch        *b_pibach_ProbNNghost;   //!
   TBranch        *b_pibach_hasMuon;   //!
   TBranch        *b_pibach_isMuon;   //!
   TBranch        *b_pibach_hasRich;   //!
   TBranch        *b_pibach_UsedRichAerogel;   //!
   TBranch        *b_pibach_UsedRich1Gas;   //!
   TBranch        *b_pibach_UsedRich2Gas;   //!
   TBranch        *b_pibach_RichAboveElThres;   //!
   TBranch        *b_pibach_RichAboveMuThres;   //!
   TBranch        *b_pibach_RichAbovePiThres;   //!
   TBranch        *b_pibach_RichAboveKaThres;   //!
   TBranch        *b_pibach_RichAbovePrThres;   //!
   TBranch        *b_pibach_hasCalo;   //!
   TBranch        *b_pibach_TRACK_Type;   //!
   TBranch        *b_pibach_TRACK_Key;   //!
   TBranch        *b_pibach_TRACK_CHI2NDOF;   //!
   TBranch        *b_pibach_TRACK_PCHI2;   //!
   TBranch        *b_pibach_TRACK_MatchCHI2;   //!
   TBranch        *b_pibach_TRACK_GhostProb;   //!
   TBranch        *b_pibach_TRACK_CloneDist;   //!
   TBranch        *b_pibach_TRACK_Likelihood;   //!
   TBranch        *b_Kbach_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_Kbach_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_Kbach_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_Kbach_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_Kbach_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_Kbach_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_Kbach_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_Kbach_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_Kbach_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_Kbach_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_Kbach_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_Kbach_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_Kbach_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_Kbach_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_Kbach_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_Kbach_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_Kbach_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_Kbach_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_Kbach_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_Kbach_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_Kbach_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_Kbach_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_Kbach_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_Kbach_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_Kbach_OWNPV_X;   //!
   TBranch        *b_Kbach_OWNPV_Y;   //!
   TBranch        *b_Kbach_OWNPV_Z;   //!
   TBranch        *b_Kbach_OWNPV_XERR;   //!
   TBranch        *b_Kbach_OWNPV_YERR;   //!
   TBranch        *b_Kbach_OWNPV_ZERR;   //!
   TBranch        *b_Kbach_OWNPV_CHI2;   //!
   TBranch        *b_Kbach_OWNPV_NDOF;   //!
   TBranch        *b_Kbach_OWNPV_COV_;   //!
   TBranch        *b_Kbach_IP_OWNPV;   //!
   TBranch        *b_Kbach_IPCHI2_OWNPV;   //!
   TBranch        *b_Kbach_ORIVX_X;   //!
   TBranch        *b_Kbach_ORIVX_Y;   //!
   TBranch        *b_Kbach_ORIVX_Z;   //!
   TBranch        *b_Kbach_ORIVX_XERR;   //!
   TBranch        *b_Kbach_ORIVX_YERR;   //!
   TBranch        *b_Kbach_ORIVX_ZERR;   //!
   TBranch        *b_Kbach_ORIVX_CHI2;   //!
   TBranch        *b_Kbach_ORIVX_NDOF;   //!
   TBranch        *b_Kbach_ORIVX_COV_;   //!
   TBranch        *b_Kbach_P;   //!
   TBranch        *b_Kbach_PT;   //!
   TBranch        *b_Kbach_PE;   //!
   TBranch        *b_Kbach_PX;   //!
   TBranch        *b_Kbach_PY;   //!
   TBranch        *b_Kbach_PZ;   //!
   TBranch        *b_Kbach_M;   //!
   TBranch        *b_Kbach_TRUEID;   //!
   TBranch        *b_Kbach_MC_MOTHER_ID;   //!
   TBranch        *b_Kbach_MC_MOTHER_KEY;   //!
   TBranch        *b_Kbach_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Kbach_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Kbach_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Kbach_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Kbach_TRUEP_E;   //!
   TBranch        *b_Kbach_TRUEP_X;   //!
   TBranch        *b_Kbach_TRUEP_Y;   //!
   TBranch        *b_Kbach_TRUEP_Z;   //!
   TBranch        *b_Kbach_TRUEPT;   //!
   TBranch        *b_Kbach_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Kbach_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Kbach_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Kbach_TRUEENDVERTEX_X;   //!
   TBranch        *b_Kbach_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Kbach_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Kbach_TRUEISSTABLE;   //!
   TBranch        *b_Kbach_TRUETAU;   //!
   TBranch        *b_Kbach_ID;   //!
   TBranch        *b_Kbach_PIDe;   //!
   TBranch        *b_Kbach_PIDmu;   //!
   TBranch        *b_Kbach_PIDK;   //!
   TBranch        *b_Kbach_PIDp;   //!
   TBranch        *b_Kbach_PIDd;   //!
   TBranch        *b_Kbach_ProbNNe;   //!
   TBranch        *b_Kbach_ProbNNk;   //!
   TBranch        *b_Kbach_ProbNNp;   //!
   TBranch        *b_Kbach_ProbNNpi;   //!
   TBranch        *b_Kbach_ProbNNmu;   //!
   TBranch        *b_Kbach_ProbNNd;   //!
   TBranch        *b_Kbach_ProbNNghost;   //!
   TBranch        *b_Kbach_hasMuon;   //!
   TBranch        *b_Kbach_isMuon;   //!
   TBranch        *b_Kbach_hasRich;   //!
   TBranch        *b_Kbach_UsedRichAerogel;   //!
   TBranch        *b_Kbach_UsedRich1Gas;   //!
   TBranch        *b_Kbach_UsedRich2Gas;   //!
   TBranch        *b_Kbach_RichAboveElThres;   //!
   TBranch        *b_Kbach_RichAboveMuThres;   //!
   TBranch        *b_Kbach_RichAbovePiThres;   //!
   TBranch        *b_Kbach_RichAboveKaThres;   //!
   TBranch        *b_Kbach_RichAbovePrThres;   //!
   TBranch        *b_Kbach_hasCalo;   //!
   TBranch        *b_Kbach_TRACK_Type;   //!
   TBranch        *b_Kbach_TRACK_Key;   //!
   TBranch        *b_Kbach_TRACK_CHI2NDOF;   //!
   TBranch        *b_Kbach_TRACK_PCHI2;   //!
   TBranch        *b_Kbach_TRACK_MatchCHI2;   //!
   TBranch        *b_Kbach_TRACK_GhostProb;   //!
   TBranch        *b_Kbach_TRACK_CloneDist;   //!
   TBranch        *b_Kbach_TRACK_Likelihood;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLT1TCK;   //!
   TBranch        *b_HLT2TCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Polarity;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVX;   //!
   TBranch        *b_PVY;   //!
   TBranch        *b_PVZ;   //!
   TBranch        *b_PVXERR;   //!
   TBranch        *b_PVYERR;   //!
   TBranch        *b_PVZERR;   //!
   TBranch        *b_PVCHI2;   //!
   TBranch        *b_PVNDOF;   //!
   TBranch        *b_PVNTRACKS;   //!
   TBranch        *b_bdtg;   //!

   DecayTree(TTree *tree=0);
   virtual ~DecayTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef DecayTree_cxx
DecayTree::DecayTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/loren/MSc/datasets/MC_2016_LcMVA.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/home/loren/MSc/datasets/MC_2016_LcMVA.root");
      }
      f->GetObject("DecayTree",tree);

   }
   Init(tree);
}

DecayTree::~DecayTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DecayTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DecayTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void DecayTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Xicst_ENDVERTEX_X", &Xicst_ENDVERTEX_X, &b_Xicst_ENDVERTEX_X);
   fChain->SetBranchAddress("Xicst_ENDVERTEX_Y", &Xicst_ENDVERTEX_Y, &b_Xicst_ENDVERTEX_Y);
   fChain->SetBranchAddress("Xicst_ENDVERTEX_Z", &Xicst_ENDVERTEX_Z, &b_Xicst_ENDVERTEX_Z);
   fChain->SetBranchAddress("Xicst_ENDVERTEX_XERR", &Xicst_ENDVERTEX_XERR, &b_Xicst_ENDVERTEX_XERR);
   fChain->SetBranchAddress("Xicst_ENDVERTEX_YERR", &Xicst_ENDVERTEX_YERR, &b_Xicst_ENDVERTEX_YERR);
   fChain->SetBranchAddress("Xicst_ENDVERTEX_ZERR", &Xicst_ENDVERTEX_ZERR, &b_Xicst_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("Xicst_ENDVERTEX_CHI2", &Xicst_ENDVERTEX_CHI2, &b_Xicst_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("Xicst_ENDVERTEX_NDOF", &Xicst_ENDVERTEX_NDOF, &b_Xicst_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("Xicst_ENDVERTEX_COV_", Xicst_ENDVERTEX_COV_, &b_Xicst_ENDVERTEX_COV_);
   fChain->SetBranchAddress("Xicst_OWNPV_X", &Xicst_OWNPV_X, &b_Xicst_OWNPV_X);
   fChain->SetBranchAddress("Xicst_OWNPV_Y", &Xicst_OWNPV_Y, &b_Xicst_OWNPV_Y);
   fChain->SetBranchAddress("Xicst_OWNPV_Z", &Xicst_OWNPV_Z, &b_Xicst_OWNPV_Z);
   fChain->SetBranchAddress("Xicst_OWNPV_XERR", &Xicst_OWNPV_XERR, &b_Xicst_OWNPV_XERR);
   fChain->SetBranchAddress("Xicst_OWNPV_YERR", &Xicst_OWNPV_YERR, &b_Xicst_OWNPV_YERR);
   fChain->SetBranchAddress("Xicst_OWNPV_ZERR", &Xicst_OWNPV_ZERR, &b_Xicst_OWNPV_ZERR);
   fChain->SetBranchAddress("Xicst_OWNPV_CHI2", &Xicst_OWNPV_CHI2, &b_Xicst_OWNPV_CHI2);
   fChain->SetBranchAddress("Xicst_OWNPV_NDOF", &Xicst_OWNPV_NDOF, &b_Xicst_OWNPV_NDOF);
   fChain->SetBranchAddress("Xicst_OWNPV_COV_", Xicst_OWNPV_COV_, &b_Xicst_OWNPV_COV_);
   fChain->SetBranchAddress("Xicst_IP_OWNPV", &Xicst_IP_OWNPV, &b_Xicst_IP_OWNPV);
   fChain->SetBranchAddress("Xicst_IPCHI2_OWNPV", &Xicst_IPCHI2_OWNPV, &b_Xicst_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Xicst_FD_OWNPV", &Xicst_FD_OWNPV, &b_Xicst_FD_OWNPV);
   fChain->SetBranchAddress("Xicst_FDCHI2_OWNPV", &Xicst_FDCHI2_OWNPV, &b_Xicst_FDCHI2_OWNPV);
   fChain->SetBranchAddress("Xicst_DIRA_OWNPV", &Xicst_DIRA_OWNPV, &b_Xicst_DIRA_OWNPV);
   fChain->SetBranchAddress("Xicst_P", &Xicst_P, &b_Xicst_P);
   fChain->SetBranchAddress("Xicst_PT", &Xicst_PT, &b_Xicst_PT);
   fChain->SetBranchAddress("Xicst_PE", &Xicst_PE, &b_Xicst_PE);
   fChain->SetBranchAddress("Xicst_PX", &Xicst_PX, &b_Xicst_PX);
   fChain->SetBranchAddress("Xicst_PY", &Xicst_PY, &b_Xicst_PY);
   fChain->SetBranchAddress("Xicst_PZ", &Xicst_PZ, &b_Xicst_PZ);
   fChain->SetBranchAddress("Xicst_MM", &Xicst_MM, &b_Xicst_MM);
   fChain->SetBranchAddress("Xicst_MMERR", &Xicst_MMERR, &b_Xicst_MMERR);
   fChain->SetBranchAddress("Xicst_M", &Xicst_M, &b_Xicst_M);
   fChain->SetBranchAddress("Xicst_BKGCAT", &Xicst_BKGCAT, &b_Xicst_BKGCAT);
   fChain->SetBranchAddress("Xicst_TRUEID", &Xicst_TRUEID, &b_Xicst_TRUEID);
   fChain->SetBranchAddress("Xicst_MC_MOTHER_ID", &Xicst_MC_MOTHER_ID, &b_Xicst_MC_MOTHER_ID);
   fChain->SetBranchAddress("Xicst_MC_MOTHER_KEY", &Xicst_MC_MOTHER_KEY, &b_Xicst_MC_MOTHER_KEY);
   fChain->SetBranchAddress("Xicst_MC_GD_MOTHER_ID", &Xicst_MC_GD_MOTHER_ID, &b_Xicst_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("Xicst_MC_GD_MOTHER_KEY", &Xicst_MC_GD_MOTHER_KEY, &b_Xicst_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Xicst_MC_GD_GD_MOTHER_ID", &Xicst_MC_GD_GD_MOTHER_ID, &b_Xicst_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("Xicst_MC_GD_GD_MOTHER_KEY", &Xicst_MC_GD_GD_MOTHER_KEY, &b_Xicst_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Xicst_TRUEP_E", &Xicst_TRUEP_E, &b_Xicst_TRUEP_E);
   fChain->SetBranchAddress("Xicst_TRUEP_X", &Xicst_TRUEP_X, &b_Xicst_TRUEP_X);
   fChain->SetBranchAddress("Xicst_TRUEP_Y", &Xicst_TRUEP_Y, &b_Xicst_TRUEP_Y);
   fChain->SetBranchAddress("Xicst_TRUEP_Z", &Xicst_TRUEP_Z, &b_Xicst_TRUEP_Z);
   fChain->SetBranchAddress("Xicst_TRUEPT", &Xicst_TRUEPT, &b_Xicst_TRUEPT);
   fChain->SetBranchAddress("Xicst_TRUEORIGINVERTEX_X", &Xicst_TRUEORIGINVERTEX_X, &b_Xicst_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("Xicst_TRUEORIGINVERTEX_Y", &Xicst_TRUEORIGINVERTEX_Y, &b_Xicst_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("Xicst_TRUEORIGINVERTEX_Z", &Xicst_TRUEORIGINVERTEX_Z, &b_Xicst_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("Xicst_TRUEENDVERTEX_X", &Xicst_TRUEENDVERTEX_X, &b_Xicst_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("Xicst_TRUEENDVERTEX_Y", &Xicst_TRUEENDVERTEX_Y, &b_Xicst_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("Xicst_TRUEENDVERTEX_Z", &Xicst_TRUEENDVERTEX_Z, &b_Xicst_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("Xicst_TRUEISSTABLE", &Xicst_TRUEISSTABLE, &b_Xicst_TRUEISSTABLE);
   fChain->SetBranchAddress("Xicst_TRUETAU", &Xicst_TRUETAU, &b_Xicst_TRUETAU);
   fChain->SetBranchAddress("Xicst_ID", &Xicst_ID, &b_Xicst_ID);
   fChain->SetBranchAddress("Xicst_DTF_LcPDG_DTF_CHI2", &Xicst_DTF_LcPDG_DTF_CHI2, &b_Xicst_DTF_LcPDG_DTF_CHI2);
   fChain->SetBranchAddress("Xicst_DTF_LcPDG_DTF_NDOF", &Xicst_DTF_LcPDG_DTF_NDOF, &b_Xicst_DTF_LcPDG_DTF_NDOF);
   fChain->SetBranchAddress("Xicst_DTF_LcPDG_Lc_M", &Xicst_DTF_LcPDG_Lc_M, &b_Xicst_DTF_LcPDG_Lc_M);
   fChain->SetBranchAddress("Xicst_DTF_LcPDG_Lc_PT", &Xicst_DTF_LcPDG_Lc_PT, &b_Xicst_DTF_LcPDG_Lc_PT);
   fChain->SetBranchAddress("Xicst_DTF_LcPDG_M", &Xicst_DTF_LcPDG_M, &b_Xicst_DTF_LcPDG_M);
   fChain->SetBranchAddress("Xicst_DTF_LcPDG_M12", &Xicst_DTF_LcPDG_M12, &b_Xicst_DTF_LcPDG_M12);
   fChain->SetBranchAddress("Xicst_DTF_LcPDG_PT", &Xicst_DTF_LcPDG_PT, &b_Xicst_DTF_LcPDG_PT);
   fChain->SetBranchAddress("Xicst_DTF_PV_DTF_CHI2", &Xicst_DTF_PV_DTF_CHI2, &b_Xicst_DTF_PV_DTF_CHI2);
   fChain->SetBranchAddress("Xicst_DTF_PV_DTF_NDOF", &Xicst_DTF_PV_DTF_NDOF, &b_Xicst_DTF_PV_DTF_NDOF);
   fChain->SetBranchAddress("Xicst_DTF_PV_Lc_M", &Xicst_DTF_PV_Lc_M, &b_Xicst_DTF_PV_Lc_M);
   fChain->SetBranchAddress("Xicst_DTF_PV_Lc_PT", &Xicst_DTF_PV_Lc_PT, &b_Xicst_DTF_PV_Lc_PT);
   fChain->SetBranchAddress("Xicst_DTF_PV_M", &Xicst_DTF_PV_M, &b_Xicst_DTF_PV_M);
   fChain->SetBranchAddress("Xicst_DTF_PV_M12", &Xicst_DTF_PV_M12, &b_Xicst_DTF_PV_M12);
   fChain->SetBranchAddress("Xicst_DTF_PV_PT", &Xicst_DTF_PV_PT, &b_Xicst_DTF_PV_PT);
   fChain->SetBranchAddress("Xicst_DTF_PV_LcPDG_DTF_CHI2", &Xicst_DTF_PV_LcPDG_DTF_CHI2, &b_Xicst_DTF_PV_LcPDG_DTF_CHI2);
   fChain->SetBranchAddress("Xicst_DTF_PV_LcPDG_DTF_NDOF", &Xicst_DTF_PV_LcPDG_DTF_NDOF, &b_Xicst_DTF_PV_LcPDG_DTF_NDOF);
   fChain->SetBranchAddress("Xicst_DTF_PV_LcPDG_Lc_M", &Xicst_DTF_PV_LcPDG_Lc_M, &b_Xicst_DTF_PV_LcPDG_Lc_M);
   fChain->SetBranchAddress("Xicst_DTF_PV_LcPDG_Lc_PT", &Xicst_DTF_PV_LcPDG_Lc_PT, &b_Xicst_DTF_PV_LcPDG_Lc_PT);
   fChain->SetBranchAddress("Xicst_DTF_PV_LcPDG_M", &Xicst_DTF_PV_LcPDG_M, &b_Xicst_DTF_PV_LcPDG_M);
   fChain->SetBranchAddress("Xicst_DTF_PV_LcPDG_M12", &Xicst_DTF_PV_LcPDG_M12, &b_Xicst_DTF_PV_LcPDG_M12);
   fChain->SetBranchAddress("Xicst_DTF_PV_LcPDG_PT", &Xicst_DTF_PV_LcPDG_PT, &b_Xicst_DTF_PV_LcPDG_PT);
   fChain->SetBranchAddress("Xicst_BPVIPCHI2", &Xicst_BPVIPCHI2, &b_Xicst_BPVIPCHI2);
   fChain->SetBranchAddress("Xicst_BPVVDCHI2", &Xicst_BPVVDCHI2, &b_Xicst_BPVVDCHI2);
   fChain->SetBranchAddress("Xicst_DOCA12", &Xicst_DOCA12, &b_Xicst_DOCA12);
   fChain->SetBranchAddress("Xicst_DOCA13", &Xicst_DOCA13, &b_Xicst_DOCA13);
   fChain->SetBranchAddress("Xicst_DOCA23", &Xicst_DOCA23, &b_Xicst_DOCA23);
   fChain->SetBranchAddress("Xicst_DOCACHI2MAX", &Xicst_DOCACHI2MAX, &b_Xicst_DOCACHI2MAX);
   fChain->SetBranchAddress("Xicst_DOCAMAX", &Xicst_DOCAMAX, &b_Xicst_DOCAMAX);
   fChain->SetBranchAddress("Xicst_DOCAMIN", &Xicst_DOCAMIN, &b_Xicst_DOCAMIN);
   fChain->SetBranchAddress("Xicst_ETA", &Xicst_ETA, &b_Xicst_ETA);
   fChain->SetBranchAddress("Xicst_M12", &Xicst_M12, &b_Xicst_M12);
   fChain->SetBranchAddress("Xicst_M13", &Xicst_M13, &b_Xicst_M13);
   fChain->SetBranchAddress("Xicst_M23", &Xicst_M23, &b_Xicst_M23);
   fChain->SetBranchAddress("Xicst_SUM_PT", &Xicst_SUM_PT, &b_Xicst_SUM_PT);
   fChain->SetBranchAddress("Xicst_Y", &Xicst_Y, &b_Xicst_Y);
   fChain->SetBranchAddress("Lc_ENDVERTEX_X", &Lc_ENDVERTEX_X, &b_Lc_ENDVERTEX_X);
   fChain->SetBranchAddress("Lc_ENDVERTEX_Y", &Lc_ENDVERTEX_Y, &b_Lc_ENDVERTEX_Y);
   fChain->SetBranchAddress("Lc_ENDVERTEX_Z", &Lc_ENDVERTEX_Z, &b_Lc_ENDVERTEX_Z);
   fChain->SetBranchAddress("Lc_ENDVERTEX_XERR", &Lc_ENDVERTEX_XERR, &b_Lc_ENDVERTEX_XERR);
   fChain->SetBranchAddress("Lc_ENDVERTEX_YERR", &Lc_ENDVERTEX_YERR, &b_Lc_ENDVERTEX_YERR);
   fChain->SetBranchAddress("Lc_ENDVERTEX_ZERR", &Lc_ENDVERTEX_ZERR, &b_Lc_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("Lc_ENDVERTEX_CHI2", &Lc_ENDVERTEX_CHI2, &b_Lc_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("Lc_ENDVERTEX_NDOF", &Lc_ENDVERTEX_NDOF, &b_Lc_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("Lc_ENDVERTEX_COV_", Lc_ENDVERTEX_COV_, &b_Lc_ENDVERTEX_COV_);
   fChain->SetBranchAddress("Lc_OWNPV_X", &Lc_OWNPV_X, &b_Lc_OWNPV_X);
   fChain->SetBranchAddress("Lc_OWNPV_Y", &Lc_OWNPV_Y, &b_Lc_OWNPV_Y);
   fChain->SetBranchAddress("Lc_OWNPV_Z", &Lc_OWNPV_Z, &b_Lc_OWNPV_Z);
   fChain->SetBranchAddress("Lc_OWNPV_XERR", &Lc_OWNPV_XERR, &b_Lc_OWNPV_XERR);
   fChain->SetBranchAddress("Lc_OWNPV_YERR", &Lc_OWNPV_YERR, &b_Lc_OWNPV_YERR);
   fChain->SetBranchAddress("Lc_OWNPV_ZERR", &Lc_OWNPV_ZERR, &b_Lc_OWNPV_ZERR);
   fChain->SetBranchAddress("Lc_OWNPV_CHI2", &Lc_OWNPV_CHI2, &b_Lc_OWNPV_CHI2);
   fChain->SetBranchAddress("Lc_OWNPV_NDOF", &Lc_OWNPV_NDOF, &b_Lc_OWNPV_NDOF);
   fChain->SetBranchAddress("Lc_OWNPV_COV_", Lc_OWNPV_COV_, &b_Lc_OWNPV_COV_);
   fChain->SetBranchAddress("Lc_IP_OWNPV", &Lc_IP_OWNPV, &b_Lc_IP_OWNPV);
   fChain->SetBranchAddress("Lc_IPCHI2_OWNPV", &Lc_IPCHI2_OWNPV, &b_Lc_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Lc_FD_OWNPV", &Lc_FD_OWNPV, &b_Lc_FD_OWNPV);
   fChain->SetBranchAddress("Lc_FDCHI2_OWNPV", &Lc_FDCHI2_OWNPV, &b_Lc_FDCHI2_OWNPV);
   fChain->SetBranchAddress("Lc_DIRA_OWNPV", &Lc_DIRA_OWNPV, &b_Lc_DIRA_OWNPV);
   fChain->SetBranchAddress("Lc_ORIVX_X", &Lc_ORIVX_X, &b_Lc_ORIVX_X);
   fChain->SetBranchAddress("Lc_ORIVX_Y", &Lc_ORIVX_Y, &b_Lc_ORIVX_Y);
   fChain->SetBranchAddress("Lc_ORIVX_Z", &Lc_ORIVX_Z, &b_Lc_ORIVX_Z);
   fChain->SetBranchAddress("Lc_ORIVX_XERR", &Lc_ORIVX_XERR, &b_Lc_ORIVX_XERR);
   fChain->SetBranchAddress("Lc_ORIVX_YERR", &Lc_ORIVX_YERR, &b_Lc_ORIVX_YERR);
   fChain->SetBranchAddress("Lc_ORIVX_ZERR", &Lc_ORIVX_ZERR, &b_Lc_ORIVX_ZERR);
   fChain->SetBranchAddress("Lc_ORIVX_CHI2", &Lc_ORIVX_CHI2, &b_Lc_ORIVX_CHI2);
   fChain->SetBranchAddress("Lc_ORIVX_NDOF", &Lc_ORIVX_NDOF, &b_Lc_ORIVX_NDOF);
   fChain->SetBranchAddress("Lc_ORIVX_COV_", Lc_ORIVX_COV_, &b_Lc_ORIVX_COV_);
   fChain->SetBranchAddress("Lc_FD_ORIVX", &Lc_FD_ORIVX, &b_Lc_FD_ORIVX);
   fChain->SetBranchAddress("Lc_FDCHI2_ORIVX", &Lc_FDCHI2_ORIVX, &b_Lc_FDCHI2_ORIVX);
   fChain->SetBranchAddress("Lc_DIRA_ORIVX", &Lc_DIRA_ORIVX, &b_Lc_DIRA_ORIVX);
   fChain->SetBranchAddress("Lc_P", &Lc_P, &b_Lc_P);
   fChain->SetBranchAddress("Lc_PT", &Lc_PT, &b_Lc_PT);
   fChain->SetBranchAddress("Lc_PE", &Lc_PE, &b_Lc_PE);
   fChain->SetBranchAddress("Lc_PX", &Lc_PX, &b_Lc_PX);
   fChain->SetBranchAddress("Lc_PY", &Lc_PY, &b_Lc_PY);
   fChain->SetBranchAddress("Lc_PZ", &Lc_PZ, &b_Lc_PZ);
   fChain->SetBranchAddress("Lc_MM", &Lc_MM, &b_Lc_MM);
   fChain->SetBranchAddress("Lc_MMERR", &Lc_MMERR, &b_Lc_MMERR);
   fChain->SetBranchAddress("Lc_M", &Lc_M, &b_Lc_M);
   fChain->SetBranchAddress("Lc_BKGCAT", &Lc_BKGCAT, &b_Lc_BKGCAT);
   fChain->SetBranchAddress("Lc_TRUEID", &Lc_TRUEID, &b_Lc_TRUEID);
   fChain->SetBranchAddress("Lc_MC_MOTHER_ID", &Lc_MC_MOTHER_ID, &b_Lc_MC_MOTHER_ID);
   fChain->SetBranchAddress("Lc_MC_MOTHER_KEY", &Lc_MC_MOTHER_KEY, &b_Lc_MC_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_MC_GD_MOTHER_ID", &Lc_MC_GD_MOTHER_ID, &b_Lc_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("Lc_MC_GD_MOTHER_KEY", &Lc_MC_GD_MOTHER_KEY, &b_Lc_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_MC_GD_GD_MOTHER_ID", &Lc_MC_GD_GD_MOTHER_ID, &b_Lc_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("Lc_MC_GD_GD_MOTHER_KEY", &Lc_MC_GD_GD_MOTHER_KEY, &b_Lc_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_TRUEP_E", &Lc_TRUEP_E, &b_Lc_TRUEP_E);
   fChain->SetBranchAddress("Lc_TRUEP_X", &Lc_TRUEP_X, &b_Lc_TRUEP_X);
   fChain->SetBranchAddress("Lc_TRUEP_Y", &Lc_TRUEP_Y, &b_Lc_TRUEP_Y);
   fChain->SetBranchAddress("Lc_TRUEP_Z", &Lc_TRUEP_Z, &b_Lc_TRUEP_Z);
   fChain->SetBranchAddress("Lc_TRUEPT", &Lc_TRUEPT, &b_Lc_TRUEPT);
   fChain->SetBranchAddress("Lc_TRUEORIGINVERTEX_X", &Lc_TRUEORIGINVERTEX_X, &b_Lc_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("Lc_TRUEORIGINVERTEX_Y", &Lc_TRUEORIGINVERTEX_Y, &b_Lc_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("Lc_TRUEORIGINVERTEX_Z", &Lc_TRUEORIGINVERTEX_Z, &b_Lc_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("Lc_TRUEENDVERTEX_X", &Lc_TRUEENDVERTEX_X, &b_Lc_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("Lc_TRUEENDVERTEX_Y", &Lc_TRUEENDVERTEX_Y, &b_Lc_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("Lc_TRUEENDVERTEX_Z", &Lc_TRUEENDVERTEX_Z, &b_Lc_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("Lc_TRUEISSTABLE", &Lc_TRUEISSTABLE, &b_Lc_TRUEISSTABLE);
   fChain->SetBranchAddress("Lc_TRUETAU", &Lc_TRUETAU, &b_Lc_TRUETAU);
   fChain->SetBranchAddress("Lc_ID", &Lc_ID, &b_Lc_ID);
   fChain->SetBranchAddress("Lc_BPVIPCHI2", &Lc_BPVIPCHI2, &b_Lc_BPVIPCHI2);
   fChain->SetBranchAddress("Lc_BPVVDCHI2", &Lc_BPVVDCHI2, &b_Lc_BPVVDCHI2);
   fChain->SetBranchAddress("Lc_DOCA12", &Lc_DOCA12, &b_Lc_DOCA12);
   fChain->SetBranchAddress("Lc_DOCA13", &Lc_DOCA13, &b_Lc_DOCA13);
   fChain->SetBranchAddress("Lc_DOCA23", &Lc_DOCA23, &b_Lc_DOCA23);
   fChain->SetBranchAddress("Lc_DOCACHI2MAX", &Lc_DOCACHI2MAX, &b_Lc_DOCACHI2MAX);
   fChain->SetBranchAddress("Lc_DOCAMAX", &Lc_DOCAMAX, &b_Lc_DOCAMAX);
   fChain->SetBranchAddress("Lc_DOCAMIN", &Lc_DOCAMIN, &b_Lc_DOCAMIN);
   fChain->SetBranchAddress("Lc_ETA", &Lc_ETA, &b_Lc_ETA);
   fChain->SetBranchAddress("Lc_M12", &Lc_M12, &b_Lc_M12);
   fChain->SetBranchAddress("Lc_M13", &Lc_M13, &b_Lc_M13);
   fChain->SetBranchAddress("Lc_M23", &Lc_M23, &b_Lc_M23);
   fChain->SetBranchAddress("Lc_SUM_PT", &Lc_SUM_PT, &b_Lc_SUM_PT);
   fChain->SetBranchAddress("Lc_Y", &Lc_Y, &b_Lc_Y);
   fChain->SetBranchAddress("Lc_p_MC12TuneV2_ProbNNe", &Lc_p_MC12TuneV2_ProbNNe, &b_Lc_p_MC12TuneV2_ProbNNe);
   fChain->SetBranchAddress("Lc_p_MC12TuneV2_ProbNNmu", &Lc_p_MC12TuneV2_ProbNNmu, &b_Lc_p_MC12TuneV2_ProbNNmu);
   fChain->SetBranchAddress("Lc_p_MC12TuneV2_ProbNNpi", &Lc_p_MC12TuneV2_ProbNNpi, &b_Lc_p_MC12TuneV2_ProbNNpi);
   fChain->SetBranchAddress("Lc_p_MC12TuneV2_ProbNNk", &Lc_p_MC12TuneV2_ProbNNk, &b_Lc_p_MC12TuneV2_ProbNNk);
   fChain->SetBranchAddress("Lc_p_MC12TuneV2_ProbNNp", &Lc_p_MC12TuneV2_ProbNNp, &b_Lc_p_MC12TuneV2_ProbNNp);
   fChain->SetBranchAddress("Lc_p_MC12TuneV2_ProbNNghost", &Lc_p_MC12TuneV2_ProbNNghost, &b_Lc_p_MC12TuneV2_ProbNNghost);
   fChain->SetBranchAddress("Lc_p_MC12TuneV3_ProbNNe", &Lc_p_MC12TuneV3_ProbNNe, &b_Lc_p_MC12TuneV3_ProbNNe);
   fChain->SetBranchAddress("Lc_p_MC12TuneV3_ProbNNmu", &Lc_p_MC12TuneV3_ProbNNmu, &b_Lc_p_MC12TuneV3_ProbNNmu);
   fChain->SetBranchAddress("Lc_p_MC12TuneV3_ProbNNpi", &Lc_p_MC12TuneV3_ProbNNpi, &b_Lc_p_MC12TuneV3_ProbNNpi);
   fChain->SetBranchAddress("Lc_p_MC12TuneV3_ProbNNk", &Lc_p_MC12TuneV3_ProbNNk, &b_Lc_p_MC12TuneV3_ProbNNk);
   fChain->SetBranchAddress("Lc_p_MC12TuneV3_ProbNNp", &Lc_p_MC12TuneV3_ProbNNp, &b_Lc_p_MC12TuneV3_ProbNNp);
   fChain->SetBranchAddress("Lc_p_MC12TuneV3_ProbNNghost", &Lc_p_MC12TuneV3_ProbNNghost, &b_Lc_p_MC12TuneV3_ProbNNghost);
   fChain->SetBranchAddress("Lc_p_MC12TuneV4_ProbNNe", &Lc_p_MC12TuneV4_ProbNNe, &b_Lc_p_MC12TuneV4_ProbNNe);
   fChain->SetBranchAddress("Lc_p_MC12TuneV4_ProbNNmu", &Lc_p_MC12TuneV4_ProbNNmu, &b_Lc_p_MC12TuneV4_ProbNNmu);
   fChain->SetBranchAddress("Lc_p_MC12TuneV4_ProbNNpi", &Lc_p_MC12TuneV4_ProbNNpi, &b_Lc_p_MC12TuneV4_ProbNNpi);
   fChain->SetBranchAddress("Lc_p_MC12TuneV4_ProbNNk", &Lc_p_MC12TuneV4_ProbNNk, &b_Lc_p_MC12TuneV4_ProbNNk);
   fChain->SetBranchAddress("Lc_p_MC12TuneV4_ProbNNp", &Lc_p_MC12TuneV4_ProbNNp, &b_Lc_p_MC12TuneV4_ProbNNp);
   fChain->SetBranchAddress("Lc_p_MC12TuneV4_ProbNNghost", &Lc_p_MC12TuneV4_ProbNNghost, &b_Lc_p_MC12TuneV4_ProbNNghost);
   fChain->SetBranchAddress("Lc_p_MC15TuneV1_ProbNNe", &Lc_p_MC15TuneV1_ProbNNe, &b_Lc_p_MC15TuneV1_ProbNNe);
   fChain->SetBranchAddress("Lc_p_MC15TuneV1_ProbNNmu", &Lc_p_MC15TuneV1_ProbNNmu, &b_Lc_p_MC15TuneV1_ProbNNmu);
   fChain->SetBranchAddress("Lc_p_MC15TuneV1_ProbNNpi", &Lc_p_MC15TuneV1_ProbNNpi, &b_Lc_p_MC15TuneV1_ProbNNpi);
   fChain->SetBranchAddress("Lc_p_MC15TuneV1_ProbNNk", &Lc_p_MC15TuneV1_ProbNNk, &b_Lc_p_MC15TuneV1_ProbNNk);
   fChain->SetBranchAddress("Lc_p_MC15TuneV1_ProbNNp", &Lc_p_MC15TuneV1_ProbNNp, &b_Lc_p_MC15TuneV1_ProbNNp);
   fChain->SetBranchAddress("Lc_p_MC15TuneV1_ProbNNghost", &Lc_p_MC15TuneV1_ProbNNghost, &b_Lc_p_MC15TuneV1_ProbNNghost);
   fChain->SetBranchAddress("Lc_p_OWNPV_X", &Lc_p_OWNPV_X, &b_Lc_p_OWNPV_X);
   fChain->SetBranchAddress("Lc_p_OWNPV_Y", &Lc_p_OWNPV_Y, &b_Lc_p_OWNPV_Y);
   fChain->SetBranchAddress("Lc_p_OWNPV_Z", &Lc_p_OWNPV_Z, &b_Lc_p_OWNPV_Z);
   fChain->SetBranchAddress("Lc_p_OWNPV_XERR", &Lc_p_OWNPV_XERR, &b_Lc_p_OWNPV_XERR);
   fChain->SetBranchAddress("Lc_p_OWNPV_YERR", &Lc_p_OWNPV_YERR, &b_Lc_p_OWNPV_YERR);
   fChain->SetBranchAddress("Lc_p_OWNPV_ZERR", &Lc_p_OWNPV_ZERR, &b_Lc_p_OWNPV_ZERR);
   fChain->SetBranchAddress("Lc_p_OWNPV_CHI2", &Lc_p_OWNPV_CHI2, &b_Lc_p_OWNPV_CHI2);
   fChain->SetBranchAddress("Lc_p_OWNPV_NDOF", &Lc_p_OWNPV_NDOF, &b_Lc_p_OWNPV_NDOF);
   fChain->SetBranchAddress("Lc_p_OWNPV_COV_", Lc_p_OWNPV_COV_, &b_Lc_p_OWNPV_COV_);
   fChain->SetBranchAddress("Lc_p_IP_OWNPV", &Lc_p_IP_OWNPV, &b_Lc_p_IP_OWNPV);
   fChain->SetBranchAddress("Lc_p_IPCHI2_OWNPV", &Lc_p_IPCHI2_OWNPV, &b_Lc_p_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Lc_p_ORIVX_X", &Lc_p_ORIVX_X, &b_Lc_p_ORIVX_X);
   fChain->SetBranchAddress("Lc_p_ORIVX_Y", &Lc_p_ORIVX_Y, &b_Lc_p_ORIVX_Y);
   fChain->SetBranchAddress("Lc_p_ORIVX_Z", &Lc_p_ORIVX_Z, &b_Lc_p_ORIVX_Z);
   fChain->SetBranchAddress("Lc_p_ORIVX_XERR", &Lc_p_ORIVX_XERR, &b_Lc_p_ORIVX_XERR);
   fChain->SetBranchAddress("Lc_p_ORIVX_YERR", &Lc_p_ORIVX_YERR, &b_Lc_p_ORIVX_YERR);
   fChain->SetBranchAddress("Lc_p_ORIVX_ZERR", &Lc_p_ORIVX_ZERR, &b_Lc_p_ORIVX_ZERR);
   fChain->SetBranchAddress("Lc_p_ORIVX_CHI2", &Lc_p_ORIVX_CHI2, &b_Lc_p_ORIVX_CHI2);
   fChain->SetBranchAddress("Lc_p_ORIVX_NDOF", &Lc_p_ORIVX_NDOF, &b_Lc_p_ORIVX_NDOF);
   fChain->SetBranchAddress("Lc_p_ORIVX_COV_", Lc_p_ORIVX_COV_, &b_Lc_p_ORIVX_COV_);
   fChain->SetBranchAddress("Lc_p_P", &Lc_p_P, &b_Lc_p_P);
   fChain->SetBranchAddress("Lc_p_PT", &Lc_p_PT, &b_Lc_p_PT);
   fChain->SetBranchAddress("Lc_p_PE", &Lc_p_PE, &b_Lc_p_PE);
   fChain->SetBranchAddress("Lc_p_PX", &Lc_p_PX, &b_Lc_p_PX);
   fChain->SetBranchAddress("Lc_p_PY", &Lc_p_PY, &b_Lc_p_PY);
   fChain->SetBranchAddress("Lc_p_PZ", &Lc_p_PZ, &b_Lc_p_PZ);
   fChain->SetBranchAddress("Lc_p_M", &Lc_p_M, &b_Lc_p_M);
   fChain->SetBranchAddress("Lc_p_TRUEID", &Lc_p_TRUEID, &b_Lc_p_TRUEID);
   fChain->SetBranchAddress("Lc_p_MC_MOTHER_ID", &Lc_p_MC_MOTHER_ID, &b_Lc_p_MC_MOTHER_ID);
   fChain->SetBranchAddress("Lc_p_MC_MOTHER_KEY", &Lc_p_MC_MOTHER_KEY, &b_Lc_p_MC_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_p_MC_GD_MOTHER_ID", &Lc_p_MC_GD_MOTHER_ID, &b_Lc_p_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("Lc_p_MC_GD_MOTHER_KEY", &Lc_p_MC_GD_MOTHER_KEY, &b_Lc_p_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_p_MC_GD_GD_MOTHER_ID", &Lc_p_MC_GD_GD_MOTHER_ID, &b_Lc_p_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("Lc_p_MC_GD_GD_MOTHER_KEY", &Lc_p_MC_GD_GD_MOTHER_KEY, &b_Lc_p_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_p_TRUEP_E", &Lc_p_TRUEP_E, &b_Lc_p_TRUEP_E);
   fChain->SetBranchAddress("Lc_p_TRUEP_X", &Lc_p_TRUEP_X, &b_Lc_p_TRUEP_X);
   fChain->SetBranchAddress("Lc_p_TRUEP_Y", &Lc_p_TRUEP_Y, &b_Lc_p_TRUEP_Y);
   fChain->SetBranchAddress("Lc_p_TRUEP_Z", &Lc_p_TRUEP_Z, &b_Lc_p_TRUEP_Z);
   fChain->SetBranchAddress("Lc_p_TRUEPT", &Lc_p_TRUEPT, &b_Lc_p_TRUEPT);
   fChain->SetBranchAddress("Lc_p_TRUEORIGINVERTEX_X", &Lc_p_TRUEORIGINVERTEX_X, &b_Lc_p_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("Lc_p_TRUEORIGINVERTEX_Y", &Lc_p_TRUEORIGINVERTEX_Y, &b_Lc_p_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("Lc_p_TRUEORIGINVERTEX_Z", &Lc_p_TRUEORIGINVERTEX_Z, &b_Lc_p_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("Lc_p_TRUEENDVERTEX_X", &Lc_p_TRUEENDVERTEX_X, &b_Lc_p_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("Lc_p_TRUEENDVERTEX_Y", &Lc_p_TRUEENDVERTEX_Y, &b_Lc_p_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("Lc_p_TRUEENDVERTEX_Z", &Lc_p_TRUEENDVERTEX_Z, &b_Lc_p_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("Lc_p_TRUEISSTABLE", &Lc_p_TRUEISSTABLE, &b_Lc_p_TRUEISSTABLE);
   fChain->SetBranchAddress("Lc_p_TRUETAU", &Lc_p_TRUETAU, &b_Lc_p_TRUETAU);
   fChain->SetBranchAddress("Lc_p_ID", &Lc_p_ID, &b_Lc_p_ID);
   fChain->SetBranchAddress("Lc_p_PIDe", &Lc_p_PIDe, &b_Lc_p_PIDe);
   fChain->SetBranchAddress("Lc_p_PIDmu", &Lc_p_PIDmu, &b_Lc_p_PIDmu);
   fChain->SetBranchAddress("Lc_p_PIDK", &Lc_p_PIDK, &b_Lc_p_PIDK);
   fChain->SetBranchAddress("Lc_p_PIDp", &Lc_p_PIDp, &b_Lc_p_PIDp);
   fChain->SetBranchAddress("Lc_p_PIDd", &Lc_p_PIDd, &b_Lc_p_PIDd);
   fChain->SetBranchAddress("Lc_p_ProbNNe", &Lc_p_ProbNNe, &b_Lc_p_ProbNNe);
   fChain->SetBranchAddress("Lc_p_ProbNNk", &Lc_p_ProbNNk, &b_Lc_p_ProbNNk);
   fChain->SetBranchAddress("Lc_p_ProbNNp", &Lc_p_ProbNNp, &b_Lc_p_ProbNNp);
   fChain->SetBranchAddress("Lc_p_ProbNNpi", &Lc_p_ProbNNpi, &b_Lc_p_ProbNNpi);
   fChain->SetBranchAddress("Lc_p_ProbNNmu", &Lc_p_ProbNNmu, &b_Lc_p_ProbNNmu);
   fChain->SetBranchAddress("Lc_p_ProbNNd", &Lc_p_ProbNNd, &b_Lc_p_ProbNNd);
   fChain->SetBranchAddress("Lc_p_ProbNNghost", &Lc_p_ProbNNghost, &b_Lc_p_ProbNNghost);
   fChain->SetBranchAddress("Lc_p_hasMuon", &Lc_p_hasMuon, &b_Lc_p_hasMuon);
   fChain->SetBranchAddress("Lc_p_isMuon", &Lc_p_isMuon, &b_Lc_p_isMuon);
   fChain->SetBranchAddress("Lc_p_hasRich", &Lc_p_hasRich, &b_Lc_p_hasRich);
   fChain->SetBranchAddress("Lc_p_UsedRichAerogel", &Lc_p_UsedRichAerogel, &b_Lc_p_UsedRichAerogel);
   fChain->SetBranchAddress("Lc_p_UsedRich1Gas", &Lc_p_UsedRich1Gas, &b_Lc_p_UsedRich1Gas);
   fChain->SetBranchAddress("Lc_p_UsedRich2Gas", &Lc_p_UsedRich2Gas, &b_Lc_p_UsedRich2Gas);
   fChain->SetBranchAddress("Lc_p_RichAboveElThres", &Lc_p_RichAboveElThres, &b_Lc_p_RichAboveElThres);
   fChain->SetBranchAddress("Lc_p_RichAboveMuThres", &Lc_p_RichAboveMuThres, &b_Lc_p_RichAboveMuThres);
   fChain->SetBranchAddress("Lc_p_RichAbovePiThres", &Lc_p_RichAbovePiThres, &b_Lc_p_RichAbovePiThres);
   fChain->SetBranchAddress("Lc_p_RichAboveKaThres", &Lc_p_RichAboveKaThres, &b_Lc_p_RichAboveKaThres);
   fChain->SetBranchAddress("Lc_p_RichAbovePrThres", &Lc_p_RichAbovePrThres, &b_Lc_p_RichAbovePrThres);
   fChain->SetBranchAddress("Lc_p_hasCalo", &Lc_p_hasCalo, &b_Lc_p_hasCalo);
   fChain->SetBranchAddress("Lc_p_TRACK_Type", &Lc_p_TRACK_Type, &b_Lc_p_TRACK_Type);
   fChain->SetBranchAddress("Lc_p_TRACK_Key", &Lc_p_TRACK_Key, &b_Lc_p_TRACK_Key);
   fChain->SetBranchAddress("Lc_p_TRACK_CHI2NDOF", &Lc_p_TRACK_CHI2NDOF, &b_Lc_p_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("Lc_p_TRACK_PCHI2", &Lc_p_TRACK_PCHI2, &b_Lc_p_TRACK_PCHI2);
   fChain->SetBranchAddress("Lc_p_TRACK_MatchCHI2", &Lc_p_TRACK_MatchCHI2, &b_Lc_p_TRACK_MatchCHI2);
   fChain->SetBranchAddress("Lc_p_TRACK_GhostProb", &Lc_p_TRACK_GhostProb, &b_Lc_p_TRACK_GhostProb);
   fChain->SetBranchAddress("Lc_p_TRACK_CloneDist", &Lc_p_TRACK_CloneDist, &b_Lc_p_TRACK_CloneDist);
   fChain->SetBranchAddress("Lc_p_TRACK_Likelihood", &Lc_p_TRACK_Likelihood, &b_Lc_p_TRACK_Likelihood);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV2_ProbNNe", &Lc_Km_MC12TuneV2_ProbNNe, &b_Lc_Km_MC12TuneV2_ProbNNe);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV2_ProbNNmu", &Lc_Km_MC12TuneV2_ProbNNmu, &b_Lc_Km_MC12TuneV2_ProbNNmu);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV2_ProbNNpi", &Lc_Km_MC12TuneV2_ProbNNpi, &b_Lc_Km_MC12TuneV2_ProbNNpi);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV2_ProbNNk", &Lc_Km_MC12TuneV2_ProbNNk, &b_Lc_Km_MC12TuneV2_ProbNNk);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV2_ProbNNp", &Lc_Km_MC12TuneV2_ProbNNp, &b_Lc_Km_MC12TuneV2_ProbNNp);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV2_ProbNNghost", &Lc_Km_MC12TuneV2_ProbNNghost, &b_Lc_Km_MC12TuneV2_ProbNNghost);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV3_ProbNNe", &Lc_Km_MC12TuneV3_ProbNNe, &b_Lc_Km_MC12TuneV3_ProbNNe);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV3_ProbNNmu", &Lc_Km_MC12TuneV3_ProbNNmu, &b_Lc_Km_MC12TuneV3_ProbNNmu);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV3_ProbNNpi", &Lc_Km_MC12TuneV3_ProbNNpi, &b_Lc_Km_MC12TuneV3_ProbNNpi);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV3_ProbNNk", &Lc_Km_MC12TuneV3_ProbNNk, &b_Lc_Km_MC12TuneV3_ProbNNk);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV3_ProbNNp", &Lc_Km_MC12TuneV3_ProbNNp, &b_Lc_Km_MC12TuneV3_ProbNNp);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV3_ProbNNghost", &Lc_Km_MC12TuneV3_ProbNNghost, &b_Lc_Km_MC12TuneV3_ProbNNghost);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV4_ProbNNe", &Lc_Km_MC12TuneV4_ProbNNe, &b_Lc_Km_MC12TuneV4_ProbNNe);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV4_ProbNNmu", &Lc_Km_MC12TuneV4_ProbNNmu, &b_Lc_Km_MC12TuneV4_ProbNNmu);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV4_ProbNNpi", &Lc_Km_MC12TuneV4_ProbNNpi, &b_Lc_Km_MC12TuneV4_ProbNNpi);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV4_ProbNNk", &Lc_Km_MC12TuneV4_ProbNNk, &b_Lc_Km_MC12TuneV4_ProbNNk);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV4_ProbNNp", &Lc_Km_MC12TuneV4_ProbNNp, &b_Lc_Km_MC12TuneV4_ProbNNp);
   fChain->SetBranchAddress("Lc_Km_MC12TuneV4_ProbNNghost", &Lc_Km_MC12TuneV4_ProbNNghost, &b_Lc_Km_MC12TuneV4_ProbNNghost);
   fChain->SetBranchAddress("Lc_Km_MC15TuneV1_ProbNNe", &Lc_Km_MC15TuneV1_ProbNNe, &b_Lc_Km_MC15TuneV1_ProbNNe);
   fChain->SetBranchAddress("Lc_Km_MC15TuneV1_ProbNNmu", &Lc_Km_MC15TuneV1_ProbNNmu, &b_Lc_Km_MC15TuneV1_ProbNNmu);
   fChain->SetBranchAddress("Lc_Km_MC15TuneV1_ProbNNpi", &Lc_Km_MC15TuneV1_ProbNNpi, &b_Lc_Km_MC15TuneV1_ProbNNpi);
   fChain->SetBranchAddress("Lc_Km_MC15TuneV1_ProbNNk", &Lc_Km_MC15TuneV1_ProbNNk, &b_Lc_Km_MC15TuneV1_ProbNNk);
   fChain->SetBranchAddress("Lc_Km_MC15TuneV1_ProbNNp", &Lc_Km_MC15TuneV1_ProbNNp, &b_Lc_Km_MC15TuneV1_ProbNNp);
   fChain->SetBranchAddress("Lc_Km_MC15TuneV1_ProbNNghost", &Lc_Km_MC15TuneV1_ProbNNghost, &b_Lc_Km_MC15TuneV1_ProbNNghost);
   fChain->SetBranchAddress("Lc_Km_OWNPV_X", &Lc_Km_OWNPV_X, &b_Lc_Km_OWNPV_X);
   fChain->SetBranchAddress("Lc_Km_OWNPV_Y", &Lc_Km_OWNPV_Y, &b_Lc_Km_OWNPV_Y);
   fChain->SetBranchAddress("Lc_Km_OWNPV_Z", &Lc_Km_OWNPV_Z, &b_Lc_Km_OWNPV_Z);
   fChain->SetBranchAddress("Lc_Km_OWNPV_XERR", &Lc_Km_OWNPV_XERR, &b_Lc_Km_OWNPV_XERR);
   fChain->SetBranchAddress("Lc_Km_OWNPV_YERR", &Lc_Km_OWNPV_YERR, &b_Lc_Km_OWNPV_YERR);
   fChain->SetBranchAddress("Lc_Km_OWNPV_ZERR", &Lc_Km_OWNPV_ZERR, &b_Lc_Km_OWNPV_ZERR);
   fChain->SetBranchAddress("Lc_Km_OWNPV_CHI2", &Lc_Km_OWNPV_CHI2, &b_Lc_Km_OWNPV_CHI2);
   fChain->SetBranchAddress("Lc_Km_OWNPV_NDOF", &Lc_Km_OWNPV_NDOF, &b_Lc_Km_OWNPV_NDOF);
   fChain->SetBranchAddress("Lc_Km_OWNPV_COV_", Lc_Km_OWNPV_COV_, &b_Lc_Km_OWNPV_COV_);
   fChain->SetBranchAddress("Lc_Km_IP_OWNPV", &Lc_Km_IP_OWNPV, &b_Lc_Km_IP_OWNPV);
   fChain->SetBranchAddress("Lc_Km_IPCHI2_OWNPV", &Lc_Km_IPCHI2_OWNPV, &b_Lc_Km_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Lc_Km_ORIVX_X", &Lc_Km_ORIVX_X, &b_Lc_Km_ORIVX_X);
   fChain->SetBranchAddress("Lc_Km_ORIVX_Y", &Lc_Km_ORIVX_Y, &b_Lc_Km_ORIVX_Y);
   fChain->SetBranchAddress("Lc_Km_ORIVX_Z", &Lc_Km_ORIVX_Z, &b_Lc_Km_ORIVX_Z);
   fChain->SetBranchAddress("Lc_Km_ORIVX_XERR", &Lc_Km_ORIVX_XERR, &b_Lc_Km_ORIVX_XERR);
   fChain->SetBranchAddress("Lc_Km_ORIVX_YERR", &Lc_Km_ORIVX_YERR, &b_Lc_Km_ORIVX_YERR);
   fChain->SetBranchAddress("Lc_Km_ORIVX_ZERR", &Lc_Km_ORIVX_ZERR, &b_Lc_Km_ORIVX_ZERR);
   fChain->SetBranchAddress("Lc_Km_ORIVX_CHI2", &Lc_Km_ORIVX_CHI2, &b_Lc_Km_ORIVX_CHI2);
   fChain->SetBranchAddress("Lc_Km_ORIVX_NDOF", &Lc_Km_ORIVX_NDOF, &b_Lc_Km_ORIVX_NDOF);
   fChain->SetBranchAddress("Lc_Km_ORIVX_COV_", Lc_Km_ORIVX_COV_, &b_Lc_Km_ORIVX_COV_);
   fChain->SetBranchAddress("Lc_Km_P", &Lc_Km_P, &b_Lc_Km_P);
   fChain->SetBranchAddress("Lc_Km_PT", &Lc_Km_PT, &b_Lc_Km_PT);
   fChain->SetBranchAddress("Lc_Km_PE", &Lc_Km_PE, &b_Lc_Km_PE);
   fChain->SetBranchAddress("Lc_Km_PX", &Lc_Km_PX, &b_Lc_Km_PX);
   fChain->SetBranchAddress("Lc_Km_PY", &Lc_Km_PY, &b_Lc_Km_PY);
   fChain->SetBranchAddress("Lc_Km_PZ", &Lc_Km_PZ, &b_Lc_Km_PZ);
   fChain->SetBranchAddress("Lc_Km_M", &Lc_Km_M, &b_Lc_Km_M);
   fChain->SetBranchAddress("Lc_Km_TRUEID", &Lc_Km_TRUEID, &b_Lc_Km_TRUEID);
   fChain->SetBranchAddress("Lc_Km_MC_MOTHER_ID", &Lc_Km_MC_MOTHER_ID, &b_Lc_Km_MC_MOTHER_ID);
   fChain->SetBranchAddress("Lc_Km_MC_MOTHER_KEY", &Lc_Km_MC_MOTHER_KEY, &b_Lc_Km_MC_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_Km_MC_GD_MOTHER_ID", &Lc_Km_MC_GD_MOTHER_ID, &b_Lc_Km_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("Lc_Km_MC_GD_MOTHER_KEY", &Lc_Km_MC_GD_MOTHER_KEY, &b_Lc_Km_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_Km_MC_GD_GD_MOTHER_ID", &Lc_Km_MC_GD_GD_MOTHER_ID, &b_Lc_Km_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("Lc_Km_MC_GD_GD_MOTHER_KEY", &Lc_Km_MC_GD_GD_MOTHER_KEY, &b_Lc_Km_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_Km_TRUEP_E", &Lc_Km_TRUEP_E, &b_Lc_Km_TRUEP_E);
   fChain->SetBranchAddress("Lc_Km_TRUEP_X", &Lc_Km_TRUEP_X, &b_Lc_Km_TRUEP_X);
   fChain->SetBranchAddress("Lc_Km_TRUEP_Y", &Lc_Km_TRUEP_Y, &b_Lc_Km_TRUEP_Y);
   fChain->SetBranchAddress("Lc_Km_TRUEP_Z", &Lc_Km_TRUEP_Z, &b_Lc_Km_TRUEP_Z);
   fChain->SetBranchAddress("Lc_Km_TRUEPT", &Lc_Km_TRUEPT, &b_Lc_Km_TRUEPT);
   fChain->SetBranchAddress("Lc_Km_TRUEORIGINVERTEX_X", &Lc_Km_TRUEORIGINVERTEX_X, &b_Lc_Km_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("Lc_Km_TRUEORIGINVERTEX_Y", &Lc_Km_TRUEORIGINVERTEX_Y, &b_Lc_Km_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("Lc_Km_TRUEORIGINVERTEX_Z", &Lc_Km_TRUEORIGINVERTEX_Z, &b_Lc_Km_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("Lc_Km_TRUEENDVERTEX_X", &Lc_Km_TRUEENDVERTEX_X, &b_Lc_Km_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("Lc_Km_TRUEENDVERTEX_Y", &Lc_Km_TRUEENDVERTEX_Y, &b_Lc_Km_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("Lc_Km_TRUEENDVERTEX_Z", &Lc_Km_TRUEENDVERTEX_Z, &b_Lc_Km_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("Lc_Km_TRUEISSTABLE", &Lc_Km_TRUEISSTABLE, &b_Lc_Km_TRUEISSTABLE);
   fChain->SetBranchAddress("Lc_Km_TRUETAU", &Lc_Km_TRUETAU, &b_Lc_Km_TRUETAU);
   fChain->SetBranchAddress("Lc_Km_ID", &Lc_Km_ID, &b_Lc_Km_ID);
   fChain->SetBranchAddress("Lc_Km_PIDe", &Lc_Km_PIDe, &b_Lc_Km_PIDe);
   fChain->SetBranchAddress("Lc_Km_PIDmu", &Lc_Km_PIDmu, &b_Lc_Km_PIDmu);
   fChain->SetBranchAddress("Lc_Km_PIDK", &Lc_Km_PIDK, &b_Lc_Km_PIDK);
   fChain->SetBranchAddress("Lc_Km_PIDp", &Lc_Km_PIDp, &b_Lc_Km_PIDp);
   fChain->SetBranchAddress("Lc_Km_PIDd", &Lc_Km_PIDd, &b_Lc_Km_PIDd);
   fChain->SetBranchAddress("Lc_Km_ProbNNe", &Lc_Km_ProbNNe, &b_Lc_Km_ProbNNe);
   fChain->SetBranchAddress("Lc_Km_ProbNNk", &Lc_Km_ProbNNk, &b_Lc_Km_ProbNNk);
   fChain->SetBranchAddress("Lc_Km_ProbNNp", &Lc_Km_ProbNNp, &b_Lc_Km_ProbNNp);
   fChain->SetBranchAddress("Lc_Km_ProbNNpi", &Lc_Km_ProbNNpi, &b_Lc_Km_ProbNNpi);
   fChain->SetBranchAddress("Lc_Km_ProbNNmu", &Lc_Km_ProbNNmu, &b_Lc_Km_ProbNNmu);
   fChain->SetBranchAddress("Lc_Km_ProbNNd", &Lc_Km_ProbNNd, &b_Lc_Km_ProbNNd);
   fChain->SetBranchAddress("Lc_Km_ProbNNghost", &Lc_Km_ProbNNghost, &b_Lc_Km_ProbNNghost);
   fChain->SetBranchAddress("Lc_Km_hasMuon", &Lc_Km_hasMuon, &b_Lc_Km_hasMuon);
   fChain->SetBranchAddress("Lc_Km_isMuon", &Lc_Km_isMuon, &b_Lc_Km_isMuon);
   fChain->SetBranchAddress("Lc_Km_hasRich", &Lc_Km_hasRich, &b_Lc_Km_hasRich);
   fChain->SetBranchAddress("Lc_Km_UsedRichAerogel", &Lc_Km_UsedRichAerogel, &b_Lc_Km_UsedRichAerogel);
   fChain->SetBranchAddress("Lc_Km_UsedRich1Gas", &Lc_Km_UsedRich1Gas, &b_Lc_Km_UsedRich1Gas);
   fChain->SetBranchAddress("Lc_Km_UsedRich2Gas", &Lc_Km_UsedRich2Gas, &b_Lc_Km_UsedRich2Gas);
   fChain->SetBranchAddress("Lc_Km_RichAboveElThres", &Lc_Km_RichAboveElThres, &b_Lc_Km_RichAboveElThres);
   fChain->SetBranchAddress("Lc_Km_RichAboveMuThres", &Lc_Km_RichAboveMuThres, &b_Lc_Km_RichAboveMuThres);
   fChain->SetBranchAddress("Lc_Km_RichAbovePiThres", &Lc_Km_RichAbovePiThres, &b_Lc_Km_RichAbovePiThres);
   fChain->SetBranchAddress("Lc_Km_RichAboveKaThres", &Lc_Km_RichAboveKaThres, &b_Lc_Km_RichAboveKaThres);
   fChain->SetBranchAddress("Lc_Km_RichAbovePrThres", &Lc_Km_RichAbovePrThres, &b_Lc_Km_RichAbovePrThres);
   fChain->SetBranchAddress("Lc_Km_hasCalo", &Lc_Km_hasCalo, &b_Lc_Km_hasCalo);
   fChain->SetBranchAddress("Lc_Km_TRACK_Type", &Lc_Km_TRACK_Type, &b_Lc_Km_TRACK_Type);
   fChain->SetBranchAddress("Lc_Km_TRACK_Key", &Lc_Km_TRACK_Key, &b_Lc_Km_TRACK_Key);
   fChain->SetBranchAddress("Lc_Km_TRACK_CHI2NDOF", &Lc_Km_TRACK_CHI2NDOF, &b_Lc_Km_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("Lc_Km_TRACK_PCHI2", &Lc_Km_TRACK_PCHI2, &b_Lc_Km_TRACK_PCHI2);
   fChain->SetBranchAddress("Lc_Km_TRACK_MatchCHI2", &Lc_Km_TRACK_MatchCHI2, &b_Lc_Km_TRACK_MatchCHI2);
   fChain->SetBranchAddress("Lc_Km_TRACK_GhostProb", &Lc_Km_TRACK_GhostProb, &b_Lc_Km_TRACK_GhostProb);
   fChain->SetBranchAddress("Lc_Km_TRACK_CloneDist", &Lc_Km_TRACK_CloneDist, &b_Lc_Km_TRACK_CloneDist);
   fChain->SetBranchAddress("Lc_Km_TRACK_Likelihood", &Lc_Km_TRACK_Likelihood, &b_Lc_Km_TRACK_Likelihood);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV2_ProbNNe", &Lc_pip_MC12TuneV2_ProbNNe, &b_Lc_pip_MC12TuneV2_ProbNNe);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV2_ProbNNmu", &Lc_pip_MC12TuneV2_ProbNNmu, &b_Lc_pip_MC12TuneV2_ProbNNmu);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV2_ProbNNpi", &Lc_pip_MC12TuneV2_ProbNNpi, &b_Lc_pip_MC12TuneV2_ProbNNpi);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV2_ProbNNk", &Lc_pip_MC12TuneV2_ProbNNk, &b_Lc_pip_MC12TuneV2_ProbNNk);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV2_ProbNNp", &Lc_pip_MC12TuneV2_ProbNNp, &b_Lc_pip_MC12TuneV2_ProbNNp);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV2_ProbNNghost", &Lc_pip_MC12TuneV2_ProbNNghost, &b_Lc_pip_MC12TuneV2_ProbNNghost);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV3_ProbNNe", &Lc_pip_MC12TuneV3_ProbNNe, &b_Lc_pip_MC12TuneV3_ProbNNe);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV3_ProbNNmu", &Lc_pip_MC12TuneV3_ProbNNmu, &b_Lc_pip_MC12TuneV3_ProbNNmu);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV3_ProbNNpi", &Lc_pip_MC12TuneV3_ProbNNpi, &b_Lc_pip_MC12TuneV3_ProbNNpi);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV3_ProbNNk", &Lc_pip_MC12TuneV3_ProbNNk, &b_Lc_pip_MC12TuneV3_ProbNNk);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV3_ProbNNp", &Lc_pip_MC12TuneV3_ProbNNp, &b_Lc_pip_MC12TuneV3_ProbNNp);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV3_ProbNNghost", &Lc_pip_MC12TuneV3_ProbNNghost, &b_Lc_pip_MC12TuneV3_ProbNNghost);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV4_ProbNNe", &Lc_pip_MC12TuneV4_ProbNNe, &b_Lc_pip_MC12TuneV4_ProbNNe);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV4_ProbNNmu", &Lc_pip_MC12TuneV4_ProbNNmu, &b_Lc_pip_MC12TuneV4_ProbNNmu);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV4_ProbNNpi", &Lc_pip_MC12TuneV4_ProbNNpi, &b_Lc_pip_MC12TuneV4_ProbNNpi);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV4_ProbNNk", &Lc_pip_MC12TuneV4_ProbNNk, &b_Lc_pip_MC12TuneV4_ProbNNk);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV4_ProbNNp", &Lc_pip_MC12TuneV4_ProbNNp, &b_Lc_pip_MC12TuneV4_ProbNNp);
   fChain->SetBranchAddress("Lc_pip_MC12TuneV4_ProbNNghost", &Lc_pip_MC12TuneV4_ProbNNghost, &b_Lc_pip_MC12TuneV4_ProbNNghost);
   fChain->SetBranchAddress("Lc_pip_MC15TuneV1_ProbNNe", &Lc_pip_MC15TuneV1_ProbNNe, &b_Lc_pip_MC15TuneV1_ProbNNe);
   fChain->SetBranchAddress("Lc_pip_MC15TuneV1_ProbNNmu", &Lc_pip_MC15TuneV1_ProbNNmu, &b_Lc_pip_MC15TuneV1_ProbNNmu);
   fChain->SetBranchAddress("Lc_pip_MC15TuneV1_ProbNNpi", &Lc_pip_MC15TuneV1_ProbNNpi, &b_Lc_pip_MC15TuneV1_ProbNNpi);
   fChain->SetBranchAddress("Lc_pip_MC15TuneV1_ProbNNk", &Lc_pip_MC15TuneV1_ProbNNk, &b_Lc_pip_MC15TuneV1_ProbNNk);
   fChain->SetBranchAddress("Lc_pip_MC15TuneV1_ProbNNp", &Lc_pip_MC15TuneV1_ProbNNp, &b_Lc_pip_MC15TuneV1_ProbNNp);
   fChain->SetBranchAddress("Lc_pip_MC15TuneV1_ProbNNghost", &Lc_pip_MC15TuneV1_ProbNNghost, &b_Lc_pip_MC15TuneV1_ProbNNghost);
   fChain->SetBranchAddress("Lc_pip_OWNPV_X", &Lc_pip_OWNPV_X, &b_Lc_pip_OWNPV_X);
   fChain->SetBranchAddress("Lc_pip_OWNPV_Y", &Lc_pip_OWNPV_Y, &b_Lc_pip_OWNPV_Y);
   fChain->SetBranchAddress("Lc_pip_OWNPV_Z", &Lc_pip_OWNPV_Z, &b_Lc_pip_OWNPV_Z);
   fChain->SetBranchAddress("Lc_pip_OWNPV_XERR", &Lc_pip_OWNPV_XERR, &b_Lc_pip_OWNPV_XERR);
   fChain->SetBranchAddress("Lc_pip_OWNPV_YERR", &Lc_pip_OWNPV_YERR, &b_Lc_pip_OWNPV_YERR);
   fChain->SetBranchAddress("Lc_pip_OWNPV_ZERR", &Lc_pip_OWNPV_ZERR, &b_Lc_pip_OWNPV_ZERR);
   fChain->SetBranchAddress("Lc_pip_OWNPV_CHI2", &Lc_pip_OWNPV_CHI2, &b_Lc_pip_OWNPV_CHI2);
   fChain->SetBranchAddress("Lc_pip_OWNPV_NDOF", &Lc_pip_OWNPV_NDOF, &b_Lc_pip_OWNPV_NDOF);
   fChain->SetBranchAddress("Lc_pip_OWNPV_COV_", Lc_pip_OWNPV_COV_, &b_Lc_pip_OWNPV_COV_);
   fChain->SetBranchAddress("Lc_pip_IP_OWNPV", &Lc_pip_IP_OWNPV, &b_Lc_pip_IP_OWNPV);
   fChain->SetBranchAddress("Lc_pip_IPCHI2_OWNPV", &Lc_pip_IPCHI2_OWNPV, &b_Lc_pip_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Lc_pip_ORIVX_X", &Lc_pip_ORIVX_X, &b_Lc_pip_ORIVX_X);
   fChain->SetBranchAddress("Lc_pip_ORIVX_Y", &Lc_pip_ORIVX_Y, &b_Lc_pip_ORIVX_Y);
   fChain->SetBranchAddress("Lc_pip_ORIVX_Z", &Lc_pip_ORIVX_Z, &b_Lc_pip_ORIVX_Z);
   fChain->SetBranchAddress("Lc_pip_ORIVX_XERR", &Lc_pip_ORIVX_XERR, &b_Lc_pip_ORIVX_XERR);
   fChain->SetBranchAddress("Lc_pip_ORIVX_YERR", &Lc_pip_ORIVX_YERR, &b_Lc_pip_ORIVX_YERR);
   fChain->SetBranchAddress("Lc_pip_ORIVX_ZERR", &Lc_pip_ORIVX_ZERR, &b_Lc_pip_ORIVX_ZERR);
   fChain->SetBranchAddress("Lc_pip_ORIVX_CHI2", &Lc_pip_ORIVX_CHI2, &b_Lc_pip_ORIVX_CHI2);
   fChain->SetBranchAddress("Lc_pip_ORIVX_NDOF", &Lc_pip_ORIVX_NDOF, &b_Lc_pip_ORIVX_NDOF);
   fChain->SetBranchAddress("Lc_pip_ORIVX_COV_", Lc_pip_ORIVX_COV_, &b_Lc_pip_ORIVX_COV_);
   fChain->SetBranchAddress("Lc_pip_P", &Lc_pip_P, &b_Lc_pip_P);
   fChain->SetBranchAddress("Lc_pip_PT", &Lc_pip_PT, &b_Lc_pip_PT);
   fChain->SetBranchAddress("Lc_pip_PE", &Lc_pip_PE, &b_Lc_pip_PE);
   fChain->SetBranchAddress("Lc_pip_PX", &Lc_pip_PX, &b_Lc_pip_PX);
   fChain->SetBranchAddress("Lc_pip_PY", &Lc_pip_PY, &b_Lc_pip_PY);
   fChain->SetBranchAddress("Lc_pip_PZ", &Lc_pip_PZ, &b_Lc_pip_PZ);
   fChain->SetBranchAddress("Lc_pip_M", &Lc_pip_M, &b_Lc_pip_M);
   fChain->SetBranchAddress("Lc_pip_TRUEID", &Lc_pip_TRUEID, &b_Lc_pip_TRUEID);
   fChain->SetBranchAddress("Lc_pip_MC_MOTHER_ID", &Lc_pip_MC_MOTHER_ID, &b_Lc_pip_MC_MOTHER_ID);
   fChain->SetBranchAddress("Lc_pip_MC_MOTHER_KEY", &Lc_pip_MC_MOTHER_KEY, &b_Lc_pip_MC_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_pip_MC_GD_MOTHER_ID", &Lc_pip_MC_GD_MOTHER_ID, &b_Lc_pip_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("Lc_pip_MC_GD_MOTHER_KEY", &Lc_pip_MC_GD_MOTHER_KEY, &b_Lc_pip_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_pip_MC_GD_GD_MOTHER_ID", &Lc_pip_MC_GD_GD_MOTHER_ID, &b_Lc_pip_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("Lc_pip_MC_GD_GD_MOTHER_KEY", &Lc_pip_MC_GD_GD_MOTHER_KEY, &b_Lc_pip_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Lc_pip_TRUEP_E", &Lc_pip_TRUEP_E, &b_Lc_pip_TRUEP_E);
   fChain->SetBranchAddress("Lc_pip_TRUEP_X", &Lc_pip_TRUEP_X, &b_Lc_pip_TRUEP_X);
   fChain->SetBranchAddress("Lc_pip_TRUEP_Y", &Lc_pip_TRUEP_Y, &b_Lc_pip_TRUEP_Y);
   fChain->SetBranchAddress("Lc_pip_TRUEP_Z", &Lc_pip_TRUEP_Z, &b_Lc_pip_TRUEP_Z);
   fChain->SetBranchAddress("Lc_pip_TRUEPT", &Lc_pip_TRUEPT, &b_Lc_pip_TRUEPT);
   fChain->SetBranchAddress("Lc_pip_TRUEORIGINVERTEX_X", &Lc_pip_TRUEORIGINVERTEX_X, &b_Lc_pip_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("Lc_pip_TRUEORIGINVERTEX_Y", &Lc_pip_TRUEORIGINVERTEX_Y, &b_Lc_pip_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("Lc_pip_TRUEORIGINVERTEX_Z", &Lc_pip_TRUEORIGINVERTEX_Z, &b_Lc_pip_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("Lc_pip_TRUEENDVERTEX_X", &Lc_pip_TRUEENDVERTEX_X, &b_Lc_pip_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("Lc_pip_TRUEENDVERTEX_Y", &Lc_pip_TRUEENDVERTEX_Y, &b_Lc_pip_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("Lc_pip_TRUEENDVERTEX_Z", &Lc_pip_TRUEENDVERTEX_Z, &b_Lc_pip_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("Lc_pip_TRUEISSTABLE", &Lc_pip_TRUEISSTABLE, &b_Lc_pip_TRUEISSTABLE);
   fChain->SetBranchAddress("Lc_pip_TRUETAU", &Lc_pip_TRUETAU, &b_Lc_pip_TRUETAU);
   fChain->SetBranchAddress("Lc_pip_ID", &Lc_pip_ID, &b_Lc_pip_ID);
   fChain->SetBranchAddress("Lc_pip_PIDe", &Lc_pip_PIDe, &b_Lc_pip_PIDe);
   fChain->SetBranchAddress("Lc_pip_PIDmu", &Lc_pip_PIDmu, &b_Lc_pip_PIDmu);
   fChain->SetBranchAddress("Lc_pip_PIDK", &Lc_pip_PIDK, &b_Lc_pip_PIDK);
   fChain->SetBranchAddress("Lc_pip_PIDp", &Lc_pip_PIDp, &b_Lc_pip_PIDp);
   fChain->SetBranchAddress("Lc_pip_PIDd", &Lc_pip_PIDd, &b_Lc_pip_PIDd);
   fChain->SetBranchAddress("Lc_pip_ProbNNe", &Lc_pip_ProbNNe, &b_Lc_pip_ProbNNe);
   fChain->SetBranchAddress("Lc_pip_ProbNNk", &Lc_pip_ProbNNk, &b_Lc_pip_ProbNNk);
   fChain->SetBranchAddress("Lc_pip_ProbNNp", &Lc_pip_ProbNNp, &b_Lc_pip_ProbNNp);
   fChain->SetBranchAddress("Lc_pip_ProbNNpi", &Lc_pip_ProbNNpi, &b_Lc_pip_ProbNNpi);
   fChain->SetBranchAddress("Lc_pip_ProbNNmu", &Lc_pip_ProbNNmu, &b_Lc_pip_ProbNNmu);
   fChain->SetBranchAddress("Lc_pip_ProbNNd", &Lc_pip_ProbNNd, &b_Lc_pip_ProbNNd);
   fChain->SetBranchAddress("Lc_pip_ProbNNghost", &Lc_pip_ProbNNghost, &b_Lc_pip_ProbNNghost);
   fChain->SetBranchAddress("Lc_pip_hasMuon", &Lc_pip_hasMuon, &b_Lc_pip_hasMuon);
   fChain->SetBranchAddress("Lc_pip_isMuon", &Lc_pip_isMuon, &b_Lc_pip_isMuon);
   fChain->SetBranchAddress("Lc_pip_hasRich", &Lc_pip_hasRich, &b_Lc_pip_hasRich);
   fChain->SetBranchAddress("Lc_pip_UsedRichAerogel", &Lc_pip_UsedRichAerogel, &b_Lc_pip_UsedRichAerogel);
   fChain->SetBranchAddress("Lc_pip_UsedRich1Gas", &Lc_pip_UsedRich1Gas, &b_Lc_pip_UsedRich1Gas);
   fChain->SetBranchAddress("Lc_pip_UsedRich2Gas", &Lc_pip_UsedRich2Gas, &b_Lc_pip_UsedRich2Gas);
   fChain->SetBranchAddress("Lc_pip_RichAboveElThres", &Lc_pip_RichAboveElThres, &b_Lc_pip_RichAboveElThres);
   fChain->SetBranchAddress("Lc_pip_RichAboveMuThres", &Lc_pip_RichAboveMuThres, &b_Lc_pip_RichAboveMuThres);
   fChain->SetBranchAddress("Lc_pip_RichAbovePiThres", &Lc_pip_RichAbovePiThres, &b_Lc_pip_RichAbovePiThres);
   fChain->SetBranchAddress("Lc_pip_RichAboveKaThres", &Lc_pip_RichAboveKaThres, &b_Lc_pip_RichAboveKaThres);
   fChain->SetBranchAddress("Lc_pip_RichAbovePrThres", &Lc_pip_RichAbovePrThres, &b_Lc_pip_RichAbovePrThres);
   fChain->SetBranchAddress("Lc_pip_hasCalo", &Lc_pip_hasCalo, &b_Lc_pip_hasCalo);
   fChain->SetBranchAddress("Lc_pip_TRACK_Type", &Lc_pip_TRACK_Type, &b_Lc_pip_TRACK_Type);
   fChain->SetBranchAddress("Lc_pip_TRACK_Key", &Lc_pip_TRACK_Key, &b_Lc_pip_TRACK_Key);
   fChain->SetBranchAddress("Lc_pip_TRACK_CHI2NDOF", &Lc_pip_TRACK_CHI2NDOF, &b_Lc_pip_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("Lc_pip_TRACK_PCHI2", &Lc_pip_TRACK_PCHI2, &b_Lc_pip_TRACK_PCHI2);
   fChain->SetBranchAddress("Lc_pip_TRACK_MatchCHI2", &Lc_pip_TRACK_MatchCHI2, &b_Lc_pip_TRACK_MatchCHI2);
   fChain->SetBranchAddress("Lc_pip_TRACK_GhostProb", &Lc_pip_TRACK_GhostProb, &b_Lc_pip_TRACK_GhostProb);
   fChain->SetBranchAddress("Lc_pip_TRACK_CloneDist", &Lc_pip_TRACK_CloneDist, &b_Lc_pip_TRACK_CloneDist);
   fChain->SetBranchAddress("Lc_pip_TRACK_Likelihood", &Lc_pip_TRACK_Likelihood, &b_Lc_pip_TRACK_Likelihood);
   fChain->SetBranchAddress("pibach_MC12TuneV2_ProbNNe", &pibach_MC12TuneV2_ProbNNe, &b_pibach_MC12TuneV2_ProbNNe);
   fChain->SetBranchAddress("pibach_MC12TuneV2_ProbNNmu", &pibach_MC12TuneV2_ProbNNmu, &b_pibach_MC12TuneV2_ProbNNmu);
   fChain->SetBranchAddress("pibach_MC12TuneV2_ProbNNpi", &pibach_MC12TuneV2_ProbNNpi, &b_pibach_MC12TuneV2_ProbNNpi);
   fChain->SetBranchAddress("pibach_MC12TuneV2_ProbNNk", &pibach_MC12TuneV2_ProbNNk, &b_pibach_MC12TuneV2_ProbNNk);
   fChain->SetBranchAddress("pibach_MC12TuneV2_ProbNNp", &pibach_MC12TuneV2_ProbNNp, &b_pibach_MC12TuneV2_ProbNNp);
   fChain->SetBranchAddress("pibach_MC12TuneV2_ProbNNghost", &pibach_MC12TuneV2_ProbNNghost, &b_pibach_MC12TuneV2_ProbNNghost);
   fChain->SetBranchAddress("pibach_MC12TuneV3_ProbNNe", &pibach_MC12TuneV3_ProbNNe, &b_pibach_MC12TuneV3_ProbNNe);
   fChain->SetBranchAddress("pibach_MC12TuneV3_ProbNNmu", &pibach_MC12TuneV3_ProbNNmu, &b_pibach_MC12TuneV3_ProbNNmu);
   fChain->SetBranchAddress("pibach_MC12TuneV3_ProbNNpi", &pibach_MC12TuneV3_ProbNNpi, &b_pibach_MC12TuneV3_ProbNNpi);
   fChain->SetBranchAddress("pibach_MC12TuneV3_ProbNNk", &pibach_MC12TuneV3_ProbNNk, &b_pibach_MC12TuneV3_ProbNNk);
   fChain->SetBranchAddress("pibach_MC12TuneV3_ProbNNp", &pibach_MC12TuneV3_ProbNNp, &b_pibach_MC12TuneV3_ProbNNp);
   fChain->SetBranchAddress("pibach_MC12TuneV3_ProbNNghost", &pibach_MC12TuneV3_ProbNNghost, &b_pibach_MC12TuneV3_ProbNNghost);
   fChain->SetBranchAddress("pibach_MC12TuneV4_ProbNNe", &pibach_MC12TuneV4_ProbNNe, &b_pibach_MC12TuneV4_ProbNNe);
   fChain->SetBranchAddress("pibach_MC12TuneV4_ProbNNmu", &pibach_MC12TuneV4_ProbNNmu, &b_pibach_MC12TuneV4_ProbNNmu);
   fChain->SetBranchAddress("pibach_MC12TuneV4_ProbNNpi", &pibach_MC12TuneV4_ProbNNpi, &b_pibach_MC12TuneV4_ProbNNpi);
   fChain->SetBranchAddress("pibach_MC12TuneV4_ProbNNk", &pibach_MC12TuneV4_ProbNNk, &b_pibach_MC12TuneV4_ProbNNk);
   fChain->SetBranchAddress("pibach_MC12TuneV4_ProbNNp", &pibach_MC12TuneV4_ProbNNp, &b_pibach_MC12TuneV4_ProbNNp);
   fChain->SetBranchAddress("pibach_MC12TuneV4_ProbNNghost", &pibach_MC12TuneV4_ProbNNghost, &b_pibach_MC12TuneV4_ProbNNghost);
   fChain->SetBranchAddress("pibach_MC15TuneV1_ProbNNe", &pibach_MC15TuneV1_ProbNNe, &b_pibach_MC15TuneV1_ProbNNe);
   fChain->SetBranchAddress("pibach_MC15TuneV1_ProbNNmu", &pibach_MC15TuneV1_ProbNNmu, &b_pibach_MC15TuneV1_ProbNNmu);
   fChain->SetBranchAddress("pibach_MC15TuneV1_ProbNNpi", &pibach_MC15TuneV1_ProbNNpi, &b_pibach_MC15TuneV1_ProbNNpi);
   fChain->SetBranchAddress("pibach_MC15TuneV1_ProbNNk", &pibach_MC15TuneV1_ProbNNk, &b_pibach_MC15TuneV1_ProbNNk);
   fChain->SetBranchAddress("pibach_MC15TuneV1_ProbNNp", &pibach_MC15TuneV1_ProbNNp, &b_pibach_MC15TuneV1_ProbNNp);
   fChain->SetBranchAddress("pibach_MC15TuneV1_ProbNNghost", &pibach_MC15TuneV1_ProbNNghost, &b_pibach_MC15TuneV1_ProbNNghost);
   fChain->SetBranchAddress("pibach_OWNPV_X", &pibach_OWNPV_X, &b_pibach_OWNPV_X);
   fChain->SetBranchAddress("pibach_OWNPV_Y", &pibach_OWNPV_Y, &b_pibach_OWNPV_Y);
   fChain->SetBranchAddress("pibach_OWNPV_Z", &pibach_OWNPV_Z, &b_pibach_OWNPV_Z);
   fChain->SetBranchAddress("pibach_OWNPV_XERR", &pibach_OWNPV_XERR, &b_pibach_OWNPV_XERR);
   fChain->SetBranchAddress("pibach_OWNPV_YERR", &pibach_OWNPV_YERR, &b_pibach_OWNPV_YERR);
   fChain->SetBranchAddress("pibach_OWNPV_ZERR", &pibach_OWNPV_ZERR, &b_pibach_OWNPV_ZERR);
   fChain->SetBranchAddress("pibach_OWNPV_CHI2", &pibach_OWNPV_CHI2, &b_pibach_OWNPV_CHI2);
   fChain->SetBranchAddress("pibach_OWNPV_NDOF", &pibach_OWNPV_NDOF, &b_pibach_OWNPV_NDOF);
   fChain->SetBranchAddress("pibach_OWNPV_COV_", pibach_OWNPV_COV_, &b_pibach_OWNPV_COV_);
   fChain->SetBranchAddress("pibach_IP_OWNPV", &pibach_IP_OWNPV, &b_pibach_IP_OWNPV);
   fChain->SetBranchAddress("pibach_IPCHI2_OWNPV", &pibach_IPCHI2_OWNPV, &b_pibach_IPCHI2_OWNPV);
   fChain->SetBranchAddress("pibach_ORIVX_X", &pibach_ORIVX_X, &b_pibach_ORIVX_X);
   fChain->SetBranchAddress("pibach_ORIVX_Y", &pibach_ORIVX_Y, &b_pibach_ORIVX_Y);
   fChain->SetBranchAddress("pibach_ORIVX_Z", &pibach_ORIVX_Z, &b_pibach_ORIVX_Z);
   fChain->SetBranchAddress("pibach_ORIVX_XERR", &pibach_ORIVX_XERR, &b_pibach_ORIVX_XERR);
   fChain->SetBranchAddress("pibach_ORIVX_YERR", &pibach_ORIVX_YERR, &b_pibach_ORIVX_YERR);
   fChain->SetBranchAddress("pibach_ORIVX_ZERR", &pibach_ORIVX_ZERR, &b_pibach_ORIVX_ZERR);
   fChain->SetBranchAddress("pibach_ORIVX_CHI2", &pibach_ORIVX_CHI2, &b_pibach_ORIVX_CHI2);
   fChain->SetBranchAddress("pibach_ORIVX_NDOF", &pibach_ORIVX_NDOF, &b_pibach_ORIVX_NDOF);
   fChain->SetBranchAddress("pibach_ORIVX_COV_", pibach_ORIVX_COV_, &b_pibach_ORIVX_COV_);
   fChain->SetBranchAddress("pibach_P", &pibach_P, &b_pibach_P);
   fChain->SetBranchAddress("pibach_PT", &pibach_PT, &b_pibach_PT);
   fChain->SetBranchAddress("pibach_PE", &pibach_PE, &b_pibach_PE);
   fChain->SetBranchAddress("pibach_PX", &pibach_PX, &b_pibach_PX);
   fChain->SetBranchAddress("pibach_PY", &pibach_PY, &b_pibach_PY);
   fChain->SetBranchAddress("pibach_PZ", &pibach_PZ, &b_pibach_PZ);
   fChain->SetBranchAddress("pibach_M", &pibach_M, &b_pibach_M);
   fChain->SetBranchAddress("pibach_TRUEID", &pibach_TRUEID, &b_pibach_TRUEID);
   fChain->SetBranchAddress("pibach_MC_MOTHER_ID", &pibach_MC_MOTHER_ID, &b_pibach_MC_MOTHER_ID);
   fChain->SetBranchAddress("pibach_MC_MOTHER_KEY", &pibach_MC_MOTHER_KEY, &b_pibach_MC_MOTHER_KEY);
   fChain->SetBranchAddress("pibach_MC_GD_MOTHER_ID", &pibach_MC_GD_MOTHER_ID, &b_pibach_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("pibach_MC_GD_MOTHER_KEY", &pibach_MC_GD_MOTHER_KEY, &b_pibach_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("pibach_MC_GD_GD_MOTHER_ID", &pibach_MC_GD_GD_MOTHER_ID, &b_pibach_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("pibach_MC_GD_GD_MOTHER_KEY", &pibach_MC_GD_GD_MOTHER_KEY, &b_pibach_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("pibach_TRUEP_E", &pibach_TRUEP_E, &b_pibach_TRUEP_E);
   fChain->SetBranchAddress("pibach_TRUEP_X", &pibach_TRUEP_X, &b_pibach_TRUEP_X);
   fChain->SetBranchAddress("pibach_TRUEP_Y", &pibach_TRUEP_Y, &b_pibach_TRUEP_Y);
   fChain->SetBranchAddress("pibach_TRUEP_Z", &pibach_TRUEP_Z, &b_pibach_TRUEP_Z);
   fChain->SetBranchAddress("pibach_TRUEPT", &pibach_TRUEPT, &b_pibach_TRUEPT);
   fChain->SetBranchAddress("pibach_TRUEORIGINVERTEX_X", &pibach_TRUEORIGINVERTEX_X, &b_pibach_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("pibach_TRUEORIGINVERTEX_Y", &pibach_TRUEORIGINVERTEX_Y, &b_pibach_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("pibach_TRUEORIGINVERTEX_Z", &pibach_TRUEORIGINVERTEX_Z, &b_pibach_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("pibach_TRUEENDVERTEX_X", &pibach_TRUEENDVERTEX_X, &b_pibach_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("pibach_TRUEENDVERTEX_Y", &pibach_TRUEENDVERTEX_Y, &b_pibach_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("pibach_TRUEENDVERTEX_Z", &pibach_TRUEENDVERTEX_Z, &b_pibach_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("pibach_TRUEISSTABLE", &pibach_TRUEISSTABLE, &b_pibach_TRUEISSTABLE);
   fChain->SetBranchAddress("pibach_TRUETAU", &pibach_TRUETAU, &b_pibach_TRUETAU);
   fChain->SetBranchAddress("pibach_ID", &pibach_ID, &b_pibach_ID);
   fChain->SetBranchAddress("pibach_PIDe", &pibach_PIDe, &b_pibach_PIDe);
   fChain->SetBranchAddress("pibach_PIDmu", &pibach_PIDmu, &b_pibach_PIDmu);
   fChain->SetBranchAddress("pibach_PIDK", &pibach_PIDK, &b_pibach_PIDK);
   fChain->SetBranchAddress("pibach_PIDp", &pibach_PIDp, &b_pibach_PIDp);
   fChain->SetBranchAddress("pibach_PIDd", &pibach_PIDd, &b_pibach_PIDd);
   fChain->SetBranchAddress("pibach_ProbNNe", &pibach_ProbNNe, &b_pibach_ProbNNe);
   fChain->SetBranchAddress("pibach_ProbNNk", &pibach_ProbNNk, &b_pibach_ProbNNk);
   fChain->SetBranchAddress("pibach_ProbNNp", &pibach_ProbNNp, &b_pibach_ProbNNp);
   fChain->SetBranchAddress("pibach_ProbNNpi", &pibach_ProbNNpi, &b_pibach_ProbNNpi);
   fChain->SetBranchAddress("pibach_ProbNNmu", &pibach_ProbNNmu, &b_pibach_ProbNNmu);
   fChain->SetBranchAddress("pibach_ProbNNd", &pibach_ProbNNd, &b_pibach_ProbNNd);
   fChain->SetBranchAddress("pibach_ProbNNghost", &pibach_ProbNNghost, &b_pibach_ProbNNghost);
   fChain->SetBranchAddress("pibach_hasMuon", &pibach_hasMuon, &b_pibach_hasMuon);
   fChain->SetBranchAddress("pibach_isMuon", &pibach_isMuon, &b_pibach_isMuon);
   fChain->SetBranchAddress("pibach_hasRich", &pibach_hasRich, &b_pibach_hasRich);
   fChain->SetBranchAddress("pibach_UsedRichAerogel", &pibach_UsedRichAerogel, &b_pibach_UsedRichAerogel);
   fChain->SetBranchAddress("pibach_UsedRich1Gas", &pibach_UsedRich1Gas, &b_pibach_UsedRich1Gas);
   fChain->SetBranchAddress("pibach_UsedRich2Gas", &pibach_UsedRich2Gas, &b_pibach_UsedRich2Gas);
   fChain->SetBranchAddress("pibach_RichAboveElThres", &pibach_RichAboveElThres, &b_pibach_RichAboveElThres);
   fChain->SetBranchAddress("pibach_RichAboveMuThres", &pibach_RichAboveMuThres, &b_pibach_RichAboveMuThres);
   fChain->SetBranchAddress("pibach_RichAbovePiThres", &pibach_RichAbovePiThres, &b_pibach_RichAbovePiThres);
   fChain->SetBranchAddress("pibach_RichAboveKaThres", &pibach_RichAboveKaThres, &b_pibach_RichAboveKaThres);
   fChain->SetBranchAddress("pibach_RichAbovePrThres", &pibach_RichAbovePrThres, &b_pibach_RichAbovePrThres);
   fChain->SetBranchAddress("pibach_hasCalo", &pibach_hasCalo, &b_pibach_hasCalo);
   fChain->SetBranchAddress("pibach_TRACK_Type", &pibach_TRACK_Type, &b_pibach_TRACK_Type);
   fChain->SetBranchAddress("pibach_TRACK_Key", &pibach_TRACK_Key, &b_pibach_TRACK_Key);
   fChain->SetBranchAddress("pibach_TRACK_CHI2NDOF", &pibach_TRACK_CHI2NDOF, &b_pibach_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("pibach_TRACK_PCHI2", &pibach_TRACK_PCHI2, &b_pibach_TRACK_PCHI2);
   fChain->SetBranchAddress("pibach_TRACK_MatchCHI2", &pibach_TRACK_MatchCHI2, &b_pibach_TRACK_MatchCHI2);
   fChain->SetBranchAddress("pibach_TRACK_GhostProb", &pibach_TRACK_GhostProb, &b_pibach_TRACK_GhostProb);
   fChain->SetBranchAddress("pibach_TRACK_CloneDist", &pibach_TRACK_CloneDist, &b_pibach_TRACK_CloneDist);
   fChain->SetBranchAddress("pibach_TRACK_Likelihood", &pibach_TRACK_Likelihood, &b_pibach_TRACK_Likelihood);
   fChain->SetBranchAddress("Kbach_MC12TuneV2_ProbNNe", &Kbach_MC12TuneV2_ProbNNe, &b_Kbach_MC12TuneV2_ProbNNe);
   fChain->SetBranchAddress("Kbach_MC12TuneV2_ProbNNmu", &Kbach_MC12TuneV2_ProbNNmu, &b_Kbach_MC12TuneV2_ProbNNmu);
   fChain->SetBranchAddress("Kbach_MC12TuneV2_ProbNNpi", &Kbach_MC12TuneV2_ProbNNpi, &b_Kbach_MC12TuneV2_ProbNNpi);
   fChain->SetBranchAddress("Kbach_MC12TuneV2_ProbNNk", &Kbach_MC12TuneV2_ProbNNk, &b_Kbach_MC12TuneV2_ProbNNk);
   fChain->SetBranchAddress("Kbach_MC12TuneV2_ProbNNp", &Kbach_MC12TuneV2_ProbNNp, &b_Kbach_MC12TuneV2_ProbNNp);
   fChain->SetBranchAddress("Kbach_MC12TuneV2_ProbNNghost", &Kbach_MC12TuneV2_ProbNNghost, &b_Kbach_MC12TuneV2_ProbNNghost);
   fChain->SetBranchAddress("Kbach_MC12TuneV3_ProbNNe", &Kbach_MC12TuneV3_ProbNNe, &b_Kbach_MC12TuneV3_ProbNNe);
   fChain->SetBranchAddress("Kbach_MC12TuneV3_ProbNNmu", &Kbach_MC12TuneV3_ProbNNmu, &b_Kbach_MC12TuneV3_ProbNNmu);
   fChain->SetBranchAddress("Kbach_MC12TuneV3_ProbNNpi", &Kbach_MC12TuneV3_ProbNNpi, &b_Kbach_MC12TuneV3_ProbNNpi);
   fChain->SetBranchAddress("Kbach_MC12TuneV3_ProbNNk", &Kbach_MC12TuneV3_ProbNNk, &b_Kbach_MC12TuneV3_ProbNNk);
   fChain->SetBranchAddress("Kbach_MC12TuneV3_ProbNNp", &Kbach_MC12TuneV3_ProbNNp, &b_Kbach_MC12TuneV3_ProbNNp);
   fChain->SetBranchAddress("Kbach_MC12TuneV3_ProbNNghost", &Kbach_MC12TuneV3_ProbNNghost, &b_Kbach_MC12TuneV3_ProbNNghost);
   fChain->SetBranchAddress("Kbach_MC12TuneV4_ProbNNe", &Kbach_MC12TuneV4_ProbNNe, &b_Kbach_MC12TuneV4_ProbNNe);
   fChain->SetBranchAddress("Kbach_MC12TuneV4_ProbNNmu", &Kbach_MC12TuneV4_ProbNNmu, &b_Kbach_MC12TuneV4_ProbNNmu);
   fChain->SetBranchAddress("Kbach_MC12TuneV4_ProbNNpi", &Kbach_MC12TuneV4_ProbNNpi, &b_Kbach_MC12TuneV4_ProbNNpi);
   fChain->SetBranchAddress("Kbach_MC12TuneV4_ProbNNk", &Kbach_MC12TuneV4_ProbNNk, &b_Kbach_MC12TuneV4_ProbNNk);
   fChain->SetBranchAddress("Kbach_MC12TuneV4_ProbNNp", &Kbach_MC12TuneV4_ProbNNp, &b_Kbach_MC12TuneV4_ProbNNp);
   fChain->SetBranchAddress("Kbach_MC12TuneV4_ProbNNghost", &Kbach_MC12TuneV4_ProbNNghost, &b_Kbach_MC12TuneV4_ProbNNghost);
   fChain->SetBranchAddress("Kbach_MC15TuneV1_ProbNNe", &Kbach_MC15TuneV1_ProbNNe, &b_Kbach_MC15TuneV1_ProbNNe);
   fChain->SetBranchAddress("Kbach_MC15TuneV1_ProbNNmu", &Kbach_MC15TuneV1_ProbNNmu, &b_Kbach_MC15TuneV1_ProbNNmu);
   fChain->SetBranchAddress("Kbach_MC15TuneV1_ProbNNpi", &Kbach_MC15TuneV1_ProbNNpi, &b_Kbach_MC15TuneV1_ProbNNpi);
   fChain->SetBranchAddress("Kbach_MC15TuneV1_ProbNNk", &Kbach_MC15TuneV1_ProbNNk, &b_Kbach_MC15TuneV1_ProbNNk);
   fChain->SetBranchAddress("Kbach_MC15TuneV1_ProbNNp", &Kbach_MC15TuneV1_ProbNNp, &b_Kbach_MC15TuneV1_ProbNNp);
   fChain->SetBranchAddress("Kbach_MC15TuneV1_ProbNNghost", &Kbach_MC15TuneV1_ProbNNghost, &b_Kbach_MC15TuneV1_ProbNNghost);
   fChain->SetBranchAddress("Kbach_OWNPV_X", &Kbach_OWNPV_X, &b_Kbach_OWNPV_X);
   fChain->SetBranchAddress("Kbach_OWNPV_Y", &Kbach_OWNPV_Y, &b_Kbach_OWNPV_Y);
   fChain->SetBranchAddress("Kbach_OWNPV_Z", &Kbach_OWNPV_Z, &b_Kbach_OWNPV_Z);
   fChain->SetBranchAddress("Kbach_OWNPV_XERR", &Kbach_OWNPV_XERR, &b_Kbach_OWNPV_XERR);
   fChain->SetBranchAddress("Kbach_OWNPV_YERR", &Kbach_OWNPV_YERR, &b_Kbach_OWNPV_YERR);
   fChain->SetBranchAddress("Kbach_OWNPV_ZERR", &Kbach_OWNPV_ZERR, &b_Kbach_OWNPV_ZERR);
   fChain->SetBranchAddress("Kbach_OWNPV_CHI2", &Kbach_OWNPV_CHI2, &b_Kbach_OWNPV_CHI2);
   fChain->SetBranchAddress("Kbach_OWNPV_NDOF", &Kbach_OWNPV_NDOF, &b_Kbach_OWNPV_NDOF);
   fChain->SetBranchAddress("Kbach_OWNPV_COV_", Kbach_OWNPV_COV_, &b_Kbach_OWNPV_COV_);
   fChain->SetBranchAddress("Kbach_IP_OWNPV", &Kbach_IP_OWNPV, &b_Kbach_IP_OWNPV);
   fChain->SetBranchAddress("Kbach_IPCHI2_OWNPV", &Kbach_IPCHI2_OWNPV, &b_Kbach_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Kbach_ORIVX_X", &Kbach_ORIVX_X, &b_Kbach_ORIVX_X);
   fChain->SetBranchAddress("Kbach_ORIVX_Y", &Kbach_ORIVX_Y, &b_Kbach_ORIVX_Y);
   fChain->SetBranchAddress("Kbach_ORIVX_Z", &Kbach_ORIVX_Z, &b_Kbach_ORIVX_Z);
   fChain->SetBranchAddress("Kbach_ORIVX_XERR", &Kbach_ORIVX_XERR, &b_Kbach_ORIVX_XERR);
   fChain->SetBranchAddress("Kbach_ORIVX_YERR", &Kbach_ORIVX_YERR, &b_Kbach_ORIVX_YERR);
   fChain->SetBranchAddress("Kbach_ORIVX_ZERR", &Kbach_ORIVX_ZERR, &b_Kbach_ORIVX_ZERR);
   fChain->SetBranchAddress("Kbach_ORIVX_CHI2", &Kbach_ORIVX_CHI2, &b_Kbach_ORIVX_CHI2);
   fChain->SetBranchAddress("Kbach_ORIVX_NDOF", &Kbach_ORIVX_NDOF, &b_Kbach_ORIVX_NDOF);
   fChain->SetBranchAddress("Kbach_ORIVX_COV_", Kbach_ORIVX_COV_, &b_Kbach_ORIVX_COV_);
   fChain->SetBranchAddress("Kbach_P", &Kbach_P, &b_Kbach_P);
   fChain->SetBranchAddress("Kbach_PT", &Kbach_PT, &b_Kbach_PT);
   fChain->SetBranchAddress("Kbach_PE", &Kbach_PE, &b_Kbach_PE);
   fChain->SetBranchAddress("Kbach_PX", &Kbach_PX, &b_Kbach_PX);
   fChain->SetBranchAddress("Kbach_PY", &Kbach_PY, &b_Kbach_PY);
   fChain->SetBranchAddress("Kbach_PZ", &Kbach_PZ, &b_Kbach_PZ);
   fChain->SetBranchAddress("Kbach_M", &Kbach_M, &b_Kbach_M);
   fChain->SetBranchAddress("Kbach_TRUEID", &Kbach_TRUEID, &b_Kbach_TRUEID);
   fChain->SetBranchAddress("Kbach_MC_MOTHER_ID", &Kbach_MC_MOTHER_ID, &b_Kbach_MC_MOTHER_ID);
   fChain->SetBranchAddress("Kbach_MC_MOTHER_KEY", &Kbach_MC_MOTHER_KEY, &b_Kbach_MC_MOTHER_KEY);
   fChain->SetBranchAddress("Kbach_MC_GD_MOTHER_ID", &Kbach_MC_GD_MOTHER_ID, &b_Kbach_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("Kbach_MC_GD_MOTHER_KEY", &Kbach_MC_GD_MOTHER_KEY, &b_Kbach_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Kbach_MC_GD_GD_MOTHER_ID", &Kbach_MC_GD_GD_MOTHER_ID, &b_Kbach_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("Kbach_MC_GD_GD_MOTHER_KEY", &Kbach_MC_GD_GD_MOTHER_KEY, &b_Kbach_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Kbach_TRUEP_E", &Kbach_TRUEP_E, &b_Kbach_TRUEP_E);
   fChain->SetBranchAddress("Kbach_TRUEP_X", &Kbach_TRUEP_X, &b_Kbach_TRUEP_X);
   fChain->SetBranchAddress("Kbach_TRUEP_Y", &Kbach_TRUEP_Y, &b_Kbach_TRUEP_Y);
   fChain->SetBranchAddress("Kbach_TRUEP_Z", &Kbach_TRUEP_Z, &b_Kbach_TRUEP_Z);
   fChain->SetBranchAddress("Kbach_TRUEPT", &Kbach_TRUEPT, &b_Kbach_TRUEPT);
   fChain->SetBranchAddress("Kbach_TRUEORIGINVERTEX_X", &Kbach_TRUEORIGINVERTEX_X, &b_Kbach_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("Kbach_TRUEORIGINVERTEX_Y", &Kbach_TRUEORIGINVERTEX_Y, &b_Kbach_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("Kbach_TRUEORIGINVERTEX_Z", &Kbach_TRUEORIGINVERTEX_Z, &b_Kbach_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("Kbach_TRUEENDVERTEX_X", &Kbach_TRUEENDVERTEX_X, &b_Kbach_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("Kbach_TRUEENDVERTEX_Y", &Kbach_TRUEENDVERTEX_Y, &b_Kbach_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("Kbach_TRUEENDVERTEX_Z", &Kbach_TRUEENDVERTEX_Z, &b_Kbach_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("Kbach_TRUEISSTABLE", &Kbach_TRUEISSTABLE, &b_Kbach_TRUEISSTABLE);
   fChain->SetBranchAddress("Kbach_TRUETAU", &Kbach_TRUETAU, &b_Kbach_TRUETAU);
   fChain->SetBranchAddress("Kbach_ID", &Kbach_ID, &b_Kbach_ID);
   fChain->SetBranchAddress("Kbach_PIDe", &Kbach_PIDe, &b_Kbach_PIDe);
   fChain->SetBranchAddress("Kbach_PIDmu", &Kbach_PIDmu, &b_Kbach_PIDmu);
   fChain->SetBranchAddress("Kbach_PIDK", &Kbach_PIDK, &b_Kbach_PIDK);
   fChain->SetBranchAddress("Kbach_PIDp", &Kbach_PIDp, &b_Kbach_PIDp);
   fChain->SetBranchAddress("Kbach_PIDd", &Kbach_PIDd, &b_Kbach_PIDd);
   fChain->SetBranchAddress("Kbach_ProbNNe", &Kbach_ProbNNe, &b_Kbach_ProbNNe);
   fChain->SetBranchAddress("Kbach_ProbNNk", &Kbach_ProbNNk, &b_Kbach_ProbNNk);
   fChain->SetBranchAddress("Kbach_ProbNNp", &Kbach_ProbNNp, &b_Kbach_ProbNNp);
   fChain->SetBranchAddress("Kbach_ProbNNpi", &Kbach_ProbNNpi, &b_Kbach_ProbNNpi);
   fChain->SetBranchAddress("Kbach_ProbNNmu", &Kbach_ProbNNmu, &b_Kbach_ProbNNmu);
   fChain->SetBranchAddress("Kbach_ProbNNd", &Kbach_ProbNNd, &b_Kbach_ProbNNd);
   fChain->SetBranchAddress("Kbach_ProbNNghost", &Kbach_ProbNNghost, &b_Kbach_ProbNNghost);
   fChain->SetBranchAddress("Kbach_hasMuon", &Kbach_hasMuon, &b_Kbach_hasMuon);
   fChain->SetBranchAddress("Kbach_isMuon", &Kbach_isMuon, &b_Kbach_isMuon);
   fChain->SetBranchAddress("Kbach_hasRich", &Kbach_hasRich, &b_Kbach_hasRich);
   fChain->SetBranchAddress("Kbach_UsedRichAerogel", &Kbach_UsedRichAerogel, &b_Kbach_UsedRichAerogel);
   fChain->SetBranchAddress("Kbach_UsedRich1Gas", &Kbach_UsedRich1Gas, &b_Kbach_UsedRich1Gas);
   fChain->SetBranchAddress("Kbach_UsedRich2Gas", &Kbach_UsedRich2Gas, &b_Kbach_UsedRich2Gas);
   fChain->SetBranchAddress("Kbach_RichAboveElThres", &Kbach_RichAboveElThres, &b_Kbach_RichAboveElThres);
   fChain->SetBranchAddress("Kbach_RichAboveMuThres", &Kbach_RichAboveMuThres, &b_Kbach_RichAboveMuThres);
   fChain->SetBranchAddress("Kbach_RichAbovePiThres", &Kbach_RichAbovePiThres, &b_Kbach_RichAbovePiThres);
   fChain->SetBranchAddress("Kbach_RichAboveKaThres", &Kbach_RichAboveKaThres, &b_Kbach_RichAboveKaThres);
   fChain->SetBranchAddress("Kbach_RichAbovePrThres", &Kbach_RichAbovePrThres, &b_Kbach_RichAbovePrThres);
   fChain->SetBranchAddress("Kbach_hasCalo", &Kbach_hasCalo, &b_Kbach_hasCalo);
   fChain->SetBranchAddress("Kbach_TRACK_Type", &Kbach_TRACK_Type, &b_Kbach_TRACK_Type);
   fChain->SetBranchAddress("Kbach_TRACK_Key", &Kbach_TRACK_Key, &b_Kbach_TRACK_Key);
   fChain->SetBranchAddress("Kbach_TRACK_CHI2NDOF", &Kbach_TRACK_CHI2NDOF, &b_Kbach_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("Kbach_TRACK_PCHI2", &Kbach_TRACK_PCHI2, &b_Kbach_TRACK_PCHI2);
   fChain->SetBranchAddress("Kbach_TRACK_MatchCHI2", &Kbach_TRACK_MatchCHI2, &b_Kbach_TRACK_MatchCHI2);
   fChain->SetBranchAddress("Kbach_TRACK_GhostProb", &Kbach_TRACK_GhostProb, &b_Kbach_TRACK_GhostProb);
   fChain->SetBranchAddress("Kbach_TRACK_CloneDist", &Kbach_TRACK_CloneDist, &b_Kbach_TRACK_CloneDist);
   fChain->SetBranchAddress("Kbach_TRACK_Likelihood", &Kbach_TRACK_Likelihood, &b_Kbach_TRACK_Likelihood);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
   fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
   fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
   fChain->SetBranchAddress("HLT1TCK", &HLT1TCK, &b_HLT1TCK);
   fChain->SetBranchAddress("HLT2TCK", &HLT2TCK, &b_HLT2TCK);
   fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
   fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVX", PVX, &b_PVX);
   fChain->SetBranchAddress("PVY", PVY, &b_PVY);
   fChain->SetBranchAddress("PVZ", PVZ, &b_PVZ);
   fChain->SetBranchAddress("PVXERR", PVXERR, &b_PVXERR);
   fChain->SetBranchAddress("PVYERR", PVYERR, &b_PVYERR);
   fChain->SetBranchAddress("PVZERR", PVZERR, &b_PVZERR);
   fChain->SetBranchAddress("PVCHI2", PVCHI2, &b_PVCHI2);
   fChain->SetBranchAddress("PVNDOF", PVNDOF, &b_PVNDOF);
   fChain->SetBranchAddress("PVNTRACKS", PVNTRACKS, &b_PVNTRACKS);
   fChain->SetBranchAddress("Lc_bdtg", &Lc_bdtg, &b_bdtg);
   Notify();
}

Bool_t DecayTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DecayTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DecayTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DecayTree_cxx
