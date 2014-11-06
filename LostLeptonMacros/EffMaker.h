//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 23 17:21:53 2014 by ROOT version 5.34/04
// from TTree RA2PreSelection/RA2PreSelection
// found on file: wjetHT600-Inf.root
//////////////////////////////////////////////////////////

#ifndef EffMaker_h
#define EffMaker_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH2F.h>
#include <TH1F.h>
#include "TVector2.h"
#include <cmath>
#include "TCanvas.h"
// output control
const bool saveEffToPDF_=true;
const bool saveEffToPNG_=true;
// cuts baseline
const double minHT_=350;
const double minMHT_=200;
const double minNJets_=1.9;
const double deltaPhi1_=0.5;
const double deltaPhi2_=0.5;
const double deltaPhi3_=0.3;
const bool applyFilters_=false;
// lepton cuts
const double minMuPt_=10;
const double maxMuEta_=2.4;
const double minElecPt_=10;
const double maxElecEta_=2.4;
const double mtwCut_=100;
const double minTauPt_=10;
const double maxTauEta_=2.4;

// lepton matching
const double maxDeltaRGenToRecoMu_ =0.3;
const double maxDiffPtGenToRecoMu_ =0.3;
const double maxDeltaRRecoToIsoMu_ =0.1;
const double maxDiffPtRecoToIsoMu_ =0.1;
const double maxDeltaRIsoToGenMu_ = 0.3;
const double maxDiffPtIsoToGenMu_ = 0.3;

const double maxDeltaRGenToRecoElec_ =0.3;
const double maxDiffPtGenToRecoElec_ =0.3;
const double maxDeltaRRecoToIsoElec_ =0.1;
const double maxDiffPtRecoToIsoElec_ =0.1;
const double maxDeltaRIsoToGenElec_ = 0.3;
const double maxDiffPtIsoToGenElec_ = 0.3;

// isolated tracks
const double maxDeltaRGenMuToTack_ = 0.2;
const double maxDiffPtGenMuToTack_ = 0.5;
const double maxDeltaRRecoIsoMuToTack_ = 0.2;
const double maxDiffPtRecoIsoMuToTack_ = 0.5;

const double maxDeltaRGenElecToTack_ = 0.3;
const double maxDiffPtGenElecToTack_ = 0.5;
const double maxDeltaRRecoIsoElecToTack_ = 0.3;
const double maxDiffPtRecoIsoElecToTack_ = 0.5;

const double maxDeltaRGenTauToTack_ = 0.3;
const double maxDiffPtGenTauToTack_ = 0.5;


const UShort_t NJetsLow_=2;
const UShort_t NJetsMedium_=5;
const UShort_t NJetsMedium2_=7;
const UShort_t NJetsHigh_=8;
const double NjetLowLow_=1.6;
const double NjetHighLow_ = 2.6;
const double NjetLow0_=2.6;
const double NjetHigh0_=5.6;
const double NjetLow1_=5.6;
const double NjetHigh1_=7.6;
const double NjetLow2_=7.6;
const double NjetHigh2_=9999;
const int muIsoHTLow_=5;
double MuIsoHTLow_[muIsoHTLow_]={350,500,800,2000,9000};
const int muIsoMHTLow_=8;
double MuIsoMHTLow_[muIsoMHTLow_]={0,50,100,200,450,600,750,9500};
const int muIsoHT0_=6;
double MuIsoHT0_[muIsoHT0_]={350,500,800,1000,1250,9000};
const int muIsoMHT0_=8;
double MuIsoMHT0_[muIsoMHT0_]={0,50,100,200,300,450,600,9500};
const int muIsoHT1_=7;
double MuIsoHT1_[muIsoHT1_]={350,500,800,1000,1250,1500,9000};
const int muIsoMHT1_=7;
double MuIsoMHT1_[muIsoMHT1_]={0,50,100,200,300,450,9500};
const int muIsoHT2_=7;
double MuIsoHT2_[muIsoHT2_]={350,500,800,1000,1250,1500,9000};
const int muIsoMHT2_=5;
double MuIsoMHT2_[muIsoMHT2_]={0,50,100,200,9500};

