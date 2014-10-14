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
   // initialize the tree and the Histograms
   tExpectation_ = new TTree("LostLeptonExpectation","a simple Tree with simple variables");
   tExpectation_->Branch("HT",&HT,"HT/F");
   tExpectation_->Branch("MHT",&MHT,"MHT/F");
   tExpectation_->Branch("NJets",&NJets,"NJets/s");
   GetOutputList()->Add(tExpectation_);

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
   
   MTWNJet_ = new TH1F("MTW","MTW",mtwNjet_-1,MtwNjet_);
   GetOutputList()->Add(MTWNJet_);
   MTWNJetFail = (TH1F*)MTWNJet_->Clone();
   MTWNJetFail->SetName("MTWNJetFail");
   GetOutputList()->Add(MTWNJetFail);
   
   MTWMHTNJet_ = new TH2F("MTWMHTNjet","MTWMHTNjet",mtwMHT_-1,MtwMHT_,mtwNjet_-1,MtwNjet_);
   GetOutputList()->Add(MTWMHTNJet_);
   MTWMHTNJetFail = (TH2F*)MTWMHTNJet_->Clone();
   MTWMHTNJetFail->SetName("MTWMHTNJetFail");
   GetOutputList()->Add(MTWMHTNJetFail);


}

Bool_t EffMaker::Process(Long64_t entry)
{
	fChain->GetTree()->GetEntry(entry);

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
   std::cout<<"EffMaker::Terminate started"<<std::endl;
   outPutFile_->cd();
 //  MuAccEff->Draw();
 //  MuAccEff_ = MuAccEff;
   tExpectation_->Write();
}
