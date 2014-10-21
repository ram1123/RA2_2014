#define Prediction_cxx
// The class definition in Prediction.h has been generated automatically
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
// Root > T->Process("Prediction.C")
// Root > T->Process("Prediction.C","some options")
// Root > T->Process("Prediction.C+")
//

#include "Prediction.h"
#include <TH2.h>
#include <TStyle.h>


void Prediction::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   
   TString option = GetOption();
   tPrediction = NULL;

   std::cout << "input:" << GetInputList() << '\n';
   //TList* list = new TList;
/*   TList* list = GetInputList();
   TH2F* temp = new TH2F("Test","test",10,1,20,10,2,10);
   list->Add(temp);
   list->Add(MuonIso0_);
   list->Add(MuonIso1_);
   list->Add(MuonIso2_);
   list->Add(MuonRecoLow_);
   list->Add(MuonReco0_);
   list->Add(MuonReco1_);
   list->Add(MuonReco2_);
   list->Add(MuonAcc_);
   list->Add(MuMTWMHTNJet_);

   list->Add(ElecIsoLow_);
   list->Add(ElecIso0_);
   list->Add(ElecIso1_);
   list->Add(ElecIso2_);
   list->Add(ElecRecoLow_);
   list->Add(ElecReco0_);
   list->Add(ElecReco1_);
   list->Add(ElecReco2_);
   list->Add(ElecAcc_);
   list->Add(ElecMTWMHTNJet_);
   list->Add(MuonIsoLow_);  
   list->Print();
   //SetInputList(list);
   */
   std::cout << "done" << '\n';
}