const int muRecoHTLow_=4;
double MuRecoHTLow_[muRecoHTLow_]={350,500,800,9000};
const int muRecoMHTLow_=7;
double MuRecoMHTLow_[muRecoMHTLow_]={0,50,100,200,450,600,9500};
const int muRecoHT0_=6;
double MuRecoHT0_[muRecoHT0_]={350,500,800,1000,1250,9000};
const int muRecoMHT0_=8;
double MuRecoMHT0_[muRecoMHT0_]={0,50,100,200,300,450,600,9500};
const int muRecoHT1_=7;
double MuRecoHT1_[muRecoHT1_]={350,500,800,1000,1250,1500,9000};
const int muRecoMHT1_=7;
double MuRecoMHT1_[muRecoMHT1_]={0,50,100,200,300,450,9500};
const int muRecoHT2_=7;
double MuRecoHT2_[muRecoHT2_]={350,500,800,1000,1250,1500,9000};
const int muRecoMHT2_=5;
double MuRecoMHT2_[muRecoMHT2_]={0,50,100,200,9500};


const int muAccMht_ = 7;
double MuAccMht_ [muAccMht_]={0,50,100,200,300,450,9600};
const int muAccNJets_ = 6;
double MuAccNJets_ [muAccNJets_]={2,3,4,6,7,22};

const int mumtwNjet_ = 5;
double muMtwNjet_[mumtwNjet_] ={2,3,4,5,22};

const int mumtwMHT_ = 5;
double muMtwMHT_[mumtwMHT_] ={0,100,200,400,9600};

const int mupurityMHT_ = 7;
double muPurityMHT_[mupurityMHT_] ={0,100,200,400,800,1200,9600};
const int mupurityNJet_ = 5;
double muPurityNJet_[mupurityNJet_] ={2,3,4,5,22};

const int mudilepMHT_ = 7;
double muDilepMHT_[mudilepMHT_] ={0,100,200,400,800,1200,9600};
const int mudilepNJet_ = 5;
double muDilepNJet_[mudilepNJet_] ={2,3,4,5,22};

const int elecIsoHTLow_=4;
double ElecIsoHTLow_[elecIsoHTLow_]={350,500,800,9000};
const int elecIsoMHTLow_=7;
double ElecIsoMHTLow_[elecIsoMHTLow_]={0,100,200,300,450,600,9500};
const int elecIsoHT0_=6;
double ElecIsoHT0_[elecIsoHT0_]={350,500,800,1000,1250,9000};
const int elecIsoMHT0_=8; 
double ElecIsoMHT0_[elecIsoMHT0_]={0,50,100,200,300,450,600,9500};
const int elecIsoHT1_=7;
double ElecIsoHT1_[elecIsoHT1_]={350,500,800,1000,1250,1500,9000};
const int elecIsoMHT1_=7;
double ElecIsoMHT1_[elecIsoMHT1_]={0,50,100,200,300,450,9500};
const int elecIsoHT2_=7;
double ElecIsoHT2_[elecIsoHT2_]={350,500,800,1000,1250,1500,9000};
const int elecIsoMHT2_=5;
double ElecIsoMHT2_[elecIsoMHT2_]={0,50,100,200,9500};

