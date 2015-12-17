// -*- C++ -*-
//
// Package:    JetPropertiesAK10
// Class:      JetPropertiesAK10
// 
/**\class JetPropertiesAK10 JetPropertiesAK10.cc RA2Classic/JetPropertiesAK10/src/JetPropertiesAK10.cc
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

class JetPropertiesAK10 : public edm::EDProducer {
public:
	explicit JetPropertiesAK10(const edm::ParameterSet&);
	~JetPropertiesAK10();
	
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
JetPropertiesAK10::JetPropertiesAK10(const edm::ParameterSet& iConfig)
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
	const std::string string0("AK10jetArea");
	produces<std::vector<double> > (string0).setBranchAlias(string0);
	const std::string string1("AK10chargedHadronEnergyFraction");
	produces<std::vector<double> > (string1).setBranchAlias(string1);
	const std::string string2("AK10chargedHadronMultiplicity");
	produces<std::vector<int> > (string2).setBranchAlias(string2);
	const std::string string3("AK10neutralHadronEnergyFraction");
	produces<std::vector<double> > (string3).setBranchAlias(string3);
	const std::string string4("AK10neutralHadronMultiplicity");
	produces<std::vector<int> > (string4).setBranchAlias(string4);
	const std::string string5("AK10chargedEmEnergyFraction");
	produces<std::vector<double> > (string5).setBranchAlias(string5);
	const std::string string6("AK10neutralEmEnergyFraction");
	produces<std::vector<double> > (string6).setBranchAlias(string6);
// 	const std::string string7("AK10patJetsNeutralEmFractionPBNR");
// 	produces<std::vector<double> > (string7).setBranchAlias(string7);
	const std::string string8("AK10electronMultiplicity");
	produces<std::vector<int> > (string8).setBranchAlias(string8);
	const std::string string9("AK10photonEnergyFraction");
	produces<std::vector<double> > (string9).setBranchAlias(string9);
	const std::string string10("AK10photonMultiplicity");
	produces<std::vector<int> > (string10).setBranchAlias(string10);
	const std::string string11("AK10muonEnergyFraction");
	produces<std::vector<double> > (string11).setBranchAlias(string11);
	const std::string string12("AK10muonMultiplicity");
	produces<std::vector<int> > (string12).setBranchAlias(string12);
	const std::string string14("AK10prunedMass");
	produces<std::vector<double> > (string14).setBranchAlias(string14);
	const std::string string15("AK10trimmedMass");
	produces<std::vector<double> > (string15).setBranchAlias(string15);
	const std::string string16("AK10filteredMass");
	produces<std::vector<double> > (string16).setBranchAlias(string16);
	const std::string string17("AK10tau1");
	produces<std::vector<double> > (string17).setBranchAlias(string17);
	const std::string string18("AK10tau2");
	produces<std::vector<double> > (string18).setBranchAlias(string18);
	const std::string string19("AK10tau3");
	produces<std::vector<double> > (string19).setBranchAlias(string19);
	const std::string string20("AK10isLooseJetId");
	produces<std::vector<bool> > (string20).setBranchAlias(string20);
	const std::string string21("AK10softDropMass");
	produces<std::vector<double> > (string21).setBranchAlias(string21);
        const std::string string22("AK10bDiscriminatorCSV");
        produces<std::vector<double> > (string22).setBranchAlias(string22);
        const std::string string23("AK10bDiscriminatorICSV");
        produces<std::vector<double> > (string23).setBranchAlias(string23);
        const std::string string24("PtCorr");
        produces<std::vector<double> > (string24).setBranchAlias(string24);
        const std::string string25("EtaCorr");
        produces<std::vector<double> > (string25).setBranchAlias(string25);
        const std::string string26("PhiCorr");
        produces<std::vector<double> > (string26).setBranchAlias(string26);
        const std::string string27("ECorr");
        produces<std::vector<double> > (string27).setBranchAlias(string27);
	const std::string string28("AK10isTightJetId");
	produces<std::vector<bool> > (string28).setBranchAlias(string28);
	const std::string string29("mass");
	produces<std::vector<double> > (string29).setBranchAlias(string29);
	const std::string string30("AK10correction");
	produces<std::vector<double> > (string30).setBranchAlias(string30);
	const std::string string31("AK10correctionUp");
	produces<std::vector<double> > (string31).setBranchAlias(string31);
	const std::string string32("AK10correctionDown");
	produces<std::vector<double> > (string32).setBranchAlias(string32);
	const std::string string33("AK10softDropPt");
	produces<std::vector<double> > (string33).setBranchAlias(string33);
	const std::string string34("AK10massCorrection");
	produces<std::vector<double> > (string34).setBranchAlias(string30);
	const std::string string35("AK10massCorrectionUp");
	produces<std::vector<double> > (string35).setBranchAlias(string35);
	const std::string string36("AK10massCorrectionDown");
	produces<std::vector<double> > (string36).setBranchAlias(string36);
	//        const std::string string28("AK10puppiMass");
        //produces<std::vector<double> > (string28).setBranchAlias(string28);

}


JetPropertiesAK10::~JetPropertiesAK10()
{
	
	// do anything here that needs to be done at desctruction time
	// (e.g. close files, deallocate resources etc.)
	
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
JetPropertiesAK10::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	std::auto_ptr<std::vector<pat::Jet> > AK10prodJets(new std::vector<pat::Jet>());
	
	std::auto_ptr< std::vector<double> > AK10jetArea(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10chargedHadronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK10chargedHadronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK10neutralHadronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK10neutralHadronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK10chargedEmEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10neutralEmEnergyFraction(new std::vector<double>);
// 	std::auto_ptr< std::vector<double> > AK10patJetsNeutralEmFractionPBNR(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10electronEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK10electronMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK10photonEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK10photonMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK10muonEnergyFraction(new std::vector<double>);
	std::auto_ptr< std::vector<int> > AK10muonMultiplicity(new std::vector<int>);
	std::auto_ptr< std::vector<double> > AK10prunedMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10softDropMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10softDropPt(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10trimmedMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10filteredMass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10tau1(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10tau2(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10tau3(new std::vector<double>);
	std::auto_ptr< std::vector<bool> > AK10isLooseJetId(new std::vector<bool>);
	std::auto_ptr< std::vector<bool> > AK10isTightJetId(new std::vector<bool>);
	std::auto_ptr< std::vector<double> > AK10bDiscriminatorCSV(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10bDiscriminatorICSV(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PtCorr(new std::vector<double>);
	std::auto_ptr< std::vector<double> > EtaCorr(new std::vector<double>);
	std::auto_ptr< std::vector<double> > PhiCorr(new std::vector<double>);
	std::auto_ptr< std::vector<double> > ECorr(new std::vector<double>);
	std::auto_ptr< std::vector<double> > mass(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10correction(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10correctionUp(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10correctionDown(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10massCorrection(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10massCorrectionUp(new std::vector<double>);
	std::auto_ptr< std::vector<double> > AK10massCorrectionDown(new std::vector<double>);
	//	std::auto_ptr< std::vector<double> > AK10puppiMass(new std::vector<double>);
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

		  massCorrection = JetMassCorrector->getCorrection(); //do anyway the mass correction
		  mass->push_back( massCorrection*uncorrJet.mass());

		  JetUnc->setJetEta( uncorrJet.eta() );
		  JetUnc->setJetPt( massCorrection * uncorrJet.pt() );
		  massCorrUp = massCorrection * (1 + fabs(JetUnc->getUncertainty(1)));
		  JetUnc->setJetEta( uncorrJet.eta() );
		  JetUnc->setJetPt( massCorrection * uncorrJet.pt() );
		  massCorrDown = massCorrection * ( 1 - fabs(JetUnc->getUncertainty(-1)) );
		  
		  if (doJEC) {
		    correction = JetCorrector->getCorrection();
		    //		    massCorrection = JetMassCorrector->getCorrection();
		    //mass->push_back( massCorrection*uncorrJet.mass());
		  }
		  //		  else
		  // mass->push_back( Jets->at(i).mass());
		  
		  //		  std::cout<<"DEBUG - AK10- raw pt: "<<uncorrJet.pt()<<" corr: "<<correction<<" corr pt: "<<correction*uncorrJet.pt()
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
		  AK10prodJets->push_back(pat::Jet(Jets->at(i)));

		  //	  AK10prodJets->push_back(reco::Candidate::LorentzVector(jet4V));
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
		  AK10jetArea->push_back( Jets->at(i).jetArea() );
		  AK10chargedHadronEnergyFraction->push_back( Jets->at(i).chargedHadronEnergyFraction() );
		  AK10chargedHadronMultiplicity->push_back( Jets->at(i).chargedHadronMultiplicity() );
		  AK10neutralHadronEnergyFraction->push_back( Jets->at(i).neutralHadronEnergyFraction() );
		  AK10neutralHadronMultiplicity->push_back( Jets->at(i).neutralHadronMultiplicity() );
		  AK10chargedEmEnergyFraction->push_back( Jets->at(i).chargedEmEnergyFraction() );
		  AK10neutralEmEnergyFraction->push_back( Jets->at(i).neutralEmEnergyFraction() );
		  // 			AK10patJetsNeutralEmFractionPBNR->push_back( Jets->at(i).patJetsNeutralEmFractionPBNR() / Jets->at(i).jecFactor(0) );
		  AK10electronEnergyFraction->push_back( Jets->at(i).electronEnergyFraction() );
		  AK10electronMultiplicity->push_back( Jets->at(i).electronMultiplicity() );
		  AK10photonEnergyFraction->push_back( Jets->at(i).photonEnergyFraction() );
		  AK10photonMultiplicity->push_back( Jets->at(i).photonMultiplicity() );
		  AK10muonEnergyFraction->push_back( Jets->at(i).muonEnergyFraction() );
		  AK10muonMultiplicity->push_back( Jets->at(i).muonMultiplicity() );

		  AK10trimmedMass->push_back( -1.);
		  AK10filteredMass->push_back( -1.);

		  //		  AK10trimmedMass->push_back( massCorrection*Jets->at(i).userFloat("ak8PFJetsCHSTrimmedMass"));
		  //		  AK10filteredMass->push_back( massCorrection*Jets->at(i).userFloat("ak8PFJetsCHSFilteredMass"));

		  AK10correction->push_back( correction );
		  AK10correctionUp->push_back( corrUp );
		  AK10correctionDown->push_back( corrDown );

		  AK10massCorrection->push_back( massCorrection );
		  AK10massCorrectionUp->push_back( massCorrUp );
		  AK10massCorrectionDown->push_back( massCorrDown );

		   /*double dR=1000.;
		   double tempMass=0.;

		   for (unsigned int j=0; j<puppiJets->size(); j++) {
		     if (deltaR(Jets->at(i).eta(),Jets->at(i).phi(),puppiJets->at(j).eta(),puppiJets->at(j).phi()) < dR) {
		       dR = deltaR(Jets->at(i).eta(),Jets->at(i).phi(),puppiJets->at(j).eta(),puppiJets->at(j).phi());
		       if (dR<0.1)
			 tempMass = puppiJets->at(j).mass();			 
		     }
		   }		    
		   AK10puppiMass->push_back(tempMass); 		  
		   */	
		   //						std::cout<<"DEBUG: "<<Jets->at(i).userFloat("ak8PFJetsCHSSoftDropLinks")<<std::endl;

		   AK10tau1->push_back( Jets->at(i).userFloat("NjettinessAK10:tau1"));
		   AK10tau2->push_back( Jets->at(i).userFloat("NjettinessAK10:tau2"));
		   AK10tau3->push_back( Jets->at(i).userFloat("NjettinessAK10:tau3"));
		   
		   AK10bDiscriminatorCSV->push_back( Jets->at(i).bDiscriminator("combinedSecondaryVertexBJetTags") );
		   AK10bDiscriminatorICSV->push_back( Jets->at(i).bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
		   
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
		   AK10isLooseJetId->push_back(looseJetId);
		   AK10isTightJetId->push_back(tightJetId);

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
			   AK10softDropMass->push_back( softdropCorrection*uncorrSoftdropJet.mass());		       
			   AK10softDropPt->push_back( softdropCorrection*uncorrSoftdropJet.pt());		       
			 }
			 else {
			   AK10softDropMass->push_back( 1.*uncorrSoftdropJet.mass());		       		     
			   AK10softDropPt->push_back( 1.*uncorrSoftdropJet.pt());		       		     
			 }

			 //			 std::cout<<"DEBUG - SD- raw pt: "<<uncorrSoftdropJet.pt()
			 // <<" raw mass: "<<uncorrSoftdropJet.mass()<<" massCorr: "<<softdropCorrection<<" corr mass: "
			 //	  <<softdropCorrection*uncorrSoftdropJet.mass()<<std::endl;
		       }
		       else {
			 AK10softDropMass->push_back( -1.);
			 AK10softDropPt->push_back(-1.0);
		       }
		     }
		     else {
			 AK10softDropMass->push_back( -1.);		       		     
			 AK10softDropPt->push_back(-1.0);
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
			   AK10prunedMass->push_back( prunedCorrection*uncorrPrunedJet.mass());
			 else 
			   AK10prunedMass->push_back( 1.*uncorrPrunedJet.mass());
		       }
		       else
			 AK10prunedMass->push_back( -1.);		       		     

		       //			 std::cout<<"DEBUG - PR- raw pt: "<<uncorrPrunedJet.pt()
		       //  <<" raw mass: "<<uncorrPrunedJet.mass()<<" massCorr: "<<prunedCorrection<<" corr mass: "
		       //	  <<softdropCorrection*uncorrPrunedJet.mass()<<std::endl;

		     }
		     else
			 AK10prunedMass->push_back( -1.);		       		     

		     //		     std::cout<<prunedCorrection<<" "<<Jets->at(i).pt()<<" "<<Jets->at(i).mass()<<" "<<prunedjet.pt()<<" "<<prunedjet.mass()<<" "<<uncorrPrunedJet.pt()<<" "<<uncorrPrunedJet.mass()<<std::endl; getchar();

		   }

		   else {
		     AK10prunedMass->push_back( massCorrection*Jets->at(i).userFloat("ak10PFJetsCHSPrunedMass"));
		     AK10softDropMass->push_back( massCorrection*Jets->at(i).userFloat("ak10PFJetsCHSSoftDropMass"));
		     auto sdSubjets = Jets->at(i).subjets("SoftDrop");
		     if ( sdSubjets.size() > 1 ) {
		       auto sdp4 = sdSubjets[0]->p4() + sdSubjets[1]->p4();
		       AK10softDropPt->push_back( sdp4.pt() );
		     } else {
		       AK10softDropPt->push_back( -1.0 );
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
	iEvent.put(AK10prodJets );
	
	const std::string string0("AK10jetArea");
	iEvent.put(AK10jetArea,string0);
	const std::string string1("AK10chargedHadronEnergyFraction");
	iEvent.put(AK10chargedHadronEnergyFraction,string1);
	const std::string string2("AK10chargedHadronMultiplicity");
	iEvent.put(AK10chargedHadronMultiplicity,string2);
	const std::string string3("AK10neutralHadronEnergyFraction");
	iEvent.put(AK10neutralHadronEnergyFraction,string3);
	const std::string string4("AK10neutralHadronMultiplicity");
	iEvent.put(AK10neutralHadronMultiplicity,string4);
	const std::string string5("AK10chargedEmEnergyFraction");
	iEvent.put(AK10chargedEmEnergyFraction,string5);
	const std::string string6("AK10neutralEmEnergyFraction");
	iEvent.put(AK10neutralEmEnergyFraction,string6);
// 	const std::string string7("AK10patJetsNeutralEmFractionPBNR");
// 	iEvent.put(AK10patJetsNeutralEmFractionPBNR,string7);
	const std::string string8("AK10electronMultiplicity");
	iEvent.put(AK10electronMultiplicity,string8);
	const std::string string9("AK10photonEnergyFraction");
	iEvent.put(AK10photonEnergyFraction,string9);
	const std::string string10("AK10photonMultiplicity");
	iEvent.put(AK10photonMultiplicity,string10);
	const std::string string11("AK10muonEnergyFraction");
	iEvent.put(AK10muonEnergyFraction,string11);
	const std::string string12("AK10muonMultiplicity");
	iEvent.put(AK10muonMultiplicity,string12);
	const std::string string14("AK10prunedMass");
	iEvent.put(AK10prunedMass,string14);
	const std::string string15("AK10trimmedMass");
	iEvent.put(AK10trimmedMass,string15);
	const std::string string16("AK10filteredMass");
	iEvent.put(AK10filteredMass,string16);
	const std::string string17("AK10tau1");
	iEvent.put(AK10tau1,string17);
	const std::string string18("AK10tau2");
	iEvent.put(AK10tau2,string18);
	const std::string string19("AK10tau3");
	iEvent.put(AK10tau3,string19);
	const std::string string20("AK10isLooseJetId");
	iEvent.put(AK10isLooseJetId,string20);
	const std::string string21("AK10softDropMass");
	iEvent.put(AK10softDropMass,string21);
	const std::string string22("AK10bDiscriminatorCSV");
	iEvent.put(AK10bDiscriminatorCSV,string22);
	const std::string string23("AK10bDiscriminatorICSV");
	iEvent.put(AK10bDiscriminatorICSV,string23);
	const std::string string24("PtCorr");
	iEvent.put(PtCorr,string24);
	const std::string string25("EtaCorr");
	iEvent.put(EtaCorr,string25);
	const std::string string26("PhiCorr");
	iEvent.put(PhiCorr,string26);
	const std::string string27("ECorr");
	iEvent.put(ECorr,string27);
	const std::string string28("AK10isTightJetId");
	iEvent.put(AK10isTightJetId,string28);
	const std::string string29("mass");
	iEvent.put(mass,string29);
	const std::string string30("AK10correction");
	iEvent.put(AK10correction,string30);
	const std::string string31("AK10correctionUp");
	iEvent.put(AK10correctionUp,string31);
	const std::string string32("AK10correctionDown");
	iEvent.put(AK10correctionDown,string32);
	const std::string string33("AK10softDropPt");
	iEvent.put(AK10softDropPt,string33);
	const std::string string34("AK10massCorrection");
	iEvent.put(AK10massCorrection,string34);
	const std::string string35("AK10massCorrectionUp");
	iEvent.put(AK10massCorrectionUp,string35);
	const std::string string36("AK10massCorrectionDown");
	iEvent.put(AK10massCorrectionDown,string36);
	//	const std::string string28("AK10puppiMass");
	//iEvent.put(AK10puppiMass,string28);
	
}

// ------------ method called once each job just before starting event loop  ------------
void 
JetPropertiesAK10::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
JetPropertiesAK10::endJob() {
}

// ------------ method called when starting to processes a run  ------------
void 
JetPropertiesAK10::beginRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
JetPropertiesAK10::endRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
JetPropertiesAK10::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
JetPropertiesAK10::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
JetPropertiesAK10::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
	//The following says we do not know what parameters are allowed so do no validation
	// Please change this to state exactly what you do use, even if it is no parameters
	edm::ParameterSetDescription desc;
	desc.setUnknown();
	descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(JetPropertiesAK10);
