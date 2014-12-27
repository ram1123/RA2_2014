#include "HelperClass.h"

Config::Config(const char* ConfFile)
{
	fileName_=ConfFile;
	std::cout<<"Config::Loading configuration file: "<<fileName_<<std::endl;
	fileStr_.open(fileName_.c_str(), std::ifstream::in);
	if(!fileStr_.is_open())
	{
		std::cout<<"Config::Error input file could not been opened!"<<std::endl;
	}
	// define here the operators to be used
	operators_.clear();
	operators_.push_back("="); // the order matters here!!!! = is also included in >= therefore >= must be checked later than = etc... 
	operators_.push_back("<");// also the values are identified in orders. 0 = '=' 1= '<' etc. dont change here anything if you dont know what you are doing
	operators_.push_back(">");
	operators_.push_back("<=");
	operators_.push_back(">=");
	ReadFile();
	std::cout<<"Config::Setup finished"<<std::endl;
}
void Config::ReadFile()
{
	std::string line="";
	std::string sectionName, tempString;
	std::string name, value;
	unsigned int sharpPos, lineNumber;
	std::string::iterator newEnd;
	unsigned int operatorPositionStart; // position of the =
	unsigned int operatorPositionEnd; // position of the =
	std::pair <std::string,std::string> TempPair;
	// reset fileStr to beginning
	fileStr_.clear() ;
	fileStr_.seekg(0, std::ios::beg) ;
	lineNumber=0;
	while(!fileStr_.eof()) // first load variables
  {
		lineNumber++;
		line.clear();
		std::getline(fileStr_, line);
		// cleaning of file removing spaces and comments
		if(line.length() == 0) continue; // empty line
    sharpPos = line.find('#');
		if(sharpPos == 0) continue; // full comment line, skip
    if(sharpPos < line.size()) // sharp found
      line.resize(sharpPos); // ignore what comes after the #
			newEnd = std::remove(line.begin(), line.end(), ' ');
		if(newEnd == line.begin()) continue; // string of spaces and comments
    line.resize(newEnd - line.begin()); // resize the string to its new size
		newEnd = std::remove(line.begin(), line.end(), '\t');
		if(newEnd == line.begin()) continue; // string of spaces, tabs and comments
    line.resize(newEnd - line.begin()); // resize the string to its new size
		// starting search for definition sections looking for:
		// Cuts on search varaibles
		if(line.substr(0,1)=="!")
		{
			sectionName = line.substr(1);
			if(sectionName=="Variables")std::cout<<"Config::Loading variables:"<<std::endl;
			continue;
		}
		if(sectionName=="Variables")
		{
			if(line.find('=')<line.size() )
			{
				name = line.substr(0, line.find('=') );
				tempString= line.substr(line.find('=')+1);
				std::cout<<"Name: "<<name<<std::endl;
			}
			else std::cout<<"Wrong syntax in line: "<<lineNumber<< " = "<<line<<"    expecting: Name;Type::label(optional)"<<std::endl;
			if(variablesMap_.find(name) !=variablesMap_.end()) std::cout<<"Config::Warning variable with name: "<<name<<" already defined. Check config file. skipping."<<std::endl;
			else
			{
				Variable *variable = new Variable(name,tempString);
				std::cout<<"typ: "<<variable->GetTypString()<<std::endl;
				variablesMap_[name]=variable;
			}
			
		}
		if(sectionName=="AnalyzeRootFiles")
		{
			if(line.find(".root")<line.size() )
			{
				InputRootFileNameVector_.push_back(line);
			}
			else if(line.find("treeName=")<line.size() )
			{
				std::cout<<"treeName:  "<<SeparateString(line,"treeName=").second<<std::endl;
				InputRootTreeName_=SeparateString(line,"treeName=").second;
			}
			else std::cout<<"Config::Error file name from config does not contain .root probably a problem, skipping file. line: "<<line<<std::endl;
			
		}
	}
	// loop to find efficiencies
	std::string EfficiencyFileName="", EfficiencyFolderName="";
	fileStr_.clear() ;
	fileStr_.seekg(0, std::ios::beg) ;
	lineNumber=0;
	while(!fileStr_.eof()) // first load variables
  {
		lineNumber++;
		line.clear();
		std::getline(fileStr_, line);
		// cleaning of file removing spaces and comments
		if(line.length() == 0) continue; // empty line
    sharpPos = line.find('#');
		if(sharpPos == 0) continue; // full comment line, skip
    if(sharpPos < line.size()) // sharp found
      line.resize(sharpPos); // ignore what comes after the #
			newEnd = std::remove(line.begin(), line.end(), ' ');
		if(newEnd == line.begin()) continue; // string of spaces and comments
    line.resize(newEnd - line.begin()); // resize the string to its new size
		newEnd = std::remove(line.begin(), line.end(), '\t');
		if(newEnd == line.begin()) continue; // string of spaces, tabs and comments
    line.resize(newEnd - line.begin()); // resize the string to its new size
		// starting search for definition sections looking for:
		// Cuts on search varaibles
		if(line.substr(0,1)=="!")
		{
			sectionName = line.substr(1);
			continue;
		}
		// MuonPurity(MHT,NJets)::MuonPurity
		if(sectionName=="Efficiencies")
		{
			if(line.find("FileName=") <line.size() )
			{
// 				std::cout<<"FileNameFound in efficiency section"<<std::endl;
				EfficiencyFileName = line.substr(line.find("=")+1);
// 				std::cout<<"FileName="<<EfficiencyFileName<<std::endl;
				continue;
				
			}
			if(line.find("Folder=")< line.size())
			{
				EfficiencyFolderName= line.substr(line.find("=")+1);
// 				std::cout<<"FolderName= "<<EfficiencyFolderName<<std::endl;
				continue;
			}
			if(line.find("(") >line.size() || line.find(")") >line.size())
			{
				std::cout<<"Config::Error in Efficiency section: line: "<<lineNumber<<" is of wrong typ expecting Name(variable,variable)::Label skipping line. line: "<<lineNumber<<std::endl;
				continue;
			}
			if(line.find(",")<line.size() ) // true if 2D or higher efficiency map note only up to 2D supported 
      {
				TempPair = SeparateString(line,"(");
				std::string nameInfFile = TempPair.first;
				TempPair = SeparateString(TempPair.second,",");
				std::string variableX = TempPair.first;
				TempPair = SeparateString(TempPair.second,")");
				std::string variableY = TempPair.first;
				std::string EffLabel = nameInfFile;
				if(TempPair.second.find("::") <line.size() ) EffLabel = SeparateString(TempPair.second,"::").second;
// 				std::cout<<"Efficiency found with nameInfFile: "<<nameInfFile<<", variableX: "<<variableX<<", variableY: "<<variableY<<" and label: "<<EffLabel<<std::endl;
				// check if variable for parametrization is defined
				if(variablesMap_.find(variableX) ==variablesMap_.end()) std::cout<<"Config::Efficiencies::Warning variable with name: "<<variableX<<" not defined line: "<<lineNumber<<std::endl;
				else if(variablesMap_.find(variableY) ==variablesMap_.end()) std::cout<<"Config::Efficiencies::Warning variable with name: "<<variableY<<" not defined line: "<<lineNumber<<std::endl;
				else 
				{
					Efficiency2D *tempEff = new Efficiency2D(nameInfFile,variableX,variableY,EffLabel);
					if(efficiencies2D_.find(EffLabel) !=efficiencies2D_.end() || efficiencies1D_.find(EffLabel) !=efficiencies1D_.end()) std::cout<<"Config::Efficiencies::Warning efficiency with label: "<<EffLabel<<" allready exists skipping storing of line: "<<lineNumber<<std::endl;
					else efficiencies2D_[EffLabel]=tempEff;
				}
				
			}
			else  // true if 1D 
			{
				TempPair = SeparateString(line,"(");
				std::string nameInfFile = TempPair.first;
				TempPair = SeparateString(TempPair.second,")");
				std::string variableX = TempPair.first;
				std::string EffLabel = nameInfFile;
				if(TempPair.second.find("::") <line.size() ) EffLabel = SeparateString(TempPair.second,"::").second;
// 				std::cout<<"Efficiency found with nameInfFile: "<<nameInfFile<<", variableX: "<<variableX<<" and label: "<<EffLabel<<std::endl;
				// check if variable for parametrization is defined
				if(variablesMap_.find(variableX) ==variablesMap_.end()) std::cout<<"Config::Efficiencies::Warning variable with name: "<<variableX<<" not defined line: "<<lineNumber<<std::endl;
				else 
				{
					Efficiency1D *tempEff = new Efficiency1D(nameInfFile,variableX,EffLabel);
					if(efficiencies2D_.find(EffLabel) !=efficiencies2D_.end() || efficiencies1D_.find(EffLabel) !=efficiencies1D_.end()) std::cout<<"Config::Efficiencies::Warning efficiency with label: "<<EffLabel<<" allready exists skipping storing of line: "<<lineNumber<<std::endl;
					else efficiencies1D_[EffLabel]=tempEff;
				}
			}
		}
	}
	
	// loop over the file again for the remaining setup
	fileStr_.clear() ;
	fileStr_.seekg(0, std::ios::beg) ;
	lineNumber=0;
	TString SectionName="", PredictionName="";
	std::vector<CutI*> cutVectorITemp;
	std::vector<CutF*> cutVectorFTemp;
	std::vector<std::string> PurityEfficienciesTemp, ControlSampleEfficienciesTemp, ScalingControlSampleToPredictionTemp, PredictionEfficienciesTemp;
	
	while(!fileStr_.eof())
  {
		
		lineNumber++;
		line.clear();
		std::getline(fileStr_, line);
		// cleaning of file removing spaces and comments
		if(line.length() == 0) continue; // empty line
    sharpPos = line.find('#');
		if(sharpPos == 0) continue; // full comment line, skip
    if(sharpPos < line.size()) // sharp found
      line.resize(sharpPos); // ignore what comes after the #
			newEnd = std::remove(line.begin(), line.end(), ' ');
		if(newEnd == line.begin()) continue; // string of spaces and comments
    line.resize(newEnd - line.begin()); // resize the string to its new size
		newEnd = std::remove(line.begin(), line.end(), '\t');
		if(newEnd == line.begin()) continue; // string of spaces, tabs and comments
    line.resize(newEnd - line.begin()); // resize the string to its new size
		// starting search for definition sections looking for:
		// Cuts on search varaibles
		if(line.substr(0,1)=="!")
		{
			SectionName = line.substr(1);
			continue;
		}
		if(SectionName=="Variables") continue;
		if(SectionName=="AnalyzeRootFiles") continue;
			 if(SectionName=="Cuts")
			 {
				 std::cout<<"Cut found: "<<line<<std::endl;
				 unsigned int CutTyp=0;
				 for (unsigned int i=0; i<operators_.size();i++)
				 {
					 if(!(line.find(operators_[i]) >line.size())) 
					 {
						 operatorPositionStart = line.find(operators_[i]);
						 operatorPositionEnd = operatorPositionStart + operators_[i].size()-1;
						 CutTyp=i;
					 }
				 }
				 name = line.substr(0,operatorPositionStart);
				 if(!(variablesMap_.find(name) !=variablesMap_.end() ) )std::cout<<"Error cut: "<<name<<" uses variable which has not been defined yet in the !Variable section please add in config.txt"<<std::endl;
				 else
				 {
					 std::string typString = variablesMap_.find(name)->second->GetTypString();
					 value =line.substr(operatorPositionStart,operatorPositionEnd-operatorPositionStart+1);
					 unsigned int cutValueI;
					 std::string cutTemp;
					 cutTemp= line.substr(operatorPositionEnd+1);
					 std::cout<<"Cut found in: line: "<<line<<" with obtained name: "<<name<< " and value: "<<value<<" and CutTyp: "<<CutTyp<<" "<<" with obtained typString: "<<typString<<std::endl;
					 if( typString.find("Int_t")< typString.size() )
					 {
						 sscanf(cutTemp.c_str(), "%hu", &cutValueI);
						 // 	  Cuts *cut = new Cuts(name,value,CutTyp,cutValueI,true);
						 CutI *cutI = new CutI(name,value,CutTyp,cutValueI);
// 						 std::cout<<"CutvalueI: Variable: "<<cutI->GetVariable()<<" CutTypStr: "<<cutI->GetCutTypStr()<<" CutTyp: "<<cutI->GetCutTyp()<<" GetCutValueI: "<<cutI->GetCutValueI()<<std::endl;
						 cutVectorI_.push_back(cutI);
					 }
					 else if ( typString.find("Float_t")< typString.size() )
					 {
						 std::cout<<"cutTemp: "<<cutTemp<<std::endl;
						 // 	  sscanf(cutTemp.c_str(), "%hu", &cutValueI);
						 double cutValueF = atof(cutTemp.c_str());
						 sscanf(cutTemp.c_str(), "%lf", &cutValueF);
						 CutF *cutF = new CutF(name,value,CutTyp,cutValueF);
// 						 std::cout<<"CutvalueF: Variable: "<<cutF->GetVariable()<<" CutTypStr: "<<cutF->GetCutTypStr()<<" CutTyp: "<<cutF->GetCutTyp()<<" GetCutValueF: "<<cutF->GetCutValueF()<<std::endl;
						 cutVectorF_.push_back(cutF);
					 }
					 // 	else std::cout<<"Config::Error typ: "<<typString<<" of variable has not been recognized as any valid cut variable..."<<std::endl;
				 }
			 }
			 if(SectionName=="Prediction")
			 {
				 if(line.substr(0,6)=="Name::")
				 {
// 					 std::cout<<"Name: found"<<std::endl;
					 TempPair = SeparateString(line,"::");
					 PredictionName = TempPair.second;
				 }
				 if(line.substr(0,5)=="Cut::")
				 {
					 line= SeparateString(line,"::").second;
					 std::cout<<"Cut Prediction found: "<<line<<std::endl;
					 unsigned int CutTyp=0;
					 for (unsigned int i=0; i<operators_.size();i++)
					 {
						 if(!(line.find(operators_[i]) >line.size())) 
						 {
							 operatorPositionStart = line.find(operators_[i]);
							 operatorPositionEnd = operatorPositionStart + operators_[i].size()-1;
							 CutTyp=i;
						 }
					 }
					 name = line.substr(0,operatorPositionStart);
					 if(!(variablesMap_.find(name) !=variablesMap_.end() ) )std::cout<<"Error Prediction cut: "<<name<<" uses variable which has not been defined yet in the !Variable section please add in config.txt"<<std::endl;
					 else
					 {
						 std::string typString = variablesMap_.find(name)->second->GetTypString();
						 value =line.substr(operatorPositionStart,operatorPositionEnd-operatorPositionStart+1);
						 unsigned int cutValueI;
						 std::string cutTemp;
						 cutTemp= line.substr(operatorPositionEnd+1);
						 std::cout<<"Cut found in: line: "<<line<<" with obtained name: "<<name<< " and value: "<<value<<" and CutTyp: "<<CutTyp<<" "<<" with obtained typString: "<<typString<<std::endl;
						 if( typString.find("Int_t")< typString.size() )
						 {
							 sscanf(cutTemp.c_str(), "%hu", &cutValueI);
							 // 	  Cuts *cut = new Cuts(name,value,CutTyp,cutValueI,true);
							 CutI *cutI = new CutI(name,value,CutTyp,cutValueI);
// 							 std::cout<<"CutvalueI: Variable: "<<cutI->GetVariable()<<" CutTypStr: "<<cutI->GetCutTypStr()<<" CutTyp: "<<cutI->GetCutTyp()<<" GetCutValueI: "<<cutI->GetCutValueI()<<std::endl;
							 cutVectorITemp.push_back(cutI);
						 }
						 else if ( typString.find("Float_t")< typString.size() )
						 {
							 std::cout<<"cutTemp: "<<cutTemp<<std::endl;
							 // 	  sscanf(cutTemp.c_str(), "%hu", &cutValueI);
							 double cutValueF = atof(cutTemp.c_str());
							 sscanf(cutTemp.c_str(), "%lf", &cutValueF);
							 CutF *cutF = new CutF(name,value,CutTyp,cutValueF);
// 							 std::cout<<"CutvalueF: Variable: "<<cutF->GetVariable()<<" CutTypStr: "<<cutF->GetCutTypStr()<<" CutTyp: "<<cutF->GetCutTyp()<<" GetCutValueF: "<<cutF->GetCutValueF()<<std::endl;
							 cutVectorFTemp.push_back(cutF);
						 }
						 // 	else std::cout<<"Config::Error typ: "<<typString<<" of variable has not been recognized as any valid cut variable..."<<std::endl;
					 }
				 }
				 if(line.substr(0,8)=="Purity::")
				 {

					 line = SeparateString(line,"::").second;
					 PurityEfficienciesTemp = SeparateStringToVector(line,",");
				 }
				 if(line.find("ControlSample::")<line.size())
				 {
			
					 line = SeparateString(line,"::").second;
					 ControlSampleEfficienciesTemp = SeparateStringToVector(line,",");
				 }
				 if(line.find("ScalingControlSampleToPrediction::")<line.size())
				 {
					 
					 line = SeparateString(line,"::").second;
					 ScalingControlSampleToPredictionTemp = SeparateStringToVector(line,",");
				 }
				 if(line.find("Prediction::")<line.size())
				 {
				
					 line = SeparateString(line,"::").second;
					 PredictionEfficienciesTemp = SeparateStringToVector(line,",");
				 }
				 if(line.substr(0,5)=="Done:" )
				 {
					 bool invalid =false;
					 for(unsigned int i =0; i<PurityEfficienciesTemp.size();i++)  if(!(efficiencies1D_.find(PurityEfficienciesTemp[i]) !=efficiencies1D_.end() ) && !(efficiencies2D_.find(PurityEfficienciesTemp[i]) !=efficiencies2D_.end() ) ) 
					 {
						 invalid=true;
						 std::cout<<"Warning purity Eff of prediciton: "<<PredictionName<<" not defined: "<<PurityEfficienciesTemp[i]<<std::endl;
					 }
					 for(unsigned int i =0; i<ControlSampleEfficienciesTemp.size();i++)  if(!(efficiencies1D_.find(ControlSampleEfficienciesTemp[i]) !=efficiencies1D_.end() ) && !(efficiencies2D_.find(ControlSampleEfficienciesTemp[i]) !=efficiencies2D_.end() ) ) 
					 {
						 invalid=true;
						 std::cout<<"Warning controlsample Eff of prediciton: "<<PredictionName<<" not defined: "<<ControlSampleEfficienciesTemp[i]<<std::endl;
					 }
					 for(unsigned int i =0; i<ScalingControlSampleToPredictionTemp.size();i++)  if(!(efficiencies1D_.find(ScalingControlSampleToPredictionTemp[i]) !=efficiencies1D_.end() ) && !(efficiencies2D_.find(ScalingControlSampleToPredictionTemp[i]) !=efficiencies2D_.end() ) ) 
					 {
						 invalid=true;
						 std::cout<<"Warning scaling of control to prediction sample eff map of prediciton: "<<PredictionName<<" not defined: "<<ScalingControlSampleToPredictionTemp[i]<<std::endl;
					 }
					 for(unsigned int i =0; i<PredictionEfficienciesTemp.size();i++)  if(!(efficiencies1D_.find(PredictionEfficienciesTemp[i]) !=efficiencies1D_.end() ) && !(efficiencies2D_.find(PredictionEfficienciesTemp[i]) !=efficiencies2D_.end() ) ) 
					 {
						 invalid=true;
						 std::cout<<"Warning prediction eff map of prediciton: "<<PredictionName<<" not defined: "<<PredictionEfficienciesTemp[i]<<std::endl;
					 }
					 if(!invalid)
					 {
						 Prediction *tempPrediction = new Prediction((std::string)PredictionName, cutVectorITemp, cutVectorFTemp, PurityEfficienciesTemp, ControlSampleEfficienciesTemp, ScalingControlSampleToPredictionTemp, PredictionEfficienciesTemp);
						 tempPrediction->DumpStatus();
						 if(!(predictions_.find((std::string)PredictionName) == predictions_.end()))std::cout<<"Error prediciton with name: "<<PredictionName<<" already defined! Skipping prediction"<<std::endl;
								else  predictions_[(std::string)PredictionName]=tempPrediction;
					 }
					 else std::cout<<"One or more efficiency maps used by prediciton: "<<PredictionName<<"  have not been defined skipping prediction"<<std::endl;
					 // reset varaibles for next prediction
					 cutVectorITemp.clear();
					 cutVectorFTemp.clear();
					 PurityEfficienciesTemp.clear();
					 ControlSampleEfficienciesTemp.clear();
					 ScalingControlSampleToPredictionTemp.clear();
					 PredictionEfficienciesTemp.clear();
					 PredictionName="";
					
				 }
				 
			 }
			 
	}
	std::cout<<"Config done dumping information: "<<std::endl;
	std::cout<<"Check what variables have been defined after looping over config"<<std::endl;
	for (std::map<std::string, Variable*>::iterator it=variablesMap_.begin(); it!=variablesMap_.end(); ++it)
	{
		std::cout<<"Varible: "<<it->first<<std::endl;
	}
	std::cout<<"efficiencies2D_"<<std::endl;
	for (std::map<std::string, Efficiency2D*>::iterator it=efficiencies2D_.begin(); it!=efficiencies2D_.end(); ++it)
	{
		std::cout<<"efficiencies2D_: "<<it->first<<std::endl;
	}
	std::cout<<"efficiencies1D_"<<std::endl;
	for (std::map<std::string, Efficiency1D*>::iterator it=efficiencies1D_.begin(); it!=efficiencies1D_.end(); ++it)
	{
		std::cout<<"efficiencies1D_: "<<it->first<<std::endl;
	}
}
// !Variables
// NJets=Int_t::N_{Jets}
void Variable::SetUp(std::string TypString)
{
	if(TypString.find("Int_t")<TypString.size())
	{
		TypString_="Int_t";
	}
	else if(TypString.find("Float_t")<TypString.size())
	{
		TypString_="Float_t";
	}
	if(TypString.find("::")<TypString.size())
	{
		label_ = TypString.substr(TypString.find("::")+2);
		std::cout<<"Label: "<<label_<<std::endl;
	}
	else label_=Name_;
}

