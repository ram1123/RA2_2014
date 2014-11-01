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
#include <iostream>


void Prediction::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   MuonIsoLow_=NULL;
   MuonIso0_=NULL;
   MuonIso1_=NULL;
   MuonIso2_=NULL;
   MuonRecoLow_=NULL;
   MuonReco0_=NULL;
   MuonReco1_=NULL;
   MuonReco2_=NULL;
   MuonAcc_=NULL;
   MuMTWNJet_=NULL;
   MuMTWMHTNJet_=NULL;
   ElecIsoLow_=NULL;
   ElecIso0_=NULL;
   ElecIso1_=NULL;
   ElecIso2_=NULL;
   ElecRecoLow_=NULL;
   ElecReco0_=NULL;
   ElecReco1_=NULL;
   ElecReco2_=NULL;
   ElecAcc_=NULL;
   ElecMTWNJet_=NULL;
   ElecMTWMHTNJet_=NULL;
   MuonPurityMHTNJet_=NULL;
   ElecPurityMHTNJet_=NULL;
   MuDiLepMTW_=NULL;
   MuDiLepEff_=NULL;
   ElecDiLepMTW_=NULL;
   ElecDiLepEff_=NULL;
   tPrediction_=NULL;
   // btag
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
   MuMTWMHTBTag=NULL;
   if(useGenInfoToMatchCSMuonToGen_)std::cout<<"WARNING USING GEN INFORMATION TO MAKE SURE THIS IS A SINGLE MUON ELEC EVENT AND DO MATCHING TO HAVE 100% PURITY OF MUON CONTROL SAMPLE"<<std::endl;

}

