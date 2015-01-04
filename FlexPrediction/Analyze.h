#ifndef Analyze_H
#define Analyze_H
#include "SharedVariables.h"
#include "map"
#include "vector"
#include "string"
#include "fstream"
#include "TString.h"
#include "HelperClass.h"
#include "TFile.h"

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
	std::vector<CutI*> CutI_;
	std::vector<CutF*> CutF_;
	std::map<std::string,Efficiency1D*> Eff1DMap_;
	std::map<std::string,Efficiency2D*> Eff2DMap_;
	std::vector<Prediction*> predictionVector_;
	bool LoadVariables();
	bool LoadCuts();
	bool LoadEfficiencies();
	bool LoadPrediction();
	bool LoadCutI(std::vector<CutI*>);
	bool LoadCutF(std::vector<CutF*>);
	
};
#endif