void Prediction::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
   TString option = GetOption();
   tPrediction = new TTree("LostLeptonPrediction","LostLeptonPrediction");
   tPrediction->Branch("HT",&HT,"HT/F");
   tPrediction->Branch("MHT",&MHT,"MHT/F");
   tPrediction->Branch("NJets",&NJets,"NJets/s");
   tPrediction->Branch("BTags",&BTags,"BTags/s");
   tPrediction->Branch("NVtx",&NVtx,"NVtx/s");
   tPrediction->Branch("DeltaPhi1",&DeltaPhi1,"DeltaPhi1/F");
   tPrediction->Branch("DeltaPhi2",&DeltaPhi2,"DeltaPhi2/F");
   tPrediction->Branch("DeltaPhi3",&DeltaPhi3,"DeltaPhi3/F");
   tPrediction->Branch("WeightProducer", &WeightProducer, "WeightProducer/F");
   tPrediction->Branch("RecoIsoMuonNum",&RecoIsoMuonNum,"RecoIsoMuonNum/s");
   tPrediction->Branch("RecoIsoMuonPt", RecoIsoMuonPt, "RecoIsoMuonPt[RecoIsoMuonNum]/F");
   tPrediction->Branch("RecoIsoMuonEta", RecoIsoMuonEta, "RecoIsoMuonEta[RecoIsoMuonNum]/F");
   tPrediction->Branch("RecoIsoMuonPhi", RecoIsoMuonPhi, "RecoIsoMuonPhi[RecoIsoMuonNum]/F");
   tPrediction->Branch("RecoIsoMuonE", RecoIsoMuonE, "RecoIsoMuonE[RecoIsoMuonNum]/F");
   tPrediction->Branch("RecoIsoElecNum",&RecoIsoElecNum,"RecoIsoElecNum/s");
   tPrediction->Branch("RecoIsoElecPt", RecoIsoElecPt, "RecoIsoElecPt[RecoIsoElecNum]/F");
   tPrediction->Branch("RecoIsoElecEta", RecoIsoElecEta, "RecoIsoElecEta[RecoIsoElecNum]/F");
   tPrediction->Branch("RecoIsoElecPhi", RecoIsoElecPhi, "RecoIsoElecPhi[RecoIsoElecNum]/F");
   tPrediction->Branch("RecoIsoElecE", RecoIsoElecE, "RecoIsoElecE[RecoIsoElecNum]/F");
   tPrediction->Branch("MTW",&mtw,"MTW/F"); 
   tPrediction->Branch("totalPrediction",&totalWeight_,"totalPrediction/F");
   tPrediction->Branch("totalPredictionMTW",&totalWeightMTW_,"totalPredictionMTW/F");
   tPrediction->Branch("totalWeightMTWDiLep",&totalWeightMTWDiLep_,"totalWeightMTWDiLep/F");
   tPrediction->Branch("muIsoWeight",&muIsoWeight_,"muIsoWeight/F");
   tPrediction->Branch("muIsoWeightErrorUp",&muIsoWeightErrorUp_,"muIsoWeightErrorUp/F");
   tPrediction->Branch("muIsoWeightErrorDown",&muIsoWeightErrorDown_,"muIsoWeightErrorDown/F"); 
   tPrediction->Branch("muRecoWeight",&muRecoWeight_,"muRecoWeight_/F");
   tPrediction->Branch("muRecoWeightErrorUp",&muRecoWeightErrorUp_,"muRecoWeightErrorUp/F");
   tPrediction->Branch("muRecoWeightErrorDown",&muRecoWeightErrorDown_,"muRecoWeightErrorDown/F");
   tPrediction->Branch("muAccWeight",&muAccWeight_,"muAccWeight_/F");
   tPrediction->Branch("muAccWeightErrorUp",&muAccWeightErrorUp_,"muAccWeightErrorUp/F");
   tPrediction->Branch("muAccWeightErrorDown",&muAccWeightErrorDown_,"muAccWeightErrorDown/F");
   tPrediction->Branch("muTotalWeight",&muTotalWeight_,"muTotalWeight/F");
   tPrediction->Branch("muIsoEff",&muIsoEff_,"muIsoEff/F");
   tPrediction->Branch("muRecoEff",&muRecoEff_,"muRecoEff/F");
   tPrediction->Branch("muAccEff",&muAccEff_,"muAccEff/F");
   tPrediction->Branch("totalMuons_",&totalMuons_,"totalMuons_/F");
   
   tPrediction->Branch("elecIsoWeight",&elecIsoWeight_,"elecIsoWeight/F");
   tPrediction->Branch("elecIsoWeightErrorUp",&elecIsoWeightErrorUp_,"elecIsoWeightErrorUp/F");
   tPrediction->Branch("elecIsoWeightErrorDown",&elecIsoWeightErrorDown_,"elecIsoWeightErrorDown/F");
   tPrediction->Branch("elecRecoWeight",&elecRecoWeight_,"elecRecoWeight_/F");
   tPrediction->Branch("elecRecoWeightErrorUp",&elecRecoWeightErrorUp_,"elecRecoWeightErrorUp/F");
   tPrediction->Branch("elecRecoWeightErrorDown",&elecRecoWeightErrorDown_,"elecRecoWeightErrorDown/F");
   tPrediction->Branch("elecAccWeight",&elecAccWeight_,"elecAccWeight_/F");
   tPrediction->Branch("elecAccWeightErrorUp",&elecAccWeightErrorUp_,"elecAccWeightErrorUp/F");
   tPrediction->Branch("elecAccWeightErrorDown",&elecAccWeightErrorDown_,"elecAccWeightErrorDown/F");
   tPrediction->Branch("elecTotalWeight",&elecTotalWeight_,"elecTotalWeight/F");
   tPrediction->Branch("elecIsoEff",&elecIsoEff_,"elecIsoEff/F");
   tPrediction->Branch("elecRecoEff",&elecRecoEff_,"elecRecoEff/F");
   tPrediction->Branch("elecAccEff",&elecAccEff_,"elecAccEff/F");
   GetOutputList()->Add(tPrediction);


