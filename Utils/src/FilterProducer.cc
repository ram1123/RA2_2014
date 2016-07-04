// -*- C++ -*-
//
// Package: FilterProducer
// Class: FilterProducer
//
/**\class FilterProducer FilterProducer.cc RA2Classic/FilterProducer/src/FilterProducer.cc
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
//
// class declaration
//
class FilterProducer : public edm::EDProducer {
public:
  explicit FilterProducer(const edm::ParameterSet&);
  ~FilterProducer();
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
private:
  virtual void beginJob() ;
  virtual void produce(edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  virtual void beginRun(edm::Run&, edm::EventSetup const&);
  virtual void endRun(edm::Run&, edm::EventSetup const&);
  virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
  virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);

// ----------member data ---------------------------
  edm::EDGetTokenT<edm::TriggerResults> noiseFilterTag_;
  //  edm::InputTag noiseFilterTag;

  std::string HBHENoiseFilter_Selector_;
  std::string HBHENoiseIsoFilter_Selector_;
  std::string CSCHaloNoiseFilter_Selector_;
  std::string GoodVtxNoiseFilter_Selector_;
  std::string EEBadScNoiseFilter_Selector_;
  std::string GlobalTightHalo2016NoiseFilter_Selector_;
  std::string EcalDeadCellTriggerPrimitiveNoiseFilter_Selector_;
  /*
  edm::InputTag HBHENoiseFilterLoose_Rerun_Selector_;
  edm::InputTag HBHENoiseFilterTight_Rerun_Selector_;
  edm::InputTag HBHENoiseIsoFilter_Rerun_Selector_;
  */
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
FilterProducer::FilterProducer(const edm::ParameterSet& iConfig):
  noiseFilterTag_(consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("noiseFilterTag")))
