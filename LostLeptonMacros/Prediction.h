//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct 24 09:51:04 2014 by ROOT version 5.34/04
// from TTree RA2PreSelection/RA2PreSelection
// found on file: /nfs/dust/cms/user/adraeger/CSA2014/mc/wjetHT600-Inf.root
//////////////////////////////////////////////////////////

#ifndef Prediction_h
#define Prediction_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH2F.h>
#include <TH1F.h>
#include "TVector2.h"
#include <cmath>
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
// use gen infomation to fix purityy of muon controlsample
const bool useGenInfoToMatchCSMuonToGen_=1;
const double maxDeltaRGenToRecoIsoMuon_=0.3;
const double maxDiffPtGenToRecoIsoMuon_=0.3;
const double minHT_=350;
const double minMHT_=100;
const double minNJets_=1.9;
const double deltaPhi1_=0.5;
const double deltaPhi2_=0.5;
const double deltaPhi3_=0.3;
const bool applyFilters_=false;

const UShort_t NJetsLow_=2;
const UShort_t NJetsMedium_=5;
const UShort_t NJetsMedium2_=7;
const UShort_t NJetsHigh_=8;

// uncertainties
const double MuAccUncertaintyDown_ = 9;  // pdf


class Prediction : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   void resetValues();
   bool FiltersPass();
   double deltaR(double eta1, double phi1, double eta2, double phi2);
   double MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi);
   double effUp(double eff, double up);
   double effDown(double eff, double down);
   // output variables
   bool useGenInfoToMatchCSMuonToGen; Float_t deltaRGenToRecoIsoMuon_, diffPtGenToRecoIsoMuon_;
   UShort_t Matched_;
   TTree *tPrediction_;
   Float_t mtw;
   Float_t muIsoEff_, muIsoEffError_, muIsoWeight_, muIsoWeightErrorUp_, muIsoWeightErrorDown_;
   Float_t muRecoEff_, muRecoEffError_, muRecoWeight_, muRecoWeightErrorUp_, muRecoWeightErrorDown_;
   Float_t muAccEff_, muAccEffError_, muAccWeight_, muAccWeightErrorUp_, muAccWeightErrorDown_;
   Float_t muTotalWeight_, totalMuons_, totalMuonsMTW_;
   
   Float_t elecIsoEff_, elecIsoEffError_, elecIsoWeight_, elecIsoWeightErrorUp_, elecIsoWeightErrorDown_;
   Float_t elecRecoEff_, elecRecoEffError_, elecRecoWeight_, elecRecoWeightErrorUp_, elecRecoWeightErrorDown_;
   Float_t elecAccEff_, elecAccEffError_, elecAccWeight_, elecAccWeightErrorUp_, elecAccWeightErrorDown_;
   Float_t elecTotalWeight_;
   
   Float_t totalWeight_, totalWeightMTW_, totalWeightMTWDiLep_;
   Float_t muIsoUp_, muIsoDown_, muAccUp_, muAccDown_, elecAccUp_, elecAccDown_, totalWeightMTWDiLepDiBosonDown_, totalWeightMTWDiLepDiNonCloUp_, totalWeightMTWDiLepDiNonCloDown_;
   // TH2F efficiencies
   TH2F *MuonIsoLow_, *MuonIso0_, *MuonIso1_, *MuonIso2_; 
   TH2F *MuonRecoLow_, *MuonReco0_, *MuonReco1_, *MuonReco2_; 
   TH2F *MuonAcc_;
   TH1F *MuMTWNJet_;
   TH2F *MuMTWMHTNJet_;
   TH2F *ElecIsoLow_, *ElecIso0_, *ElecIso1_, *ElecIso2_; 
   TH2F *ElecRecoLow_, *ElecReco0_, *ElecReco1_, *ElecReco2_; 
   TH2F *ElecAcc_;
   TH1F *ElecMTWNJet_;
   TH2F *ElecMTWMHTNJet_;
   TH2F *MuonPurityMHTNJet_, *ElecPurityMHTNJet_;
   // Declaration of leaf types
   UInt_t          RunNum;
   UInt_t          LumiBlockNum;
   UInt_t          EvtNum;
   UShort_t        NVtx;
   Float_t         WeightProducer;
   Float_t         HT;
   Float_t         MHT;
   Float_t         MHTEta;
   Float_t         MHTPhi;
   UShort_t        NJets;
   UShort_t        BTags;
   UShort_t        Leptons;
   Float_t         METPt;
   Float_t         METEta;
   Float_t         METPhi;
   Float_t         Jet1Pt;
   Float_t         Jet2Pt;
   Float_t         Jet3Pt;
   Float_t         Jet1Eta;
   Float_t         Jet2Eta;
   Float_t         Jet3Eta;
   Float_t         DeltaPhi1;
   Float_t         DeltaPhi2;
   Float_t         DeltaPhi3;
   Float_t         ak4HT;
   Float_t         ak4MHT;
   UShort_t        ak4NJets;
   UShort_t        ak4BTags;
   Float_t         ak4Jet1Pt;
   Float_t         ak4Jet2Pt;
   Float_t         ak4Jet3Pt;
   Float_t         ak4Jet1Eta;
   Float_t         ak4Jet2Eta;
   Float_t         ak4Jet3Eta;
   Float_t         ak4DeltaPhi1;
   Float_t         ak4DeltaPhi2;
   Float_t         ak4DeltaPhi3;
   UShort_t        ak4Num;
   Float_t         ak4Pt[53];   //[ak4Num]
   Float_t         ak4Eta[53];   //[ak4Num]
   Float_t         ak4Phi[53];   //[ak4Num]
   Float_t         ak4E[53];   //[ak4Num]
   Float_t         ak4BTagValue[53];   //[ak4Num]
   UShort_t        ak4BTag[53];   //[ak4Num]
   UShort_t        RecoIsoMuonNum;
   Float_t         RecoIsoMuonPt[3];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonEta[3];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonPhi[3];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonE[3];   //[RecoIsoMuonNum]
   UShort_t        RecoMuonNum;
   Float_t         RecoMuonPt[6];   //[RecoMuonNum]
   Float_t         RecoMuonEta[6];   //[RecoMuonNum]
   Float_t         RecoMuonPhi[6];   //[RecoMuonNum]
   Float_t         RecoMuonE[6];   //[RecoMuonNum]
   UShort_t        RecoIsoElecNum;
   Float_t         RecoIsoElecPt[4];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecEta[4];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecPhi[4];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecE[4];   //[RecoIsoElecNum]
   UShort_t        RecoElecNum;
   Float_t         RecoElecPt[9];   //[RecoElecNum]
   Float_t         RecoElecEta[9];   //[RecoElecNum]
   Float_t         RecoElecPhi[9];   //[RecoElecNum]
   Float_t         RecoElecE[9];   //[RecoElecNum]
   UShort_t        GenWNum;
   Float_t         GenWPt[1];   //[GenWNum]
   Float_t         GenWEta[1];   //[GenWNum]
   Float_t         GenWPhi[1];   //[GenWNum]
   UShort_t        GenMuNum;
   UShort_t        GenMuFromTau[1];   //[GenMuNum]
   Float_t         GenMuPt[1];   //[GenMuNum]
   Float_t         GenMuEta[1];   //[GenMuNum]
   Float_t         GenMuPhi[1];   //[GenMuNum]
   UShort_t        GenElecNum;
   UShort_t        GenElecFromTau[1];   //[GenElecNum]
   Float_t         GenElecPt[1];   //[GenElecNum]
   Float_t         GenElecEta[1];   //[GenElecNum]
   Float_t         GenElecPhi[1];   //[GenElecNum]
   UShort_t        GenTauNum;
   Float_t         GenTauPt[1];   //[GenTauNum]
   Float_t         GenTauEta[1];   //[GenTauNum]
   Float_t         GenTauPhi[1];   //[GenTauNum]
   Float_t         genHT;
   Float_t         genMHT;
   UShort_t        genNJets;
   Float_t         genJet1Pt;
   Float_t         genJet2Pt;
   Float_t         genJet3Pt;
   Float_t         genJet1Eta;
   Float_t         genJet2Eta;
   Float_t         genJet3Eta;
   Float_t         genDeltaPhi1;
   Float_t         genDeltaPhi2;
   Float_t         genDeltaPhi3;
   UChar_t         Filter_HBHENoiseFilterRA2;
   UChar_t         Filter_beamHaloFilter;
   UChar_t         Filter_eeNoiseFilter;
   UChar_t         Filter_trackingFailureFilter;
   UChar_t         Filter_inconsistentMuons;
   UChar_t         Filter_greedyMuons;
   UChar_t         Filter_ra2EcalTPFilter;
   UChar_t         Filter_ra2EcalBEFilter;
   UChar_t         Filter_hcalLaserEventFilter;
   UChar_t         Filter_ecalLaserCorrFilter;
   UChar_t         Filter_eeBadScFilter;
   UChar_t         Filter_PBNRFilter;
   UChar_t         Filter_HCALLaserEvtFilterList2012;
   UChar_t         Filter_manystripclus53X;
   UChar_t         Filter_toomanystripclus53X;
   UChar_t         Filter_logErrorTooManyClusters;
   UChar_t         Filter_RA2HONoiseFilter;

   // List of branches
   TBranch        *b_RunNum;   //!
   TBranch        *b_LumiBlockNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_WeightProducer;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_MHTEta;   //!
   TBranch        *b_MHTPhi;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_BTags;   //!
   TBranch        *b_Leptons;   //!
   TBranch        *b_METPt;   //!
   TBranch        *b_METEta;   //!
   TBranch        *b_METPhi;   //!
   TBranch        *b_Jet1Pt;   //!
   TBranch        *b_Jet2Pt;   //!
   TBranch        *b_Jet3Pt;   //!
   TBranch        *b_Jet1Eta;   //!
   TBranch        *b_Jet2Eta;   //!
   TBranch        *b_Jet3Eta;   //!
   TBranch        *b_DeltaPhi1;   //!
   TBranch        *b_DeltaPhi2;   //!
   TBranch        *b_DeltaPhi3;   //!
   TBranch        *b_ak4HT;   //!
   TBranch        *b_ak4MHT;   //!
   TBranch        *b_ak4NJets;   //!
   TBranch        *b_ak4BTags;   //!
   TBranch        *b_ak4Jet1Pt;   //!
   TBranch        *b_ak4Jet2Pt;   //!
   TBranch        *b_ak4Jet3Pt;   //!
   TBranch        *b_ak4Jet1Eta;   //!
   TBranch        *b_ak4Jet2Eta;   //!
   TBranch        *b_ak4Jet3Eta;   //!
   TBranch        *b_ak4DeltaPhi1;   //!
   TBranch        *b_ak4DeltaPhi2;   //!
   TBranch        *b_ak4DeltaPhi3;   //!
   TBranch        *b_ak4Num;   //!
   TBranch        *b_ak4Pt;   //!
   TBranch        *b_ak4Eta;   //!
   TBranch        *b_ak4Phi;   //!
   TBranch        *b_ak4E;   //!
   TBranch        *b_ak4BTagValue;   //!
   TBranch        *b_ak4BTag;   //!
   TBranch        *b_RecoIsoMuonNum;   //!
   TBranch        *b_RecoIsoMuonPt;   //!
   TBranch        *b_RecoIsoMuonEta;   //!
   TBranch        *b_RecoIsoMuonPhi;   //!
   TBranch        *b_RecoIsoMuonE;   //!
   TBranch        *b_RecoMuonNum;   //!
   TBranch        *b_RecoMuonPt;   //!
   TBranch        *b_RecoMuonEta;   //!
   TBranch        *b_RecoMuonPhi;   //!
   TBranch        *b_RecoMuonE;   //!
   TBranch        *b_RecoIsoElecNum;   //!
   TBranch        *b_RecoIsoElecPt;   //!
   TBranch        *b_RecoIsoElecEta;   //!
   TBranch        *b_RecoIsoElecPhi;   //!
   TBranch        *b_RecoIsoElecE;   //!
   TBranch        *b_RecoElecNum;   //!
   TBranch        *b_RecoElecPt;   //!
   TBranch        *b_RecoElecEta;   //!
   TBranch        *b_RecoElecPhi;   //!
   TBranch        *b_RecoElecE;   //!
   TBranch        *b_GenWNum;   //!
   TBranch        *b_GenWPt;   //!
   TBranch        *b_GenWEta;   //!
   TBranch        *b_GenWPhi;   //!
   TBranch        *b_GenMuNum;   //!
   TBranch        *b_GenMuFromTau;   //!
   TBranch        *b_GenMuPt;   //!
   TBranch        *b_GenMuEta;   //!
   TBranch        *b_GenMuPhi;   //!
   TBranch        *b_GenElecNum;   //!
   TBranch        *b_GenElecFromTau;   //!
   TBranch        *b_GenElecPt;   //!
   TBranch        *b_GenElecEta;   //!
   TBranch        *b_GenElecPhi;   //!
   TBranch        *b_GenTauNum;   //!
   TBranch        *b_GenTauPt;   //!
   TBranch        *b_GenTauEta;   //!
   TBranch        *b_GenTauPhi;   //!
   TBranch        *b_genHT;   //!
   TBranch        *b_genMHT;   //!
   TBranch        *b_genNJets;   //!
   TBranch        *b_genJet1Pt;   //!
   TBranch        *b_genJet2Pt;   //!
   TBranch        *b_genJet3Pt;   //!
   TBranch        *b_genJet1Eta;   //!
   TBranch        *b_genJet2Eta;   //!
   TBranch        *b_genJet3Eta;   //!
   TBranch        *b_genDeltaPhi1;   //!
   TBranch        *b_genDeltaPhi2;   //!
   TBranch        *b_genDeltaPhi3;   //!
   TBranch        *b_Filter_HBHENoiseFilterRA2;   //!
   TBranch        *b_Filter_beamHaloFilter;   //!
   TBranch        *b_Filter_eeNoiseFilter;   //!
   TBranch        *b_Filter_trackingFailureFilter;   //!
   TBranch        *b_Filter_inconsistentMuons;   //!
   TBranch        *b_Filter_greedyMuons;   //!
   TBranch        *b_Filter_ra2EcalTPFilter;   //!
   TBranch        *b_Filter_ra2EcalBEFilter;   //!
   TBranch        *b_Filter_hcalLaserEventFilter;   //!
   TBranch        *b_Filter_ecalLaserCorrFilter;   //!
   TBranch        *b_Filter_eeBadScFilter;   //!
   TBranch        *b_Filter_PBNRFilter;   //!
   TBranch        *b_Filter_HCALLaserEvtFilterList2012;   //!
   TBranch        *b_Filter_manystripclus53X;   //!
   TBranch        *b_Filter_toomanystripclus53X;   //!
   TBranch        *b_Filter_logErrorTooManyClusters;   //!
   TBranch        *b_Filter_RA2HONoiseFilter;   //!

   Prediction(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~Prediction() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(Prediction,0);
};

