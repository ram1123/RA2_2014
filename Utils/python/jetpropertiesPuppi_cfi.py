import FWCore.ParameterSet.Config as cms

jetpropertiesPuppi = cms.EDProducer('JetPropertiesPuppi',
JetTag_               = cms.InputTag('slimmedJetsPuppi'),
MinPt = cms.double(15),
doJEC = cms.bool(False),
RhoTag = cms.InputTag("fixedGridRhoFastjetAll"),
L1File = cms.string("Summer15_25nsV6_DATA_L1FastJet_AK4PFPuppi.txt"),
L2File = cms.string("Summer15_25nsV6_DATA_L2Relative_AK4PFPuppi.txt"),
L3File = cms.string("Summer15_25nsV6_DATA_L3Absolute_AK4PFPuppi.txt"),
L2L3File = cms.string("Summer15_25nsV6_DATA_L2L3Residual_AK4PFPuppi.txt"),
uncFile = cms.string("Summer15_25nsV6_DATA_Uncertainty_AK4PFPuppi.txt"),
#L1File = cms.string("PHYS14_25_V2_All_L1FastJet_AK4PFPuppi.txt"),
#L2File = cms.string("PHYS14_25_V2_All_L2Relative_AK4PFPuppi.txt"),
#L3File = cms.string("PHYS14_25_V2_All_L3Absolute_AK4PFPuppi.txt"),
#jecPayloadNames      = cms.vstring("JEC/PHYS14_25_V2::All_L3Absolute_AK4PFPuppi.txt","JEC/PHYS14_25_V2::All_L2Relative_AK4PFPuppi.txt","JEC/PHYS14_25_V2::All_L1FastJet_AK4PFPuppi.txt"),
#BTagInputTag	        = cms.string('combinedSecondaryVertexBJetTags'),
)
