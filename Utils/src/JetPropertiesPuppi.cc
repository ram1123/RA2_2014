// -*- C++ -*-
//
// Package:    JetPropertiesPuppi
// Class:      JetPropertiesPuppi
// 
/**\class JetPropertiesPuppi JetPropertiesPuppi.cc RA2Classic/JetPropertiesPuppi/src/JetPropertiesPuppi.cc
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
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrectorCalculator.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
//
// class declaration
//

class JetPropertiesPuppi : public edm::EDProducer {
public:
	explicit JetPropertiesPuppi(const edm::ParameterSet&);
	~JetPropertiesPuppi();
	
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
	edm::InputTag prunedJetTag_;
	edm::InputTag softdropJetTag_;
	std::string   btagname_;
        edm::InputTag RhoTag_;
  std::string l1file;
  std::string l2file;
  std::string l3file;
  std::string l2l3file;
  std::string uncfile;
  bool doJEC;
  bool doReclusteringForPrunedAndSoftdrop;
  //	edm::InputTag puppiJetTag_;
  double MinPt_;
  JetCorrectorParameters *L2L3JetPar;
  //  std::vector<std::string> jecPayloadNames_;
	
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
JetPropertiesPuppi::JetPropertiesPuppi(const edm::ParameterSet& iConfig)
  //  jecPayloadNames_( iConfig.getParameter<std::vector<std::string> >("jecPayloadNames") ) // JEC level payloads
{
	JetTag_ = iConfig.getParameter<edm::InputTag>("JetTag");
	prunedJetTag_ = iConfig.getParameter<edm::InputTag>("prunedJetTag");
	softdropJetTag_ = iConfig.getParameter<edm::InputTag>("softdropJetTag");
	btagname_ = iConfig.getParameter<std::string>  ("BTagInputTag");
	RhoTag_ = iConfig.getParameter<edm::InputTag>("RhoTag");
	l1file = iConfig.getParameter<std::string>  ("L1File");
	l2file = iConfig.getParameter<std::string>  ("L2File");
	l3file = iConfig.getParameter<std::string>  ("L3File");
	l2l3file = iConfig.getParameter<std::string>  ("L2L3File");
	uncfile = iConfig.getParameter<std::string>  ("uncFile");
	doJEC = iConfig.getParameter<bool>  ("doJEC");
	doReclusteringForPrunedAndSoftdrop = iConfig.getParameter<bool>  ("doReclusteringForPrunedAndSoftdrop");
	//puppiJetTag_ = iConfig.getParameter<edm::InputTag>("puppiJetTag");
        MinPt_ = iConfig.getParameter <double> ("MinPt");
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
	const std::string string0("PuppijetArea");
	produces<std::vector<double> > (string0).setBranchAlias(string0);
	const std::string string1("PuppichargedHadronEnergyFraction");
	produces<std::vector<double> > (string1).setBranchAlias(string1);
	const std::string string2("PuppichargedHadronMultiplicity");
	produces<std::vector<int> > (string2).setBranchAlias(string2);
	const std::string string3("PuppineutralHadronEnergyFraction");
	produces<std::vector<double> > (string3).setBranchAlias(string3);
	const std::string string4("PuppineutralHadronMultiplicity");
	produces<std::vector<int> > (string4).setBranchAlias(string4);
	const std::string string5("PuppichargedEmEnergyFraction");
	produces<std::vector<double> > (string5).setBranchAlias(string5);
	const std::string string6("PuppineutralEmEnergyFraction");
	produces<std::vector<double> > (string6).setBranchAlias(string6);
// 	const std::string string7("PuppipatJetsNeutralEmFractionPBNR");
// 	produces<std::vector<double> > (string7).setBranchAlias(string7);
	const std::string string8("PuppielectronMultiplicity");
	produces<std::vector<int> > (string8).setBranchAlias(string8);
	const std::string string9("PuppiphotonEnergyFraction");
	produces<std::vector<double> > (string9).setBranchAlias(string9);
	const std::string string10("PuppiphotonMultiplicity");
	produces<std::vector<int> > (string10).setBranchAlias(string10);
	const std::string string11("PuppimuonEnergyFraction");
	produces<std::vector<double> > (string11).setBranchAlias(string11);
	const std::string string12("PuppimuonMultiplicity");
	produces<std::vector<int> > (string12).setBranchAlias(string12);
	const std::string string14("PuppiprunedMass");
	produces<std::vector<double> > (string14).setBranchAlias(string14);
	const std::string string15("PuppitrimmedMass");
	produces<std::vector<double> > (string15).setBranchAlias(string15);
	const std::string string16("PuppifilteredMass");
	produces<std::vector<double> > (string16).setBranchAlias(string16);
	const std::string string17("Puppitau1");
	produces<std::vector<double> > (string17).setBranchAlias(string17);
	const std::string string18("Puppitau2");
	produces<std::vector<double> > (string18).setBranchAlias(string18);
	const std::string string19("Puppitau3");
	produces<std::vector<double> > (string19).setBranchAlias(string19);
	const std::string string20("PuppiisLooseJetId");
	produces<std::vector<bool> > (string20).setBranchAlias(string20);
	const std::string string21("PuppisoftDropMass");
	produces<std::vector<double> > (string21).setBranchAlias(string21);
        const std::string string22("PuppibDiscriminatorCSV");
        produces<std::vector<double> > (string22).setBranchAlias(string22);
        const std::string string23("PuppibDiscriminatorICSV");
        produces<std::vector<double> > (string23).setBranchAlias(string23);
        const std::string string24("PtCorr");
        produces<std::vector<double> > (string24).setBranchAlias(string24);
        const std::string string25("EtaCorr");
        produces<std::vector<double> > (string25).setBranchAlias(string25);
        const std::string string26("PhiCorr");
        produces<std::vector<double> > (string26).setBranchAlias(string26);
        const std::string string27("ECorr");
        produces<std::vector<double> > (string27).setBranchAlias(string27);
	const std::string string28("PuppiisTightJetId");
	produces<std::vector<bool> > (string28).setBranchAlias(string28);
	const std::string string29("mass");
	produces<std::vector<double> > (string29).setBranchAlias(string29);
	const std::string string30("Puppicorrection");
	produces<std::vector<double> > (string30).setBranchAlias(string30);
	const std::string string31("PuppicorrectionUp");
	produces<std::vector<double> > (string31).setBranchAlias(string31);
	const std::string string32("PuppicorrectionDown");
	produces<std::vector<double> > (string32).setBranchAlias(string32);
	const std::string string33("PuppisoftDropPt");
	produces<std::vector<double> > (string33).setBranchAlias(string33);
	const std::string string34("PuppimassCorrection");
	produces<std::vector<double> > (string34).setBranchAlias(string30);
	const std::string string35("PuppimassCorrectionUp");
	produces<std::vector<double> > (string35).setBranchAlias(string35);
	const std::string string36("PuppimassCorrectionDown");
	produces<std::vector<double> > (string36).setBranchAlias(string36);
	//        const std::string string28("PuppipuppiMass");
        //produces<std::vector<double> > (string28).setBranchAlias(string28);

}


JetPropertiesPuppi::~JetPropertiesPuppi()
{
	
	// do anything here that needs to be done at desctruction time
	// (e.g. close files, deallocate resources etc.)
	
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
JetPropertiesPuppi::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	std::auto_ptr<std::vector<pat::Jet> > PuppiprodJets(new std::vector<pat::Jet>());
	
	std::auto_ptr< std::vector<double> > PuppijetArea(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppichargedHadronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > PuppichargedHadronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > PuppineutralHadronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > PuppineutralHadronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > PuppichargedEmEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppineutralEmEnergyFraction(new std::vector<double>);
// 	std::auto_ptr< std::vector<double> > PuppipatJetsNeutralEmFractionPBNR(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppielectronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > PuppielectronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > PuppiphotonEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > PuppiphotonMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > PuppimuonEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > PuppimuonMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > PuppiprunedMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppisoftDropMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppisoftDropPt(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppitrimmedMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppifilteredMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > Puppitau1(new std::vector<double>);
	std::auto_ptr< std::vector<double> > Puppitau2(new std::vector<double>);
	std::auto_ptr< std::vector<double> > Puppitau3(new std::vector<double>);
	std::auto_ptr< std::vector<bool> > PuppiisLooseJetId(new std::vector<bool>);
	std::auto_ptr< std::vector<bool> > PuppiisTightJetId(new std::vector<bool>);
	std::auto_ptr< std::vector<double> > PuppibDiscriminatorCSV(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppibDiscriminatorICSV(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PtCorr(new std::vector<double>);
	std::auto_ptr< std::vector<double> > EtaCorr(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PhiCorr(new std::vector<double>);
	std::auto_ptr< std::vector<double> > ECorr(new std::vector<double>);
	std::auto_ptr< std::vector<double> > mass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > Puppicorrection(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppicorrectionUp(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppicorrectionDown(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppimassCorrection(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppimassCorrectionUp(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PuppimassCorrectionDown(new std::vector<double>);
	//	std::auto_ptr< std::vector<double> > PuppipuppiMass(new std::vector<double>);
	using namespace edm;
	using namespace reco;
	using namespace pat;
	edm::Handle< edm::View<pat::Jet> > Jets;
	iEvent.getByLabel(JetTag_,Jets);
	edm::Handle< edm::View<pat::Jet> > prunedJets;
	iEvent.getByLabel(prunedJetTag_,prunedJets);
	edm::Handle< edm::View<pat::Jet> > softdropJets;
	iEvent.getByLabel(softdropJetTag_,softdropJets);
	edm::Handle<double> rho_ ;
        iEvent.getByLabel(RhoTag_, rho_);
	//edm::Handle< edm::View<pat::Jet> > puppiJets;
	//iEvent.getByLabel(puppiJetTag_,puppiJets);

	//  Load the JetCorrectorParameter objects into a vector, IMPORTANT: THE ORDER MATTERS HERE !!!! 
	std::vector<JetCorrectorParameters> vPar;
	std::vector<JetCorrectorParameters> vParMass;
	//	std::vector<JetCorrectionUncertainty> vParUnc;
	/*	for ( std::vector<std::string>::const_iterator payloadBegin = jecPayloadNames_.begin(),
		payloadEnd = jecPayloadNames_.end(), ipayload = payloadBegin; ipayload != payloadEnd; ++ipayload ) {
	  JetCorrectorParameters pars(*ipayload);
	  vPar.push_back(pars);
	  }*/

        if (l2l3file!="NONE")
          L2L3JetPar  = new JetCorrectorParameters(l2l3file);
	//	JetCorrectorParameters L3JetPar(*l3file);
	JetCorrectorParameters *L3JetPar  = new JetCorrectorParameters(l3file);
	JetCorrectorParameters *L2JetPar  = new JetCorrectorParameters(l2file);
	JetCorrectorParameters *L1JetPar  = new JetCorrectorParameters(l1file);

	vPar.push_back(*L1JetPar);
	vPar.push_back(*L2JetPar);
	vPar.push_back(*L3JetPar);
        if (l2l3file!="NONE")
	  vPar.push_back(*L2L3JetPar);

	vParMass.push_back(*L2JetPar);
	vParMass.push_back(*L3JetPar);
        if (l2l3file!="NONE")
	  vParMass.push_back(*L2L3JetPar);

	JetCorrectionUncertainty *JetUnc  = new JetCorrectionUncertainty(uncfile);
	//	vParUnc.push_back(*JetUnc);
	
	FactorizedJetCorrector *JetCorrector = new FactorizedJetCorrector(vPar);
	FactorizedJetCorrector *JetMassCorrector = new FactorizedJetCorrector(vParMass);
	FactorizedJetCorrector *JetPrunedCorrector = new FactorizedJetCorrector(vParMass);
	FactorizedJetCorrector *JetSoftdropCorrector = new FactorizedJetCorrector(vParMass);

	TLorentzVector FatJet; 
	pat::Jet prunedjet;
	pat::Jet softdropjet;
	TLorentzVector jetPruned; 
	TLorentzVector jetSoftdrop; 	
	reco::Candidate::LorentzVector uncorrJet;
	reco::Candidate::LorentzVector uncorrPrunedJet;
	reco::Candidate::LorentzVector uncorrSoftdropJet;

	double correction;
	double corrUp;
	double corrDown;
	double massCorrection;
	double massCorrUp;
	double massCorrDown;
	
	if( Jets.isValid() ) {
	  edm::View<pat::Jet>::const_iterator ijet = Jets->begin();
	  //	  edm::View<pat::Jet>::const_iterator puppiJet = puppiJets->begin();
		for(unsigned int i=0; i<Jets->size();i++)
		{
		  if (Jets->at(i).pt()<MinPt_)  continue;

		  bool looseJetId=false;
		  bool tightJetId=false;

		  // The pat::Jet "knows" if it has been corrected, so here
		  // we can "uncorrect" the entire jet to apply the corrections
		  // we want here.
		  pat::Jet const * pJet = dynamic_cast<pat::Jet const *>( &*ijet );
		  if ( pJet != 0 ) {
		    uncorrJet = pJet->correctedP4(0);
		  }
		  // Otherwise, if we do not have pat::Jets on input, we just assume
		  // the user has not corrected them upstream and use it as raw.
		  else {
		    uncorrJet = ijet->p4();
		  }

		  JetCorrector->setJetEta(uncorrJet.eta());
		  JetCorrector->setJetPt(uncorrJet.pt());
		  JetCorrector->setJetA(ijet->jetArea());
		  JetCorrector->setRho(*(rho_.product())); 

		  
		  JetMassCorrector->setJetEta(uncorrJet.eta());
		  JetMassCorrector->setJetPt(uncorrJet.pt());
		  JetMassCorrector->setJetA(ijet->jetArea());
		  JetMassCorrector->setRho(*(rho_.product())); 
		  

		  correction = 1.;
		  massCorrection = 1.;

		  if (doJEC) {
		    correction = JetCorrector->getCorrection();
		    massCorrection = JetMassCorrector->getCorrection();
		    //mass->push_back( massCorrection*uncorrJet.mass());
		  }
		  mass->push_back( massCorrection*uncorrJet.mass());

		  JetUnc->setJetEta( uncorrJet.eta() );
		  JetUnc->setJetPt( massCorrection * uncorrJet.pt() );
		  massCorrUp = massCorrection * (1 + fabs(JetUnc->getUncertainty(1)));
		  JetUnc->setJetEta( uncorrJet.eta() );
		  JetUnc->setJetPt( massCorrection * uncorrJet.pt() );
		  massCorrDown = massCorrection * ( 1 - fabs(JetUnc->getUncertainty(-1)) );
		  
		  //		  else
		  // mass->push_back( Jets->at(i).mass());
		  
		  //		  std::cout<<"DEBUG - Puppi- raw pt: "<<uncorrJet.pt()<<" corr: "<<correction<<" corr pt: "<<correction*uncorrJet.pt()
		  //			   <<" raw mass: "<<uncorrJet.mass()<<" massCorr: "<<massCorrection<<" corr mass: "<<massCorrection*uncorrJet.mass()<<std::endl;
		  JetUnc->setJetEta( uncorrJet.eta() );
		  JetUnc->setJetPt( correction * uncorrJet.pt() );
		  corrUp = correction * (1 + fabs(JetUnc->getUncertainty(1)));
		  JetUnc->setJetEta( uncorrJet.eta() );
		  JetUnc->setJetPt( correction * uncorrJet.pt() );
		  corrDown = correction * ( 1 - fabs(JetUnc->getUncertainty(-1)) );

		  ijet++;
	//	(Jets->at(i)).scaleEnergy(correction);
	//	reco::Candidate::LorentzVector jet4V = correction*(Jets->at(i).p4());		  
		  PuppiprodJets->push_back(pat::Jet(Jets->at(i)));

		  //	  PuppiprodJets->push_back(reco::Candidate::LorentzVector(jet4V));
		  if (doJEC) {
		    PtCorr->push_back(correction*uncorrJet.pt());
		    EtaCorr->push_back(correction*uncorrJet.eta());
		    PhiCorr->push_back(correction*uncorrJet.phi());
		    ECorr->push_back(correction*uncorrJet.e());
		  }
		  else {
		    PtCorr->push_back(Jets->at(i).pt());
		    EtaCorr->push_back(Jets->at(i).eta());
		    PhiCorr->push_back(Jets->at(i).phi());
		    ECorr->push_back(Jets->at(i).energy());
		  }
		  PuppijetArea->push_back( Jets->at(i).jetArea() );
		  PuppichargedHadronEnergyFraction->push_back( Jets->at(i).chargedHadronEnergyFraction() );
		  PuppichargedHadronMultiplicity->push_back( Jets->at(i).chargedHadronMultiplicity() );
		  PuppineutralHadronEnergyFraction->push_back( Jets->at(i).neutralHadronEnergyFraction() );
		  PuppineutralHadronMultiplicity->push_back( Jets->at(i).neutralHadronMultiplicity() );
		  PuppichargedEmEnergyFraction->push_back( Jets->at(i).chargedEmEnergyFraction() );
		  PuppineutralEmEnergyFraction->push_back( Jets->at(i).neutralEmEnergyFraction() );
		  // 			PuppipatJetsNeutralEmFractionPBNR->push_back( Jets->at(i).patJetsNeutralEmFractionPBNR() / Jets->at(i).jecFactor(0) );
		  PuppielectronEnergyFraction->push_back( Jets->at(i).electronEnergyFraction() );
		  PuppielectronMultiplicity->push_back( Jets->at(i).electronMultiplicity() );
		  PuppiphotonEnergyFraction->push_back( Jets->at(i).photonEnergyFraction() );
		  PuppiphotonMultiplicity->push_back( Jets->at(i).photonMultiplicity() );
		  PuppimuonEnergyFraction->push_back( Jets->at(i).muonEnergyFraction() );
		  PuppimuonMultiplicity->push_back( Jets->at(i).muonMultiplicity() );

		  PuppitrimmedMass->push_back( -1.);
		  PuppifilteredMass->push_back( -1.);

		  //		  PuppitrimmedMass->push_back( massCorrection*Jets->at(i).userFloat("ak8PFJetsCHSTrimmedMass"));
		  //		  PuppifilteredMass->push_back( massCorrection*Jets->at(i).userFloat("ak8PFJetsCHSFilteredMass"));

		  Puppicorrection->push_back( correction );
		  PuppicorrectionUp->push_back( corrUp );
		  PuppicorrectionDown->push_back( corrDown );

		  PuppimassCorrection->push_back( massCorrection );
		  PuppimassCorrectionUp->push_back( massCorrUp );
		  PuppimassCorrectionDown->push_back( massCorrDown );

		   /*double dR=1000.;
		   double tempMass=0.;

		   for (unsigned int j=0; j<puppiJets->size(); j++) {
		     if (deltaR(Jets->at(i).eta(),Jets->at(i).phi(),puppiJets->at(j).eta(),puppiJets->at(j).phi()) < dR) {
		       dR = deltaR(Jets->at(i).eta(),Jets->at(i).phi(),puppiJets->at(j).eta(),puppiJets->at(j).phi());
		       if (dR<0.1)
			 tempMass = puppiJets->at(j).mass();			 
		     }
		   }		    
		   PuppipuppiMass->push_back(tempMass); 		  
		   */	
		   //						std::cout<<"DEBUG: "<<Jets->at(i).userFloat("ak8PFJetsCHSSoftDropLinks")<<std::endl;

		   Puppitau1->push_back( Jets->at(i).userFloat("NjettinessAK8Puppi:tau1"));
		   Puppitau2->push_back( Jets->at(i).userFloat("NjettinessAK8Puppi:tau2"));
		   Puppitau3->push_back( Jets->at(i).userFloat("NjettinessAK8Puppi:tau3"));
		   
		   PuppibDiscriminatorCSV->push_back( Jets->at(i).bDiscriminator("combinedSecondaryVertexBJetTags") );
		   PuppibDiscriminatorICSV->push_back( Jets->at(i).bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
		   
		   float NHF = Jets->at(i).neutralHadronEnergyFraction();
		   float NEMF = Jets->at(i).neutralEmEnergyFraction();
		   float CHF = Jets->at(i).chargedHadronEnergyFraction();
		   float MUF = Jets->at(i).muonEnergyFraction();
		   float CEMF = Jets->at(i).chargedEmEnergyFraction();
		   int NumConst = Jets->at(i).chargedMultiplicity()+Jets->at(i).neutralMultiplicity();
		   int CHM = Jets->at(i).chargedMultiplicity(); 

		   if ((NHF<0.99 && NEMF<0.99 && NumConst>1 && MUF<0.8) && ((abs(Jets->at(i).eta())<=2.4 && CHF>0 && CHM>0 && CEMF<0.99) || abs(Jets->at(i).eta())>2.4))  looseJetId=true;
		   if ((NHF<0.90 && NEMF<0.90 && NumConst>1 && MUF<0.8) && ((abs(Jets->at(i).eta())<=2.4 && CHF>0 && CHM>0 && CEMF<0.90) || abs(Jets->at(i).eta())>2.4))  tightJetId=true;

		   /*		   if (Jets->at(i).nConstituents() > 1 && //OLD JET LOOSE ID
		       Jets->at(i).photonEnergyFraction() < 0.99 &&
		       Jets->at(i).neutralHadronEnergyFraction() < 0.99 &&
		       Jets->at(i).muonEnergyFraction() < 0.8 &&
		       Jets->at(i).electronEnergyFraction() < 0.9 &&
		       (Jets->at(i).chargedHadronMultiplicity() > 0 || fabs(Jets->at(i).eta())>2.4 ) &&
		       (Jets->at(i).chargedEmEnergyFraction() < 0.99 || fabs(Jets->at(i).eta())>2.4 ) &&
		       (Jets->at(i).chargedHadronEnergyFraction() > 0. || fabs(Jets->at(i).eta())>2.4 ) )
		     looseJetId = true;
		   */
		   PuppiisLooseJetId->push_back(looseJetId);
		   PuppiisTightJetId->push_back(tightJetId);

		   if (doReclusteringForPrunedAndSoftdrop) {

		     FatJet.SetPtEtaPhiE( Jets->at(i).pt(), Jets->at(i).eta(), Jets->at(i).phi(), Jets->at(i).energy() ); 

		     float dRmin =  999. ;
		     double softdropCorrection = 1.;
		     double prunedCorrection = 1.;
		     bool foundSoftdrop=false;
		     bool foundPruned=false;

		     if( softdropJets.isValid() && softdropJets->size()>0) {

		       for (const pat::Jet &pj : *softdropJets) {
			 jetSoftdrop.SetPtEtaPhiE( pj.pt(), pj.eta(), pj.phi(), pj.energy() );
			 float dRtmp   = FatJet.DeltaR(jetSoftdrop);
			 if( dRtmp < dRmin && dRtmp < 1.0 ){ dRmin = dRtmp; softdropjet = pj; foundSoftdrop=true; }
			 else continue;
		       }

		       if (foundSoftdrop) {
			 uncorrSoftdropJet= softdropjet.correctedP4(0);

			 JetSoftdropCorrector->setJetEta(uncorrSoftdropJet.eta());
			 JetSoftdropCorrector->setJetPt(uncorrSoftdropJet.pt());
			 JetSoftdropCorrector->setJetA(softdropjet.jetArea());
			 JetSoftdropCorrector->setRho(*(rho_.product())); 
		       
			 softdropCorrection = JetSoftdropCorrector->getCorrection();

			 if (doJEC) {
			   PuppisoftDropMass->push_back( softdropCorrection*uncorrSoftdropJet.mass());		       
			   PuppisoftDropPt->push_back( softdropCorrection*uncorrSoftdropJet.pt());		       
			 }
			 else {
			   PuppisoftDropMass->push_back( 1.*uncorrSoftdropJet.mass());		       		     
			   PuppisoftDropPt->push_back( 1.*uncorrSoftdropJet.pt());		       		     
			 }

			 //			 std::cout<<"DEBUG - SD- raw pt: "<<uncorrSoftdropJet.pt()
			 // <<" raw mass: "<<uncorrSoftdropJet.mass()<<" massCorr: "<<softdropCorrection<<" corr mass: "
			 //	  <<softdropCorrection*uncorrSoftdropJet.mass()<<std::endl;
		       }
		       else {
			 PuppisoftDropMass->push_back( -1.);
			 PuppisoftDropPt->push_back(-1.0);
		       }
		     }
		     else {
			 PuppisoftDropMass->push_back( -1.);		       		     
			 PuppisoftDropPt->push_back(-1.0);
		     }

		     //		     FatJet.SetPtEtaPhiE( Jets->at(i).pt(), Jets->at(i).eta(), Jets->at(i).phi(), Jets->at(i).energy() ); 

		     dRmin =  999. ;

		     if( prunedJets.isValid() && prunedJets->size()>0) {

		       for (const pat::Jet &pj : *prunedJets) {
			 jetPruned.SetPtEtaPhiE( pj.pt(), pj.eta(), pj.phi(), pj.energy() );
			 float dRtmp   = FatJet.DeltaR(jetPruned);
			 if( dRtmp < dRmin && dRtmp < 1.0 ){ dRmin = dRtmp; prunedjet = pj; foundPruned=true;}
			 else continue;
		       }

		       if (foundPruned) {
			 uncorrPrunedJet= prunedjet.correctedP4(0);
		       
			 JetPrunedCorrector->setJetEta(uncorrPrunedJet.eta());
			 JetPrunedCorrector->setJetPt(uncorrPrunedJet.pt());
			 JetPrunedCorrector->setJetA(prunedjet.jetArea());
			 JetPrunedCorrector->setRho(*(rho_.product())); 

			 prunedCorrection = JetPrunedCorrector->getCorrection();

			 if (doJEC) 
			   PuppiprunedMass->push_back( prunedCorrection*uncorrPrunedJet.mass());
			 else 
			   PuppiprunedMass->push_back( 1.*uncorrPrunedJet.mass());
		       }
		       else
			 PuppiprunedMass->push_back( -1.);		       		     

		       //			 std::cout<<"DEBUG - PR- raw pt: "<<uncorrPrunedJet.pt()
		       //  <<" raw mass: "<<uncorrPrunedJet.mass()<<" massCorr: "<<prunedCorrection<<" corr mass: "
		       //	  <<softdropCorrection*uncorrPrunedJet.mass()<<std::endl;

		     }
		     else
			 PuppiprunedMass->push_back( -1.);		       		     

		     //		     std::cout<<prunedCorrection<<" "<<Jets->at(i).pt()<<" "<<Jets->at(i).mass()<<" "<<prunedjet.pt()<<" "<<prunedjet.mass()<<" "<<uncorrPrunedJet.pt()<<" "<<uncorrPrunedJet.mass()<<std::endl; getchar();

		   }

		   else {
		     PuppiprunedMass->push_back( massCorrection*Jets->at(i).userFloat("ak8PFJetsPuppiPrunedMass"));
		     PuppisoftDropMass->push_back( massCorrection*Jets->at(i).userFloat("ak8PFJetsPuppiSoftDropMass"));
		     auto sdSubjets = Jets->at(i).subjets("SoftDrop");
		     if ( sdSubjets.size() > 1 ) {
		       auto sdp4 = sdSubjets[0]->p4() + sdSubjets[1]->p4();
		       PuppisoftDropPt->push_back( sdp4.pt() );
		     } else {
		       PuppisoftDropPt->push_back( -1.0 );
		     }
		   }

		}
	}
	delete JetCorrector;
	delete JetMassCorrector;
	delete JetPrunedCorrector;
	delete JetSoftdropCorrector;
	delete JetUnc;
	delete L1JetPar;
	delete L2JetPar;
	delete L3JetPar;

	const std::string string00("");
	iEvent.put(PuppiprodJets );
	
	const std::string string0("PuppijetArea");
	iEvent.put(PuppijetArea,string0);
	const std::string string1("PuppichargedHadronEnergyFraction");
	iEvent.put(PuppichargedHadronEnergyFraction,string1);
	const std::string string2("PuppichargedHadronMultiplicity");
	iEvent.put(PuppichargedHadronMultiplicity,string2);
	const std::string string3("PuppineutralHadronEnergyFraction");
	iEvent.put(PuppineutralHadronEnergyFraction,string3);
	const std::string string4("PuppineutralHadronMultiplicity");
	iEvent.put(PuppineutralHadronMultiplicity,string4);
	const std::string string5("PuppichargedEmEnergyFraction");
	iEvent.put(PuppichargedEmEnergyFraction,string5);
	const std::string string6("PuppineutralEmEnergyFraction");
	iEvent.put(PuppineutralEmEnergyFraction,string6);
// 	const std::string string7("PuppipatJetsNeutralEmFractionPBNR");
// 	iEvent.put(PuppipatJetsNeutralEmFractionPBNR,string7);
	const std::string string8("PuppielectronMultiplicity");
	iEvent.put(PuppielectronMultiplicity,string8);
	const std::string string9("PuppiphotonEnergyFraction");
	iEvent.put(PuppiphotonEnergyFraction,string9);
	const std::string string10("PuppiphotonMultiplicity");
	iEvent.put(PuppiphotonMultiplicity,string10);
	const std::string string11("PuppimuonEnergyFraction");
	iEvent.put(PuppimuonEnergyFraction,string11);
	const std::string string12("PuppimuonMultiplicity");
	iEvent.put(PuppimuonMultiplicity,string12);
	const std::string string14("PuppiprunedMass");
	iEvent.put(PuppiprunedMass,string14);
	const std::string string15("PuppitrimmedMass");
	iEvent.put(PuppitrimmedMass,string15);
	const std::string string16("PuppifilteredMass");
	iEvent.put(PuppifilteredMass,string16);
	const std::string string17("Puppitau1");
	iEvent.put(Puppitau1,string17);
	const std::string string18("Puppitau2");
	iEvent.put(Puppitau2,string18);
	const std::string string19("Puppitau3");
	iEvent.put(Puppitau3,string19);
	const std::string string20("PuppiisLooseJetId");
	iEvent.put(PuppiisLooseJetId,string20);
	const std::string string21("PuppisoftDropMass");
	iEvent.put(PuppisoftDropMass,string21);
	const std::string string22("PuppibDiscriminatorCSV");
	iEvent.put(PuppibDiscriminatorCSV,string22);
	const std::string string23("PuppibDiscriminatorICSV");
	iEvent.put(PuppibDiscriminatorICSV,string23);
	const std::string string24("PtCorr");
	iEvent.put(PtCorr,string24);
	const std::string string25("EtaCorr");
	iEvent.put(EtaCorr,string25);
	const std::string string26("PhiCorr");
	iEvent.put(PhiCorr,string26);
	const std::string string27("ECorr");
	iEvent.put(ECorr,string27);
	const std::string string28("PuppiisTightJetId");
	iEvent.put(PuppiisTightJetId,string28);
	const std::string string29("mass");
	iEvent.put(mass,string29);
	const std::string string30("Puppicorrection");
	iEvent.put(Puppicorrection,string30);
	const std::string string31("PuppicorrectionUp");
	iEvent.put(PuppicorrectionUp,string31);
	const std::string string32("PuppicorrectionDown");
	iEvent.put(PuppicorrectionDown,string32);
	const std::string string33("PuppisoftDropPt");
	iEvent.put(PuppisoftDropPt,string33);
	const std::string string34("PuppimassCorrection");
	iEvent.put(PuppimassCorrection,string34);
	const std::string string35("PuppimassCorrectionUp");
	iEvent.put(PuppimassCorrectionUp,string35);
	const std::string string36("PuppimassCorrectionDown");
	iEvent.put(PuppimassCorrectionDown,string36);
	//	const std::string string28("PuppipuppiMass");
	//iEvent.put(PuppipuppiMass,string28);
	
}

// ------------ method called once each job just before starting event loop  ------------
void 
JetPropertiesPuppi::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
JetPropertiesPuppi::endJob() {
}

// ------------ method called when starting to processes a run  ------------
void 
JetPropertiesPuppi::beginRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
JetPropertiesPuppi::endRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
JetPropertiesPuppi::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
JetPropertiesPuppi::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
JetPropertiesPuppi::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
	//The following says we do not know what parameters are allowed so do no validation
	// Please change this to state exactly what you do use, even if it is no parameters
	edm::ParameterSetDescription desc;
	desc.setUnknown();
	descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(JetPropertiesPuppi);
