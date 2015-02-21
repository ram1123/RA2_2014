import FWCore.ParameterSet.Config as cms

muon = cms.EDProducer('Muon',
VertexTag = cms.InputTag("offlineSlimmedPrimaryVertices"),
MuTag = cms.InputTag("slimmedMuons"),
RhoTag = cms.InputTag("fixedGridRhoFastjetAll"),
)
