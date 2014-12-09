#include "Prediction.h"

// using namespace std;
Prediction::Prediction()
{
  std::cout<<"Prediction class created with no name"<<std::endl;
  initilized_=false;
  
}
Prediction::Prediction(std::string Name)
{
  name_=Name;
  std::cout<<"Prediction class created with name: "<<name_<<std::endl;
  initilized_=false;
  
}
Prediction::~Prediction()
{
  std::cout<<"Ended"<<std::endl;
}
void Prediction::ClassicRA2Eff(std::vector<double> inputEffShouldBeTObjects)
{
  std::cout<<"ClassicalRA2Eff binning selected. Will do prediction with single muon cs only. Binning of efficiencies:\endl";
  std::cout<<"Muon: \endl Iso: ";
  initilized_  =true;
}