// HBHENoiseFilterTag_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("HBHENoiseFilterTag"))),
// HBHENoiseIsoFilterTag_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("HBHENoiseIsoFilterTag"))),
// CSCHaloNoiseFilterTag_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("CSCHaloNoiseFilterTag"))),
// GoodVtxNoiseFilterTag_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("GoodVtxNoiseFilterTag"))),
// EEBadScNoiseFilterTag_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("EEBadScNoiseFilterTag"))),
// GlobalTightHalo2016FilterTag_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("GlobalTightHalo2016FilterTag"))),
// EcalDeadCellTriggerPrimitiveFilterTag_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("EcalDeadCellTriggerPrimitiveFilterTag"))),
  //  HBHENoiseFilterLoose_Rerun_Selector_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("HBHENoiseFilterLoose"))),
  //HBHENoiseFilterTight_Rerun_Selector_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("HBHENoiseFilterTight"))),
  // HBHENoiseIsoFilter_Rerun_Selector_(consumes<edm::View<string> >(iConfig.getParameter<edm::InputTag>("HBHENoiseIsoFilter"))),
  //  noiseFilterToken_( noiseFilterToken )
{
  //  noiseFilterTag = iConfig.getParameter<edm::InputTag>("noiseFilterTag");
  HBHENoiseFilter_Selector_ =  iConfig.getParameter<std::string> ("HBHENoiseFilter_Selector_");  
  HBHENoiseIsoFilter_Selector_ =  iConfig.getParameter<std::string> ("HBHENoiseIsoFilter_Selector_");  
  CSCHaloNoiseFilter_Selector_ =  iConfig.getParameter<std::string> ("CSCHaloNoiseFilter_Selector_");
  GoodVtxNoiseFilter_Selector_ =  iConfig.getParameter<std::string> ("GoodVtxNoiseFilter_Selector_");
  EEBadScNoiseFilter_Selector_ =  iConfig.getParameter<std::string> ("EEBadScNoiseFilter_Selector_");
  GlobalTightHalo2016NoiseFilter_Selector_ =  iConfig.getParameter<std::string> ("GlobalTightHalo2016NoiseFilter_Selector_");
  EcalDeadCellTriggerPrimitiveNoiseFilter_Selector_ =  iConfig.getParameter<std::string> ("EcalDeadCellTriggerPrimitiveNoiseFilter_Selector_");

  produces<int>("passFilterHBHE");
  produces<int>("passFilterHBHEIso");
  produces<int>("passFilterCSCHalo");
  produces<int>("passFilterGoodVtx");
  produces<int>("passFilterEEBadSC");
  produces<int>("passFilterGlobalTightHalo2016");
  produces<int>("passFilterEcalDeadCellTriggerPrimitive");
  //  produces<int>("passFilterHBHELooseRerun");
  //produces<int>("passFilterHBHETightRerun");
  //produces<int>("passFilterHBHEIsoRerun");

 /*
 const std::string string0("passFilterHBHEIso");
 produces<std::vector<int> > (string0).setBranchAlias(string0);
 const std::string string1("passFilterHBHE");
 produces<std::vector<int> > (string1).setBranchAlias(string1);
 const std::string string2("passFilterCSCHalo");
 produces<std::vector<int> > (string2).setBranchAlias(string2);
 const std::string string3("passFilterGoodVtx");
 produces<std::vector<int> > (string3).setBranchAlias(string3);
 const std::string string4("passFilterEEBadSC");
 produces<std::vector<bool> > (string4).setBranchAlias(string4);
 */
}
FilterProducer::~FilterProducer()
{}
//
// member functions
//
// ------------ method called to produce the data ------------
void
FilterProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  /*
  std::auto_ptr<std::vector<int> > passFilter_HBHE(new std::vector<int>());
  std::auto_ptr<std::vector<int> > passFilter_HBHEIso(new std::vector<int>());
  std::auto_ptr<std::vector<int> > passFilter_CSCHalo(new std::vector<int>());
  std::auto_ptr<std::vector<int> > passFilter_GoodVtx(new std::vector<int>());
  std::auto_ptr<std::vector<bool> > passFilter_EEBadSC(new std::vector<bool>());
  */
  int passFilterHBHE=0;
  int passFilterHBHEIso=0;
  int passFilterCSCHalo=0;
  int passFilterGoodVtx=0;
  int passFilterEEBadSC=0;
  int passFilterGlobalTightHalo2016=0;
  int passFilterEcalDeadCellTriggerPrimitive=0;
  //  int passFilterBadMuon=0;
  //int passFilterBadChargedHadron=0;
  //  int passFilterHBHELooseRerun=0;
  //int passFilterHBHETightRerun=0;
  //int passFilterHBHEIsoRerun=0;


  //int passesTrigger;
  edm::Handle<edm::TriggerResults> noiseFilterBits_; //our trigger result object
  iEvent.getByToken(noiseFilterTag_,noiseFilterBits_);
  //  iEvent.getByToken(noiseFilterTag, noiseFilterBits_);
  const edm::TriggerNames &names = iEvent.triggerNames(*noiseFilterBits_);
      
  for (unsigned int i = 0, n = noiseFilterBits_->size(); i < n; ++i) {
    //    std::cout<<names.triggerName(i)<<" "<<noiseFilterBits_->accept(i)<<std::endl;
    if (names.triggerName(i) == HBHENoiseFilter_Selector_)
      passFilterHBHE=noiseFilterBits_->accept(i);
    if (names.triggerName(i) == HBHENoiseIsoFilter_Selector_)
      passFilterHBHEIso=noiseFilterBits_->accept(i);
    if (names.triggerName(i) == CSCHaloNoiseFilter_Selector_)
      passFilterCSCHalo=noiseFilterBits_->accept(i);
    if (names.triggerName(i) == GoodVtxNoiseFilter_Selector_)
      passFilterGoodVtx=noiseFilterBits_->accept(i);
    if (names.triggerName(i) == EEBadScNoiseFilter_Selector_)
      passFilterEEBadSC=noiseFilterBits_->accept(i);
    if (names.triggerName(i) == GlobalTightHalo2016NoiseFilter_Selector_)
      passFilterGlobalTightHalo2016=noiseFilterBits_->accept(i);
    if (names.triggerName(i) == EcalDeadCellTriggerPrimitiveNoiseFilter_Selector_)
      passFilterEcalDeadCellTriggerPrimitive=noiseFilterBits_->accept(i);
  }
  /*
  edm::Handle<bool> ifilterbadChCand;
  iEvent.getByToken("BadChCandFilter", ifilterbadChCand);
  int filterbadChCandidate = *ifilterbadChCand;
    
  edm::Handle<bool> ifilterbadPFMuon;
  iEvent.getByToken("BadPFMuon", ifilterbadPFMuon);
  int filterbadPFMuon = *ifilterbadPFMuon;
  */    
  /*
  edm::Handle<bool> HBHENoiseFilterLooseResultHandle;
  iEvent.getByToken(HBHENoiseFilterLoose_Rerun_Selector_, HBHENoiseFilterLooseResultHandle);
  bool HBHENoiseFilterLooseResult = *HBHENoiseFilterLooseResultHandle;
  if (!HBHENoiseFilterLooseResultHandle.isValid()) {
    LogDebug("") << "CaloTowerAnalyzer: Could not find HBHENoiseFilterResult" << std::endl;
  }
 
  passFilterHBHELooseRerun = HBHENoiseFilterLooseResult;

  edm::Handle<bool> HBHENoiseFilterTightResultHandle;
  iEvent.getByToken(HBHENoiseFilterTight_Rerun_Selector_, HBHENoiseFilterTightResultHandle);
  bool HBHENoiseFilterTightResult = *HBHENoiseFilterTightResultHandle;
  if (!HBHENoiseFilterTightResultHandle.isValid()) {
    LogDebug("") << "CaloTowerAnalyzer: Could not find HBHENoiseFilterResult" << std::endl;
  }
 
  passFilterHBHETightRerun = HBHENoiseFilterTightResult;
 
  edm::Handle<bool> HBHENoiseIsoFilterResultHandle;
  iEvent.getByToken(HBHENoiseIsoFilter_Rerun_Selector_, HBHENoiseIsoFilterResultHandle);
  bool HBHENoiseIsoFilterResult = *HBHENoiseIsoFilterResultHandle;
  if (!HBHENoiseIsoFilterResultHandle.isValid()) {
    LogDebug("") << "CaloTowerAnalyzer: Could not find HBHENoiseFilterResult" << std::endl;
  }

  passFilterHBHEIsoRerun = HBHENoiseIsoFilterResult;
  */

  std::auto_ptr<int> f0(new int(passFilterHBHE));
  iEvent.put(f0,"passFilterHBHE");
  std::auto_ptr<int> f1(new int(passFilterHBHEIso));
  iEvent.put(f1,"passFilterHBHEIso");
  std::auto_ptr<int> f2(new int(passFilterCSCHalo));
  iEvent.put(f2,"passFilterCSCHalo");
  std::auto_ptr<int> f3(new int(passFilterGoodVtx));
  iEvent.put(f3,"passFilterGoodVtx");
  std::auto_ptr<int> f4(new int(passFilterEEBadSC));
  iEvent.put(f4,"passFilterEEBadSC");
  std::auto_ptr<int> f5(new int(passFilterGlobalTightHalo2016));
  iEvent.put(f5,"passFilterGlobalTightHalo2016");
  std::auto_ptr<int> f6(new int(passFilterEcalDeadCellTriggerPrimitive));
  iEvent.put(f6,"passFilterEcalDeadCellTriggerPrimitive");
  //  std::auto_ptr<int> f7(new int(passFilterBadMuon));
  //iEvent.put(f7,"passFilterBadMuon");
  //std::auto_ptr<int> f8(new int(passFilterBadChargedHadron));
  //iEvent.put(f8,"passFilterBadChargedHadron");
  /*
  std::auto_ptr<int> f7(new int(passFilterHBHELooseRerun));
  iEvent.put(f7,"passFilterHBHELooseRerun");
  std::auto_ptr<int> f8(new int(passFilterHBHETightRerun));
  iEvent.put(f8,"passFilterHBHETightRerun");
  std::auto_ptr<int> f9(new int(passFilterHBHEIsoRerun));
  iEvent.put(f9,"passFilterHBHEIsoRerun");
  */
}  
// ------------ method called once each job just before starting event loop ------------
void
FilterProducer::beginJob()
{
}
// ------------ method called once each job just after ending the event loop ------------
void
FilterProducer::endJob() {
}
// ------------ method called when starting to processes a run ------------
void
FilterProducer::beginRun(edm::Run&, edm::EventSetup const&)
{
}
// ------------ method called when ending the processing of a run ------------
void
FilterProducer::endRun(edm::Run&, edm::EventSetup const&)
{
}
// ------------ method called when starting to processes a luminosity block ------------
void
FilterProducer::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}
// ------------ method called when ending the processing of a luminosity block ------------
void
FilterProducer::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}
// ------------ method fills 'descriptions' with the allowed parameters for the module ------------
void
FilterProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(FilterProducer);
