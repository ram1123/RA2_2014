#define FlexPrediction_cxx
#include "FlexPrediction.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void FlexPrediction::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L FlexPrediction.C
//      Root > FlexPrediction t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
  std::cout<<"Loop started fChain: "<<fChain<<std::endl;
   if (fChain == 0) return;
   // store all necessary varaibles from tree in maps for UShort_t Float_t (more need to be implemented)
   // Float_t
   treeFloat_ts_["HT"]=&HT;
   treeFloat_ts_["MHT"]=&MHT;
   // UShort_t
   treeUShort_ts_["NJets"]=&NJets;

   
   Long64_t nentries = fChain->GetEntriesFast();
   double HTSum=0;
   double HTSumCheck=0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
   //   std::cout<<"HT: "<<HT<<", MHT: "<<MHT<<", NJets: "<<NJets<<std::endl;
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
     if(PerformeCut(cuts_))continue;
      HTSum+=HT;
      HTSumCheck+=*(treeFloat_ts_.find("HT")->second);
   }
   std::cout<<"Total HT: "<<HTSum<<std::endl;
   std::cout<<"Total HT: "<<HTSumCheck<<std::endl;
}
bool FlexPrediction::InitConfig(Config* config, fstream *textOutPut)
{
 bool result = true;
 *textOutPut <<"\n------------------------------------------------------------------------------------------------------------------\n";
 *textOutPut <<"----------------------------FlexPrediction::InitConfig started----------------------------------------------------\n";
 // load efficiency maps using the config file for defining the input TH2Fs
 // open file and folder
 std::map<std::string, std::string> efficienciesSharedValues = config->GetEfficiencySharedValues();
 std::map<std::string, std::string>::iterator itt;
 if(efficienciesSharedValues.find("FileName") !=efficienciesSharedValues.end() )
 { 
   itt=efficienciesSharedValues.find("FileName");
 }
 else 
 {
   std::cout<<"FlexPrediction:: Could not retrieve FileName. Please check config input file!! line expected with: FileName=blub.root";
   return (1);
 }
 tTemp_=  (std::string) itt->second;
 *textOutPut <<"Loading efficiencies from file: "<<tTemp_<<"\n";
 //std::cout<<"FileName: "<<tTemp_<<std::endl;
 TFile *effInput = new TFile(tTemp_,"OPEN");
 // open folder
 TDirectory *EffInputFolder;
 if(efficienciesSharedValues.find("Folder") !=efficienciesSharedValues.end() )
 { 
   itt=efficienciesSharedValues.find("Folder");
 }
 else 
 {
   std::cout<<"FlexPrediction:: Could not retrieve Folder. Please check config input file!! line expected with: Folder=Blub";
   return (1);
 }
 tTemp_=  (std::string) itt->second;
 *textOutPut <<"Loading efficiencies from folder: "<<tTemp_<<"\n";
 std::cout<<"Folder: "<<tTemp_<<std::endl;
 EffInputFolder =   (TDirectory*)effInput->Get(tTemp_);
 *textOutPut <<"List of efficiencies loaded: [Internale Name, Name as in file]\n";
 std::map<std::string, Efficiency*> efficiencies = config->GetEfficiencies();
 for (std::map<std::string, Efficiency*>::iterator it=efficiencies.begin(); it!=efficiencies.end(); ++it)
 {
   std::string sTemp = it->first;
   tTemp_=it->second->Name();
   *textOutPut <<"["<<sTemp<<","<<tTemp_<<"]\n";
   efficiencies_[sTemp]= (TH2F*)EffInputFolder->Get(tTemp_);
 }
 *textOutPut <<"------------------------------------------------------------------------------------------------------------------\n\n";
 *textOutPut <<"Loading cuts: \n";
 // loading cuts
 cuts_ = config->GetCuts();
 for (std::map<std::string, std::vector<Cuts*> >::iterator it=cuts_.begin(); it!=cuts_.end(); ++it)
 {
   *textOutPut <<it->second[0]->Variable()<<"("<<it->second[0]->VariableTyp()<<" isInt: "<<it->second[0]->isInt()<<")"<<" "<<it->second[0]->cutTyp()<<" "<<it->second[0]->value();
   for(unsigned int i=1; i< it->second.size();i++)
   {
     *textOutPut<<", " <<it->second[i]->cutTyp()<<" "<<it->second[i]->value();
   }
   *textOutPut<<"\n";
 }
  return result;
}
bool FlexPrediction::PerformeCut(std::map<std::string, std::vector<Cuts*> > cuts)
{
  bool result = false;
  for (std::map<std::string, std::vector<Cuts*> >::iterator it=cuts.begin(); it!=cuts.end(); ++it)
  {
    std::string key = it->first;
    for (unsigned int i=0; i< it->second.size();i++)
    {
      unsigned int cutTyp = it->second[i]->CutTyp();
      double cutvalue = it->second[i]->value();
      if(cutTyp==0) // =
      {
	if(key.find("UShort_t")<key.size())
	{
	  //
	  if( !(*(treeUShort_ts_.find(it->second[i]->Variable()))->second == it->second[i]->valueI() )) return true;
	}
	else if(key.find("Float_t")<key.size())
	{
	  if( *(treeFloat_ts_.find(it->second[i]->Variable()))->second == it->second[i]->value()) return true;
	}
	else 
	{
	  std::cout<<"Error cut is of unknown typ: "<<key<<" only UShort_t and Float_t are defined."<<std::endl;
	}
      }
      if(cutTyp==1)// <
      {
	if(key.find("UShort_t")<key.size())
	{
	  if( *(treeUShort_ts_.find(it->second[i]->Variable()))->second > it->second[i]->valueI()) return true;
	}
	else if(key.find("Float_t")<key.size())
	{
	  if( *(treeFloat_ts_.find(it->second[i]->Variable()))->second > it->second[i]->value()) return true;
	}
	else 
	{
	  std::cout<<"Error cut is of unknown typ: "<<key<<" only UShort_t and Float_t are defined."<<std::endl;
	}
      }
      if(cutTyp==2)// >
      {
	if(key.find("UShort_t")<key.size())
	{
	  if( *(treeUShort_ts_.find(it->second[i]->Variable()))->second < it->second[i]->valueI()) return true;
	}
	else if(key.find("Float_t")<key.size())
	{
	  if( *(treeFloat_ts_.find(it->second[i]->Variable()))->second < it->second[i]->value()) return true;
	}
	else 
	{
	  std::cout<<"Error cut is of unknown typ: "<<key<<" only UShort_t and Float_t are defined."<<std::endl;
	}
      }
      if(cutTyp==3)// <=
      {
	if(key.find("UShort_t")<key.size())
	{
	  if( *(treeUShort_ts_.find(it->second[i]->Variable()))->second > it->second[i]->valueI()) return true;
	}
	else if(key.find("Float_t")<key.size())
	{
	  if( *(treeFloat_ts_.find(it->second[i]->Variable()))->second > it->second[i]->value()) return true;
	}
	else 
	{
	  std::cout<<"Error cut is of unknown typ: "<<key<<" only UShort_t and Float_t are defined."<<std::endl;
	}
      }
      if(cutTyp==4)// >=
      {
	if(key.find("UShort_t")<key.size())
	{
	  if( *(treeUShort_ts_.find(it->second[i]->Variable()))->second < it->second[i]->valueI()) return true;
	}
	else if(key.find("Float_t")<key.size())
	{
	  if( *(treeFloat_ts_.find(it->second[i]->Variable()))->second < it->second[i]->value()) return true;
	}
	else 
	{
	  std::cout<<"Error cut is of unknown typ: "<<key<<" only UShort_t and Float_t are defined."<<std::endl;
	}
      }
      if(cutTyp>4) std::cout<<"Error cut typ is not defined. Cut: "<<it->second[i]->cutTyp()<<std::endl;
    }	
  }
  return result;
  
}
