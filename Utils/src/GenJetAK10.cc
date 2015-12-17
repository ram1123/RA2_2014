// -*- C++ -*-
//
// Package:    GenJet
// Class:      GenJet
// 
/**\class GenJet GenJet.cc RA2Classic/GenJet/src/GenJet.cc
 * 
 * Description: [one line class summary]
 * 
 * Implementation:
 *     [Notes on implementation]
 */
//
// Original Author:  Arne-Rasmus Draeger,68/111,4719,
//         Created:  Fri Apr 11 16:35:33 CEST 2014
// $Id$
//
//


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
#include "DataFormats/PatCandidates/interface/Jet.h"
//
// class declaration
//

class GenJetAK10 : public edm::EDProducer {
public:
	explicit GenJetAK10(const edm::ParameterSet&);
	~GenJetAK10();
	
	static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
	
private:
	virtual void beginJob() ;
	virtual void produce(edm::Event&, const edm::EventSetup&);
	virtual void endJob() ;
	
	virtual void beginRun(edm::Run&, edm::EventSetup const&);
	virtual void endRun(edm::Run&, edm::EventSetup const&);
	virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
	virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
	edm::InputTag GenJetCollTag_;

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
GenJetAK10::GenJetAK10(const edm::ParameterSet& iConfig)
{
	//register your produc
	GenJetCollTag_ 				= 	iConfig.getParameter<edm::InputTag >("GenJetCollTag");	

	const std::string string1("GenJetAK10");
	produces<std::vector<pat::Jet> > (string1).setBranchAlias(string1);
        const std::string string2("GenAK10prunedMass");
        produces<std::vector<double> > (string2).setBranchAlias(string2);
        const std::string string3("GenAK10softdropMass");
	produces<std::vector<double> > (string3).setBranchAlias(string3);

        const std::string string4("GenAK10tau1");
        produces<std::vector<double> > (string4).setBranchAlias(string4);
        const std::string string5("GenAK10tau2");
        produces<std::vector<double> > (string5).setBranchAlias(string5);
        const std::string string6("GenAK10tau3");
        produces<std::vector<double> > (string6).setBranchAlias(string6);
	/* Examples
	 *   produces<ExampleData2>();
	 * 
	 *   //if do put with a label
	 *   produces<ExampleData2>("label");
	 * 
	 *   //if you want to put into the Run
	 *   produces<ExampleData2,InRun>();
	 */
	//now do what ever other initialization is needed
	
}


GenJetAK10::~GenJetAK10()
{
	
	// do anything here that needs to be done at desctruction time
	// (e.g. close files, deallocate resources etc.)
	
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
GenJetAK10::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;	

	std::auto_ptr< std::vector<pat::Jet> > selectedJet(new std::vector<pat::Jet>);

	std::auto_ptr< std::vector<double> > GenAK10prunedMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > GenAK10softdropMass(new std::vector<double>);

	std::auto_ptr< std::vector<double> > GenAK10tau1(new std::vector<double>);
	std::auto_ptr< std::vector<double> > GenAK10tau2(new std::vector<double>);
	std::auto_ptr< std::vector<double> > GenAK10tau3(new std::vector<double>);

	Handle<edm::View<pat::Jet> > jet;
	iEvent.getByLabel(GenJetCollTag_,jet);

	for(size_t i=0; i<jet->size();i++)
	{
	  selectedJet->push_back(pat::Jet(jet->at(i)));

	  GenAK10prunedMass->push_back( jet->at(i).userFloat("ak10GenJetsPrunedMass"));
	  GenAK10softdropMass->push_back( jet->at(i).userFloat("ak10GenJetsSoftDropMass"));//	  std::cout<<jet->at(i).pt()<<std::endl;

	  GenAK10tau1->push_back( jet->at(i).userFloat("NjettinessGenAK10:tau1"));
	  GenAK10tau2->push_back( jet->at(i).userFloat("NjettinessGenAK10:tau2"));
	  GenAK10tau3->push_back( jet->at(i).userFloat("NjettinessGenAK10:tau3"));
	}

	const std::string string1("GenJetAK10");
	iEvent.put(selectedJet,string1);
        const std::string string2("GenAK10prunedMass");
        iEvent.put(GenAK10prunedMass,string2);
        const std::string string3("GenAK10softdropMass");
        iEvent.put(GenAK10softdropMass,string3);	

        const std::string string4("GenAK10tau1");
        iEvent.put(GenAK10tau1,string4);	
        const std::string string5("GenAK10tau2");
        iEvent.put(GenAK10tau2,string5);	
        const std::string string6("GenAK10tau3");
        iEvent.put(GenAK10tau3,string6);	
}

// ------------ method called once each job just before starting event loop  ------------
void 
GenJetAK10::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
GenJetAK10::endJob() {
}

// ------------ method called when starting to processes a run  ------------
void 
GenJetAK10::beginRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
GenJetAK10::endRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
GenJetAK10::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
GenJetAK10::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
GenJetAK10::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
	//The following says we do not know what parameters are allowed so do no validation
	// Please change this to state exactly what you do use, even if it is no parameters
	edm::ParameterSetDescription desc;
	desc.setUnknown();
	descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(GenJetAK10);
