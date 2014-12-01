//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Nov 22 22:34:19 2014 by ROOT version 5.34/14
// from TTree LostLeptonPrediction/a simple Tree with simple variables
// found on file: Prediction.root
//////////////////////////////////////////////////////////

#ifndef FlexPrediction_h
#define FlexPrediction_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "iostream"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxmuAccWeight = 1;
const Int_t kMaxmuAccWeightBTagBTag = 1;

class FlexPrediction {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Bool_t          MatchedToGenMuonExDiLep;
   Float_t         HT;
   Float_t         MHT;
   UShort_t        NJets;
   UShort_t        BTags;
   UShort_t        NVtx;
   Float_t         DeltaPhi1;
   Float_t         DeltaPhi2;
   Float_t         DeltaPhi3;
   Float_t         WeightProducer;
   Float_t         METPt;
   Float_t         METEta;
   Float_t         METPhi;
   UShort_t        RecoIsoMuonNum;
   Float_t         RecoIsoMuonPt[1];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonEta[1];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonPhi[1];   //[RecoIsoMuonNum]
   Float_t         RecoIsoMuonE[1];   //[RecoIsoMuonNum]
   UShort_t        RecoIsoElecNum;
   Float_t         RecoIsoElecPt[1];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecEta[1];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecPhi[1];   //[RecoIsoElecNum]
   Float_t         RecoIsoElecE[1];   //[RecoIsoElecNum]
   Float_t         MTW;
   Bool_t          applyDiLepCorrection;
   Float_t         totalPrediction;
   Float_t         totalPredictionMTW;
   Float_t         totalWeightMTWDiLep;
   Float_t         muIsoWeight;
   Float_t         muIsoWeightErrorUp;
   Float_t         muIsoWeightErrorDown;
   Float_t         muRecoWeight;
   Float_t         muRecoWeightErrorUp;
   Float_t         muRecoWeightErrorDown;
   Float_t         muAccWeight;
   Float_t         muAccWeightErrorUp;
   Float_t         muAccWeightErrorDown;
   Float_t         muTotalWeight;
   Float_t         muIsoEff;
   Float_t         muRecoEff;
   Float_t         muAccEff;
   Float_t         totalMuons;
   Float_t         elecIsoWeight;
   Float_t         elecIsoWeightErrorUp;
   Float_t         elecIsoWeightErrorDown;
   Float_t         elecRecoWeight;
   Float_t         elecRecoWeightErrorUp;
   Float_t         elecRecoWeightErrorDown;
   Float_t         elecAccWeight;
   Float_t         elecAccWeightErrorUp;
   Float_t         elecAccWeightErrorDown;
   Float_t         elecTotalWeight;
   Float_t         elecIsoEff;
   Float_t         elecRecoEff;
   Float_t         elecAccEff;
   Float_t         diLepCorrectionEff;
   Float_t         diLepCorrectionEffErro_;
   Float_t         diLepMuEff;
   Float_t         diLepMuEffError;
   Float_t         diLepElecEff;
   Float_t         diLepElecEffError;
   Float_t         totalPredictionBTag;
   Float_t         totalPredictionMTWBTag;
   Float_t         totalWeightMTWDiLepBTag;
   Float_t         muIsoWeightBTag;
   Float_t         muIsoWeightErrorUpBTag;
   Float_t         muIsoWeightErrorDownBTag;
   Float_t         muRecoWeightBTag;
   Float_t         muRecoWeightErrorUpBTag;
   Float_t         muRecoWeightErrorDownBTag;
   Float_t         muAccWeightBTag;
   Float_t         muAccWeightErrorUpBTag;
   Float_t         muAccWeightErrorDownBTag;
   Float_t         muTotalWeightBTag;
   Float_t         muIsoEffBTag;
   Float_t         muRecoEffBTag;
   Float_t         muAccEffBTag;
   Float_t         totalMuonsBTag;
   Float_t         elecIsoWeightBTag;
   Float_t         elecIsoWeightErrorUpBTag;
   Float_t         elecIsoWeightErrorDownBTag;
   Float_t         elecRecoWeightBTag;
   Float_t         elecRecoWeightErrorUpBTag;
   Float_t         elecRecoWeightErrorDownBTag;
   Float_t         elecAccWeightBTag;
   Float_t         elecAccWeightErrorUpBTag;
   Float_t         elecAccWeightErrorDownBTag;
   Float_t         elecTotalWeightBTag;
   Float_t         elecIsoEffBTag;
   Float_t         elecRecoEffBTag;
   Float_t         elecAccEffBTag;

