// -*- C++ -*-
//
// Package:    AllHadronicSUSY/TreeMaker
// Class:      TreeMaker
// 
/**\class TreeMaker TreeMaker.cc AllHadronicSUSY/TreeMaker/plugins/TreeMaker.cc
 * 
 * Description: [one line class summary]
 * 
 * Implementation:
 *     [Notes on implementation]
 */
//
// Original Author:  Arne-Rasmus Draeger
//         Created:  Fri, 03 Dec 2014 13:48:35 GMT
//
//
#include "AllHadronicSUSY/TreeMaker/interface/TreeMaker.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include <memory>

// system include files

//
// constants, enums and typedefs
//


//
// static data member definitions
//

//
// constructors and destructor
//
TreeMaker::TreeMaker(const edm::ParameterSet& iConfig)
: nMaxCandidates_(200), tree_(0)
{
  // generell
  treeName_ = iConfig.getParameter<std::string>("TreeName");
  // input tags for float variables eg HT MHT MET or what not
  varsFloatNames_= iConfig.getParameter< std::vector<std::string> >  ("VarsFloat");
  // input tags for int variables eg NJets nBJets etc.
  varsIntNames_= iConfig.getParameter< std::vector<std::string> >  ("VarsInt");
  // input tags for bool variables eg filters
  varsBoolNames_= iConfig.getParameter< std::vector<std::string> >  ("VarsBool");
  // input tags for float variables eg HT MHT MET or what not
  varsRecoCandNames_= iConfig.getParameter< std::vector<std::string> >  ("VarsRecoCand");
}


TreeMaker::~TreeMaker()
{
  
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
TreeMaker::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace reco;
  using namespace pat;
  setBranchVariablesToDefault();
  

  tree_->Fill();
}

// ------------ method called once each job just before starting event loop  ------------
void 
TreeMaker::beginJob()
{
  edm::Service<TFileService> fs;
  if( !fs ) {
    throw edm::Exception(edm::errors::Configuration, "TFile Service is not registered in cfg file");
  }
  tree_ = fs->make<TTree>(treeName_,treeName_);  
  tree_->SetAutoSave(10000000000);
  tree_->SetAutoFlush(1000000);
  // loop over input varsFloat string to extract optional names in tree
  for(unsigned int i=0; i<varsRecoCandNames_.size();i++)
  {
    RecoCandN_.push_back(0);
    RecoCandPt_.push_back (new Float_t[200]);
    RecoCandEta_.push_back(new Float_t[200]);
    RecoCandPhi_.push_back(new Float_t[200]);
    RecoCandE_.push_back  (new Float_t[200]);

    std::string temp = varsRecoCandNames_[i];

    std::cout<<"RecoCandNameFull["<<i<<"]: "<<temp<<std::endl;
    if(temp.find('|')<temp.size() ) temp = temp.substr(0,temp.find("|") );
    std::cout<<"Temp string stored in main inputTag "<<temp<<std::endl;
    varsRecoCandTags_.push_back(edm::InputTag(temp));
    tree_->Branch((temp+"Num").c_str(),&(RecoCandN_[i]),(temp+"Num/s").c_str());
    tree_->Branch((temp+"Pt").c_str(), RecoCandPt_.at(i), (temp+"Pt["+temp+"Num]/F").c_str());
    tree_->Branch((temp+"Eta").c_str(),RecoCandEta_.at(i),(temp+"Eta["+temp+"Num]/F").c_str());
    tree_->Branch((temp+"Phi").c_str(),RecoCandPhi_.at(i),(temp+"Phi["+temp+"Num]/F").c_str());
    tree_->Branch((temp+"E").c_str(),  RecoCandE_.at(i),  (temp+"E["+temp+"Num]/F").c_str());
    std::string mainTagName=temp;
    temp = varsRecoCandNames_[i];
    unsigned int count=0;
    std::vector<Float_t*> vec;
    RecoCandAdditionalVariables_.push_back(vec);
    std::vector<edm::InputTag> tagvec;
    RecoCandAdditionalVariablesTags_.push_back(tagvec);
    std::string temp2="";
    while (temp.find('|')<temp.size() ) // loop over the posible additonal variables
    {
      RecoCandAdditionalVariables_[i].push_back(new Float_t[200]);
      temp = temp.substr(temp.find("|")+1 );
      temp2="";
      std::cout<<"| found in string: "<<temp<<std::endl;
      if(temp.find('|')<temp.size() ) temp2 = temp.substr(0, temp.find('|') );
      else temp2=temp;
      std::cout<<"| TagName: "<<temp2<<std::endl;
      RecoCandAdditionalVariablesTags_[i].push_back(edm::InputTag(temp2 ) );
      tree_->Branch((mainTagName+"_"+temp2).c_str(), RecoCandAdditionalVariables_.at(i).at(count), (mainTagName+"_"+temp2+"["+mainTagName+"Num]/F").c_str());
      count++;
    }
    RecoCandAdditionalVariablesN_.push_back(count);
  }
  
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TreeMaker::endJob() {
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TreeMaker::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
void 
TreeMaker::setBranchVariablesToDefault() 
{
  // event information

  
}

//define this as a plug-in
DEFINE_FWK_MODULE(TreeMaker);
