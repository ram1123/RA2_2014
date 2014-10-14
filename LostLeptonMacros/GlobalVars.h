#include <vector>
#include <TH2F.h>
#include <iostream>
#include <cmath>
#include <TVector2.h>
#include <TFile.h>
#include "TStyle.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdio> 
#include <sstream>
#include "TROOT.h"

#ifndef _mal2_hpp_
#define _mal2_hpp_
// user defined functions
double deltaR(double eta1, double phi1, double eta2, double phi2);
double MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi);
// Global Variables for debuging documentation and reports
fstream *llLogFile_;
// global variables generell
TFile *outPutFile_;
TString outPutFileName_;
unsigned int toBeProcessedEvents_;
// basic cuts
const double NjetLowLow_=1.6;
const double NjetHighLow_ = 2.6;
const double NjetLow0_=2.6;
const double NjetHigh0_=5.6;
const double NjetLow1_=5.6;
const double NjetHigh1_=7.6;
const double NjetLow2_=7.6;
const double NjetHigh2_=9999;
const int muIsoHTLow_=4;
double MuIsoHTLow_[muIsoHTLow_]={350,500,800,2000};
const int muIsoMHTLow_=7;
double MuIsoMHTLow_[muIsoMHTLow_]={0,50,100,200,450,600,2500};
const int muIsoHT0_=6;
double MuIsoHT0_[muIsoHT0_]={350,500,800,1000,1250,2000};
const int muIsoMHT0_=8;
double MuIsoMHT0_[muIsoMHT0_]={0,50,100,200,300,450,600,2500};
const int muIsoHT1_=7;
double MuIsoHT1_[muIsoHT1_]={350,500,800,1000,1250,1500,2000};
const int muIsoMHT1_=7;
double MuIsoMHT1_[muIsoMHT1_]={0,50,100,200,300,450,2500};
const int muIsoHT2_=7;
double MuIsoHT2_[muIsoHT2_]={350,500,800,1000,1250,1500,2000};
const int muIsoMHT2_=5;
double MuIsoMHT2_[muIsoMHT2_]={0,50,100,200,2500};

const int muRecoHTLow_=4;
double MuRecoHTLow_[muRecoHTLow_]={350,500,800,2000};
const int muRecoMHTLow_=7;
double MuRecoMHTLow_[muRecoMHTLow_]={0,50,100,200,450,600,2500};
const int muRecoHT0_=6;
double MuRecoHT0_[muRecoHT0_]={350,500,800,1000,1250,2000};
const int muRecoMHT0_=8;
double MuRecoMHT0_[muRecoMHT0_]={0,50,100,200,300,450,600,2500};
const int muRecoHT1_=7;
double MuRecoHT1_[muRecoHT1_]={350,500,800,1000,1250,1500,2000};
const int muRecoMHT1_=7;
double MuRecoMHT1_[muRecoMHT1_]={0,50,100,200,300,450,2500};
const int muRecoHT2_=7;
double MuRecoHT2_[muRecoHT2_]={350,500,800,1000,1250,1500,2000};
const int muRecoMHT2_=5;
double MuRecoMHT2_[muRecoMHT2_]={0,50,100,200,2500};


const int muAccMht_ = 7;
double MuAccMht_ [muAccMht_]={0,50,100,200,300,450,2600};
const int muAccNJets_ = 6;
double MuAccNJets_ [muAccNJets_]={2,3,4,6,7,14};

const int elecIsoHTLow_=4;
double ElecIsoHTLow_[elecIsoHTLow_]={350,500,800,2000};
const int elecIsoMHTLow_=7;
double ElecIsoMHTLow_[elecIsoMHTLow_]={0,100,200,300,450,600,2500};
const int elecIsoHT0_=6;
double ElecIsoHT0_[elecIsoHT0_]={350,500,800,1000,1250,2000};
const int elecIsoMHT0_=8;
double ElecIsoMHT0_[elecIsoMHT0_]={0,50,100,200,300,450,600,2500};
const int elecIsoHT1_=7;
double ElecIsoHT1_[elecIsoHT1_]={350,500,800,1000,1250,1500,2000};
const int elecIsoMHT1_=7;
double ElecIsoMHT1_[elecIsoMHT1_]={0,50,100,200,300,450,2500};
const int elecIsoHT2_=7;
double ElecIsoHT2_[elecIsoHT2_]={350,500,800,1000,1250,1500,2000};
const int elecIsoMHT2_=5;
double ElecIsoMHT2_[elecIsoMHT2_]={0,50,100,200,2500};

const int elecRecoHTLow_=5;
double ElecRecoHTLow_[elecRecoHTLow_]={350,500,800,1000,2000};
const int elecRecoMHTLow_=8;
double ElecRecoMHTLow_[elecRecoMHTLow_]={0,50,100,200,300,450,600,2500};
const int elecRecoHT0_=6;
double ElecRecoHT0_[elecRecoHT0_]={350,500,800,1000,1250,2000};
const int elecRecoMHT0_=8;
double ElecRecoMHT0_[elecRecoMHT0_]={0,50,100,200,300,450,600,2500};
const int elecRecoHT1_=7;
double ElecRecoHT1_[elecRecoHT1_]={350,500,800,1000,1250,1500,2000};
const int elecRecoMHT1_=7;
double ElecRecoMHT1_[elecRecoMHT1_]={0,50,100,200,300,450,2500};
const int elecRecoHT2_=7;
double ElecRecoHT2_[elecRecoHT2_]={350,500,800,1000,1250,1500,2000};
const int elecRecoMHT2_=5;
double ElecRecoMHT2_[elecRecoMHT2_]={0,50,100,200,2500};

const int elecAccMht_ = 7;
double ElecAccMht_ [elecAccMht_]={0,50,100,200,300,450,2600};
const int elecAccNJets_ = 6;
double ElecAccNJets_ [elecAccNJets_]={2,3,4,6,7,14};

const int mtwNjet_ = 5;
double MtwNjet_[mtwNjet_] ={2,3,4,5,14};

const int mtwMHT_ = 5;
double MtwMHT_[mtwMHT_] ={0,100,200,400,1600};
TH2F *MuAccEff_;
// reusable variables
string line_;
#endif

