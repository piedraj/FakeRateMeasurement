Int_t   year;

TString inputdir;


void getYields(Int_t the_year = -1)
{
  if (the_year < 0)
    {
      printf("\n");
      printf(" root -l -b -q getYields.C\\(2017\\)\n");
      printf(" root -l -b -q getYields.C\\(2018\\)\n");
      printf("\n");

      return;
    }

  year = the_year;

  inputdir = Form("results/%d", year);

  TFile* data  = new TFile (inputdir + "/hadd_data.root",  "read");
  TFile* wjets = new TFile (inputdir + "/hadd_wjets.root", "read");
  TFile* zjets = new TFile (inputdir + "/hadd_zjets.root", "read");

  TString muonjetet = "_25GeV";
  TString elejetet  = "_35GeV";


  // Loose muons
  //----------------------------------------------------------------------------
  TH1D* h_data_Muon_loose_lowpt            = (TH1D*)data->Get("FR/00_QCD/h_Muon_loose_lowpt"            + muonjetet);
  TH1D* h_data_Muon_loose_highpt           = (TH1D*)data->Get("FR/00_QCD/h_Muon_loose_highpt"           + muonjetet);
  TH1D* h_data_Muon_loose_lowpt_weighted   = (TH1D*)data->Get("FR/00_QCD/h_Muon_loose_lowpt_weighted"   + muonjetet);
  TH1D* h_data_Muon_loose_highpt_weighted  = (TH1D*)data->Get("FR/00_QCD/h_Muon_loose_highpt_weighted"  + muonjetet);

  TH1D* h_wjets_Muon_loose_lowpt           = (TH1D*)wjets->Get("FR/00_QCD/h_Muon_loose_lowpt"           + muonjetet);
  TH1D* h_wjets_Muon_loose_highpt          = (TH1D*)wjets->Get("FR/00_QCD/h_Muon_loose_highpt"          + muonjetet);
  TH1D* h_wjets_Muon_loose_lowpt_weighted  = (TH1D*)wjets->Get("FR/00_QCD/h_Muon_loose_lowpt_weighted"  + muonjetet);
  TH1D* h_wjets_Muon_loose_highpt_weighted = (TH1D*)wjets->Get("FR/00_QCD/h_Muon_loose_highpt_weighted" + muonjetet);

  TH1D* h_zjets_Muon_loose_lowpt           = (TH1D*)zjets->Get("FR/00_QCD/h_Muon_loose_lowpt"           + muonjetet);
  TH1D* h_zjets_Muon_loose_lowpt_weighted  = (TH1D*)zjets->Get("FR/00_QCD/h_Muon_loose_lowpt_weighted"  + muonjetet);
  TH1D* h_zjets_Muon_loose_highpt          = (TH1D*)zjets->Get("FR/00_QCD/h_Muon_loose_highpt"          + muonjetet);
  TH1D* h_zjets_Muon_loose_highpt_weighted = (TH1D*)zjets->Get("FR/00_QCD/h_Muon_loose_highpt_weighted" + muonjetet);


  // Tight muons
  //----------------------------------------------------------------------------
  TH1D* h_data_Muon_tight_lowpt            = (TH1D*)data->Get("FR/00_QCD/h_Muon_tight_lowpt"            + muonjetet);
  TH1D* h_data_Muon_tight_highpt           = (TH1D*)data->Get("FR/00_QCD/h_Muon_tight_highpt"           + muonjetet);
  TH1D* h_data_Muon_tight_lowpt_weighted   = (TH1D*)data->Get("FR/00_QCD/h_Muon_tight_lowpt_weighted"   + muonjetet);
  TH1D* h_data_Muon_tight_highpt_weighted  = (TH1D*)data->Get("FR/00_QCD/h_Muon_tight_highpt_weighted"  + muonjetet);

  TH1D* h_wjets_Muon_tight_lowpt           = (TH1D*)wjets->Get("FR/00_QCD/h_Muon_tight_lowpt"           + muonjetet);
  TH1D* h_wjets_Muon_tight_highpt          = (TH1D*)wjets->Get("FR/00_QCD/h_Muon_tight_highpt"          + muonjetet);
  TH1D* h_wjets_Muon_tight_lowpt_weighted  = (TH1D*)wjets->Get("FR/00_QCD/h_Muon_tight_lowpt_weighted"  + muonjetet);
  TH1D* h_wjets_Muon_tight_highpt_weighted = (TH1D*)wjets->Get("FR/00_QCD/h_Muon_tight_highpt_weighted" + muonjetet);

  TH1D* h_zjets_Muon_tight_lowpt           = (TH1D*)zjets->Get("FR/00_QCD/h_Muon_tight_lowpt"           + muonjetet);
  TH1D* h_zjets_Muon_tight_highpt          = (TH1D*)zjets->Get("FR/00_QCD/h_Muon_tight_highpt"          + muonjetet);
  TH1D* h_zjets_Muon_tight_lowpt_weighted  = (TH1D*)zjets->Get("FR/00_QCD/h_Muon_tight_lowpt_weighted"  + muonjetet);
  TH1D* h_zjets_Muon_tight_highpt_weighted = (TH1D*)zjets->Get("FR/00_QCD/h_Muon_tight_highpt_weighted" + muonjetet);


  // Loose electrons
  //----------------------------------------------------------------------------
  TH1D* h_data_Ele_loose_lowpt            = (TH1D*)data->Get("FR/00_QCD/h_Ele_loose_lowpt"            + elejetet);
  TH1D* h_data_Ele_loose_highpt           = (TH1D*)data->Get("FR/00_QCD/h_Ele_loose_highpt"           + elejetet);
  TH1D* h_data_Ele_loose_lowpt_weighted   = (TH1D*)data->Get("FR/00_QCD/h_Ele_loose_lowpt_weighted"   + elejetet);
  TH1D* h_data_Ele_loose_highpt_weighted  = (TH1D*)data->Get("FR/00_QCD/h_Ele_loose_highpt_weighted"  + elejetet);

  TH1D* h_wjets_Ele_loose_lowpt           = (TH1D*)wjets->Get("FR/00_QCD/h_Ele_loose_lowpt"           + elejetet);
  TH1D* h_wjets_Ele_loose_highpt          = (TH1D*)wjets->Get("FR/00_QCD/h_Ele_loose_highpt"          + elejetet);
  TH1D* h_wjets_Ele_loose_lowpt_weighted  = (TH1D*)wjets->Get("FR/00_QCD/h_Ele_loose_lowpt_weighted"  + elejetet);
  TH1D* h_wjets_Ele_loose_highpt_weighted = (TH1D*)wjets->Get("FR/00_QCD/h_Ele_loose_highpt_weighted" + elejetet);

  TH1D* h_zjets_Ele_loose_lowpt           = (TH1D*)zjets->Get("FR/00_QCD/h_Ele_loose_lowpt"           + elejetet);
  TH1D* h_zjets_Ele_loose_highpt          = (TH1D*)zjets->Get("FR/00_QCD/h_Ele_loose_highpt"          + elejetet);
  TH1D* h_zjets_Ele_loose_lowpt_weighted  = (TH1D*)zjets->Get("FR/00_QCD/h_Ele_loose_lowpt_weighted"  + elejetet);
  TH1D* h_zjets_Ele_loose_highpt_weighted = (TH1D*)zjets->Get("FR/00_QCD/h_Ele_loose_highpt_weighted" + elejetet);


  // Tight electrons
  //----------------------------------------------------------------------------
  TH1D* h_data_Ele_tight_lowpt            = (TH1D*)data->Get("FR/00_QCD/h_Ele_tight_lowpt"            + elejetet);
  TH1D* h_data_Ele_tight_highpt           = (TH1D*)data->Get("FR/00_QCD/h_Ele_tight_highpt"           + elejetet);
  TH1D* h_data_Ele_tight_lowpt_weighted   = (TH1D*)data->Get("FR/00_QCD/h_Ele_tight_lowpt_weighted"   + elejetet);
  TH1D* h_data_Ele_tight_highpt_weighted  = (TH1D*)data->Get("FR/00_QCD/h_Ele_tight_highpt_weighted"  + elejetet);

  TH1D* h_wjets_Ele_tight_lowpt           = (TH1D*)wjets->Get("FR/00_QCD/h_Ele_tight_lowpt"           + elejetet);
  TH1D* h_wjets_Ele_tight_highpt          = (TH1D*)wjets->Get("FR/00_QCD/h_Ele_tight_highpt"          + elejetet);
  TH1D* h_wjets_Ele_tight_lowpt_weighted  = (TH1D*)wjets->Get("FR/00_QCD/h_Ele_tight_lowpt_weighted"  + elejetet);
  TH1D* h_wjets_Ele_tight_highpt_weighted = (TH1D*)wjets->Get("FR/00_QCD/h_Ele_tight_highpt_weighted" + elejetet);

  TH1D* h_zjets_Ele_tight_lowpt           = (TH1D*)zjets->Get("FR/00_QCD/h_Ele_tight_lowpt"           + elejetet);
  TH1D* h_zjets_Ele_tight_highpt          = (TH1D*)zjets->Get("FR/00_QCD/h_Ele_tight_highpt"          + elejetet);
  TH1D* h_zjets_Ele_tight_lowpt_weighted  = (TH1D*)zjets->Get("FR/00_QCD/h_Ele_tight_lowpt_weighted"  + elejetet);
  TH1D* h_zjets_Ele_tight_highpt_weighted = (TH1D*)zjets->Get("FR/00_QCD/h_Ele_tight_highpt_weighted" + elejetet);


  // Prescales applied for each year as in nanoFakes.C
  //----------------------------------------------------------------------------
  printf("\n Prescales applied for %d in nanoFakes.C\n\n", year);

  if (year == 2016) {
    printf("\t  14.851/pb - HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30\n");
    printf("\t  62.808/pb - HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30\n");
    printf("\t   7.801/pb - HLT_Mu8_TrkIsoVVL\n");
    printf("\t 216.748/pb - HLT_Mu17_TrkIsoVVL\n");
  }
  else if (year == 2017) {
    printf("\t  3.973/pb - HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30\n");
    printf("\t 27.699/pb - HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 (not used)\n");
    printf("\t 43.469/pb - HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30\n");
    printf("\t  2.903/pb - HLT_Mu8_TrkIsoVVL\n");
    printf("\t 65.944/pb - HLT_Mu17_TrkIsoVVL\n");
  }
  else if (year == 2018) {
    printf("\t  6.412/pb - HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30\n");
    printf("\t 38.849/pb - HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 (not used)\n");
    printf("\t 38.906/pb - HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30\n");
    printf("\t  8.561/pb - HLT_Mu8_TrkIsoVVL\n");
    printf("\t 45.781/pb - HLT_Mu17_TrkIsoVVL\n");
  }

  printf("\n");


  // Print muons
  //----------------------------------------------------------------------------
  printf("     Low pt loose muons %6s %6s %6s |",  "data", "Z+jets", "W+jets");
  printf("     High pt loose muons %6s %6s %6s\n", "data", "Z+jets", "W+jets");
  printf("                    Raw %6.0f %6.0f %6.0f |",
	 h_data_Muon_loose_lowpt->Integral(-1,-1),
	 h_zjets_Muon_loose_lowpt->Integral(-1,-1),
	 h_wjets_Muon_loose_lowpt->Integral(-1,-1));
  printf("                     Raw %6.0f %6.0f %6.0f\n",
	 h_data_Muon_loose_highpt->Integral(-1,-1),
	 h_zjets_Muon_loose_highpt->Integral(-1,-1),
	 h_wjets_Muon_loose_highpt->Integral(-1,-1));
  printf("               Weighted %6.0f %6.1f %6.1f |",
	 h_data_Muon_loose_lowpt_weighted->Integral(-1,-1),
	 h_zjets_Muon_loose_lowpt_weighted->Integral(-1,-1),
	 h_wjets_Muon_loose_lowpt_weighted->Integral(-1,-1));
  printf("                Weighted %6.0f %6.1f %6.1f\n\n",
	 h_data_Muon_loose_highpt_weighted->Integral(-1,-1),
	 h_zjets_Muon_loose_highpt_weighted->Integral(-1,-1),
	 h_wjets_Muon_loose_highpt_weighted->Integral(-1,-1));

  printf("     Low pt tight muons %6s %6s %6s |",  "data", "Z+jets", "W+jets");
  printf("     High pt tight muons %6s %6s %6s\n", "data", "Z+jets", "W+jets");
  printf("                    Raw %6.0f %6.0f %6.0f |",
	 h_data_Muon_tight_lowpt->Integral(-1,-1),
	 h_zjets_Muon_tight_lowpt->Integral(-1,-1),
	 h_wjets_Muon_tight_lowpt->Integral(-1,-1));
  printf("                     Raw %6.0f %6.0f %6.0f\n",
	 h_data_Muon_tight_highpt->Integral(-1,-1),
	 h_zjets_Muon_tight_highpt->Integral(-1,-1),
	 h_wjets_Muon_tight_highpt->Integral(-1,-1));
  printf("               Weighted %6.0f %6.1f %6.1f |",
	 h_data_Muon_tight_lowpt_weighted->Integral(-1,-1),
	 h_zjets_Muon_tight_lowpt_weighted->Integral(-1,-1),
	 h_wjets_Muon_tight_lowpt_weighted->Integral(-1,-1));
  printf("                Weighted %6.0f %6.1f %6.1f\n\n",
	 h_data_Muon_tight_highpt_weighted->Integral(-1,-1),
	 h_zjets_Muon_tight_highpt_weighted->Integral(-1,-1),
	 h_wjets_Muon_tight_highpt_weighted->Integral(-1,-1));


  // Print electrons
  //----------------------------------------------------------------------------
  printf(" Low pt loose electrons %6s %6s %6s |",  "data", "Z+jets", "W+jets");
  printf(" High pt loose electrons %6s %6s %6s\n", "data", "Z+jets", "W+jets");
  printf("                    Raw %6.0f %6.0f %6.0f |",
	 h_data_Ele_loose_lowpt->Integral(-1,-1),
	 h_zjets_Ele_loose_lowpt->Integral(-1,-1),
	 h_wjets_Ele_loose_lowpt->Integral(-1,-1));
  printf("                     Raw %6.0f %6.0f %6.0f\n",
	 h_data_Ele_loose_highpt->Integral(-1,-1),
	 h_zjets_Ele_loose_highpt->Integral(-1,-1),
	 h_wjets_Ele_loose_highpt->Integral(-1,-1));
  printf("               Weighted %6.0f %6.1f %6.1f |",
	 h_data_Ele_loose_lowpt_weighted->Integral(-1,-1),
	 h_zjets_Ele_loose_lowpt_weighted->Integral(-1,-1),
	 h_wjets_Ele_loose_lowpt_weighted->Integral(-1,-1));
  printf("                Weighted %6.0f %6.1f %6.1f\n\n",
	 h_data_Ele_loose_highpt_weighted->Integral(-1,-1),
	 h_zjets_Ele_loose_highpt_weighted->Integral(-1,-1),
	 h_wjets_Ele_loose_highpt_weighted->Integral(-1,-1));

  printf(" Low pt tight electrons %6s %6s %6s |",  "data", "Z+jets", "W+jets");
  printf(" High pt tight electrons %6s %6s %6s\n", "data", "Z+jets", "W+jets");
  printf("                    Raw %6.0f %6.0f %6.0f |",
	 h_data_Ele_tight_lowpt->Integral(-1,-1),
	 h_zjets_Ele_tight_lowpt->Integral(-1,-1),
	 h_wjets_Ele_tight_lowpt->Integral(-1,-1));
  printf("                     Raw %6.0f %6.0f %6.0f\n",
	 h_data_Ele_tight_highpt->Integral(-1,-1),
	 h_zjets_Ele_tight_highpt->Integral(-1,-1),
	 h_wjets_Ele_tight_highpt->Integral(-1,-1));
  printf("               Weighted %6.0f %6.1f %6.1f |",
	 h_data_Ele_tight_lowpt_weighted->Integral(-1,-1),
	 h_zjets_Ele_tight_lowpt_weighted->Integral(-1,-1),
	 h_wjets_Ele_tight_lowpt_weighted->Integral(-1,-1));
  printf("                Weighted %6.0f %6.1f %6.1f\n\n",
	 h_data_Ele_tight_highpt_weighted->Integral(-1,-1),
	 h_zjets_Ele_tight_highpt_weighted->Integral(-1,-1),
	 h_wjets_Ele_tight_highpt_weighted->Integral(-1,-1));
}
