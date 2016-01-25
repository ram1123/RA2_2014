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
config.JobType.pyCfgParams = ['global_tag=74X_mcRun2_asymptotic_v2', 'MC=True', 'isCrab=True', 'DoJECCorrection=True', 'isHBHERun2015D=False', 'DoPuppi=True',  'DoAK10Reclustering=True', 'genJetsAK10Reclustering=True', 'DoAK12Reclustering=True', 'genJetsAK12Reclustering=True', 'DoAK8Reclustering=True', 'ReDoPruningAndSoftdrop=True']
config.JobType.inputFiles = ['Summer15_25nsV6_MC_L1FastJet_AK8PFchs.txt','Summer15_25nsV6_MC_L2Relative_AK8PFchs.txt','Summer15_25nsV6_MC_L3Absolute_AK8PFchs.txt','Summer15_25nsV6_MC_L1FastJet_AK4PFchs.txt','Summer15_25nsV6_MC_L2Relative_AK4PFchs.txt','Summer15_25nsV6_MC_L3Absolute_AK4PFchs.txt','Summer15_25nsV6_MC_Uncertainty_AK4PFchs.txt','Summer15_25nsV6_MC_Uncertainty_AK8PFchs.txt','Summer15_25nsV6_MC_L1FastJet_AK8PFPuppi.txt','Summer15_25nsV6_MC_L2Relative_AK8PFPuppi.txt','Summer15_25nsV6_MC_L3Absolute_AK8PFPuppi.txt','Summer15_25nsV6_MC_L1FastJet_AK4PFPuppi.txt','Summer15_25nsV6_MC_L2Relative_AK4PFPuppi.txt','Summer15_25nsV6_MC_L3Absolute_AK4PFPuppi.txt','Summer15_25nsV6_MC_Uncertainty_AK4PFPuppi.txt','Summer15_25nsV6_MC_Uncertainty_AK8PFPuppi.txt' ]
config.JobType.allowUndistributedCMSSW = True
#config.JobType.maxMemoryMB = 2500    # 2.5 GB     
config.JobType.maxJobRuntimeMin = 900 #15 h
config.section_('Data')
config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1000_TuneCUETP8M1_13TeV-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
config.Data.unitsPerJob = 1
config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
config.Data.splitting = 'FileBased'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC/RSGraviton1000/'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
config.Site.blacklist= ['T2_US_Purdue','T2_UA_KIPT']

if __name__ == '__main__':
    from CRABAPI.RawCommand import crabCommand

    #Make sure you set this parameter (here or above in the config it does not matter)
    config.General.workArea = 'ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2'

    def submit(config):
        res = crabCommand('submit', config = config)

    #########    From now on that's what users should modify: this is the a-la-CRAB2 configuration part.

    
    config.General.requestName = 'RSGraviton600'
#    config.JobType.pyCfgParams = ['global_tag=74X_mcRun2_asymptotic_v2', 'MC=True', 'name=RSGraviton600']
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-600_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton600/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'RSGraviton800'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-800_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'RSGraviton1000'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1000_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
#    config.JobType.pyCfgParams = ['global_tag=74X_mcRun2_asymptotic_v2', 'MC=True', 'name=RSGraviton1000']
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton1000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'Higgs650'
    config.Data.inputDataset = '/GluGluHToWWToLNuQQ_M650_13TeV_powheg_JHUgen_pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/Higgs650/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'Higgs1000'
    config.Data.inputDataset = '/GluGluHToWWToLNuQQ_M1000_13TeV_powheg_JHUgen_pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/Higgs1000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'VBFHiggs650'
    config.Data.inputDataset = '/VBF_HToWWToLNuQQ_M650_13TeV_powheg_JHUgen_pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/VBFHiggs650/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'VBFHiggs1000'
    config.Data.inputDataset = '/VBF_HToWWToLNuQQ_M1000_13TeV_powheg_JHUgen_pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/VBFHiggs1000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'RSGraviton1200'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1200_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