const int elecRecoHTLow_=5;
double ElecRecoHTLow_[elecRecoHTLow_]={350,500,800,1000,9000};
const int elecRecoMHTLow_=8;
double ElecRecoMHTLow_[elecRecoMHTLow_]={0,50,100,200,300,450,600,9500};
const int elecRecoHT0_=6;
double ElecRecoHT0_[elecRecoHT0_]={350,500,800,1000,1250,9000};
const int elecRecoMHT0_=8;
double ElecRecoMHT0_[elecRecoMHT0_]={0,50,100,200,300,450,600,9500};
const int elecRecoHT1_=7;
double ElecRecoHT1_[elecRecoHT1_]={350,500,800,1000,1250,1500,9000};
const int elecRecoMHT1_=7;
double ElecRecoMHT1_[elecRecoMHT1_]={0,50,100,200,300,450,9500};
const int elecRecoHT2_=7;
double ElecRecoHT2_[elecRecoHT2_]={350,500,800,1000,1250,1500,9000};
const int elecRecoMHT2_=5;
double ElecRecoMHT2_[elecRecoMHT2_]={0,50,100,200,9500};

const int elecAccMht_ = 7;
double ElecAccMht_ [elecAccMht_]={0,50,100,200,300,450,9600};
const int elecAccNJets_ = 6;
double ElecAccNJets_ [elecAccNJets_]={2,3,4,6,7,22};

const int elecmtwNjet_ = 5;
double elecMtwNjet_[elecmtwNjet_] ={2,3,4,5,22};

const int elecmtwMHT_ = 5;
double elecMtwMHT_[elecmtwMHT_] ={0,100,200,400,9600};

const int elecpurityNJet_ = 5;
double elecPurityNJet_[elecpurityNJet_] ={2,3,4,5,22};
const int elecpurityMHT_ = 7;
double elecPurityMHT_[elecpurityMHT_] ={0,100,200,400,800,1200,9600};

const int elecdilepMHT_ = 7;
double elecDilepMHT_[elecdilepMHT_] ={0,100,200,400,800,1200,9600};
const int elecdilepNJet_ = 5;
double elecDilepNJet_[elecdilepNJet_] ={2,3,4,5,22};

const int muilepEffNJet_ = 5;
double muiLepEffNJet_[muilepEffNJet_] ={2,3,5,7,22};

const int elecilepEffNJet_ = 5;
double eleciLepEffNJet_[elecilepEffNJet_] ={2,3,5,7,22};





// b-tag included instead of njets
const int muonAccBTagB_=4;
double MuAccBTagB_[muonAccBTagB_]={0,1,2,15};
const int muonAccBTagMHT_=8;
double MuAccBTagMHT_[muonAccBTagMHT_]={0,50,100,200,450,600,750,9500};

const int muIsoBTagHT0_=5;
double MuIsoBTagHT0_[muIsoBTagHT0_]={350,500,800,2000,9000};
const int muIsoBTagMHT0_=8;
double MuIsoBTagMHT0_[muIsoBTagMHT0_]={0,50,100,200,450,600,750,9500};

const int muIsoBTagHT1_=5;
double MuIsoBTagHT1_[muIsoBTagHT1_]={350,500,800,2000,9000};
const int muIsoBTagMHT1_=7;
double MuIsoBTagMHT1_[muIsoBTagMHT1_]={0,50,100,200,450,750,9500};

const int muIsoBTagHT2ToInf_=4;
double MuIsoBTagHT2ToInf_[muIsoBTagHT2ToInf_]={350,500,800,9000};
const int muIsoBTagMHT2ToInf_=5;
double MuIsoBTagMHT2ToInf_[muIsoBTagMHT2ToInf_]={0,100,200,450,9500};


const int muRecoBTagHT0_=5;
double MuRecoBTagHT0_[muRecoBTagHT0_]={350,500,800,2000,9000};
const int muRecoBTagMHT0_=8;
double MuRecoBTagMHT0_[muRecoBTagMHT0_]={0,50,100,200,450,600,750,9500};

const int muRecoBTagHT1_=5;
double MuRecoBTagHT1_[muRecoBTagHT1_]={350,500,800,2000,9000};
const int muRecoBTagMHT1_=7;
double MuRecoBTagMHT1_[muRecoBTagMHT1_]={0,50,100,200,450,750,9500};

