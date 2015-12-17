import FWCore.ParameterSet.Config as cms

genJetAK10 = cms.EDProducer('GenJetAK10',
  GenJetCollTag  = cms.InputTag("selectedGenJetsAK10"),
)
