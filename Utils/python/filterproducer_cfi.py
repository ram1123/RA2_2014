import FWCore.ParameterSet.Config as cms
filterProducer = cms.EDProducer('FilterProducer',
                                 noiseFilterTag = cms.InputTag('TriggerResults','', 'PAT'),
                                 BadChCandNoiseFilterTag = cms.InputTag("badChargedCandidateFilter"),
                                 BadPFMuonNoiseFilterTag = cms.InputTag("badPFMuonFilter"),
                                 HBHENoiseFilter_Selector_ = cms.string("Flag_HBHENoiseFilter"),
                                 HBHENoiseIsoFilter_Selector_ = cms.string("Flag_HBHENoiseIsoFilter"),
                                 CSCHaloNoiseFilter_Selector_ = cms.string("Flag_CSCTightHaloFilter"),
                                 GoodVtxNoiseFilter_Selector_ = cms.string("Flag_goodVertices"),
                                 EEBadScNoiseFilter_Selector_ = cms.string("Flag_eeBadScFilter"),
                                 EcalDeadCellTriggerPrimitiveNoiseFilter_Selector_ = cms.string("Flag_EcalDeadCellTriggerPrimitiveFilter"),
                                 GlobalTightHalo2016NoiseFilter_Selector_ = cms.string("Flag_globalTightHalo2016Filter"),
#                                 HBHENoiseFilterLoose = cms.InputTag("HBHENoiseFilterResultProducer", "HBHENoiseFilterResultRun2Loose"),
#                                 HBHENoiseFilterTight = cms.InputTag("HBHENoiseFilterResultProducer", "HBHENoiseFilterResultRun2Tight"),
#                                 HBHENoiseIsoFilter = cms.InputTag("HBHENoiseFilterResultProducer", "HBHEIsoNoiseFilterResult")
                                 )
