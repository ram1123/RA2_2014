#include <TChain.h>
#include "TProofServ.h"
#include "TProof.h"
//#include "EffMaker.h"
void MakePrediction()
{
	//TString connect = gSystem->GetFromPipe("pod-info -c");
	//TProof *proof = TProof::Open("adraeger@nafhh-cms03.desy.de:21001");
  	TProof *proof = TProof::Open("workers=20");
	//TProof *proof = TProof::Open("");
	//TProof *proof = TProof::Open(connect);
	// analyse the trees
	TChain *Effchain = new TChain("TreeMaker2/PreSelection");
	Effchain->Add("/nfs/dust/cms/user/adraeger/phys14/mc/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/*root");
	Effchain->Add("/nfs/dust/cms/user/adraeger/phys14/mc/WJetsToLNu_HT-200to400/*root");
	Effchain->Add("/nfs/dust/cms/user/adraeger/phys14/mc/WJetsToLNu_HT-400to600/*root");
	Effchain->Add("/nfs/dust/cms/user/adraeger/phys14/mc/WJetsToLNu_HT-600toInf/*root");
//   	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauolaPU20bx25_V5-v2/*.root");
//   	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/WJetsToLNu_HT-200to400/*root");
//    	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/WJetsToLNu_HT-400to600/*root");
//    	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/WJetsToLNu_HT-600toInf/*root");
	//	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/QCD_Pt-470to600_Tune4C_13TeV_pythia8_PU20bx25_POSTLS170_V5-v1/*.root");
// 		Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/signal/25ns20PU.SMS-T1bbbb_2J_mGl-1000_mLSP-900*root");
//  	       Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/signal/25ns20PU.SMS-T1bbbb_2J_mGl-1500_mLSP-100*root");
// 		Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/signal/25ns20PU.SMS-T1qqqq_2J_mGl-1000_mLSP-800*root");	
	//	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/signal/25ns20PU.SMS-T1qqqq_2J_mGl-1400_mLSP-100*root");
	//	Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/signal/25ns20PU.SMS-T1tttt_2J_mGl-1200_mLSP-800*root");
// 		Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/signal/25ns20PU.SMS-T1tttt_2J_mGl-1500_mLSP-100*root");
  	Effchain->SetProof();
	//	Effchain->Process("EffMaker.C+g",0,800000);
	Effchain->Process("Prediction.C+");
	//Effchain->Process("EffMaker.C+",0,800000);
  	Effchain->SetProof(0);
  	delete proof;
}
