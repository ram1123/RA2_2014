from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'RSGraviton1000'
config.General.workArea = 'RSGraviton1000'
config.section_('JobType')
config.JobType.psetName = 'TreeMaker/test/runMakeTreeFromMiniAOD_cfg.py'
config.JobType.pluginName = 'Analysis'
#config.JobType.pyCfgParams = ['global_tag=74X_mcRun2_asymptotic_v2', 'MC=True', 'isCrab=True', 'DoJECCorrection=False', 'isHBHERun2015D=False', 'DoPuppi=False',  'DoAK10Reclustering=False', 'genJetsAK10Reclustering=False', 'DoAK12Reclustering=False', 'genJetsAK12Reclustering=False', 'DoAK8Reclustering=False', 'ReDoPruningAndSoftdrop=False']
config.JobType.pyCfgParams = ['global_tag=80X_mcRun2_asymptotic_2016_v3','leptonFilter=False', 'MC=True', 'isCrab=True', 'DoJECCorrection=True', 'isHBHERun2015D=False', 'DoPuppi=True','ReDoPruningAndSoftdropPuppi=True']
config.JobType.inputFiles = ['Spring16_25nsV3_MC_L1FastJet_AK8PFchs.txt','Spring16_25nsV3_MC_L2Relative_AK8PFchs.txt','Spring16_25nsV3_MC_L3Absolute_AK8PFchs.txt','Spring16_25nsV3_MC_L1FastJet_AK4PFchs.txt','Spring16_25nsV3_MC_L2Relative_AK4PFchs.txt','Spring16_25nsV3_MC_L3Absolute_AK4PFchs.txt','Spring16_25nsV3_MC_Uncertainty_AK4PFchs.txt','Spring16_25nsV3_MC_Uncertainty_AK8PFchs.txt','Spring16_25nsV3_MC_L1FastJet_AK8PFPuppi.txt','Spring16_25nsV3_MC_L2Relative_AK8PFPuppi.txt','Spring16_25nsV3_MC_L3Absolute_AK8PFPuppi.txt','Spring16_25nsV3_MC_L1FastJet_AK4PFPuppi.txt','Spring16_25nsV3_MC_L2Relative_AK4PFPuppi.txt','Spring16_25nsV3_MC_L3Absolute_AK4PFPuppi.txt','Spring16_25nsV3_MC_Uncertainty_AK4PFPuppi.txt','Spring16_25nsV3_MC_Uncertainty_AK8PFPuppi.txt' ]
config.JobType.allowUndistributedCMSSW = True
#config.JobType.maxMemoryMB = 2500    # 2.5 GB     
config.JobType.maxJobRuntimeMin = 900 #15 h
config.section_('Data')
config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1000_TuneCUETP8M1_13TeV-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
config.Data.unitsPerJob = 1
config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
config.Data.splitting = 'FileBased'
config.Data.outLFNDirBase = '/store/user/rasharma/aQGC_15July/'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T3_US_FNALLPC'
config.Site.blacklist= ['T2_US_Purdue','T2_UA_KIPT']

#NB: SAMPLES HAVE TO BE UPDATED!

if __name__ == '__main__':
    from CRABAPI.RawCommand import crabCommand

    #Make sure you set this parameter (here or above in the config it does not matter)
    config.General.workArea = 'ntuple_MC_17jun_v1'

    def submit(config):
        res = crabCommand('submit', config = config)

    #########    From now on that's what users should modify: this is the a-la-CRAB2 configuration part.

   
    config.General.requestName = 'Signal_LT'
    config.Data.inputDataset = '/WWJJToLNuQQ_LT_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_07Nov2016/Signal_LT/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'Signal_LL'
    config.Data.inputDataset = '/WWJJToLNuQQ_LL_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_07Nov2016/Signal_LL/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'Signal_TT'
    config.Data.inputDataset = '/WWJJToLNuQQ_TT_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_07Nov2016/Signal_TT/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    '''
    config.General.requestName = 'WJets_amcatnlo'
    config.Data.inputDataset = '/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets_amcatnlo/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WJets_madgraph'
    config.Data.inputDataset = '/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets_madgraph/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'DYJetsToLL_amcatnlo'
    config.Data.outLFNDirBase = ''
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()



    config.General.requestName = 'WJets_amcatnlo'
    config.Data.inputDataset = '/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets_amcatnlo/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WJets_madgraph'
    config.Data.inputDataset = '/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets_madgraph/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'DYJetsToLL_amcatnlo'
    config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/DYJetsToLL_amcatnlo/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'WJets100'
    config.Data.inputDataset = '/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets100/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'WJets200'
    config.Data.inputDataset = '/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets200/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    
    config.General.requestName = 'WJets400'
    config.Data.inputDataset = '/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets400/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'WJets600bis'
    config.Data.inputDataset = '/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets600bis/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WJets800'
    config.Data.inputDataset = '/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'WJets1200'
    config.Data.inputDataset = '/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets1200/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WJets2500'
    config.Data.inputDataset = '/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WJets2500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'WW'
    config.Data.inputDataset = '/WW_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WW/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WZ'
    config.Data.inputDataset = '/WZ_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WZ/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'ZZ'
    config.Data.inputDataset = '/ZZ_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/ZZ/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'WW_excl'
    config.Data.inputDataset = '/WWToLNuQQ_13TeV-powheg/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WW_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WZ_excl'
    config.Data.inputDataset = '/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/WZ_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'ZZ_excl'
    config.Data.inputDataset = '/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/ZZ_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'TTbar_amcatnlo'
    config.Data.inputDataset = '/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/TTbar_amcatnlo/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    config.General.requestName = 'tch'
    config.Data.inputDataset = '/'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/tch/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'tch_bar'
    config.Data.inputDataset = '/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/tch_bar/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'tWch_bar'
    config.Data.inputDataset = '/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/tWch_bar/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'tWch'
    config.Data.inputDataset = '/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/aQGC_16July2016/tWch/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    #...
    '''

