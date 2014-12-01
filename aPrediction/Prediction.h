#ifndef Prediction_H
#define Prediction_H
#include "string"
#include <vector>
#include <iostream>
class Prediction
{
public:
  Prediction();
  Prediction(std::string Name){Name_=Name;}
  ~Prediction();
  void ClassicRA2Eff(std::vector<double> inputEffShouldBeTObjects);
private:
  std::string Name_;
  bool initilized_;
};

#endif

