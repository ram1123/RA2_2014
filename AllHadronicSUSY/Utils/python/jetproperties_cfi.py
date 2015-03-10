import FWCore.ParameterSet.Config as cms

jetproperties = cms.EDProducer('JetProperties',
JetTag_               = cms.InputTag('slimmedJets'),
RhoTag = cms.InputTag("fixedGridRhoFastjetAll"),
jecPayloadNames      = cms.vstring("JEC/PHYS14_25_V2::All_L3Absolute_AK4PFchs.txt","JEC/PHYS14_25_V2::All_L2Relative_AK4PFchs.txt","JEC/PHYS14_25_V2::All_L1FastJet_AK4PFchs.txt"),
#BTagInputTag	        = cms.string('combinedSecondaryVertexBJetTags'),
)
