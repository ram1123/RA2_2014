import FWCore.ParameterSet.Config as cms

jetpropertiesAK8 = cms.EDProducer('JetPropertiesAK8',
JetTag_               = cms.InputTag('slimmedJetsAK8'),
BTagInputTag	        = cms.string('combinedSecondaryVertexBJetTags'),
)
