// -*- C++ -*-
//
// Package: TriggerProducer
// Class: TriggerProducer
//
/**\class TriggerProducer TriggerProducer.cc RA2Classic/TriggerProducer/src/TriggerProducer.cc
*/
//
// Original Author: Sam Bein,
// Created: Wednesday June 24 2015
// system include files
#include <memory>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include <DataFormats/Math/interface/deltaR.h>
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
//
// class declaration
//
class TriggerProducer : public edm::EDProducer {
public:
  explicit TriggerProducer(const edm::ParameterSet&);
  ~TriggerProducer();
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
private:
  virtual void beginJob() ;
  virtual void produce(edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  virtual void beginRun(edm::Run&, edm::EventSetup const&);
  virtual void endRun(edm::Run&, edm::EventSetup const&);
  virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
  virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
  void GetInputTag(edm::InputTag& tag, std::string arg1, std::string arg2, std::string arg3, std::string arg1_default);
  edm::InputTag trigResultsTag_;
  edm::InputTag trigPrescalesTag_;
  std::vector<std::string> parsedTrigNamesVec;
  // ----------member data ---------------------------
};
//
// constants, enums and typedefs
//
//
// static data member definitions
//
//
// constructors and destructor
//
TriggerProducer::TriggerProducer(const edm::ParameterSet& iConfig)
{
  parsedTrigNamesVec = iConfig.getParameter <std::vector<std::string> > ("triggerNameList");
  GetInputTag(trigResultsTag_,
	      iConfig.getParameter <std::string> ("trigTagArg1"),
	      iConfig.getParameter <std::string> ("trigTagArg2"),
	      iConfig.getParameter <std::string> ("trigTagArg3"),
	      "TriggerResults");
  GetInputTag(trigPrescalesTag_,
	      iConfig.getParameter <std::string> ("prescaleTagArg1"),
	      iConfig.getParameter <std::string> ("prescaleTagArg2"),
	      iConfig.getParameter <std::string> ("prescaleTagArg3"),
	      "patTrigger");
  produces<std::vector<std::string> >("TriggerNames");
  produces<std::vector<bool> >("TriggerPass");
  produces<std::vector<int> >("TriggerPrescales");
}
TriggerProducer::~TriggerProducer()
{}
//
// member functions
//
// ------------ helper function to make InputTags ------------
void
TriggerProducer::GetInputTag(edm::InputTag& tag, std::string arg1, std::string arg2, std::string arg3, std::string arg1_default=""){
// We we make the producer a little smarter. There are four cases we look at
// 1) arg1 and arg3 are set, if this is the case we create the label bases on all three arguments
// 2) arg3 is not set, in this case we create the label based only on arg1
// 3) Neither arg1 nor arg3 are set, in this case we default to searching for arg1_default
// 4) arg1 is not set, but arg3 is set, we look for arg1_default in the process defined by arg3
  if(arg1.empty()) arg1 = arg1_default;
  if(arg3.empty()){
    tag = edm::InputTag(arg1);
  } else {
    tag = edm::InputTag(arg1,arg2,arg3);
  }
}
// ------------ method called to produce the data ------------
void
TriggerProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  std::auto_ptr<std::vector<bool> > passTrigVec(new std::vector<bool>());
  std::auto_ptr<std::vector<int> > trigPrescaleVec(new std::vector<int>());
  std::auto_ptr<std::vector<std::string> > trigNamesVec(new std::vector<std::string>());
  //int passesTrigger;
  edm::Handle<edm::TriggerResults> trigResults; //our trigger result object
  iEvent.getByLabel(trigResultsTag_,trigResults);
  const edm::TriggerNames& trigNames = iEvent.triggerNames(*trigResults);
  edm::Handle<pat::PackedTriggerPrescales> trigPrescales;
  iEvent.getByLabel(trigPrescalesTag_,trigPrescales);
  //Find the matching triggers
  std::string testTriggerName;
  for(unsigned int trigIndex = 0; trigIndex < trigNames.size(); trigIndex++){
    testTriggerName = trigNames.triggerName(trigIndex);
    for(unsigned int parsedIndex = 0; parsedIndex < parsedTrigNamesVec.size(); parsedIndex++){
      if(testTriggerName.find(parsedTrigNamesVec.at(parsedIndex)) != std::string::npos){
	trigNamesVec->push_back(testTriggerName.c_str());
	passTrigVec->push_back(trigResults->accept(trigIndex));
	trigPrescaleVec->push_back(trigPrescales->getPrescaleForIndex(trigIndex));
	//std::cout << "Matched: " << testTriggerName << std::endl;
	//std::cout << "Pass Trigger?: " << trigResults->accept(trigIndex) << std::endl;
	//break; //We only match one trigger to each trigger name fragment passed
      }
    }
  }
  iEvent.put(passTrigVec,"TriggerPass");
  iEvent.put(trigPrescaleVec,"TriggerPrescales");
  iEvent.put(trigNamesVec,"TriggerNames");
}
// ------------ method called once each job just before starting event loop ------------
void
TriggerProducer::beginJob()
{
  std::cout << "will store trigger information for..." << std::endl;
  for(unsigned int i = 0; i< parsedTrigNamesVec.size(); i++)
    std::cout << parsedTrigNamesVec.at(i) << std::endl;
}
// ------------ method called once each job just after ending the event loop ------------
void
TriggerProducer::endJob() {
}
// ------------ method called when starting to processes a run ------------
void
TriggerProducer::beginRun(edm::Run&, edm::EventSetup const&)
{
}
// ------------ method called when ending the processing of a run ------------
void
TriggerProducer::endRun(edm::Run&, edm::EventSetup const&)
{
}
// ------------ method called when starting to processes a luminosity block ------------
void
TriggerProducer::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}
// ------------ method called when ending the processing of a luminosity block ------------
void
TriggerProducer::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}
// ------------ method fills 'descriptions' with the allowed parameters for the module ------------
void
TriggerProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(TriggerProducer);
