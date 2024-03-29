//------------------------------------------------------------------------------
//
//      Target: Produce fake and prompt rates
//      Authors: Jonatan Piedra, Cedric Prieels
//      Last update: August 24th, 2022
//
//------------------------------------------------------------------------------
TString path_mc   = "";
TString path_data = "";


std::string to_string(int i)
{
  std::stringstream ss;
  ss << i;
  return ss.str();
}


void runNanoFakes(TString year = "2018", TString filename = "NONE")
{
  if (year == "2016_HIPM")
    {
      path_mc   = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer20UL16_106x_nAODv9_HIPM_Full2016v9/MCl1loose2016v9__MCCorr2016v9/";
      path_data = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2016_UL2016_nAODv9_HIPM_Full2016v9/DATAl1loose2016v9/";
    }
  else if (year == "2016_noHIPM")
    {
      path_mc   = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer20UL16_106x_nAODv9_noHIPM_Full2016v9/MCl1loose2016v9__fakeSelKinMC/";
      path_data = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2016_UL2016_nAODv9_noHIPM_Full2016v9/DATAl1loose2016v9__fakeSel/";
    }
  else if (year == "2017")
    {
      path_mc   = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer20UL17_106x_nAODv9_Full2017v9/MCl1loose2017v9__fakeSelKinMC/";
      path_data = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_UL2017_nAODv9_Full2017v9/DATAl1loose2017v9__fakeSel/";
    }
  else if (year == "2018")
    {
      path_mc   = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer20UL18_106x_nAODv9_Full2018v9/MCl1loose2018v9__fakeSelKinMC/";
      path_data = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2018_UL2018_nAODv9_Full2018v9/DATAl1loose2018v9__fakeSel/";
    }
  else
    {
      printf(" The year should be either 2016_noHIPM, 2016_HIPM, 2017 or 2018\n");
      return;
    }

  if (filename.EqualTo("NONE"))
    {
      printf("\n Examples\n\n");
      printf(" root -l -b -q \'runNanoFakes.C(\"2017\", \"nanoLatino_DoubleMuon_Run2017C-UL2017-v1__part0\")\'\n");
      printf(" root -l -b -q \'runNanoFakes.C(\"2017\", \"nanoLatino_SingleElectron_Run2017C-UL2017-v1__part0\")\'\n");
      printf(" root -l -b -q \'runNanoFakes.C(\"%s\", \"nanoLatino_WJetsToLNu-LO__part0\")\'\n", year.Data());
      printf(" root -l -b -q \'runNanoFakes.C(\"%s\", \"nanoLatino_DYJetsToLL_M-50__part0\")\'\n", year.Data());
      printf("\n");

      return;
    }
  
  TString path = (filename.Contains("Run201")) ? path_data : path_mc;

  TChain* mychain = new TChain("Events", "Events");

  mychain->Add(path + filename + ".root");

  printf("\n Executing mychain->Process(\"nanoFakes.C+\")...\n\n");

  TString option = year + filename;

//mychain->Process("/afs/cern.ch/work/p/piedra/public/fakes/CMSSW_10_1_0/src/FakeRateMeasurement/nanoFakes.C+", option);
  mychain->Process("nanoFakes.C", option);
  
  return;
}
