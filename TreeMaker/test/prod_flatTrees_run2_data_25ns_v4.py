from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'data_mu'
config.General.workArea = 'data_mu'
config.section_('JobType')
config.JobType.psetName = 'TreeMaker/test/runMakeTreeFromMiniAOD_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.pyCfgParams = ['global_tag=74X_dataRun2_Prompt_v4', 'MC=False', 'debug=False', 'isHBHERun2015D=False', 'DoJECCorrection=True', 'leptonFilter=True', 'DoAK8Reclustering=True','ReDoPruningAndSoftdrop=True', 'isHBHERun2015D=True' ]
#config.JobType.pyCfgParams = ['global_tag=74X_dataRun2_v2', 'MC=False', 'isCrab=True', 'doJECCorrection=True', 'isHBHERun2015D=True']
config.JobType.allowUndistributedCMSSW = True
#config.JobType.maxMemoryMB = 2500    # 2.5 GB                      
config.JobType.maxJobRuntimeMin = 900 #15 h
config.JobType.inputFiles = ['Summer15_25nsV5_DATA_L1FastJet_AK8PFchs.txt','Summer15_25nsV5_DATA_L2Relative_AK8PFchs.txt','Summer15_25nsV5_DATA_L3Absolute_AK8PFchs.txt','Summer15_25nsV5_DATA_L2L3Residual_AK8PFchs.txt','Summer15_25nsV5_DATA_L1FastJet_AK4PFchs.txt','Summer15_25nsV5_DATA_L2Relative_AK4PFchs.txt','Summer15_25nsV5_DATA_L3Absolute_AK4PFchs.txt','Summer15_25nsV5_DATA_L2L3Residual_AK4PFchs.txt' ]
config.section_('Data')
config.Data.inputDataset = '/SingleMuon/Run2015B-PromptReco-v1/MINIAOD'
config.Data.unitsPerJob = 5
config.Data.lumiMask = 'json/Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON.txt' #FOR THE SYNCH!
config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
config.Data.splitting = 'LumiBased'
config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12_data_mu/'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T3_US_FNALLPC'
#config.Site.blacklist= ['T2_US_Purdue']

if __name__ == '__main__':
    from CRABAPI.RawCommand import crabCommand

    #Make sure you set this parameter (here or above in the config it does not matter)
    config.General.workArea = 'ntuple_data_T3_Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON'

    def submit(config):
        res = crabCommand('submit', config = config)

    #########    From now on that's what users should modify: this is the a-la-CRAB2 configuration part.
        
#    config.General.requestName = 'data_mu_prompt_25ns_runC'
#    config.Data.inputDataset = '/SingleMuon/Run2015C-PromptReco-v1/MINIAOD'
#    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12_data_Cert_246908-259891_13TeV_PromptReco_Collisions15_25ns_JSON_v3/data_mu_prompt_25ns_runC/'
##    config.Data.lumiMask = 'json/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON_v2.txt'
#    from multiprocessing import Process
#    p = Process(target=submit, args=(config,))
#    p.start()
#    p.join()
#    
#    config.General.requestName = 'data_el_prompt_25ns_runC'
#    config.Data.inputDataset = '/SingleElectron/Run2015C-PromptReco-v1/MINIAOD'
#    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12_data_Cert_246908-259891_13TeV_PromptReco_Collisions15_25ns_JSON_v3/data_el_prompt_25ns_runC/'
##    config.Data.lumiMask = 'json/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON_v2.txt'
#    from multiprocessing import Process
#    p = Process(target=submit, args=(config,))
#    p.start()
#    p.join()
#
#    config.General.requestName = 'data_mu_prompt_25ns_runD_v3'
#    config.Data.inputDataset = '/SingleMuon/Run2015D-PromptReco-v3/MINIAOD'
#    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12_data_Cert_246908-259891_13TeV_PromptReco_Collisions15_25ns_JSON_v3/data_mu_prompt_v3_25ns_runD/'
##    config.Data.lumiMask = 'json/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON_v2.txt'
#    from multiprocessing import Process
#    p = Process(target=submit, args=(config,))
#    p.start()
#    p.join()
#    
#    config.General.requestName = 'data_el_prompt_25ns_runD_v3'
#    config.Data.inputDataset = '/SingleElectron/Run2015D-PromptReco-v3/MINIAOD'
#    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12_data_Cert_246908-259891_13TeV_PromptReco_Collisions15_25ns_JSON_v3/data_el_prompt_v3_25ns_runD/'
##    config.Data.lumiMask = 'json/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON_v2.txt'
#    from multiprocessing import Process
#    p = Process(target=submit, args=(config,))
#    p.start()
#    p.join()

    config.General.requestName = 'data_mu_prompt_25ns_runD_v4'
    config.Data.inputDataset = '/SingleMuon/Run2015D-PromptReco-v4/MINIAOD'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12_data_Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON/data_mu_prompt_v4_25ns_runD/'
#    config.Data.lumiMask = 'json/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON_v2.txt'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    config.General.requestName = 'data_el_prompt_25ns_runD_v4'
    config.Data.inputDataset = '/SingleElectron/Run2015D-PromptReco-v4/MINIAOD'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12_data_Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON/data_el_prompt_v4_25ns_runD/'
#    config.Data.lumiMask = 'json/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON_v2.txt'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

   #...