#    config.JobType.pyCfgParams = ['global_tag=74X_mcRun2_asymptotic_v2', 'MC=True', 'name=RSGraviton1200']
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton1200/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'RSGraviton1400'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1400_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton1400/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    
    config.General.requestName = 'RSGraviton1600'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1600_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton1600/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'RSGraviton1800'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1800_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton1800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'RSGraviton2000'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-2000_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton2000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'RSGraviton2500'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-2500_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton2500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'RSGraviton3000'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-3000_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton3000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'RSGraviton3500'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-3500_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton3500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    
    config.General.requestName = 'RSGraviton4000'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-4000_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton4000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'RSGraviton4500'
    config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-4500_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/RSGraviton4500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton600'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-600_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton600/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'BulkGraviton700'
    config.Data.inputDataset = '/BulkGraviton/huangh-BG-MINIAOD-700_50000-387ce20ab3250374874491bf136d6c14/USER'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton700/'
    config.Data.inputDBS = 'phys03' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'BulkGraviton750'
    config.Data.inputDataset = '/BulkGraviton/huangh-BG-MINIAOD-750_50000-387ce20ab3250374874491bf136d6c14/USER'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton750/'
    config.Data.inputDBS = 'phys03' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'BulkGraviton900'
    config.Data.inputDataset = '/BulkGraviton/huangh-BG-MINIAOD-900_50000-387ce20ab3250374874491bf136d6c14/USER'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton900/'
    config.Data.inputDBS = 'phys03' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'BulkGraviton800'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-800_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton800/'
    config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'VBFBulkGraviton800'
    config.Data.inputDataset = '/VBF_BulkGravToWW_narrow_M-800_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/VBFBulkGraviton800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton1000'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-1000_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton1000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton1200'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-1200_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton1200/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'BulkGraviton1400'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-1400_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton1400/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton1600'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-1600_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton1600/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton1800'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-1800_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton1800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton2000'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-2000_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton2000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton2500'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-2500_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton2500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton3000'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-3000_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton3000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton3500'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-3500_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton3500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton4000'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-4000_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton4000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'BulkGraviton4500'
    config.Data.inputDataset = '/BulkGravToWWToWlepWhad_narrow_M-4500_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/BulkGraviton4500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'WprimeToWZ600'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-600_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ600/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ800'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-800_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ1000'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-1000_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ1000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ1200'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-1200_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ1200/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ1400'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-1400_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ1400/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ1600'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-1600_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ1600/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ1800'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-1800_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ1800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ2000'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-2000_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v3/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ2000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ2500'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-2500_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ2500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ3000'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-3000_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ3000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ3500'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-3500_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ3500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ4000'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-4000_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ4000/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WprimeToWZ4500'
    config.Data.inputDataset = '/WprimeToWZToWlepZhad_narrow_M-4500_13TeV-madgraph/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WprimeToWZ4500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
   
    config.General.requestName = 'WJets'
    config.Data.inputDataset = '/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WJets_madgraph'
    config.Data.inputDataset = '/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets_madgraph/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'WJets100'
    config.Data.inputDataset = '/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets100/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'WJets200'
    config.Data.inputDataset = '/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets200/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    
    config.General.requestName = 'WJets400'
    config.Data.inputDataset = '/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets400/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    
    config.General.requestName = 'WJets600'
    config.Data.inputDataset = '/WJetsToLNu_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets600/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WJets600bis'
    config.Data.inputDataset = '/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets600bis/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WJets800'
    config.Data.inputDataset = '/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'WJets1200'
    config.Data.inputDataset = '/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets1200/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WJets2500'
    config.Data.inputDataset = '/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WJets2500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WW'
    config.Data.inputDataset = '/WW_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WW/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WW_excl'
    config.Data.inputDataset = '/WWToLNuQQ_13TeV-powheg/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WW_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WZ'
    config.Data.inputDataset = '/WZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WZ/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'WZ_excl'
    config.Data.inputDataset = '/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/WZ_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'ZZ'
    config.Data.inputDataset = '/ZZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/ZZ/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'ZZ_excl'
    config.Data.inputDataset = '/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/ZZ_excl/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'TTbar_amcatnlo'
    config.Data.inputDataset = '/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v3/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/TTbar_amcatnlo/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'TTbar_powheg'
    config.Data.inputDataset = '/TT_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/TTbar_powheg/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'TTbar_madgraph'
    config.Data.inputDataset = '/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/TTbar_madgraph/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'TTbar600'
    config.Data.inputDataset = '/TTJets_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/TTbar600/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'TTbar800'
    config.Data.inputDataset = '/TTJets_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/TTbar800/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'TTbar1200'
    config.Data.inputDataset = '/TTJets_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/TTbar1200/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'TTbar2500'
    config.Data.inputDataset = '/TTJets_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/TTbar2500/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'sch'
    config.Data.inputDataset = '/ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/sch/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    
    config.General.requestName = 'tch'
    config.Data.inputDataset = '/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/tch/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()


    config.General.requestName = 'tch_bar'
    config.Data.inputDataset = '/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/tch_bar/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'tWch_bar'
    config.Data.inputDataset = '/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/tWch_bar/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    

    config.General.requestName = 'tWch'
    config.Data.inputDataset = '/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_MC_newMINIAOD_21gen2016_JEC_V6_v2/tWch/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    
    #...
