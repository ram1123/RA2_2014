#define EffMaker_cxx
// The class definition in EffMaker.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("EffMaker.C")
// Root > T->Process("EffMaker.C","some options")
// Root > T->Process("EffMaker.C+")
//

#include "EffMaker.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include "TSystem.h"

void EffMaker::Begin(TTree * /*tree*/)
{
	// The Begin() function is called at the start of the query.
	// When running with PROOF Begin() is only called on the client.
	// The tree argument is deprecated (on PROOF 0 is passed).
	
	TString option = GetOption();
	MuonIsoLow=NULL;
	MuonIso0=NULL;
	MuonIso1=NULL;
	MuonIso2=NULL;
	MuonRecoLow=NULL;
	MuonReco0=NULL;
	MuonReco1=NULL;
	MuonReco2=NULL;
	MuonAcc=NULL;
	MuMTWNJet=NULL;
	MuMTWMHTNJet=NULL;
	MuDiLepControlSampleMHTNJet=NULL;
	MuDiLepControlSampleMHTNJetMTW=NULL;
	ElecIsoLow=NULL;
	ElecIso0=NULL;
	ElecIso1=NULL;
	ElecIso2=NULL;
	ElecRecoLow=NULL;
	ElecReco0=NULL;
	ElecReco1=NULL;
	ElecReco2=NULL;
	ElecAcc=NULL;
	ElecMTWNJet=NULL;
	ElecMTWMHTNJet=NULL;
	ElecDiLepControlSampleMHTNJet=NULL;
	ElecDiLepControlSampleMHTNJetMTW=NULL;
	
	MuonIsoLowFail=NULL;
	MuonIso0Fail=NULL;
	MuonIso1Fail=NULL;
	MuonIso2Fail=NULL;
	MuonRecoLowFail=NULL;
	MuonReco0Fail=NULL;
	MuonReco1Fail=NULL;
	MuonReco2Fail=NULL;
	MuonAccFail=NULL;
	MuMTWNJetFail=NULL;
	MuMTWMHTNJetFail=NULL;
	MuDiLepControlSampleMHTNJetFail=NULL;
	MuDiLepControlSampleMHTNJetMTWFail=NULL;
	ElecIsoLowFail=NULL;
	ElecIso0Fail=NULL;
	ElecIso1Fail=NULL;
	ElecIso2Fail=NULL;
	ElecRecoLowFail=NULL;
	ElecReco0Fail=NULL;
	ElecReco1Fail=NULL;
	ElecReco2Fail=NULL;
	ElecAccFail=NULL;
	ElecMTWNJetFail=NULL;
	ElecMTWMHTNJetFail=NULL;
	ElecDiLepControlSampleMHTNJetFail=NULL;
	ElecDiLepControlSampleMHTNJetMTWFail=NULL;
	MuonPurityMHTNJet=NULL;
	ElecPurityMHTNJet=NULL;
	MuonPurityMHTNJetFail=NULL;
	ElecPurityMHTNJetFail=NULL;
	
	MuonAccBTag=NULL;
	MuonIsoBTag0=NULL;
	MuonIsoBTag1=NULL;
	MuonIsoBTag2ToInf=NULL;  
	MuonRecoBTag0=NULL;
	MuonRecoBTag1=NULL;
	MuonRecoBTag2ToInf=NULL;  
	MuMTWMHTBTag=NULL;
	ElecAccBTag=NULL;
	ElecIsoBTag0=NULL;
	ElecIsoBTag1=NULL;
	ElecIsoBTag2ToInf=NULL;  
	ElecRecoBTag0=NULL;
	ElecRecoBTag1=NULL;
	ElecRecoBTag2ToInf=NULL;  
	ElecMTWMHTBTag=NULL;
	
	MuonAccBTagFail=NULL;
	MuonIsoBTag0Fail=NULL;
	MuonIsoBTag1Fail=NULL;
	MuonIsoBTag2ToInfFail=NULL;  
	MuonRecoBTag0Fail=NULL;
	MuonRecoBTag1Fail=NULL;
	MuonRecoBTag2ToInfFail=NULL;  
	MuMTWMHTBTagFail=NULL;
	ElecAccBTagFail=NULL;
	ElecIsoBTag0Fail=NULL;
	ElecIsoBTag1Fail=NULL;
	ElecIsoBTag2ToInfFail=NULL;  
	ElecRecoBTag0Fail=NULL;
	ElecRecoBTag1Fail=NULL;
	ElecRecoBTag2ToInfFail=NULL;  
	ElecMTWMHTBTagFail=NULL;
	
	// efficiency studies TH1 and so on
	MuAccBTag_=NULL; MuAccBTagFail_=NULL;
	MuAccNJetS_=NULL; MuAccNJetSFail_=NULL;
	MuAccHT_=NULL; MuAccHTFail_=NULL;
	MuAccMHT_=NULL; MuAccMHTFail_=NULL;
	
	MuRecoBTag_=NULL; MuRecoBTagFail_=NULL;
	MuRecoNJets_=NULL; MuRecoNJetsFail_=NULL;
	MuRecoHT_=NULL; MuRecoHTFail_=NULL;
	MuRecoMHT_=NULL; MuRecoMHTFail_=NULL;
	
	MuIsoBTag_=NULL; MuIsoBTagFail_=NULL;
	MuIsoNJets_=NULL; MuIsoNJetsFail_=NULL;
	MuIsoHT_=NULL; MuIsoHTFail_=NULL;
	MuIsoMHT_=NULL; MuIsoMHTFail_=NULL;
	
	MuMTWBTag_=NULL; MuMTWBTagFail_=NULL;
	MuMTWNJets_=NULL; MuMTWNJetsFail_=NULL;
	MuMTWHT_=NULL; MuMTWHTFail_=NULL;
	MuMTWMHT_=NULL; MuMTWMHTFail_=NULL;
	
	MuPurityBTag_=NULL; MuPurityBTagFail_=NULL;
	MuPurityNJets_=NULL; MuPurityNJetsFail_=NULL;
	MuPurityHT_=NULL; MuPurityHTFail_=NULL;
	MuPurityMHT_=NULL; MuPurityMHTFail_=NULL;
	
	
	ElecAccBTag_=NULL; ElecAccBTagFail_=NULL;
	ElecAccNJetS_=NULL; ElecAccNJetSFail_=NULL;
	ElecAccHT_=NULL; ElecAccHTFail_=NULL;
	ElecAccMHT_=NULL; ElecAccMHTFail_=NULL;
	
	ElecRecoBTag_=NULL; ElecRecoBTagFail_=NULL;
	ElecRecoNJets_=NULL; ElecRecoNJetsFail_=NULL;
	ElecRecoHT_=NULL; ElecRecoHTFail_=NULL;
	ElecRecoMHT_=NULL; ElecRecoMHTFail_=NULL;
	
	ElecIsoBTag_=NULL; ElecIsoBTagFail_=NULL;
	ElecIsoNJets_=NULL; ElecIsoNJetsFail_=NULL;
	ElecIsoHT_=NULL; ElecIsoHTFail_=NULL;
	ElecIsoMHT_=NULL; ElecIsoMHTFail_=NULL;
	
	ElecMTWBTag_=NULL; ElecMTWBTagFail_=NULL;
	ElecMTWNJets_=NULL; ElecMTWNJetsFail_=NULL;
	ElecMTWHT_=NULL; ElecMTWHTFail_=NULL;
	ElecMTWMHT_=NULL; ElecMTWMHTFail_=NULL;
	
	ElecPurityBTag_=NULL; ElecPurityBTagFail_=NULL;
	ElecPurityNJets_=NULL; ElecPurityNJetsFail_=NULL;
	ElecPurityHT_=NULL; ElecPurityHTFail_=NULL;
	ElecPurityMHT_=NULL; ElecPurityMHTFail_=NULL;
	// pt , delta R relPT
	MuRecoPT_=NULL; MuRecoPTFail_=NULL;
	MuRecoDeltaR_=NULL; MuRecoDeltaRFail_=NULL;
	MuRecoPTRel_=NULL; MuRecoPTRelFail_=NULL;
	
	MuIsoPT_=NULL; MuIsoPTFail_=NULL;
	MuIsoDeltaR_=NULL; MuIsoDeltaRFail_=NULL;
	MuIsoPTRel_=NULL; MuIsoPTRelFail_=NULL;
	
	MuMTWPT_=NULL; MuMTWPTFail_=NULL;
	MuMTWDeltaR_=NULL; MuMTWDeltaRFail_=NULL;
	MuMTWPTRel_=NULL; MuMTWPTRelFail_=NULL;
	
	
	ElecRecoPT_=NULL; ElecRecoPTFail_=NULL;
	ElecRecoDeltaR_=NULL; ElecRecoDeltaRFail_=NULL;
	ElecRecoPTRel_=NULL; ElecRecoPTRelFail_=NULL;
	
	ElecIsoPT_=NULL; ElecIsoPTFail_=NULL;
	ElecIsoDeltaR_=NULL; ElecIsoDeltaRFail_=NULL;
	ElecIsoPTRel_=NULL; ElecIsoPTRelFail_=NULL;
	
	ElecMTWPT_=NULL; ElecMTWPTFail_=NULL;
	ElecMTWDeltaR_=NULL; ElecMTWDeltaRFail_=NULL;
	ElecMTWPTRel_=NULL; ElecMTWPTRelFail_=NULL;
	
	
	MuIsoTrackBTag_=NULL; MuIsoTrackBTagFail_=NULL;
	MuIsoTrackNJets_=NULL; MuIsoTrackNJetsFail_=NULL;
	MuIsoTrackHT_=NULL; MuIsoTrackHTFail_=NULL;
	MuIsoTrackMHT_=NULL; MuIsoTrackMHTFail_=NULL;
	MuIsoTrackPT_=NULL; MuIsoTrackPTFail_=NULL;
	MuIsoTrackDeltaR_=NULL; MuIsoTrackDeltaRFail_=NULL;
	MuIsoTrackPTRel_=NULL; MuIsoTrackPTRelFail_=NULL;
	
	ElecIsoTrackBTag_=NULL; ElecIsoTrackBTagFail_=NULL;
	ElecIsoTrackNJets_=NULL; ElecIsoTrackNJetsFail_=NULL;
	ElecIsoTrackHT_=NULL; ElecIsoTrackHTFail_=NULL;
	ElecIsoTrackMHT_=NULL; ElecIsoTrackMHTFail_=NULL;
	ElecIsoTrackPT_=NULL; ElecIsoTrackPTFail_=NULL;
	ElecIsoTrackDeltaR_=NULL; ElecIsoTrackDeltaRFail_=NULL;
	ElecIsoTrackPTRel_=NULL; ElecIsoTrackPTRelFail_=NULL;
	
	
	tExpectation_=NULL;
	//   tExpectation_ = new TTree("LostLeptonExpectation","a simple Tree with simple variables");
	//   tExpectation_->Branch("HT",&HT,"HT/F");
	//   tExpectation_->Branch("MHT",&MHT,"MHT/F");
	
	
}

