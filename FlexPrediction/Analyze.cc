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
	if(result) result= LoadEfficiencies();
	if(result) result= LoadPrediction();
	
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
	CutI_ = config_->GetCutIVector();
	result = LoadCutI(CutI_);
	CutF_ = config_->GetCutFVector();
	result = LoadCutF(CutF_);

	
	return result;
}
bool Analyze::LoadEfficiencies()
{
  *textOutPut_<<"Loading efficiencies...\n";
 bool result=true;
 Eff2DMap_ = config_->Get2DEffMap();
 Eff1DMap_ = config_->Get1DEffMap();
 unsigned int floatnumber=0, intnumber=0;
 std::string EffFileName = config_->GetEfficiencyFileName();
 std::string EffFolderName = config_->GetEfficiencyFolderName();
 *textOutPut_<<"Opening input file for efficiencies: Name: "<<EffFileName<<" with folder: "<<EffFolderName<<"\n";
  TFile *tempFile = new TFile((TString)EffFileName,"READ");
  if(!tempFile)
  {
    std::cout<<"Error in LoadEfficiencies efficiencies file not found. Name: "<<EffFileName<<std::endl;
    *textOutPut_<<"Error in LoadEfficiencies efficiencies file not found. Name: "<<EffFileName<<std::endl;
    return false;
  }
//   tempFile->GetListOfKeys()->Print();
  if(!tempFile->GetListOfKeys()->FindObject(EffFolderName.c_str())) 
  {
    std::cout<<"Error in LoadEfficiencies efficiencies folder not found. Name: "<<EffFolderName<<std::endl;
    *textOutPut_<<"Error in LoadEfficiencies efficiencies folder not found. Name: "<<EffFolderName<<std::endl;
    return false;
  }
  TDirectory *tempEffFolder= (TDirectory*)tempFile->Get(EffFolderName.c_str());
  if(!tempEffFolder)
  {
    std::cout<<"Could not open folder: "<<EffFolderName<<std::endl;
    *textOutPut_<<"Could not open folder: "<<EffFolderName<<std::endl;
    return false;
  }
//   tempEffFolder->GetListOfKeys()->Print();
  for(std::map<std::string,Efficiency2D*>::const_iterator iter=Eff2DMap_.begin(); iter!=Eff2DMap_.end(); ++iter)
 {
   Efficiency2D *eff2D = iter->second;
   std::string xVar = eff2D->GetXVariable(), yVar = eff2D->GetYVariable();
   *textOutPut_<<"Efficieny:NameInFile: "<<eff2D->GetNameInFile()<<" lable: "<<eff2D->GetLabel()<<" x: "<<eff2D->GetXVariable()<<" y: "<<eff2D->GetYVariable();
   std::cout<<"Efficieny:NameInFile: "<<eff2D->GetNameInFile()<<" lable: "<<eff2D->GetLabel()<<" x: "<<eff2D->GetXVariable()<<" y: "<<eff2D->GetYVariable();
   bool foundX=false, foundY=false;
   for(unsigned int ii=0; ii<treeVariablesIntNames_.size();ii++)
   {
     if(xVar==treeVariablesIntNames_[ii])
     {
       foundX=true;
       eff2D->SetXVectorPosition(0,ii);
     }
     if(yVar==treeVariablesIntNames_[ii])
     {
       foundY=true;
       eff2D->SetYVectorPosition(0,ii);
     }
   }
   for(unsigned int ii=0; ii<treeVariablesFloatNames_.size();ii++)
   {
     if(xVar==treeVariablesFloatNames_[ii])
     {
       foundX=true;
       eff2D->SetXVectorPosition(1,ii);

     }
     if(yVar==treeVariablesFloatNames_[ii])
     {
       foundY=true;
       eff2D->SetYVectorPosition(1,ii);
     }
   }
   if(foundX && foundY)
   {
     *textOutPut_<<" both variables are ok loading eff from file...";
     if(tempEffFolder->GetListOfKeys()->FindObject((TString)eff2D->GetNameInFile())) 
     {
       eff2D->SetTH2F((TH2F*)tempEffFolder->Get((TString)eff2D->GetNameInFile()));
     }
     else
     {
       std::cout<<"Error could not load efficiency from folder. Name of effieciency: "<<eff2D->GetNameInFile()<<"\n";
       *textOutPut_<<"Error could not load efficiency from folder. Name of effieciency: "<<eff2D->GetNameInFile()<<"\n";
     }
   }
   else 
   {
     std::cout<<"Error not both variables were found error!!!";
     *textOutPut_<<" Error not both variables were found error!!!";
   }

 }
 for(std::map<std::string,Efficiency1D*>::const_iterator iter=Eff1DMap_.begin(); iter!=Eff1DMap_.end(); ++iter)
 {
   Efficiency1D *eff1D = iter->second;
   std::string xVar = eff1D->GetXVariable();
   *textOutPut_<<"Efficieny:NameInFile: "<<eff1D->GetNameInFile()<<" lable: "<<eff1D->GetLabel()<<" x: "<<eff1D->GetXVariable();
   std::cout<<"Efficieny:NameInFile: "<<eff1D->GetNameInFile()<<" lable: "<<eff1D->GetLabel()<<" x: "<<eff1D->GetXVariable();
   bool foundX=false;
   for(unsigned int ii=0; ii<treeVariablesIntNames_.size();ii++)
   {
     if(xVar==treeVariablesIntNames_[ii])
     {
       foundX=true;
       eff1D->SetXVectorPosition(0,ii);
     }
   }
   for(unsigned int ii=0; ii<treeVariablesFloatNames_.size();ii++)
   {
     if(xVar==treeVariablesFloatNames_[ii])
     {
       foundX=true;
       eff1D->SetXVectorPosition(1,ii);
       
     }
   }
   if(foundX)
   {
     *textOutPut_<<" variable is ok loading eff from file...";
     if(tempEffFolder->GetListOfKeys()->FindObject((TString)eff1D->GetNameInFile())) 
     {
       eff1D->SetTH1F((TH1F*)tempEffFolder->Get((TString)eff1D->GetNameInFile()));
     }
     else
     {
       std::cout<<"Error could not load efficiency from folder. Name of effieciency: "<<eff1D->GetNameInFile()<<"\n";
       *textOutPut_<<"Error could not load efficiency from folder. Name of effieciency: "<<eff1D->GetNameInFile()<<"\n";
     }
   }
   else 
   {
     *textOutPut_<<" Error not both variables were found error!!!";
   }
 }
 return result; 
}
bool Analyze::LoadPrediction()
{
  bool result=true;
  for(std::map<std::string,Prediction*>::const_iterator iter=config_->GetPredictionsMap().begin(); iter!=config_->GetPredictionsMap().end(); ++iter)
  {
    predictionVector_.push_back(iter->second);
  }
  for(unsigned int i=0; i<predictionVector_.size();i++)
  {
    if(!LoadCutI(predictionVector_[i]->GetCutVectorI() ))
    {
      std::cout<<"Analyze::LoadPrediction Error loading cut vector int! please check"<<std::endl;
      *textOutPut_<<"Analyze::LoadPrediction Error loading cut vector int! please check"<<std::endl;
      return false;
    }
    if(!LoadCutF(predictionVector_[i]->GetCutVectorF() ))
    {
      std::cout<<"Analyze::LoadPrediction Error loading cut vector float! please check"<<std::endl;
      *textOutPut_<<"Analyze::LoadPrediction Error loading cut vector float! please check"<<std::endl;
      return false;
    }
    std::cout<<"Analyze::LoadPrediction setting up prediction chain...";
    *textOutPut_<<"Analyze::LoadPrediction setting up prediction chain...";
    if(!predictionVector_[i]->Initialize())
    {
      std::cout<<"Analyze::LoadPrediction Error in prediction "<<predictionVector_[i]->GetName()<<" during Initialization please check";
      *textOutPut_<<"Analyze::LoadPrediction Error in prediction "<<predictionVector_[i]->GetName()<<" during Initialization please check";
      return false;
    }
  }
  return result;
}
bool Analyze::LoadCutI(std::vector<CutI*> CutI)
{
  bool result=true;
  for(unsigned int i=0; i<CutI.size();i++)
  {
    bool found=false;
    std::string variable = CutI[i]->GetVariable();
    for(unsigned int ii=0; ii<treeVariablesIntNames_.size();ii++)
    {
      if(treeVariablesIntNames_[ii]==variable)
      {
	CutI[i]->SetVectorPosition(ii);
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
  return result;
}
bool Analyze::LoadCutF(std::vector<CutF*> CutF)
{
  bool result=true;
  for(unsigned int i=0; i<CutF.size();i++)
  {
    bool found=false;
    std::string variable = CutF[i]->GetVariable();
    for(unsigned int ii=0; ii<treeVariablesFloatNames_.size();ii++)
    {
      if(treeVariablesFloatNames_[ii]==variable)
      {
	CutF[i]->SetVectorPosition(ii);
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
