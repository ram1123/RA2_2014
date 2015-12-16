import FWCore.ParameterSet.Config as cms

electron = cms.EDProducer('Electron',
VertexTag = cms.InputTag("offlineSlimmedPrimaryVertices"),
EleTag = cms.InputTag("slimmedElectrons"),
MinPt = cms.double(15),
RhoTag = cms.InputTag("fixedGridRhoFastjetAll"),
ConversionTag = cms.InputTag('reducedEgamma:reducedConversions'),
BeamSpotTag = cms.InputTag('offlineBeamSpot'),
eleVetoIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-veto"),
eleLooseIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-loose"),
eleMediumIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-medium"),
eleTightIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-tight"),
eleHEEPIdMap = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV60")
)
