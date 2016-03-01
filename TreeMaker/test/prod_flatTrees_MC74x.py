from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'RSGraviton1000'
config.General.workArea = 'RSGraviton1000'
config.section_('JobType')
config.JobType.psetName = 'TreeMaker/test/runMakeTreeFromMiniAOD_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.pyCfgParams = ['global_tag=74X_mcRun2_asymptotic_v2', 'MC=True', 'isCrab=True', 'doJECCorrection=True', 'isHBHERun2015D=False', 'doAK8Reclustering=True', 'ReDoPruningAndSoftdrop=True']
config.JobType.inputFiles = ['Summer15_25nsV2_MC_L1FastJet_AK8PFchs.txt','Summer15_25nsV2_MC_L2Relative_AK8PFchs.txt','Summer15_25nsV2_MC_L3Absolute_AK8PFchs.txt','Summer15_25nsV2_MC_L1FastJet_AK4PFchs.txt','Summer15_25nsV2_MC_L2Relative_AK4PFchs.txt','Summer15_25nsV2_MC_L3Absolute_AK4PFchs.txt' ]
config.JobType.allowUndistributedCMSSW = True
#config.JobType.maxMemoryMB = 2500    # 2.5 GB     
config.JobType.maxJobRuntimeMin = 900 #15 h
config.section_('Data')
config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1000_TuneCUETP8M1_13TeV-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
config.Data.unitsPerJob = 1
config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
config.Data.splitting = 'FileBased'
config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/RSGraviton1000/'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T3_US_FNALLPC'
#config.Site.blacklist= ['T2_US_Purdue']

if __name__ == '__main__':
    from CRABAPI.RawCommand import crabCommand

    #Make sure you set this parameter (here or above in the config it does not matter)
    config.General.workArea = 'ntuple_16Nov'

    def submit(config):
        res = crabCommand('submit', config = config)

    #########    From now on that's what users should modify: this is the a-la-CRAB2 configuration part.
   
    config.General.requestName = 'Pol_WLWL'
    config.Data.inputDataset = '/WWJJToLNuQQ_LL_13TeV-madgraph-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/Pol_WLWL/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    config.General.requestName = 'Pol_WLWT'
    config.Data.inputDataset = '/WWJJToLNuQQ_LT_13TeV-madgraph-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/Pol_WLWL/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    config.General.requestName = 'Pol_WTWT'
    config.Data.inputDataset = '/WWJJToLNuQQ_TT_13TeV-madgraph-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/Pol_WLWL/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    config.General.requestName = 'WJets'
    config.Data.inputDataset = '/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/WJets/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'WW'
    config.Data.inputDataset = '/WW_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/WW_TuneCUETP8M1_13TeV-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/WW/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WW_excl'
    config.Data.inputDataset = '/WWToLNuQQ_13TeV-powheg/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/WWToLNuQQ_13TeV-powheg/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/WW_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'WZ'
    config.Data.inputDataset = '/WZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/WZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/WZ/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WZ_excl'
    config.Data.inputDataset = '/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/WZ_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    config.General.requestName = 'WZJets'
    config.Data.inputDataset = '/WZJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/WZJets/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'ZZ'
    config.Data.inputDataset = '/ZZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/ZZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/ZZ/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'ZZ_excl'
    config.Data.inputDataset = '/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/ZZ_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'TTbar_amcatnlo'
    config.Data.inputDataset = '/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v3/MINIAODSIM'
    #config.Data.inputDataset = '/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/TTbar_amcatnlo/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'TTbar_powheg'
    config.Data.inputDataset = '/TT_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/TT_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/TTbar_powheg/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'TTbar_madgraph'
    config.Data.inputDataset = '/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/TTbar_madgraph/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'sch'
    config.Data.inputDataset = '/ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/sch/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    
    config.General.requestName = 'tch_inclusive'
    config.Data.inputDataset = '/ST_t-channel_5f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v2/MINIAODSIM'
    #config.Data.inputDataset = '/ST_t-channel_5f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/tch/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'tch_bar'
    config.Data.inputDataset = '/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/tch_bar/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    config.General.requestName = 'tch'
    config.Data.inputDataset = '/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/tch_bar/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'tW_bar'
    config.Data.inputDataset = '/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    #config.Data.inputDataset = '/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/tWch_bar/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'tWch'
    config.Data.inputDataset = '/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v2/MINIAODSIM'
    #config.Data.inputDataset = '/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/16Nov_CMSSW74_12/tWch/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    
    #...
