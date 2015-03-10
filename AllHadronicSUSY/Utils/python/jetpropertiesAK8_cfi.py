import FWCore.ParameterSet.Config as cms

jetpropertiesAK8 = cms.EDProducer('JetPropertiesAK8',
JetTag_               = cms.InputTag('slimmedJetsAK8'),
RhoTag = cms.InputTag("fixedGridRhoFastjetAll"),
BTagInputTag	        = cms.string('combinedSecondaryVertexBJetTags'),
jecPayloadNames      = cms.vstring("JEC/PHYS14_25_V2::All_L3Absolute_AK8PFchs.txt","JEC/PHYS14_25_V2::All_L2Relative_AK8PFchs.txt","JEC/PHYS14_25_V2::All_L1FastJet_AK8PFchs.txt"),
)