void EffMaker::SlaveBegin(TTree * /*tree*/)
{
	// The SlaveBegin() function is called after the Begin() function.
	// When running with PROOF SlaveBegin() is called on each slave server.
	// The tree argument is deprecated (on PROOF 0 is passed).
	
	TString option = GetOption();
	// histograms for efficiencies
	MuonIsoLow = new TH2F("MuonIsoNJet2Jet","MuonIsoNJet2Jet",muIsoHTLow_-1,MuIsoHTLow_,muIsoMHTLow_-1,MuIsoMHTLow_);
	GetOutputList()->Add(MuonIsoLow);
	MuonIsoLowFail = (TH2F*)MuonIsoLow->Clone();
	MuonIsoLowFail->SetName("MuonIsoLowFail");
	GetOutputList()->Add(MuonIsoLowFail);
	
	MuonIso0 = new TH2F("MuonIsoNJetLow","MuonIsoNJetLow",muIsoHT0_-1,MuIsoHT0_,muIsoMHT0_-1,MuIsoMHT0_);
	GetOutputList()->Add(MuonIso0);
	MuonIso0Fail = (TH2F*)MuonIso0->Clone();
	MuonIso0Fail->SetName("MuonIso0Fail");
	GetOutputList()->Add(MuonIso0Fail);
	
	MuonIso1 = new TH2F("MuonIsoNJetMedium","MuonIsoNJetMedium",muIsoHT1_-1,MuIsoHT1_,muIsoMHT1_-1,MuIsoMHT1_);
	GetOutputList()->Add(MuonIso1);
	MuonIso1Fail = (TH2F*)MuonIso1->Clone();
	MuonIso1Fail->SetName("MuonIso1Fail");
	GetOutputList()->Add(MuonIso1Fail);
	
	MuonIso2 = new TH2F("MuonIsoNJetHgih","MuonIsoNJetHigh",muIsoHT2_-1,MuIsoHT2_,muIsoMHT2_-1,MuIsoMHT2_);
	GetOutputList()->Add(MuonIso2);
	MuonIso2Fail = (TH2F*)MuonIso2->Clone();
	MuonIso2Fail->SetName("MuonIso2Fail");
	GetOutputList()->Add(MuonIso2Fail);
	
	MuonRecoLow = new TH2F("MuonRecoNJet2Jet","MuonRecoNJet2Jet",muRecoHTLow_-1,MuRecoHTLow_,muRecoMHTLow_-1,MuRecoMHTLow_);
	GetOutputList()->Add(MuonRecoLow);
	MuonRecoLowFail = (TH2F*)MuonRecoLow->Clone();
	MuonRecoLowFail->SetName("MuonRecoLowFail");
	GetOutputList()->Add(MuonRecoLowFail);
	
	MuonReco0 = new TH2F("MuonRecoNJetLow","MuonRecoNJetLow",muRecoHT0_-1,MuRecoHT0_,muRecoMHT0_-1,MuRecoMHT0_);
	GetOutputList()->Add(MuonReco0);
	MuonReco0Fail = (TH2F*)MuonReco0->Clone();
	MuonReco0Fail->SetName("MuonReco0Fail");
	GetOutputList()->Add(MuonReco0Fail);
	
	MuonReco1 = new TH2F("MuonRecoNJetMedium","MuonRecoNJetMedium",muRecoHT1_-1,MuRecoHT1_,muRecoMHT1_-1,MuRecoMHT1_);
	GetOutputList()->Add(MuonReco1);
	MuonReco1Fail = (TH2F*)MuonReco1->Clone();
	MuonReco1Fail->SetName("MuonReco1Fail");
	GetOutputList()->Add(MuonReco1Fail);
	
	MuonReco2 = new TH2F("MuonRecoNJetHgih","MuonRecoNJetHigh",muRecoHT2_-1,MuRecoHT2_,muRecoMHT2_-1,MuRecoMHT2_);
	GetOutputList()->Add(MuonReco2);
	MuonReco2Fail = (TH2F*)MuonReco2->Clone();
	MuonReco2Fail->SetName("MuonReco2Fail");
	GetOutputList()->Add(MuonReco2Fail);
	
	MuonAcc = new TH2F("MuonAcc","MuonAcc",muAccMht_-1,MuAccMht_,muAccNJets_-1,MuAccNJets_);
	GetOutputList()->Add(MuonAcc);
	MuonAccFail = (TH2F*)MuonAcc->Clone();
	MuonAccFail->SetName("MuonAccFail");
	GetOutputList()->Add(MuonAccFail);
	
	MuMTWNJet = new TH1F("MuMTW","MuMTW",mumtwNjet_-1,muMtwNjet_);
	GetOutputList()->Add(MuMTWNJet);
	MuMTWNJetFail = (TH1F*)MuMTWNJet->Clone();
	MuMTWNJetFail->SetName("MuMTWNJetFail");
	GetOutputList()->Add(MuMTWNJetFail);
	
	MuMTWMHTNJet = new TH2F("MuMTWMHTNjet","MuMTWMHTNjet",mumtwMHT_-1,muMtwMHT_,mumtwNjet_-1,muMtwNjet_);
	GetOutputList()->Add(MuMTWMHTNJet);
	MuMTWMHTNJetFail = (TH2F*)MuMTWMHTNJet->Clone();
	MuMTWMHTNJetFail->SetName("MuMTWMHTNJetFail");
	GetOutputList()->Add(MuMTWMHTNJetFail);
	
	
	ElecIsoLow = new TH2F("ElecIsoNJet2Jet","ElecIsoNJet2Jet",elecIsoHTLow_-1,ElecIsoHTLow_,elecIsoMHTLow_-1,ElecIsoMHTLow_);
	GetOutputList()->Add(ElecIsoLow);
	ElecIsoLowFail = (TH2F*)ElecIsoLow->Clone();
	ElecIsoLowFail->SetName("ElecIsoLowFail");
	GetOutputList()->Add(ElecIsoLowFail);
	
	ElecIso0 = new TH2F("ElecIsoNJetLow","ElecIsoNJetLow",elecIsoHT0_-1,ElecIsoHT0_,elecIsoMHT0_-1,ElecIsoMHT0_);
	GetOutputList()->Add(ElecIso0);
	ElecIso0Fail = (TH2F*)ElecIso0->Clone();
	ElecIso0Fail->SetName("ElecIso0Fail");
	GetOutputList()->Add(ElecIso0Fail);
	
	ElecIso1 = new TH2F("ElecIsoNJetMedium","ElecIsoNJetMedium",elecIsoHT1_-1,ElecIsoHT1_,elecIsoMHT1_-1,ElecIsoMHT1_);
	GetOutputList()->Add(ElecIso1);
	ElecIso1Fail = (TH2F*)ElecIso1->Clone();
	ElecIso1Fail->SetName("ElecIso1Fail");
	GetOutputList()->Add(ElecIso1Fail);
	
	ElecIso2 = new TH2F("ElecIsoNJetHgih","ElecIsoNJetHigh",elecIsoHT2_-1,ElecIsoHT2_,elecIsoMHT2_-1,ElecIsoMHT2_);
	GetOutputList()->Add(ElecIso2);
	ElecIso2Fail = (TH2F*)ElecIso2->Clone();
	ElecIso2Fail->SetName("ElecIso2Fail");
	GetOutputList()->Add(ElecIso2Fail);
	
	ElecRecoLow = new TH2F("ElecRecoNJet2Jet","ElecRecoNJet2Jet",elecRecoHTLow_-1,ElecRecoHTLow_,elecRecoMHTLow_-1,ElecRecoMHTLow_);
	GetOutputList()->Add(ElecRecoLow);
	ElecRecoLowFail = (TH2F*)ElecRecoLow->Clone();
	ElecRecoLowFail->SetName("ElecRecoLowFail");
	GetOutputList()->Add(ElecRecoLowFail);
	
	ElecReco0 = new TH2F("ElecRecoNJetLow","ElecRecoNJetLow",elecRecoHT0_-1,ElecRecoHT0_,elecRecoMHT0_-1,ElecRecoMHT0_);
	GetOutputList()->Add(ElecReco0);
	ElecReco0Fail = (TH2F*)ElecReco0->Clone();
	ElecReco0Fail->SetName("ElecReco0Fail");
	GetOutputList()->Add(ElecReco0Fail);
	
	ElecReco1 = new TH2F("ElecRecoNJetMedium","ElecRecoNJetMedium",elecRecoHT1_-1,ElecRecoHT1_,elecRecoMHT1_-1,ElecRecoMHT1_);
	GetOutputList()->Add(ElecReco1);
	ElecReco1Fail = (TH2F*)ElecReco1->Clone();
	ElecReco1Fail->SetName("ElecReco1Fail");
	GetOutputList()->Add(ElecReco1Fail);
	
	ElecReco2 = new TH2F("ElecRecoNJetHgih","ElecRecoNJetHigh",elecRecoHT2_-1,ElecRecoHT2_,elecRecoMHT2_-1,ElecRecoMHT2_);
	GetOutputList()->Add(ElecReco2);
	ElecReco2Fail = (TH2F*)ElecReco2->Clone();
	ElecReco2Fail->SetName("ElecReco2Fail");
	GetOutputList()->Add(ElecReco2Fail);
	
	ElecAcc = new TH2F("ElecAcc","ElecAcc",elecAccMht_-1,ElecAccMht_,elecAccNJets_-1,ElecAccNJets_);
	GetOutputList()->Add(ElecAcc);
	ElecAccFail = (TH2F*)ElecAcc->Clone();
	ElecAccFail->SetName("ElecAccFail");
	GetOutputList()->Add(ElecAccFail);
	
	ElecMTWNJet = new TH1F("ElecMTW","ElecMTW",elecmtwNjet_-1,elecMtwNjet_);
	GetOutputList()->Add(ElecMTWNJet);
	ElecMTWNJetFail = (TH1F*)ElecMTWNJet->Clone();
	ElecMTWNJetFail->SetName("ElecMTWNJetFail");
	GetOutputList()->Add(ElecMTWNJetFail);
	
	ElecMTWMHTNJet = new TH2F("ElecMTWMHTNjet","ElecMTWMHTNjet",elecmtwMHT_-1,elecMtwMHT_,elecmtwNjet_-1,elecMtwNjet_);
	GetOutputList()->Add(ElecMTWMHTNJet);
	ElecMTWMHTNJetFail = (TH2F*)ElecMTWMHTNJet->Clone();
	ElecMTWMHTNJetFail->SetName("ElecMTWMHTNJetFail");
	GetOutputList()->Add(ElecMTWMHTNJetFail);
	
	MuonPurityMHTNJet = new TH2F("MuonPurity","MuonPurity",mupurityMHT_-1,muPurityMHT_,mupurityNJet_-1,muPurityNJet_);
	GetOutputList()->Add(MuonPurityMHTNJet);
	MuonPurityMHTNJetFail = (TH2F*)MuonPurityMHTNJet->Clone();
	MuonPurityMHTNJetFail->SetName("MuonPurityFail");
	GetOutputList()->Add(MuonPurityMHTNJetFail);  
	
	ElecPurityMHTNJet = new TH2F("ElecPurity","ElecPurity",elecpurityMHT_-1,elecPurityMHT_,elecpurityNJet_-1,elecPurityNJet_);
	GetOutputList()->Add(ElecPurityMHTNJet);
	ElecPurityMHTNJetFail = (TH2F*)ElecPurityMHTNJet->Clone();
	ElecPurityMHTNJetFail->SetName("ElecPurityFail");
	GetOutputList()->Add(ElecPurityMHTNJetFail); 
	
	MuDiLepControlSampleMHTNJet = new TH2F("MuonDiLep","MuonDiLep",mudilepMHT_-1,muDilepMHT_,mudilepNJet_-1,muDilepNJet_);
	GetOutputList()->Add(MuDiLepControlSampleMHTNJet);
	MuDiLepControlSampleMHTNJetFail = (TH2F*)MuDiLepControlSampleMHTNJet->Clone();
	MuDiLepControlSampleMHTNJetFail->SetName("MuonDiLepFail");
	GetOutputList()->Add(MuDiLepControlSampleMHTNJetFail);  
	
	ElecDiLepControlSampleMHTNJet = new TH2F("EleconDiLep","EleconDiLep",elecdilepMHT_-1,elecDilepMHT_,elecdilepNJet_-1,elecDilepNJet_);
	GetOutputList()->Add(ElecDiLepControlSampleMHTNJet);
	ElecDiLepControlSampleMHTNJetFail = (TH2F*)ElecDiLepControlSampleMHTNJet->Clone();
	ElecDiLepControlSampleMHTNJetFail->SetName("ElecDiLepFail");
	GetOutputList()->Add(ElecDiLepControlSampleMHTNJetFail);  
	
	MuDiLepControlSampleMHTNJetMTW = new TH2F("MuonDiLepMTW","MuonDiLepMTW",mudilepMHT_-1,muDilepMHT_,mudilepNJet_-1,muDilepNJet_);
	GetOutputList()->Add(MuDiLepControlSampleMHTNJetMTW);
	MuDiLepControlSampleMHTNJetMTWFail = (TH2F*)MuDiLepControlSampleMHTNJetMTW->Clone();
	MuDiLepControlSampleMHTNJetMTWFail->SetName("MuonDiLepMTWFail");
	GetOutputList()->Add(MuDiLepControlSampleMHTNJetMTWFail);  
	
	ElecDiLepControlSampleMHTNJetMTW = new TH2F("EleconDiLepMTW","EleconDiLepMTW",elecdilepMHT_-1,elecDilepMHT_,elecdilepNJet_-1,elecDilepNJet_);
	GetOutputList()->Add(ElecDiLepControlSampleMHTNJetMTW);
	ElecDiLepControlSampleMHTNJetMTWFail = (TH2F*)ElecDiLepControlSampleMHTNJetMTW->Clone();
	ElecDiLepControlSampleMHTNJetMTWFail->SetName("ElecDiLepMTWFail");
	GetOutputList()->Add(ElecDiLepControlSampleMHTNJetMTWFail); 
	
	MuDiLepEffNJets = new TH1F("MuonDiLepEff","MuonDiLepEff",muilepEffNJet_-1,muiLepEffNJet_);
	GetOutputList()->Add(MuDiLepEffNJets);
	MuDiLepEffNJetsFail = (TH1F*)MuDiLepEffNJets->Clone();
	MuDiLepEffNJetsFail->SetName("MuDiLepEffNJetsFail");
	GetOutputList()->Add(MuDiLepEffNJetsFail); 
	
	ElecDiLepEffNJets = new TH1F("ElecDiLepEff","ElecDiLepEff",muilepEffNJet_-1,muiLepEffNJet_);
	GetOutputList()->Add(ElecDiLepEffNJets);
	ElecDiLepEffNJetsFail = (TH1F*)ElecDiLepEffNJets->Clone();
	ElecDiLepEffNJetsFail->SetName("ElecDiLepEffNJetsFail");
	GetOutputList()->Add(ElecDiLepEffNJetsFail); 
	
	// btag instead of njets
	MuonAccBTag = new TH2F("MuonAccBTag","MuonAccBTag",muonAccBTagMHT_-1,MuAccBTagMHT_,muonAccBTagB_-1,MuAccBTagB_);
	GetOutputList()->Add(MuonAccBTag);
	MuonAccBTagFail = (TH2F*)MuonAccBTag->Clone();
	MuonAccBTagFail->SetName("MuonAccBTagFail");
	GetOutputList()->Add(MuonAccBTagFail); 
	
	MuonIsoBTag0 = new TH2F("MuonIsoBTag0","MuonIsoBTag0",muIsoBTagHT0_-1,MuIsoBTagHT0_,muIsoBTagMHT0_-1,MuIsoBTagMHT0_);
	GetOutputList()->Add(MuonIsoBTag0);
	MuonIsoBTag0Fail = (TH2F*)MuonIsoBTag0->Clone();
	MuonIsoBTag0Fail->SetName("MuonIsoBTag0Fail");
	GetOutputList()->Add(MuonIsoBTag0Fail); 
	
	MuonIsoBTag1 = new TH2F("MuonIsoBTag1","MuonIsoBTag1",muIsoBTagHT1_-1,MuIsoBTagHT1_,muIsoBTagMHT1_-1,MuIsoBTagMHT1_);
	GetOutputList()->Add(MuonIsoBTag1);
	MuonIsoBTag1Fail = (TH2F*)MuonIsoBTag1->Clone();
	MuonIsoBTag1Fail->SetName("MuonIsoBTag1Fail");
	GetOutputList()->Add(MuonIsoBTag1Fail); 
	
	MuonIsoBTag2ToInf = new TH2F("MuonIsoBTag2ToInf","MuonIsoBTag2ToInf",muIsoBTagHT2ToInf_-1,MuIsoBTagHT2ToInf_,muIsoBTagMHT2ToInf_-1,MuIsoBTagMHT2ToInf_);
	GetOutputList()->Add(MuonIsoBTag2ToInf);
	MuonIsoBTag2ToInfFail = (TH2F*)MuonIsoBTag2ToInf->Clone();
	MuonIsoBTag2ToInfFail->SetName("MuonIsoBTag2ToInfFail");
	GetOutputList()->Add(MuonIsoBTag2ToInfFail); 
	
	MuonRecoBTag0 = new TH2F("MuonRecoBTag0","MuonRecoBTag0",muRecoBTagHT0_-1,MuRecoBTagHT0_,muRecoBTagMHT0_-1,MuRecoBTagMHT0_);
	GetOutputList()->Add(MuonRecoBTag0);
	MuonRecoBTag0Fail = (TH2F*)MuonRecoBTag0->Clone();
	MuonRecoBTag0Fail->SetName("MuonRecoBTag0Fail");
	GetOutputList()->Add(MuonRecoBTag0Fail); 
	
	MuonRecoBTag1 = new TH2F("MuonRecoBTag1","MuonRecoBTag1",muRecoBTagHT1_-1,MuRecoBTagHT1_,muRecoBTagMHT1_-1,MuRecoBTagMHT1_);
	GetOutputList()->Add(MuonRecoBTag1);
	MuonRecoBTag1Fail = (TH2F*)MuonRecoBTag1->Clone();
	MuonRecoBTag1Fail->SetName("MuonRecoBTag1Fail");
	GetOutputList()->Add(MuonRecoBTag1Fail); 
	
	MuonRecoBTag2ToInf = new TH2F("MuonRecoBTag2ToInf","MuonRecoBTag2ToInf",muRecoBTagHT2ToInf_-1,MuRecoBTagHT2ToInf_,muRecoBTagMHT2ToInf_-1,MuRecoBTagMHT2ToInf_);
	GetOutputList()->Add(MuonRecoBTag2ToInf);
	MuonRecoBTag2ToInfFail = (TH2F*)MuonRecoBTag2ToInf->Clone();
	MuonRecoBTag2ToInfFail->SetName("MuonRecoBTag2ToInfFail");
	GetOutputList()->Add(MuonRecoBTag2ToInfFail); 
	
	MuMTWMHTBTag = new TH2F("MuMTWMHTBTag","MuMTWMHTBTag",mumtwBTagB_-1,muMtwBTagB_,mumtwMHTBTag_-1,muMtwMHTBTag_);
	GetOutputList()->Add(MuMTWMHTBTag);
	MuMTWMHTBTagFail = (TH2F*)MuMTWMHTBTag->Clone();
	MuMTWMHTBTagFail->SetName("MuMTWMHTBTagFail");
	GetOutputList()->Add(MuMTWMHTBTagFail); 
	
	
	ElecAccBTag = new TH2F("ElecAccBTag","ElecAccBTag",elecAccBTagMHT_-1,ElecAccBTagMHT_,elecAccBTagB_-1,ElecAccBTagB_);
	GetOutputList()->Add(ElecAccBTag);
	ElecAccBTagFail = (TH2F*)ElecAccBTag->Clone();
	ElecAccBTagFail->SetName("ElecAccBTagFail");
	GetOutputList()->Add(ElecAccBTagFail); 
	
	ElecIsoBTag0 = new TH2F("ElecIsoBTag0","ElecIsoBTag0",elecIsoBTagHT0_-1,ElecIsoBTagHT0_,elecIsoBTagMHT0_-1,ElecIsoBTagMHT0_);
	GetOutputList()->Add(ElecIsoBTag0);
	ElecIsoBTag0Fail = (TH2F*)ElecIsoBTag0->Clone();
	ElecIsoBTag0Fail->SetName("ElecIsoBTag0Fail");
	GetOutputList()->Add(ElecIsoBTag0Fail); 
	
	ElecIsoBTag1 = new TH2F("ElecIsoBTag1","ElecIsoBTag1",elecIsoBTagHT1_-1,ElecIsoBTagHT1_,elecIsoBTagMHT1_-1,ElecIsoBTagMHT1_);
	GetOutputList()->Add(ElecIsoBTag1);
	ElecIsoBTag1Fail = (TH2F*)ElecIsoBTag1->Clone();
	ElecIsoBTag1Fail->SetName("ElecIsoBTag1Fail");
	GetOutputList()->Add(ElecIsoBTag1Fail); 
	
	ElecIsoBTag2ToInf = new TH2F("ElecIsoBTag2ToInf","ElecIsoBTag2ToInf",elecIsoBTagHT2ToInf_-1,ElecIsoBTagHT2ToInf_,elecIsoBTagMHT2ToInf_-1,ElecIsoBTagMHT2ToInf_);
	GetOutputList()->Add(ElecIsoBTag2ToInf);
	ElecIsoBTag2ToInfFail = (TH2F*)ElecIsoBTag2ToInf->Clone();
	ElecIsoBTag2ToInfFail->SetName("ElecIsoBTag2ToInfFail");
	GetOutputList()->Add(ElecIsoBTag2ToInfFail); 
	
	ElecRecoBTag0 = new TH2F("ElecRecoBTag0","ElecRecoBTag0",elecRecoBTagHT0_-1,ElecRecoBTagHT0_,elecRecoBTagMHT0_-1,ElecRecoBTagMHT0_);
	GetOutputList()->Add(ElecRecoBTag0);
	ElecRecoBTag0Fail = (TH2F*)ElecRecoBTag0->Clone();
	ElecRecoBTag0Fail->SetName("ElecRecoBTag0Fail");
	GetOutputList()->Add(ElecRecoBTag0Fail); 
	
	ElecRecoBTag1 = new TH2F("ElecRecoBTag1","ElecRecoBTag1",elecRecoBTagHT1_-1,ElecRecoBTagHT1_,elecRecoBTagMHT1_-1,ElecRecoBTagMHT1_);
	GetOutputList()->Add(ElecRecoBTag1);
	ElecRecoBTag1Fail = (TH2F*)ElecRecoBTag1->Clone();
	ElecRecoBTag1Fail->SetName("ElecRecoBTag1Fail");
	GetOutputList()->Add(ElecRecoBTag1Fail); 
	
	ElecRecoBTag2ToInf = new TH2F("ElecRecoBTag2ToInf","ElecRecoBTag2ToInf",elecRecoBTagHT2ToInf_-1,ElecRecoBTagHT2ToInf_,elecRecoBTagMHT2ToInf_-1,ElecRecoBTagMHT2ToInf_);
	GetOutputList()->Add(ElecRecoBTag2ToInf);
	ElecRecoBTag2ToInfFail = (TH2F*)ElecRecoBTag2ToInf->Clone();
	ElecRecoBTag2ToInfFail->SetName("ElecRecoBTag2ToInfFail");
	GetOutputList()->Add(ElecRecoBTag2ToInfFail); 
	
	ElecMTWMHTBTag = new TH2F("ElecMTWMHTBTag","ElecMTWMHTBTag",elecmtwBTagB_-1,elecMtwBTagB_,elecmtwMHTBTag_-1,elecMtwMHTBTag_);
	GetOutputList()->Add(ElecMTWMHTBTag);
	ElecMTWMHTBTagFail = (TH2F*)ElecMTWMHTBTag->Clone();
	ElecMTWMHTBTagFail->SetName("ElecMTWMHTBTagFail");
	GetOutputList()->Add(ElecMTWMHTBTagFail); 
	
	// efficiency studies TH1 and so on
	MuAccBTag_ = new TH1F("MuAccBTag1D","MuAccBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(MuAccBTag_);
	MuAccBTagFail_ = (TH1F*)MuAccBTag_->Clone();
	MuAccBTagFail_->SetName("MuAccBTag1DFail");
	GetOutputList()->Add(MuAccBTagFail_); 
	
	MuAccNJetS_ = new TH1F("MuAccNJetS1D","MuAccNJetS1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(MuAccNJetS_);
	MuAccNJetSFail_ = (TH1F*)MuAccNJetS_->Clone();
	MuAccNJetSFail_->SetName("MuAccNJetS1DFail");
	GetOutputList()->Add(MuAccNJetSFail_); 
	
	MuAccHT_ = new TH1F("MuAccHT1D","MuAccHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(MuAccHT_);
	MuAccHTFail_ = (TH1F*)MuAccHT_->Clone();
	MuAccHTFail_->SetName("MuAccHT1DFail");
	GetOutputList()->Add(MuAccHTFail_); 
	
	MuAccMHT_ = new TH1F("MuAccMHT1D","MuAccMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(MuAccMHT_);
	MuAccMHTFail_ = (TH1F*)MuAccMHT_->Clone();
	MuAccMHTFail_->SetName("MuAccMHT1DFail");
	GetOutputList()->Add(MuAccMHTFail_); 
	
	
	MuRecoBTag_ = new TH1F("MuRecoBTag1D","MuRecoBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(MuRecoBTag_);
	MuRecoBTagFail_ = (TH1F*)MuRecoBTag_->Clone();
	MuRecoBTagFail_->SetName("MuRecoBTag1DFail");
	GetOutputList()->Add(MuRecoBTagFail_); 
	
	MuRecoNJets_ = new TH1F("MuRecoNJets1D","MuRecoNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(MuRecoNJets_);
	MuRecoNJetsFail_ = (TH1F*)MuRecoNJets_->Clone();
	MuRecoNJetsFail_->SetName("MuRecoNJets1DFail");
	GetOutputList()->Add(MuRecoNJetsFail_); 
	
	MuRecoHT_ = new TH1F("MuRecoHT1D","MuRecoHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(MuRecoHT_);
	MuRecoHTFail_ = (TH1F*)MuRecoHT_->Clone();
	MuRecoHTFail_->SetName("MuRecoHT1DFail");
	GetOutputList()->Add(MuRecoHTFail_); 
	
	MuRecoMHT_ = new TH1F("MuRecoMHT1D","MuRecoMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(MuRecoMHT_);
	MuRecoMHTFail_ = (TH1F*)MuRecoMHT_->Clone();
	MuRecoMHTFail_->SetName("MuRecoMHT1DFail");
	GetOutputList()->Add(MuRecoMHTFail_); 
	
	
	MuIsoBTag_ = new TH1F("MuIsoBTag1D","MuIsoBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(MuIsoBTag_);
	MuIsoBTagFail_ = (TH1F*)MuIsoBTag_->Clone();
	MuIsoBTagFail_->SetName("MuIsoBTag1DFail");
	GetOutputList()->Add(MuIsoBTagFail_); 
	
	MuIsoNJets_ = new TH1F("MuIsoNJets1D","MuIsoNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(MuIsoNJets_);
	MuIsoNJetsFail_ = (TH1F*)MuIsoNJets_->Clone();
	MuIsoNJetsFail_->SetName("MuIsoNJets1DFail");
	GetOutputList()->Add(MuIsoNJetsFail_); 
	
	MuIsoHT_ = new TH1F("MuIsoHT1D","MuIsoHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(MuIsoHT_);
	MuIsoHTFail_ = (TH1F*)MuIsoHT_->Clone();
	MuIsoHTFail_->SetName("MuIsoHT1DFail");
	GetOutputList()->Add(MuIsoHTFail_); 
	
	MuIsoMHT_ = new TH1F("MuIsoMHT1D","MuIsoMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(MuIsoMHT_);
	MuIsoMHTFail_ = (TH1F*)MuIsoMHT_->Clone();
	MuIsoMHTFail_->SetName("MuIsoMHT1DFail");
	GetOutputList()->Add(MuIsoMHTFail_); 
	
	
	MuMTWBTag_ = new TH1F("MuMTWBTag1D","MuMTWBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(MuMTWBTag_);
	MuMTWBTagFail_ = (TH1F*)MuMTWBTag_->Clone();
	MuMTWBTagFail_->SetName("MuMTWBTag1DFail");
	GetOutputList()->Add(MuMTWBTagFail_); 
	
	MuMTWNJets_ = new TH1F("MuMTWNJets1D","MuMTWNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(MuMTWNJets_);
	MuMTWNJetsFail_ = (TH1F*)MuMTWNJets_->Clone();
	MuMTWNJetsFail_->SetName("MuMTWNJets1DFail");
	GetOutputList()->Add(MuMTWNJetsFail_); 
	
	MuMTWHT_ = new TH1F("MuMTWHT1D","MuMTWHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(MuMTWHT_);
	MuMTWHTFail_ = (TH1F*)MuMTWHT_->Clone();
	MuMTWHTFail_->SetName("MuMTWHT1DFail");
	GetOutputList()->Add(MuMTWHTFail_); 
	
	MuMTWMHT_ = new TH1F("MuMTWMHT1D","MuMTWMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(MuMTWMHT_);
	MuMTWMHTFail_ = (TH1F*)MuMTWMHT_->Clone();
	MuMTWMHTFail_->SetName("MuMTWMHT1DFail");
	GetOutputList()->Add(MuMTWMHTFail_); 
	
	
	MuPurityBTag_ = new TH1F("MuPurityBTag1D","MuPurityBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(MuPurityBTag_);
	MuPurityBTagFail_ = (TH1F*)MuPurityBTag_->Clone();
	MuPurityBTagFail_->SetName("MuPurityBTag1DFail");
	GetOutputList()->Add(MuPurityBTagFail_); 
	
	MuPurityNJets_ = new TH1F("MuPurityNJets1D","MuPurityNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(MuPurityNJets_);
	MuPurityNJetsFail_ = (TH1F*)MuPurityNJets_->Clone();
	MuPurityNJetsFail_->SetName("MuPurityNJets1DFail");
	GetOutputList()->Add(MuPurityNJetsFail_); 
	
	MuPurityHT_ = new TH1F("MuPurityHT1D","MuPurityHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(MuPurityHT_);
	MuPurityHTFail_ = (TH1F*)MuPurityHT_->Clone();
	MuPurityHTFail_->SetName("MuPurityHT1DFail");
	GetOutputList()->Add(MuPurityHTFail_); 
	
	MuPurityMHT_ = new TH1F("MuPurityMHT1D","MuPurityMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(MuPurityMHT_);
	MuPurityMHTFail_ = (TH1F*)MuPurityMHT_->Clone();
	MuPurityMHTFail_->SetName("MuPurityMHT1DFail");
	GetOutputList()->Add(MuPurityMHTFail_); 
	
	
	
	
	
	ElecAccBTag_ = new TH1F("ElecAccBTag1D","ElecAccBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(ElecAccBTag_);
	ElecAccBTagFail_ = (TH1F*)ElecAccBTag_->Clone();
	ElecAccBTagFail_->SetName("ElecAccBTag1DFail");
	GetOutputList()->Add(ElecAccBTagFail_); 
	
	ElecAccNJetS_ = new TH1F("ElecAccNJetS1D","ElecAccNJetS1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(ElecAccNJetS_);
	ElecAccNJetSFail_ = (TH1F*)ElecAccNJetS_->Clone();
	ElecAccNJetSFail_->SetName("ElecAccNJetS1DFail");
	GetOutputList()->Add(ElecAccNJetSFail_); 
	
	ElecAccHT_ = new TH1F("ElecAccHT1D","ElecAccHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(ElecAccHT_);
	ElecAccHTFail_ = (TH1F*)ElecAccHT_->Clone();
	ElecAccHTFail_->SetName("ElecAccHT1DFail");
	GetOutputList()->Add(ElecAccHTFail_); 
	
	ElecAccMHT_ = new TH1F("ElecAccMHT1D","ElecAccMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(ElecAccMHT_);
	ElecAccMHTFail_ = (TH1F*)ElecAccMHT_->Clone();
	ElecAccMHTFail_->SetName("ElecAccMHT1DFail");
	GetOutputList()->Add(ElecAccMHTFail_); 
	
	
	ElecRecoBTag_ = new TH1F("ElecRecoBTag1D","ElecRecoBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(ElecRecoBTag_);
	ElecRecoBTagFail_ = (TH1F*)ElecRecoBTag_->Clone();
	ElecRecoBTagFail_->SetName("ElecRecoBTag1DFail");
	GetOutputList()->Add(ElecRecoBTagFail_); 
	
	ElecRecoNJets_ = new TH1F("ElecRecoNJets1D","ElecRecoNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(ElecRecoNJets_);
	ElecRecoNJetsFail_ = (TH1F*)ElecRecoNJets_->Clone();
	ElecRecoNJetsFail_->SetName("ElecRecoNJets1DFail");
	GetOutputList()->Add(ElecRecoNJetsFail_); 
	
	ElecRecoHT_ = new TH1F("ElecRecoHT1D","ElecRecoHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(ElecRecoHT_);
	ElecRecoHTFail_ = (TH1F*)ElecRecoHT_->Clone();
	ElecRecoHTFail_->SetName("ElecRecoHT1DFail");
	GetOutputList()->Add(ElecRecoHTFail_); 
	
	ElecRecoMHT_ = new TH1F("ElecRecoMHT1D","ElecRecoMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(ElecRecoMHT_);
	ElecRecoMHTFail_ = (TH1F*)ElecRecoMHT_->Clone();
	ElecRecoMHTFail_->SetName("ElecRecoMHT1DFail");
	GetOutputList()->Add(ElecRecoMHTFail_); 
	
	
	ElecIsoBTag_ = new TH1F("ElecIsoBTag1D","ElecIsoBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(ElecIsoBTag_);
	ElecIsoBTagFail_ = (TH1F*)ElecIsoBTag_->Clone();
	ElecIsoBTagFail_->SetName("ElecIsoBTag1DFail");
	GetOutputList()->Add(ElecIsoBTagFail_); 
	
	ElecIsoNJets_ = new TH1F("ElecIsoNJets1D","ElecIsoNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(ElecIsoNJets_);
	ElecIsoNJetsFail_ = (TH1F*)ElecIsoNJets_->Clone();
	ElecIsoNJetsFail_->SetName("ElecIsoNJets1DFail");
	GetOutputList()->Add(ElecIsoNJetsFail_); 
	
	ElecIsoHT_ = new TH1F("ElecIsoHT1D","ElecIsoHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(ElecIsoHT_);
	ElecIsoHTFail_ = (TH1F*)ElecIsoHT_->Clone();
	ElecIsoHTFail_->SetName("ElecIsoHT1DFail");
	GetOutputList()->Add(ElecIsoHTFail_); 
	
	ElecIsoMHT_ = new TH1F("ElecIsoMHT1D","ElecIsoMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(ElecIsoMHT_);
	ElecIsoMHTFail_ = (TH1F*)ElecIsoMHT_->Clone();
	ElecIsoMHTFail_->SetName("ElecIsoMHT1DFail");
	GetOutputList()->Add(ElecIsoMHTFail_); 
	
	
	ElecMTWBTag_ = new TH1F("ElecMTWBTag1D","ElecMTWBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(ElecMTWBTag_);
	ElecMTWBTagFail_ = (TH1F*)ElecMTWBTag_->Clone();
	ElecMTWBTagFail_->SetName("ElecMTWBTag1DFail");
	GetOutputList()->Add(ElecMTWBTagFail_); 
	
	ElecMTWNJets_ = new TH1F("ElecMTWNJets1D","ElecMTWNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(ElecMTWNJets_);
	ElecMTWNJetsFail_ = (TH1F*)ElecMTWNJets_->Clone();
	ElecMTWNJetsFail_->SetName("ElecMTWNJets1DFail");
	GetOutputList()->Add(ElecMTWNJetsFail_); 
	
	ElecMTWHT_ = new TH1F("ElecMTWHT1D","ElecMTWHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(ElecMTWHT_);
	ElecMTWHTFail_ = (TH1F*)ElecMTWHT_->Clone();
	ElecMTWHTFail_->SetName("ElecMTWHT1DFail");
	GetOutputList()->Add(ElecMTWHTFail_); 
	
	ElecMTWMHT_ = new TH1F("ElecMTWMHT1D","ElecMTWMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(ElecMTWMHT_);
	ElecMTWMHTFail_ = (TH1F*)ElecMTWMHT_->Clone();
	ElecMTWMHTFail_->SetName("ElecMTWMHT1DFail");
	GetOutputList()->Add(ElecMTWMHTFail_); 
	
	
	ElecPurityBTag_ = new TH1F("ElecPurityBTag1D","ElecPurityBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(ElecPurityBTag_);
	ElecPurityBTagFail_ = (TH1F*)ElecPurityBTag_->Clone();
	ElecPurityBTagFail_->SetName("ElecPurityBTag1DFail");
	GetOutputList()->Add(ElecPurityBTagFail_); 
	
	ElecPurityNJets_ = new TH1F("ElecPurityNJets1D","ElecPurityNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(ElecPurityNJets_);
	ElecPurityNJetsFail_ = (TH1F*)ElecPurityNJets_->Clone();
	ElecPurityNJetsFail_->SetName("ElecPurityNJets1DFail");
	GetOutputList()->Add(ElecPurityNJetsFail_); 
	
	ElecPurityHT_ = new TH1F("ElecPurityHT1D","ElecPurityHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(ElecPurityHT_);
	ElecPurityHTFail_ = (TH1F*)ElecPurityHT_->Clone();
	ElecPurityHTFail_->SetName("ElecPurityHT1DFail");
	GetOutputList()->Add(ElecPurityHTFail_); 
	
	ElecPurityMHT_ = new TH1F("ElecPurityMHT1D","ElecPurityMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(ElecPurityMHT_);
	ElecPurityMHTFail_ = (TH1F*)ElecPurityMHT_->Clone();
	ElecPurityMHTFail_->SetName("ElecPurityMHT1DFail");
	GetOutputList()->Add(ElecPurityMHTFail_); 
	
	
	// pt , delta R relPT
	MuRecoPT_ = new TH1F("MuRecoPT","MuRecoPT",oneDPT_-1,OneDPT_);
	GetOutputList()->Add(MuRecoPT_);
	MuRecoPTFail_ = (TH1F*)MuRecoPT_->Clone();
	MuRecoPTFail_->SetName("MuRecoPTFail");
	GetOutputList()->Add(MuRecoPTFail_); 
	
	MuRecoDeltaR_ = new TH1F("MuRecoDeltaR","MuRecoDeltaR",oneDDeltaR_-1,OneDDeltaR_);
	GetOutputList()->Add(MuRecoDeltaR_);
	MuRecoDeltaRFail_ = (TH1F*)MuRecoDeltaR_->Clone();
	MuRecoDeltaRFail_->SetName("MuRecoDeltaRFail");
	GetOutputList()->Add(MuRecoDeltaRFail_); 
	
	MuRecoPTRel_ = new TH1F("MuRecoPTRel","MuRecoPTRel",oneDPTRel_-1,OneDPTRel_);
	GetOutputList()->Add(MuRecoPTRel_);
	MuRecoPTRelFail_ = (TH1F*)MuRecoPTRel_->Clone();
	MuRecoPTRelFail_->SetName("MuRecoPTRelFail");
	GetOutputList()->Add(MuRecoPTRelFail_); 
	
	MuIsoPT_ = new TH1F("MuIsoPT","MuIsoPT",oneDPT_-1,OneDPT_);
	GetOutputList()->Add(MuIsoPT_);
	MuIsoPTFail_ = (TH1F*)MuIsoPT_->Clone();
	MuIsoPTFail_->SetName("MuIsoPTFail");
	GetOutputList()->Add(MuIsoPTFail_); 
	
	MuIsoDeltaR_ = new TH1F("MuIsoDeltaR","MuIsoDeltaR",oneDDeltaR_-1,OneDDeltaR_);
	GetOutputList()->Add(MuIsoDeltaR_);
	MuIsoDeltaRFail_ = (TH1F*)MuIsoDeltaR_->Clone();
	MuIsoDeltaRFail_->SetName("MuIsoDeltaRFail");
	GetOutputList()->Add(MuIsoDeltaRFail_); 
	
	MuIsoPTRel_ = new TH1F("MuIsoPTRel","MuIsoPTRel",oneDPTRel_-1,OneDPTRel_);
	GetOutputList()->Add(MuIsoPTRel_);
	MuIsoPTRelFail_ = (TH1F*)MuIsoPTRel_->Clone();
	MuIsoPTRelFail_->SetName("MuIsoPTRelFail");
	GetOutputList()->Add(MuIsoPTRelFail_); 
	
	MuMTWPT_ = new TH1F("MuMTWPT","MuMTWPT",oneDPT_-1,OneDPT_);
	GetOutputList()->Add(MuMTWPT_);
	MuMTWPTFail_ = (TH1F*)MuMTWPT_->Clone();
	MuMTWPTFail_->SetName("MuMTWPTFail");
	GetOutputList()->Add(MuMTWPTFail_); 
	
	MuMTWDeltaR_ = new TH1F("MuMTWDeltaR","MuMTWDeltaR",oneDDeltaR_-1,OneDDeltaR_);
	GetOutputList()->Add(MuMTWDeltaR_);
	MuMTWDeltaRFail_ = (TH1F*)MuMTWDeltaR_->Clone();
	MuMTWDeltaRFail_->SetName("MuMTWDeltaRFail");
	GetOutputList()->Add(MuMTWDeltaRFail_); 
	
	MuMTWPTRel_ = new TH1F("MuMTWPTRel","MuMTWPTRel",oneDPTRel_-1,OneDPTRel_);
	GetOutputList()->Add(MuMTWPTRel_);
	MuMTWPTRelFail_ = (TH1F*)MuMTWPTRel_->Clone();
	MuMTWPTRelFail_->SetName("MuMTWPTRelFail");
	GetOutputList()->Add(MuMTWPTRelFail_); 
	
	
	
	ElecRecoPT_ = new TH1F("ElecRecoPT","ElecRecoPT",oneDPT_-1,OneDPT_);
	GetOutputList()->Add(ElecRecoPT_);
	ElecRecoPTFail_ = (TH1F*)ElecRecoPT_->Clone();
	ElecRecoPTFail_->SetName("ElecRecoPTFail");
	GetOutputList()->Add(ElecRecoPTFail_); 
	
	ElecRecoDeltaR_ = new TH1F("ElecRecoDeltaR","ElecRecoDeltaR",oneDDeltaR_-1,OneDDeltaR_);
	GetOutputList()->Add(ElecRecoDeltaR_);
	ElecRecoDeltaRFail_ = (TH1F*)ElecRecoDeltaR_->Clone();
	ElecRecoDeltaRFail_->SetName("ElecRecoDeltaRFail");
	GetOutputList()->Add(ElecRecoDeltaRFail_); 
	
	ElecRecoPTRel_ = new TH1F("ElecRecoPTRel","ElecRecoPTRel",oneDPTRel_-1,OneDPTRel_);
	GetOutputList()->Add(ElecRecoPTRel_);
	ElecRecoPTRelFail_ = (TH1F*)ElecRecoPTRel_->Clone();
	ElecRecoPTRelFail_->SetName("ElecRecoPTRelFail");
	GetOutputList()->Add(ElecRecoPTRelFail_); 
	
	ElecIsoPT_ = new TH1F("ElecIsoPT","ElecIsoPT",oneDPT_-1,OneDPT_);
	GetOutputList()->Add(ElecIsoPT_);
	ElecIsoPTFail_ = (TH1F*)ElecIsoPT_->Clone();
	ElecIsoPTFail_->SetName("ElecIsoPTFail");
	GetOutputList()->Add(ElecIsoPTFail_); 
	
	ElecIsoDeltaR_ = new TH1F("ElecIsoDeltaR","ElecIsoDeltaR",oneDDeltaR_-1,OneDDeltaR_);
	GetOutputList()->Add(ElecIsoDeltaR_);
	ElecIsoDeltaRFail_ = (TH1F*)ElecIsoDeltaR_->Clone();
	ElecIsoDeltaRFail_->SetName("ElecIsoDeltaRFail");
	GetOutputList()->Add(ElecIsoDeltaRFail_); 
	
	ElecIsoPTRel_ = new TH1F("ElecIsoPTRel","ElecIsoPTRel",oneDPTRel_-1,OneDPTRel_);
	GetOutputList()->Add(ElecIsoPTRel_);
	ElecIsoPTRelFail_ = (TH1F*)ElecIsoPTRel_->Clone();
	ElecIsoPTRelFail_->SetName("ElecIsoPTRelFail");
	GetOutputList()->Add(ElecIsoPTRelFail_); 
	
	ElecMTWPT_ = new TH1F("ElecMTWPT","ElecMTWPT",oneDPT_-1,OneDPT_);
	GetOutputList()->Add(ElecMTWPT_);
	ElecMTWPTFail_ = (TH1F*)ElecMTWPT_->Clone();
	ElecMTWPTFail_->SetName("ElecMTWPTFail");
	GetOutputList()->Add(ElecMTWPTFail_); 
	
	ElecMTWDeltaR_ = new TH1F("ElecMTWDeltaR","ElecMTWDeltaR",oneDDeltaR_-1,OneDDeltaR_);
	GetOutputList()->Add(ElecMTWDeltaR_);
	ElecMTWDeltaRFail_ = (TH1F*)ElecMTWDeltaR_->Clone();
	ElecMTWDeltaRFail_->SetName("ElecMTWDeltaRFail");
	GetOutputList()->Add(ElecMTWDeltaRFail_); 
	
	ElecMTWPTRel_ = new TH1F("ElecMTWPTRel","ElecMTWPTRel",oneDPTRel_-1,OneDPTRel_);
	GetOutputList()->Add(ElecMTWPTRel_);
	ElecMTWPTRelFail_ = (TH1F*)ElecMTWPTRel_->Clone();
	ElecMTWPTRelFail_->SetName("ElecMTWPTRelFail");
	GetOutputList()->Add(ElecMTWPTRelFail_); 
	
	// iso track study
	MuIsoTrackBTag_ = new TH1F("MuIsoTrackBTag1D","MuIsoTrackBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(MuIsoTrackBTag_);
	MuIsoTrackBTagFail_ = (TH1F*)MuIsoTrackBTag_->Clone();
	MuIsoTrackBTagFail_->SetName("MuIsoTrackBTag1DFail");
	GetOutputList()->Add(MuIsoTrackBTagFail_); 
	
	MuIsoTrackNJets_ = new TH1F("MuIsoTrackNJets1D","MuIsoTrackNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(MuIsoTrackNJets_);
	MuIsoTrackNJetsFail_ = (TH1F*)MuIsoTrackNJets_->Clone();
	MuIsoTrackNJetsFail_->SetName("MuIsoTrackNJets1DFail");
	GetOutputList()->Add(MuIsoTrackNJetsFail_); 
	
	MuIsoTrackHT_ = new TH1F("MuIsoTrackHT1D","MuIsoTrackHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(MuIsoTrackHT_);
	MuIsoTrackHTFail_ = (TH1F*)MuIsoTrackHT_->Clone();
	MuIsoTrackHTFail_->SetName("MuIsoTrackHT1DFail");
	GetOutputList()->Add(MuIsoTrackHTFail_); 
	
	MuIsoTrackMHT_ = new TH1F("MuIsoTrackMHT1D","MuIsoTrackMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(MuIsoTrackMHT_);
	MuIsoTrackMHTFail_ = (TH1F*)MuIsoTrackMHT_->Clone();
	MuIsoTrackMHTFail_->SetName("MuIsoTrackMHT1DFail");
	GetOutputList()->Add(MuIsoTrackMHTFail_); 
	
	MuIsoTrackPT_ = new TH1F("MuIsoTrackPT","MuIsoTrackPT",oneDPT_-1,OneDPT_);
	GetOutputList()->Add(MuIsoTrackPT_);
	MuIsoTrackPTFail_ = (TH1F*)MuIsoTrackPT_->Clone();
	MuIsoTrackPTFail_->SetName("MuIsoTrackPTFail");
	GetOutputList()->Add(MuIsoTrackPTFail_); 
	
	MuIsoTrackDeltaR_ = new TH1F("MuIsoTrackDeltaR","MuIsoTrackDeltaR",oneDDeltaR_-1,OneDDeltaR_);
	GetOutputList()->Add(MuIsoTrackDeltaR_);
	MuIsoTrackDeltaRFail_ = (TH1F*)MuIsoTrackDeltaR_->Clone();
	MuIsoTrackDeltaRFail_->SetName("MuIsoTrackDeltaRFail");
	GetOutputList()->Add(MuIsoTrackDeltaRFail_); 
	
	MuIsoTrackPTRel_ = new TH1F("MuIsoTrackPTRel","MuIsoTrackPTRel",oneDPTRel_-1,OneDPTRel_);
	GetOutputList()->Add(MuIsoTrackPTRel_);
	MuIsoTrackPTRelFail_ = (TH1F*)MuIsoTrackPTRel_->Clone();
	MuIsoTrackPTRelFail_->SetName("MuIsoTrackPTRelFail");
	GetOutputList()->Add(MuIsoTrackPTRelFail_); 
	
	
	
	ElecIsoTrackBTag_ = new TH1F("ElecIsoTrackBTag1D","ElecIsoTrackBTag1D",oneDBJets_-1,OneDBJets_);
	GetOutputList()->Add(ElecIsoTrackBTag_);
	ElecIsoTrackBTagFail_ = (TH1F*)ElecIsoTrackBTag_->Clone();
	ElecIsoTrackBTagFail_->SetName("ElecIsoTrackBTag1DFail");
	GetOutputList()->Add(ElecIsoTrackBTagFail_); 
	
	ElecIsoTrackNJets_ = new TH1F("ElecIsoTrackNJets1D","ElecIsoTrackNJets1D",oneDNJets_-1,OneDNJets_);
	GetOutputList()->Add(ElecIsoTrackNJets_);
	ElecIsoTrackNJetsFail_ = (TH1F*)ElecIsoTrackNJets_->Clone();
	ElecIsoTrackNJetsFail_->SetName("ElecIsoTrackNJets1DFail");
	GetOutputList()->Add(ElecIsoTrackNJetsFail_); 
	
	ElecIsoTrackHT_ = new TH1F("ElecIsoTrackHT1D","ElecIsoTrackHT1D",oneDHT_-1,OneDHT_);
	GetOutputList()->Add(ElecIsoTrackHT_);
	ElecIsoTrackHTFail_ = (TH1F*)ElecIsoTrackHT_->Clone();
	ElecIsoTrackHTFail_->SetName("ElecIsoTrackHT1DFail");
	GetOutputList()->Add(ElecIsoTrackHTFail_); 
	
	ElecIsoTrackMHT_ = new TH1F("ElecIsoTrackMHT1D","ElecIsoTrackMHT1D",oneDMHT_-1,OneDMHT_);
	GetOutputList()->Add(ElecIsoTrackMHT_);
	ElecIsoTrackMHTFail_ = (TH1F*)ElecIsoTrackMHT_->Clone();
	ElecIsoTrackMHTFail_->SetName("ElecIsoTrackMHT1DFail");
	GetOutputList()->Add(ElecIsoTrackMHTFail_); 
	
	ElecIsoTrackPT_ = new TH1F("ElecIsoTrackPT","ElecIsoTrackPT",oneDPT_-1,OneDPT_);
	GetOutputList()->Add(ElecIsoTrackPT_);
	ElecIsoTrackPTFail_ = (TH1F*)ElecIsoTrackPT_->Clone();
	ElecIsoTrackPTFail_->SetName("ElecIsoTrackPTFail");
	GetOutputList()->Add(ElecIsoTrackPTFail_); 
	
	ElecIsoTrackDeltaR_ = new TH1F("ElecIsoTrackDeltaR","ElecIsoTrackDeltaR",oneDDeltaR_-1,OneDDeltaR_);
	GetOutputList()->Add(ElecIsoTrackDeltaR_);
	ElecIsoTrackDeltaRFail_ = (TH1F*)ElecIsoTrackDeltaR_->Clone();
	ElecIsoTrackDeltaRFail_->SetName("ElecIsoTrackDeltaRFail");
	GetOutputList()->Add(ElecIsoTrackDeltaRFail_); 
	
	ElecIsoTrackPTRel_ = new TH1F("ElecIsoTrackPTRel","ElecIsoTrackPTRel",oneDPTRel_-1,OneDPTRel_);
	GetOutputList()->Add(ElecIsoTrackPTRel_);
	ElecIsoTrackPTRelFail_ = (TH1F*)ElecIsoTrackPTRel_->Clone();
	ElecIsoTrackPTRelFail_->SetName("ElecIsoTrackPTRelFail");
	GetOutputList()->Add(ElecIsoTrackPTRelFail_); 
	
	
	
	// tree
	tExpectation_ = new TTree("LostLeptonExpectation","a simple Tree with simple variables");
	tExpectation_->SetAutoSave(10000000000);
	//  tExpectation_->SetAutoFlush(1000000);
	tExpectation_->Branch("HT",&HT,"HT/F");
	tExpectation_->Branch("MHT",&MHT,"MHT/F");
	tExpectation_->Branch("NJets",&NJets,"NJets/s");
	tExpectation_->Branch("BTags",&BTags,"BTags/s");
	tExpectation_->Branch("Leptons",&Leptons,"Leptons/s");
	tExpectation_->Branch("NVtx",&NVtx,"NVtx/s");
	tExpectation_->Branch("DeltaPhi1",&DeltaPhi1,"DeltaPhi1/F");
	tExpectation_->Branch("DeltaPhi2",&DeltaPhi2,"DeltaPhi2/F");
	tExpectation_->Branch("DeltaPhi3",&DeltaPhi3,"DeltaPhi3/F");
	tExpectation_->Branch("Weight", &Weight, "Weight/F");
	tExpectation_->Branch("MET",&METPt,"MET/F");
	tExpectation_->Branch("METPhi",&METPhi,"METPhi/F");
	tExpectation_->Branch("GenMuNum",&GenMuNum,"GenMuNum/s");
	tExpectation_->Branch("GenMuFromTau",GenMu_GenMuFromTau,"GenMuFromTau[GenMuNum]/s");
	tExpectation_->Branch("GenMuPt", GenMuPt,"GenMuPt[GenMuNum]/F");
	tExpectation_->Branch("GenMuEta", GenMuEta,"GenMuEta[GenMuNum]/F");
	tExpectation_->Branch("GenMuPhi", GenMuPhi,"GenMuPhi[GenMuNum]/F");
	tExpectation_->Branch("GenMuonIsoTrackMatched", GenMuonIsoTrackMatched, "GenMuonIsoTrackMatched[GenMuNum]/s"); 
	tExpectation_->Branch("GenElecNum",&GenElecNum,"GenElecNum/s");
	tExpectation_->Branch("GenElecFromTau",GenElec_GenElecFromTau,"GenElecFromTau[GenElecNum]/s");
	tExpectation_->Branch("GenElecPt", GenElecPt,"GenElecPt[GenElecNum]/F");
	tExpectation_->Branch("GenElecEta", GenElecEta,"GenElecEta[GenElecNum]/F");
	tExpectation_->Branch("GenElecPhi", GenElecPhi,"GenElecPhi[GenElecNum]/F");
	tExpectation_->Branch("GenElecIsoTrackMatched", GenElecIsoTrackMatched, "GenElecIsoTrackMatched[GenElecNum]/s"); 
	tExpectation_->Branch("GenTauNum",&GenTauNum,"GenTauNum/s");
	tExpectation_->Branch("GenTauPt", GenTauPt,"GenTauPt[GenTauNum]/F");
	tExpectation_->Branch("GenTauEta", GenTauEta,"GenTauEta[GenTauNum]/F");
	tExpectation_->Branch("GenTauPhi", GenTauPhi,"GenTauPhi[GenTauNum]/F");
	tExpectation_->Branch("GenTauIsoTrackMatched", GenTauIsoTrackMatched, "GenTauIsoTrackMatched[GenTauNum]/s"); 
	tExpectation_->Branch("Expectation",&Expectation,"Expectation/s");  
	tExpectation_->Branch("muAcc",&muAcc,"muAcc/s");  
	tExpectation_->Branch("muReco",&muReco,"muReco/s");  
	tExpectation_->Branch("muIso",&muIso,"muIso/s");  
	tExpectation_->Branch("MTW",&mtw,"MTW/F");  
	tExpectation_->Branch("elecAcc",&elecAcc,"elecAcc/s");  
	tExpectation_->Branch("elecReco",&elecReco,"elecReco/s");  
	tExpectation_->Branch("elecIso",&elecIso,"elecIso/s");  
	tExpectation_->Branch("FallsVetoLep",&FallsVetoLep,"FallsVetoLep/s");
	tExpectation_->Branch("selectedIDIsoMuonsNum",&selectedIDIsoMuonsNum,"selectedIDIsoMuonsNum/s");
	tExpectation_->Branch("selectedIDIsoMuonsPt", selectedIDIsoMuonsPt, "selectedIDIsoMuonsPt[selectedIDIsoMuonsNum]/F");
	tExpectation_->Branch("RecoIsoMuonPromtMatched", RecoIsoMuonPromtMatched, "RecoIsoMuonPromtMatched[selectedIDIsoMuonsNum]/s");
	tExpectation_->Branch("RecoIsoMuonPromtMatchedDeltaR", RecoIsoMuonPromtMatchedDeltaR, "RecoIsoMuonPromtMatchedDeltaR[selectedIDIsoMuonsNum]/F");
	tExpectation_->Branch("RecoIsoMuonPromtMatchedRelPt", RecoIsoMuonPromtMatchedRelPt, "RecoIsoMuonPromtMatchedRelPt[selectedIDIsoMuonsNum]/F");
	tExpectation_->Branch("selectedIDIsoMuonsEta", selectedIDIsoMuonsEta, "selectedIDIsoMuonsEta[selectedIDIsoMuonsNum]/F");
	tExpectation_->Branch("selectedIDIsoMuonsPhi", selectedIDIsoMuonsPhi, "selectedIDIsoMuonsPhi[selectedIDIsoMuonsNum]/F");
	tExpectation_->Branch("selectedIDIsoMuonsE", selectedIDIsoMuonsE, "selectedIDIsoMuonsE[selectedIDIsoMuonsNum]/F");
	tExpectation_->Branch("RecoIsoMuonIsoTrackMatched", RecoIsoMuonIsoTrackMatched, "RecoIsoMuonIsoTrackMatched[selectedIDIsoMuonsNum]/s");  
	tExpectation_->Branch("selectedIDIsoElectronsNum",&selectedIDIsoElectronsNum,"selectedIDIsoElectronsNum/s");
	tExpectation_->Branch("selectedIDIsoElectronsPt", selectedIDIsoElectronsPt, "selectedIDIsoElectronsPt[selectedIDIsoElectronsNum]/F");
	tExpectation_->Branch("RecoIsoElecPromtMatched", RecoIsoElecPromtMatched, "RecoIsoElecPromtMatched[selectedIDIsoElectronsNum]/s");
	tExpectation_->Branch("RecoIsoElecPromtMatchedDeltaR", RecoIsoElecPromtMatchedDeltaR, "RecoIsoElecPromtMatchedDeltaR[selectedIDIsoElectronsNum]/F");
	tExpectation_->Branch("RecoIsoElecPromtMatchedRelPt", RecoIsoElecPromtMatchedRelPt, "RecoIsoElecPromtMatchedRelPt[selectedIDIsoElectronsNum]/F");
	tExpectation_->Branch("selectedIDIsoElectronsEta", selectedIDIsoElectronsEta, "selectedIDIsoElectronsEta[selectedIDIsoElectronsNum]/F");
	tExpectation_->Branch("selectedIDIsoElectronsPhi", selectedIDIsoElectronsPhi, "selectedIDIsoElectronsPhi[selectedIDIsoElectronsNum]/F");
	tExpectation_->Branch("selectedIDIsoElectronsE", selectedIDIsoElectronsE, "selectedIDIsoElectronsE[selectedIDIsoElectronsNum]/F");
	tExpectation_->Branch("RecoIsoElecIsoTrackMatched", RecoIsoElecIsoTrackMatched, "RecoIsoElecIsoTrackMatched[selectedIDIsoElectronsNum]/s"); 
	
	tExpectation_->Branch("IsolatedTracksNum",&IsolatedTracksNum,"IsolatedTracksNum/s");
	tExpectation_->Branch("FallsVetoIsoTrack",&FallsVetoIsoTrack,"FallsVetoIsoTrack/s");
	tExpectation_->Branch("IsolatedTracksPt", IsolatedTracksPt, "IsolatedTracksPt[IsolatedTracksNum]/F");
	tExpectation_->Branch("IsolatedTracksEta", IsolatedTracksEta, "IsolatedTracksEta[IsolatedTracksNum]/F");
	tExpectation_->Branch("IsolatedTracksPhi", IsolatedTracksPhi, "IsolatedTracksPhi[IsolatedTracksNum]/F");
	tExpectation_->Branch("IsolatedTracksE", IsolatedTracksE, "IsolatedTracksE[IsolatedTracksNum]/F");
	tExpectation_->Branch("SelectedIsoTracksMatchedToGenLepton", SelectedIsoTracksMatchedToGenLepton, "SelectedIsoTracksMatchedToGenLepton[IsolatedTracksNum]/s");  
	tExpectation_->Branch("SelectedIsoTracksMatchedToGenDeltaR", SelectedIsoTracksMatchedToGenDeltaR, "SelectedIsoTracksMatchedToGenDeltaR[IsolatedTracksNum]/F"); 
	tExpectation_->Branch("SelectedIsoTracksMatchedToGenRelPT", SelectedIsoTracksMatchedToGenRelPT, "SelectedIsoTracksMatchedToGenRelPT[IsolatedTracksNum]/F"); 
	tExpectation_->Branch("SelectedIsoTracksMatchedToRecoIsoLepton", SelectedIsoTracksMatchedToRecoIsoLepton, "SelectedIsoTracksMatchedToRecoIsoLepton[IsolatedTracksNum]/s");  
	
	GetOutputList()->Add(tExpectation_);
}

Bool_t EffMaker::Process(Long64_t entry)
{
	// The Process() function is called for each entry in the tree (or possibly
	// keyed object in the case of PROOF) to be processed. The entry argument
	// specifies which entry in the currently loaded tree is to be processed.
	// It can be passed to either EffMaker::GetEntry() or TBranch::GetEntry()
	// to read either all or the required parts of the data. When processing
	// keyed objects with PROOF, the object is already loaded and is available
	// via the fObject pointer.
	//
	// This function should contain the "body" of the analysis. It can contain
	// simple or elaborate selection criteria, run algorithms on the data
	// of the event and typically fill histograms.
	//
	// The processing can be stopped by calling Abort().
	//
	// Use fStatus to set the return value of TTree::Process().
	//
	// The return value is currently not used.
	
	resetValues();
	fChain->GetTree()->GetEntry(entry);
	if(HT<minHT_ || MHT< minMHT_ || NJets < minNJets_||  DeltaPhi1 < deltaPhi1_ || DeltaPhi2 < deltaPhi2_ || DeltaPhi3 < deltaPhi3_ ) return kTRUE;
	if(applyFilters_ &&  !FiltersPass() ) return kTRUE;
	
	// IsoTracksStudies
	for (unsigned  i=0; i<GenMuNum;i++)
	{
		if(GenMuPt[i] <minMuPt_ || std::abs(GenMuEta[i]) > maxMuEta_) continue;
		for(unsigned int ii=0; ii< IsolatedTracksNum;ii++)
		{
			if(SelectedIsoTracksMatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
				if(deltaR(GenMuEta[i],GenMuPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii])<maxDeltaRGenMuToTack_ && std::abs(GenMuPt[i]-IsolatedTracksPt[ii])/GenMuPt[i] <maxDiffPtGenMuToTack_)
				{
					GenMuonIsoTrackMatched[i]=1;
					SelectedIsoTracksMatchedToGenLepton[ii]=1;
					SelectedIsoTracksMatchedToGenDeltaR[ii]=deltaR(GenMuEta[i],GenMuPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii]);
					SelectedIsoTracksMatchedToGenRelPT[ii]=GenMuPt[i]-IsolatedTracksPt[ii]/GenMuPt[i];
				}
			}
		}
	}
	for (unsigned  i=0; i<GenElecNum;i++)
	{
		if(GenElecPt[i] <minElecPt_ || std::abs(GenElecEta[i]) > maxElecEta_) continue;
		for(unsigned int ii=0; ii< IsolatedTracksNum;ii++)
		{
			if(SelectedIsoTracksMatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
				if(deltaR(GenElecEta[i],GenElecPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii])<maxDeltaRGenElecToTack_ && std::abs(GenElecPt[i]-IsolatedTracksPt[ii])/GenElecPt[i] <maxDiffPtGenElecToTack_)
				{
					GenElecIsoTrackMatched[i]=1;
					SelectedIsoTracksMatchedToGenLepton[ii]=2;
					SelectedIsoTracksMatchedToGenDeltaR[ii]=deltaR(GenElecEta[i],GenElecPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii]);
					SelectedIsoTracksMatchedToGenRelPT[ii]=GenElecPt[i]-IsolatedTracksPt[ii]/GenElecPt[i];
				}
			}
		}
	}
	for (unsigned  i=0; i<GenTauNum;i++)
	{
		if(GenTauPt[i] <minTauPt_ || std::abs(GenTauEta[i]) > maxTauEta_) continue;
		for(unsigned int ii=0; ii< IsolatedTracksNum;ii++)
		{
			if(SelectedIsoTracksMatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
				if(deltaR(GenTauEta[i],GenTauPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii])<maxDeltaRGenTauToTack_ && std::abs(GenTauPt[i]-IsolatedTracksPt[ii])/GenTauPt[i] <maxDiffPtGenTauToTack_)
				{
					GenTauIsoTrackMatched[i]=1;
					SelectedIsoTracksMatchedToGenLepton[ii]=3;
					SelectedIsoTracksMatchedToGenDeltaR[ii]=deltaR(GenTauEta[i],GenTauPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii]);
					SelectedIsoTracksMatchedToGenRelPT[ii]=GenTauPt[i]-IsolatedTracksPt[ii]/GenTauPt[i];
				}
			}
		}
	}
	// save if fals veto is true
	unsigned int temp =0;
	for(unsigned int i=0; i< IsolatedTracksNum;i++)
	{
		if(SelectedIsoTracksMatchedToGenLepton[i]==0)temp++;
		
	}
	if(temp!=0)FallsVetoIsoTrack=1;
	//
	

	
	//
	
	
	
	for (unsigned  i=0; i<selectedIDIsoMuonsNum;i++)
	{
		if(selectedIDIsoMuonsPt[i] <minMuPt_ || std::abs(selectedIDIsoMuonsEta[i]) > maxMuEta_) continue;
		for(unsigned int ii=0; ii< IsolatedTracksNum;ii++)
		{
			if(SelectedIsoTracksMatchedToRecoIsoLepton[ii]==0) // only look at not yet matched tracks
      {
				if(deltaR(selectedIDIsoMuonsEta[i],selectedIDIsoMuonsPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii])<maxDeltaRRecoIsoMuToTack_ && std::abs(selectedIDIsoMuonsPt[i]-IsolatedTracksPt[ii])/selectedIDIsoMuonsPt[i] <maxDiffPtRecoIsoMuToTack_)
				{
					RecoIsoMuonIsoTrackMatched[ii]=1;
					SelectedIsoTracksMatchedToRecoIsoLepton[ii]=2;
					SelectedIsoTracksMatchedToRecoIsoDeltaR[ii]=deltaR(selectedIDIsoMuonsEta[i],selectedIDIsoMuonsPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii]);
					SelectedIsoTracksMatchedToRecoIsoRelPT[ii]=selectedIDIsoMuonsPt[i]-IsolatedTracksPt[ii]/GenMuPt[i];
				}
			}
		}
	}
	for (unsigned  i=0; i<selectedIDIsoElectronsNum;i++)
	{
		if(selectedIDIsoElectronsPt[i] <minElecPt_ || std::abs(selectedIDIsoElectronsEta[i]) > maxElecEta_) continue;
		for(unsigned int ii=0; ii< IsolatedTracksNum;ii++)
		{
			if(SelectedIsoTracksMatchedToRecoIsoLepton[ii]==0) // only look at not yet matched tracks
      {
				if(deltaR(selectedIDIsoElectronsEta[i],selectedIDIsoElectronsPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii])<maxDeltaRRecoIsoElecToTack_ && std::abs(selectedIDIsoElectronsPt[i]-IsolatedTracksPt[ii])/selectedIDIsoElectronsPt[i] <maxDiffPtRecoIsoElecToTack_)
				{
					RecoIsoElecIsoTrackMatched[ii]=1;
					SelectedIsoTracksMatchedToRecoIsoLepton[ii]=1;
					SelectedIsoTracksMatchedToRecoIsoDeltaR[ii]=deltaR(selectedIDIsoElectronsEta[i],selectedIDIsoElectronsPhi[i],IsolatedTracksEta[ii],IsolatedTracksPhi[ii]);
					SelectedIsoTracksMatchedToRecoIsoRelPT[ii]=selectedIDIsoElectronsPt[i]-IsolatedTracksPt[ii]/GenElecPt[i];
				}
			}
		}
	}
	/*  if(GenMuNum==2)// di muon event
	 *  {
	 *	  if(selectedIDIsoMuonsNum>0)
	 *	  {
	 *		  MuDiLepEffNJets->Fill(NJets,Weight);
}
else MuDiLepEffNJetsFail->Fill(NJets,Weight);
}
if(GenElecNum==2)// di elec event
  {
		if(selectedIDIsoElectronsNum>0)
		{
			ElecDiLepEffNJets->Fill(NJets,Weight);
}
else ElecDiLepEffNJetsFail->Fill(NJets,Weight);
}
if(GenMuNum==1 && GenElecNum==1) // di lepton with one elec one muon
  {
		if(selectedIDIsoMuonsNum>0)
		{
			MuDiLepEffNJets->Fill(NJets,Weight);
}

if(selectedIDIsoElectronsNum>0)
{
	ElecDiLepEffNJets->Fill(NJets,Weight);
}
if(selectedIDIsoElectronsNum==0 && selectedIDIsoMuonsNum==0)
{
	MuDiLepEffNJetsFail->Fill(NJets,Weight);
	ElecDiLepEffNJetsFail->Fill(NJets,Weight);
}
}
*/
	if((GenMuNum+GenElecNum)==2)
	{
		if(selectedIDIsoElectronsNum==0 && selectedIDIsoMuonsNum==1) 
		{
			MuDiLepEffNJets->Fill(NJets,Weight);
			ElecDiLepEffNJets->Fill(NJets,Weight);
		}
		if(selectedIDIsoElectronsNum==0 && selectedIDIsoMuonsNum==0) 
		{
			MuDiLepEffNJetsFail->Fill(NJets,Weight);
			ElecDiLepEffNJetsFail->Fill(NJets,Weight);
		}
	}
	
	if( (GenMuNum+GenElecNum)==2)
	{
		if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0)
		{
			Expectation=1;
		}
		if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
		{
			MuDiLepControlSampleMHTNJetFail->Fill(MHT,NJets,Weight);
			mtw =  MTWCalculator(METPt,METPhi, selectedIDIsoMuonsPt[0], selectedIDIsoMuonsPhi[0]);
			if(mtw<mtwCut_)MuDiLepControlSampleMHTNJetMTWFail->Fill(MHT,NJets,Weight);
		}
		if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
		{
			ElecDiLepControlSampleMHTNJetFail->Fill(MHT,NJets,Weight);  
			mtw =  MTWCalculator(METPt,METPhi, selectedIDIsoElectronsPt[0], selectedIDIsoElectronsPhi[0]);
			if(mtw<mtwCut_)ElecDiLepControlSampleMHTNJetMTWFail->Fill(MHT,NJets,Weight);
		}
	}
	// start with gen muons consider only single muon events
	if(GenMuNum==1 && GenElecNum==0)
	{
		if ( GenMuPt[0] < minMuPt_ || std::abs(GenMuEta[0]) > maxMuEta_)
		{
			MuonAccBTagFail->Fill(MHT,BTags,Weight);
			MuonAccFail->Fill(MHT,NJets,Weight);
			muAcc=0;
			Expectation=1;
			// efficiency studies TH1 and so on
			MuAccBTagFail_->Fill(BTags,Weight);
			MuAccNJetSFail_->Fill(NJets,Weight);
			MuAccHTFail_->Fill(HT,Weight);
			MuAccMHTFail_->Fill(MHT,Weight);
		}
		else
		{
			MuonAccBTag->Fill(MHT,BTags,Weight);
			MuonAcc->Fill(MHT,NJets,Weight);
			muAcc=2;
			bool RecoNotMatched=true;
			for (UShort_t i=0; i<IsolatedTracksNum; i++)
			{
				if(deltaR(GenMuEta[0],GenMuPhi[0],IsolatedTracksEta[i],IsolatedTracksPhi[i])<maxDeltaRGenToRecoIsoTrack_ && std::abs(GenMuPt[0]-IsolatedTracksPt[i])/GenMuPt[0] <maxDiffPtGenToRecoIsoTrack_)
				{
					MuIsoTrackBTag_->Fill(BTags,Weight);
					MuIsoTrackNJets_->Fill(NJets,Weight);
					MuIsoTrackHT_->Fill(HT,Weight);
					MuIsoTrackMHT_->Fill(MHT,Weight);
					MuIsoTrackPT_->Fill(IsolatedTracksPt[i],Weight);
					RecoNotMatched=false;
				}
			}
			if(RecoNotMatched)
			{
				MuIsoTrackBTagFail_->Fill(BTags,Weight);
				MuIsoTrackNJetsFail_->Fill(NJets,Weight);
				MuIsoTrackHTFail_->Fill(HT,Weight);
				MuIsoTrackMHTFail_->Fill(MHT,Weight);
				MuIsoTrackPTFail_->Fill(GenMuPt[0],Weight);
			}
			RecoNotMatched=true;
			// efficiency studies TH1 and so on
			MuAccBTag_->Fill(BTags,Weight);
			MuAccNJetS_->Fill(NJets,Weight);
			MuAccHT_->Fill(HT,Weight);
			MuAccMHT_->Fill(MHT,Weight);
			for (UShort_t i=0; i<selectedIDMuonsNum; i++)
			{
				//std::cout<<"selectedIDMuonsNum["<<i<<"] started"<<std::endl;
				if(deltaR(GenMuEta[0],GenMuPhi[0],selectedIDMuonsEta[i],selectedIDMuonsPhi[i])<maxDeltaRGenToRecoMu_ && std::abs(GenMuPt[0]-selectedIDMuonsPt[i])/GenMuPt[0] <maxDiffPtGenToRecoMu_)
				{
					// std::cout<<"selectedIDMuonsNum["<<i<<"] started"<<std::endl;
					RecoNotMatched=false;
					if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonRecoLow->Fill(HT,MHT,Weight);
					if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonReco0->Fill(HT,MHT,Weight);
					if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonReco1->Fill(HT,MHT,Weight);
					if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonReco2->Fill(HT,MHT,Weight);
					if( BTags <1) MuonRecoBTag0->Fill(HT,MHT,Weight);
					if( BTags <2) MuonRecoBTag1->Fill(HT,MHT,Weight);
					if( BTags >1) MuonRecoBTag2ToInf->Fill(HT,MHT,Weight);
					// efficiency studies TH1 and so on
					MuRecoBTag_->Fill(BTags,Weight);
					MuRecoNJets_->Fill(NJets,Weight);
					MuRecoHT_->Fill(HT,Weight);
					MuRecoMHT_->Fill(MHT,Weight);
					MuRecoPT_->Fill(selectedIDMuonsPt[i],Weight);
					
					muReco =2;
					bool IsoNotMatched=true;
					for (UShort_t ii=0; ii < selectedIDIsoMuonsNum; ii++)
					{
						if(deltaR(selectedIDIsoMuonsEta[ii],selectedIDIsoMuonsPhi[ii],selectedIDMuonsEta[i],selectedIDMuonsPhi[i])<maxDeltaRRecoToIsoMu_ && std::abs(selectedIDIsoMuonsPt[ii]-selectedIDMuonsPt[i])/selectedIDIsoMuonsPt[ii] <maxDiffPtRecoToIsoMu_)
						{
							IsoNotMatched=false;
							if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonIsoLow->Fill(HT,MHT,Weight);
							if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonIso0->Fill(HT,MHT,Weight);
							if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonIso1->Fill(HT,MHT,Weight);
							if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonIso2->Fill(HT,MHT,Weight);
							if( BTags <1) MuonIsoBTag0->Fill(HT,MHT,Weight);
							if( BTags <2) MuonIsoBTag1->Fill(HT,MHT,Weight);
							if( BTags >1) MuonIsoBTag2ToInf->Fill(HT,MHT,Weight);
							// efficiency studies TH1 and so on
							MuIsoBTag_->Fill(BTags,Weight);
							MuIsoNJets_->Fill(NJets,Weight);
							MuIsoHT_->Fill(HT,Weight);
							MuIsoMHT_->Fill(MHT,Weight);
							muIso=2;
							Expectation=2;
							MuDiLepControlSampleMHTNJet->Fill(MHT,NJets,Weight);
							mtw =  MTWCalculator(METPt,METPhi, selectedIDIsoMuonsPt[ii], selectedIDIsoMuonsPhi[ii]);
							if (mtw<mtwCut_)
							{
								MuMTWMHTBTag->Fill(BTags,MHT,Weight);
								MuMTWNJet->Fill(NJets,Weight);
								MuMTWMHTNJet->Fill(MHT,NJets,Weight);
								MuDiLepControlSampleMHTNJetMTW->Fill(MHT,NJets,Weight);
								// efficiency studies TH1 and so on
								MuMTWBTag_->Fill(BTags,Weight);
								MuMTWNJets_->Fill(NJets,Weight);
								MuMTWHT_->Fill(HT,Weight);
								MuMTWMHT_->Fill(MHT,Weight);
							}
							else
							{
								MuMTWMHTBTagFail->Fill(BTags,MHT,Weight);
								MuMTWNJetFail->Fill(NJets,Weight);
								MuMTWMHTNJetFail->Fill(MHT,NJets,Weight);
								// efficiency studies TH1 and so on
								MuMTWBTagFail_->Fill(BTags,Weight);
								MuMTWNJetsFail_->Fill(NJets,Weight);
								MuMTWHTFail_->Fill(HT,Weight);
								MuMTWMHTFail_->Fill(MHT,Weight);
							}
						}
					}
					if(IsoNotMatched)
					{
						if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonIsoLowFail->Fill(HT,MHT,Weight);
						if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonIso0Fail->Fill(HT,MHT,Weight);
						if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonIso1Fail->Fill(HT,MHT,Weight);
						if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonIso2Fail->Fill(HT,MHT,Weight);
						if( BTags <1) MuonIsoBTag0Fail->Fill(HT,MHT,Weight);
						if( BTags <2) MuonIsoBTag1Fail->Fill(HT,MHT,Weight);
						if( BTags >1) MuonIsoBTag2ToInfFail->Fill(HT,MHT,Weight);
						muIso=0;
						Expectation=1;
						// efficiency studies TH1 and so on
						MuIsoBTagFail_->Fill(BTags,Weight);
						MuIsoNJetsFail_->Fill(NJets,Weight);
						MuIsoHTFail_->Fill(HT,Weight);
						MuIsoMHTFail_->Fill(MHT,Weight);
					}
				}
			}
			if(RecoNotMatched)
			{
				if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonRecoLowFail->Fill(HT,MHT,Weight);
				if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonReco0Fail->Fill(HT,MHT,Weight);
				if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonReco1Fail->Fill(HT,MHT,Weight);
				if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonReco2Fail->Fill(HT,MHT,Weight);
				if( BTags <1) MuonRecoBTag0Fail->Fill(HT,MHT,Weight);
				if( BTags <2) MuonRecoBTag1Fail->Fill(HT,MHT,Weight);
				if( BTags >1) MuonRecoBTag2ToInfFail->Fill(HT,MHT,Weight);
				muReco=0;
				Expectation=1;
				// efficiency studies TH1 and so on
				MuRecoBTagFail_->Fill(BTags,Weight);
				MuRecoNJetsFail_->Fill(NJets,Weight);
				MuRecoHTFail_->Fill(HT,Weight);
				MuRecoMHTFail_->Fill(MHT,Weight);
			}
		}
	} 
	// analyse gen electrons consider only single elec events
	if(GenMuNum==0 && GenElecNum==1)
	{
		if ( GenElecPt[0] < minElecPt_ || std::abs(GenElecEta[0]) > maxElecEta_)
		{
			ElecAccBTagFail->Fill(MHT,BTags,Weight);
			ElecAccFail->Fill(MHT,NJets,Weight);
			elecAcc=0;
			Expectation=1;
			// efficiency studies TH1 and so on
			ElecAccBTagFail_->Fill(BTags,Weight);
			ElecAccNJetSFail_->Fill(NJets,Weight);
			ElecAccHTFail_->Fill(HT,Weight);
			ElecAccMHTFail_->Fill(MHT,Weight);
		}
		else
		{
			ElecAccBTag->Fill(MHT,BTags,Weight);
			ElecAcc->Fill(MHT,NJets,Weight);
			elecAcc=2;
			bool RecoNotMatched=true;
			for (UShort_t i=0; i<IsolatedTracksNum; i++)
			{
				if(deltaR(GenElecEta[0],GenElecPhi[0],IsolatedTracksEta[i],IsolatedTracksPhi[i])<maxDeltaRGenToRecoIsoTrack_ && std::abs(GenElecPt[0]-IsolatedTracksPt[i])/GenElecPt[0] <maxDiffPtGenToRecoIsoTrack_)
				{
					ElecIsoTrackBTag_->Fill(BTags,Weight);
					ElecIsoTrackNJets_->Fill(NJets,Weight);
					ElecIsoTrackHT_->Fill(HT,Weight);
					ElecIsoTrackMHT_->Fill(MHT,Weight);
					ElecIsoTrackPT_->Fill(IsolatedTracksPt[i],Weight);
					RecoNotMatched=false;
				}
			}
			if(RecoNotMatched)
			{
				ElecIsoTrackBTagFail_->Fill(BTags,Weight);
				ElecIsoTrackNJetsFail_->Fill(NJets,Weight);
				ElecIsoTrackHTFail_->Fill(HT,Weight);
				ElecIsoTrackMHTFail_->Fill(MHT,Weight);
				ElecIsoTrackPTFail_->Fill(GenElecPt[0],Weight);
				
			}
			RecoNotMatched=true;
			// efficiency studies TH1 and so on
			ElecAccBTag_->Fill(BTags,Weight);
			ElecAccNJetS_->Fill(NJets,Weight);
			ElecAccHT_->Fill(HT,Weight);
			ElecAccMHT_->Fill(MHT,Weight);
			for (UShort_t i=0; i<selectedIDElectronsNum; i++)
			{
				//std::cout<<"selectedIDElectronsNum["<<i<<"] started"<<std::endl;
				if(deltaR(GenElecEta[0],GenElecPhi[0],selectedIDElectronsEta[i],selectedIDElectronsPhi[i])<maxDeltaRGenToRecoElec_ && std::abs(GenElecPt[0]-selectedIDElectronsPt[i])/GenElecPt[0] <maxDiffPtGenToRecoElec_)
				{
					// std::cout<<"selectedIDElectronsNum["<<i<<"] started"<<std::endl;
					RecoNotMatched=false;
					if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecRecoLow->Fill(HT,MHT,Weight);
					if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecReco0->Fill(HT,MHT,Weight);
					if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecReco1->Fill(HT,MHT,Weight);
					if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecReco2->Fill(HT,MHT,Weight);
					if( BTags <1) ElecRecoBTag0->Fill(HT,MHT,Weight);
					if( BTags <2) ElecRecoBTag1->Fill(HT,MHT,Weight);
					if( BTags >1) ElecRecoBTag2ToInf->Fill(HT,MHT,Weight);
					// efficiency studies TH1 and so on
					ElecRecoBTag_->Fill(BTags,Weight);
					ElecRecoNJets_->Fill(NJets,Weight);
					ElecRecoHT_->Fill(HT,Weight);
					ElecRecoMHT_->Fill(MHT,Weight);
					elecReco =2;
					bool IsoNotMatched=true;
					for (UShort_t ii=0; ii < selectedIDIsoElectronsNum; ii++)
					{
						if(deltaR(selectedIDIsoElectronsEta[ii],selectedIDIsoElectronsPhi[ii],selectedIDElectronsEta[i],selectedIDElectronsPhi[i])<maxDeltaRRecoToIsoElec_ && std::abs(selectedIDIsoElectronsPt[ii]-selectedIDElectronsPt[i])/selectedIDIsoElectronsPt[ii] <maxDiffPtRecoToIsoElec_)
						{
							IsoNotMatched=false;
							if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecIsoLow->Fill(HT,MHT,Weight);
							if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecIso0->Fill(HT,MHT,Weight);
							if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecIso1->Fill(HT,MHT,Weight);
							if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecIso2->Fill(HT,MHT,Weight);
							if( BTags <1) ElecIsoBTag0->Fill(HT,MHT,Weight);
							if( BTags <2) ElecIsoBTag1->Fill(HT,MHT,Weight);
							if( BTags >1) ElecIsoBTag2ToInf->Fill(HT,MHT,Weight);
							// efficiency studies TH1 and so on
							ElecIsoBTag_->Fill(BTags,Weight);
							ElecIsoNJets_->Fill(NJets,Weight);
							ElecIsoHT_->Fill(HT,Weight);
							ElecIsoMHT_->Fill(MHT,Weight);
							elecIso=2;
							Expectation=2;
							ElecDiLepControlSampleMHTNJet->Fill(MHT,NJets,Weight);
							mtw =  MTWCalculator(METPt,METPhi, selectedIDIsoElectronsPt[ii], selectedIDIsoElectronsPhi[ii]);
							if (mtw<mtwCut_)
							{
								ElecMTWMHTBTag->Fill(BTags,MHT,Weight);
								ElecMTWNJet->Fill(NJets,Weight);
								ElecMTWMHTNJet->Fill(MHT,NJets,Weight);
								ElecDiLepControlSampleMHTNJetMTW->Fill(MHT,NJets,Weight);
								// efficiency studies TH1 and so on
								ElecMTWBTag_->Fill(BTags,Weight);
								ElecMTWNJets_->Fill(NJets,Weight);
								ElecMTWHT_->Fill(HT,Weight);
								ElecMTWMHT_->Fill(MHT,Weight);
							}
							else
							{
								ElecMTWMHTBTagFail->Fill(BTags,MHT,Weight);
								ElecMTWNJetFail->Fill(NJets,Weight);
								ElecMTWMHTNJetFail->Fill(MHT,NJets,Weight);
								// efficiency studies TH1 and so on
								ElecMTWBTagFail_->Fill(BTags,Weight);
								ElecMTWNJetsFail_->Fill(NJets,Weight);
								ElecMTWHTFail_->Fill(HT,Weight);
								ElecMTWMHTFail_->Fill(MHT,Weight);
							}
						}
					}
					if(IsoNotMatched)
					{
						if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecIsoLowFail->Fill(HT,MHT,Weight);
						if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecIso0Fail->Fill(HT,MHT,Weight);
						if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecIso1Fail->Fill(HT,MHT,Weight);
						if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecIso2Fail->Fill(HT,MHT,Weight);
						if( BTags <1) ElecIsoBTag0Fail->Fill(HT,MHT,Weight);
						if( BTags <2) ElecIsoBTag1Fail->Fill(HT,MHT,Weight);
						if( BTags >1) ElecIsoBTag2ToInfFail->Fill(HT,MHT,Weight);
						elecIso=0;
						Expectation=1;
						// efficiency studies TH1 and so on
						ElecIsoBTagFail_->Fill(BTags,Weight);
						ElecIsoNJetsFail_->Fill(NJets,Weight);
						ElecIsoHTFail_->Fill(HT,Weight);
						ElecIsoMHTFail_->Fill(MHT,Weight);
					}
				}
			}
			if(RecoNotMatched)
			{
				if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecRecoLowFail->Fill(HT,MHT,Weight);
				if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecReco0Fail->Fill(HT,MHT,Weight);
				if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecReco1Fail->Fill(HT,MHT,Weight);
				if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecReco2Fail->Fill(HT,MHT,Weight);
				if( BTags <1) ElecRecoBTag0Fail->Fill(HT,MHT,Weight);
				if( BTags <2) ElecRecoBTag1Fail->Fill(HT,MHT,Weight);
				if( BTags >1) ElecRecoBTag2ToInfFail->Fill(HT,MHT,Weight);
				elecReco=0;
				Expectation=1;
				// efficiency studies TH1 and so on
				ElecRecoBTagFail_->Fill(BTags,Weight);
				ElecRecoNJetsFail_->Fill(NJets,Weight);
				ElecRecoHTFail_->Fill(HT,Weight);
				ElecRecoMHTFail_->Fill(MHT,Weight);
			}
		}
	} 
	// purity studies:
	for (UShort_t i=0; i< selectedIDIsoMuonsNum;i++)
	{
		if(selectedIDIsoMuonsNum>1 || MTWCalculator(METPt,METPhi, selectedIDIsoMuonsPt[0], selectedIDIsoMuonsPhi[0])>mtwCut_) break;
		bool matched=false;
		for(UShort_t ii=0; ii<GenMuNum;ii++)
		{
			if(deltaR(selectedIDIsoMuonsEta[i],selectedIDIsoMuonsPhi[i],GenMuEta[ii],GenMuPhi[ii])<RecoIsoMuonPromtMatchedDeltaR[i])RecoIsoMuonPromtMatchedDeltaR[i]=deltaR(selectedIDIsoMuonsEta[i],selectedIDIsoMuonsPhi[i],GenMuEta[ii],GenMuPhi[ii]);
			if(std::abs(selectedIDIsoMuonsPt[i]-GenMuPt[ii])/selectedIDIsoMuonsPt[i] < std::abs(RecoIsoMuonPromtMatchedRelPt[i]) )RecoIsoMuonPromtMatchedRelPt[i]=(selectedIDIsoMuonsPt[i]-GenMuPt[ii])/selectedIDIsoMuonsPt[i];
			if(deltaR(selectedIDIsoMuonsEta[i],selectedIDIsoMuonsPhi[i],GenMuEta[ii],GenMuPhi[ii])<maxDeltaRIsoToGenMu_ && std::abs(selectedIDIsoMuonsPt[i]-GenMuPt[ii])/selectedIDIsoMuonsPt[i] <maxDiffPtIsoToGenMu_)
			{
				MuonPurityMHTNJet->Fill(MHT,NJets,Weight);
				RecoIsoMuonPromtMatched[i]=1;
				matched=true;
				// efficiency studies TH1 and so on
				MuPurityBTag_->Fill(BTags,Weight);
				MuPurityNJets_->Fill(NJets,Weight);
				MuPurityHT_->Fill(HT,Weight);
				MuPurityMHT_->Fill(MHT,Weight);
			}
		}
		if(!matched)
		{
			RecoIsoMuonPromtMatched[i]=0;
			MuonPurityMHTNJetFail->Fill(MHT,NJets,Weight);
			// efficiency studies TH1 and so on
			MuPurityBTagFail_->Fill(BTags,Weight);
			MuPurityNJetsFail_->Fill(NJets,Weight);
			MuPurityHTFail_->Fill(HT,Weight);
			MuPurityMHTFail_->Fill(MHT,Weight);
		}
		if(GenMuNum==0)
		{
			RecoIsoMuonPromtMatchedDeltaR[i]=-1;
			RecoIsoMuonPromtMatchedRelPt[i]=-100;
		}
	}
	for (UShort_t i=0; i< selectedIDIsoElectronsNum;i++)
	{
		if(selectedIDIsoElectronsNum>1 || MTWCalculator(METPt,METPhi, selectedIDIsoElectronsPt[0], selectedIDIsoElectronsPhi[0])>mtwCut_) break;
		bool matched=false;
		for(UShort_t ii=0; ii<GenElecNum;ii++)
		{
			if(deltaR(selectedIDIsoElectronsEta[i],selectedIDIsoElectronsPhi[i],GenElecEta[ii],GenElecPhi[ii])<RecoIsoElecPromtMatchedDeltaR[i])RecoIsoElecPromtMatchedDeltaR[i]=deltaR(selectedIDIsoElectronsEta[i],selectedIDIsoElectronsPhi[i],GenElecEta[ii],GenElecPhi[ii]);
			if(std::abs(selectedIDIsoElectronsPt[i]-GenElecPt[ii])/selectedIDIsoElectronsPt[i] < std::abs(RecoIsoElecPromtMatchedRelPt[i]) )RecoIsoElecPromtMatchedRelPt[i]=(selectedIDIsoElectronsPt[i]-GenElecPt[ii])/selectedIDIsoElectronsPt[i];
			if(deltaR(selectedIDIsoElectronsEta[i],selectedIDIsoElectronsPhi[i],GenElecEta[ii],GenElecPhi[ii])<maxDeltaRIsoToGenElec_ && std::abs(selectedIDIsoElectronsPt[i]-GenElecPt[ii])/selectedIDIsoElectronsPt[i] <maxDiffPtIsoToGenElec_)
			{
				RecoIsoElecPromtMatched[i]=1;
				matched=true;
				ElecPurityMHTNJet->Fill(MHT,NJets,Weight);
				// efficiency studies TH1 and so on
				ElecPurityBTag_->Fill(BTags,Weight);
				ElecPurityNJets_->Fill(NJets,Weight);
				ElecPurityHT_->Fill(HT,Weight);
				ElecPurityMHT_->Fill(MHT,Weight);
			}
		}
		if(!matched)
		{
			RecoIsoElecPromtMatched[i]=0;
			ElecPurityMHTNJetFail->Fill(MHT,NJets,Weight);
			// efficiency studies TH1 and so on
			ElecPurityBTagFail_->Fill(BTags,Weight);
			ElecPurityNJetsFail_->Fill(NJets,Weight);
			ElecPurityHTFail_->Fill(HT,Weight);
			ElecPurityMHTFail_->Fill(MHT,Weight);
		}
		if(GenElecNum==0)
		{
			RecoIsoElecPromtMatchedDeltaR[i]=-1;
			RecoIsoElecPromtMatchedRelPt[i]=-100;
		}
	}
	// check if falls lepton veto will be applied
	temp=0;
	for(unsigned int i=0; i< selectedIDIsoElectronsNum;i++)
	{
		if(RecoIsoElecPromtMatched[i]==0)temp=1;
	}
	for(unsigned int i=0; i< selectedIDIsoMuonsNum;i++)
	{
		if(RecoIsoMuonPromtMatched[i]==0)temp=1;
	}
	if(temp==1)FallsVetoLep=1;
	
	tExpectation_->Fill();
	return kTRUE;
}

void EffMaker::SlaveTerminate()
{
	// The SlaveTerminate() function is called after all entries or objects
	// have been processed. When running with PROOF SlaveTerminate() is called
	// on each slave server.
	
}

void EffMaker::Terminate()
{
	TFile *outPutFile = new TFile("Expectation.root","RECREATE"); 
	outPutFile->cd();
	tExpectation_->Write();
	outPutFile->mkdir("Efficiencies");
	TDirectory *dEfficiencies = (TDirectory*)outPutFile->Get("Efficiencies");
	dEfficiencies->cd();
	gStyle->SetPaintTextFormat("5.2f");
	gStyle->SetStatW(0.1);
	gStyle->SetStatH(0.1);
	gStyle->SetStatY(202);
	gStyle->SetTitleYOffset(1.3);
	
	
	MuonAcc = ratioCalculator(MuonAcc,MuonAccFail);   
	// MuonAccFail->Delete("all");
	MuonAcc->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu acceptance; #slash{H}_{T} [GeV]; N_{Jets}");
	MuonAcc->SetMarkerSize(2.0);
	MuonAcc->UseCurrentStyle();
	MuonAcc->Write();
	SaveEfficiency(MuonAcc);
	
	
	MuonRecoLow = ratioCalculator(MuonRecoLow,MuonRecoLowFail);   
	//MuonRecoLowFail->Delete("all");
	MuonRecoLow->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu reco N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonRecoLow->SetMarkerSize(2.0);
	MuonRecoLow->UseCurrentStyle();
	MuonRecoLow->Write();
	SaveEfficiency(MuonRecoLow);
	
	MuonReco0 = ratioCalculator(MuonReco0,MuonReco0Fail);   
	// MuonReco0Fail->Delete("all");
	MuonReco0->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu reco 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonReco0->SetMarkerSize(2.0);
	MuonReco0->UseCurrentStyle();
	MuonReco0->Write();
	SaveEfficiency(MuonReco0);
	
	MuonReco1 = ratioCalculator(MuonReco1,MuonReco1Fail);   
	//MuonReco1Fail->Delete("all");
	MuonReco1->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu reco 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonReco1->SetMarkerSize(2.0);
	MuonReco1->UseCurrentStyle();
	MuonReco1->Write();
	SaveEfficiency(MuonReco1);
	
	MuonReco2 = ratioCalculator(MuonReco2,MuonReco2Fail);   
	// MuonReco2Fail->Delete("all");
	MuonReco2->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu reco 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonReco2->SetMarkerSize(2.0);
	MuonReco2->UseCurrentStyle();
	MuonReco2->Write();
	SaveEfficiency(MuonReco2);
	
	
	MuonIsoLow = ratioCalculator(MuonIsoLow,MuonIsoLowFail);   
	//  MuonIsoLowFail->Delete("all");
	MuonIsoLow->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu iso N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonIsoLow->SetMarkerSize(2.0);
	MuonIsoLow->UseCurrentStyle();
	MuonIsoLow->Write();
	SaveEfficiency(MuonIsoLow);
	
	MuonIso0 = ratioCalculator(MuonIso0,MuonIso0Fail);   
	//  MuonIso0Fail->Delete("all");
	MuonIso0->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu iso 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonIso0->SetMarkerSize(2.0);
	MuonIso0->UseCurrentStyle();
	MuonIso0->Write();
	SaveEfficiency(MuonIso0);
	
	MuonIso1 = ratioCalculator(MuonIso1,MuonIso1Fail);   
	//  MuonIso1Fail->Delete("all");
	MuonIso1->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu iso 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonIso1->SetMarkerSize(2.0);
	MuonIso1->UseCurrentStyle();
	MuonIso1->Write();
	SaveEfficiency(MuonIso1);
	
	MuonIso2 = ratioCalculator(MuonIso2,MuonIso2Fail);   
	//  MuonIso2Fail->Delete("all");
	MuonIso2->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu iso 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonIso2->SetMarkerSize(2.0);
	MuonIso2->UseCurrentStyle();
	MuonIso2->Write();
	SaveEfficiency(MuonIso2);
	
	MuMTWNJet = ratioCalculator(MuMTWNJet,MuMTWNJetFail);   
	// MuMTWNJetFail->Delete("all");
	MuMTWNJet->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu M_{T}(W); N_{Jets}");
	MuMTWNJet->UseCurrentStyle();
	MuMTWNJet->Write();
	
	MuMTWMHTNJet = ratioCalculator(MuMTWMHTNJet,MuMTWMHTNJetFail);   
	// MuMTWMHTNJetFail->Delete("all");
	MuMTWMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu M_{T}(W); #slash{H}_{T} [GeV]; N_{Jets}");
	MuMTWMHTNJet->SetMarkerSize(2.0);
	MuMTWMHTNJet->UseCurrentStyle();
	MuMTWMHTNJet->Write();
	SaveEfficiency(MuMTWMHTNJet);
	
	MuonPurityMHTNJet = ratioCalculator(MuonPurityMHTNJet,MuonPurityMHTNJetFail);   
	// MuMTWMHTNJetFail->Delete("all");
	MuonPurityMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu purity; #slash{H}_{T} [GeV]; N_{Jets}");
	MuonPurityMHTNJet->SetMarkerSize(2.0);
	MuonPurityMHTNJet->UseCurrentStyle();
	MuonPurityMHTNJet->Write();
	SaveEfficiency(MuonPurityMHTNJet);
	
	
	MuDiLepControlSampleMHTNJet = ratioCalculator(MuDiLepControlSampleMHTNJet,MuDiLepControlSampleMHTNJetFail);   
	// MuMTWMHTNJetFail->Delete("all");
	MuDiLepControlSampleMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu diLepCorrection; #slash{H}_{T} [GeV]; N_{Jets}");
	MuDiLepControlSampleMHTNJet->SetMarkerSize(2.0);
	MuDiLepControlSampleMHTNJet->UseCurrentStyle();
	MuDiLepControlSampleMHTNJet->Write();
	SaveEfficiency(MuDiLepControlSampleMHTNJet);
	
	int n_;
	char buffer_[300];
	TString TTemp_;
	n_ = sprintf(buffer_,"CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu diLepCorrection m_{T}(w)<%.0f; #slash{H}_{T} [GeV]; N_{Jets}",mtwCut_);
	TTemp_+=buffer_;
	
	MuDiLepControlSampleMHTNJetMTW = ratioCalculator(MuDiLepControlSampleMHTNJetMTW,MuDiLepControlSampleMHTNJetMTWFail);   
	// MuMTWMHTNJetFail->Delete("all");
	MuDiLepControlSampleMHTNJetMTW->SetTitle(TTemp_);
	MuDiLepControlSampleMHTNJetMTW->SetMarkerSize(2.0);
	MuDiLepControlSampleMHTNJetMTW->UseCurrentStyle();
	MuDiLepControlSampleMHTNJetMTW->Write();
	SaveEfficiency(MuDiLepControlSampleMHTNJetMTW);
	
	MuDiLepEffNJets = ratioCalculator(MuDiLepEffNJets,MuDiLepEffNJetsFail);   
	// MuMTWMHTNJetFail->Delete("all");
	MuDiLepEffNJets->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu di lep eff; N_{Jets}");
	MuDiLepEffNJets->SetMarkerSize(2.0);
	MuDiLepEffNJets->UseCurrentStyle();
	MuDiLepEffNJets->Write();
	SaveEfficiency(MuDiLepEffNJets);
	
	//Btag
	MuonAccBTag = ratioCalculator(MuonAccBTag,MuonAccBTagFail);   
	MuonAccBTag->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu acceptance; #slash{H}_{T} [GeV]; BTag");
	MuonAccBTag->SetMarkerSize(2.0);
	MuonAccBTag->UseCurrentStyle();
	MuonAccBTag->Write();
	SaveEfficiency(MuonAccBTag);
	
	MuonRecoBTag0 = ratioCalculator(MuonRecoBTag0,MuonRecoBTag0Fail);   
	//MuonRecoLowFail->Delete("all");
	MuonRecoBTag0->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu reco BTag=0; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonRecoBTag0->SetMarkerSize(2.0);
	MuonRecoBTag0->UseCurrentStyle();
	MuonRecoBTag0->Write();
	SaveEfficiency(MuonRecoBTag0);
	
	MuonRecoBTag1 = ratioCalculator(MuonRecoBTag1,MuonRecoBTag1Fail);   
	//MuonRecoLowFail->Delete("all");
	MuonRecoBTag1->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu reco BTag=1; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonRecoBTag1->SetMarkerSize(2.0);
	MuonRecoBTag1->UseCurrentStyle();
	MuonRecoBTag1->Write();
	SaveEfficiency(MuonRecoBTag1);
	
	MuonRecoBTag2ToInf = ratioCalculator(MuonRecoBTag2ToInf,MuonRecoBTag2ToInfFail);   
	//MuonRecoLowFail->Delete("all");
	MuonRecoBTag2ToInf->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu reco BTag=>2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonRecoBTag2ToInf->SetMarkerSize(2.0);
	MuonRecoBTag2ToInf->UseCurrentStyle();
	MuonRecoBTag2ToInf->Write();
	SaveEfficiency(MuonRecoBTag2ToInf);
	
	MuonIsoBTag0 = ratioCalculator(MuonIsoBTag0,MuonIsoBTag0Fail);   
	//MuonIsoLowFail->Delete("all");
	MuonIsoBTag0->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu iso BTag=0; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonIsoBTag0->SetMarkerSize(2.0);
	MuonIsoBTag0->UseCurrentStyle();
	MuonIsoBTag0->Write();
	SaveEfficiency(MuonIsoBTag0);
	
	MuonIsoBTag1 = ratioCalculator(MuonIsoBTag1,MuonIsoBTag1Fail);   
	//MuonIsoLowFail->Delete("all");
	MuonIsoBTag1->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu iso BTag=1; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonIsoBTag1->SetMarkerSize(2.0);
	MuonIsoBTag1->UseCurrentStyle();
	MuonIsoBTag1->Write();
	SaveEfficiency(MuonIsoBTag1);
	
	MuonIsoBTag2ToInf = ratioCalculator(MuonIsoBTag2ToInf,MuonIsoBTag2ToInfFail);   
	//MuonIsoLowFail->Delete("all");
	MuonIsoBTag2ToInf->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu iso BTag=>2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	MuonIsoBTag2ToInf->SetMarkerSize(2.0);
	MuonIsoBTag2ToInf->UseCurrentStyle();
	MuonIsoBTag2ToInf->Write();
	SaveEfficiency(MuonIsoBTag2ToInf);
	
	n_ = sprintf(buffer_,"CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV #mu m_{T} correction m_{T}(w)<%.0f; BTag; N_{Jets}",mtwCut_);
	TTemp_+=buffer_;
	
	MuMTWMHTBTag = ratioCalculator(MuMTWMHTBTag,MuMTWMHTBTagFail);   
	//MuonIsoLowFail->Delete("all");
	MuMTWMHTBTag->SetTitle(TTemp_);
	MuMTWMHTBTag->SetMarkerSize(2.0);
	MuMTWMHTBTag->UseCurrentStyle();
	MuMTWMHTBTag->Write();
	SaveEfficiency(MuMTWMHTBTag);
	
	
	ElecAcc = ratioCalculator(ElecAcc,ElecAccFail);   
	//  ElecAccFail->Delete("all");
	ElecAcc->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec acceptance; #slash{H}_{T} [GeV]; N_{Jets}");
	ElecAcc->Write();
	SaveEfficiency(ElecAcc);
	
	ElecRecoLow = ratioCalculator(ElecRecoLow,ElecRecoLowFail);   
	//  ElecRecoLowFail->Delete("all");
	ElecRecoLow->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec reco N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecRecoLow->Write();
	SaveEfficiency(ElecRecoLow);
	
	ElecReco0 = ratioCalculator(ElecReco0,ElecReco0Fail);   
	//   ElecReco0Fail->Delete("all");
	ElecReco0->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec reco 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecReco0->Write();
	SaveEfficiency(ElecReco0);
	
	ElecReco1 = ratioCalculator(ElecReco1,ElecReco1Fail);   
	// ElecReco1Fail->Delete("all");
	ElecReco1->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec reco 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecReco1->Write();
	SaveEfficiency(ElecReco1);
	
	ElecReco2 = ratioCalculator(ElecReco2,ElecReco2Fail);   
	//  ElecReco2Fail->Delete("all");
	ElecReco2->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec reco 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecReco2->Write();
	SaveEfficiency(ElecReco2);
	
	ElecIsoLow = ratioCalculator(ElecIsoLow,ElecIsoLowFail);   
	//  ElecIsoLowFail->Delete("all");
	ElecIsoLow->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec iso N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecIsoLow->Write();
	SaveEfficiency(ElecIsoLow);
	
	ElecIso0 = ratioCalculator(ElecIso0,ElecIso0Fail);   
	//  ElecIso0Fail->Delete("all");
	ElecIso0->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec iso 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecIso0->Write();
	SaveEfficiency(ElecIso0);
	
	ElecIso1 = ratioCalculator(ElecIso1,ElecIso1Fail);   
	//   ElecIso1Fail->Delete("all");
	ElecIso1->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec iso 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecIso1->Write();
	SaveEfficiency(ElecIso1);
	
	ElecIso2 = ratioCalculator(ElecIso2,ElecIso2Fail);   
	//  ElecIso2Fail->Delete("all");
	ElecIso2->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec iso 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecIso2->Write();
	SaveEfficiency(ElecIso2);
	
	ElecMTWNJet = ratioCalculator(ElecMTWNJet,ElecMTWNJetFail);   
	//  ElecMTWNJetFail->Delete("all");
	ElecMTWNJet->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec M_{T}(W); N_{Jets}");
	ElecMTWNJet->Write();
	
	ElecMTWMHTNJet = ratioCalculator(ElecMTWMHTNJet,ElecMTWMHTNJetFail);   
	//  ElecMTWMHTNJetFail->Delete("all");
	ElecMTWMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec M_{T}(W); #slash{H}_{T} [GeV]; N_{Jets}");
	ElecMTWMHTNJet->Write();
	SaveEfficiency(ElecMTWMHTNJet);
	
	ElecPurityMHTNJet = ratioCalculator(ElecPurityMHTNJet,ElecPurityMHTNJetFail);   
	// MuMTWMHTNJetFail->Delete("all");
	ElecPurityMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec purity; #slash{H}_{T} [GeV]; N_{Jets}");
	ElecPurityMHTNJet->SetMarkerSize(2.0);
	ElecPurityMHTNJet->UseCurrentStyle();
	ElecPurityMHTNJet->Write();
	SaveEfficiency(ElecPurityMHTNJet);
	
	ElecDiLepControlSampleMHTNJet = ratioCalculator(ElecDiLepControlSampleMHTNJet,ElecDiLepControlSampleMHTNJetFail);   
	// ElecMTWMHTNJetFail->Delete("all");
	ElecDiLepControlSampleMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec diLepCorrection; #slash{H}_{T} [GeV]; N_{Jets}");
	ElecDiLepControlSampleMHTNJet->SetMarkerSize(2.0);
	ElecDiLepControlSampleMHTNJet->UseCurrentStyle();
	ElecDiLepControlSampleMHTNJet->Write();
	SaveEfficiency(ElecDiLepControlSampleMHTNJet);
	
	
	n_ = sprintf(buffer_,"CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec diLepCorrection m_{T}(w)<%.0f; #slash{H}_{T} [GeV]; N_{Jets}",mtwCut_);
	TTemp_+=buffer_;
	
	ElecDiLepControlSampleMHTNJetMTW = ratioCalculator(ElecDiLepControlSampleMHTNJetMTW,ElecDiLepControlSampleMHTNJetMTWFail);   
	// MuMTWMHTNJetFail->Delete("all");
	ElecDiLepControlSampleMHTNJetMTW->SetTitle(TTemp_);
	ElecDiLepControlSampleMHTNJetMTW->SetMarkerSize(2.0);
	ElecDiLepControlSampleMHTNJetMTW->UseCurrentStyle();
	ElecDiLepControlSampleMHTNJetMTW->Write();
	SaveEfficiency(ElecDiLepControlSampleMHTNJetMTW);
	
	ElecDiLepEffNJets = ratioCalculator(ElecDiLepEffNJets,ElecDiLepEffNJetsFail);   
	// elecMTWMHTNJetFail->Delete("all");
	ElecDiLepEffNJets->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec di lep eff; N_{Jets}");
	ElecDiLepEffNJets->SetMarkerSize(2.0);
	ElecDiLepEffNJets->UseCurrentStyle();
	ElecDiLepEffNJets->Write();
	SaveEfficiency(ElecDiLepEffNJets);
	
	//Btag
	ElecAccBTag = ratioCalculator(ElecAccBTag,ElecAccBTagFail);   
	ElecAccBTag->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec acceptance; #slash{H}_{T} [GeV]; BTag");
	ElecAccBTag->SetMarkerSize(2.0);
	ElecAccBTag->UseCurrentStyle();
	ElecAccBTag->Write();
	SaveEfficiency(ElecAccBTag);
	
	ElecRecoBTag0 = ratioCalculator(ElecRecoBTag0,ElecRecoBTag0Fail);   
	//ElecRecoLowFail->Delete("all");
	ElecRecoBTag0->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec reco BTag=0; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecRecoBTag0->SetMarkerSize(2.0);
	ElecRecoBTag0->UseCurrentStyle();
	ElecRecoBTag0->Write();
	SaveEfficiency(ElecRecoBTag0);
	
	ElecRecoBTag1 = ratioCalculator(ElecRecoBTag1,ElecRecoBTag1Fail);   
	//ElecRecoLowFail->Delete("all");
	ElecRecoBTag1->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec reco BTag=1; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecRecoBTag1->SetMarkerSize(2.0);
	ElecRecoBTag1->UseCurrentStyle();
	ElecRecoBTag1->Write();
	SaveEfficiency(ElecRecoBTag1);
	
	ElecRecoBTag2ToInf = ratioCalculator(ElecRecoBTag2ToInf,ElecRecoBTag2ToInfFail);   
	//ElecRecoLowFail->Delete("all");
	ElecRecoBTag2ToInf->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec reco BTag=>2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecRecoBTag2ToInf->SetMarkerSize(2.0);
	ElecRecoBTag2ToInf->UseCurrentStyle();
	ElecRecoBTag2ToInf->Write();
	SaveEfficiency(ElecRecoBTag2ToInf);
	
	ElecIsoBTag0 = ratioCalculator(ElecIsoBTag0,ElecIsoBTag0Fail);   
	//ElecIsoLowFail->Delete("all");
	ElecIsoBTag0->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec iso BTag=0; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecIsoBTag0->SetMarkerSize(2.0);
	ElecIsoBTag0->UseCurrentStyle();
	ElecIsoBTag0->Write();
	SaveEfficiency(ElecIsoBTag0);
	
	ElecIsoBTag1 = ratioCalculator(ElecIsoBTag1,ElecIsoBTag1Fail);   
	//ElecIsoLowFail->Delete("all");
	ElecIsoBTag1->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec iso BTag=1; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecIsoBTag1->SetMarkerSize(2.0);
	ElecIsoBTag1->UseCurrentStyle();
	ElecIsoBTag1->Write();
	SaveEfficiency(ElecIsoBTag1);
	
	ElecIsoBTag2ToInf = ratioCalculator(ElecIsoBTag2ToInf,ElecIsoBTag2ToInfFail);   
	//ElecIsoLowFail->Delete("all");
	ElecIsoBTag2ToInf->SetTitle("CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec iso BTag=>2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
	ElecIsoBTag2ToInf->SetMarkerSize(2.0);
	ElecIsoBTag2ToInf->UseCurrentStyle();
	ElecIsoBTag2ToInf->Write();
	SaveEfficiency(ElecIsoBTag2ToInf);
	
	n_ = sprintf(buffer_,"CMS Simulation, L=5 fb-1, #sqrt(s)=13 TeV elec m_{T} correction m_{T}(w)<%.0f; BTag; N_{Jets}",mtwCut_);
	TTemp_+=buffer_;
	
	ElecMTWMHTBTag = ratioCalculator(ElecMTWMHTBTag,ElecMTWMHTBTagFail);   
	//ElecIsoLowFail->Delete("all");
	ElecMTWMHTBTag->SetTitle(TTemp_);
	ElecMTWMHTBTag->SetMarkerSize(2.0);
	ElecMTWMHTBTag->UseCurrentStyle();
	ElecMTWMHTBTag->Write();
	SaveEfficiency(ElecMTWMHTBTag);
	
	
	
	// save pass and fail not ratio
	MuonAcc->Write(); MuonAccFail->Write();

	MuonRecoLow->Write(); MuonRecoLowFail->Write();
	MuonReco0->Write(); MuonReco0Fail->Write();
	MuonReco1->Write(); MuonReco1Fail->Write();
	MuonReco2->Write(); MuonReco2Fail->Write();
	
	MuonIsoLow->Write(); MuonIsoLowFail->Write();
	MuonIso0->Write(); MuonIso0Fail->Write();
	MuonIso1->Write(); MuonIso1Fail->Write();
	MuonIso2->Write(); MuonIso2Fail->Write();
	
	MuMTWNJet->Write(); MuMTWNJetFail->Write();
	MuMTWMHTNJet->Write(); 	MuMTWMHTNJetFail->Write();
	MuonPurityMHTNJet->Write(); MuonPurityMHTNJetFail->Write();
	MuDiLepControlSampleMHTNJet->Write(); MuDiLepControlSampleMHTNJetFail->Write();
	MuDiLepControlSampleMHTNJetMTW->Write(); MuDiLepControlSampleMHTNJetMTWFail->Write();
	MuDiLepEffNJets->Write(); MuDiLepEffNJetsFail->Write();
	
	MuonAccBTag->Write(); MuonAccBTagFail->Write();
	
	MuonRecoBTag0->Write(); MuonRecoBTag0Fail->Write();
	MuonRecoBTag1->Write(); MuonRecoBTag1Fail->Write();
	MuonRecoBTag2ToInf->Write(); MuonRecoBTag2ToInfFail->Write();
	
	MuonIsoBTag0->Write(); MuonIsoBTag0Fail->Write();
	MuonIsoBTag1->Write(); MuonIsoBTag1Fail->Write();
	MuonIsoBTag2ToInf->Write(); MuonIsoBTag2ToInfFail->Write();
	
	MuMTWMHTBTag->Write();MuMTWMHTBTagFail->Write();
	
	
	ElecAcc->Write(); ElecAccFail->Write();
	
	ElecRecoLow->Write(); ElecRecoLowFail->Write();
	ElecReco0->Write(); ElecReco0Fail->Write();
	ElecReco1->Write(); ElecReco1Fail->Write();
	ElecReco2->Write(); ElecReco2Fail->Write();
	
	ElecIsoLow->Write(); ElecIsoLowFail->Write();
	ElecIso0->Write(); ElecIso0Fail->Write();
	ElecIso1->Write(); ElecIso1Fail->Write();
	ElecIso2->Write(); ElecIso2Fail->Write();
	
	ElecMTWNJet->Write(); ElecMTWNJetFail->Write();
	ElecMTWMHTNJet->Write(); 	ElecMTWMHTNJetFail->Write();
	ElecPurityMHTNJet->Write(); ElecPurityMHTNJetFail->Write();
	ElecDiLepControlSampleMHTNJet->Write(); ElecDiLepControlSampleMHTNJetFail->Write();
	ElecDiLepControlSampleMHTNJetMTW->Write(); ElecDiLepControlSampleMHTNJetMTWFail->Write();
	ElecDiLepEffNJets->Write(); ElecDiLepEffNJetsFail->Write();
	
	
	ElecAccBTag->Write(); ElecAccBTagFail->Write();
	
	ElecRecoBTag0->Write(); ElecRecoBTag0Fail->Write();
	ElecRecoBTag1->Write(); ElecRecoBTag1Fail->Write();
	ElecRecoBTag2ToInf->Write(); ElecRecoBTag2ToInfFail->Write();
	
	ElecIsoBTag0->Write(); ElecIsoBTag0Fail->Write();
	ElecIsoBTag1->Write(); ElecIsoBTag1Fail->Write();
	ElecIsoBTag2ToInf->Write(); ElecIsoBTag2ToInfFail->Write();
	
	ElecMTWMHTBTag->Write();ElecMTWMHTBTagFail->Write();
	

	
	// efficiency studies TH1 and so on
	outPutFile->mkdir("OneDEffStudy");
	TDirectory *dOneDEffStudy = (TDirectory*)outPutFile->Get("OneDEffStudy");
	dOneDEffStudy->cd();
	
	MuAccBTag_->Write();
	MuAccBTagFail_->Write();
	MuAccNJetS_->Write();
	MuAccNJetSFail_->Write();
	MuAccHT_->Write();
	MuAccHTFail_->Write();
	MuAccMHT_->Write();
	MuAccMHTFail_->Write();
	
	MuRecoBTag_->Write();
	MuRecoBTagFail_->Write();
	MuRecoNJets_->Write();
	MuRecoNJetsFail_->Write();
	MuRecoHT_->Write();
	MuRecoHTFail_->Write();
	MuRecoMHT_->Write();
	MuRecoMHTFail_->Write();
	
	MuIsoBTag_->Write();
	MuIsoBTagFail_->Write();
	MuIsoNJets_->Write();
	MuIsoNJetsFail_->Write();
	MuIsoHT_->Write();
	MuIsoHTFail_->Write();
	MuIsoMHT_->Write();
	MuIsoMHTFail_->Write();
	
	MuMTWBTag_->Write();
	MuMTWBTagFail_->Write();
	MuMTWNJets_->Write();
	MuMTWNJetsFail_->Write();
	MuMTWHT_->Write();
	MuMTWHTFail_->Write();
	MuMTWMHT_->Write();
	MuMTWMHTFail_->Write();
	
	MuPurityBTag_->Write();
	MuPurityBTagFail_->Write();
	MuPurityNJets_->Write();
	MuPurityNJetsFail_->Write();
	MuPurityHT_->Write();
	MuPurityHTFail_->Write();
	MuPurityMHT_->Write();
	MuPurityMHTFail_->Write();
	
	
	
	ElecAccBTag_->Write();
	ElecAccBTagFail_->Write();
	ElecAccNJetS_->Write();
	ElecAccNJetSFail_->Write();
	ElecAccHT_->Write();
	ElecAccHTFail_->Write();
	ElecAccMHT_->Write();
	ElecAccMHTFail_->Write();
	
	ElecRecoBTag_->Write();
	ElecRecoBTagFail_->Write();
	ElecRecoNJets_->Write();
	ElecRecoNJetsFail_->Write();
	ElecRecoHT_->Write();
	ElecRecoHTFail_->Write();
	ElecRecoMHT_->Write();
	ElecRecoMHTFail_->Write();
	
	ElecIsoBTag_->Write();
	ElecIsoBTagFail_->Write();
	ElecIsoNJets_->Write();
	ElecIsoNJetsFail_->Write();
	ElecIsoHT_->Write();
	ElecIsoHTFail_->Write();
	ElecIsoMHT_->Write();
	ElecIsoMHTFail_->Write();
	
	ElecMTWBTag_->Write();
	ElecMTWBTagFail_->Write();
	ElecMTWNJets_->Write();
	ElecMTWNJetsFail_->Write();
	ElecMTWHT_->Write();
	ElecMTWHTFail_->Write();
	ElecMTWMHT_->Write();
	ElecMTWMHTFail_->Write();
	
	
	ElecPurityBTag_->Write();
	ElecPurityBTagFail_->Write();
	ElecPurityNJets_->Write();
	ElecPurityNJetsFail_->Write();
	ElecPurityHT_->Write();
	ElecPurityHTFail_->Write();
	ElecPurityMHT_->Write();
	ElecPurityMHTFail_->Write();
	
	
	MuIsoTrackBTag_->Write();
	MuIsoTrackBTagFail_->Write();
	MuIsoTrackNJets_->Write();
	MuIsoTrackNJetsFail_->Write();
	MuIsoTrackHT_->Write();
	MuIsoTrackHTFail_->Write();
	MuIsoTrackMHT_->Write();
	MuIsoTrackMHTFail_->Write();
	MuIsoTrackPT_->Write();
	MuIsoTrackPTFail_->Write();
	
	
	ElecIsoTrackBTag_->Write();
	ElecIsoTrackBTagFail_->Write();
	ElecIsoTrackNJets_->Write();
	ElecIsoTrackNJetsFail_->Write();
	ElecIsoTrackHT_->Write();
	ElecIsoTrackHTFail_->Write();
	ElecIsoTrackMHT_->Write();
	ElecIsoTrackMHTFail_->Write();
	ElecIsoTrackPT_->Write();
	ElecIsoTrackPTFail_->Write();
	
	// The Terminate() function is the last function to be called during
	// a query. It always runs on the client, it can be used to present
	// the results graphically or save the results to file.
	
}
void EffMaker::resetValues()
{
	Expectation=0;
	muIso =1;
	muReco =1;
	muAcc =1;
	muMTW =1;
	muTotal=1;
	elecIso =1;
	elecReco =1;
	elecAcc =1;
	elecTotal=1;
	elecMTW=1;
	FallsVetoLep=0;
	FallsVetoIsoTrack=0;
	FallsVetoIsoTrackPT10=0;
	FallsVetoIsoTrackPT10IsoCut08=0;
	FallsVetoIsoTrackPT10IsoCut12=0;
	for(unsigned int i=0; i<20;i++)
	{
		RecoIsoMuonPromtMatched[i]=999;
		RecoIsoMuonPromtMatchedDeltaR[i]=999.;
		RecoIsoMuonPromtMatchedRelPt[i]=999.;
		RecoIsoElecPromtMatched[i]=999;
		RecoIsoElecPromtMatchedDeltaR[i]=999.;
		RecoIsoElecPromtMatchedRelPt[i]=999.;
		GenMuonIsoTrackMatched[i]=0;
		RecoIsoMuonIsoTrackMatched[i]=0;
		GenElecIsoTrackMatched[i]=0;
		RecoIsoElecIsoTrackMatched[i]=0;
		GenTauIsoTrackMatched[i]=0;
		SelectedIsoTracksMatchedToGenLepton[i]=0;
		SelectedIsoTracksMatchedToRecoIsoLepton[i]=0;
		SelectedIsoTracksMatchedToGenDeltaR[i]=-1; 
		SelectedIsoTracksMatchedToGenRelPT[i]=-1;
		SelectedIsoTracksMatchedToRecoIsoDeltaR[i]=-1;
		SelectedIsoTracksMatchedToRecoIsoRelPT[i]=-1;
		
		
		GenMuonIsolatedTracksPT10Matched[i]=0;
		RecoIsoMuonIsolatedTracksPT10Matched[i]=0;
		GenElecIsolatedTracksPT10Matched[i]=0;
		RecoIsoElecIsolatedTracksPT10Matched[i]=0;
		GenTauIsolatedTracksPT10Matched[i]=0;
		IsolatedTracksPT10MatchedToGenLepton[i]=0;
		IsolatedTracksPT10MatchedToRecoIsoLepton[i]=0;
		IsolatedTracksPT10MatchedToGenDeltaR[i]=-1; 
		IsolatedTracksPT10MatchedToGenRelPT[i]=-1;
		IsolatedTracksPT10MatchedToRecoIsoDeltaR[i]=-1;
		IsolatedTracksPT10MatchedToRecoIsoRelPT[i]=-1;
		
		GenMuonIsolatedTracksPT10IsoCut08Matched[i]=0;
		RecoIsoMuonIsolatedTracksPT10IsoCut08Matched[i]=0;
		GenElecIsolatedTracksPT10IsoCut08Matched[i]=0;
		RecoIsoElecIsolatedTracksPT10IsoCut08Matched[i]=0;
		GenTauIsolatedTracksPT10IsoCut08Matched[i]=0;
		IsolatedTracksPT10IsoCut08MatchedToGenLepton[i]=0;
		IsolatedTracksPT10IsoCut08MatchedToRecoIsoLepton[i]=0;
		IsolatedTracksPT10IsoCut08MatchedToGenDeltaR[i]=-1; 
		IsolatedTracksPT10IsoCut08MatchedToGenRelPT[i]=-1;
		IsolatedTracksPT10IsoCut08MatchedToRecoIsoDeltaR[i]=-1;
		IsolatedTracksPT10IsoCut08MatchedToRecoIsoRelPT[i]=-1;
		
		GenMuonIsolatedTracksPT10IsoCut12Matched[i]=0;
		RecoIsoMuonIsolatedTracksPT10IsoCut12Matched[i]=0;
		GenElecIsolatedTracksPT10IsoCut12Matched[i]=0;
		RecoIsoElecIsolatedTracksPT10IsoCut12Matched[i]=0;
		GenTauIsolatedTracksPT10IsoCut12Matched[i]=0;
		IsolatedTracksPT10IsoCut12MatchedToGenLepton[i]=0;
		IsolatedTracksPT10IsoCut12MatchedToRecoIsoLepton[i]=0;
		IsolatedTracksPT10IsoCut12MatchedToGenDeltaR[i]=-1; 
		IsolatedTracksPT10IsoCut12MatchedToGenRelPT[i]=-1;
		IsolatedTracksPT10IsoCut12MatchedToRecoIsoDeltaR[i]=-1;
		IsolatedTracksPT10IsoCut12MatchedToRecoIsoRelPT[i]=-1;
		
	}
}
bool EffMaker::FiltersPass()
{
	bool result=true;
	// if(Filter_HBHENoiseFilterRA2==0) result=false;
	return result;
}
TH2F* EffMaker::ratioCalculator(TH2F* passTH2, TH2F* failTH2)
{
	passTH2->Sumw2();
	TH2F *sum = (TH2F*)passTH2->Clone();
	failTH2->Sumw2();
	
	sum->Add(failTH2);
	passTH2->Divide(passTH2,sum,1,1,"B");
	return passTH2;
}
TH1F* EffMaker::ratioCalculator(TH1F* passTH1, TH1F* failTH1)
{
	passTH1->Sumw2();
	TH1F *sum = (TH1F*)passTH1->Clone();
	failTH1->Sumw2();
	
	sum->Add(failTH1);
	passTH1->Divide(passTH1,sum,1,1,"B");
	return passTH1;
}
double EffMaker::deltaR(double eta1, double phi1, double eta2, double phi2)
{
	double deta = eta1-eta2;
	double dphi = TVector2::Phi_mpi_pi(phi1-phi2);
	return sqrt(deta * deta + dphi *dphi); 
}

double EffMaker::MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi)
{
	double deltaPhi =TVector2::Phi_mpi_pi(lepPhi-metPhi);
	return sqrt(2*lepPt*metPt*(1-cos(deltaPhi)) );
}

void EffMaker::SaveEfficiency(TH2F *input)
{
	gROOT->SetBatch(true);
	const TString th2Name = input->GetName();
	const TString th2Title = input->GetTitle();
	TCanvas *c1 = new TCanvas(th2Name,th2Title,1);
	c1->cd();
	c1->SetLogx();
	c1->SetLogy();
	input->SetMarkerSize(2.0);
	input->UseCurrentStyle();
	input->Draw("ColZ,Text,E");
	// c1->SaveAs(s+"MuonAccEff3"+".png");
	if(saveEffToPDF_) c1->SaveAs(th2Name+".pdf");
	if(saveEffToPNG_) c1->SaveAs(th2Name+".png");
	delete c1;
	gROOT->SetBatch(false);
	
}

void EffMaker::SaveEfficiency(TH1F *input)
{
	gROOT->SetBatch(true);
	const TString th2Name = input->GetName();
	const TString th2Title = input->GetTitle();
	TCanvas *c1 = new TCanvas(th2Name,th2Title,1);
	c1->cd();
	//c1->SetLogx();
	//c1->SetLogy();
	input->SetMarkerSize(2.0);
	input->UseCurrentStyle();
	input->Draw("ColZ,Text,E");
	// c1->SaveAs(s+"MuonAccEff3"+".png");
	if(saveEffToPDF_) c1->SaveAs(th2Name+".pdf");
	if(saveEffToPNG_) c1->SaveAs(th2Name+".png");
	delete c1;
	gROOT->SetBatch(false);
	
}
