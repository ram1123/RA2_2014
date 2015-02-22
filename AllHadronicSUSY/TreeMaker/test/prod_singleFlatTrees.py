from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'RSGraviton1000'
config.General.workArea = 'RSGraviton1000'
config.section_('JobType')
config.JobType.psetName = 'test/runMakeTreeFromMiniAOD_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.pyCfgParams = ['global_tag=PHYS14_25_V1::All', 'MC=True']
config.section_('Data')
config.Data.inputDataset = '/RSGravitonToWW_kMpl01_M_1000_Tune4C_13TeV_pythia8/Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v2/MINIAODSIM'
config.Data.unitsPerJob = 50
config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
config.Data.splitting = 'LumiBased'
config.Data.outLFN = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple/RSGraviton1000/'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
