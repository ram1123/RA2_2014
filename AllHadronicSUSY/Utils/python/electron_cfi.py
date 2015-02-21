import FWCore.ParameterSet.Config as cms

electron = cms.EDProducer('Electron',
VertexTag = cms.InputTag("offlineSlimmedPrimaryVertices"),
EleTag = cms.InputTag("slimmedElectrons"),
RhoTag = cms.InputTag("fixedGridRhoFastjetAll"),
ConversionTag = cms.InputTag('reducedEgamma:reducedConversions'),
BeamSpotTag = cms.InputTag('offlineBeamSpot'),
)