const int muRecoBTagHT2ToInf_=4;
double MuRecoBTagHT2ToInf_[muRecoBTagHT2ToInf_]={350,500,800,9000};
const int muRecoBTagMHT2ToInf_=5;
double MuRecoBTagMHT2ToInf_[muRecoBTagMHT2ToInf_]={0,100,200,450,9500};


const int mumtwBTagB_ = 4;
double muMtwBTagB_[mumtwBTagB_] ={0,1,2,15};

const int mumtwMHTBTag_ = 5;
double muMtwMHTBTag_[mumtwMHTBTag_] ={0,100,200,400,9600};




const int elecAccBTagB_=4;
double ElecAccBTagB_[elecAccBTagB_]={0,1,2,15};
const int elecAccBTagMHT_=8;
double ElecAccBTagMHT_[elecAccBTagMHT_]={0,50,100,200,450,600,750,9500};

const int elecIsoBTagHT0_=5;
double ElecIsoBTagHT0_[elecIsoBTagHT0_]={350,500,800,2000,9000};
const int elecIsoBTagMHT0_=8;
double ElecIsoBTagMHT0_[elecIsoBTagMHT0_]={0,50,100,200,450,600,750,9500};

const int elecIsoBTagHT1_=5;
double ElecIsoBTagHT1_[elecIsoBTagHT1_]={350,500,800,2000,9000};
const int elecIsoBTagMHT1_=7;
double ElecIsoBTagMHT1_[elecIsoBTagMHT1_]={0,50,100,200,450,750,9500};

const int elecIsoBTagHT2ToInf_=4;
double ElecIsoBTagHT2ToInf_[elecIsoBTagHT2ToInf_]={350,500,800,9000};
const int elecIsoBTagMHT2ToInf_=5;
double ElecIsoBTagMHT2ToInf_[elecIsoBTagMHT2ToInf_]={0,100,200,450,9500};


const int elecRecoBTagHT0_=5;
double ElecRecoBTagHT0_[elecRecoBTagHT0_]={350,500,800,2000,9000};
const int elecRecoBTagMHT0_=8;
double ElecRecoBTagMHT0_[elecRecoBTagMHT0_]={0,50,100,200,450,600,750,9500};

const int elecRecoBTagHT1_=5;
double ElecRecoBTagHT1_[elecRecoBTagHT1_]={350,500,800,2000,9000};
const int elecRecoBTagMHT1_=7;
double ElecRecoBTagMHT1_[elecRecoBTagMHT1_]={0,50,100,200,450,750,9500};

const int elecRecoBTagHT2ToInf_=4;
double ElecRecoBTagHT2ToInf_[elecRecoBTagHT2ToInf_]={350,500,800,9000};
const int elecRecoBTagMHT2ToInf_=5;
double ElecRecoBTagMHT2ToInf_[elecRecoBTagMHT2ToInf_]={0,100,200,450,9500};


const int elecmtwBTagB_ = 4;
double elecMtwBTagB_[elecmtwBTagB_] ={0,1,2,15};

