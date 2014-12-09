#ifndef Prediction_H
#define Prediction_H
#include "string"
#include <vector>
#include <iostream>
class Prediction
{
public:
  Prediction();
  Prediction(std::string Name);
  bool FullSetupDone(){return initilized_;}
  std::string getName(){return name_;}
  ~Prediction();
  void ClassicRA2Eff(std::vector<double> inputEffShouldBeTObjects);
private:
  std::string name_;
  bool initilized_;
  std::fstream *textOutPut_;
};

#endif

