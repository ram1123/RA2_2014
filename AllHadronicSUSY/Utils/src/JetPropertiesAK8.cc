// -*- C++ -*-
//
// Package:    JetPropertiesAK8
// Class:      JetPropertiesAK8
// 
/**\class JetPropertiesAK8 JetPropertiesAK8.cc RA2Classic/JetPropertiesAK8/src/JetPropertiesAK8.cc
 * 
 * Description: [one line class summary]
 * 
 * Implementation:
 *     [Notes on implementation]
 */
//
// Original Author:  Luca Brianza
//         Created:  Mon, 12 Jan 2015
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
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/Candidate/interface/Candidate.h"

//
// class declaration
//

class JetPropertiesAK8 : public edm::EDProducer {
public:
	explicit JetPropertiesAK8(const edm::ParameterSet&);
	~JetPropertiesAK8();
	
	static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
	
private:
	virtual void beginJob() ;
	virtual void produce(edm::Event&, const edm::EventSetup&);
	virtual void endJob() ;
	
	virtual void beginRun(edm::Run&, edm::EventSetup const&);
	virtual void endRun(edm::Run&, edm::EventSetup const&);
	virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
	virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
	edm::InputTag JetTag_;
	std::string   btagname_;

	
	
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
JetPropertiesAK8::JetPropertiesAK8(const edm::ParameterSet& iConfig)
{
	JetTag_ = iConfig.getParameter<edm::InputTag>("JetTag");
	btagname_ = iConfig.getParameter<std::string>  ("BTagInputTag");
	//register your products
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
	//register your products
	produces<std::vector<pat::Jet> >();
	const std::string string0("AK8jetArea");
	produces<std::vector<double> > (string0).setBranchAlias(string0);
	const std::string string1("AK8chargedHadronEnergyFraction");
	produces<std::vector<double> > (string1).setBranchAlias(string1);
	const std::string string2("AK8chargedHadronMultiplicity");
	produces<std::vector<int> > (string2).setBranchAlias(string2);
	const std::string string3("AK8neutralHadronEnergyFraction");
	produces<std::vector<double> > (string3).setBranchAlias(string3);
	const std::string string4("AK8neutralHadronMultiplicity");
	produces<std::vector<int> > (string4).setBranchAlias(string4);
	const std::string string5("AK8chargedEmEnergyFraction");
	produces<std::vector<double> > (string5).setBranchAlias(string5);
	const std::string string6("AK8neutralEmEnergyFraction");
	produces<std::vector<double> > (string6).setBranchAlias(string6);
// 	const std::string string7("AK8patJetsNeutralEmFractionPBNR");
// 	produces<std::vector<double> > (string7).setBranchAlias(string7);
	const std::string string8("AK8electronMultiplicity");
	produces<std::vector<int> > (string8).setBranchAlias(string8);
	const std::string string9("AK8photonEnergyFraction");
	produces<std::vector<double> > (string9).setBranchAlias(string9);
	const std::string string10("AK8photonMultiplicity");
	produces<std::vector<int> > (string10).setBranchAlias(string10);
	const std::string string11("AK8muonEnergyFraction");
	produces<std::vector<double> > (string11).setBranchAlias(string11);
	const std::string string12("AK8muonMultiplicity");
	produces<std::vector<int> > (string12).setBranchAlias(string12);
	const std::string string14("AK8prunedMass");
	produces<std::vector<double> > (string14).setBranchAlias(string14);
	const std::string string15("AK8trimmedMass");
	produces<std::vector<double> > (string15).setBranchAlias(string15);
	const std::string string16("AK8filteredMass");
	produces<std::vector<double> > (string16).setBranchAlias(string16);
	const std::string string17("AK8tau1");
	produces<std::vector<double> > (string17).setBranchAlias(string17);
	const std::string string18("AK8tau2");
	produces<std::vector<double> > (string18).setBranchAlias(string18);
	const std::string string19("AK8tau3");
	produces<std::vector<double> > (string19).setBranchAlias(string19);
	
}


JetPropertiesAK8::~JetPropertiesAK8()
{
	
	// do anything here that needs to be done at desctruction time
	// (e.g. close files, deallocate resources etc.)
	
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
JetPropertiesAK8::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	std::auto_ptr<std::vector<pat::Jet> > AK8prodJets(new std::vector<pat::Jet>());
	
	std::auto_ptr< std::vector<double> > AK8jetArea(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK8chargedHadronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK8chargedHadronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK8neutralHadronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK8neutralHadronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK8chargedEmEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK8neutralEmEnergyFraction(new std::vector<double>);
// 	std::auto_ptr< std::vector<double> > AK8patJetsNeutralEmFractionPBNR(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK8electronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK8electronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK8photonEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK8photonMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK8muonEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK8muonMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK8prunedMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK8trimmedMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK8filteredMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK8tau1(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK8tau2(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK8tau3(new std::vector<double>);
	using namespace edm;
	using namespace reco;
	using namespace pat;
	edm::Handle< edm::View<pat::Jet> > Jets;
	iEvent.getByLabel(JetTag_,Jets);
	if( Jets.isValid() ) {
		for(unsigned int i=0; i<Jets->size();i++)
		{
			AK8prodJets->push_back(pat::Jet(Jets->at(i)));
			AK8jetArea->push_back( Jets->at(i).jetArea() );
			AK8chargedHadronEnergyFraction->push_back( Jets->at(i).chargedHadronEnergyFraction() );
			AK8chargedHadronMultiplicity->push_back( Jets->at(i).chargedHadronMultiplicity() );
			AK8neutralHadronEnergyFraction->push_back( Jets->at(i).neutralHadronEnergyFraction() );
			AK8neutralHadronMultiplicity->push_back( Jets->at(i).neutralHadronMultiplicity() );
			AK8chargedEmEnergyFraction->push_back( Jets->at(i).chargedEmEnergyFraction() );
			AK8neutralEmEnergyFraction->push_back( Jets->at(i).neutralEmEnergyFraction() );
// 			AK8patJetsNeutralEmFractionPBNR->push_back( Jets->at(i).patJetsNeutralEmFractionPBNR() / Jets->at(i).jecFactor(0) );
			AK8electronEnergyFraction->push_back( Jets->at(i).electronEnergyFraction() );
			AK8electronMultiplicity->push_back( Jets->at(i).electronMultiplicity() );
			AK8photonEnergyFraction->push_back( Jets->at(i).photonEnergyFraction() );
			AK8photonMultiplicity->push_back( Jets->at(i).photonMultiplicity() );
			AK8muonEnergyFraction->push_back( Jets->at(i).muonEnergyFraction() );
			AK8muonMultiplicity->push_back( Jets->at(i).muonMultiplicity() );

			AK8prunedMass->push_back( Jets->at(i).userFloat("ak8PFJetsCHSPrunedLinks"));
			AK8trimmedMass->push_back( Jets->at(i).userFloat("ak8PFJetsCHSTrimmedLinks"));
			AK8filteredMass->push_back( Jets->at(i).userFloat("ak8PFJetsCHSFilteredLinks"));

			AK8tau1->push_back( Jets->at(i).userFloat("NjettinessAK8:tau1"));
			AK8tau2->push_back( Jets->at(i).userFloat("NjettinessAK8:tau2"));
			AK8tau3->push_back( Jets->at(i).userFloat("NjettinessAK8:tau3"));
		}
	}
	const std::string string00("");
	iEvent.put(AK8prodJets );
	
	const std::string string0("AK8jetArea");
	iEvent.put(AK8jetArea,string0);
	const std::string string1("AK8chargedHadronEnergyFraction");
	iEvent.put(AK8chargedHadronEnergyFraction,string1);
	const std::string string2("AK8chargedHadronMultiplicity");
	iEvent.put(AK8chargedHadronMultiplicity,string2);
	const std::string string3("AK8neutralHadronEnergyFraction");
	iEvent.put(AK8neutralHadronEnergyFraction,string3);
	const std::string string4("AK8neutralHadronMultiplicity");
	iEvent.put(AK8neutralHadronMultiplicity,string4);
	const std::string string5("AK8chargedEmEnergyFraction");
	iEvent.put(AK8chargedEmEnergyFraction,string5);
	const std::string string6("AK8neutralEmEnergyFraction");
	iEvent.put(AK8neutralEmEnergyFraction,string6);
// 	const std::string string7("AK8patJetsNeutralEmFractionPBNR");
// 	iEvent.put(AK8patJetsNeutralEmFractionPBNR,string7);
	const std::string string8("AK8electronMultiplicity");
	iEvent.put(AK8electronMultiplicity,string8);
	const std::string string9("AK8photonEnergyFraction");
	iEvent.put(AK8photonEnergyFraction,string9);
	const std::string string10("AK8photonMultiplicity");
	iEvent.put(AK8photonMultiplicity,string10);
	const std::string string11("AK8muonEnergyFraction");
	iEvent.put(AK8muonEnergyFraction,string11);
	const std::string string12("AK8muonMultiplicity");
	iEvent.put(AK8muonMultiplicity,string12);
	const std::string string14("AK8prunedMass");
	iEvent.put(AK8prunedMass,string14);
	const std::string string15("AK8trimmedMass");
	iEvent.put(AK8trimmedMass,string15);
	const std::string string16("AK8filteredMass");
	iEvent.put(AK8filteredMass,string16);
	const std::string string17("AK8tau1");
	iEvent.put(AK8tau1,string17);
	const std::string string18("AK8tau2");
	iEvent.put(AK8tau2,string18);
	const std::string string19("AK8tau3");
	iEvent.put(AK8tau3,string19);
	
}

// ------------ method called once each job just before starting event loop  ------------
void 
JetPropertiesAK8::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
JetPropertiesAK8::endJob() {
}

// ------------ method called when starting to processes a run  ------------
void 
JetPropertiesAK8::beginRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
JetPropertiesAK8::endRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
JetPropertiesAK8::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
JetPropertiesAK8::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
JetPropertiesAK8::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
	//The following says we do not know what parameters are allowed so do no validation
	// Please change this to state exactly what you do use, even if it is no parameters
	edm::ParameterSetDescription desc;
	desc.setUnknown();
	descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(JetPropertiesAK8);
