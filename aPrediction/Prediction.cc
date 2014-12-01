#include "Prediction.h"

// using namespace std;
Prediction::Prediction()
{
  std::cout<<"Started"<<std::endl;
  initilized_=false;
  
}
Prediction::~Prediction()
{
  std::cout<<"Ended"<<std::endl;
}
void Prediction::ClassicRA2Eff(std::vector<double> inputEffShouldBeTObjects)
{
  initilized_=true;
  std::cout<<"ClassicalRA2Eff binning selected. Will do prediction with single muon cs only. Binning of efficiencies:\endl";
  std::cout<<"Muon: \endl Iso: ";
  
}