void Prediction::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TFile *effInput = new TFile("/afs/desy.de/user/a/adraeger/xxl/csa14/RA2_2014/LostLeptonMacros/Expectation.root","UPDATE");
   TDirectory *EffInputFolder =   (TDirectory*)effInput->Get("Efficiencies");
   MuonIsoLow_ = (TH2F*)EffInputFolder->Get("MuonIsoNJet2Jet");
   MuonIso0_ = (TH2F*)EffInputFolder->Get("MuonIsoNJetLow");
   MuonIso1_ = (TH2F*)EffInputFolder->Get("MuonIsoNJetMedium");
   MuonIso2_ = (TH2F*)EffInputFolder->Get("MuonIsoNJetHgih");
   MuonRecoLow_ = (TH2F*)EffInputFolder->Get("MuonRecoNJet2Jet");
   MuonReco0_ = (TH2F*)EffInputFolder->Get("MuonRecoNJetLow");
   MuonReco1_ = (TH2F*)EffInputFolder->Get("MuonRecoNJetMedium");
   MuonReco2_ = (TH2F*)EffInputFolder->Get("MuonRecoNJetHgih");
   MuonAcc_ = (TH2F*)EffInputFolder->Get("MuonAcc");
   MuMTWNJet_ = (TH1F*)EffInputFolder->Get("MuMTW");
   MuMTWMHTNJet_ = (TH2F*)EffInputFolder->Get("MuMTWMHTNjet");
   MuDiLepMTW_ = (TH2F*)EffInputFolder->Get("MuonDiLepMTW");
   MuDiLepEff_ = (TH1F*)EffInputFolder->Get("MuonDiLepEff");
   
   ElecIsoLow_ = (TH2F*)EffInputFolder->Get("ElecIsoNJet2Jet");
   ElecIso0_ = (TH2F*)EffInputFolder->Get("ElecIsoNJetLow");
   ElecIso1_ = (TH2F*)EffInputFolder->Get("ElecIsoNJetMedium");
   ElecIso2_ = (TH2F*)EffInputFolder->Get("ElecIsoNJetHgih");
   ElecRecoLow_ = (TH2F*)EffInputFolder->Get("ElecRecoNJet2Jet");
   ElecReco0_ = (TH2F*)EffInputFolder->Get("ElecRecoNJetLow");
   ElecReco1_ = (TH2F*)EffInputFolder->Get("ElecRecoNJetMedium");
   ElecReco2_ = (TH2F*)EffInputFolder->Get("ElecRecoNJetHgih");
   ElecAcc_ = (TH2F*)EffInputFolder->Get("ElecAcc");
   MuMTWNJet_ = (TH1F*)EffInputFolder->Get("MuMTW");
   MuMTWMHTNJet_ = (TH2F*)EffInputFolder->Get("MuMTWMHTNjet");
   ElecDiLepMTW_ = (TH2F*)EffInputFolder->Get("ElecDiLepMTW");
   ElecDiLepEff_ = (TH1F*)EffInputFolder->Get("ElecDiLepEff");
   
   // btag information
   MuonAccBTag = (TH2F*)EffInputFolder->Get("MuonAccBTag");
   MuonIsoBTag0 = (TH2F*)EffInputFolder->Get("MuonIsoBTag0");
   MuonIsoBTag1 = (TH2F*)EffInputFolder->Get("MuonIsoBTag1");
   MuonIsoBTag2ToInf = (TH2F*)EffInputFolder->Get("MuonIsoBTag2ToInf");
   MuonRecoBTag0 = (TH2F*)EffInputFolder->Get("MuonRecoBTag0");
   MuonRecoBTag1 = (TH2F*)EffInputFolder->Get("MuonRecoBTag1");
   MuonRecoBTag2ToInf = (TH2F*)EffInputFolder->Get("MuonRecoBTag2ToInf");
   MuMTWMHTBTag = (TH2F*)EffInputFolder->Get("MuMTWMHTBTag");
   
   ElecAccBTag = (TH2F*)EffInputFolder->Get("ElecAccBTag");
   ElecIsoBTag0 = (TH2F*)EffInputFolder->Get("ElecIsoBTag0");
   ElecIsoBTag1 = (TH2F*)EffInputFolder->Get("ElecIsoBTag1");
   ElecIsoBTag2ToInf = (TH2F*)EffInputFolder->Get("ElecIsoBTag2ToInf");
   ElecRecoBTag0 = (TH2F*)EffInputFolder->Get("ElecRecoBTag0");
   ElecRecoBTag1 = (TH2F*)EffInputFolder->Get("ElecRecoBTag1");
   ElecRecoBTag2ToInf = (TH2F*)EffInputFolder->Get("ElecRecoBTag2ToInf");
   MuMTWMHTBTag = (TH2F*)EffInputFolder->Get("MuMTWMHTBTag");
   
   
   TString option = GetOption();
   useGenInfoToMatchCSMuonToGen=useGenInfoToMatchCSMuonToGen_;
   tPrediction_ = new TTree("LostLeptonPrediction","a simple Tree with simple variables");
   tPrediction_->Branch("MatchedToGenMuonExDiLep",&useGenInfoToMatchCSMuonToGen,"MatchedToGenMuonExDiLep/O");
   if(useGenInfoToMatchCSMuonToGen_) tPrediction_->Branch("DeltaRGenToRecoIsoMuon",&deltaRGenToRecoIsoMuon_,"DeltaRGenToRecoIsoMuon/F");
   if(useGenInfoToMatchCSMuonToGen_) tPrediction_->Branch("DiffPtGenToRecoIsoMuon",&diffPtGenToRecoIsoMuon_,"DiffPtGenToRecoIsoMuon/F");
   if(useGenInfoToMatchCSMuonToGen_)  tPrediction_->Branch("MuonCSMatched",&Matched_,"MuonCSMatched/s");
   tPrediction_->Branch("HT",&HT,"HT/F");
   tPrediction_->Branch("MHT",&MHT,"MHT/F");
   tPrediction_->Branch("NJets",&NJets,"NJets/s");
   tPrediction_->Branch("BTags",&BTags,"BTags/s");
   tPrediction_->Branch("NVtx",&NVtx,"NVtx/s");
   tPrediction_->Branch("DeltaPhi1",&DeltaPhi1,"DeltaPhi1/F");
   tPrediction_->Branch("DeltaPhi2",&DeltaPhi2,"DeltaPhi2/F");
   tPrediction_->Branch("DeltaPhi3",&DeltaPhi3,"DeltaPhi3/F");
   tPrediction_->Branch("WeightProducer", &WeightProducer, "WeightProducer/F");
   tPrediction_->Branch("METPt",&METPt,"METPt/F");
   tPrediction_->Branch("METEta",&METEta,"METEta/F");
   tPrediction_->Branch("METPhi",&METPhi,"METPhi/F");
   tPrediction_->Branch("RecoIsoMuonNum",&RecoIsoMuonNum,"RecoIsoMuonNum/s");
   tPrediction_->Branch("RecoIsoMuonPt", RecoIsoMuonPt, "RecoIsoMuonPt[RecoIsoMuonNum]/F");
   tPrediction_->Branch("RecoIsoMuonEta", RecoIsoMuonEta, "RecoIsoMuonEta[RecoIsoMuonNum]/F");
   tPrediction_->Branch("RecoIsoMuonPhi", RecoIsoMuonPhi, "RecoIsoMuonPhi[RecoIsoMuonNum]/F");
   tPrediction_->Branch("RecoIsoMuonE", RecoIsoMuonE, "RecoIsoMuonE[RecoIsoMuonNum]/F");
   tPrediction_->Branch("RecoIsoElecNum",&RecoIsoElecNum,"RecoIsoElecNum/s");
   tPrediction_->Branch("RecoIsoElecPt", RecoIsoElecPt, "RecoIsoElecPt[RecoIsoElecNum]/F");
   tPrediction_->Branch("RecoIsoElecEta", RecoIsoElecEta, "RecoIsoElecEta[RecoIsoElecNum]/F");
   tPrediction_->Branch("RecoIsoElecPhi", RecoIsoElecPhi, "RecoIsoElecPhi[RecoIsoElecNum]/F");
   tPrediction_->Branch("RecoIsoElecE", RecoIsoElecE, "RecoIsoElecE[RecoIsoElecNum]/F");
   tPrediction_->Branch("MTW",&mtw,"MTW/F"); 
   applyDiLepCorrection=applyDiLepCorrection_;
   tPrediction_->Branch("applyDiLepCorrection",&applyDiLepCorrection,"applyDiLepCorrection/O");
   tPrediction_->Branch("totalPrediction",&totalWeight_,"totalPrediction/F");
   tPrediction_->Branch("totalPredictionMTW",&totalWeightMTW_,"totalPredictionMTW/F");
   tPrediction_->Branch("totalWeightMTWDiLep",&totalWeightMTWDiLep_,"totalWeightMTWDiLep/F");
   tPrediction_->Branch("muIsoWeight",&muIsoWeight_,"muIsoWeight/F");
   tPrediction_->Branch("muIsoWeightErrorUp",&muIsoWeightErrorUp_,"muIsoWeightErrorUp/F");
   tPrediction_->Branch("muIsoWeightErrorDown",&muIsoWeightErrorDown_,"muIsoWeightErrorDown/F"); 
   tPrediction_->Branch("muRecoWeight",&muRecoWeight_,"muRecoWeight/F");
   tPrediction_->Branch("muRecoWeightErrorUp",&muRecoWeightErrorUp_,"muRecoWeightErrorUp/F");
   tPrediction_->Branch("muRecoWeightErrorDown",&muRecoWeightErrorDown_,"muRecoWeightErrorDown/F");
   tPrediction_->Branch("muAccWeight",&muAccWeight_,"muAccWeight_/F");
   tPrediction_->Branch("muAccWeightErrorUp",&muAccWeightErrorUp_,"muAccWeightErrorUp/F");
   tPrediction_->Branch("muAccWeightErrorDown",&muAccWeightErrorDown_,"muAccWeightErrorDown/F");
   tPrediction_->Branch("muTotalWeight",&muTotalWeight_,"muTotalWeight/F");
   tPrediction_->Branch("muIsoEff",&muIsoEff_,"muIsoEff/F");
   tPrediction_->Branch("muRecoEff",&muRecoEff_,"muRecoEff/F");
   tPrediction_->Branch("muAccEff",&muAccEff_,"muAccEff/F");
   tPrediction_->Branch("totalMuons",&totalMuons_,"totalMuons/F");
   
   tPrediction_->Branch("elecIsoWeight",&elecIsoWeight_,"elecIsoWeight/F");
   tPrediction_->Branch("elecIsoWeightErrorUp",&elecIsoWeightErrorUp_,"elecIsoWeightErrorUp/F");
   tPrediction_->Branch("elecIsoWeightErrorDown",&elecIsoWeightErrorDown_,"elecIsoWeightErrorDown/F");
   tPrediction_->Branch("elecRecoWeight",&elecRecoWeight_,"elecRecoWeight/F");
   tPrediction_->Branch("elecRecoWeightErrorUp",&elecRecoWeightErrorUp_,"elecRecoWeightErrorUp/F");
   tPrediction_->Branch("elecRecoWeightErrorDown",&elecRecoWeightErrorDown_,"elecRecoWeightErrorDown/F");
   tPrediction_->Branch("elecAccWeight",&elecAccWeight_,"elecAccWeight/F");
   tPrediction_->Branch("elecAccWeightErrorUp",&elecAccWeightErrorUp_,"elecAccWeightErrorUp/F");
   tPrediction_->Branch("elecAccWeightErrorDown",&elecAccWeightErrorDown_,"elecAccWeightErrorDown/F");
   tPrediction_->Branch("elecTotalWeight",&elecTotalWeight_,"elecTotalWeight/F");
   tPrediction_->Branch("elecIsoEff",&elecIsoEff_,"elecIsoEff/F");
   tPrediction_->Branch("elecRecoEff",&elecRecoEff_,"elecRecoEff/F");
   tPrediction_->Branch("elecAccEff",&elecAccEff_,"elecAccEff/F");
   if(applyDiLepCorrection_)
   {
	   tPrediction_->Branch("diLepCorrectionEff",&diLepCorrectionEff_,"diLepCorrectionEff/F");
	   tPrediction_->Branch("diLepCorrectionEffErro_",&diLepCorrectionEffError_,"diLepCorrectionEffError/F");
	   tPrediction_->Branch("diLepMuEff",&diLepMuEff_,"diLepMuEff/F");
	   tPrediction_->Branch("diLepMuEffError",&diLepMuEffError_,"diLepMuEffError/F");
	   tPrediction_->Branch("diLepElecEff",&diLepElecEff_,"diLepElecEff/F");
	   tPrediction_->Branch("diLepElecEffError",&diLepElecEffError_,"diLepElecEffError/F");
   }
   tPrediction_->Branch("totalPredictionBTag",&totalWeightBTag_,"totalPredictionBTag/F");
   tPrediction_->Branch("totalPredictionMTWBTag",&totalWeightMTWBTag_,"totalPredictionMTWBTag/F");
   tPrediction_->Branch("totalWeightMTWDiLepBTag",&totalWeightMTWDiLepBTag_,"totalWeightMTWDiLepBTag/F");
   tPrediction_->Branch("muIsoWeightBTag",&muIsoWeightBTag_,"muIsoWeightBTag/F");
   tPrediction_->Branch("muIsoWeightErrorUpBTag",&muIsoWeightErrorUpBTag_,"muIsoWeightErrorUpBTag/F");
   tPrediction_->Branch("muIsoWeightErrorDownBTag",&muIsoWeightErrorDownBTag_,"muIsoWeightErrorDownBTag/F"); 
   tPrediction_->Branch("muRecoWeightBTag",&muRecoWeightBTag_,"muRecoWeightBTag/F");
   tPrediction_->Branch("muRecoWeightErrorUpBTag",&muRecoWeightErrorUpBTag_,"muRecoWeightErrorUpBTag/F");
   tPrediction_->Branch("muRecoWeightErrorDownBTag",&muRecoWeightErrorDownBTag_,"muRecoWeightErrorDownBTag/F");
   tPrediction_->Branch("muAccWeightBTag",&muAccWeightBTag_,"muAccWeightBTagBTag_/F");
   tPrediction_->Branch("muAccWeightErrorUpBTag",&muAccWeightErrorUpBTag_,"muAccWeightErrorUpBTag/F");
   tPrediction_->Branch("muAccWeightErrorDownBTag",&muAccWeightErrorDownBTag_,"muAccWeightErrorDownBTag/F");
   tPrediction_->Branch("muTotalWeightBTag",&muTotalWeightBTag_,"muTotalWeightBTag/F");
   tPrediction_->Branch("muIsoEffBTag",&muIsoEffBTag_,"muIsoEffBTag/F");
   tPrediction_->Branch("muRecoEffBTag",&muRecoEffBTag_,"muRecoEffBTag/F");
   tPrediction_->Branch("muAccEffBTag",&muAccEffBTag_,"muAccEffBTag/F");
   tPrediction_->Branch("totalMuonsBTag",&totalMuonsBTag_,"totalMuonsBTag/F");
   
   tPrediction_->Branch("elecIsoWeightBTag",&elecIsoWeightBTag_,"elecIsoWeightBTag/F");
   tPrediction_->Branch("elecIsoWeightErrorUpBTag",&elecIsoWeightErrorUpBTag_,"elecIsoWeightErrorUpBTag/F");
   tPrediction_->Branch("elecIsoWeightErrorDownBTag",&elecIsoWeightErrorDownBTag_,"elecIsoWeightErrorDownBTag/F");
   tPrediction_->Branch("elecRecoWeightBTag",&elecRecoWeightBTag_,"elecRecoWeightBTag/F");
   tPrediction_->Branch("elecRecoWeightErrorUpBTag",&elecRecoWeightErrorUpBTag_,"elecRecoWeightErrorUpBTag/F");
   tPrediction_->Branch("elecRecoWeightErrorDownBTag",&elecRecoWeightErrorDownBTag_,"elecRecoWeightErrorDownBTag/F");
   tPrediction_->Branch("elecAccWeightBTag",&elecAccWeightBTag_,"elecAccWeightBTag/F");
   tPrediction_->Branch("elecAccWeightErrorUpBTag",&elecAccWeightErrorUpBTag_,"elecAccWeightErrorUpBTag/F");
   tPrediction_->Branch("elecAccWeightErrorDownBTag",&elecAccWeightErrorDownBTag_,"elecAccWeightErrorDownBTag/F");
   tPrediction_->Branch("elecTotalWeightBTag",&elecTotalWeightBTag_,"elecTotalWeightBTag/F");
   tPrediction_->Branch("elecIsoEffBTag",&elecIsoEffBTag_,"elecIsoEffBTag/F");
   tPrediction_->Branch("elecRecoEffBTag",&elecRecoEffBTag_,"elecRecoEffBTag/F");
   tPrediction_->Branch("elecAccEffBTag",&elecAccEffBTag_,"elecAccEffBTag/F");
   GetOutputList()->Add(tPrediction_);
}