/*   GetInputList()->Print();
   MuonIso0_ = (TH2F*)GetInputList()->At(1);
   MuonIso1_ = (TH2F*)GetInputList()->At(2);
   MuonIso2_ = (TH2F*)GetInputList()->At(3);
   MuonRecoLow_ = (TH2F*)GetInputList()->At(4);
   MuonReco0_ = (TH2F*)GetInputList()->At(5);
   MuonReco1_ = (TH2F*)GetInputList()->At(6);
   MuonReco2_ = (TH2F*)GetInputList()->At(7);
   MuonAcc_ = (TH2F*)GetInputList()->At(8);
   MuMTWMHTNJet_ = (TH2F*)GetInputList()->At(9);
   ElecIsoLow_ = (TH2F*)GetInputList()->At(10);
   ElecIso0_ = (TH2F*)GetInputList()->At(11);
   ElecIso1_ = (TH2F*)GetInputList()->At(12);
   ElecIso2_ = (TH2F*)GetInputList()->At(13);
   ElecRecoLow_ = (TH2F*)GetInputList()->At(14);
   ElecReco0_ =  (TH2F*)GetInputList()->At(15);
   ElecReco1_ =  (TH2F*)GetInputList()->At(16);
   ElecReco2_ =  (TH2F*)GetInputList()->At(17);
   ElecAcc_ =  (TH2F*)GetInputList()->At(18);
   MuMTWMHTNJet_ =  (TH2F*)GetInputList()->At(19);
   MuonIsoLow_ = (TH2F*)GetInputList()->At(20);

*/
   std::cout<<"Prepartion of prediction done!"<<std::endl;
}

