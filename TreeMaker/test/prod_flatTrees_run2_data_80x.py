from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'data_mu'
config.General.workArea = 'data_mu'
config.section_('JobType')
config.JobType.psetName = 'TreeMaker/test/runMakeTreeFromMiniAOD_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.pyCfgParams = ['global_tag=80X_dataRun2_Prompt_v8','leptonFilter=True', 'MC=False', 'isCrab=True', 'DoJECCorrection=True', 'isHBHERun2015D=False', 'DoPuppi=True','ReDoPruningAndSoftdropPuppi=True']
config.JobType.allowUndistributedCMSSW = True
#config.JobType.maxMemoryMB = 2500    # 2.5 GB                      
config.JobType.maxJobRuntimeMin = 900 #15 h
config.JobType.inputFiles = ['Spring16_25nsV3_DATA_L1FastJet_AK8PFchs.txt','Spring16_25nsV3_DATA_L2Relative_AK8PFchs.txt','Spring16_25nsV3_DATA_L3Absolute_AK8PFchs.txt','Spring16_25nsV3_DATA_L2L3Residual_AK8PFchs.txt','Spring16_25nsV3_DATA_L1FastJet_AK4PFchs.txt','Spring16_25nsV3_DATA_L2Relative_AK4PFchs.txt','Spring16_25nsV3_DATA_L3Absolute_AK4PFchs.txt','Spring16_25nsV3_DATA_L2L3Residual_AK4PFchs.txt','Spring16_25nsV3_DATA_Uncertainty_AK4PFchs.txt','Spring16_25nsV3_DATA_Uncertainty_AK8PFchs.txt','Spring16_25nsV3_DATA_L1FastJet_AK8PFPuppi.txt','Spring16_25nsV3_DATA_L2Relative_AK8PFPuppi.txt','Spring16_25nsV3_DATA_L3Absolute_AK8PFPuppi.txt','Spring16_25nsV3_DATA_L2L3Residual_AK8PFPuppi.txt','Spring16_25nsV3_DATA_L1FastJet_AK4PFPuppi.txt','Spring16_25nsV3_DATA_L2Relative_AK4PFPuppi.txt','Spring16_25nsV3_DATA_L3Absolute_AK4PFPuppi.txt','Spring16_25nsV3_DATA_L2L3Residual_AK4PFPuppi.txt','Spring16_25nsV3_DATA_Uncertainty_AK4PFPuppi.txt','Spring16_25nsV3_DATA_Uncertainty_AK8PFPuppi.txt' ]
config.section_('Data')
config.Data.inputDataset = '/SingleMuon/Run2015B-PromptReco-v1/MINIAOD'
config.Data.unitsPerJob = 7
#config.Data.lumiMask = 'json/Cert_271036-275125_13TeV_PromptReco_Collisions16_JSON.txt' #2016, 3.99/fb
#config.Data.lumiMask = 'json/Cert_271036-275783_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt' #5.8/fb
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-276811_13TeV_PromptReco_Collisions16_JSON.txt' #ICHEP, 12.9/fb
#config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Final/Cert_271036-284044_13TeV_PromptReco_Collisions16_JSON.txt'
config.Data.inputDBS = 'global' #'http://cmsdbsprod.cern.ch/cms_dbs_prod_global/servlet/DBSServlet'
config.Data.splitting = 'LumiBased'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/ntuple_data_mu/'
#config.Data.runRange = '275126-275783'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
config.Site.blacklist= ['T2_US_Purdue','T2_UA_KIPT']

if __name__ == '__main__':
    from CRABAPI.RawCommand import crabCommand

    #Make sure you set this parameter (here or above in the config it does not matter)
    config.General.workArea = 'data_2016_ichep_13dec'

    def submit(config):
        res = crabCommand('submit', config = config)

    #########    From now on that's what users should modify: this is the a-la-CRAB2 configuration part.
    config.General.requestName = 'data_el_2016_runB_v2'
    config.Data.inputDataset = '/SingleElectron/Run2016B-PromptReco-v2/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runB_v2/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_el_2016_runC_v2'
    config.Data.inputDataset = '/SingleElectron/Run2016C-PromptReco-v2/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runC_v2/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_el_2016_runD_v2'
    config.Data.inputDataset = '/SingleElectron/Run2016D-PromptReco-v2/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runD_v2/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    '''
    config.General.requestName = 'data_el_2016_runE_v1'
    config.Data.inputDataset = '/SingleElectron/Run2016E-PromptReco-v1/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runE_v1/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_el_2016_runF_v1'
    config.Data.inputDataset = '/SingleElectron/Run2016F-PromptReco-v1/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runF_v1/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_el_2016_runG_v1'
    config.Data.inputDataset = '/SingleElectron/Run2016G-PromptReco-v1/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runG_v1/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_el_2016_runH_v1'
    config.Data.inputDataset = '/SingleElectron/Run2016H-PromptReco-v1/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runH_v1/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_el_2016_runH_v2'
    config.Data.inputDataset = '/SingleElectron/Run2016H-PromptReco-v2/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runH_v2/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_el_2016_runH_v3'
    config.Data.inputDataset = '/SingleElectron/Run2016H-PromptReco-v3/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_el_2016_runH_v3/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    '''

    config.General.requestName = 'data_mu_2016_runB_v2'
    config.Data.inputDataset = '/SingleMuon/Run2016B-PromptReco-v2/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runB_v2/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_mu_2016_runC_v2'
    config.Data.inputDataset = '/SingleMuon/Run2016C-PromptReco-v2/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runC_v2/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_mu_2016_runD_v2'
    config.Data.inputDataset = '/SingleMuon/Run2016D-PromptReco-v2/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runD_v2/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    '''
    config.General.requestName = 'data_mu_2016_runE_v1'
    config.Data.inputDataset = '/SingleMuon/Run2016E-PromptReco-v1/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runE_v1/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_mu_2016_runF_v1'
    config.Data.inputDataset = '/SingleMuon/Run2016F-PromptReco-v1/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runF_v1/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_mu_2016_runG_v1'
    config.Data.inputDataset = '/SingleMuon/Run2016G-PromptReco-v1/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runG_v1/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_mu_2016_runH_v1'
    config.Data.inputDataset = '/SingleMuon/Run2016H-PromptReco-v1/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runH_v1/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_mu_2016_runH_v2'
    config.Data.inputDataset = '/SingleMuon/Run2016H-PromptReco-v2/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runH_v2/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    config.General.requestName = 'data_mu_2016_runH_v3'
    config.Data.inputDataset = '/SingleMuon/Run2016H-PromptReco-v3/MINIAOD'
    config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/ecalMIBI/lbrianza/data_2016_ichep_13dec/data_mu_2016_runH_v3/'
    from multiprocessing import Process
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
    '''

    #...
