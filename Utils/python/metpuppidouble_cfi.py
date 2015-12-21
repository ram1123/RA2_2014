import FWCore.ParameterSet.Config as cms

metpuppidouble = cms.EDProducer('METPuppiDouble',
METTag  = cms.InputTag("slimmedMETsPuppi"),
corrMet = cms.bool(False),
doJEC = cms.bool(False),
JetTag_               = cms.InputTag('slimmedJetsPuppi'),
RhoTag = cms.InputTag("fixedGridRhoFastjetAll"),
L1File = cms.string("Summer15_25nsV6_DATA_L1FastJet_AK4PFPuppi.txt"),
L2File = cms.string("Summer15_25nsV6_DATA_L2Relative_AK4PFPuppi.txt"),
L3File = cms.string("Summer15_25nsV6_DATA_L3Absolute_AK4PFPuppi.txt"),
L2L3File = cms.string("Summer15_25nsV6_DATA_L2L3Residual_AK4PFPuppi.txt"),
uncFile = cms.string("Summer15_25nsV6_DATA_Uncertainty_AK4PFPuppi.txt"),
#jecPayloadNames      = cms.vstring("JEC/PHYS14_25_V2::All_L3Absolute_AK4PFPuppi.txt","JEC/PHYS14_25_V2::All_L2Relative_AK4PFPuppi.txt","JEC/PHYS14_25_V2::All_L1FastJet_AK4PFPuppi.txt"),
MuTag = cms.InputTag("slimmedMuons"),
)
