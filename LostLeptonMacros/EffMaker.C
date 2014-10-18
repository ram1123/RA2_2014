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

#include <TStyle.h>


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
   
   MC_TAP_mu_iso_eff=NULL;
   Data_TAP_mu_iso_eff=NULL;
   MC_TAP_mu_reco_eff=NULL;
   Data_TAP_mu_reco_eff=NULL;
   MC_TAP_elec_iso_eff=NULL;
   Data_TAP_elec_iso_eff=NULL;
   MC_TAP_elec_reco_eff=NULL;
   Data_TAP_elec_reco_eff=NULL;
   tExpectation_=NULL;
   

}

void EffMaker::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
 //  std::cout<<"SlaveStarted"<<std::endl;

   
   
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
   
   // initialize the tree and the Histograms
   tExpectation_ = new TTree("LostLeptonExpectation","a simple Tree with simple variables");
   tExpectation_->Branch("HT",&HT,"HT/F");
   tExpectation_->Branch("MHT",&MHT,"MHT/F");
   tExpectation_->Branch("NJets",&NJets,"NJets/s");
   tExpectation_->Branch("BTags",&BTags,"BTags/s");
   tExpectation_->Branch("NVtx",&NVtx,"NVtx/s");
   tExpectation_->Branch("DeltaPhi1",&DeltaPhi1,"DeltaPhi1/F");
   tExpectation_->Branch("DeltaPhi2",&DeltaPhi2,"DeltaPhi2/F");
   tExpectation_->Branch("DeltaPhi3",&DeltaPhi3,"DeltaPhi3/F");
   tExpectation_->Branch("WeightProducer", &WeightProducer, "WeightProducer/F");
   tExpectation_->Branch("GenMuNum",&GenMuNum,"GenMuNum/s");
   tExpectation_->Branch("GenMuFromTau",GenMuFromTau,"GenMuFromTau[GenMuNum]/s");
   tExpectation_->Branch("GenMuPt", GenMuPt,"GenMuPt[GenMuNum]/F");
   tExpectation_->Branch("GenMuEta", GenMuEta,"GenMuEta[GenMuNum]/F");
   tExpectation_->Branch("GenMuPhi", GenMuPhi,"GenMuPhi[GenMuNum]/F");
   tExpectation_->Branch("GenElecNum",&GenElecNum,"GenElecNum/s");
   tExpectation_->Branch("GenElecFromTau",GenElecFromTau,"GenElecFromTau[GenElecNum]/s");
   tExpectation_->Branch("GenElecPt", GenElecPt,"GenElecPt[GenElecNum]/F");
   tExpectation_->Branch("GenElecEta", GenElecEta,"GenElecEta[GenElecNum]/F");
   tExpectation_->Branch("GenElecPhi", GenElecPhi,"GenElecPhi[GenElecNum]/F");
   tExpectation_->Branch("GenTauNum",&GenTauNum,"GenTauNum/s");
   tExpectation_->Branch("GenTauPt", GenTauPt,"GenTauPt[GenTauNum]/F");
   tExpectation_->Branch("GenTauEta", GenTauEta,"GenTauEta[GenTauNum]/F");
   tExpectation_->Branch("GenTauPhi", GenTauPhi,"GenTauPhi[GenTauNum]/F");
   tExpectation_->Branch("Expectation",&Expectation,"Expectation/s");  
   tExpectation_->Branch("muAcc",&muAcc,"muAcc/s");  
   tExpectation_->Branch("muReco",&muReco,"muReco/s");  
   tExpectation_->Branch("muIso",&muIso,"muIso/s");  
   tExpectation_->Branch("MTW",&mtw,"MTW/F");  
   tExpectation_->Branch("elecAcc",&elecAcc,"elecAcc/s");  
   tExpectation_->Branch("elecReco",&elecReco,"elecReco/s");  
   tExpectation_->Branch("elecIso",&elecIso,"elecIso/s");  
   tExpectation_->Branch("RecoIsoMuonNum",&RecoIsoMuonNum,"RecoIsoMuonNum/s");
   tExpectation_->Branch("RecoIsoMuonPt", RecoIsoMuonPt, "RecoIsoMuonPt[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonPromtMatched", RecoIsoMuonPromtMatched, "RecoIsoMuonPromtMatched[RecoIsoMuonNum]/s");
