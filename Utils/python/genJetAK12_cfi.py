import FWCore.ParameterSet.Config as cms

genJetAK12 = cms.EDProducer('GenJetAK12',
  GenJetCollTag  = cms.InputTag("selectedGenJetsAK12"),
)