const int elecmtwMHTBTag_ = 5;
double elecMtwMHTBTag_[elecmtwMHTBTag_] ={0,100,200,400,9600};
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class EffMaker : public TSelector {
public :
  void resetValues();
  bool FiltersPass();
  double deltaR(double eta1, double phi1, double eta2, double phi2);
  double MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi);
  TH2F* ratioCalculator(TH2F* passTH2, TH2F* failTH2);
  TH1F* ratioCalculator(TH1F* passTH1, TH1F* failTH1);
  void SaveEfficiency(TH2F *input);
  void SaveEfficiency(TH1F *input);
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   // Storing stuff
   TTree	*tExpectation_;
   // TH2F efficiencies
   TH2F *MuonIsoLow, *MuonIso0, *MuonIso1, *MuonIso2; 
   TH2F *MuonRecoLow, *MuonReco0, *MuonReco1, *MuonReco2; 
   TH2F *MuonAcc;
   TH1F *MuMTWNJet;
   TH2F *MuMTWMHTNJet;
   TH2F *ElecIsoLow, *ElecIso0, *ElecIso1, *ElecIso2; 
   TH2F *ElecRecoLow, *ElecReco0, *ElecReco1, *ElecReco2; 
   TH2F *ElecAcc;
   TH1F *ElecMTWNJet;
   TH2F *ElecMTWMHTNJet;
   
   TH2F *MuonPurityMHTNJet, *ElecPurityMHTNJet, *MuDiLepControlSampleMHTNJet, *MuDiLepControlSampleMHTNJetMTW, *ElecDiLepControlSampleMHTNJet, *ElecDiLepControlSampleMHTNJetMTW;
   TH2F *MuonPurityMHTNJetFail, *ElecPurityMHTNJetFail, *MuDiLepControlSampleMHTNJetFail, *ElecDiLepControlSampleMHTNJetFail, *MuDiLepControlSampleMHTNJetMTWFail, *ElecDiLepControlSampleMHTNJetMTWFail;
   TH1F *MuDiLepEffNJets, *ElecDiLepEffNJets, *MuDiLepEffNJetsFail, *ElecDiLepEffNJetsFail;
   
   TH2F *MuonIso0Fail, *MuonIsoLowFail, *MuonIso1Fail, *MuonIso2Fail, *MuonAccFail, *MuonReco0Fail, *MuonRecoLowFail, *MuonReco1Fail, *MuonReco2Fail;
   TH2F *ElecIso0Fail, *ElecIsoLowFail, *ElecIso1Fail, *ElecIso2Fail, *ElecAccFail, *ElecReco0Fail, *ElecRecoLowFail, *ElecReco1Fail, *ElecReco2Fail;
   TH1F *MuMTWNJetFail, *ElecMTWNJetFail;
   TH2F *MuMTWMHTNJetFail, *ElecMTWMHTNJetFail;
   // btag included instaed of njets
   
   TH2F *MuonAccBTag, *MuonIsoBTag0, *MuonIsoBTag1, *MuonIsoBTag2ToInf, *MuonRecoBTag0, *MuonRecoBTag1, *MuonRecoBTag2ToInf, *MuMTWMHTBTag;
   TH2F *ElecAccBTag, *ElecIsoBTag0, *ElecIsoBTag1, *ElecIsoBTag2ToInf, *ElecRecoBTag0, *ElecRecoBTag1, *ElecRecoBTag2ToInf, *ElecMTWMHTBTag; 
   
   TH2F *MuonAccBTagFail, *MuonIsoBTag0Fail, *MuonIsoBTag1Fail, *MuonIsoBTag2ToInfFail, *MuonRecoBTag0Fail, *MuonRecoBTag1Fail, *MuonRecoBTag2ToInfFail, *MuMTWMHTBTagFail;
   TH2F *ElecAccBTagFail, *ElecIsoBTag0Fail, *ElecIsoBTag1Fail, *ElecIsoBTag2ToInfFail, *ElecRecoBTag0Fail, *ElecRecoBTag1Fail, *ElecRecoBTag2ToInfFail, *ElecMTWMHTBTagFail; 
   
   
   
   // eff variables fot the tree
   UShort_t Expectation;
	 UShort_t FallsVetoLep, FallsVetoIsoTrack;
	 UShort_t FallsVetoIsoTrackPT10, FallsVetoIsoTrackPT10IsoCut08, FallsVetoIsoTrackPT10IsoCut12;
   UShort_t muIso, muReco, muAcc, muMTW, muTotal;
   UShort_t elecIso, elecReco, elecAcc, elecMTW, elecTotal;
   UShort_t         RecoIsoMuonPromtMatched[20];
   Float_t         RecoIsoMuonPromtMatchedDeltaR[20];
   Float_t         RecoIsoMuonPromtMatchedRelPt[20];
   UShort_t         RecoIsoElecPromtMatched[20];
   Float_t         RecoIsoElecPromtMatchedDeltaR[20];
   Float_t         RecoIsoElecPromtMatchedRelPt[20];
   // isolated track studies
   UShort_t GenMuonIsoTrackMatched[20], RecoIsoMuonIsoTrackMatched[20];
   UShort_t GenElecIsoTrackMatched[20], RecoIsoElecIsoTrackMatched[20];
   UShort_t GenTauIsoTrackMatched[20];
   UShort_t SelectedIsoTracksMatchedToGenLepton[20], SelectedIsoTracksMatchedToRecoIsoLepton[20];
   Float_t SelectedIsoTracksMatchedToGenDeltaR[20], SelectedIsoTracksMatchedToGenRelPT[20];
   Float_t SelectedIsoTracksMatchedToRecoIsoDeltaR[20], SelectedIsoTracksMatchedToRecoIsoRelPT[20];
   
   UShort_t GenMuonIsolatedTracksPT10Matched[20], RecoIsoMuonIsolatedTracksPT10Matched[20];
   UShort_t GenElecIsolatedTracksPT10Matched[20], RecoIsoElecIsolatedTracksPT10Matched[20];
   UShort_t GenTauIsolatedTracksPT10Matched[20];
   UShort_t IsolatedTracksPT10MatchedToGenLepton[20], IsolatedTracksPT10MatchedToRecoIsoLepton[20];
   Float_t IsolatedTracksPT10MatchedToGenDeltaR[20], IsolatedTracksPT10MatchedToGenRelPT[20];
   Float_t IsolatedTracksPT10MatchedToRecoIsoDeltaR[20], IsolatedTracksPT10MatchedToRecoIsoRelPT[20];
   
   UShort_t GenMuonIsolatedTracksPT10IsoCut08Matched[20], RecoIsoMuonIsolatedTracksPT10IsoCut08Matched[20];
   UShort_t GenElecIsolatedTracksPT10IsoCut08Matched[20], RecoIsoElecIsolatedTracksPT10IsoCut08Matched[20];
   UShort_t GenTauIsolatedTracksPT10IsoCut08Matched[20];
   UShort_t IsolatedTracksPT10IsoCut08MatchedToGenLepton[20], IsolatedTracksPT10IsoCut08MatchedToRecoIsoLepton[20];
   Float_t IsolatedTracksPT10IsoCut08MatchedToGenDeltaR[20], IsolatedTracksPT10IsoCut08MatchedToGenRelPT[20];
   Float_t IsolatedTracksPT10IsoCut08MatchedToRecoIsoDeltaR[20], IsolatedTracksPT10IsoCut08MatchedToRecoIsoRelPT[20];
   

   UShort_t GenMuonIsolatedTracksPT10IsoCut12Matched[20], RecoIsoMuonIsolatedTracksPT10IsoCut12Matched[20];
   UShort_t GenElecIsolatedTracksPT10IsoCut12Matched[20], RecoIsoElecIsolatedTracksPT10IsoCut12Matched[20];
   UShort_t GenTauIsolatedTracksPT10IsoCut12Matched[20];
   UShort_t IsolatedTracksPT10IsoCut12MatchedToGenLepton[20], IsolatedTracksPT10IsoCut12MatchedToRecoIsoLepton[20];
   Float_t IsolatedTracksPT10IsoCut12MatchedToGenDeltaR[20], IsolatedTracksPT10IsoCut12MatchedToGenRelPT[20];
   Float_t IsolatedTracksPT10IsoCut12MatchedToRecoIsoDeltaR[20], IsolatedTracksPT10IsoCut12MatchedToRecoIsoRelPT[20];

   
   
   Float_t mtw;

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
   Float_t         RecoIsoMuonPt[20];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonEta[20];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonPhi[20];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonE[20];   //[RecoIsoMuonNum]
   UShort_t        RecoMuonNum;
   Float_t         RecoMuonPt[20];   //[RecoMuonNum]
   Float_t         RecoMuonEta[20];   //[RecoMuonNum]
   Float_t         RecoMuonPhi[20];   //[RecoMuonNum]
   Float_t         RecoMuonE[20];   //[RecoMuonNum]
   UShort_t        RecoIsoElecNum;
   Float_t         RecoIsoElecPt[20];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecEta[20];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecPhi[20];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecE[20];   //[RecoIsoElecNum]
   UShort_t        RecoElecNum;
   Float_t         RecoElecPt[20];   //[RecoElecNum]
   Float_t         RecoElecEta[20];   //[RecoElecNum]
   Float_t         RecoElecPhi[20];   //[RecoElecNum]
   Float_t         RecoElecE[20];   //[RecoElecNum]
   UShort_t        SelectedIsoTracksNum;
   Float_t         SelectedIsoTracksPt[20];   //[SelectedIsoTracksNum]
   Float_t         SelectedIsoTracksEta[20];   //[SelectedIsoTracksNum]
   Float_t         SelectedIsoTracksPhi[20];   //[SelectedIsoTracksNum]
   Float_t         SelectedIsoTracksE[20];   //[SelectedIsoTracksNum]
   //
   
   UShort_t        IsolatedTracksPT10Num;
   Float_t         IsolatedTracksPT10Pt[4];   //[IsolatedTracksPT10Num]
   Float_t         IsolatedTracksPT10Eta[4];   //[IsolatedTracksPT10Num]
   Float_t         IsolatedTracksPT10Phi[4];   //[IsolatedTracksPT10Num]
   Float_t         IsolatedTracksPT10E[4];   //[IsolatedTracksPT10Num]
   UShort_t        IsolatedTracksPT10IsoCut08Num;
   Float_t         IsolatedTracksPT10IsoCut08Pt[4];   //[IsolatedTracksPT10IsoCut08Num]
   Float_t         IsolatedTracksPT10IsoCut08Eta[4];   //[IsolatedTracksPT10IsoCut08Num]
   Float_t         IsolatedTracksPT10IsoCut08Phi[4];   //[IsolatedTracksPT10IsoCut08Num]
   Float_t         IsolatedTracksPT10IsoCut08E[4];   //[IsolatedTracksPT10IsoCut08Num]
   UShort_t        IsolatedTracksPT10IsoCut12Num;
   Float_t         IsolatedTracksPT10IsoCut12Pt[4];   //[IsolatedTracksPT10IsoCut12Num]
   Float_t         IsolatedTracksPT10IsoCut12Eta[4];   //[IsolatedTracksPT10IsoCut12Num]
   Float_t         IsolatedTracksPT10IsoCut12Phi[4];   //[IsolatedTracksPT10IsoCut12Num]
   Float_t         IsolatedTracksPT10IsoCut12E[4];   //[IsolatedTracksPT10IsoCut12Num]
   
   //
   UShort_t        GenWNum;
   Float_t         GenWPt[2];   //[GenWNum]
   Float_t         GenWEta[2];   //[GenWNum]
   Float_t         GenWPhi[2];   //[GenWNum]
   UShort_t        GenMuNum;
   UShort_t        GenMuFromTau[2];   //[GenMuNum]
   Float_t         GenMuPt[2];   //[GenMuNum]
   Float_t         GenMuEta[2];   //[GenMuNum]
   Float_t         GenMuPhi[2];   //[GenMuNum]
   UShort_t        GenElecNum;
   UShort_t        GenElecFromTau[2];   //[GenElecNum]
   Float_t         GenElecPt[2];   //[GenElecNum]
   Float_t         GenElecEta[2];   //[GenElecNum]
   Float_t         GenElecPhi[2];   //[GenElecNum]
   UShort_t        GenTauNum;
   Float_t         GenTauPt[2];   //[GenTauNum]
   Float_t         GenTauEta[2];   //[GenTauNum]
   Float_t         GenTauPhi[2];   //[GenTauNum]
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
   TBranch        *b_SelectedIsoTracksNum;   //!
   TBranch        *b_SelectedIsoTracksPt;   //!
   TBranch        *b_SelectedIsoTracksEta;   //!
   TBranch        *b_SelectedIsoTracksPhi;   //!
   TBranch        *b_SelectedIsoTracksE;   //!
   //
   
   TBranch        *b_IsolatedTracksPT10Num;   //!
   TBranch        *b_IsolatedTracksPT10Pt;   //!
   TBranch        *b_IsolatedTracksPT10Eta;   //!
   TBranch        *b_IsolatedTracksPT10Phi;   //!
   TBranch        *b_IsolatedTracksPT10E;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut08Num;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut08Pt;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut08Eta;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut08Phi;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut08E;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut12Num;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut12Pt;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut12Eta;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut12Phi;   //!
   TBranch        *b_IsolatedTracksPT10IsoCut12E;   //!
   
   
   //
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

   EffMaker(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~EffMaker() { }
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

   ClassDef(EffMaker,0);
};

