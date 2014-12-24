#ifndef Analyzer_H
#define Analyzer_H
#include "vector"
#include <TTree.h>
#include "TFile.h"
#include <TChain.h>
#include "string"
#include "fstream"
#include "map"
#include <iostream>
#include "stdlib.h"
#include "algorithm"
#include "TString.h"
#include "SharedVariables.h"
#include "HelperClass.h"
class Analyzer
{
public:
  Analyzer();
  Analyzer(Config *config){config_=config;TChain_ = new TChain((TString)config->GetInputTreeName() );}
//   TChain *Effchain = new TChain("RA2TreeMaker2/RA2PreSelection");
//   Effchain->Add("/nfs/dust/cms/user/adraeger/CSA2014/mc/WJetsToLNu_HT-200to400/*root");
  ~Analyzer(){};
private:
  std::string name_;
  Config *config_;
  TChain *TChain_;
};
#endif