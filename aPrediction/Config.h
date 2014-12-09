#ifndef Config_H
#define Config_H
#include "vector"
#include "string"
#include "fstream"
#include "map"
#include <iostream>
#include "stdlib.h"
#include "algorithm"
#include "Prediction.h"
class Cuts
{
public:
	Cuts();
	Cuts(std::string Variable, std::string cutTyp,unsigned int CutTyp, double value){Variable_=Variable;cutTyp_=cutTyp;CutTyp_=CutTyp;value_=value;isUShort_=false;}
	Cuts(std::string Variable, std::string cutTyp,unsigned int CutTyp, unsigned int value,bool ushort){Variable_=Variable;cutTyp_=cutTyp;CutTyp_=CutTyp;valueI_=value;isUShort_=ushort;}
	std::string Variable(){unsigned int position = Variable_.find(";");if(position>Variable_.size())return "EROOOOROROORORORO";std::string result = Variable_.substr(0,position);return result;};
	std::string VariableTyp()
	{
	  unsigned int position = Variable_.find(";");
	  if(position>Variable_.size())return "EROOOOROROORORORO";
	  std::string result = Variable_.substr(position+1);
	  return result;
	  
	};
	std::string cutTyp(){return cutTyp_;}
	unsigned int CutTyp(){return CutTyp_;}
	double value(){return value_;}
	unsigned int valueI(){return valueI_;}
	bool isInt(){return isUShort_;}
	~Cuts(){}
private:
	std::string Variable_, cutTyp_;
	double value_;
	unsigned int CutTyp_, valueI_;
	bool isUShort_;
};

class Efficiency
{
public:
	Efficiency();
	Efficiency(std::string Name,std::string FileName,std::string variableX, std::string variableY){Name_=Name;FileName_=FileName;variableX_=variableX;variableY_=variableY;}

	~Efficiency(){}
	std::string Name(){return Name_;}
private:
	std::string Name_, FileName_,variableX_,variableY_;
	

};

class Config
{
public:
	Config(const char* ConfFile);
	~Config();
	std::map<std::string, Efficiency*> GetEfficiencies (){return efficiencies_;}
	std::map<std::string,std::string> GetEfficiencySharedValues(){return efficiencySharedValues_;}
	std::map<std::string, std::vector<Cuts*> > GetCuts(){return cuts_;}
	std::map<std::string, std::vector<Cuts*> > returnCut(std::vector<std::string> cutStringVector);
	
private:
	// filename and file itself
	std::string fileName_;
	std::ifstream fileStr_;
	// functions
	void ReadFile();
	bool initilized_;
	std::map<std::string, std::vector<Cuts*> > cuts_;
	std::map<std::string, Efficiency*> efficiencies_;
	std::vector<std::string> operators_;
	std::vector<std::string> EfficiencySharedValues_;
	std::map<std::string,std::string> efficiencySharedValues_;
	std::map<std::string,Prediction > predictionMap_;
};

#endif