std::pair <std::string,std::string> Config::SeparateString(std::string InputStr, std::string Separater)
{
	std::string first="";
	std::string second="";
	unsigned int SeparatorStart=0;
	unsigned int SeparatorEnd=0;
	if(InputStr.find(Separater) >InputStr.size()) 
	{
		std::cout<<"SeparateString:: Separater: "<<Separater<<" in: "<<InputStr<<" not found."<<std::endl;
		return std::make_pair(InputStr,second);
	}
	else 
	{
		SeparatorStart=InputStr.find(Separater);
		SeparatorEnd=SeparatorStart + Separater.size()-1;
		first = InputStr.substr(0,SeparatorStart);
		second =InputStr.substr(SeparatorEnd+1);
	}
	//std::cout<<"SeparateString:: Inputstr: "<<InputStr<<" Separater: "<<Separater<<" first: "<<first<<" second: "<<second<<std::endl;
	return std::make_pair(first,second);
}
std::vector<std::string> Config::SeparateStringToVector(std::string InputStr, std::string Separater)
{
	std::vector<std::string> result;
	if(InputStr.find(Separater) < InputStr.size() )
	{
		std::pair <std::string,std::string> pair;
		for(;InputStr.find(Separater) < InputStr.size(); InputStr = SeparateString(InputStr,Separater).second)
		{
			result.push_back(SeparateString(InputStr,Separater).first);
		}

	}
	result.push_back(InputStr);
	return result;
}