Bool_t Prediction::Process(Long64_t entry)
{
  resetValues();
  fChain->GetTree()->GetEntry(entry);
  if(HT<minHT_ || MHT< minMHT_ || NJets < minNJets_ ||  DeltaPhi1 < deltaPhi1_ || DeltaPhi2 < deltaPhi2_ || DeltaPhi3 < deltaPhi3_) return kTRUE;
  if(applyFilters_ &&  !FiltersPass() ) return kTRUE;
  if(RecoIsoMuonNum!=1 || RecoIsoElecNum!=0) return kTRUE;
  mtw =  MTWCalculator(METPt,METPhi, RecoIsoMuonPt[0], RecoIsoMuonPhi[0]);
//  std::cout<<"HT "<<HT<<" MHT "<<MHT<<std::endl;
//  GetEff(MuonIso0_,HT,MHT);
//  std::cout << "-------------------------------------------------------------------------------------" <<NJetsLow_ << '\n'; 
 // std::cout << "HT: " <<HT << " MHT: " <<MHT << " NJets: "<<NJets <<  '\n'; 
 // std::cout << "low:" <<NJetsLow_ << '\n'; 
  if( NJets==NJetsLow_ )
  {

	  muIsoEff_ = MuonIsoLow_->GetBinContent(MuonIsoLow_->GetXaxis()->FindBin(HT),MuonIsoLow_->GetYaxis()->FindBin(MHT));    
	  muIsoEffError_= MuonIsoLow_->GetBinError(MuonIsoLow_->GetXaxis()->FindBin(HT),MuonIsoLow_->GetYaxis()->FindBin(MHT));    
	  muRecoEff_ = MuonRecoLow_->GetBinContent(MuonRecoLow_->GetXaxis()->FindBin(HT),MuonRecoLow_->GetYaxis()->FindBin(MHT));    
	  muRecoEffError_= MuonRecoLow_->GetBinError(MuonRecoLow_->GetXaxis()->FindBin(HT),MuonRecoLow_->GetYaxis()->FindBin(MHT));   
    
	  elecIsoEff_ = ElecIsoLow_->GetBinContent(ElecIsoLow_->GetXaxis()->FindBin(HT),ElecIsoLow_->GetYaxis()->FindBin(MHT));    
	  elecIsoEffError_= ElecIsoLow_->GetBinError(ElecIsoLow_->GetXaxis()->FindBin(HT),ElecIsoLow_->GetYaxis()->FindBin(MHT));   
	  elecRecoEff_ = ElecRecoLow_->GetBinContent(ElecRecoLow_->GetXaxis()->FindBin(HT),ElecRecoLow_->GetYaxis()->FindBin(MHT));    
	  elecRecoEffError_= ElecRecoLow_->GetBinError(ElecRecoLow_->GetXaxis()->FindBin(HT),ElecRecoLow_->GetYaxis()->FindBin(MHT));   
  }
 // std::cout << "medium:" <<NJetsMedium_ << '\n'; 
  if (NJetsLow_<NJets &&NJets <= NJetsMedium_ )
  {
    muIsoEff_ = MuonIso0_->GetBinContent(MuonIso0_->GetXaxis()->FindBin(HT),MuonIso0_->GetYaxis()->FindBin(MHT));
    muIsoEffError_= MuonIso0_->GetBinError(MuonIso0_->GetXaxis()->FindBin(HT),MuonIso0_->GetYaxis()->FindBin(MHT));
    muRecoEff_ = MuonReco0_->GetBinContent(MuonReco0_->GetXaxis()->FindBin(HT),MuonReco0_->GetYaxis()->FindBin(MHT));
    muRecoEffError_= MuonReco0_->GetBinError(MuonReco0_->GetXaxis()->FindBin(HT),MuonReco0_->GetYaxis()->FindBin(MHT));
    
    elecIsoEff_ = ElecIso0_->GetBinContent(ElecIso0_->GetXaxis()->FindBin(HT),ElecIso0_->GetYaxis()->FindBin(MHT));
    elecIsoEffError_= ElecIso0_->GetBinError(ElecIso0_->GetXaxis()->FindBin(HT),ElecIso0_->GetYaxis()->FindBin(MHT));
    elecRecoEff_ = ElecReco0_->GetBinContent(ElecReco0_->GetXaxis()->FindBin(HT),ElecReco0_->GetYaxis()->FindBin(MHT));
    elecRecoEffError_= ElecReco0_->GetBinError(ElecReco0_->GetXaxis()->FindBin(HT),ElecReco0_->GetYaxis()->FindBin(MHT));
    
  }
 // std::cout << "medium:" <<NJetsMedium2_ << '\n'; 
  if (NJetsMedium_ < NJets && NJets <= NJetsMedium2_)
  {
    muIsoEff_ = MuonIso1_->GetBinContent(MuonIso1_->GetXaxis()->FindBin(HT),MuonIso1_->GetYaxis()->FindBin(MHT));
    muIsoEffError_= MuonIso1_->GetBinError(MuonIso1_->GetXaxis()->FindBin(HT),MuonIso1_->GetYaxis()->FindBin(MHT));
    muRecoEff_ = MuonReco1_->GetBinContent(MuonReco1_->GetXaxis()->FindBin(HT),MuonReco1_->GetYaxis()->FindBin(MHT));
    muRecoEffError_= MuonReco1_->GetBinError(MuonReco1_->GetXaxis()->FindBin(HT),MuonReco1_->GetYaxis()->FindBin(MHT));
    
    elecIsoEff_ = ElecIso1_->GetBinContent(ElecIso1_->GetXaxis()->FindBin(HT),ElecIso1_->GetYaxis()->FindBin(MHT));
    elecIsoEffError_= ElecIso1_->GetBinError(ElecIso1_->GetXaxis()->FindBin(HT),ElecIso1_->GetYaxis()->FindBin(MHT));
    elecRecoEff_ = ElecReco1_->GetBinContent(ElecReco1_->GetXaxis()->FindBin(HT),ElecReco1_->GetYaxis()->FindBin(MHT));
    elecRecoEffError_= ElecReco1_->GetBinError(ElecReco1_->GetXaxis()->FindBin(HT),ElecReco1_->GetYaxis()->FindBin(MHT));
  }
  if (NJets >= NJetsHigh_)
  {
    muIsoEff_ = MuonIso2_->GetBinContent(MuonIso2_->GetXaxis()->FindBin(HT),MuonIso2_->GetYaxis()->FindBin(MHT));
    muIsoEffError_= MuonIso2_->GetBinError(MuonIso2_->GetXaxis()->FindBin(HT),MuonIso2_->GetYaxis()->FindBin(MHT));
    muRecoEff_ = MuonReco2_->GetBinContent(MuonReco2_->GetXaxis()->FindBin(HT),MuonReco2_->GetYaxis()->FindBin(MHT));
    muRecoEffError_= MuonReco2_->GetBinError(MuonReco2_->GetXaxis()->FindBin(HT),MuonReco2_->GetYaxis()->FindBin(MHT));
    
    elecIsoEff_ = ElecIso2_->GetBinContent(ElecIso2_->GetXaxis()->FindBin(HT),ElecIso2_->GetYaxis()->FindBin(MHT));
    elecIsoEffError_= ElecIso2_->GetBinError(ElecIso2_->GetXaxis()->FindBin(HT),ElecIso2_->GetYaxis()->FindBin(MHT));
    elecRecoEff_ = ElecReco2_->GetBinContent(ElecReco2_->GetXaxis()->FindBin(HT),ElecReco2_->GetYaxis()->FindBin(MHT));
    elecRecoEffError_= ElecReco2_->GetBinError(ElecReco2_->GetXaxis()->FindBin(HT),ElecReco2_->GetYaxis()->FindBin(MHT));
  }
//  std::cout << "after njets\n";
  if(muIsoEffError_ + muIsoEff_ >1.00) muIsoEffError_ = (1 - muIsoEff_)*0.5;
  if(muRecoEffError_ + muRecoEff_ >1.00) muRecoEffError_ = (1 - muRecoEff_)*0.5;
  if(elecIsoEffError_ + elecIsoEff_ >1.00) elecIsoEffError_ = (1 - elecIsoEff_)*0.5;
  if(elecRecoEffError_ + elecRecoEff_ >1.00) elecRecoEffError_ = (1 - elecRecoEff_)*0.5;
  // acceptance
  muAccEff_ = MuonAcc_->GetBinContent(MuonAcc_->GetXaxis()->FindBin(MHT),MuonAcc_->GetYaxis()->FindBin(NJets+0.01) );
  muAccEffError_ = MuonAcc_->GetBinError(MuonAcc_->GetXaxis()->FindBin(MHT),MuonAcc_->GetYaxis()->FindBin(NJets+0.01) );
  if(muAccEffError_ + muAccEff_ >1.00) muAccEffError_ = .95 - muAccEff_;
  elecAccEff_ = ElecAcc_->GetBinContent(ElecAcc_->GetXaxis()->FindBin(MHT),ElecAcc_->GetYaxis()->FindBin(NJets+0.01) );
  elecAccEffError_ = ElecAcc_->GetBinError(ElecAcc_->GetXaxis()->FindBin(MHT),ElecAcc_->GetYaxis()->FindBin(NJets+0.01) );
  if(elecAccEffError_ + elecAccEff_ >1.00) elecAccEffError_ = .95 - elecAccEff_;
  // muon iso weight & uncertainty
  muIsoWeight_ = WeightProducer* (1 - muIsoEff_)/muIsoEff_;	
  muIsoWeightErrorUp_ = muIsoWeight_ - WeightProducer* (1 - effUp(muIsoEff_, muIsoEffError_))/ (effUp(muIsoEff_, muIsoEffError_));
  muIsoWeightErrorDown_ = WeightProducer* (1 - effDown(muIsoEff_, muIsoEffError_))/ (effDown(muIsoEff_, muIsoEffError_)) - muIsoWeight_;
  //		cout<<"muIsoWeight_:"<<muIsoWeight_ <<"+"<<muIsoWeightErrorUp_<<"-"<<muIsoWeightErrorDown_<<endl;
  // muon reco weight & uncertainty
  muRecoWeight_ = WeightProducer* 1 / muIsoEff_ * (1-muRecoEff_)/muRecoEff_;
  muRecoWeightErrorUp_ = muRecoWeight_ - WeightProducer* 1 / muIsoEff_ * (1-effUp(muRecoEff_, muRecoEffError_))/(effUp(muRecoEff_, muRecoEffError_));
  muRecoWeightErrorDown_ = WeightProducer* 1 / muIsoEff_ * (1-effDown(muRecoEff_, muRecoEffError_))/(effDown(muRecoEff_, muRecoEffError_))- muRecoWeight_;
  //		cout<<"muRecoWeight_:"<<muRecoWeight_ <<"+"<<muRecoWeightErrorUp_<<"-"<<muRecoWeightErrorDown_<<endl;
  // muon acc weight & uncertainty
  muAccWeight_ = WeightProducer* 1/muIsoEff_ * 1/muRecoEff_ *(1-muAccEff_)/muAccEff_;
  muAccWeightErrorUp_ = muAccWeight_ - WeightProducer* 1/muIsoEff_ * 1/muRecoEff_ *(1-effUp(muAccEff_,muAccEffError_))/(effUp(muAccEff_,muAccEffError_));
  muAccUp_ = WeightProducer* 1 / muIsoEff_ * 1/ muRecoEff_ * (1 - effUp(muAccEff_,muAccEffError_ )) / effUp(muAccEff_,muAccEffError_ );
  muAccWeightErrorDown_ = WeightProducer* 1/muIsoEff_ * 1/muRecoEff_ *(1-effDown(muAccEff_,muAccEffError_))/(effDown(muAccEff_,muAccEffError_)) - muAccWeight_;
  muAccDown_ = WeightProducer* 1 / muIsoEff_ * 1/ muRecoEff_ * (1 - effDown(muAccEff_,muAccEffError_ )) / effDown(muAccEff_,muAccEffError_ + muAccEff_*MuAccUncertaintyDown_ / 100);
  //		cout<<"muAccWeight_:"<<muAccWeight_ <<"+"<<muAccWeightErrorUp_<<"-"<<muAccWeightErrorDown_<<endl;
  
  muTotalWeight_ = muIsoWeight_ + muRecoWeight_ + muAccWeight_;
  totalMuons_ = WeightProducer/ (muIsoEff_ * muRecoEff_ * muAccEff_);
  
  // elec acc weight & uncertainty
  elecAccWeight_ = totalMuons_ * (1 - elecAccEff_);
  elecAccWeightErrorUp_ = elecAccWeight_ - totalMuons_ * (1 - effUp(elecAccEff_,elecAccEffError_));
  elecAccUp_ = totalMuons_ * (1- effUp(elecAccEff_, elecAccEffError_) ) ;
  elecAccWeightErrorDown_ =  totalMuons_ * (1 - effDown(elecAccEff_,elecAccEffError_)) - elecAccWeight_;
  elecAccDown_ = totalMuons_ * (1- effDown(elecAccEff_, elecAccEffError_) ) ;
  //		cout<<"ElecAcc:"<<elecAccWeight_ <<"+"<<elecAccWeightErrorUp_<<"-"<<elecAccWeightErrorDown_<<endl;
  // elec reco weight & uncertainty
  elecRecoWeight_ = totalMuons_ * (elecAccEff_) * (1 - elecRecoEff_);
  elecRecoWeightErrorUp_ = elecRecoWeight_ - totalMuons_ * (elecAccEff_) * (1 - effUp(elecRecoEff_,elecRecoEffError_)) ;
  elecRecoWeightErrorDown_ =  totalMuons_ * (elecAccEff_) * (1 - effDown(elecRecoEff_,elecRecoEffError_)) - elecRecoWeight_;
  //		cout<<"ElecReco:"<<elecRecoWeight_ <<"+"<<elecRecoWeightErrorUp_<<"-"<<elecRecoWeightErrorDown_<<endl;
  // elec iso weight & uncertainty
  elecIsoWeight_ = totalMuons_ * (elecAccEff_) * (elecRecoEff_) * (1 - elecIsoEff_) ;
  elecIsoWeightErrorUp_ = elecIsoWeight_ - totalMuons_ * (elecAccEff_) * elecRecoEff_ * (1 - effUp(elecIsoEff_,elecIsoEffError_)) ;
  elecIsoWeightErrorDown_ = totalMuons_ * (elecAccEff_) * elecRecoEff_ * (1 - effDown(elecIsoEff_,elecIsoEffError_)) - elecIsoWeight_;
  //		cout<<"ElecIso:"<<elecIsoWeight_ <<"+"<<elecIsoWeightErrorUp_<<"-"<<elecIsoWeightErrorDown_<<endl;
  
  elecTotalWeight_ = elecAccWeight_ + elecRecoWeight_ + elecIsoWeight_;
  totalWeight_ = muTotalWeight_ + elecTotalWeight_;

  // MTW cut and uncertainty
  int MTWBinX = MuMTWMHTNJet_->GetXaxis()->FindBin(MHT);
  if(MTWBinX > MuMTWMHTNJet_->GetXaxis()->GetNbins() )
  {
    MTWBinX=MTWBinX-1;
    cout<<"MTWBinX out of range:"<<MuMTWMHTNJet_->GetXaxis()->GetNbins() <<", was "<<MuMTWMHTNJet_->GetXaxis()->FindBin(MHT)<<", set to"<<MTWBinX<<endl;
  }
  int MTWBinY = MuMTWMHTNJet_->GetYaxis()->FindBin(NJets+0.01);
  if(MTWBinY>MuMTWMHTNJet_->GetYaxis()->GetNbins() )
  {
    MTWBinY=MTWBinY-1;
    cout<<"MTWBinY out of range:"<<MuMTWMHTNJet_->GetYaxis()->GetNbins() <<", was "<<MuMTWMHTNJet_->GetYaxis()->FindBin(NJets+0.01)<<", set to"<<MTWBinY<<endl;
  }
  totalWeightMTW_ = totalWeight_ / MuMTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
  totalMuonsMTW_= totalMuons_ / MuMTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
  tPrediction->Fill();
   return kTRUE;
}

