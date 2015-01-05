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
const bool useGenInfoToMatchCSMuonToGen_=0; // changed 20 Nov from 1 to 0
const double maxDeltaRGenToRecoIsoMuon_=0.3;
const double maxDiffPtGenToRecoIsoMuon_=0.3;
const double minHT_=500;
const double minMHT_=200;
const double minNJets_=2.5;
const double deltaPhi1_=0.5;
const double deltaPhi2_=0.5;
const double deltaPhi3_=0.3;
const bool applyFilters_=false;
const bool applyDiLepCorrection_=true;

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
	 double getEff(TH2F* effTH2F, double xValue, double yValue);
   // output variables
   bool useGenInfoToMatchCSMuonToGen, applyDiLepCorrection; Float_t deltaRGenToRecoIsoMuon_, diffPtGenToRecoIsoMuon_;
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
   Float_t diLepCorrectionEff_, diLepCorrectionEffError_, diLepMuEff_, diLepMuEffError_, diLepElecEff_, diLepElecEffError_;
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
   TH2F *MuDiLepMTW_, *ElecDiLepMTW_;
   TH1F *MuDiLepEff_, *ElecDiLepEff_;
   
   // btag included instaed of njets
   Float_t muIsoEffBTag_, muIsoEffErrorBTag_, muIsoWeightBTag_, muIsoWeightErrorUpBTag_, muIsoWeightErrorDownBTag_;
   Float_t muRecoEffBTag_, muRecoEffErrorBTag_, muRecoWeightBTag_, muRecoWeightErrorUpBTag_, muRecoWeightErrorDownBTag_;
   Float_t muAccEffBTag_, muAccEffErrorBTag_, muAccWeightBTag_, muAccWeightErrorUpBTag_, muAccWeightErrorDownBTag_;
   Float_t muTotalWeightBTag_, totalMuonsBTag_, totalMuonsMTWBTag_;
   
   Float_t elecIsoEffBTag_, elecIsoEffErrorBTag_, elecIsoWeightBTag_, elecIsoWeightErrorUpBTag_, elecIsoWeightErrorDownBTag_;
   Float_t elecRecoEffBTag_, elecRecoEffErrorBTag_, elecRecoWeightBTag_, elecRecoWeightErrorUpBTag_, elecRecoWeightErrorDownBTag_;
   Float_t elecAccEffBTag_, elecAccEffErrorBTag_, elecAccWeightBTag_, elecAccWeightErrorUpBTag_, elecAccWeightErrorDownBTag_;
   Float_t elecTotalWeightBTag_;
   
   Float_t totalWeightBTag_, totalWeightMTWBTag_, totalWeightMTWDiLepBTag_;
   Float_t muIsoUpBTag_, muIsoDownBTag_, muAccUpBTag_, muAccDownBTag_, elecAccUpBTag_, elecAccDownBTag_, totalWeightMTWDiLepDiBosonDownBTag_, totalWeightMTWDiLepDiNonCloUpBTag_, totalWeightMTWDiLepDiNonCloDownBTag_;
   Float_t diLepCorrectionEffBTag_, diLepCorrectionEffErrorBTag_, diLepMuEffBTag_, diLepMuEffErrorBTag_, diLepElecEffBTag_, diLepElecEffErrorBTag_;
	 
	 // elec control sample
	 TH2F *ElecPurity_;
	 Float_t ElecCSTotalWeight_, ElecCSTotalWeightMTW_, ElecCSTotalWeightMTWDiLep_;
	 Float_t ElecCSTotalElecWeight_, ElecCSTotalMuWeight_, ElecCSTotalElectrons_;
	 Float_t ElecCSElecIsoEff_, ElecCSElecIsoWeight_, ElecCSElecRecoEff_, ElecCSElecRecoWeight_, ElecCSElecAccEff_, ElecCSElecAccWeight_, ElecCSMuAccEff_, ElecCSMuAccWeight_, ElecCSMuRecoEff_, ElecCSMuRecoWeight_, ElecCSMuIsoEff_, ElecCSMuIsoWeight_, diLepElecCSCorrectionEff_, diLepElecCSCorrectionEffError_, diLepElecCSMuEff_, diLepElecCSMuEffError_, diLepElecCSElecEff_, diLepElecCSElecEffError_;
	 Float_t ElecCSPurityEff_, ElecCSPurityWeight_;
   
   
   TH2F *MuonAccBTag, *MuonIsoBTag0, *MuonIsoBTag1, *MuonIsoBTag2ToInf, *MuonRecoBTag0, *MuonRecoBTag1, *MuonRecoBTag2ToInf, *MuMTWMHTBTag;
   TH2F *ElecAccBTag, *ElecIsoBTag0, *ElecIsoBTag1, *ElecIsoBTag2ToInf, *ElecRecoBTag0, *ElecRecoBTag1, *ElecRecoBTag2ToInf, *ElecMTWMHTBTag; 
   // Declaration of leaf types
	 UInt_t          RunNum;
	 UInt_t          LumiBlockNum;
	 UInt_t          EvtNum;
	 Int_t           NJets;
	 Int_t           BTags;
	 Int_t           Leptons;
	 Int_t           NVtx;
	 Float_t         Weight;
	 Float_t         MHT;
	 Float_t         METPt;
	 Float_t         METPhi;
	 Float_t         HT;
	 Float_t         DeltaPhi1;
	 Float_t         DeltaPhi2;
	 Float_t         DeltaPhi3;
	 UShort_t        selectedIDIsoMuonsNum;
	 Float_t         selectedIDIsoMuonsPt[3];   //[selectedIDIsoMuonsNum]
	 Float_t         selectedIDIsoMuonsEta[3];   //[selectedIDIsoMuonsNum]
	 Float_t         selectedIDIsoMuonsPhi[3];   //[selectedIDIsoMuonsNum]
	 Float_t         selectedIDIsoMuonsE[3];   //[selectedIDIsoMuonsNum]
	 Float_t         selectedIDIsoMuonsTLorentzVector[3];   //[selectedIDIsoMuonsNum]
	 UShort_t        selectedIDIsoElectronsNum;
	 Float_t         selectedIDIsoElectronsPt[4];   //[selectedIDIsoElectronsNum]
	 Float_t         selectedIDIsoElectronsEta[4];   //[selectedIDIsoElectronsNum]
	 Float_t         selectedIDIsoElectronsPhi[4];   //[selectedIDIsoElectronsNum]
	 Float_t         selectedIDIsoElectronsE[4];   //[selectedIDIsoElectronsNum]
	 Float_t         selectedIDIsoElectronsTLorentzVector[4];   //[selectedIDIsoElectronsNum]
	 UShort_t        IsolatedTracksNum;
	 Float_t         IsolatedTracksPt[4];   //[IsolatedTracksNum]
	 Float_t         IsolatedTracksEta[4];   //[IsolatedTracksNum]
	 Float_t         IsolatedTracksPhi[4];   //[IsolatedTracksNum]
	 Float_t         IsolatedTracksE[4];   //[IsolatedTracksNum]
	 Float_t         IsolatedTracksTLorentzVector[4];   //[IsolatedTracksNum]
	 UShort_t        selectedIDMuonsNum;
	 Float_t         selectedIDMuonsPt[4];   //[selectedIDMuonsNum]
	 Float_t         selectedIDMuonsEta[4];   //[selectedIDMuonsNum]
	 Float_t         selectedIDMuonsPhi[4];   //[selectedIDMuonsNum]
	 Float_t         selectedIDMuonsE[4];   //[selectedIDMuonsNum]
	 Float_t         selectedIDMuonsTLorentzVector[4];   //[selectedIDMuonsNum]
	 UShort_t        selectedIDElectronsNum;
	 Float_t         selectedIDElectronsPt[7];   //[selectedIDElectronsNum]
	 Float_t         selectedIDElectronsEta[7];   //[selectedIDElectronsNum]
	 Float_t         selectedIDElectronsPhi[7];   //[selectedIDElectronsNum]
	 Float_t         selectedIDElectronsE[7];   //[selectedIDElectronsNum]
	 Float_t         selectedIDElectronsTLorentzVector[7];   //[selectedIDElectronsNum]
	 UShort_t        GenBosonNum;
	 Float_t         GenBosonPt[2];   //[GenBosonNum]
	 Float_t         GenBosonEta[2];   //[GenBosonNum]
	 Float_t         GenBosonPhi[2];   //[GenBosonNum]
	 Float_t         GenBosonE[2];   //[GenBosonNum]
	 Float_t         GenBosonTLorentzVector[2];   //[GenBosonNum]
	 Int_t           GenBoson_GenBosonPDGId[2];   //[GenBosonNum]
	 UShort_t        GenMuNum;
	 Float_t         GenMuPt[2];   //[GenMuNum]
	 Float_t         GenMuEta[2];   //[GenMuNum]
	 Float_t         GenMuPhi[2];   //[GenMuNum]
	 Float_t         GenMuE[2];   //[GenMuNum]
	 Float_t         GenMuTLorentzVector[2];   //[GenMuNum]
	 Int_t           GenMu_GenMuFromTau[2];   //[GenMuNum]
	 UShort_t        GenElecNum;
	 Float_t         GenElecPt[2];   //[GenElecNum]
	 Float_t         GenElecEta[2];   //[GenElecNum]
	 Float_t         GenElecPhi[2];   //[GenElecNum]
	 Float_t         GenElecE[2];   //[GenElecNum]
	 Float_t         GenElecTLorentzVector[2];   //[GenElecNum]
	 Int_t           GenElec_GenElecFromTau[2];   //[GenElecNum]
	 UShort_t        GenTauNum;
	 Float_t         GenTauPt[2];   //[GenTauNum]
	 Float_t         GenTauEta[2];   //[GenTauNum]
	 Float_t         GenTauPhi[2];   //[GenTauNum]
	 Float_t         GenTauE[2];   //[GenTauNum]
	 Float_t         GenTauTLorentzVector[2];   //[GenTauNum]
	 Int_t           GenTau_GenTauHad[2];   //[GenTauNum]
	 UShort_t        MHTJetsNum;
	 Float_t         MHTJetsPt[13];   //[MHTJetsNum]
	 Float_t         MHTJetsEta[13];   //[MHTJetsNum]
	 Float_t         MHTJetsPhi[13];   //[MHTJetsNum]
	 Float_t         MHTJetsE[13];   //[MHTJetsNum]
	 Float_t         MHTJetsTLorentzVector[13];   //[MHTJetsNum]
	 Float_t         MHTJets_bDiscriminator[13];   //[MHTJetsNum]
	 Float_t         MHTJets_chargedEmEnergyFraction[13];   //[MHTJetsNum]
	 Float_t         MHTJets_chargedHadronEnergyFraction[13];   //[MHTJetsNum]
	 Int_t           MHTJets_chargedHadronMultiplicity[13];   //[MHTJetsNum]
	 Int_t           MHTJets_electronMultiplicity[13];   //[MHTJetsNum]
	 Float_t         MHTJets_jetArea[13];   //[MHTJetsNum]
	 Float_t         MHTJets_muonEnergyFraction[13];   //[MHTJetsNum]
	 Int_t           MHTJets_muonMultiplicity[13];   //[MHTJetsNum]
	 Float_t         MHTJets_neutralEmEnergyFraction[13];   //[MHTJetsNum]
	 Int_t           MHTJets_neutralHadronMultiplicity[13];   //[MHTJetsNum]
	 Float_t         MHTJets_photonEnergyFraction[13];   //[MHTJetsNum]
	 Int_t           MHTJets_photonMultiplicity[13];   //[MHTJetsNum]
	 
	 // List of branches
	 TBranch        *b_RunNum;   //!
	 TBranch        *b_LumiBlockNum;   //!
	 TBranch        *b_EvtNum;   //!
	 TBranch        *b_NJets;   //!
	 TBranch        *b_BTags;   //!
	 TBranch        *b_Leptons;   //!
	 TBranch        *b_NVtx;   //!
	 TBranch        *b_Weight;   //!
	 TBranch        *b_MHT;   //!
	 TBranch        *b_METPt;   //!
	 TBranch        *b_METPhi;   //!
	 TBranch        *b_HT;   //!
	 TBranch        *b_DeltaPhi1;   //!
	 TBranch        *b_DeltaPhi2;   //!
	 TBranch        *b_DeltaPhi3;   //!
	 TBranch        *b_selectedIDIsoMuonsNum;   //!
	 TBranch        *b_selectedIDIsoMuonsPt;   //!
	 TBranch        *b_selectedIDIsoMuonsEta;   //!
	 TBranch        *b_selectedIDIsoMuonsPhi;   //!
	 TBranch        *b_selectedIDIsoMuonsE;   //!
	 TBranch        *b_selectedIDIsoMuonsTLorentzVector;   //!
	 TBranch        *b_selectedIDIsoElectronsNum;   //!
	 TBranch        *b_selectedIDIsoElectronsPt;   //!
	 TBranch        *b_selectedIDIsoElectronsEta;   //!
	 TBranch        *b_selectedIDIsoElectronsPhi;   //!
	 TBranch        *b_selectedIDIsoElectronsE;   //!
	 TBranch        *b_selectedIDIsoElectronsTLorentzVector;   //!
	 TBranch        *b_IsolatedTracksNum;   //!
	 TBranch        *b_IsolatedTracksPt;   //!
	 TBranch        *b_IsolatedTracksEta;   //!
	 TBranch        *b_IsolatedTracksPhi;   //!
	 TBranch        *b_IsolatedTracksE;   //!
	 TBranch        *b_IsolatedTracksTLorentzVector;   //!
	 TBranch        *b_selectedIDMuonsNum;   //!
	 TBranch        *b_selectedIDMuonsPt;   //!
	 TBranch        *b_selectedIDMuonsEta;   //!
	 TBranch        *b_selectedIDMuonsPhi;   //!
	 TBranch        *b_selectedIDMuonsE;   //!
	 TBranch        *b_selectedIDMuonsTLorentzVector;   //!
	 TBranch        *b_selectedIDElectronsNum;   //!
	 TBranch        *b_selectedIDElectronsPt;   //!
	 TBranch        *b_selectedIDElectronsEta;   //!
	 TBranch        *b_selectedIDElectronsPhi;   //!
	 TBranch        *b_selectedIDElectronsE;   //!
	 TBranch        *b_selectedIDElectronsTLorentzVector;   //!
	 TBranch        *b_GenBosonNum;   //!
	 TBranch        *b_GenBosonPt;   //!
	 TBranch        *b_GenBosonEta;   //!
	 TBranch        *b_GenBosonPhi;   //!
	 TBranch        *b_GenBosonE;   //!
	 TBranch        *b_GenBosonTLorentzVector;   //!
	 TBranch        *b_GenBoson_GenBosonPDGId;   //!
	 TBranch        *b_GenMuNum;   //!
	 TBranch        *b_GenMuPt;   //!
	 TBranch        *b_GenMuEta;   //!
	 TBranch        *b_GenMuPhi;   //!
	 TBranch        *b_GenMuE;   //!
	 TBranch        *b_GenMuTLorentzVector;   //!
	 TBranch        *b_GenMu_GenMuFromTau;   //!
	 TBranch        *b_GenElecNum;   //!
	 TBranch        *b_GenElecPt;   //!
	 TBranch        *b_GenElecEta;   //!
	 TBranch        *b_GenElecPhi;   //!
	 TBranch        *b_GenElecE;   //!
	 TBranch        *b_GenElecTLorentzVector;   //!
	 TBranch        *b_GenElec_GenElecFromTau;   //!
	 TBranch        *b_GenTauNum;   //!
	 TBranch        *b_GenTauPt;   //!
	 TBranch        *b_GenTauEta;   //!
	 TBranch        *b_GenTauPhi;   //!
	 TBranch        *b_GenTauE;   //!
	 TBranch        *b_GenTauTLorentzVector;   //!
	 TBranch        *b_GenTau_GenTauHad;   //!
	 TBranch        *b_MHTJetsNum;   //!
	 TBranch        *b_MHTJetsPt;   //!
	 TBranch        *b_MHTJetsEta;   //!
	 TBranch        *b_MHTJetsPhi;   //!
	 TBranch        *b_MHTJetsE;   //!
	 TBranch        *b_MHTJetsTLorentzVector;   //!
	 TBranch        *b_MHTJets_bDiscriminator;   //!
	 TBranch        *b_MHTJets_chargedEmEnergyFraction;   //!
	 TBranch        *b_MHTJets_chargedHadronEnergyFraction;   //!
	 TBranch        *b_MHTJets_chargedHadronMultiplicity;   //!
	 TBranch        *b_MHTJets_electronMultiplicity;   //!
	 TBranch        *b_MHTJets_jetArea;   //!
	 TBranch        *b_MHTJets_muonEnergyFraction;   //!
	 TBranch        *b_MHTJets_muonMultiplicity;   //!
	 TBranch        *b_MHTJets_neutralEmEnergyFraction;   //!
	 TBranch        *b_MHTJets_neutralHadronMultiplicity;   //!
	 TBranch        *b_MHTJets_photonEnergyFraction;   //!
	 TBranch        *b_MHTJets_photonMultiplicity;   //!

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
	 fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
	 fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
	 fChain->SetBranchAddress("Leptons", &Leptons, &b_Leptons);
	 fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
	 fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
	 fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
	 fChain->SetBranchAddress("METPt", &METPt, &b_METPt);
	 fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
	 fChain->SetBranchAddress("HT", &HT, &b_HT);
	 fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
	 fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
	 fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
	 fChain->SetBranchAddress("selectedIDIsoMuonsNum", &selectedIDIsoMuonsNum, &b_selectedIDIsoMuonsNum);
	 fChain->SetBranchAddress("selectedIDIsoMuonsPt", selectedIDIsoMuonsPt, &b_selectedIDIsoMuonsPt);
	 fChain->SetBranchAddress("selectedIDIsoMuonsEta", selectedIDIsoMuonsEta, &b_selectedIDIsoMuonsEta);
	 fChain->SetBranchAddress("selectedIDIsoMuonsPhi", selectedIDIsoMuonsPhi, &b_selectedIDIsoMuonsPhi);
	 fChain->SetBranchAddress("selectedIDIsoMuonsE", selectedIDIsoMuonsE, &b_selectedIDIsoMuonsE);
	 fChain->SetBranchAddress("selectedIDIsoMuonsTLorentzVector", selectedIDIsoMuonsTLorentzVector, &b_selectedIDIsoMuonsTLorentzVector);
	 fChain->SetBranchAddress("selectedIDIsoElectronsNum", &selectedIDIsoElectronsNum, &b_selectedIDIsoElectronsNum);
	 fChain->SetBranchAddress("selectedIDIsoElectronsPt", selectedIDIsoElectronsPt, &b_selectedIDIsoElectronsPt);
	 fChain->SetBranchAddress("selectedIDIsoElectronsEta", selectedIDIsoElectronsEta, &b_selectedIDIsoElectronsEta);
	 fChain->SetBranchAddress("selectedIDIsoElectronsPhi", selectedIDIsoElectronsPhi, &b_selectedIDIsoElectronsPhi);
	 fChain->SetBranchAddress("selectedIDIsoElectronsE", selectedIDIsoElectronsE, &b_selectedIDIsoElectronsE);
	 fChain->SetBranchAddress("selectedIDIsoElectronsTLorentzVector", selectedIDIsoElectronsTLorentzVector, &b_selectedIDIsoElectronsTLorentzVector);
	 fChain->SetBranchAddress("IsolatedTracksNum", &IsolatedTracksNum, &b_IsolatedTracksNum);
	 fChain->SetBranchAddress("IsolatedTracksPt", IsolatedTracksPt, &b_IsolatedTracksPt);
	 fChain->SetBranchAddress("IsolatedTracksEta", IsolatedTracksEta, &b_IsolatedTracksEta);
	 fChain->SetBranchAddress("IsolatedTracksPhi", IsolatedTracksPhi, &b_IsolatedTracksPhi);
	 fChain->SetBranchAddress("IsolatedTracksE", IsolatedTracksE, &b_IsolatedTracksE);
	 fChain->SetBranchAddress("IsolatedTracksTLorentzVector", IsolatedTracksTLorentzVector, &b_IsolatedTracksTLorentzVector);
	 fChain->SetBranchAddress("selectedIDMuonsNum", &selectedIDMuonsNum, &b_selectedIDMuonsNum);
	 fChain->SetBranchAddress("selectedIDMuonsPt", selectedIDMuonsPt, &b_selectedIDMuonsPt);
	 fChain->SetBranchAddress("selectedIDMuonsEta", selectedIDMuonsEta, &b_selectedIDMuonsEta);
	 fChain->SetBranchAddress("selectedIDMuonsPhi", selectedIDMuonsPhi, &b_selectedIDMuonsPhi);
	 fChain->SetBranchAddress("selectedIDMuonsE", selectedIDMuonsE, &b_selectedIDMuonsE);
	 fChain->SetBranchAddress("selectedIDMuonsTLorentzVector", selectedIDMuonsTLorentzVector, &b_selectedIDMuonsTLorentzVector);
	 fChain->SetBranchAddress("selectedIDElectronsNum", &selectedIDElectronsNum, &b_selectedIDElectronsNum);
	 fChain->SetBranchAddress("selectedIDElectronsPt", selectedIDElectronsPt, &b_selectedIDElectronsPt);
	 fChain->SetBranchAddress("selectedIDElectronsEta", selectedIDElectronsEta, &b_selectedIDElectronsEta);
	 fChain->SetBranchAddress("selectedIDElectronsPhi", selectedIDElectronsPhi, &b_selectedIDElectronsPhi);
	 fChain->SetBranchAddress("selectedIDElectronsE", selectedIDElectronsE, &b_selectedIDElectronsE);
	 fChain->SetBranchAddress("selectedIDElectronsTLorentzVector", selectedIDElectronsTLorentzVector, &b_selectedIDElectronsTLorentzVector);
	 fChain->SetBranchAddress("GenBosonNum", &GenBosonNum, &b_GenBosonNum);
	 fChain->SetBranchAddress("GenBosonPt", GenBosonPt, &b_GenBosonPt);
	 fChain->SetBranchAddress("GenBosonEta", GenBosonEta, &b_GenBosonEta);
	 fChain->SetBranchAddress("GenBosonPhi", GenBosonPhi, &b_GenBosonPhi);
	 fChain->SetBranchAddress("GenBosonE", GenBosonE, &b_GenBosonE);
	 fChain->SetBranchAddress("GenBosonTLorentzVector", GenBosonTLorentzVector, &b_GenBosonTLorentzVector);
	 fChain->SetBranchAddress("GenBoson_GenBosonPDGId", GenBoson_GenBosonPDGId, &b_GenBoson_GenBosonPDGId);
	 fChain->SetBranchAddress("GenMuNum", &GenMuNum, &b_GenMuNum);
	 fChain->SetBranchAddress("GenMuPt", GenMuPt, &b_GenMuPt);
	 fChain->SetBranchAddress("GenMuEta", GenMuEta, &b_GenMuEta);
	 fChain->SetBranchAddress("GenMuPhi", GenMuPhi, &b_GenMuPhi);
	 fChain->SetBranchAddress("GenMuE", GenMuE, &b_GenMuE);
	 fChain->SetBranchAddress("GenMuTLorentzVector", GenMuTLorentzVector, &b_GenMuTLorentzVector);
	 fChain->SetBranchAddress("GenMu_GenMuFromTau", GenMu_GenMuFromTau, &b_GenMu_GenMuFromTau);
	 fChain->SetBranchAddress("GenElecNum", &GenElecNum, &b_GenElecNum);
	 fChain->SetBranchAddress("GenElecPt", GenElecPt, &b_GenElecPt);
	 fChain->SetBranchAddress("GenElecEta", GenElecEta, &b_GenElecEta);
	 fChain->SetBranchAddress("GenElecPhi", GenElecPhi, &b_GenElecPhi);
	 fChain->SetBranchAddress("GenElecE", GenElecE, &b_GenElecE);
	 fChain->SetBranchAddress("GenElecTLorentzVector", GenElecTLorentzVector, &b_GenElecTLorentzVector);
	 fChain->SetBranchAddress("GenElec_GenElecFromTau", GenElec_GenElecFromTau, &b_GenElec_GenElecFromTau);
	 fChain->SetBranchAddress("GenTauNum", &GenTauNum, &b_GenTauNum);
	 fChain->SetBranchAddress("GenTauPt", GenTauPt, &b_GenTauPt);
	 fChain->SetBranchAddress("GenTauEta", GenTauEta, &b_GenTauEta);
	 fChain->SetBranchAddress("GenTauPhi", GenTauPhi, &b_GenTauPhi);
	 fChain->SetBranchAddress("GenTauE", GenTauE, &b_GenTauE);
	 fChain->SetBranchAddress("GenTauTLorentzVector", GenTauTLorentzVector, &b_GenTauTLorentzVector);
	 fChain->SetBranchAddress("GenTau_GenTauHad", GenTau_GenTauHad, &b_GenTau_GenTauHad);
	 fChain->SetBranchAddress("MHTJetsNum", &MHTJetsNum, &b_MHTJetsNum);
	 fChain->SetBranchAddress("MHTJetsPt", MHTJetsPt, &b_MHTJetsPt);
	 fChain->SetBranchAddress("MHTJetsEta", MHTJetsEta, &b_MHTJetsEta);
	 fChain->SetBranchAddress("MHTJetsPhi", MHTJetsPhi, &b_MHTJetsPhi);
	 fChain->SetBranchAddress("MHTJetsE", MHTJetsE, &b_MHTJetsE);
	 fChain->SetBranchAddress("MHTJetsTLorentzVector", MHTJetsTLorentzVector, &b_MHTJetsTLorentzVector);
	 fChain->SetBranchAddress("MHTJets_bDiscriminator", MHTJets_bDiscriminator, &b_MHTJets_bDiscriminator);
	 fChain->SetBranchAddress("MHTJets_chargedEmEnergyFraction", MHTJets_chargedEmEnergyFraction, &b_MHTJets_chargedEmEnergyFraction);
	 fChain->SetBranchAddress("MHTJets_chargedHadronEnergyFraction", MHTJets_chargedHadronEnergyFraction, &b_MHTJets_chargedHadronEnergyFraction);
	 fChain->SetBranchAddress("MHTJets_chargedHadronMultiplicity", MHTJets_chargedHadronMultiplicity, &b_MHTJets_chargedHadronMultiplicity);
	 fChain->SetBranchAddress("MHTJets_electronMultiplicity", MHTJets_electronMultiplicity, &b_MHTJets_electronMultiplicity);
	 fChain->SetBranchAddress("MHTJets_jetArea", MHTJets_jetArea, &b_MHTJets_jetArea);
	 fChain->SetBranchAddress("MHTJets_muonEnergyFraction", MHTJets_muonEnergyFraction, &b_MHTJets_muonEnergyFraction);
	 fChain->SetBranchAddress("MHTJets_muonMultiplicity", MHTJets_muonMultiplicity, &b_MHTJets_muonMultiplicity);
	 fChain->SetBranchAddress("MHTJets_neutralEmEnergyFraction", MHTJets_neutralEmEnergyFraction, &b_MHTJets_neutralEmEnergyFraction);
	 fChain->SetBranchAddress("MHTJets_neutralHadronMultiplicity", MHTJets_neutralHadronMultiplicity, &b_MHTJets_neutralHadronMultiplicity);
	 fChain->SetBranchAddress("MHTJets_photonEnergyFraction", MHTJets_photonEnergyFraction, &b_MHTJets_photonEnergyFraction);
	 fChain->SetBranchAddress("MHTJets_photonMultiplicity", MHTJets_photonMultiplicity, &b_MHTJets_photonMultiplicity);
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
