#include "Config.h"

// using namespace std;
Config::Config(const char* ConfFile)
{
	initilized_=false;
	fileName_ = ConfFile;
	std::cout<<"Loading configuration file: "<<fileName_<<std::endl;
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
	EfficiencySharedValues_.clear(); // these variables are used as global defintions for the input efficiencies file name to read from folder name and more if necessary
	EfficiencySharedValues_.push_back("FileName");
	EfficiencySharedValues_.push_back("Folder");
	ReadFile();

}
Config::~Config()
{
	std::cout<<"Config End with name: "<<std::endl;
}
void Config::ReadFile()
{
	std::string line;
	std::string sectionName;
	sectionName.clear();
	unsigned int sharpPos; // position of the #
	std::string::iterator newEnd; // end of the string after remove
	unsigned int section=999;
	std::string name;
	std::string value;
	unsigned int operatorPositionStart; // position of the =
	unsigned int operatorPositionEnd; // position of the =
	while (!fileStr_.eof())
	{
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
			std::cout<<"Config::Section: "<<sectionName<<std::endl;
			continue;
		}
		if(sectionName=="Cuts")
		{
			unsigned int CutTyp=0;
			for (unsigned int i=0; i<operators_.size();i++)
			{
				if(line.find(operators_[i]) >line.size()) continue;
				operatorPositionStart = line.find(operators_[i]);
				operatorPositionEnd = operatorPositionStart + operators_[i].size()-1;
				
				CutTyp=i;
			}
			name = line.substr(0,operatorPositionStart);
			value =line.substr(operatorPositionStart,operatorPositionEnd-1);
			std::string cutTemp;
			double cutValue;
			cutTemp= line.substr(operatorPositionEnd+1);
			sscanf(cutTemp.c_str(), "%lf", &cutValue);
			std::cout<<"New cut with: Name: "<<name<<", cutTyp: "<<value<<", CutTyp: "<<CutTyp<<" cutValue: "<<cutValue<<std::endl;
			Cuts *cut = new Cuts(name,value,CutTyp,cutValue);
			cuts_[name]=cut;
		}
		if(sectionName=="Efficiencies")
		{
			if(line.find("(") >line.size() || line.find(")") >line.size() || line.find("=") >line.size()) continue;
			name = line.substr(0,line.find("(") );
			std::string xvarible =  line.substr(line.find("(")+1,line.find(",")-line.find("(")-1);
			std::string yvarible =  line.substr(line.find(",")+1,line.find(")") - line.find(",") -1 );
			value = line.substr(line.find("=")+1);
			std::cout<<"Efficiencies: Name: "<<name<<", xvarible: "<<xvarible<<", yvarible: "<<yvarible<<", nameInFile: "<<value<<std::endl;
			Efficiency *efficiency = new Efficiency(name,xvarible,yvarible,value);
			if(efficiencies_[name])
			{
				std::cout<<"Warning efficiency with name already declared!!!! will not work starting endless loop please wait until the end of time."<<std::endl;
				int i=1;
				while (i>0)
				{
					i=12;
				}
			}
			efficiencies_[name]=efficiency;
		}
	}
	initilized_=true;
}