void Prediction::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Prediction::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  outPutFile2_->cd();
  tPrediction->Write();

}
void Prediction::resetValues()
{
  mtw=0.;
  muIsoEff_=0;
  muIsoEffError_=0;
  muIsoWeight_=0;
  muIsoWeightErrorUp_=0;
  muIsoWeightErrorDown_=0;
  muRecoEff_=0;
  muRecoEffError_=0;
  muRecoWeight_=0;	
  muRecoWeightErrorUp_=0;
  muRecoWeightErrorDown_=0;
  muAccEff_=0;
  muAccEffError_=0;
  muAccWeight_=0;
  muAccWeightErrorUp_=0;	
  muAccWeightErrorDown_=0;	
  
  elecIsoEff_=0;
  elecIsoEffError_=0;
  elecIsoWeight_=0;
  elecIsoWeightErrorUp_=0;
  elecIsoWeightErrorDown_=0;
  elecRecoEff_=0;
  elecRecoEffError_=0;
  elecRecoWeight_=0;	
  elecRecoWeightErrorUp_=0;
  elecRecoWeightErrorDown_=0;
  elecAccEff_=0;
  elecAccEffError_=0;
  elecAccWeight_=0;
  elecAccWeightErrorUp_=0;	
  elecAccWeightErrorDown_=0;	
}
bool Prediction::FiltersPass()
{
  bool result=true;
  // if(Filter_HBHENoiseFilterRA2==0) result=false;
  return result;
}
double Prediction::deltaR(double eta1, double phi1, double eta2, double phi2)
{
  double deta = eta1-eta2;
  double dphi = TVector2::Phi_mpi_pi(phi1-phi2);
  return sqrt(deta * deta + dphi *dphi); 
}