   // List of branches
   TBranch        *b_MatchedToGenMuonExDiLep;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_BTags;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_DeltaPhi1;   //!
   TBranch        *b_DeltaPhi2;   //!
   TBranch        *b_DeltaPhi3;   //!
   TBranch        *b_WeightProducer;   //!
   TBranch        *b_METPt;   //!
   TBranch        *b_METEta;   //!
   TBranch        *b_METPhi;   //!
   TBranch        *b_RecoIsoMuonNum;   //!
   TBranch        *b_RecoIsoMuonPt;   //!
   TBranch        *b_RecoIsoMuonEta;   //!
   TBranch        *b_RecoIsoMuonPhi;   //!
   TBranch        *b_RecoIsoMuonE;   //!
   TBranch        *b_RecoIsoElecNum;   //!
   TBranch        *b_RecoIsoElecPt;   //!
   TBranch        *b_RecoIsoElecEta;   //!
   TBranch        *b_RecoIsoElecPhi;   //!
   TBranch        *b_RecoIsoElecE;   //!
   TBranch        *b_MTW;   //!
   TBranch        *b_applyDiLepCorrection;   //!
   TBranch        *b_totalPrediction;   //!
   TBranch        *b_totalPredictionMTW;   //!
   TBranch        *b_totalWeightMTWDiLep;   //!
   TBranch        *b_muIsoWeight;   //!
   TBranch        *b_muIsoWeightErrorUp;   //!
   TBranch        *b_muIsoWeightErrorDown;   //!
   TBranch        *b_muRecoWeight;   //!
   TBranch        *b_muRecoWeightErrorUp;   //!
   TBranch        *b_muRecoWeightErrorDown;   //!
   TBranch        *b_muAccWeight_;   //!
   TBranch        *b_muAccWeightErrorUp;   //!
   TBranch        *b_muAccWeightErrorDown;   //!
   TBranch        *b_muTotalWeight;   //!
   TBranch        *b_muIsoEff;   //!
   TBranch        *b_muRecoEff;   //!
   TBranch        *b_muAccEff;   //!
   TBranch        *b_totalMuons;   //!
   TBranch        *b_elecIsoWeight;   //!
   TBranch        *b_elecIsoWeightErrorUp;   //!
   TBranch        *b_elecIsoWeightErrorDown;   //!
   TBranch        *b_elecRecoWeight;   //!
   TBranch        *b_elecRecoWeightErrorUp;   //!
   TBranch        *b_elecRecoWeightErrorDown;   //!
   TBranch        *b_elecAccWeight;   //!
   TBranch        *b_elecAccWeightErrorUp;   //!
   TBranch        *b_elecAccWeightErrorDown;   //!
   TBranch        *b_elecTotalWeight;   //!
   TBranch        *b_elecIsoEff;   //!
   TBranch        *b_elecRecoEff;   //!
   TBranch        *b_elecAccEff;   //!
   TBranch        *b_diLepCorrectionEff;   //!
   TBranch        *b_diLepCorrectionEffError;   //!
   TBranch        *b_diLepMuEff;   //!
   TBranch        *b_diLepMuEffError;   //!
   TBranch        *b_diLepElecEff;   //!
   TBranch        *b_diLepElecEffError;   //!
   TBranch        *b_totalPredictionBTag;   //!
   TBranch        *b_totalPredictionMTWBTag;   //!
   TBranch        *b_totalWeightMTWDiLepBTag;   //!
   TBranch        *b_muIsoWeightBTag;   //!
   TBranch        *b_muIsoWeightErrorUpBTag;   //!
   TBranch        *b_muIsoWeightErrorDownBTag;   //!
   TBranch        *b_muRecoWeightBTag;   //!
   TBranch        *b_muRecoWeightErrorUpBTag;   //!
   TBranch        *b_muRecoWeightErrorDownBTag;   //!
   TBranch        *b_muAccWeightBTagBTag_;   //!
   TBranch        *b_muAccWeightErrorUpBTag;   //!
   TBranch        *b_muAccWeightErrorDownBTag;   //!
   TBranch        *b_muTotalWeightBTag;   //!
   TBranch        *b_muIsoEffBTag;   //!
   TBranch        *b_muRecoEffBTag;   //!
   TBranch        *b_muAccEffBTag;   //!
   TBranch        *b_totalMuonsBTag;   //!
   TBranch        *b_elecIsoWeightBTag;   //!
   TBranch        *b_elecIsoWeightErrorUpBTag;   //!
   TBranch        *b_elecIsoWeightErrorDownBTag;   //!
   TBranch        *b_elecRecoWeightBTag;   //!
   TBranch        *b_elecRecoWeightErrorUpBTag;   //!
   TBranch        *b_elecRecoWeightErrorDownBTag;   //!
   TBranch        *b_elecAccWeightBTag;   //!
   TBranch        *b_elecAccWeightErrorUpBTag;   //!
   TBranch        *b_elecAccWeightErrorDownBTag;   //!
   TBranch        *b_elecTotalWeightBTag;   //!
   TBranch        *b_elecIsoEffBTag;   //!
   TBranch        *b_elecRecoEffBTag;   //!
   TBranch        *b_elecAccEffBTag;   //!