#endif

#ifdef Prediction_cxx
void Prediction::Init(TTree *tree)
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
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("WeightProducer", &WeightProducer, &b_WeightProducer);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("MHTEta", &MHTEta, &b_MHTEta);
   fChain->SetBranchAddress("MHTPhi", &MHTPhi, &b_MHTPhi);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
   fChain->SetBranchAddress("Leptons", &Leptons, &b_Leptons);
   fChain->SetBranchAddress("METPt", &METPt, &b_METPt);
   fChain->SetBranchAddress("METEta", &METEta, &b_METEta);
   fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
   fChain->SetBranchAddress("Jet1Pt", &Jet1Pt, &b_Jet1Pt);
   fChain->SetBranchAddress("Jet2Pt", &Jet2Pt, &b_Jet2Pt);
   fChain->SetBranchAddress("Jet3Pt", &Jet3Pt, &b_Jet3Pt);
   fChain->SetBranchAddress("Jet1Eta", &Jet1Eta, &b_Jet1Eta);
   fChain->SetBranchAddress("Jet2Eta", &Jet2Eta, &b_Jet2Eta);
   fChain->SetBranchAddress("Jet3Eta", &Jet3Eta, &b_Jet3Eta);
   fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
   fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
   fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
   fChain->SetBranchAddress("ak4HT", &ak4HT, &b_ak4HT);
   fChain->SetBranchAddress("ak4MHT", &ak4MHT, &b_ak4MHT);
   fChain->SetBranchAddress("ak4NJets", &ak4NJets, &b_ak4NJets);
   fChain->SetBranchAddress("ak4BTags", &ak4BTags, &b_ak4BTags);
   fChain->SetBranchAddress("ak4Jet1Pt", &ak4Jet1Pt, &b_ak4Jet1Pt);
   fChain->SetBranchAddress("ak4Jet2Pt", &ak4Jet2Pt, &b_ak4Jet2Pt);
   fChain->SetBranchAddress("ak4Jet3Pt", &ak4Jet3Pt, &b_ak4Jet3Pt);
   fChain->SetBranchAddress("ak4Jet1Eta", &ak4Jet1Eta, &b_ak4Jet1Eta);
   fChain->SetBranchAddress("ak4Jet2Eta", &ak4Jet2Eta, &b_ak4Jet2Eta);
   fChain->SetBranchAddress("ak4Jet3Eta", &ak4Jet3Eta, &b_ak4Jet3Eta);
   fChain->SetBranchAddress("ak4DeltaPhi1", &ak4DeltaPhi1, &b_ak4DeltaPhi1);
   fChain->SetBranchAddress("ak4DeltaPhi2", &ak4DeltaPhi2, &b_ak4DeltaPhi2);
   fChain->SetBranchAddress("ak4DeltaPhi3", &ak4DeltaPhi3, &b_ak4DeltaPhi3);
   fChain->SetBranchAddress("ak4Num", &ak4Num, &b_ak4Num);
   fChain->SetBranchAddress("ak4Pt", ak4Pt, &b_ak4Pt);
   fChain->SetBranchAddress("ak4Eta", ak4Eta, &b_ak4Eta);
   fChain->SetBranchAddress("ak4Phi", ak4Phi, &b_ak4Phi);
   fChain->SetBranchAddress("ak4E", ak4E, &b_ak4E);
   fChain->SetBranchAddress("ak4BTagValue", ak4BTagValue, &b_ak4BTagValue);
   fChain->SetBranchAddress("ak4BTag", ak4BTag, &b_ak4BTag);
   fChain->SetBranchAddress("RecoIsoMuonNum", &RecoIsoMuonNum, &b_RecoIsoMuonNum);
   fChain->SetBranchAddress("RecoIsoMuonPt", RecoIsoMuonPt, &b_RecoIsoMuonPt);
   fChain->SetBranchAddress("RecoIsoMuonEta", RecoIsoMuonEta, &b_RecoIsoMuonEta);
   fChain->SetBranchAddress("RecoIsoMuonPhi", RecoIsoMuonPhi, &b_RecoIsoMuonPhi);
   fChain->SetBranchAddress("RecoIsoMuonE", RecoIsoMuonE, &b_RecoIsoMuonE);
   fChain->SetBranchAddress("RecoMuonNum", &RecoMuonNum, &b_RecoMuonNum);
   fChain->SetBranchAddress("RecoMuonPt", RecoMuonPt, &b_RecoMuonPt);
   fChain->SetBranchAddress("RecoMuonEta", RecoMuonEta, &b_RecoMuonEta);
   fChain->SetBranchAddress("RecoMuonPhi", RecoMuonPhi, &b_RecoMuonPhi);
   fChain->SetBranchAddress("RecoMuonE", RecoMuonE, &b_RecoMuonE);
   fChain->SetBranchAddress("RecoIsoElecNum", &RecoIsoElecNum, &b_RecoIsoElecNum);
   fChain->SetBranchAddress("RecoIsoElecPt", RecoIsoElecPt, &b_RecoIsoElecPt);
   fChain->SetBranchAddress("RecoIsoElecEta", RecoIsoElecEta, &b_RecoIsoElecEta);
   fChain->SetBranchAddress("RecoIsoElecPhi", RecoIsoElecPhi, &b_RecoIsoElecPhi);
   fChain->SetBranchAddress("RecoIsoElecE", RecoIsoElecE, &b_RecoIsoElecE);
   fChain->SetBranchAddress("RecoElecNum", &RecoElecNum, &b_RecoElecNum);
   fChain->SetBranchAddress("RecoElecPt", RecoElecPt, &b_RecoElecPt);
   fChain->SetBranchAddress("RecoElecEta", RecoElecEta, &b_RecoElecEta);
   fChain->SetBranchAddress("RecoElecPhi", RecoElecPhi, &b_RecoElecPhi);
   fChain->SetBranchAddress("RecoElecE", RecoElecE, &b_RecoElecE);
   fChain->SetBranchAddress("GenWNum", &GenWNum, &b_GenWNum);
   fChain->SetBranchAddress("GenWPt", GenWPt, &b_GenWPt);
   fChain->SetBranchAddress("GenWEta", GenWEta, &b_GenWEta);
   fChain->SetBranchAddress("GenWPhi", GenWPhi, &b_GenWPhi);
   fChain->SetBranchAddress("GenMuNum", &GenMuNum, &b_GenMuNum);
   fChain->SetBranchAddress("GenMuFromTau", GenMuFromTau, &b_GenMuFromTau);
   fChain->SetBranchAddress("GenMuPt", GenMuPt, &b_GenMuPt);
   fChain->SetBranchAddress("GenMuEta", GenMuEta, &b_GenMuEta);
   fChain->SetBranchAddress("GenMuPhi", GenMuPhi, &b_GenMuPhi);
   fChain->SetBranchAddress("GenElecNum", &GenElecNum, &b_GenElecNum);
   fChain->SetBranchAddress("GenElecFromTau", GenElecFromTau, &b_GenElecFromTau);
   fChain->SetBranchAddress("GenElecPt", GenElecPt, &b_GenElecPt);
   fChain->SetBranchAddress("GenElecEta", GenElecEta, &b_GenElecEta);
   fChain->SetBranchAddress("GenElecPhi", GenElecPhi, &b_GenElecPhi);
   fChain->SetBranchAddress("GenTauNum", &GenTauNum, &b_GenTauNum);
   fChain->SetBranchAddress("GenTauPt", GenTauPt, &b_GenTauPt);
   fChain->SetBranchAddress("GenTauEta", GenTauEta, &b_GenTauEta);
   fChain->SetBranchAddress("GenTauPhi", GenTauPhi, &b_GenTauPhi);
   fChain->SetBranchAddress("genHT", &genHT, &b_genHT);
   fChain->SetBranchAddress("genMHT", &genMHT, &b_genMHT);
   fChain->SetBranchAddress("genNJets", &genNJets, &b_genNJets);
   fChain->SetBranchAddress("genJet1Pt", &genJet1Pt, &b_genJet1Pt);
   fChain->SetBranchAddress("genJet2Pt", &genJet2Pt, &b_genJet2Pt);
   fChain->SetBranchAddress("genJet3Pt", &genJet3Pt, &b_genJet3Pt);
   fChain->SetBranchAddress("genJet1Eta", &genJet1Eta, &b_genJet1Eta);
   fChain->SetBranchAddress("genJet2Eta", &genJet2Eta, &b_genJet2Eta);
   fChain->SetBranchAddress("genJet3Eta", &genJet3Eta, &b_genJet3Eta);
   fChain->SetBranchAddress("genDeltaPhi1", &genDeltaPhi1, &b_genDeltaPhi1);
   fChain->SetBranchAddress("genDeltaPhi2", &genDeltaPhi2, &b_genDeltaPhi2);
   fChain->SetBranchAddress("genDeltaPhi3", &genDeltaPhi3, &b_genDeltaPhi3);
   fChain->SetBranchAddress("Filter_HBHENoiseFilterRA2", &Filter_HBHENoiseFilterRA2, &b_Filter_HBHENoiseFilterRA2);
   fChain->SetBranchAddress("Filter_beamHaloFilter", &Filter_beamHaloFilter, &b_Filter_beamHaloFilter);
   fChain->SetBranchAddress("Filter_eeNoiseFilter", &Filter_eeNoiseFilter, &b_Filter_eeNoiseFilter);
   fChain->SetBranchAddress("Filter_trackingFailureFilter", &Filter_trackingFailureFilter, &b_Filter_trackingFailureFilter);
   fChain->SetBranchAddress("Filter_inconsistentMuons", &Filter_inconsistentMuons, &b_Filter_inconsistentMuons);
   fChain->SetBranchAddress("Filter_greedyMuons", &Filter_greedyMuons, &b_Filter_greedyMuons);
   fChain->SetBranchAddress("Filter_ra2EcalTPFilter", &Filter_ra2EcalTPFilter, &b_Filter_ra2EcalTPFilter);
   fChain->SetBranchAddress("Filter_ra2EcalBEFilter", &Filter_ra2EcalBEFilter, &b_Filter_ra2EcalBEFilter);
   fChain->SetBranchAddress("Filter_hcalLaserEventFilter", &Filter_hcalLaserEventFilter, &b_Filter_hcalLaserEventFilter);
   fChain->SetBranchAddress("Filter_ecalLaserCorrFilter", &Filter_ecalLaserCorrFilter, &b_Filter_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Filter_eeBadScFilter", &Filter_eeBadScFilter, &b_Filter_eeBadScFilter);
   fChain->SetBranchAddress("Filter_PBNRFilter", &Filter_PBNRFilter, &b_Filter_PBNRFilter);
   fChain->SetBranchAddress("Filter_HCALLaserEvtFilterList2012", &Filter_HCALLaserEvtFilterList2012, &b_Filter_HCALLaserEvtFilterList2012);
   fChain->SetBranchAddress("Filter_manystripclus53X", &Filter_manystripclus53X, &b_Filter_manystripclus53X);
   fChain->SetBranchAddress("Filter_toomanystripclus53X", &Filter_toomanystripclus53X, &b_Filter_toomanystripclus53X);
   fChain->SetBranchAddress("Filter_logErrorTooManyClusters", &Filter_logErrorTooManyClusters, &b_Filter_logErrorTooManyClusters);
   fChain->SetBranchAddress("Filter_RA2HONoiseFilter", &Filter_RA2HONoiseFilter, &b_Filter_RA2HONoiseFilter);
}

Bool_t Prediction::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef Prediction_cxx