Bool_t Prediction::Process(Long64_t entry)
{
	resetValues();
	fChain->GetTree()->GetEntry(entry);
	if(HT<minHT_ || MHT< minMHT_ || NJets < minNJets_||  DeltaPhi1 < deltaPhi1_ || DeltaPhi2 < deltaPhi2_ || DeltaPhi3 < deltaPhi3_ ) return kTRUE;
	if(applyFilters_ &&  !FiltersPass() ) return kTRUE;
	if(RecoIsoMuonNum!=1 || RecoIsoElecNum!=0) return kTRUE;
	if(useGenInfoToMatchCSMuonToGen_)
	{
		if(GenMuNum!=0)if(deltaR(GenMuEta[0],GenMuPhi[0],RecoIsoMuonEta[0],RecoIsoMuonPhi[0])<maxDeltaRGenToRecoIsoMuon_ || std::abs(GenMuPt[0]-RecoIsoMuonPt[0])/GenMuPt[0]<maxDiffPtGenToRecoIsoMuon_)
		{
			Matched_=1;
		}
		if(GenMuNum!=1 || GenElecNum!=0) Matched_=0;
	}
	deltaRGenToRecoIsoMuon_=deltaR(GenMuEta[0],GenMuPhi[0],RecoIsoMuonEta[0],RecoIsoMuonPhi[0]);
	diffPtGenToRecoIsoMuon_=std::abs(GenMuPt[0]-RecoIsoMuonPt[0])/GenMuPt[0];
	mtw =  MTWCalculator(METPt,METPhi, RecoIsoMuonPt[0], RecoIsoMuonPhi[0]);
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
	// di lepton
	if(applyDiLepCorrection_)
	{
		diLepCorrectionEff_ = MuDiLepMTW_->GetBinContent(MuDiLepMTW_->GetXaxis()->FindBin(MHT),MuDiLepMTW_->GetYaxis()->FindBin(NJets+0.01));
		diLepCorrectionEffError_ = MuDiLepMTW_->GetBinError(MuDiLepMTW_->GetXaxis()->FindBin(MHT),MuDiLepMTW_->GetYaxis()->FindBin(NJets+0.01));
		diLepMuEff_ = MuDiLepEff_->GetBinContent(MuDiLepEff_->GetXaxis()->FindBin(NJets+0.01));
		diLepMuEffError_ = MuDiLepEff_->GetBinError(MuDiLepEff_->GetXaxis()->FindBin(NJets+0.01));
		diLepElecEff_ = ElecDiLepEff_->GetBinContent(ElecDiLepEff_->GetXaxis()->FindBin(NJets+0.01));
		diLepElecEffError_ = ElecDiLepEff_->GetBinError(ElecDiLepEff_->GetXaxis()->FindBin(NJets+0.01));
	}
	double diLepCorrectedWeight =WeightProducer;
	if(applyDiLepCorrection_)
	{
		diLepCorrectedWeight = WeightProducer * diLepCorrectionEff_;
	}
	// muon iso weight & uncertaint
	muIsoWeight_ = diLepCorrectedWeight* (1 - muIsoEff_)/muIsoEff_;	
	muIsoWeightErrorUp_ = muIsoWeight_ - diLepCorrectedWeight* (1 - effUp(muIsoEff_, muIsoEffError_))/ (effUp(muIsoEff_, muIsoEffError_));
	muIsoWeightErrorDown_ = diLepCorrectedWeight* (1 - effDown(muIsoEff_, muIsoEffError_))/ (effDown(muIsoEff_, muIsoEffError_)) - muIsoWeight_;
	//		cout<<"muIsoWeight_:"<<muIsoWeight_ <<"+"<<muIsoWeightErrorUp_<<"-"<<muIsoWeightErrorDown_<<endl;
	// muon reco weight & uncertainty
	muRecoWeight_ = diLepCorrectedWeight* 1 / muIsoEff_ * (1-muRecoEff_)/muRecoEff_;
	muRecoWeightErrorUp_ = muRecoWeight_ - diLepCorrectedWeight* 1 / muIsoEff_ * (1-effUp(muRecoEff_, muRecoEffError_))/(effUp(muRecoEff_, muRecoEffError_));
	muRecoWeightErrorDown_ = diLepCorrectedWeight* 1 / muIsoEff_ * (1-effDown(muRecoEff_, muRecoEffError_))/(effDown(muRecoEff_, muRecoEffError_))- muRecoWeight_;
	//		cout<<"muRecoWeight_:"<<muRecoWeight_ <<"+"<<muRecoWeightErrorUp_<<"-"<<muRecoWeightErrorDown_<<endl;
	// muon acc weight & uncertainty
	muAccWeight_ = diLepCorrectedWeight* 1/muIsoEff_ * 1/muRecoEff_ *(1-muAccEff_)/muAccEff_;
	muAccWeightErrorUp_ = muAccWeight_ - diLepCorrectedWeight* 1/muIsoEff_ * 1/muRecoEff_ *(1-effUp(muAccEff_,muAccEffError_))/(effUp(muAccEff_,muAccEffError_));
	muAccUp_ = diLepCorrectedWeight* 1 / muIsoEff_ * 1/ muRecoEff_ * (1 - effUp(muAccEff_,muAccEffError_ )) / effUp(muAccEff_,muAccEffError_ );
	muAccWeightErrorDown_ = diLepCorrectedWeight* 1/muIsoEff_ * 1/muRecoEff_ *(1-effDown(muAccEff_,muAccEffError_))/(effDown(muAccEff_,muAccEffError_)) - muAccWeight_;
	muAccDown_ = diLepCorrectedWeight* 1 / muIsoEff_ * 1/ muRecoEff_ * (1 - effDown(muAccEff_,muAccEffError_ )) / effDown(muAccEff_,muAccEffError_ + muAccEff_*MuAccUncertaintyDown_ / 100);
	//		cout<<"muAccWeight_:"<<muAccWeight_ <<"+"<<muAccWeightErrorUp_<<"-"<<muAccWeightErrorDown_<<endl;
	
	muTotalWeight_ = muIsoWeight_ + muRecoWeight_ + muAccWeight_;
	totalMuons_ = diLepCorrectedWeight/ (muIsoEff_ * muRecoEff_ * muAccEff_);
	
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
	//totalWeightMTWDiLep_ = totalWeightMTW_ + (1-diLepCorrectionEff_)*WeightProducer *(1-diLepMuEff_)/diLepMuEff_ * (1-diLepElecEff_)/diLepElecEff_;
	totalWeightMTWDiLep_ = totalWeightMTW_ + (1-diLepCorrectionEff_)*WeightProducer *(1-diLepMuEff_)/diLepMuEff_ ;
	// Btag information prediction
	if(BTags==0)
	{
	  muIsoEffBTag_ = MuonIsoBTag0->GetBinContent(MuonIsoBTag0->GetXaxis()->FindBin(HT),MuonIsoBTag0->GetYaxis()->FindBin(MHT));    
	  muIsoEffError_= MuonIsoBTag0->GetBinError(MuonIsoBTag0->GetXaxis()->FindBin(HT),MuonIsoBTag0->GetYaxis()->FindBin(MHT));    
	  muRecoEffBTag_ = MuonRecoBTag0->GetBinContent(MuonRecoBTag0->GetXaxis()->FindBin(HT),MuonRecoBTag0->GetYaxis()->FindBin(MHT));    
	  muRecoEffError_= MuonRecoBTag0->GetBinError(MuonRecoBTag0->GetXaxis()->FindBin(HT),MuonRecoBTag0->GetYaxis()->FindBin(MHT));   
	  
	  elecIsoEffBTag_ = ElecIsoBTag0->GetBinContent(ElecIsoBTag0->GetXaxis()->FindBin(HT),ElecIsoBTag0->GetYaxis()->FindBin(MHT));    
	  elecIsoEffError_= ElecIsoBTag0->GetBinError(ElecIsoBTag0->GetXaxis()->FindBin(HT),ElecIsoBTag0->GetYaxis()->FindBin(MHT));    
	  elecRecoEffBTag_ = ElecRecoBTag0->GetBinContent(ElecRecoBTag0->GetXaxis()->FindBin(HT),ElecRecoBTag0->GetYaxis()->FindBin(MHT));    
	  elecRecoEffError_= ElecRecoBTag0->GetBinError(ElecRecoBTag0->GetXaxis()->FindBin(HT),ElecRecoBTag0->GetYaxis()->FindBin(MHT));   
	}
	if(BTags==1)
	{
	  muIsoEffBTag_ = MuonIsoBTag1->GetBinContent(MuonIsoBTag1->GetXaxis()->FindBin(HT),MuonIsoBTag1->GetYaxis()->FindBin(MHT));    
	  muIsoEffError_= MuonIsoBTag1->GetBinError(MuonIsoBTag1->GetXaxis()->FindBin(HT),MuonIsoBTag1->GetYaxis()->FindBin(MHT));    
	  muRecoEffBTag_ = MuonRecoBTag1->GetBinContent(MuonRecoBTag1->GetXaxis()->FindBin(HT),MuonRecoBTag1->GetYaxis()->FindBin(MHT));    
	  muRecoEffError_= MuonRecoBTag1->GetBinError(MuonRecoBTag1->GetXaxis()->FindBin(HT),MuonRecoBTag1->GetYaxis()->FindBin(MHT));   
	  
	  elecIsoEffBTag_ = ElecIsoBTag1->GetBinContent(ElecIsoBTag1->GetXaxis()->FindBin(HT),ElecIsoBTag1->GetYaxis()->FindBin(MHT));    
	  elecIsoEffError_= ElecIsoBTag1->GetBinError(ElecIsoBTag1->GetXaxis()->FindBin(HT),ElecIsoBTag1->GetYaxis()->FindBin(MHT));    
	  elecRecoEffBTag_ = ElecRecoBTag1->GetBinContent(ElecRecoBTag1->GetXaxis()->FindBin(HT),ElecRecoBTag1->GetYaxis()->FindBin(MHT));    
	  elecRecoEffError_= ElecRecoBTag1->GetBinError(ElecRecoBTag1->GetXaxis()->FindBin(HT),ElecRecoBTag1->GetYaxis()->FindBin(MHT));   
	}
	if(BTags>=2)
	{
	  muIsoEffBTag_ = MuonIsoBTag2ToInf->GetBinContent(MuonIsoBTag2ToInf->GetXaxis()->FindBin(HT),MuonIsoBTag2ToInf->GetYaxis()->FindBin(MHT));    
	  muIsoEffError_= MuonIsoBTag2ToInf->GetBinError(MuonIsoBTag2ToInf->GetXaxis()->FindBin(HT),MuonIsoBTag2ToInf->GetYaxis()->FindBin(MHT));    
	  muRecoEffBTag_ = MuonRecoBTag2ToInf->GetBinContent(MuonRecoBTag2ToInf->GetXaxis()->FindBin(HT),MuonRecoBTag2ToInf->GetYaxis()->FindBin(MHT));    
	  muRecoEffError_= MuonRecoBTag2ToInf->GetBinError(MuonRecoBTag2ToInf->GetXaxis()->FindBin(HT),MuonRecoBTag2ToInf->GetYaxis()->FindBin(MHT));   
	  
	  elecIsoEffBTag_ = ElecIsoBTag2ToInf->GetBinContent(ElecIsoBTag2ToInf->GetXaxis()->FindBin(HT),ElecIsoBTag2ToInf->GetYaxis()->FindBin(MHT));    
	  elecIsoEffError_= ElecIsoBTag2ToInf->GetBinError(ElecIsoBTag2ToInf->GetXaxis()->FindBin(HT),ElecIsoBTag2ToInf->GetYaxis()->FindBin(MHT));    
	  elecRecoEffBTag_ = ElecRecoBTag2ToInf->GetBinContent(ElecRecoBTag2ToInf->GetXaxis()->FindBin(HT),ElecRecoBTag2ToInf->GetYaxis()->FindBin(MHT));    
	  elecRecoEffError_= ElecRecoBTag2ToInf->GetBinError(ElecRecoBTag2ToInf->GetXaxis()->FindBin(HT),ElecRecoBTag2ToInf->GetYaxis()->FindBin(MHT));   
	}
	if(muIsoEffErrorBTag_ + muIsoEffBTag_ >1.00) muIsoEffErrorBTag_ = (1 - muIsoEffBTag_)*0.5;
	if(muRecoEffErrorBTag_ + muRecoEffBTag_ >1.00) muRecoEffErrorBTag_ = (1 - muRecoEffBTag_)*0.5;
	if(elecIsoEffErrorBTag_ + elecIsoEffBTag_ >1.00) elecIsoEffErrorBTag_ = (1 - elecIsoEffBTag_)*0.5;
	if(elecRecoEffErrorBTag_ + elecRecoEffBTag_ >1.00) elecRecoEffErrorBTag_ = (1 - elecRecoEffBTag_)*0.5;
	//acceptance
	muAccEffBTag_ = MuonAccBTag->GetBinContent(MuonAccBTag->GetXaxis()->FindBin(MHT),MuonAccBTag->GetYaxis()->FindBin(BTags+0.01) );
	muAccEffErrorBTag_ = MuonAccBTag->GetBinError(MuonAccBTag->GetXaxis()->FindBin(MHT),MuonAccBTag->GetYaxis()->FindBin(BTags+0.01) );
	if(muAccEffErrorBTag_ + muAccEffBTag_ >1.00) muAccEffErrorBTag_ = .95 - muAccEffBTag_;
	elecAccEffBTag_ = ElecAccBTag->GetBinContent(ElecAccBTag->GetXaxis()->FindBin(MHT),ElecAccBTag->GetYaxis()->FindBin(BTags+0.01) );
	elecAccEffErrorBTag_ = ElecAccBTag->GetBinError(ElecAccBTag->GetXaxis()->FindBin(MHT),ElecAccBTag->GetYaxis()->FindBin(BTags+0.01) );
	if(elecAccEffErrorBTag_ + elecAccEffBTag_ >1.00) elecAccEffErrorBTag_ = .95 - elecAccEffBTag_;
	// di lepton depends on NJETS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if(applyDiLepCorrection_)
	{
	  diLepCorrectionEffBTag_ = MuDiLepMTW_->GetBinContent(MuDiLepMTW_->GetXaxis()->FindBin(MHT),MuDiLepMTW_->GetYaxis()->FindBin(NJets+0.01));
	  diLepCorrectionEffErrorBTag_ = MuDiLepMTW_->GetBinError(MuDiLepMTW_->GetXaxis()->FindBin(MHT),MuDiLepMTW_->GetYaxis()->FindBin(NJets+0.01));
	  diLepMuEffBTag_ = MuDiLepEff_->GetBinContent(MuDiLepEff_->GetXaxis()->FindBin(NJets+0.01));
	  diLepMuEffErrorBTag_ = MuDiLepEff_->GetBinError(MuDiLepEff_->GetXaxis()->FindBin(NJets+0.01));
	  diLepElecEffBTag_ = ElecDiLepEff_->GetBinContent(ElecDiLepEff_->GetXaxis()->FindBin(NJets+0.01));
	  diLepElecEffErrorBTag_ = ElecDiLepEff_->GetBinError(ElecDiLepEff_->GetXaxis()->FindBin(NJets+0.01));
	}
	if(applyDiLepCorrection_)
	{
	  diLepCorrectedWeight = WeightProducer * diLepCorrectionEffBTag_;
	}
	// muon iso weight & uncertaint
	muIsoWeightBTag_ = diLepCorrectedWeight* (1 - muIsoEffBTag_)/muIsoEffBTag_;	
	muIsoWeightErrorUpBTag_ = muIsoWeightBTag_ - diLepCorrectedWeight* (1 - effUp(muIsoEffBTag_, muIsoEffErrorBTag_))/ (effUp(muIsoEffBTag_, muIsoEffErrorBTag_));
	muIsoWeightErrorDownBTag_ = diLepCorrectedWeight* (1 - effDown(muIsoEffBTag_, muIsoEffErrorBTag_))/ (effDown(muIsoEffBTag_, muIsoEffErrorBTag_)) - muIsoWeightBTag_;
	//		cout<<"muIsoWeightBTag_:"<<muIsoWeightBTag_ <<"+"<<muIsoWeightErrorUpBTag_<<"-"<<muIsoWeightErrorDownBTag_<<endl;
	// muon reco weight & uncertainty
	muRecoWeightBTag_ = diLepCorrectedWeight* 1 / muIsoEffBTag_ * (1-muRecoEffBTag_)/muRecoEffBTag_;
	muRecoWeightErrorUpBTag_ = muRecoWeightBTag_ - diLepCorrectedWeight* 1 / muIsoEffBTag_ * (1-effUp(muRecoEffBTag_, muRecoEffErrorBTag_))/(effUp(muRecoEffBTag_, muRecoEffErrorBTag_));
	muRecoWeightErrorDownBTag_ = diLepCorrectedWeight* 1 / muIsoEffBTag_ * (1-effDown(muRecoEffBTag_, muRecoEffErrorBTag_))/(effDown(muRecoEffBTag_, muRecoEffErrorBTag_))- muRecoWeightBTag_;
	//		cout<<"muRecoWeightBTag_:"<<muRecoWeightBTag_ <<"+"<<muRecoWeightErrorUpBTag_<<"-"<<muRecoWeightErrorDownBTag_<<endl;
	// muon acc weight & uncertainty
	muAccWeightBTag_ = diLepCorrectedWeight* 1/muIsoEffBTag_ * 1/muRecoEffBTag_ *(1-muAccEffBTag_)/muAccEffBTag_;
	muAccWeightErrorUpBTag_ = muAccWeightBTag_ - diLepCorrectedWeight* 1/muIsoEffBTag_ * 1/muRecoEffBTag_ *(1-effUp(muAccEffBTag_,muAccEffErrorBTag_))/(effUp(muAccEffBTag_,muAccEffErrorBTag_));
	muAccUpBTag_ = diLepCorrectedWeight* 1 / muIsoEffBTag_ * 1/ muRecoEffBTag_ * (1 - effUp(muAccEffBTag_,muAccEffErrorBTag_ )) / effUp(muAccEffBTag_,muAccEffErrorBTag_ );
	muAccWeightErrorDownBTag_ = diLepCorrectedWeight* 1/muIsoEffBTag_ * 1/muRecoEffBTag_ *(1-effDown(muAccEffBTag_,muAccEffErrorBTag_))/(effDown(muAccEffBTag_,muAccEffErrorBTag_)) - muAccWeightBTag_;
	muAccDownBTag_ = diLepCorrectedWeight* 1 / muIsoEffBTag_ * 1/ muRecoEffBTag_ * (1 - effDown(muAccEffBTag_,muAccEffErrorBTag_ )) / effDown(muAccEffBTag_,muAccEffErrorBTag_ + muAccEffBTag_*muAccWeightErrorDownBTag_ / 100);
	//		cout<<"muAccWeightBTag_:"<<muAccWeightBTag_ <<"+"<<muAccWeightErrorUpBTag_<<"-"<<muAccWeightErrorDownBTag_<<endl;
	
	muTotalWeightBTag_ = muIsoWeightBTag_ + muRecoWeightBTag_ + muAccWeightBTag_;
	totalMuonsBTag_ = diLepCorrectedWeight/ (muIsoEffBTag_ * muRecoEffBTag_ * muAccEffBTag_);
	
	// elec acc weight & uncertainty
	elecAccWeightBTag_ = totalMuonsBTag_ * (1 - elecAccEffBTag_);
	elecAccWeightErrorUpBTag_ = elecAccWeightBTag_ - totalMuonsBTag_ * (1 - effUp(elecAccEffBTag_,elecAccEffErrorBTag_));
	elecAccUpBTag_ = totalMuonsBTag_ * (1- effUp(elecAccEffBTag_, elecAccEffErrorBTag_) ) ;
	elecAccWeightErrorDownBTag_ =  totalMuonsBTag_ * (1 - effDown(elecAccEffBTag_,elecAccEffErrorBTag_)) - elecAccWeightBTag_;
	elecAccDownBTag_ = totalMuonsBTag_ * (1- effDown(elecAccEffBTag_, elecAccEffErrorBTag_) ) ;
	//		cout<<"ElecAcc:"<<elecAccWeightBTag_ <<"+"<<elecAccWeightErrorUpBTag_<<"-"<<elecAccWeightErrorDownBTag_<<endl;
	// elec reco weight & uncertainty
	elecRecoWeightBTag_ = totalMuonsBTag_ * (elecAccEffBTag_) * (1 - elecRecoEffBTag_);
	elecRecoWeightErrorUpBTag_ = elecRecoWeightBTag_ - totalMuonsBTag_ * (elecAccEffBTag_) * (1 - effUp(elecRecoEffBTag_,elecRecoEffErrorBTag_)) ;
	elecRecoWeightErrorDownBTag_ =  totalMuonsBTag_ * (elecAccEffBTag_) * (1 - effDown(elecRecoEffBTag_,elecRecoEffErrorBTag_)) - elecRecoWeightBTag_;
	//		cout<<"ElecReco:"<<elecRecoWeightBTag_ <<"+"<<elecRecoWeightErrorUpBTag_<<"-"<<elecRecoWeightErrorDownBTag_<<endl;
	// elec iso weight & uncertainty
	elecIsoWeightBTag_ = totalMuonsBTag_ * (elecAccEffBTag_) * (elecRecoEffBTag_) * (1 - elecIsoEffBTag_) ;
	elecIsoWeightErrorUpBTag_ = elecIsoWeightBTag_ - totalMuonsBTag_ * (elecAccEffBTag_) * elecRecoEffBTag_ * (1 - effUp(elecIsoEffBTag_,elecIsoEffErrorBTag_)) ;
	elecIsoWeightErrorDownBTag_ = totalMuonsBTag_ * (elecAccEffBTag_) * elecRecoEffBTag_ * (1 - effDown(elecIsoEffBTag_,elecIsoEffErrorBTag_)) - elecIsoWeightBTag_;
	//		cout<<"ElecIso:"<<elecIsoWeightBTag_ <<"+"<<elecIsoWeightErrorUpBTag_<<"-"<<elecIsoWeightErrorDownBTag_<<endl;
	
	elecTotalWeightBTag_ = elecAccWeightBTag_ + elecRecoWeightBTag_ + elecIsoWeightBTag_;
	totalWeightBTag_ = muTotalWeightBTag_ + elecTotalWeightBTag_;
	
	// MTW cut and uncertainty
	MTWBinX = MuMTWMHTBTag->GetXaxis()->FindBin(BTags+0.01);
	if(MTWBinX > MuMTWMHTBTag->GetXaxis()->GetNbins() )
	{
	  MTWBinX=MTWBinX-1;
	  cout<<"MTWBinX btag out of range:"<<MuMTWMHTBTag->GetXaxis()->GetNbins() <<", was "<<MuMTWMHTBTag->GetXaxis()->FindBin(BTags+0.01)<<", set to"<<MTWBinX<<endl;
	}
	MTWBinY = MuMTWMHTBTag->GetYaxis()->FindBin(MHT);
	if(MTWBinY>MuMTWMHTBTag->GetYaxis()->GetNbins() )
	{
	  MTWBinY=MTWBinY-1;
	  cout<<"MTWBinY out of range:"<<MuMTWMHTBTag->GetYaxis()->GetNbins() <<", was "<<MuMTWMHTBTag->GetYaxis()->FindBin(MHT)<<", set to"<<MTWBinY<<endl;
	}
	totalWeightMTWBTag_ = totalWeightBTag_ / MuMTWMHTBTag->GetBinContent(MTWBinX,MTWBinY);
	totalMuonsMTWBTag_= totalMuonsBTag_ / MuMTWMHTBTag->GetBinContent(MTWBinX,MTWBinY);
//	totalWeightMTWDiLepBTag_ = totalWeightMTWBTag_ + (1-diLepCorrectionEffBTag_)*WeightProducer *(1-diLepMuEffBTag_)/diLepMuEffBTag_ * (1-diLepElecEffBTag_)/diLepElecEffBTag_;
	totalWeightMTWDiLepBTag_ = totalWeightMTWBTag_ + (1-diLepCorrectionEff_)*WeightProducer *(1-diLepMuEff_)/diLepMuEff_ ;
	
	tPrediction_->Fill();
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
   TFile *outPutFile = new TFile("Prediction.root","RECREATE"); ;
   outPutFile->cd();
   tPrediction_->Write();

}
void Prediction::resetValues()
{
	deltaRGenToRecoIsoMuon_=0.;
	diffPtGenToRecoIsoMuon_=0.;
	Matched_=0;
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
	diLepCorrectionEff_=0.;
	diLepCorrectionEffError_=0.;
	diLepMuEff_=0.;
	diLepMuEffError_=0.;
	diLepElecEff_=0.;
	diLepElecEffError_=0.;
	totalWeightMTWDiLep_=0.;
	
	muIsoEffBTag_=0;
	muIsoEffErrorBTag_=0;
	muIsoWeightBTag_=0;
	muIsoWeightErrorUpBTag_=0;
	muIsoWeightErrorDownBTag_=0;
	muRecoEffBTag_=0;
	muRecoEffErrorBTag_=0;
	muRecoWeightBTag_=0;	
	muRecoWeightErrorUpBTag_=0;
	muRecoWeightErrorDownBTag_=0;
	muAccEffBTag_=0;
	muAccEffErrorBTag_=0;
	muAccWeightBTag_=0;
	muAccWeightErrorUpBTag_=0;	
	muAccWeightErrorDownBTag_=0;	
	
	elecIsoEffBTag_=0;
	elecIsoEffErrorBTag_=0;
	elecIsoWeightBTag_=0;
	elecIsoWeightErrorUpBTag_=0;
	elecIsoWeightErrorDownBTag_=0;
	elecRecoEffBTag_=0;
	elecRecoEffErrorBTag_=0;
	elecRecoWeightBTag_=0;	
	elecRecoWeightErrorUpBTag_=0;
	elecRecoWeightErrorDownBTag_=0;
	elecAccEffBTag_=0;
	elecAccEffErrorBTag_=0;
	elecAccWeightBTag_=0;
	elecAccWeightErrorUpBTag_=0;	
	elecAccWeightErrorDownBTag_=0;	
	diLepCorrectionEffBTag_=0.;
	diLepCorrectionEffErrorBTag_=0.;
	diLepMuEffBTag_=0.;
	diLepMuEffErrorBTag_=0.;
	diLepElecEffBTag_=0.;
	diLepElecEffErrorBTag_=0.;
	totalWeightMTWDiLepBTag_=0.;
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
