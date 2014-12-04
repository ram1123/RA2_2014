import FWCore.ParameterSet.Config as cms

TreeMaker = cms.EDProducer(
'TreeMaker',
# Name of the output tree
TreeName          = cms.string('RA2Tree'),
VarsFloat = cms.vstring(),
VarsInt = cms.vstring(),
VarsBool = cms.vstring(),
VarsRecoCand = cms.vstring(),
)