//   tExpectation_->Branch("RecoIsoMuonPromtMatchedDeltaR", RecoIsoMuonPromtMatchedDeltaR, "RecoIsoMuonPromtMatchedDeltaR[RecoIsoMuonNum]/F");
//   tExpectation_->Branch("RecoIsoMuonPromtMatchedRelPt", RecoIsoMuonPromtMatchedRelPt, "RecoIsoMuonPromtMatchedRelPt[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonEta", RecoIsoMuonEta, "RecoIsoMuonEta[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonPhi", RecoIsoMuonPhi, "RecoIsoMuonPhi[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoMuonE", RecoIsoMuonE, "RecoIsoMuonE[RecoIsoMuonNum]/F");
   tExpectation_->Branch("RecoIsoElecNum",&RecoIsoElecNum,"RecoIsoElecNum/s");
   tExpectation_->Branch("RecoIsoElecPt", RecoIsoElecPt, "RecoIsoElecPt[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecPromtMatched", RecoIsoElecPromtMatched, "RecoIsoElecPromtMatched[RecoIsoElecNum]/s");
   tExpectation_->Branch("RecoIsoElecPromtMatchedDeltaR", RecoIsoElecPromtMatchedDeltaR, "RecoIsoElecPromtMatchedDeltaR[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecPromtMatchedRelPt", RecoIsoElecPromtMatchedRelPt, "RecoIsoElecPromtMatchedRelPt[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecEta", RecoIsoElecEta, "RecoIsoElecEta[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecPhi", RecoIsoElecPhi, "RecoIsoElecPhi[RecoIsoElecNum]/F");
   tExpectation_->Branch("RecoIsoElecE", RecoIsoElecE, "RecoIsoElecE[RecoIsoElecNum]/F");
   GetOutputList()->Add(tExpectation_);


}

