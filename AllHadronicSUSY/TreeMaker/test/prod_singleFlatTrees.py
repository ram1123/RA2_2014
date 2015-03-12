from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'RSGraviton1000'
config.General.workArea = 'RSGraviton1000'
config.section_('JobType')
config.JobType.psetName = 'TreeMaker/test/runMakeTreeFromMiniAOD_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.pyCfgParams = ['global_tag=PHYS14_25_V2::All', 'MC=True']
config.JobType.allowNonProductionCMSSW = True
config.JobType.inputFiles = ['PHYS14_25_V2_All_L1FastJet_AK8PFchs.txt','PHYS14_25_V2_All_L2Relative_AK8PFchs.txt','PHYS14_25_V2_All_L3Absolute_AK8PFchs.txt','PHYS14_25_V2_All_L1FastJet_AK4PFchs.txt','PHYS14_25_V2_All_L2Relative_AK4PFchs.txt','PHYS14_25_V2_All_L3Absolute_AK4PFchs.txt' ]
config.section_('Data')
config.Data.inputDataset = '/RSGravitonToWW_kMpl01_M_1000_Tune4C_13TeV_pythia8/Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v2/MINIAODSIM'
config.Data.unitsPerJob = 50
config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
config.Data.splitting = 'LumiBased'
config.Data.outLFN = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple/RSGraviton1000/'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
