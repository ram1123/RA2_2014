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
   tExpectation_->Branch("WeightProducer", &WeightProducer, "WeightProducer/F");
   tExpectation_->Branch("METPt",&METPt,"METPt/F");
   tExpectation_->Branch("METEta",&METEta,"METEta/F");
   tExpectation_->Branch("METPhi",&METPhi,"METPhi/F");
   tExpectation_->Branch("GenMuNum",&GenMuNum,"GenMuNum/s");
   tExpectation_->Branch("GenMuFromTau",GenMuFromTau,"GenMuFromTau[GenMuNum]/s");
   tExpectation_->Branch("GenMuPt", GenMuPt,"GenMuPt[GenMuNum]/F");
   tExpectation_->Branch("GenMuEta", GenMuEta,"GenMuEta[GenMuNum]/F");
   tExpectation_->Branch("GenMuPhi", GenMuPhi,"GenMuPhi[GenMuNum]/F");
   tExpectation_->Branch("GenMuonIsoTrackMatched", GenMuonIsoTrackMatched, "GenMuonIsoTrackMatched[GenMuNum]/s"); 
   tExpectation_->Branch("GenElecNum",&GenElecNum,"GenElecNum/s");
   tExpectation_->Branch("GenElecFromTau",GenElecFromTau,"GenElecFromTau[GenElecNum]/s");
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
   tExpectation_->Branch("RecoIsoMuonNum",&RecoIsoMuonNum,"RecoIsoMuonNum/s");
   tExpectation_->Branch("RecoIsoMuonPt", RecoIsoMuonPt, "RecoIsoMuonPt[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonPromtMatched", RecoIsoMuonPromtMatched, "RecoIsoMuonPromtMatched[RecoIsoMuonNum]/s");
   tExpectation_->Branch("RecoIsoMuonPromtMatchedDeltaR", RecoIsoMuonPromtMatchedDeltaR, "RecoIsoMuonPromtMatchedDeltaR[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonPromtMatchedRelPt", RecoIsoMuonPromtMatchedRelPt, "RecoIsoMuonPromtMatchedRelPt[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonEta", RecoIsoMuonEta, "RecoIsoMuonEta[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonPhi", RecoIsoMuonPhi, "RecoIsoMuonPhi[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonE", RecoIsoMuonE, "RecoIsoMuonE[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonIsoTrackMatched", RecoIsoMuonIsoTrackMatched, "RecoIsoMuonIsoTrackMatched[RecoIsoMuonNum]/s");  
   tExpectation_->Branch("RecoIsoElecNum",&RecoIsoElecNum,"RecoIsoElecNum/s");
   tExpectation_->Branch("RecoIsoElecPt", RecoIsoElecPt, "RecoIsoElecPt[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecPromtMatched", RecoIsoElecPromtMatched, "RecoIsoElecPromtMatched[RecoIsoElecNum]/s");
   tExpectation_->Branch("RecoIsoElecPromtMatchedDeltaR", RecoIsoElecPromtMatchedDeltaR, "RecoIsoElecPromtMatchedDeltaR[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecPromtMatchedRelPt", RecoIsoElecPromtMatchedRelPt, "RecoIsoElecPromtMatchedRelPt[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecEta", RecoIsoElecEta, "RecoIsoElecEta[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecPhi", RecoIsoElecPhi, "RecoIsoElecPhi[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecE", RecoIsoElecE, "RecoIsoElecE[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecIsoTrackMatched", RecoIsoElecIsoTrackMatched, "RecoIsoElecIsoTrackMatched[RecoIsoElecNum]/s"); 
   
   tExpectation_->Branch("SelectedIsoTracksNum",&SelectedIsoTracksNum,"SelectedIsoTracksNum/s");
	 tExpectation_->Branch("FallsVetoIsoTrack",&FallsVetoIsoTrack,"FallsVetoIsoTrack/s");
   tExpectation_->Branch("SelectedIsoTracksPt", SelectedIsoTracksPt, "SelectedIsoTracksPt[SelectedIsoTracksNum]/F");
   tExpectation_->Branch("SelectedIsoTracksEta", SelectedIsoTracksEta, "SelectedIsoTracksEta[SelectedIsoTracksNum]/F");
   tExpectation_->Branch("SelectedIsoTracksPhi", SelectedIsoTracksPhi, "SelectedIsoTracksPhi[SelectedIsoTracksNum]/F");
   tExpectation_->Branch("SelectedIsoTracksE", SelectedIsoTracksE, "SelectedIsoTracksE[SelectedIsoTracksNum]/F");
   tExpectation_->Branch("SelectedIsoTracksMatchedToGenLepton", SelectedIsoTracksMatchedToGenLepton, "SelectedIsoTracksMatchedToGenLepton[SelectedIsoTracksNum]/s");  
   tExpectation_->Branch("SelectedIsoTracksMatchedToGenDeltaR", SelectedIsoTracksMatchedToGenDeltaR, "SelectedIsoTracksMatchedToGenDeltaR[SelectedIsoTracksNum]/F"); 
   tExpectation_->Branch("SelectedIsoTracksMatchedToGenRelPT", SelectedIsoTracksMatchedToGenRelPT, "SelectedIsoTracksMatchedToGenRelPT[SelectedIsoTracksNum]/F"); 
   tExpectation_->Branch("SelectedIsoTracksMatchedToRecoIsoLepton", SelectedIsoTracksMatchedToRecoIsoLepton, "SelectedIsoTracksMatchedToRecoIsoLepton[SelectedIsoTracksNum]/s");  
   
   //
   tExpectation_->Branch("IsolatedTracksPT10Num",&IsolatedTracksPT10Num,"IsolatedTracksPT10Num/s");
   tExpectation_->Branch("IsolatedTracksPT10Pt", IsolatedTracksPT10Pt, "IsolatedTracksPT10Pt[IsolatedTracksPT10Num]/F");
	 tExpectation_->Branch("FallsVetoIsoTrackPT10",&FallsVetoIsoTrackPT10,"FallsVetoIsoTrackPT10/s");
   tExpectation_->Branch("IsolatedTracksPT10Eta", IsolatedTracksPT10Eta, "IsolatedTracksPT10Eta[IsolatedTracksPT10Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10Phi", IsolatedTracksPT10Phi, "IsolatedTracksPT10Phi[IsolatedTracksPT10Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10E", IsolatedTracksPT10E, "IsolatedTracksPT10E[IsolatedTracksPT10Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10MatchedToGenLepton", IsolatedTracksPT10MatchedToGenLepton, "IsolatedTracksPT10MatchedToGenLepton[IsolatedTracksPT10Num]/s");  
   tExpectation_->Branch("IsolatedTracksPT10MatchedToGenDeltaR", IsolatedTracksPT10MatchedToGenDeltaR, "IsolatedTracksPT10MatchedToGenDeltaR[IsolatedTracksPT10Num]/F"); 
   tExpectation_->Branch("IsolatedTracksPT10MatchedToGenRelPT", IsolatedTracksPT10MatchedToGenRelPT, "IsolatedTracksPT10MatchedToGenRelPT[IsolatedTracksPT10Num]/F"); 
   tExpectation_->Branch("IsolatedTracksPT10MatchedToRecoIsoLepton", IsolatedTracksPT10MatchedToRecoIsoLepton, "IsolatedTracksPT10MatchedToRecoIsoLepton[IsolatedTracksPT10Num]/s");  
   
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08Num",&IsolatedTracksPT10IsoCut08Num,"IsolatedTracksPT10IsoCut08Num/s");
	 tExpectation_->Branch("FallsVetoIsoTrackPT10IsoCut08",&FallsVetoIsoTrackPT10IsoCut08,"FallsVetoIsoTrackPT10IsoCut08/s");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08Pt", IsolatedTracksPT10IsoCut08Pt, "IsolatedTracksPT10IsoCut08Pt[IsolatedTracksPT10IsoCut08Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08Eta", IsolatedTracksPT10IsoCut08Eta, "IsolatedTracksPT10IsoCut08Eta[IsolatedTracksPT10IsoCut08Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08Phi", IsolatedTracksPT10IsoCut08Phi, "IsolatedTracksPT10IsoCut08Phi[IsolatedTracksPT10IsoCut08Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08E", IsolatedTracksPT10IsoCut08E, "IsolatedTracksPT10IsoCut08E[IsolatedTracksPT10IsoCut08Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08MatchedToGenLepton", IsolatedTracksPT10IsoCut08MatchedToGenLepton, "IsolatedTracksPT10IsoCut08MatchedToGenLepton[IsolatedTracksPT10IsoCut08Num]/s");  
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08MatchedToGenDeltaR", IsolatedTracksPT10IsoCut08MatchedToGenDeltaR, "IsolatedTracksPT10IsoCut08MatchedToGenDeltaR[IsolatedTracksPT10IsoCut08Num]/F"); 
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08MatchedToGenRelPT", IsolatedTracksPT10IsoCut08MatchedToGenRelPT, "IsolatedTracksPT10IsoCut08MatchedToGenRelPT[IsolatedTracksPT10IsoCut08Num]/F"); 
   tExpectation_->Branch("IsolatedTracksPT10IsoCut08MatchedToRecoIsoLepton", IsolatedTracksPT10IsoCut08MatchedToRecoIsoLepton, "IsolatedTracksPT10IsoCut08MatchedToRecoIsoLepton[IsolatedTracksPT10IsoCut08Num]/s");  
   
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12Num",&IsolatedTracksPT10IsoCut12Num,"IsolatedTracksPT10IsoCut12Num/s");
	 tExpectation_->Branch("FallsVetoIsoTrackPT10IsoCut12",&FallsVetoIsoTrackPT10IsoCut12,"FallsVetoIsoTrackPT10IsoCut12/s");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12Pt", IsolatedTracksPT10IsoCut12Pt, "IsolatedTracksPT10IsoCut12Pt[IsolatedTracksPT10IsoCut12Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12Eta", IsolatedTracksPT10IsoCut12Eta, "IsolatedTracksPT10IsoCut12Eta[IsolatedTracksPT10IsoCut12Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12Phi", IsolatedTracksPT10IsoCut12Phi, "IsolatedTracksPT10IsoCut12Phi[IsolatedTracksPT10IsoCut12Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12E", IsolatedTracksPT10IsoCut12E, "IsolatedTracksPT10IsoCut12E[IsolatedTracksPT10IsoCut12Num]/F");
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12MatchedToGenLepton", IsolatedTracksPT10IsoCut12MatchedToGenLepton, "IsolatedTracksPT10IsoCut12MatchedToGenLepton[IsolatedTracksPT10IsoCut12Num]/s");  
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12MatchedToGenDeltaR", IsolatedTracksPT10IsoCut12MatchedToGenDeltaR, "IsolatedTracksPT10IsoCut12MatchedToGenDeltaR[IsolatedTracksPT10IsoCut12Num]/F"); 
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12MatchedToGenRelPT", IsolatedTracksPT10IsoCut12MatchedToGenRelPT, "IsolatedTracksPT10IsoCut12MatchedToGenRelPT[IsolatedTracksPT10IsoCut12Num]/F"); 
   tExpectation_->Branch("IsolatedTracksPT10IsoCut12MatchedToRecoIsoLepton", IsolatedTracksPT10IsoCut12MatchedToRecoIsoLepton, "IsolatedTracksPT10IsoCut12MatchedToRecoIsoLepton[IsolatedTracksPT10IsoCut12Num]/s");  
   
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
    for(unsigned int ii=0; ii< SelectedIsoTracksNum;ii++)
    {
      if(SelectedIsoTracksMatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenMuEta[i],GenMuPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii])<maxDeltaRGenMuToTack_ && std::abs(GenMuPt[i]-SelectedIsoTracksPt[ii])/GenMuPt[i] <maxDiffPtGenMuToTack_)
	{
	  GenMuonIsoTrackMatched[i]=1;
	  SelectedIsoTracksMatchedToGenLepton[ii]=1;
	  SelectedIsoTracksMatchedToGenDeltaR[ii]=deltaR(GenMuEta[i],GenMuPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii]);
	  SelectedIsoTracksMatchedToGenRelPT[ii]=GenMuPt[i]-SelectedIsoTracksPt[ii]/GenMuPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<GenElecNum;i++)
  {
    if(GenElecPt[i] <minElecPt_ || std::abs(GenElecEta[i]) > maxElecEta_) continue;
    for(unsigned int ii=0; ii< SelectedIsoTracksNum;ii++)
    {
      if(SelectedIsoTracksMatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenElecEta[i],GenElecPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii])<maxDeltaRGenElecToTack_ && std::abs(GenElecPt[i]-SelectedIsoTracksPt[ii])/GenElecPt[i] <maxDiffPtGenElecToTack_)
	{
	  GenElecIsoTrackMatched[i]=1;
	  SelectedIsoTracksMatchedToGenLepton[ii]=2;
	  SelectedIsoTracksMatchedToGenDeltaR[ii]=deltaR(GenElecEta[i],GenElecPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii]);
	  SelectedIsoTracksMatchedToGenRelPT[ii]=GenElecPt[i]-SelectedIsoTracksPt[ii]/GenElecPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<GenTauNum;i++)
  {
    if(GenTauPt[i] <minTauPt_ || std::abs(GenTauEta[i]) > maxTauEta_) continue;
    for(unsigned int ii=0; ii< SelectedIsoTracksNum;ii++)
    {
      if(SelectedIsoTracksMatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenTauEta[i],GenTauPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii])<maxDeltaRGenTauToTack_ && std::abs(GenTauPt[i]-SelectedIsoTracksPt[ii])/GenTauPt[i] <maxDiffPtGenTauToTack_)
	{
	  GenTauIsoTrackMatched[i]=1;
	  SelectedIsoTracksMatchedToGenLepton[ii]=3;
	  SelectedIsoTracksMatchedToGenDeltaR[ii]=deltaR(GenTauEta[i],GenTauPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii]);
	  SelectedIsoTracksMatchedToGenRelPT[ii]=GenTauPt[i]-SelectedIsoTracksPt[ii]/GenTauPt[i];
	}
      }
    }
  }
  // save if fals veto is true
  unsigned int temp =0;
  for(unsigned int i=0; i< SelectedIsoTracksNum;i++)
	{
		if(SelectedIsoTracksMatchedToGenLepton[i]==0)temp++;
		
	}
	if(temp!=0)FallsVetoIsoTrack=1;
  //
  
  
  for (unsigned  i=0; i<GenMuNum;i++)
  {
    if(GenMuPt[i] <minMuPt_ || std::abs(GenMuEta[i]) > maxMuEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10Num;ii++)
    {
      if(IsolatedTracksPT10MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenMuEta[i],GenMuPhi[i],IsolatedTracksPT10Eta[ii],IsolatedTracksPT10Phi[ii])<maxDeltaRGenMuToTack_ && std::abs(GenMuPt[i]-IsolatedTracksPT10Pt[ii])/GenMuPt[i] <maxDiffPtGenMuToTack_)
	{
	  GenMuonIsolatedTracksPT10Matched[i]=1;
	  IsolatedTracksPT10MatchedToGenLepton[ii]=1;
	  IsolatedTracksPT10MatchedToGenDeltaR[ii]=deltaR(GenMuEta[i],GenMuPhi[i],IsolatedTracksPT10Eta[ii],IsolatedTracksPT10Phi[ii]);
	  IsolatedTracksPT10MatchedToGenRelPT[ii]=GenMuPt[i]-IsolatedTracksPT10Pt[ii]/GenMuPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<GenElecNum;i++)
  {
    if(GenElecPt[i] <minElecPt_ || std::abs(GenElecEta[i]) > maxElecEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10Num;ii++)
    {
      if(IsolatedTracksPT10MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenElecEta[i],GenElecPhi[i],IsolatedTracksPT10Eta[ii],IsolatedTracksPT10Phi[ii])<maxDeltaRGenElecToTack_ && std::abs(GenElecPt[i]-IsolatedTracksPT10Pt[ii])/GenElecPt[i] <maxDiffPtGenElecToTack_)
	{
		GenElecIsolatedTracksPT10Matched[i]=1;
	  IsolatedTracksPT10MatchedToGenLepton[ii]=2;
	  IsolatedTracksPT10MatchedToGenDeltaR[ii]=deltaR(GenElecEta[i],GenElecPhi[i],IsolatedTracksPT10Eta[ii],IsolatedTracksPT10Phi[ii]);
	  IsolatedTracksPT10MatchedToGenRelPT[ii]=GenElecPt[i]-IsolatedTracksPT10Pt[ii]/GenElecPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<GenTauNum;i++)
  {
    if(GenTauPt[i] <minTauPt_ || std::abs(GenTauEta[i]) > maxTauEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10Num;ii++)
    {
      if(IsolatedTracksPT10MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenTauEta[i],GenTauPhi[i],IsolatedTracksPT10Eta[ii],IsolatedTracksPT10Phi[ii])<maxDeltaRGenTauToTack_ && std::abs(GenTauPt[i]-IsolatedTracksPT10Pt[ii])/GenTauPt[i] <maxDiffPtGenTauToTack_)
	{
		GenTauIsolatedTracksPT10Matched[i]=1;
	  IsolatedTracksPT10MatchedToGenLepton[ii]=3;
	  IsolatedTracksPT10MatchedToGenDeltaR[ii]=deltaR(GenTauEta[i],GenTauPhi[i],IsolatedTracksPT10Eta[ii],IsolatedTracksPT10Phi[ii]);
	  IsolatedTracksPT10MatchedToGenRelPT[ii]=GenTauPt[i]-IsolatedTracksPT10Pt[ii]/GenTauPt[i];
	}
      }
    }
  }
  // save if fals veto is true
  temp =0;
	for(unsigned int i=0; i< IsolatedTracksPT10Num;i++)
	{
		if(IsolatedTracksPT10MatchedToGenLepton[i]==0)temp++;
		
	}
	if(temp!=0)FallsVetoIsoTrackPT10=1;
  
  for (unsigned  i=0; i<GenMuNum;i++)
  {
    if(GenMuPt[i] <minMuPt_ || std::abs(GenMuEta[i]) > maxMuEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10IsoCut08Num;ii++)
    {
      if(IsolatedTracksPT10IsoCut08MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenMuEta[i],GenMuPhi[i],IsolatedTracksPT10IsoCut08Eta[ii],IsolatedTracksPT10IsoCut08Phi[ii])<maxDeltaRGenMuToTack_ && std::abs(GenMuPt[i]-IsolatedTracksPT10IsoCut08Pt[ii])/GenMuPt[i] <maxDiffPtGenMuToTack_)
	{
		GenMuonIsolatedTracksPT10IsoCut08Matched[i]=1;
	  IsolatedTracksPT10IsoCut08MatchedToGenLepton[ii]=1;
	  IsolatedTracksPT10IsoCut08MatchedToGenDeltaR[ii]=deltaR(GenMuEta[i],GenMuPhi[i],IsolatedTracksPT10IsoCut08Eta[ii],IsolatedTracksPT10IsoCut08Phi[ii]);
	  IsolatedTracksPT10IsoCut08MatchedToGenRelPT[ii]=GenMuPt[i]-IsolatedTracksPT10IsoCut08Pt[ii]/GenMuPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<GenElecNum;i++)
  {
    if(GenElecPt[i] <minElecPt_ || std::abs(GenElecEta[i]) > maxElecEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10IsoCut08Num;ii++)
    {
      if(IsolatedTracksPT10IsoCut08MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenElecEta[i],GenElecPhi[i],IsolatedTracksPT10IsoCut08Eta[ii],IsolatedTracksPT10IsoCut08Phi[ii])<maxDeltaRGenElecToTack_ && std::abs(GenElecPt[i]-IsolatedTracksPT10IsoCut08Pt[ii])/GenElecPt[i] <maxDiffPtGenElecToTack_)
	{
		GenElecIsolatedTracksPT10IsoCut08Matched[i]=1;
	  IsolatedTracksPT10IsoCut08MatchedToGenLepton[ii]=2;
	  IsolatedTracksPT10IsoCut08MatchedToGenDeltaR[ii]=deltaR(GenElecEta[i],GenElecPhi[i],IsolatedTracksPT10IsoCut08Eta[ii],IsolatedTracksPT10IsoCut08Phi[ii]);
	  IsolatedTracksPT10IsoCut08MatchedToGenRelPT[ii]=GenElecPt[i]-IsolatedTracksPT10IsoCut08Pt[ii]/GenElecPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<GenTauNum;i++)
  {
    if(GenTauPt[i] <minTauPt_ || std::abs(GenTauEta[i]) > maxTauEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10IsoCut08Num;ii++)
    {
      if(IsolatedTracksPT10IsoCut08MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenTauEta[i],GenTauPhi[i],IsolatedTracksPT10IsoCut08Eta[ii],IsolatedTracksPT10IsoCut08Phi[ii])<maxDeltaRGenTauToTack_ && std::abs(GenTauPt[i]-IsolatedTracksPT10IsoCut08Pt[ii])/GenTauPt[i] <maxDiffPtGenTauToTack_)
	{
		GenTauIsolatedTracksPT10IsoCut08Matched[i]=1;
	  IsolatedTracksPT10IsoCut08MatchedToGenLepton[ii]=3;
	  IsolatedTracksPT10IsoCut08MatchedToGenDeltaR[ii]=deltaR(GenTauEta[i],GenTauPhi[i],IsolatedTracksPT10IsoCut08Eta[ii],IsolatedTracksPT10IsoCut08Phi[ii]);
	  IsolatedTracksPT10IsoCut08MatchedToGenRelPT[ii]=GenTauPt[i]-IsolatedTracksPT10IsoCut08Pt[ii]/GenTauPt[i];
	}
      }
    }
  }
  // save if fals veto is true
  temp =0;
	for(unsigned int i=0; i< IsolatedTracksPT10IsoCut08Num;i++)
	{
		if(IsolatedTracksPT10IsoCut08MatchedToGenLepton[i]==0)temp++;
		
	}
	if(temp!=0)FallsVetoIsoTrackPT10IsoCut08=1;
  
  for (unsigned  i=0; i<GenMuNum;i++)
  {
    if(GenMuPt[i] <minMuPt_ || std::abs(GenMuEta[i]) > maxMuEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10IsoCut12Num;ii++)
    {
      if(IsolatedTracksPT10IsoCut12MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenMuEta[i],GenMuPhi[i],IsolatedTracksPT10IsoCut12Eta[ii],IsolatedTracksPT10IsoCut12Phi[ii])<maxDeltaRGenMuToTack_ && std::abs(GenMuPt[i]-IsolatedTracksPT10IsoCut12Pt[ii])/GenMuPt[i] <maxDiffPtGenMuToTack_)
	{
		GenMuonIsolatedTracksPT10IsoCut12Matched[i]=1;
	  IsolatedTracksPT10IsoCut12MatchedToGenLepton[ii]=1;
	  IsolatedTracksPT10IsoCut12MatchedToGenDeltaR[ii]=deltaR(GenMuEta[i],GenMuPhi[i],IsolatedTracksPT10IsoCut12Eta[ii],IsolatedTracksPT10IsoCut12Phi[ii]);
	  IsolatedTracksPT10IsoCut12MatchedToGenRelPT[ii]=GenMuPt[i]-IsolatedTracksPT10IsoCut12Pt[ii]/GenMuPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<GenElecNum;i++)
  {
    if(GenElecPt[i] <minElecPt_ || std::abs(GenElecEta[i]) > maxElecEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10IsoCut12Num;ii++)
    {
      if(IsolatedTracksPT10IsoCut12MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenElecEta[i],GenElecPhi[i],IsolatedTracksPT10IsoCut12Eta[ii],IsolatedTracksPT10IsoCut12Phi[ii])<maxDeltaRGenElecToTack_ && std::abs(GenElecPt[i]-IsolatedTracksPT10IsoCut12Pt[ii])/GenElecPt[i] <maxDiffPtGenElecToTack_)
	{
		GenElecIsolatedTracksPT10IsoCut12Matched[i]=1;
	  IsolatedTracksPT10IsoCut12MatchedToGenLepton[ii]=2;
	  IsolatedTracksPT10IsoCut12MatchedToGenDeltaR[ii]=deltaR(GenElecEta[i],GenElecPhi[i],IsolatedTracksPT10IsoCut12Eta[ii],IsolatedTracksPT10IsoCut12Phi[ii]);
	  IsolatedTracksPT10IsoCut12MatchedToGenRelPT[ii]=GenElecPt[i]-IsolatedTracksPT10IsoCut12Pt[ii]/GenElecPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<GenTauNum;i++)
  {
    if(GenTauPt[i] <minTauPt_ || std::abs(GenTauEta[i]) > maxTauEta_) continue;
    for(unsigned int ii=0; ii< IsolatedTracksPT10IsoCut12Num;ii++)
    {
      if(IsolatedTracksPT10IsoCut12MatchedToGenLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(GenTauEta[i],GenTauPhi[i],IsolatedTracksPT10IsoCut12Eta[ii],IsolatedTracksPT10IsoCut12Phi[ii])<maxDeltaRGenTauToTack_ && std::abs(GenTauPt[i]-IsolatedTracksPT10IsoCut12Pt[ii])/GenTauPt[i] <maxDiffPtGenTauToTack_)
	{
		GenTauIsolatedTracksPT10IsoCut12Matched[i]=1;
	  IsolatedTracksPT10IsoCut12MatchedToGenLepton[ii]=3;
	  IsolatedTracksPT10IsoCut12MatchedToGenDeltaR[ii]=deltaR(GenTauEta[i],GenTauPhi[i],IsolatedTracksPT10IsoCut12Eta[ii],IsolatedTracksPT10IsoCut12Phi[ii]);
	  IsolatedTracksPT10IsoCut12MatchedToGenRelPT[ii]=GenTauPt[i]-IsolatedTracksPT10IsoCut12Pt[ii]/GenTauPt[i];
	}
      }
    }
  }
  // save if fals veto is true
  temp =0;
	for(unsigned int i=0; i< IsolatedTracksPT10IsoCut12Num;i++)
	{
		if(IsolatedTracksPT10IsoCut12MatchedToGenLepton[i]==0)temp++;
		
	}
	if(temp!=0)FallsVetoIsoTrackPT10IsoCut12=1;
  
  //
  
  
  
  for (unsigned  i=0; i<RecoIsoMuonNum;i++)
  {
    if(RecoIsoMuonPt[i] <minMuPt_ || std::abs(RecoIsoMuonEta[i]) > maxMuEta_) continue;
    for(unsigned int ii=0; ii< SelectedIsoTracksNum;ii++)
    {
      if(SelectedIsoTracksMatchedToRecoIsoLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(RecoIsoMuonEta[i],RecoIsoMuonPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii])<maxDeltaRRecoIsoMuToTack_ && std::abs(RecoIsoMuonPt[i]-SelectedIsoTracksPt[ii])/RecoIsoMuonPt[i] <maxDiffPtRecoIsoMuToTack_)
	{
	  RecoIsoMuonIsoTrackMatched[ii]=1;
	  SelectedIsoTracksMatchedToRecoIsoLepton[ii]=2;
	  SelectedIsoTracksMatchedToRecoIsoDeltaR[ii]=deltaR(RecoIsoMuonEta[i],RecoIsoMuonPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii]);
	  SelectedIsoTracksMatchedToRecoIsoRelPT[ii]=RecoIsoMuonPt[i]-SelectedIsoTracksPt[ii]/GenMuPt[i];
	}
      }
    }
  }
  for (unsigned  i=0; i<RecoIsoElecNum;i++)
  {
    if(RecoIsoElecPt[i] <minElecPt_ || std::abs(RecoIsoElecEta[i]) > maxElecEta_) continue;
    for(unsigned int ii=0; ii< SelectedIsoTracksNum;ii++)
    {
      if(SelectedIsoTracksMatchedToRecoIsoLepton[ii]==0) // only look at not yet matched tracks
      {
	if(deltaR(RecoIsoElecEta[i],RecoIsoElecPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii])<maxDeltaRRecoIsoElecToTack_ && std::abs(RecoIsoElecPt[i]-SelectedIsoTracksPt[ii])/RecoIsoElecPt[i] <maxDiffPtRecoIsoElecToTack_)
	{
	  RecoIsoElecIsoTrackMatched[ii]=1;
	  SelectedIsoTracksMatchedToRecoIsoLepton[ii]=1;
	  SelectedIsoTracksMatchedToRecoIsoDeltaR[ii]=deltaR(RecoIsoElecEta[i],RecoIsoElecPhi[i],SelectedIsoTracksEta[ii],SelectedIsoTracksPhi[ii]);
	  SelectedIsoTracksMatchedToRecoIsoRelPT[ii]=RecoIsoElecPt[i]-SelectedIsoTracksPt[ii]/GenElecPt[i];
	}
      }
    }
  }
