#ifndef Analyze_H
#define Analyze_H
#include "SharedVariables.h"
#include "map"
#include "vector"
#include "string"
#include "fstream"
#include "TString.h"
#include "HelperClass.h"

#include "TChain.h"
class Analyze
{
public:
	Analyze();
	Analyze(Config* config, fstream *textOutPut);
	void Initialize();
	bool Loop();
	~Analyze(){};
private:
	Config* config_;
	fstream* textOutPut_;
	TChain *chain_;
	bool initialized_;
	std::vector<std::string> treeVariablesFloatNames_, treeVariablesIntNames_;
	std::vector<Float_t> treeVariablesFloat_;
	std::vector<Int_t>  treeVariablesInt_;
	
	bool LoadVariables();
	bool LoadCuts();
	
};
#endif