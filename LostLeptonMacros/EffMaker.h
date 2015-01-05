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
const double minHT_=500;
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

const double maxDeltaRGenToRecoIsoTrack_= 0.3;
const double maxDiffPtGenToRecoIsoTrack_=0.5;


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
// Efficiency studies

const int oneDHT_=14;
double OneDHT_[oneDHT_] = {350,500,550,600,650,700,750,800,900,1000,1200,1500,2000,4000};
const int oneDMHT_=17;
double OneDMHT_[oneDMHT_] = {0,50,100,150,200,250,300,350,400,450,500,600,700,900,1200,1700,4000};
const int oneDNJets_=8;
double OneDNJets_[oneDNJets_] = {2,3,4,5,6,8,11,20};
const int oneDBJets_=6;
double OneDBJets_[oneDBJets_] = {0,1,2,3,5,10};
const int oneDDeltaR_=17;
double OneDDeltaR_[oneDDeltaR_]={0 ,0.1 ,0.2 ,0.3 ,0.4 ,0.5 ,0.6 ,0.7 ,0.8 ,0.9 ,1.0 ,1.1 ,1.3 ,1.5 ,1.8 ,2.0 , 5.0 };
const int oneDPT_=15;
double OneDPT_[oneDPT_]={10,15,20,25,30,40,50,60,70,90,110,150,200,400,1200};
const int oneDPTRel_=17;
double OneDPTRel_[oneDPTRel_]={0 ,0.1 ,0.2 ,0.3 ,0.4 ,0.5 ,0.6 ,0.7 ,0.8 ,0.9 ,1.0 ,1.1 ,1.3 ,1.5 ,1.8 ,2.0 , 5.0 };
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
   
   // efficiency studies TH1 and so on
	 TH1F *MuAccBTag_, *MuAccBTagFail_;
	 TH1F *MuAccNJetS_, *MuAccNJetSFail_;
	 TH1F *MuAccHT_, *MuAccHTFail_;
	 TH1F *MuAccMHT_, *MuAccMHTFail_;
	 
	 TH1F *MuRecoBTag_, *MuRecoBTagFail_;
	 TH1F *MuRecoNJets_, *MuRecoNJetsFail_;
	 TH1F *MuRecoHT_, *MuRecoHTFail_;
	 TH1F *MuRecoMHT_, *MuRecoMHTFail_;	 
	 
	 TH1F *MuIsoBTag_, *MuIsoBTagFail_;
	 TH1F *MuIsoNJets_, *MuIsoNJetsFail_;
	 TH1F *MuIsoHT_, *MuIsoHTFail_;
	 TH1F *MuIsoMHT_, *MuIsoMHTFail_;
	 
	 TH1F *MuMTWBTag_, *MuMTWBTagFail_;
	 TH1F *MuMTWNJets_, *MuMTWNJetsFail_;
	 TH1F *MuMTWHT_, *MuMTWHTFail_;
	 TH1F *MuMTWMHT_, *MuMTWMHTFail_;
	 
	 TH1F *MuPurityBTag_, *MuPurityBTagFail_;
	 TH1F *MuPurityNJets_, *MuPurityNJetsFail_;
	 TH1F *MuPurityHT_, *MuPurityHTFail_;
	 TH1F *MuPurityMHT_, *MuPurityMHTFail_;
	 
	 
	 TH1F *ElecAccBTag_, *ElecAccBTagFail_;
	 TH1F *ElecAccNJetS_, *ElecAccNJetSFail_;
	 TH1F *ElecAccHT_, *ElecAccHTFail_;
	 TH1F *ElecAccMHT_, *ElecAccMHTFail_;
	 
	 TH1F *ElecRecoBTag_, *ElecRecoBTagFail_;
	 TH1F *ElecRecoNJets_, *ElecRecoNJetsFail_;
	 TH1F *ElecRecoHT_, *ElecRecoHTFail_;
	 TH1F *ElecRecoMHT_, *ElecRecoMHTFail_;
	 
	 TH1F *ElecIsoBTag_, *ElecIsoBTagFail_;
	 TH1F *ElecIsoNJets_, *ElecIsoNJetsFail_;
	 TH1F *ElecIsoHT_, *ElecIsoHTFail_;
	 TH1F *ElecIsoMHT_, *ElecIsoMHTFail_;
	 
	 TH1F *ElecMTWBTag_, *ElecMTWBTagFail_;
	 TH1F *ElecMTWNJets_, *ElecMTWNJetsFail_;
	 TH1F *ElecMTWHT_, *ElecMTWHTFail_;
	 TH1F *ElecMTWMHT_, *ElecMTWMHTFail_;
	 
	 TH1F *ElecPurityBTag_, *ElecPurityBTagFail_;
	 TH1F *ElecPurityNJets_, *ElecPurityNJetsFail_;
	 TH1F *ElecPurityHT_, *ElecPurityHTFail_;
	 TH1F *ElecPurityMHT_, *ElecPurityMHTFail_;
	 
	 // pt , delta R relPT
	 TH1F *MuRecoPT_, *MuRecoPTFail_;
	 TH1F *MuRecoDeltaR_, *MuRecoDeltaRFail_;
	 TH1F *MuRecoPTRel_, *MuRecoPTRelFail_;
	 
	 TH1F *MuIsoPT_, *MuIsoPTFail_;
	 TH1F *MuIsoDeltaR_, *MuIsoDeltaRFail_;
	 TH1F *MuIsoPTRel_, *MuIsoPTRelFail_;
	 
	 TH1F *MuMTWPT_, *MuMTWPTFail_;
	 TH1F *MuMTWDeltaR_, *MuMTWDeltaRFail_;
	 TH1F *MuMTWPTRel_, *MuMTWPTRelFail_;
	 
	 
	 TH1F *ElecRecoPT_, *ElecRecoPTFail_;
	 TH1F *ElecRecoDeltaR_, *ElecRecoDeltaRFail_;
	 TH1F *ElecRecoPTRel_, *ElecRecoPTRelFail_;
	 
	 TH1F *ElecIsoPT_, *ElecIsoPTFail_;
	 TH1F *ElecIsoDeltaR_, *ElecIsoDeltaRFail_;
	 TH1F *ElecIsoPTRel_, *ElecIsoPTRelFail_;
	 
	 TH1F *ElecMTWPT_, *ElecMTWPTFail_;
	 TH1F *ElecMTWDeltaR_, *ElecMTWDeltaRFail_;
	 TH1F *ElecMTWPTRel_, *ElecMTWPTRelFail_;
	 
	 // isolated track
	 TH1F *MuIsoTrackBTag_, *MuIsoTrackBTagFail_;
	 TH1F *MuIsoTrackNJets_, *MuIsoTrackNJetsFail_;
	 TH1F *MuIsoTrackHT_, *MuIsoTrackHTFail_;
	 TH1F *MuIsoTrackMHT_, *MuIsoTrackMHTFail_;
	 TH1F *MuIsoTrackPT_, *MuIsoTrackPTFail_;
	 TH1F *MuIsoTrackDeltaR_, *MuIsoTrackDeltaRFail_;
	 TH1F *MuIsoTrackPTRel_, *MuIsoTrackPTRelFail_;
	 
	 TH1F *ElecIsoTrackBTag_, *ElecIsoTrackBTagFail_;
	 TH1F *ElecIsoTrackNJets_, *ElecIsoTrackNJetsFail_;
	 TH1F *ElecIsoTrackHT_, *ElecIsoTrackHTFail_;
	 TH1F *ElecIsoTrackMHT_, *ElecIsoTrackMHTFail_;
	 TH1F *ElecIsoTrackPT_, *ElecIsoTrackPTFail_;
	 TH1F *ElecIsoTrackDeltaR_, *ElecIsoTrackDeltaRFail_;
	 TH1F *ElecIsoTrackPTRel_, *ElecIsoTrackPTRelFail_;
   
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