#endif

#ifdef EffMaker_cxx
void EffMaker::Init(TTree *tree)
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
   fChain->SetBranchAddress("SelectedIsoTracksNum", &SelectedIsoTracksNum, &b_SelectedIsoTracksNum);
   fChain->SetBranchAddress("SelectedIsoTracksPt", SelectedIsoTracksPt, &b_SelectedIsoTracksPt);
   fChain->SetBranchAddress("SelectedIsoTracksEta", SelectedIsoTracksEta, &b_SelectedIsoTracksEta);
   fChain->SetBranchAddress("SelectedIsoTracksPhi", SelectedIsoTracksPhi, &b_SelectedIsoTracksPhi);
   fChain->SetBranchAddress("SelectedIsoTracksE", SelectedIsoTracksE, &b_SelectedIsoTracksE);
   //
   
   fChain->SetBranchAddress("IsolatedTracksPT10Num", &IsolatedTracksPT10Num, &b_IsolatedTracksPT10Num);
   fChain->SetBranchAddress("IsolatedTracksPT10Pt", IsolatedTracksPT10Pt, &b_IsolatedTracksPT10Pt);
   fChain->SetBranchAddress("IsolatedTracksPT10Eta", IsolatedTracksPT10Eta, &b_IsolatedTracksPT10Eta);
   fChain->SetBranchAddress("IsolatedTracksPT10Phi", IsolatedTracksPT10Phi, &b_IsolatedTracksPT10Phi);
   fChain->SetBranchAddress("IsolatedTracksPT10E", IsolatedTracksPT10E, &b_IsolatedTracksPT10E);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut08Num", &IsolatedTracksPT10IsoCut08Num, &b_IsolatedTracksPT10IsoCut08Num);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut08Pt", IsolatedTracksPT10IsoCut08Pt, &b_IsolatedTracksPT10IsoCut08Pt);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut08Eta", IsolatedTracksPT10IsoCut08Eta, &b_IsolatedTracksPT10IsoCut08Eta);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut08Phi", IsolatedTracksPT10IsoCut08Phi, &b_IsolatedTracksPT10IsoCut08Phi);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut08E", IsolatedTracksPT10IsoCut08E, &b_IsolatedTracksPT10IsoCut08E);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut12Num", &IsolatedTracksPT10IsoCut12Num, &b_IsolatedTracksPT10IsoCut12Num);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut12Pt", IsolatedTracksPT10IsoCut12Pt, &b_IsolatedTracksPT10IsoCut12Pt);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut12Eta", IsolatedTracksPT10IsoCut12Eta, &b_IsolatedTracksPT10IsoCut12Eta);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut12Phi", IsolatedTracksPT10IsoCut12Phi, &b_IsolatedTracksPT10IsoCut12Phi);
   fChain->SetBranchAddress("IsolatedTracksPT10IsoCut12E", IsolatedTracksPT10IsoCut12E, &b_IsolatedTracksPT10IsoCut12E);
   
   
   //
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

Bool_t EffMaker::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef EffMaker_cxx