double Prediction::MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi)
{
  double deltaPhi =TVector2::Phi_mpi_pi(lepPhi-metPhi);
  return sqrt(2*lepPt*metPt*(1-cos(deltaPhi)) );
}
double Prediction::effUp(double eff, double up)
{
  double result = eff + up;
  if(result>0.995)result=0.995;
  return result;
}
double Prediction::effDown(double eff, double down)
{
  double result = eff - down;
  if(result<0.01)result=eff * 0.1;
  return result;
}
std::vector<Float_t> Prediction::GetEff(TH2F *TH2Eff, Float_t XValue, Float_t YValue)
{
  std::vector<Float_t> result;
  std::cout << "hist:" << TH2Eff << '\n';
  Float_t maxX = TH2Eff->GetXaxis()->GetXmax();
  Float_t minX = TH2Eff->GetXaxis()->GetXmin();
  Float_t maxY = TH2Eff->GetYaxis()->GetXmax();
  Float_t minY = TH2Eff->GetYaxis()->GetXmin();
  std::cout<<"Hist x: "<<minX<<" "<<maxX<<std::endl;
  std::cout<<"Hist y: "<<minY<<" "<<maxY<<std::endl;
  if(XValue>maxX) XValue=maxX-0.0001;
  if(XValue<minX) XValue=minX+0.0001;
  if(YValue>maxY) YValue=maxY-0.0001;
  if(YValue<minY) YValue=minY+0.0001;
//  std::cout<<"Bin[3,3]: "<<TH2Eff->GetBinContent(3,3)<<std::endl;
//  std::cout<<"Bin[2,5]: "<<TH2Eff->GetBinContent(2,5)<<std::endl;
//  std::cout<<"Bin[4,3]: "<<TH2Eff->GetBinContent(4,3)<<std::endl;
  result.push_back(TH2Eff->GetBinContent(TH2Eff->GetXaxis()->FindBin(XValue),TH2Eff->GetYaxis()->FindBin(YValue)));
  result.push_back(TH2Eff->GetBinError(TH2Eff->GetXaxis()->FindBin(XValue),TH2Eff->GetYaxis()->FindBin(YValue)));
  return result;
}