   FlexPrediction(TTree *tree=0);
   virtual ~FlexPrediction();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef FlexPrediction_cxx
FlexPrediction::FlexPrediction(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Prediction.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Prediction.root");
      }
      f->GetObject("LostLeptonPrediction",tree);

   }
   Init(tree);
}

FlexPrediction::~FlexPrediction()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t FlexPrediction::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t FlexPrediction::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void FlexPrediction::Init(TTree *tree)
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
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("MatchedToGenMuonExDiLep", &MatchedToGenMuonExDiLep, &b_MatchedToGenMuonExDiLep);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
   fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
   fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
   fChain->SetBranchAddress("WeightProducer", &WeightProducer, &b_WeightProducer);
   fChain->SetBranchAddress("METPt", &METPt, &b_METPt);
   fChain->SetBranchAddress("METEta", &METEta, &b_METEta);
   fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
   fChain->SetBranchAddress("RecoIsoMuonNum", &RecoIsoMuonNum, &b_RecoIsoMuonNum);
   fChain->SetBranchAddress("RecoIsoMuonPt", RecoIsoMuonPt, &b_RecoIsoMuonPt);
   fChain->SetBranchAddress("RecoIsoMuonEta", RecoIsoMuonEta, &b_RecoIsoMuonEta);
   fChain->SetBranchAddress("RecoIsoMuonPhi", RecoIsoMuonPhi, &b_RecoIsoMuonPhi);
   fChain->SetBranchAddress("RecoIsoMuonE", RecoIsoMuonE, &b_RecoIsoMuonE);
   fChain->SetBranchAddress("RecoIsoElecNum", &RecoIsoElecNum, &b_RecoIsoElecNum);
   fChain->SetBranchAddress("RecoIsoElecPt", &RecoIsoElecPt, &b_RecoIsoElecPt);
   fChain->SetBranchAddress("RecoIsoElecEta", &RecoIsoElecEta, &b_RecoIsoElecEta);
   fChain->SetBranchAddress("RecoIsoElecPhi", &RecoIsoElecPhi, &b_RecoIsoElecPhi);
   fChain->SetBranchAddress("RecoIsoElecE", &RecoIsoElecE, &b_RecoIsoElecE);
   fChain->SetBranchAddress("MTW", &MTW, &b_MTW);
   fChain->SetBranchAddress("applyDiLepCorrection", &applyDiLepCorrection, &b_applyDiLepCorrection);
   fChain->SetBranchAddress("totalPrediction", &totalPrediction, &b_totalPrediction);
   fChain->SetBranchAddress("totalPredictionMTW", &totalPredictionMTW, &b_totalPredictionMTW);
   fChain->SetBranchAddress("totalWeightMTWDiLep", &totalWeightMTWDiLep, &b_totalWeightMTWDiLep);
   fChain->SetBranchAddress("muIsoWeight", &muIsoWeight, &b_muIsoWeight);
   fChain->SetBranchAddress("muIsoWeightErrorUp", &muIsoWeightErrorUp, &b_muIsoWeightErrorUp);
   fChain->SetBranchAddress("muIsoWeightErrorDown", &muIsoWeightErrorDown, &b_muIsoWeightErrorDown);
   fChain->SetBranchAddress("muRecoWeight", &muRecoWeight, &b_muRecoWeight);
   fChain->SetBranchAddress("muRecoWeightErrorUp", &muRecoWeightErrorUp, &b_muRecoWeightErrorUp);
   fChain->SetBranchAddress("muRecoWeightErrorDown", &muRecoWeightErrorDown, &b_muRecoWeightErrorDown);
   fChain->SetBranchAddress("muAccWeight", &muAccWeight, &b_muAccWeight_);
   fChain->SetBranchAddress("muAccWeightErrorUp", &muAccWeightErrorUp, &b_muAccWeightErrorUp);
   fChain->SetBranchAddress("muAccWeightErrorDown", &muAccWeightErrorDown, &b_muAccWeightErrorDown);
   fChain->SetBranchAddress("muTotalWeight", &muTotalWeight, &b_muTotalWeight);
   fChain->SetBranchAddress("muIsoEff", &muIsoEff, &b_muIsoEff);
   fChain->SetBranchAddress("muRecoEff", &muRecoEff, &b_muRecoEff);
   fChain->SetBranchAddress("muAccEff", &muAccEff, &b_muAccEff);
   fChain->SetBranchAddress("totalMuons", &totalMuons, &b_totalMuons);
   fChain->SetBranchAddress("elecIsoWeight", &elecIsoWeight, &b_elecIsoWeight);
   fChain->SetBranchAddress("elecIsoWeightErrorUp", &elecIsoWeightErrorUp, &b_elecIsoWeightErrorUp);
   fChain->SetBranchAddress("elecIsoWeightErrorDown", &elecIsoWeightErrorDown, &b_elecIsoWeightErrorDown);
   fChain->SetBranchAddress("elecRecoWeight", &elecRecoWeight, &b_elecRecoWeight);
   fChain->SetBranchAddress("elecRecoWeightErrorUp", &elecRecoWeightErrorUp, &b_elecRecoWeightErrorUp);
   fChain->SetBranchAddress("elecRecoWeightErrorDown", &elecRecoWeightErrorDown, &b_elecRecoWeightErrorDown);
   fChain->SetBranchAddress("elecAccWeight", &elecAccWeight, &b_elecAccWeight);
   fChain->SetBranchAddress("elecAccWeightErrorUp", &elecAccWeightErrorUp, &b_elecAccWeightErrorUp);
   fChain->SetBranchAddress("elecAccWeightErrorDown", &elecAccWeightErrorDown, &b_elecAccWeightErrorDown);
   fChain->SetBranchAddress("elecTotalWeight", &elecTotalWeight, &b_elecTotalWeight);
   fChain->SetBranchAddress("elecIsoEff", &elecIsoEff, &b_elecIsoEff);
   fChain->SetBranchAddress("elecRecoEff", &elecRecoEff, &b_elecRecoEff);
   fChain->SetBranchAddress("elecAccEff", &elecAccEff, &b_elecAccEff);
   fChain->SetBranchAddress("diLepCorrectionEff", &diLepCorrectionEff, &b_diLepCorrectionEff);
   fChain->SetBranchAddress("diLepCorrectionEffErro_", &diLepCorrectionEffErro_, &b_diLepCorrectionEffError);
   fChain->SetBranchAddress("diLepMuEff", &diLepMuEff, &b_diLepMuEff);
   fChain->SetBranchAddress("diLepMuEffError", &diLepMuEffError, &b_diLepMuEffError);
   fChain->SetBranchAddress("diLepElecEff", &diLepElecEff, &b_diLepElecEff);
   fChain->SetBranchAddress("diLepElecEffError", &diLepElecEffError, &b_diLepElecEffError);
   fChain->SetBranchAddress("totalPredictionBTag", &totalPredictionBTag, &b_totalPredictionBTag);
   fChain->SetBranchAddress("totalPredictionMTWBTag", &totalPredictionMTWBTag, &b_totalPredictionMTWBTag);
   fChain->SetBranchAddress("totalWeightMTWDiLepBTag", &totalWeightMTWDiLepBTag, &b_totalWeightMTWDiLepBTag);
   fChain->SetBranchAddress("muIsoWeightBTag", &muIsoWeightBTag, &b_muIsoWeightBTag);
   fChain->SetBranchAddress("muIsoWeightErrorUpBTag", &muIsoWeightErrorUpBTag, &b_muIsoWeightErrorUpBTag);
   fChain->SetBranchAddress("muIsoWeightErrorDownBTag", &muIsoWeightErrorDownBTag, &b_muIsoWeightErrorDownBTag);
   fChain->SetBranchAddress("muRecoWeightBTag", &muRecoWeightBTag, &b_muRecoWeightBTag);
   fChain->SetBranchAddress("muRecoWeightErrorUpBTag", &muRecoWeightErrorUpBTag, &b_muRecoWeightErrorUpBTag);
   fChain->SetBranchAddress("muRecoWeightErrorDownBTag", &muRecoWeightErrorDownBTag, &b_muRecoWeightErrorDownBTag);
   fChain->SetBranchAddress("muAccWeightBTag", &muAccWeightBTag, &b_muAccWeightBTagBTag_);
   fChain->SetBranchAddress("muAccWeightErrorUpBTag", &muAccWeightErrorUpBTag, &b_muAccWeightErrorUpBTag);
   fChain->SetBranchAddress("muAccWeightErrorDownBTag", &muAccWeightErrorDownBTag, &b_muAccWeightErrorDownBTag);
   fChain->SetBranchAddress("muTotalWeightBTag", &muTotalWeightBTag, &b_muTotalWeightBTag);
   fChain->SetBranchAddress("muIsoEffBTag", &muIsoEffBTag, &b_muIsoEffBTag);
   fChain->SetBranchAddress("muRecoEffBTag", &muRecoEffBTag, &b_muRecoEffBTag);
   fChain->SetBranchAddress("muAccEffBTag", &muAccEffBTag, &b_muAccEffBTag);
   fChain->SetBranchAddress("totalMuonsBTag", &totalMuonsBTag, &b_totalMuonsBTag);
   fChain->SetBranchAddress("elecIsoWeightBTag", &elecIsoWeightBTag, &b_elecIsoWeightBTag);
   fChain->SetBranchAddress("elecIsoWeightErrorUpBTag", &elecIsoWeightErrorUpBTag, &b_elecIsoWeightErrorUpBTag);
   fChain->SetBranchAddress("elecIsoWeightErrorDownBTag", &elecIsoWeightErrorDownBTag, &b_elecIsoWeightErrorDownBTag);
   fChain->SetBranchAddress("elecRecoWeightBTag", &elecRecoWeightBTag, &b_elecRecoWeightBTag);
   fChain->SetBranchAddress("elecRecoWeightErrorUpBTag", &elecRecoWeightErrorUpBTag, &b_elecRecoWeightErrorUpBTag);
   fChain->SetBranchAddress("elecRecoWeightErrorDownBTag", &elecRecoWeightErrorDownBTag, &b_elecRecoWeightErrorDownBTag);
   fChain->SetBranchAddress("elecAccWeightBTag", &elecAccWeightBTag, &b_elecAccWeightBTag);
   fChain->SetBranchAddress("elecAccWeightErrorUpBTag", &elecAccWeightErrorUpBTag, &b_elecAccWeightErrorUpBTag);
   fChain->SetBranchAddress("elecAccWeightErrorDownBTag", &elecAccWeightErrorDownBTag, &b_elecAccWeightErrorDownBTag);
   fChain->SetBranchAddress("elecTotalWeightBTag", &elecTotalWeightBTag, &b_elecTotalWeightBTag);
   fChain->SetBranchAddress("elecIsoEffBTag", &elecIsoEffBTag, &b_elecIsoEffBTag);
   fChain->SetBranchAddress("elecRecoEffBTag", &elecRecoEffBTag, &b_elecRecoEffBTag);
   fChain->SetBranchAddress("elecAccEffBTag", &elecAccEffBTag, &b_elecAccEffBTag);
   Notify();
}

Bool_t FlexPrediction::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void FlexPrediction::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t FlexPrediction::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef FlexPrediction_cxx
