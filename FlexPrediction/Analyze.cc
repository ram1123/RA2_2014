#include "Analyze.h"


Analyze::Analyze(Config* config, fstream *textOutPut)
{
	config_=config; 
	textOutPut_=textOutPut;
	initialized_=false;
	const char *c = config->GetInputRootTreeName().c_str();
	chain_ = new TChain(c );
	*textOutPut_ <<"-----------------------------------------------Starting Analyze::Analyze--------------------------------------------------\n";
	*textOutPut_ <<"TChain: "<<c<<std::endl;
	*textOutPut_ <<"Files: "<<std::endl;
	std::vector<std::string> tempVectorString = config_->GetInputRootFileName();
	for(unsigned int i=0; i<tempVectorString.size();i++)
	{
		std::cout<<"File["<<i<<"]: "<<tempVectorString[i]<<std::endl;
		*textOutPut_ <<"["<<i<<"]: "<<tempVectorString[i]<<std::endl;
		const char *cc=tempVectorString[i].c_str();
		chain_->Add(cc);
	}
	Initialize();
	
	
}
bool Analyze::Loop()
{
	bool result = initialized_;
	if(!initialized_)
	{
		*textOutPut_ <<"Error in Analyze::Loop not correlty initialized! canceling loop.\n";
		return !initialized_;
	}
}
void Analyze::Initialize()
{
	bool result=true;
	result = LoadVariables();
	if(result) result= LoadCuts();
	
	
	if(result)
	{
		*textOutPut_<<"Analyze::Initialize finished sucessfully.\n";
		initialized_=true;
	}
}

bool Analyze::LoadVariables()
{
	bool result=true;
	std::map<std::string,Variable*> varialbesMap = config_->GetVariableMap();
	unsigned int floatnumber=0, intnumber=0;
	for(std::map<std::string,Variable*>::const_iterator iter=varialbesMap.begin(); iter!=varialbesMap.end(); ++iter)
	{
		const Variable *tempVar = iter->second;
		std::cout<<iter->first<<std::endl;
		*textOutPut_<<"Analyze::Initialize Variable: "<<iter->first;
		if(chain_->GetListOfBranches()->FindObject(tempVar->GetVariable().c_str()) == 0) 
		{
			*textOutPut_<<" WARNING varialbe not found in input trees!!\n";
			std::cout<<"WARNING varialbe not found in input trees!!"<<std::endl;
			break;
			result=false;
		}
		std::cout<<"typ: "<<tempVar->GetTypString()<<" variable: "<<tempVar->GetVariable()<<std::endl;
		if(tempVar->GetTypString()=="Float_t")
		{
			Float_t tempFloat=0;
			treeVariablesFloat_.push_back(tempFloat);
			chain_->SetBranchAddress(tempVar->GetVariable().c_str(), &treeVariablesFloat_[floatnumber]);
			treeVariablesFloatNames_.push_back(tempVar->GetVariable());
			floatnumber++;
			*textOutPut_<<" done.\n";
		}
		else if(tempVar->GetTypString()=="Int_t")
		{
			Int_t tempFloat=0;
			treeVariablesInt_.push_back(tempFloat);
			chain_->SetBranchAddress(tempVar->GetVariable().c_str(), &treeVariablesInt_[intnumber]);
			treeVariablesIntNames_.push_back(tempVar->GetVariable());
			intnumber++;
			*textOutPut_<<" done.\n";
		}
		else
		{
			std::cout<<"Error varialbe is of non recognized typ: "<<tempVar->GetTypString()<<std::endl;
			*textOutPut_<<" Error varialbe is of non recognized typ: "<<tempVar->GetTypString()<<std::endl;
			result=false;
		}
	}
	return result;
}
bool Analyze::LoadCuts()
{
	bool result=true;
	std::vector<CutI*> tempCutI = config_->GetCutIVector();
	for(unsigned int i=0; i<tempCutI.size();i++)
	{
		bool found=false;
		std::string variable = tempCutI[i]->GetVariable();
		for(unsigned int ii=0; ii<treeVariablesIntNames_.size();ii++)
		{
			if(treeVariablesIntNames_[ii]==variable)
			{
				tempCutI[i]->SetVectorPosition(ii);
				found=true;
				*textOutPut_<<"Int_t cut with varialbe: "<<treeVariablesIntNames_[ii]<<" set to position: "<<ii<<std::endl;
			}
		}
		if(!found)
		{
			std::cout<<"Analyze::LoadCuts error could not find cut variable: "<<variable<<" in list of Int_t variables!"<<std::endl;
			*textOutPut_<<"Analyze::LoadCuts error could not find cut variable: "<<variable<<" in list of Int_t variables!"<<std::endl;
			result =false;
		}
	}
	std::vector<CutF*> tempCutF = config_->GetCutFVector();
	for(unsigned int i=0; i<tempCutF.size();i++)
	{
		bool found=false;
		std::string variable = tempCutF[i]->GetVariable();
		for(unsigned int ii=0; ii<treeVariablesFloatNames_.size();ii++)
		{
			if(treeVariablesFloatNames_[ii]==variable)
			{
				tempCutF[i]->SetVectorPosition(ii);
				found=true;
				*textOutPut_<<"Float_t cut with varialbe: "<<treeVariablesFloatNames_[ii]<<" set to position: "<<ii<<std::endl;
			}
		}
		if(!found)
		{
			std::cout<<"Analyze::LoadCuts error could not find cut variable: "<<variable<<" in list of Float_t variables!"<<std::endl;
			*textOutPut_<<"Analyze::LoadCuts error could not find cut variable: "<<variable<<" in list of Float_t variables!"<<std::endl;
			result =false;
		}
	}
	
	return result;
}

