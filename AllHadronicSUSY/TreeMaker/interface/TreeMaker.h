#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
// additional headers
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/Utilities/interface/EDMException.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DataFormats/Provenance/interface/EventAuxiliary.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "TString.h"
#include "TTree.h"
#include <TFile.h>
#include <vector>
#include <DataFormats/Math/interface/deltaR.h>
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
//
// class declaration
//

class TreeMaker : public edm::EDProducer {
public:
	explicit TreeMaker(const edm::ParameterSet&);
	~TreeMaker();
	static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
private:
	virtual void beginJob() override;
	virtual void produce(edm::Event&, const edm::EventSetup&) override;
	virtual void endJob() override;
	// ----------member data ---------------------------
	const unsigned int nMaxCandidates_;
	void setBranchVariablesToDefault();
	TString treeName_;
	TTree* tree_;	
	// generell event information
	UInt_t runNum_;      
	UInt_t lumiBlockNum_;
	UInt_t evtNum_;
	// any float precision varialbes
//	std::vector<edm::InputTag> varsFloatTags_;
//	std::vector<std::string> varsFloatNames_;
//	std::vector<Float_t> varsFloat_;
	// any int precision varialbes
	std::vector<edm::InputTag> varsIntTags_;
	std::vector<std::string> varsIntNames_;
	std::vector<Int_t> varsInt_;
	// any bool precision varialbes
	std::vector<edm::InputTag> varsBoolTags_;
	std::vector<std::string> varsBoolNames_;
	std::vector<UChar_t> varsBool_;
	// any reco candidate plus addiation doubles
	std::vector<edm::InputTag> varsRecoCandTags_;
	std::vector<std::string> varsRecoCandNames_;
	std::vector<UShort_t> RecoCandN_;
	std::vector<Float_t*> RecoCandPt_;
	std::vector<Float_t*> RecoCandEta_;
	std::vector<Float_t*> RecoCandPhi_;
	std::vector<Float_t*> RecoCandE_;
	std::vector<UShort_t> RecoCandAdditionalVariablesN_;
	std::vector< std::vector<edm::InputTag> > RecoCandAdditionalVariablesTags_;
	std::vector< std::vector<Float_t*> > RecoCandAdditionalVariables_;
};
