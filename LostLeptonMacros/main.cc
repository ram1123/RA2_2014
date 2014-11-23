 #include <TTree.h>
#include "iostream"
#include "FlexPrediction.h"
int main(int argc, char* argv[])
{
   if(argc < 2)
   {
     std::cout << "Opening of file failed. Please use ./run RootFileName" << std::endl;
     return 1;
   }
  TFile *file = new TFile(argv[1],"OPEN");
  if(!file->IsOpen())
  {
    std::cout << "Opening of file("<<argv[1]<<" failed. Please check name." << std::endl;
    return 1;
  }
  TTree *inputTree=NULL;
  if(argc>2) inputTree = (TTree*) file->Get(argv[2]);
  else inputTree = (TTree*) file->Get("LostLeptonPrediction");
  if(!inputTree)
  {
    std::cout<<"Tree name not found in file."<<std::endl;
    return 1;
  }
 // TTre *tree = 
 // Effchain->Process("Prediction.C+");
//  Prediction *Muon = new Prediction();
  FlexPrediction *Prediction = new FlexPrediction(inputTree);
//   delete Muon;
  return 0;
}