void Prediction::DumpStatus()
{
	std::cout<<"Dumping status of Predcition: "<<Name_<<std::endl;
	std::cout<<"Int cuts: ";
	for(unsigned int i=0; i <cutVectorI_.size();i++) std::cout<<cutVectorI_[i]->GetVariable()<<" ";
	std::cout<<std::endl;
	std::cout<<"Double cuts: ";
	for(unsigned int i=0; i <cutVectorF_.size();i++) std::cout<<cutVectorF_[i]->GetVariable()<<" ";
	std::cout<<std::endl;
	std::cout<<"Purity efficiencies: ";
	for(unsigned int i=0; i <PurityEfficiencies_.size();i++) std::cout<<PurityEfficiencies_[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"ControlSample efficiencies: ";
	for(unsigned int i=0; i <ControlSampleEfficiencies_.size();i++) std::cout<<ControlSampleEfficiencies_[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"ScalingControlSampleToPredictionSample efficiencies: ";
	for(unsigned int i=0; i <ScalingControlSampleToPredictionSample_.size();i++) std::cout<<ScalingControlSampleToPredictionSample_[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"Prediction efficiencies: ";
	for(unsigned int i=0; i <PredictionEfficiencies_.size();i++) std::cout<<PredictionEfficiencies_[i]<<" ";
	std::cout<<std::endl;
	
}



