// -*- C++ -*-
//
// Package:    METDouble
// Class:      METDouble
// 
/**\class METDouble METDouble.cc RA2Classic/METDouble/src/METDouble.cc
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

//
// class declaration
//

class METDouble : public edm::EDProducer {
public:
	explicit METDouble(const edm::ParameterSet&);
	~METDouble();
	
	static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
	
private:
	virtual void beginJob() ;
	virtual void produce(edm::Event&, const edm::EventSetup&);
	virtual void endJob() ;
	
	virtual void beginRun(edm::Run&, edm::EventSetup const&);
	virtual void endRun(edm::Run&, edm::EventSetup const&);
	virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
	virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
	edm::InputTag metTag_;
	
	
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
METDouble::METDouble(const edm::ParameterSet& iConfig)
{
	//register your produc
	metTag_ = iConfig.getParameter<edm::InputTag> ("METTag");
	
	produces<double>("Pt");
	produces<double>("Phi");
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


METDouble::~METDouble()
{
	
	// do anything here that needs to be done at desctruction time
	// (e.g. close files, deallocate resources etc.)
	
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
METDouble::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	double metpt_=0, metphi_=0;;
	edm::Handle< edm::View<reco::MET> > MET;
	iEvent.getByLabel(metTag_,MET); 
	if(MET.isValid() ){
		metpt_=MET->at(0).pt();
		metphi_=MET->at(0).phi();
	}
	else std::cout<<"METDouble::Invlide Tag: "<<metTag_.label()<<std::endl;
	std::auto_ptr<double> htp(new double(metpt_));
	iEvent.put(htp,"Pt");
	std::auto_ptr<double> htp2(new double(metphi_));
	iEvent.put(htp2,"Phi");
	
}

// ------------ method called once each job just before starting event loop  ------------
void 
METDouble::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
METDouble::endJob() {
}

// ------------ method called when starting to processes a run  ------------
void 
METDouble::beginRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
METDouble::endRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
METDouble::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
METDouble::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
METDouble::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
	//The following says we do not know what parameters are allowed so do no validation
	// Please change this to state exactly what you do use, even if it is no parameters
	edm::ParameterSetDescription desc;
	desc.setUnknown();
	descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(METDouble);
