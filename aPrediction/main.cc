 #include <TTree.h>
#include "iostream"
#include <fstream>
#include "FlexPrediction.h"
#include "Config.h"
int main(int argc, char* argv[])
{
  ofstream *tempStream = new ofstream;
  tempStream->open("LostLeptonPrediction.log");
  tempStream->close();
  delete tempStream;
  fstream *textOutPut = new fstream("LostLeptonPrediction.log");
  *textOutPut <<"------------------------------------------------------------------------------------------------------------------\n";
  *textOutPut <<"------------------------------------LogFileLostLepton Prediction--------------------------------------------------\n";
  *textOutPut <<"------------------------------------------------------------------------------------------------------------------\n";
   if(argc <3)
   {
     std::cout << "Opening of file failed. Please use ./run confFile rootFile" << std::endl;
     return 1;
   }
   Config *ConfigFile = new Config(argv[1]);
  TFile *file = new TFile(argv[2],"OPEN");
  if(!file->IsOpen())
  {
    std::cout << "Opening of root file("<<argv[2]<<" failed. Please check name." << std::endl;
    return 1;
  }
  TTree *inputTree=NULL;
  inputTree = (TTree*) file->Get("LostLeptonPrediction");
  if(!inputTree)
  {
    std::cout<<"Tree name not found in file."<<std::endl;
    return 1;
  }
 // TTre *tree = 
 // Effchain->Process("Prediction.C+");
//  Prediction *Muon = new Prediction();
  FlexPrediction *Predictions = new FlexPrediction(inputTree);
  Predictions->InitConfig(ConfigFile, textOutPut);
  Predictions->Loop();
//   delete Muon;
  textOutPut->close();
  return 0;
}
