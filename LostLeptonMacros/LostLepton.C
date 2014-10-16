#include <TH2F.h>
#include <TFile.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <iostream>
#include "TStyle.h"
#include <ostream>
#include <fstream> 
#include <string.h>
#include <TTree.h>
#include <TH1.h>
#include <TH3.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TMath.h>
#include <TF1.h>
#include <stdio.h>
#include "TROOT.h"
#include "TMinuit.h"
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "Fit/Fitter.h"
#include "Fit/BinData.h"
#include "Fit/Chi2FCN.h"
#include "TH1.h"
#include "TH2F.h"
#include "TList.h"
#include "Math/WrappedMultiTF1.h"
#include "Math/FitMethodFunction.h"
#include "HFitInterface.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TList.h"
#include "TROOT.h"
#include "TProofServ.h"
#include "TProof.h"


#include "GlobalVars.h"
#include "EffMaker.h"
void LostLepton()
{
	// basic setup output
	ofstream *textOutPut = new ofstream;
	textOutPut->open("LostLeptonLogFile.txt");
	textOutPut->close();	
	delete textOutPut;
	llLogFile_ = new fstream("LostLeptonLogFile.txt");
	*llLogFile_ <<"------------------------------------------------------------------------------------------------------------------------------------\n";
	*llLogFile_ <<"-----------------------------------------LostLepton results and error report--------------------------------------------------------\n";
	*llLogFile_ <<"------------------------------------------------------------------------------------------------------------------------------------\n\n";
	// trees to analyse
	toBeProcessedEvents_= 1.0; // in percent use this value to determine how much of the samples you want to process! 1.00 = 100%
	saveCutsToFile(llLogFile_);
	outPutFileName_ = "LostLepton.root";
	outPutFile_ = new TFile(outPutFileName_,"RECREATE");
	// analyse the trees
	TProof *proof = TProof::Open("workers=8");
	//TProof *proof = TProof::Open();
	TChain *Effchain = new TChain("RA2TreeMaker2/RA2PreSelection");
	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauolaPU20bx250_V5-v2/*.root");
	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/WJetsToLNu_HT-200to400/*root");
	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/WJetsToLNu_HT-400to600/*root");
	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/WJetsToLNu_HT-600toInf/*root");
	
	//Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/WJetsToLNu*/*.root");
	Effchain->SetProof(proof);
	// run the selector
	Effchain->Process("EffMaker.C+");
	Effchain->SetProof(0);
	delete proof;
	// print out report file
	std::cout<<"Processing done finishing macro"<<std::endl;
	if(llLogFile_->is_open())
	{
		*llLogFile_ <<"\n------------------------------------------------------------------------------------------------------------------------------------\n";
		*llLogFile_ <<"---------------------------------------------------LostLepton end------------------------------------------------------------------\n";
		*llLogFile_ <<"------------------------------------------------------------------------------------------------------------------------------------\n";
		llLogFile_->seekg(0,llLogFile_->beg);
		while (getline (*llLogFile_,line_)) cout<<line_<<endl;
	}
	else cout<<"File not opend output not printed out please see LostLeptonLogFile.txt file"<<std::endl;
	llLogFile_->close();
	delete llLogFile_;
	outPutFile_->Close();
}


void saveCutsToFile(fstream *llLogFile)
{
  *llLogFile <<"\n--------------------------------------------------------Basic cuts used---------------------------------------------------------------\n";
  *llLogFile <<"Min HT: "<<minHT_<<"\n";
  *llLogFile <<"Min MHT: "<<minMHT_<<"\n";
  *llLogFile <<"Min NJets: "<<minNJets_<<"\n";
  *llLogFile <<"Min deltaPhi1: "<<deltaPhi1_<<"\n";
  *llLogFile <<"Min deltaPhi2: "<<deltaPhi2_<<"\n";
  *llLogFile <<"Min deltaPhi3: "<<deltaPhi3_<<"\n";
  *llLogFile <<"Filters applied: "<<applyFilters_<<"\n";
  *llLogFile <<"\n---------------------------Lepton cuts-------------------------\n";
  *llLogFile <<"Min muon pT: "<<minMuPt_<<"\n";
  *llLogFile <<"Max muon eta: "<<maxMuEta_<<"\n";
  *llLogFile <<"Min electron pT: "<<minElecPt_<<"\n";
  *llLogFile <<"Max electron eta: "<<maxElecEta_<<"\n";
  *llLogFile <<"\n---------------------------Search and Efficiency bins-------------------------\n";
  *llLogFile <<"NJet: ["<<NjetLowLow_<<","<<NjetHighLow_<<","<<NjetLow0_<<","<<NjetHigh0_<<","<<NjetLow1_<<","<<NjetHigh1_<<","<<NjetLow2_<<","<<NjetHigh2_<<"]"<<"\n";
  *llLogFile <<"\n--------------------------------------------------------End---------------------------------------------------------------\n\n";
  
}