Bool_t EffMaker::Process(Long64_t entry)
{
  resetValues();
  fChain->GetTree()->GetEntry(entry);
  if(HT<minHT_ || MHT< minMHT_ || NJets < minNJets_ ||  DeltaPhi1 < deltaPhi1_ || DeltaPhi2 < deltaPhi2_ || DeltaPhi3 < deltaPhi3_) return kTRUE;
  if(applyFilters_ &&  !FiltersPass() ) return kTRUE;
  // check if it is a diplepton event
  
  if( (GenMuNum+GenElecNum)==2)
  {
    
  }
  // start with gen muons consider only single muon events
  if(GenMuNum==1 && GenElecNum==0)
  {
    if ( GenMuPt[0] < minMuPt_ || std::abs(GenMuEta[0]) > maxMuEta_)
    {
      MuonAccFail->Fill(MHT,NJets,WeightProducer);
      muAcc=0;
      Expectation=1;
    }
    else
    {
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
	      muIso=2;
	      Expectation=2;
	      mtw =  MTWCalculator(METPt,METPhi, RecoIsoMuonPt[ii], RecoIsoMuonPhi[ii]);
	      if (mtw<mtwCut_)
	      {
		MuMTWNJet->Fill(NJets,WeightProducer);
		MuMTWMHTNJet->Fill(MHT,NJets,WeightProducer);
	      }
	      else
	      {
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
      ElecAccFail->Fill(MHT,NJets,WeightProducer);
      elecAcc=0;
      Expectation=1;
    }
    else
    {
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
	      elecIso=2;
	      Expectation=2;
	      mtw =  MTWCalculator(METPt,METPhi, RecoIsoElecPt[ii], RecoIsoElecPhi[ii]);
	      if (mtw<mtwCut_)
	      {
		ElecMTWNJet->Fill(NJets,WeightProducer);
		ElecMTWMHTNJet->Fill(MHT,NJets,WeightProducer);
	      }
	      else
	      {
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
	elecReco=0;
	Expectation=1;
      }
    }
  }
  // purity studies:
  for (UShort_t i=0; i< RecoIsoMuonNum;i++)
  {
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
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  gStyle->SetPaintTextFormat("5.2f");
  gStyle->SetStatW(0.1);
  gStyle->SetStatH(0.1);
  gStyle->SetStatY(202);
  gStyle->SetTitleYOffset(1.3);	
   std::cout<<"EffMaker::Terminate started"<<std::endl;
   outPutFile_->cd();
   tExpectation_->Write();
   outPutFile_->mkdir("Efficiencies");
 
   TDirectory *dEfficiencies = (TDirectory*)outPutFile_->Get("Efficiencies");
   dEfficiencies->cd();   std::cout<<"1"<<std::endl;
   
   MuonAcc = ratioCalculator(MuonAcc,MuonAccFail);   
  // MuonAccFail->Delete("all");
   MuonAcc->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu acceptance; #slash{H}_{T} [GeV]; N_{Jets}");
   MuonAcc->SetMarkerSize(2.0);
   MuonAcc->UseCurrentStyle();
   MuonAcc->Write();
   
   MuonRecoLow = ratioCalculator(MuonRecoLow,MuonRecoLowFail);   
   //MuonRecoLowFail->Delete("all");
   MuonRecoLow->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu reco N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonRecoLow->SetMarkerSize(2.0);
   MuonRecoLow->UseCurrentStyle();
   MuonRecoLow->Write();
   MuonReco0 = ratioCalculator(MuonReco0,MuonReco0Fail);   
  // MuonReco0Fail->Delete("all");
   MuonReco0->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu reco 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonReco0->SetMarkerSize(2.0);
   MuonReco0->UseCurrentStyle();
   MuonReco0->Write();
   MuonReco1 = ratioCalculator(MuonReco1,MuonReco1Fail);   
   //MuonReco1Fail->Delete("all");
   MuonReco1->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu reco 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonReco1->SetMarkerSize(2.0);
   MuonReco1->UseCurrentStyle();
   MuonReco1->Write();
   MuonReco2 = ratioCalculator(MuonReco2,MuonReco2Fail);   
  // MuonReco2Fail->Delete("all");
   MuonReco2->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu reco 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonReco2->SetMarkerSize(2.0);
   MuonReco2->UseCurrentStyle();
   MuonReco2->Write();
   
   MuonIsoLow = ratioCalculator(MuonIsoLow,MuonIsoLowFail);   
 //  MuonIsoLowFail->Delete("all");
   MuonIsoLow->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu iso N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonIsoLow->SetMarkerSize(2.0);
   MuonIsoLow->UseCurrentStyle();
   MuonIsoLow->Write();
   MuonIso0 = ratioCalculator(MuonIso0,MuonIso0Fail);   
 //  MuonIso0Fail->Delete("all");
   MuonIso0->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu iso 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonIso0->SetMarkerSize(2.0);
   MuonIso0->UseCurrentStyle();
   MuonIso0->Write();
   MuonIso1 = ratioCalculator(MuonIso1,MuonIso1Fail);   
 //  MuonIso1Fail->Delete("all");
   MuonIso1->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu iso 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonIso1->SetMarkerSize(2.0);
   MuonIso1->UseCurrentStyle();
   MuonIso1->Write();
   MuonIso2 = ratioCalculator(MuonIso2,MuonIso2Fail);   
 //  MuonIso2Fail->Delete("all");
   MuonIso2->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu iso 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonIso2->SetMarkerSize(2.0);
   MuonIso2->UseCurrentStyle();
   MuonIso2->Write();
   
   MuMTWNJet = ratioCalculator(MuMTWNJet,MuMTWNJetFail);   
  // MuMTWNJetFail->Delete("all");
   MuMTWNJet->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu M_{T}(W); N_{Jets}");
   MuMTWNJet->UseCurrentStyle();
   MuMTWNJet->Write();
   
   MuMTWMHTNJet = ratioCalculator(MuMTWMHTNJet,MuMTWMHTNJetFail);   
  // MuMTWMHTNJetFail->Delete("all");
   MuMTWMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu M_{T}(W); #slash{H}_{T} [GeV]; N_{Jets}");
   MuMTWMHTNJet->SetMarkerSize(2.0);
   MuMTWMHTNJet->UseCurrentStyle();
   MuMTWMHTNJet->Write();
   
   MuonPurityMHTNJet = ratioCalculator(MuonPurityMHTNJet,MuonPurityMHTNJetFail);   
   // MuMTWMHTNJetFail->Delete("all");
   MuonPurityMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu purity; #slash{H}_{T} [GeV]; N_{Jets}");
   MuonPurityMHTNJet->SetMarkerSize(2.0);
   MuonPurityMHTNJet->UseCurrentStyle();
   MuonPurityMHTNJet->Write();
   
   
   ElecAcc = ratioCalculator(ElecAcc,ElecAccFail);   
 //  ElecAccFail->Delete("all");
   ElecAcc->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec acceptance; #slash{H}_{T} [GeV]; N_{Jets}");
   ElecAcc->Write();
   ElecRecoLow = ratioCalculator(ElecRecoLow,ElecRecoLowFail);   
 //  ElecRecoLowFail->Delete("all");
   ElecRecoLow->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec reco N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecRecoLow->Write();
   ElecReco0 = ratioCalculator(ElecReco0,ElecReco0Fail);   
//   ElecReco0Fail->Delete("all");
   ElecReco0->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec reco 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecReco0->Write();
   ElecReco1 = ratioCalculator(ElecReco1,ElecReco1Fail);   
  // ElecReco1Fail->Delete("all");
   ElecReco1->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec reco 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecReco1->Write();
   ElecReco2 = ratioCalculator(ElecReco2,ElecReco2Fail);   
 //  ElecReco2Fail->Delete("all");
   ElecReco2->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec reco 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecReco2->Write();
   
   ElecIsoLow = ratioCalculator(ElecIsoLow,ElecIsoLowFail);   
 //  ElecIsoLowFail->Delete("all");
   ElecIsoLow->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec iso N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecIsoLow->Write();
   ElecIso0 = ratioCalculator(ElecIso0,ElecIso0Fail);   
 //  ElecIso0Fail->Delete("all");
   ElecIso0->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec iso 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecIso0->Write();
   ElecIso1 = ratioCalculator(ElecIso1,ElecIso1Fail);   
//   ElecIso1Fail->Delete("all");
   ElecIso1->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec iso 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecIso1->Write();
   ElecIso2 = ratioCalculator(ElecIso2,ElecIso2Fail);   
 //  ElecIso2Fail->Delete("all");
   ElecIso2->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec iso 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecIso2->Write();
   
   ElecMTWNJet = ratioCalculator(ElecMTWNJet,ElecMTWNJetFail);   
 //  ElecMTWNJetFail->Delete("all");
   ElecMTWNJet->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec M_{T}(W); N_{Jets}");
   ElecMTWNJet->Write();
   
   ElecMTWMHTNJet = ratioCalculator(ElecMTWMHTNJet,ElecMTWMHTNJetFail);   
 //  ElecMTWMHTNJetFail->Delete("all");
   ElecMTWMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec M_{T}(W); #slash{H}_{T} [GeV]; N_{Jets}");
   ElecMTWMHTNJet->Write();
   
   ElecPurityMHTNJet = ratioCalculator(ElecPurityMHTNJet,ElecPurityMHTNJetFail);   
   // MuMTWMHTNJetFail->Delete("all");
   ElecPurityMHTNJet->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec purity; #slash{H}_{T} [GeV]; N_{Jets}");
   ElecPurityMHTNJet->SetMarkerSize(2.0);
   ElecPurityMHTNJet->UseCurrentStyle();
   ElecPurityMHTNJet->Write();
  // copyEff();
   
   std::cout<<"End of Effmaker"<<std::endl;

   std::cout<<"All objects have been deleted"<<std::endl;
   
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
  for(unsigned int i=0; i<10;i++)
  {
    RecoIsoMuonPromtMatched[i]=999;
    RecoIsoMuonPromtMatchedDeltaR[i]=999.;
    RecoIsoMuonPromtMatchedRelPt[i]=999.;
    RecoIsoElecPromtMatched[i]=999;
    RecoIsoElecPromtMatchedDeltaR[i]=999.;
    RecoIsoElecPromtMatchedRelPt[i]=999.;
  }
}
void EffMaker::copyEff()
{


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
