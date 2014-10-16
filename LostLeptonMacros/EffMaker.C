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


   

}

void EffMaker::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
 //  std::cout<<"SlaveStarted"<<std::endl;

   
   
   MuonIsoLow_ = new TH2F("MuonIsoNJet2Jet","MuonIsoNJet2Jet",muIsoHTLow_-1,MuIsoHTLow_,muIsoMHTLow_-1,MuIsoMHTLow_);
   GetOutputList()->Add(MuonIsoLow_);
   MuonIsoLowFail = (TH2F*)MuonIsoLow_->Clone();
   MuonIsoLowFail->SetName("MuonIsoLowFail");
   GetOutputList()->Add(MuonIsoLowFail);
   
   MuonIso0_ = new TH2F("MuonIsoNJetLow","MuonIsoNJetLow",muIsoHT0_-1,MuIsoHT0_,muIsoMHT0_-1,MuIsoMHT0_);
   GetOutputList()->Add(MuonIso0_);
   MuonIso0Fail = (TH2F*)MuonIso0_->Clone();
   MuonIso0Fail->SetName("MuonIso0Fail");
   GetOutputList()->Add(MuonIso0Fail);
   
   MuonIso1_ = new TH2F("MuonIsoNJetMedium","MuonIsoNJetMedium",muIsoHT1_-1,MuIsoHT1_,muIsoMHT1_-1,MuIsoMHT1_);
   GetOutputList()->Add(MuonIso1_);
   MuonIso1Fail = (TH2F*)MuonIso1_->Clone();
   MuonIso1Fail->SetName("MuonIso1Fail");
   GetOutputList()->Add(MuonIso1Fail);
   
   MuonIso2_ = new TH2F("MuonIsoNJetHgih","MuonIsoNJetHigh",muIsoHT2_-1,MuIsoHT2_,muIsoMHT2_-1,MuIsoMHT2_);
   GetOutputList()->Add(MuonIso2_);
   MuonIso2Fail = (TH2F*)MuonIso2_->Clone();
   MuonIso2Fail->SetName("MuonIso2Fail");
   GetOutputList()->Add(MuonIso2Fail);
   
   MuonRecoLow_ = new TH2F("MuonRecoNJet2Jet","MuonRecoNJet2Jet",muRecoHTLow_-1,MuRecoHTLow_,muRecoMHTLow_-1,MuRecoMHTLow_);
   GetOutputList()->Add(MuonRecoLow_);
   MuonRecoLowFail = (TH2F*)MuonRecoLow_->Clone();
   MuonRecoLowFail->SetName("MuonRecoLowFail");
   GetOutputList()->Add(MuonRecoLowFail);
   
   MuonReco0_ = new TH2F("MuonRecoNJetLow","MuonRecoNJetLow",muRecoHT0_-1,MuRecoHT0_,muRecoMHT0_-1,MuRecoMHT0_);
   GetOutputList()->Add(MuonReco0_);
   MuonReco0Fail = (TH2F*)MuonReco0_->Clone();
   MuonReco0Fail->SetName("MuonReco0Fail");
   GetOutputList()->Add(MuonReco0Fail);
   
   MuonReco1_ = new TH2F("MuonRecoNJetMedium","MuonRecoNJetMedium",muRecoHT1_-1,MuRecoHT1_,muRecoMHT1_-1,MuRecoMHT1_);
   GetOutputList()->Add(MuonReco1_);
   MuonReco1Fail = (TH2F*)MuonReco1_->Clone();
   MuonReco1Fail->SetName("MuonReco1Fail");
   GetOutputList()->Add(MuonReco1Fail);
   
   MuonReco2_ = new TH2F("MuonRecoNJetHgih","MuonRecoNJetHigh",muRecoHT2_-1,MuRecoHT2_,muRecoMHT2_-1,MuRecoMHT2_);
   GetOutputList()->Add(MuonReco2_);
   MuonReco2Fail = (TH2F*)MuonReco2_->Clone();
   MuonReco2Fail->SetName("MuonReco2Fail");
   GetOutputList()->Add(MuonReco2Fail);
   
   MuonAcc_ = new TH2F("MuonAcc","MuonAcc",muAccMht_-1,MuAccMht_,muAccNJets_-1,MuAccNJets_);
   GetOutputList()->Add(MuonAcc_);
   MuonAccFail = (TH2F*)MuonAcc_->Clone();
   MuonAccFail->SetName("MuonAccFail");
   GetOutputList()->Add(MuonAccFail);
   
   MuMTWNJet_ = new TH1F("MuMTW","MuMTW",mumtwNjet_-1,muMtwNjet_);
   GetOutputList()->Add(MuMTWNJet_);
   MuMTWNJetFail = (TH1F*)MuMTWNJet_->Clone();
   MuMTWNJetFail->SetName("MuMTWNJetFail");
   GetOutputList()->Add(MuMTWNJetFail);
   
   MuMTWMHTNJet_ = new TH2F("MuMTWMHTNjet","MuMTWMHTNjet",mumtwMHT_-1,muMtwMHT_,mumtwNjet_-1,muMtwNjet_);
   GetOutputList()->Add(MuMTWMHTNJet_);
   MuMTWMHTNJetFail = (TH2F*)MuMTWMHTNJet_->Clone();
   MuMTWMHTNJetFail->SetName("MuMTWMHTNJetFail");
   GetOutputList()->Add(MuMTWMHTNJetFail);
   
   
   ElecIsoLow_ = new TH2F("ElecIsoNJet2Jet","ElecIsoNJet2Jet",elecIsoHTLow_-1,ElecIsoHTLow_,elecIsoMHTLow_-1,ElecIsoMHTLow_);
   GetOutputList()->Add(ElecIsoLow_);
   ElecIsoLowFail = (TH2F*)ElecIsoLow_->Clone();
   ElecIsoLowFail->SetName("ElecIsoLowFail");
   GetOutputList()->Add(ElecIsoLowFail);
   
   ElecIso0_ = new TH2F("ElecIsoNJetLow","ElecIsoNJetLow",elecIsoHT0_-1,ElecIsoHT0_,elecIsoMHT0_-1,ElecIsoMHT0_);
   GetOutputList()->Add(ElecIso0_);
   ElecIso0Fail = (TH2F*)ElecIso0_->Clone();
   ElecIso0Fail->SetName("ElecIso0Fail");
   GetOutputList()->Add(ElecIso0Fail);
   
   ElecIso1_ = new TH2F("ElecIsoNJetMedium","ElecIsoNJetMedium",elecIsoHT1_-1,ElecIsoHT1_,elecIsoMHT1_-1,ElecIsoMHT1_);
   GetOutputList()->Add(ElecIso1_);
   ElecIso1Fail = (TH2F*)ElecIso1_->Clone();
   ElecIso1Fail->SetName("ElecIso1Fail");
   GetOutputList()->Add(ElecIso1Fail);
   
   ElecIso2_ = new TH2F("ElecIsoNJetHgih","ElecIsoNJetHigh",elecIsoHT2_-1,ElecIsoHT2_,elecIsoMHT2_-1,ElecIsoMHT2_);
   GetOutputList()->Add(ElecIso2_);
   ElecIso2Fail = (TH2F*)ElecIso2_->Clone();
   ElecIso2Fail->SetName("ElecIso2Fail");
   GetOutputList()->Add(ElecIso2Fail);
   
   ElecRecoLow_ = new TH2F("ElecRecoNJet2Jet","ElecRecoNJet2Jet",elecRecoHTLow_-1,ElecRecoHTLow_,elecRecoMHTLow_-1,ElecRecoMHTLow_);
   GetOutputList()->Add(ElecRecoLow_);
   ElecRecoLowFail = (TH2F*)ElecRecoLow_->Clone();
   ElecRecoLowFail->SetName("ElecRecoLowFail");
   GetOutputList()->Add(ElecRecoLowFail);
   
   ElecReco0_ = new TH2F("ElecRecoNJetLow","ElecRecoNJetLow",elecRecoHT0_-1,ElecRecoHT0_,elecRecoMHT0_-1,ElecRecoMHT0_);
   GetOutputList()->Add(ElecReco0_);
   ElecReco0Fail = (TH2F*)ElecReco0_->Clone();
   ElecReco0Fail->SetName("ElecReco0Fail");
   GetOutputList()->Add(ElecReco0Fail);
   
   ElecReco1_ = new TH2F("ElecRecoNJetMedium","ElecRecoNJetMedium",elecRecoHT1_-1,ElecRecoHT1_,elecRecoMHT1_-1,ElecRecoMHT1_);
   GetOutputList()->Add(ElecReco1_);
   ElecReco1Fail = (TH2F*)ElecReco1_->Clone();
   ElecReco1Fail->SetName("ElecReco1Fail");
   GetOutputList()->Add(ElecReco1Fail);
   
   ElecReco2_ = new TH2F("ElecRecoNJetHgih","ElecRecoNJetHigh",elecRecoHT2_-1,ElecRecoHT2_,elecRecoMHT2_-1,ElecRecoMHT2_);
   GetOutputList()->Add(ElecReco2_);
   ElecReco2Fail = (TH2F*)ElecReco2_->Clone();
   ElecReco2Fail->SetName("ElecReco2Fail");
   GetOutputList()->Add(ElecReco2Fail);
   
   ElecAcc_ = new TH2F("ElecAcc","ElecAcc",elecAccMht_-1,ElecAccMht_,elecAccNJets_-1,ElecAccNJets_);
   GetOutputList()->Add(ElecAcc_);
   ElecAccFail = (TH2F*)ElecAcc_->Clone();
   ElecAccFail->SetName("ElecAccFail");
   GetOutputList()->Add(ElecAccFail);
   
   ElecMTWNJet_ = new TH1F("ElecMTW","ElecMTW",elecmtwNjet_-1,elecMtwNjet_);
   GetOutputList()->Add(ElecMTWNJet_);
   ElecMTWNJetFail = (TH1F*)ElecMTWNJet_->Clone();
   ElecMTWNJetFail->SetName("ElecMTWNJetFail");
   GetOutputList()->Add(ElecMTWNJetFail);
   
   ElecMTWMHTNJet_ = new TH2F("ElecMTWMHTNjet","ElecMTWMHTNjet",elecmtwMHT_-1,elecMtwMHT_,elecmtwNjet_-1,elecMtwNjet_);
   GetOutputList()->Add(ElecMTWMHTNJet_);
   ElecMTWMHTNJetFail = (TH2F*)ElecMTWMHTNJet_->Clone();
   ElecMTWMHTNJetFail->SetName("ElecMTWMHTNJetFail");
   GetOutputList()->Add(ElecMTWMHTNJetFail);
   
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
      MuonAcc_->Fill(MHT,NJets,WeightProducer);
      muAcc=2;
      bool RecoNotMatched=true;
      for (UShort_t i=0; i<RecoMuonNum; i++)
      {
	//std::cout<<"RecoMuonNum["<<i<<"] started"<<std::endl;
	if(deltaR(GenMuEta[0],GenMuPhi[0],RecoMuonEta[i],RecoMuonPhi[i])<maxDeltaRGenToRecoMu_ && std::abs(GenMuPt[0]-RecoMuonPt[i])/GenMuPt[0] <maxDiffPtGenToRecoMu_)
	{
	 // std::cout<<"RecoMuonNum["<<i<<"] started"<<std::endl;
	  RecoNotMatched=false;
	  if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonRecoLow_->Fill(HT,MHT,WeightProducer);
	  if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonReco0_->Fill(HT,MHT,WeightProducer);
	  if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonReco1_->Fill(HT,MHT,WeightProducer);
	  if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonReco2_->Fill(HT,MHT,WeightProducer);
	  muReco =2;
	  bool IsoNotMatched=true;
	  for (UShort_t ii=0; ii < RecoIsoMuonNum; ii++)
	  {
	    if(deltaR(RecoIsoMuonEta[ii],RecoIsoMuonPhi[ii],RecoMuonEta[i],RecoMuonPhi[i])<maxDeltaRRecoToIsoMu_ && std::abs(RecoIsoMuonPt[ii]-RecoMuonPt[i])/RecoIsoMuonPt[ii] <maxDiffPtRecoToIsoMu_)
	    {
	      IsoNotMatched=false;
	      if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonIsoLow_->Fill(HT,MHT,WeightProducer);
	      if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonIso0_->Fill(HT,MHT,WeightProducer);
	      if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonIso1_->Fill(HT,MHT,WeightProducer);
	      if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonIso2_->Fill(HT,MHT,WeightProducer);
	      muIso=2;
	      Expectation=2;
	      mtw =  MTWCalculator(METPt,METPhi, RecoIsoMuonPt[ii], RecoIsoMuonPhi[ii]);
	      if (mtw<mtwCut_)
	      {
		MuMTWNJet_->Fill(NJets,WeightProducer);
		MuMTWMHTNJet_->Fill(MHT,NJets,WeightProducer);
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
      ElecAcc_->Fill(MHT,NJets,WeightProducer);
      elecAcc=2;
      bool RecoNotMatched=true;
      for (UShort_t i=0; i<RecoElecNum; i++)
      {
	//std::cout<<"RecoElecNum["<<i<<"] started"<<std::endl;
	if(deltaR(GenElecEta[0],GenElecPhi[0],RecoElecEta[i],RecoElecPhi[i])<maxDeltaRGenToRecoElec_ && std::abs(GenElecPt[0]-RecoElecPt[i])/GenElecPt[0] <maxDiffPtGenToRecoElec_)
	{
	  // std::cout<<"RecoElecNum["<<i<<"] started"<<std::endl;
	  RecoNotMatched=false;
	  if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecRecoLow_->Fill(HT,MHT,WeightProducer);
	  if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecReco0_->Fill(HT,MHT,WeightProducer);
	  if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecReco1_->Fill(HT,MHT,WeightProducer);
	  if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecReco2_->Fill(HT,MHT,WeightProducer);
	  elecReco =2;
	  bool IsoNotMatched=true;
	  for (UShort_t ii=0; ii < RecoIsoElecNum; ii++)
	  {
	    if(deltaR(RecoIsoElecEta[ii],RecoIsoElecPhi[ii],RecoElecEta[i],RecoElecPhi[i])<maxDeltaRRecoToIsoElec_ && std::abs(RecoIsoElecPt[ii]-RecoElecPt[i])/RecoIsoElecPt[ii] <maxDiffPtRecoToIsoElec_)
	    {
	      IsoNotMatched=false;
	      if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecIsoLow_->Fill(HT,MHT,WeightProducer);
	      if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecIso0_->Fill(HT,MHT,WeightProducer);
	      if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecIso1_->Fill(HT,MHT,WeightProducer);
	      if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecIso2_->Fill(HT,MHT,WeightProducer);
	      elecIso=2;
	      Expectation=2;
	      mtw =  MTWCalculator(METPt,METPhi, RecoIsoElecPt[ii], RecoIsoElecPhi[ii]);
	      if (mtw<mtwCut_)
	      {
		ElecMTWNJet_->Fill(NJets,WeightProducer);
		ElecMTWMHTNJet_->Fill(MHT,NJets,WeightProducer);
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
   
   MuonAcc_ = ratioCalculator(MuonAcc_,MuonAccFail);   
  // MuonAccFail->Delete("all");
   MuonAcc_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu acceptance; #slash{H}_{T} [GeV]; N_{Jets}");
   MuonAcc_->SetMarkerSize(2.0);
   MuonAcc_->UseCurrentStyle();
   MuonAcc_->Write();
   
   MuonRecoLow_ = ratioCalculator(MuonRecoLow_,MuonRecoLowFail);   
   //MuonRecoLowFail->Delete("all");
   MuonRecoLow_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu reco N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonRecoLow_->SetMarkerSize(2.0);
   MuonRecoLow_->UseCurrentStyle();
   MuonRecoLow_->Write();
   MuonReco0_ = ratioCalculator(MuonReco0_,MuonReco0Fail);   
  // MuonReco0Fail->Delete("all");
   MuonReco0_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu reco 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonReco0_->SetMarkerSize(2.0);
   MuonReco0_->UseCurrentStyle();
   MuonReco0_->Write();
   MuonReco1_ = ratioCalculator(MuonReco1_,MuonReco1Fail);   
   //MuonReco1Fail->Delete("all");
   MuonReco1_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu reco 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonReco1_->SetMarkerSize(2.0);
   MuonReco1_->UseCurrentStyle();
   MuonReco1_->Write();
   MuonReco2_ = ratioCalculator(MuonReco2_,MuonReco2Fail);   
  // MuonReco2Fail->Delete("all");
   MuonReco2_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu reco 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonReco2_->SetMarkerSize(2.0);
   MuonReco2_->UseCurrentStyle();
   MuonReco2_->Write();
   
   MuonIsoLow_ = ratioCalculator(MuonIsoLow_,MuonIsoLowFail);   
 //  MuonIsoLowFail->Delete("all");
   MuonIsoLow_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu iso N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonIsoLow_->SetMarkerSize(2.0);
   MuonIsoLow_->UseCurrentStyle();
   MuonIsoLow_->Write();
   MuonIso0_ = ratioCalculator(MuonIso0_,MuonIso0Fail);   
 //  MuonIso0Fail->Delete("all");
   MuonIso0_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu iso 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonIso0_->SetMarkerSize(2.0);
   MuonIso0_->UseCurrentStyle();
   MuonIso0_->Write();
   MuonIso1_ = ratioCalculator(MuonIso1_,MuonIso1Fail);   
 //  MuonIso1Fail->Delete("all");
   MuonIso1_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu iso 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonIso1_->SetMarkerSize(2.0);
   MuonIso1_->UseCurrentStyle();
   MuonIso1_->Write();
   MuonIso2_ = ratioCalculator(MuonIso2_,MuonIso2Fail);   
 //  MuonIso2Fail->Delete("all");
   MuonIso2_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu iso 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   MuonIso2_->SetMarkerSize(2.0);
   MuonIso2_->UseCurrentStyle();
   MuonIso2_->Write();
   
   MuMTWNJet_ = ratioCalculator(MuMTWNJet_,MuMTWNJetFail);   
  // MuMTWNJetFail->Delete("all");
   MuMTWNJet_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu M_{T}(W); N_{Jets}");
   MuMTWNJet_->UseCurrentStyle();
   MuMTWNJet_->Write();
   
   MuMTWMHTNJet_ = ratioCalculator(MuMTWMHTNJet_,MuMTWMHTNJetFail);   
  // MuMTWMHTNJetFail->Delete("all");
   MuMTWMHTNJet_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV #mu M_{T}(W); #slash{H}_{T} [GeV]; N_{Jets}");
   MuMTWMHTNJet_->SetMarkerSize(2.0);
   MuMTWMHTNJet_->UseCurrentStyle();
   MuMTWMHTNJet_->Write();
   
   
   ElecAcc_ = ratioCalculator(ElecAcc_,ElecAccFail);   
 //  ElecAccFail->Delete("all");
   ElecAcc_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec acceptance; #slash{H}_{T} [GeV]; N_{Jets}");
   ElecAcc_->Write();
   ElecRecoLow_ = ratioCalculator(ElecRecoLow_,ElecRecoLowFail);   
 //  ElecRecoLowFail->Delete("all");
   ElecRecoLow_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec reco N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecRecoLow_->Write();
   ElecReco0_ = ratioCalculator(ElecReco0_,ElecReco0Fail);   
//   ElecReco0Fail->Delete("all");
   ElecReco0_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec reco 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecReco0_->Write();
   ElecReco1_ = ratioCalculator(ElecReco1_,ElecReco1Fail);   
  // ElecReco1Fail->Delete("all");
   ElecReco1_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec reco 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecReco1_->Write();
   ElecReco2_ = ratioCalculator(ElecReco2_,ElecReco2Fail);   
 //  ElecReco2Fail->Delete("all");
   ElecReco2_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec reco 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecReco2_->Write();
   
   ElecIsoLow_ = ratioCalculator(ElecIsoLow_,ElecIsoLowFail);   
 //  ElecIsoLowFail->Delete("all");
   ElecIsoLow_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec iso N_{Jets}=2; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecIsoLow_->Write();
   ElecIso0_ = ratioCalculator(ElecIso0_,ElecIso0Fail);   
 //  ElecIso0Fail->Delete("all");
   ElecIso0_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec iso 3#leqN_{Jets}#leq5; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecIso0_->Write();
   ElecIso1_ = ratioCalculator(ElecIso1_,ElecIso1Fail);   
//   ElecIso1Fail->Delete("all");
   ElecIso1_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec iso 6#leqN_{Jets}#leq7; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecIso1_->Write();
   ElecIso2_ = ratioCalculator(ElecIso2_,ElecIso2Fail);   
 //  ElecIso2Fail->Delete("all");
   ElecIso2_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec iso 8#leqlegN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
   ElecIso2_->Write();
   
   ElecMTWNJet_ = ratioCalculator(ElecMTWNJet_,ElecMTWNJetFail);   
 //  ElecMTWNJetFail->Delete("all");
   ElecMTWNJet_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec M_{T}(W); N_{Jets}");
   ElecMTWNJet_->Write();
   
   ElecMTWMHTNJet_ = ratioCalculator(ElecMTWMHTNJet_,ElecMTWMHTNJetFail);   
 //  ElecMTWMHTNJetFail->Delete("all");
   ElecMTWMHTNJet_->SetTitle("CMS Simulation, L=5 fb-1, sqrt(s)=13 TeV elec M_{T}(W); #slash{H}_{T} [GeV]; N_{Jets}");
   ElecMTWMHTNJet_->Write();
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