/*  if(GenMuNum==2)// di muon event
  {
	  if(RecoIsoMuonNum>0)
	  {
		  MuDiLepEffNJets->Fill(NJets,WeightProducer);
	  }
	  else MuDiLepEffNJetsFail->Fill(NJets,WeightProducer);
  }
  if(GenElecNum==2)// di elec event
  {
	  if(RecoIsoElecNum>0)
	  {
		  ElecDiLepEffNJets->Fill(NJets,WeightProducer);
	  }
	  else ElecDiLepEffNJetsFail->Fill(NJets,WeightProducer);
  }
  if(GenMuNum==1 && GenElecNum==1) // di lepton with one elec one muon
  {
	  if(RecoIsoMuonNum>0)
	  {
		  MuDiLepEffNJets->Fill(NJets,WeightProducer);
	  }
	  
	  if(RecoIsoElecNum>0)
	  {
		  ElecDiLepEffNJets->Fill(NJets,WeightProducer);
	  }
	  if(RecoIsoElecNum==0 && RecoIsoMuonNum==0)
	  {
		  MuDiLepEffNJetsFail->Fill(NJets,WeightProducer);
		  ElecDiLepEffNJetsFail->Fill(NJets,WeightProducer);
	  }
  }
  */
  if((GenMuNum+GenElecNum)==2)
  {
	  if(RecoIsoElecNum==0 && RecoIsoMuonNum==1) MuDiLepEffNJets->Fill(NJets,WeightProducer);
	  if(RecoIsoElecNum==0 && RecoIsoMuonNum==0) MuDiLepEffNJetsFail->Fill(NJets,WeightProducer);
  }
  
  if( (GenMuNum+GenElecNum)==2)
  {
    if(RecoIsoMuonNum==0 && RecoIsoElecNum==0)
    {
	    Expectation=1;
    }
    if(RecoIsoMuonNum==1 && RecoIsoElecNum==0)
    {
	    MuDiLepControlSampleMHTNJetFail->Fill(MHT,NJets,WeightProducer);
	    mtw =  MTWCalculator(METPt,METPhi, RecoIsoMuonPt[0], RecoIsoMuonPhi[0]);
	    if(mtw<mtwCut_)MuDiLepControlSampleMHTNJetMTWFail->Fill(MHT,NJets,WeightProducer);
    }
    if(RecoIsoMuonNum==0 && RecoIsoElecNum==1)
    {
	    ElecDiLepControlSampleMHTNJetFail->Fill(MHT,NJets,WeightProducer);  
	    mtw =  MTWCalculator(METPt,METPhi, RecoIsoElecPt[0], RecoIsoElecPhi[0]);
	    if(mtw<mtwCut_)ElecDiLepControlSampleMHTNJetMTWFail->Fill(MHT,NJets,WeightProducer);
    }
  }
  // start with gen muons consider only single muon events
  if(GenMuNum==1 && GenElecNum==0)
  {
    if ( GenMuPt[0] < minMuPt_ || std::abs(GenMuEta[0]) > maxMuEta_)
    {
      MuonAccBTagFail->Fill(MHT,BTags,WeightProducer);
      MuonAccFail->Fill(MHT,NJets,WeightProducer);
      muAcc=0;
      Expectation=1;
    }
    else
    {
      MuonAccBTag->Fill(MHT,BTags,WeightProducer);
      MuonAcc->Fill(MHT,NJets,WeightProducer);
      muAcc=2;
      bool RecoNotMatched=true;
      for (UShort_t i=0; i<RecoMuonNum; i++)
      {
	//std::cout<<"RecoMuonNum["<<i<<"] started"<<std::endl;
	if(deltaR(GenMuEta[0],GenMuPhi[0],RecoMuonEta[i],RecoMuonPhi[i])<maxDeltaRGenToRecoMu_ && std::abs(GenMuPt[0]-RecoMuonPt[i])/GenMuPt[0] <maxDiffPtGenToRecoMu_)
	{
	  // std::cout<<"RecoMuonNum["<<i<<"] started"<<std::endl;
	  RecoNotMatched=false;
	  if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonRecoLow->Fill(HT,MHT,WeightProducer);
	  if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonReco0->Fill(HT,MHT,WeightProducer);
	  if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonReco1->Fill(HT,MHT,WeightProducer);
	  if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonReco2->Fill(HT,MHT,WeightProducer);
	  if( BTags <1) MuonRecoBTag0->Fill(HT,MHT,WeightProducer);
	  if( BTags <2) MuonRecoBTag1->Fill(HT,MHT,WeightProducer);
	  if( BTags >1) MuonRecoBTag2ToInf->Fill(HT,MHT,WeightProducer);
	  muReco =2;
	  bool IsoNotMatched=true;
	  for (UShort_t ii=0; ii < RecoIsoMuonNum; ii++)
	  {
	    if(deltaR(RecoIsoMuonEta[ii],RecoIsoMuonPhi[ii],RecoMuonEta[i],RecoMuonPhi[i])<maxDeltaRRecoToIsoMu_ && std::abs(RecoIsoMuonPt[ii]-RecoMuonPt[i])/RecoIsoMuonPt[ii] <maxDiffPtRecoToIsoMu_)
	    {
	      IsoNotMatched=false;
	      if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonIsoLow->Fill(HT,MHT,WeightProducer);
	      if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonIso0->Fill(HT,MHT,WeightProducer);
	      if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonIso1->Fill(HT,MHT,WeightProducer);
	      if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonIso2->Fill(HT,MHT,WeightProducer);
	      if( BTags <1) MuonIsoBTag0->Fill(HT,MHT,WeightProducer);
	      if( BTags <2) MuonIsoBTag1->Fill(HT,MHT,WeightProducer);
	      if( BTags >1) MuonIsoBTag2ToInf->Fill(HT,MHT,WeightProducer);
	      muIso=2;
	      Expectation=2;
	      MuDiLepControlSampleMHTNJet->Fill(MHT,NJets,WeightProducer);
	      mtw =  MTWCalculator(METPt,METPhi, RecoIsoMuonPt[ii], RecoIsoMuonPhi[ii]);
	      if (mtw<mtwCut_)
	      {
		MuMTWMHTBTag->Fill(BTags,MHT,WeightProducer);
		MuMTWNJet->Fill(NJets,WeightProducer);
		MuMTWMHTNJet->Fill(MHT,NJets,WeightProducer);
		MuDiLepControlSampleMHTNJetMTW->Fill(MHT,NJets,WeightProducer);
	      }
	      else
	      {
		MuMTWMHTBTagFail->Fill(BTags,MHT,WeightProducer);
		MuMTWNJetFail->Fill(NJets,WeightProducer);
		MuMTWMHTNJetFail->Fill(MHT,NJets,WeightProducer);
	      }
	    }
	  }
	  if(IsoNotMatched)
	  {
	    if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonIsoLowFail->Fill(HT,MHT,WeightProducer);
	    if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonIso0Fail->Fill(HT,MHT,WeightProducer);
	    if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonIso1Fail->Fill(HT,MHT,WeightProducer);
	    if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonIso2Fail->Fill(HT,MHT,WeightProducer);
	    if( BTags <1) MuonIsoBTag0Fail->Fill(HT,MHT,WeightProducer);
	    if( BTags <2) MuonIsoBTag1Fail->Fill(HT,MHT,WeightProducer);
	    if( BTags >1) MuonIsoBTag2ToInfFail->Fill(HT,MHT,WeightProducer);
	    muIso=0;
	    Expectation=1;
	  }
	}
      }
      if(RecoNotMatched)
      {
	if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonRecoLowFail->Fill(HT,MHT,WeightProducer);
	if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonReco0Fail->Fill(HT,MHT,WeightProducer);
	if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonReco1Fail->Fill(HT,MHT,WeightProducer);
	if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonReco2Fail->Fill(HT,MHT,WeightProducer);
	if( BTags <1) MuonRecoBTag0Fail->Fill(HT,MHT,WeightProducer);
	if( BTags <2) MuonRecoBTag1Fail->Fill(HT,MHT,WeightProducer);
	if( BTags >1) MuonRecoBTag2ToInfFail->Fill(HT,MHT,WeightProducer);
	muReco=0;
	Expectation=1;
      }
    }
  } 
  // analyse gen electrons consider only single elec events
  if(GenMuNum==0 && GenElecNum==1)
  {
    if ( GenElecPt[0] < minElecPt_ || std::abs(GenElecEta[0]) > maxElecEta_)
    {
      ElecAccBTagFail->Fill(MHT,BTags,WeightProducer);
      ElecAccFail->Fill(MHT,NJets,WeightProducer);
      elecAcc=0;
      Expectation=1;
    }
    else
    {
      ElecAccBTag->Fill(MHT,BTags,WeightProducer);
      ElecAcc->Fill(MHT,NJets,WeightProducer);
      elecAcc=2;
      bool RecoNotMatched=true;
      for (UShort_t i=0; i<RecoElecNum; i++)
      {
	//std::cout<<"RecoElecNum["<<i<<"] started"<<std::endl;
	if(deltaR(GenElecEta[0],GenElecPhi[0],RecoElecEta[i],RecoElecPhi[i])<maxDeltaRGenToRecoElec_ && std::abs(GenElecPt[0]-RecoElecPt[i])/GenElecPt[0] <maxDiffPtGenToRecoElec_)
	{
	  // std::cout<<"RecoElecNum["<<i<<"] started"<<std::endl;
	  RecoNotMatched=false;
	  if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecRecoLow->Fill(HT,MHT,WeightProducer);
	  if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecReco0->Fill(HT,MHT,WeightProducer);
	  if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecReco1->Fill(HT,MHT,WeightProducer);
	  if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecReco2->Fill(HT,MHT,WeightProducer);
	  if( BTags <1) ElecRecoBTag0->Fill(HT,MHT,WeightProducer);
	  if( BTags <2) ElecRecoBTag1->Fill(HT,MHT,WeightProducer);
	  if( BTags >1) ElecRecoBTag2ToInf->Fill(HT,MHT,WeightProducer);
	  elecReco =2;
	  bool IsoNotMatched=true;
	  for (UShort_t ii=0; ii < RecoIsoElecNum; ii++)
	  {
	    if(deltaR(RecoIsoElecEta[ii],RecoIsoElecPhi[ii],RecoElecEta[i],RecoElecPhi[i])<maxDeltaRRecoToIsoElec_ && std::abs(RecoIsoElecPt[ii]-RecoElecPt[i])/RecoIsoElecPt[ii] <maxDiffPtRecoToIsoElec_)
	    {
	      IsoNotMatched=false;
	      if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecIsoLow->Fill(HT,MHT,WeightProducer);
	      if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecIso0->Fill(HT,MHT,WeightProducer);
	      if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecIso1->Fill(HT,MHT,WeightProducer);
	      if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecIso2->Fill(HT,MHT,WeightProducer);
	      if( BTags <1) ElecIsoBTag0->Fill(HT,MHT,WeightProducer);
	      if( BTags <2) ElecIsoBTag1->Fill(HT,MHT,WeightProducer);
	      if( BTags >1) ElecIsoBTag2ToInf->Fill(HT,MHT,WeightProducer);
	      elecIso=2;
	      Expectation=2;
	      ElecDiLepControlSampleMHTNJet->Fill(MHT,NJets,WeightProducer);
	      mtw =  MTWCalculator(METPt,METPhi, RecoIsoElecPt[ii], RecoIsoElecPhi[ii]);
	      if (mtw<mtwCut_)
	      {
		ElecMTWMHTBTag->Fill(BTags,MHT,WeightProducer);
		ElecMTWNJet->Fill(NJets,WeightProducer);
		ElecMTWMHTNJet->Fill(MHT,NJets,WeightProducer);
		ElecDiLepControlSampleMHTNJetMTW->Fill(MHT,NJets,WeightProducer);
	      }
	      else
	      {
		ElecMTWMHTBTagFail->Fill(BTags,MHT,WeightProducer);
		ElecMTWNJetFail->Fill(NJets,WeightProducer);
		ElecMTWMHTNJetFail->Fill(MHT,NJets,WeightProducer);
	      }
	    }
	  }
	  if(IsoNotMatched)
	  {
	    if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecIsoLowFail->Fill(HT,MHT,WeightProducer);
	    if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecIso0Fail->Fill(HT,MHT,WeightProducer);
	    if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecIso1Fail->Fill(HT,MHT,WeightProducer);
	    if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecIso2Fail->Fill(HT,MHT,WeightProducer);
	    if( BTags <1) ElecIsoBTag0Fail->Fill(HT,MHT,WeightProducer);
	    if( BTags <2) ElecIsoBTag1Fail->Fill(HT,MHT,WeightProducer);
	    if( BTags >1) ElecIsoBTag2ToInfFail->Fill(HT,MHT,WeightProducer);
	    elecIso=0;
	    Expectation=1;
	  }
	}
      }
      if(RecoNotMatched)
      {
	if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecRecoLowFail->Fill(HT,MHT,WeightProducer);
	if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecReco0Fail->Fill(HT,MHT,WeightProducer);
	if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecReco1Fail->Fill(HT,MHT,WeightProducer);
	if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecReco2Fail->Fill(HT,MHT,WeightProducer);
	if( BTags <1) ElecRecoBTag0Fail->Fill(HT,MHT,WeightProducer);
	if( BTags <2) ElecRecoBTag1Fail->Fill(HT,MHT,WeightProducer);
	if( BTags >1) ElecRecoBTag2ToInfFail->Fill(HT,MHT,WeightProducer);
	elecReco=0;
	Expectation=1;
      }
    }
  } 
  // purity studies:
  for (UShort_t i=0; i< RecoIsoMuonNum;i++)
  {
	  if(RecoIsoMuonNum>1 || MTWCalculator(METPt,METPhi, RecoIsoMuonPt[0], RecoIsoMuonPhi[0])>mtwCut_) break;
    bool matched=false;
    for(UShort_t ii=0; ii<GenMuNum;ii++)
    {
      if(deltaR(RecoIsoMuonEta[i],RecoIsoMuonPhi[i],GenMuEta[ii],GenMuPhi[ii])<RecoIsoMuonPromtMatchedDeltaR[i])RecoIsoMuonPromtMatchedDeltaR[i]=deltaR(RecoIsoMuonEta[i],RecoIsoMuonPhi[i],GenMuEta[ii],GenMuPhi[ii]);
      if(std::abs(RecoIsoMuonPt[i]-GenMuPt[ii])/RecoIsoMuonPt[i] < std::abs(RecoIsoMuonPromtMatchedRelPt[i]) )RecoIsoMuonPromtMatchedRelPt[i]=(RecoIsoMuonPt[i]-GenMuPt[ii])/RecoIsoMuonPt[i];
      if(deltaR(RecoIsoMuonEta[i],RecoIsoMuonPhi[i],GenMuEta[ii],GenMuPhi[ii])<maxDeltaRIsoToGenMu_ && std::abs(RecoIsoMuonPt[i]-GenMuPt[ii])/RecoIsoMuonPt[i] <maxDiffPtIsoToGenMu_)
      {
	MuonPurityMHTNJet->Fill(MHT,NJets,WeightProducer);
	RecoIsoMuonPromtMatched[i]=1;
	matched=true;
      }
    }
    if(!matched)
    {
      RecoIsoMuonPromtMatched[i]=0;
      MuonPurityMHTNJetFail->Fill(MHT,NJets,WeightProducer);
    }
    if(GenMuNum==0)
    {
      RecoIsoMuonPromtMatchedDeltaR[i]=-1;
      RecoIsoMuonPromtMatchedRelPt[i]=-100;
    }
  }
  for (UShort_t i=0; i< RecoIsoElecNum;i++)
  {
	  if(RecoIsoElecNum>1 || MTWCalculator(METPt,METPhi, RecoIsoElecPt[0], RecoIsoElecPhi[0])>mtwCut_) break;
    bool matched=false;
    for(UShort_t ii=0; ii<GenElecNum;ii++)
    {
      if(deltaR(RecoIsoElecEta[i],RecoIsoElecPhi[i],GenElecEta[ii],GenElecPhi[ii])<RecoIsoElecPromtMatchedDeltaR[i])RecoIsoElecPromtMatchedDeltaR[i]=deltaR(RecoIsoElecEta[i],RecoIsoElecPhi[i],GenElecEta[ii],GenElecPhi[ii]);
      if(std::abs(RecoIsoElecPt[i]-GenElecPt[ii])/RecoIsoElecPt[i] < std::abs(RecoIsoElecPromtMatchedRelPt[i]) )RecoIsoElecPromtMatchedRelPt[i]=(RecoIsoElecPt[i]-GenElecPt[ii])/RecoIsoElecPt[i];
      if(deltaR(RecoIsoElecEta[i],RecoIsoElecPhi[i],GenElecEta[ii],GenElecPhi[ii])<maxDeltaRIsoToGenElec_ && std::abs(RecoIsoElecPt[i]-GenElecPt[ii])/RecoIsoElecPt[i] <maxDiffPtIsoToGenElec_)
      {
	RecoIsoElecPromtMatched[i]=1;
	matched=true;
	ElecPurityMHTNJet->Fill(MHT,NJets,WeightProducer);
      }
    }
    if(!matched)
    {
      RecoIsoElecPromtMatched[i]=0;
      ElecPurityMHTNJetFail->Fill(MHT,NJets,WeightProducer);
    }
    if(GenElecNum==0)
    {
      RecoIsoElecPromtMatchedDeltaR[i]=-1;
      RecoIsoElecPromtMatchedRelPt[i]=-100;
    }
  }
  // check if falls lepton veto will be applied
  temp=0;
  for(unsigned int i=0; i< RecoIsoElecNum;i++)
	{
		if(RecoIsoElecPromtMatched[i]==0)temp=1;
	}
	for(unsigned int i=0; i< RecoIsoMuonNum;i++)
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
  TFile *outPutFile = new TFile("Expectation.root","RECREATE"); ;
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
