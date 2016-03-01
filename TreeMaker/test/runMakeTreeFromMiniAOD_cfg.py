# $Id: runMakeTreeFromPAT_cfg.py,v 1.9 2013/01/24 15:42:54 mschrode Exp $
#
# Expects a file name as argument e.g.
# cmsRun runMakeLostLeptonTreeFromPAT_cfg.py dataset=/store/user/mschrode/HT/RA2PreSelection_Run2012A-13Jul2012-v1_V4/21a074f94cdbe7cfbeeb19be46b40a6a/RA2Skim_9_1_h6A.root
# cmsRun ../test/runMakeLostLeptonTreeFromPAT_cfg.py dataset=/store/user/mschrode/WJetsToLNu_HT-400ToInf_8TeV-madgraph_v2/RA2PreSelection_Summer12_DR53X-PU_S10_START53_V7A-v1_V4/6c50609e978ba7d5388d5439fc628605/RA2Skim_100_1_dgv.root, global_tag=START53_V7F::All, MC=True, debug=True

# Read parameters
from AllHadronicSUSY.Utils.CommandLineParams import CommandLineParams
parameters = CommandLineParams()

dataSetName = parameters.value("dataset","")
#dataSetName = parameters.value("dataset","file:/pnfs/desy.de/cms/tier2/store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU20bx25_POSTLS170_V5-v2/00000/F2742E0D-F603-E411-A246-0025905A60BE.root")
#dataSetName = parameters.value("dataset","file:/pnfs/desy.de/cms/tier2/store/mc/Phys14DR/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU20bx25_PHYS14_25_V1-v1/00000/F452BBD7-BE76-E411-B1D7-002590DB928E.root")
#dataSetName = parameters.value("dataset","file:/pnfs/desy.de/cms/tier2/store/mc/Spring14miniaod/WJetsToLNu_13TeV-madgraph-pythia8-tauola/MINIAODSIM/PU20bx25_POSTLS170_V5-v1/00000/B6E695EA-DE18-E411-B4D9-002590596498.root")
global_tag = parameters.value("global_tag","")
MC= parameters.value("MC", True)
QCD= parameters.value("QCD", False)
LostLepton= parameters.value("LostLepton", True)
debug= parameters.value("debug", False)
nJetsMin    = parameters.value("njets_min",0)
htMin       = parameters.value("ht_min",0)
mhtMin      = parameters.value("mht_min",0)
NumProcessedEvt=parameters.value("NumProcessedEvt",-1)
METFiltersProcess=parameters.value("METFiltersProcess","")
DoAK8Reclustering=parameters.value("DoAK8Reclustering",False)
DoJECCorrection=parameters.value("DoJECCorrection",False)
DoPuppi=parameters.value("DoPuppi",False)
LeptonFilter=parameters.value("leptonFilter",True)
GenJetsAK8Reclustering=parameters.value("genJetsAK8Reclustering",True)
isHBHEEarlyData = parameters.value("isHBHEEarlyData",False)
isHBHERun2015D=parameters.value("isHBHERun2015D",True)
JsonFileName=parameters.value("jsonFileName","json/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON_v2.txt")
IsCrab=parameters.value("isCrab",False)
ReDoPruningAndSoftdrop=parameters.value("ReDoPruningAndSoftdrop",False)

processName      = parameters.value("name","RSGraviton1000")


print "***** SETUP ************************************"
print "  dataSetName : "+dataSetName
print " global_tag : "+global_tag
print " runningOnMC : "+str(MC)
print " runningOnQCD : "+str(QCD)
print " LostLepton(MC) : "+str(LostLepton)
print "     nJetsMin : "+str(nJetsMin)
print "        htMin : "+str(htMin)
print "       mhtMin : "+str(mhtMin)
print "       debug : "+str(debug)
print "       num of events : "+str(NumProcessedEvt)
print "       doAK8Reclustering : "+str(DoAK8Reclustering)
print "       doJECCorrection : "+str(DoJECCorrection)
print "       ReDoPruningAndSoftdrop :"+str(ReDoPruningAndSoftdrop)
print "       doPuppi : "+str(DoPuppi)
print "       leptonFilter : "+str(LeptonFilter)
print "       genJetsAK8Reclustering : "+str(GenJetsAK8Reclustering)
print "       isHBHEEarlyData : "+str(isHBHEEarlyData)
print "       isHBHERun2015D : "+str(isHBHERun2015D)
print "       jsonFileName : "+str(JsonFileName)
print "       isCrab : "+str(False)
print "************************************************"

# The process needs to be defined AFTER reading sys.argv,
# otherwise edmConfigHash fails
import FWCore.ParameterSet.Config as cms
#process = cms.Process("RA2EventSelection")
process = cms.Process(processName)

from AllHadronicSUSY.TreeMaker.makeTreeFromMiniAOD_cff import makeTreeTreeFromMiniAOD
makeTreeTreeFromMiniAOD(process,
                outFileName="ReducedSelection",
                NJetsMin=nJetsMin,
                HTMin=htMin,
                MHTMin=mhtMin,
                reportEveryEvt=1,
                testFileName=dataSetName,
		Global_Tag=global_tag,
                METFiltersProcess=METFiltersProcess,
		MC=MC,
		QCD=QCD,
		LostLepton=LostLepton,
		debug = debug,
                numProcessedEvt=NumProcessedEvt,
                doAK8Reclustering=DoAK8Reclustering,
                doJECCorrection=DoJECCorrection,
                doPuppi=DoPuppi,
                leptonFilter=LeptonFilter,
                genJetsAK8Reclustering=GenJetsAK8Reclustering,
                customizeHBHENoiseForEarlyData=isHBHEEarlyData,
                customizeHBHENoiseForRun2015D=isHBHERun2015D,
                jsonFileName=JsonFileName,
                isCrab=IsCrab,
                reDoPruningAndSoftdrop=ReDoPruningAndSoftdrop)

