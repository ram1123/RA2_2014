from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'MiniAODDump'
config.General.workArea = 'WWScatteringSamples'
config.section_('JobType')
config.JobType.psetName = 'TreeMaker/test/runMakeTreeFromMiniAOD_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.pyCfgParams = ['global_tag=MCRUN2_74_V9::All', 'MC=True']
config.JobType.inputFiles = ['PHYS14_25_V2_All_L1FastJet_AK8PFchs.txt','PHYS14_25_V2_All_L2Relative_AK8PFchs.txt','PHYS14_25_V2_All_L3Absolute_AK8PFchs.txt','PHYS14_25_V2_All_L1FastJet_AK4PFchs.txt','PHYS14_25_V2_All_L2Relative_AK4PFchs.txt','PHYS14_25_V2_All_L3Absolute_AK4PFchs.txt' ]
config.JobType.allowUndistributedCMSSW = True
config.section_('Data')
config.Data.inputDataset = '/RSGravToWWToLNQQ_kMpl01_M-1000_TuneCUETP8M1_13TeV-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
config.Data.unitsPerJob = 1
config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
config.Data.splitting = 'FileBased'
config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/4Sep15'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T3_US_FNALLPC'

if __name__ == '__main__':
    from CRABAPI.RawCommand import crabCommand

    #Make sure you set this parameter (here or above in the config it does not matter)
    config.General.workArea = 'ntuple_PolSignal'

    def submit(config):
        res = crabCommand('submit', config = config)

    #########    From now on that's what users should modify: this is the a-la-CRAB2 configuration part.
        
    config.General.requestName = 'PolWW_25ns_LL'
    config.Data.inputDataset = '/WWJJToLNuQQ_LL_13TeV-madgraph-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/4Sep15/PolWW_25ns_LL/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'PolWW_25ns_LT'
    config.Data.inputDataset = '/WWJJToLNuQQ_LT_13TeV-madgraph-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/4Sep15/PolWW_25ns_LT/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'PolWW_25ns_TT'
    config.Data.inputDataset = '/WWJJToLNuQQ_TT_13TeV-madgraph-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/MINIAODSIM'
    config.Data.outLFNDirBase = '/store/user/rasharma/WWScattering/4Sep15/PolWW_25ns_TT/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    #...














