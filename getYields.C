Int_t   year;

TString inputdir;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// root -l -b -q getYields.C\(2017\)
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void getYields(Int_t the_year = 2017)
{
  year = the_year;

  inputdir = Form("results/%d", year);

  TFile* data  = new TFile (inputdir + "/hadd_data.root",  "read");
  TFile* wjets = new TFile (inputdir + "/hadd_wjets.root", "read");
  TFile* zjets = new TFile (inputdir + "/hadd_zjets.root", "read");

  TString muonjetet = "_25GeV";
  TString elejetet  = "_35GeV";


  // Loose muons
  //----------------------------------------------------------------------------
  TH1D* h_data_Muon_loose_lowpt           = (TH1D*)data->Get("FR/00_QCD/h_Muon_loose_lowpt"           + muonjetet);
  TH1D* h_data_Muon_loose_highpt          = (TH1D*)data->Get("FR/00_QCD/h_Muon_loose_highpt"          + muonjetet);
  TH1D* h_data_Muon_loose_lowpt_weighted  = (TH1D*)data->Get("FR/00_QCD/h_Muon_loose_lowpt_weighted"  + muonjetet);
  TH1D* h_data_Muon_loose_highpt_weighted = (TH1D*)data->Get("FR/00_QCD/h_Muon_loose_highpt_weighted" + muonjetet);

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
  TH1D* h_data_Muon_tight_lowpt  = (TH1D*)data ->Get("FR/00_QCD/h_Muon_tight_lowpt" + muonjetet);
  TH1D* h_data_Muon_tight_lowpt_weighted  = (TH1D*)data ->Get("FR/00_QCD/h_Muon_tight_lowpt_weighted" + muonjetet);
  TH1D* h_data_Muon_tight_highpt  = (TH1D*)data ->Get("FR/00_QCD/h_Muon_tight_highpt" + muonjetet);
  TH1D* h_data_Muon_tight_highpt_weighted  = (TH1D*)data ->Get("FR/00_QCD/h_Muon_tight_highpt_weighted" + muonjetet);

  TH1D* h_wjets_Muon_tight_lowpt  = (TH1D*)wjets ->Get("FR/00_QCD/h_Muon_tight_lowpt" + muonjetet);
  TH1D* h_wjets_Muon_tight_lowpt_weighted  = (TH1D*)wjets ->Get("FR/00_QCD/h_Muon_tight_lowpt_weighted" + muonjetet);
  TH1D* h_wjets_Muon_tight_highpt  = (TH1D*)wjets ->Get("FR/00_QCD/h_Muon_tight_highpt" + muonjetet);
  TH1D* h_wjets_Muon_tight_highpt_weighted  = (TH1D*)wjets ->Get("FR/00_QCD/h_Muon_tight_highpt_weighted" + muonjetet);

  TH1D* h_zjets_Muon_tight_lowpt  = (TH1D*)zjets ->Get("FR/00_QCD/h_Muon_tight_lowpt" + muonjetet);
  TH1D* h_zjets_Muon_tight_lowpt_weighted  = (TH1D*)zjets ->Get("FR/00_QCD/h_Muon_tight_lowpt_weighted" + muonjetet);
  TH1D* h_zjets_Muon_tight_highpt  = (TH1D*)zjets ->Get("FR/00_QCD/h_Muon_tight_highpt" + muonjetet);
  TH1D* h_zjets_Muon_tight_highpt_weighted  = (TH1D*)zjets ->Get("FR/00_QCD/h_Muon_tight_highpt_weighted" + muonjetet);


  //Electrons
  //----------------------------------------------------------------------------

  //Electrons loose
  TH1D* h_data_Ele_loose_lowpt  = (TH1D*)data ->Get("FR/00_QCD/h_Ele_loose_lowpt" + elejetet);
  TH1D* h_data_Ele_loose_lowpt_weighted  = (TH1D*)data ->Get("FR/00_QCD/h_Ele_loose_lowpt_weighted" + elejetet);
  TH1D* h_data_Ele_loose_highpt  = (TH1D*)data ->Get("FR/00_QCD/h_Ele_loose_highpt" + elejetet);
  TH1D* h_data_Ele_loose_highpt_weighted  = (TH1D*)data ->Get("FR/00_QCD/h_Ele_loose_highpt_weighted" + elejetet);

  TH1D* h_wjets_Ele_loose_lowpt  = (TH1D*)wjets ->Get("FR/00_QCD/h_Ele_loose_lowpt" + elejetet);
  TH1D* h_wjets_Ele_loose_lowpt_weighted  = (TH1D*)wjets ->Get("FR/00_QCD/h_Ele_loose_lowpt_weighted" + elejetet);
  TH1D* h_wjets_Ele_loose_highpt  = (TH1D*)wjets ->Get("FR/00_QCD/h_Ele_loose_highpt" + elejetet);
  TH1D* h_wjets_Ele_loose_highpt_weighted  = (TH1D*)wjets ->Get("FR/00_QCD/h_Ele_loose_highpt_weighted" + elejetet);

  TH1D* h_zjets_Ele_loose_lowpt  = (TH1D*)zjets ->Get("FR/00_QCD/h_Ele_loose_lowpt" + elejetet);
  TH1D* h_zjets_Ele_loose_lowpt_weighted  = (TH1D*)zjets ->Get("FR/00_QCD/h_Ele_loose_lowpt_weighted" + elejetet);
  TH1D* h_zjets_Ele_loose_highpt  = (TH1D*)zjets ->Get("FR/00_QCD/h_Ele_loose_highpt" + elejetet);
  TH1D* h_zjets_Ele_loose_highpt_weighted  = (TH1D*)zjets ->Get("FR/00_QCD/h_Ele_loose_highpt_weighted" + elejetet);

  //Electrons tight
  TH1D* h_data_Ele_tight_lowpt  = (TH1D*)data ->Get("FR/00_QCD/h_Ele_tight_lowpt" + elejetet);
  TH1D* h_data_Ele_tight_lowpt_weighted  = (TH1D*)data ->Get("FR/00_QCD/h_Ele_tight_lowpt_weighted" + elejetet);
  TH1D* h_data_Ele_tight_highpt  = (TH1D*)data ->Get("FR/00_QCD/h_Ele_tight_highpt" + elejetet);
  TH1D* h_data_Ele_tight_highpt_weighted  = (TH1D*)data ->Get("FR/00_QCD/h_Ele_tight_highpt_weighted" + elejetet);

  TH1D* h_wjets_Ele_tight_lowpt  = (TH1D*)wjets ->Get("FR/00_QCD/h_Ele_tight_lowpt" + elejetet);
  TH1D* h_wjets_Ele_tight_lowpt_weighted  = (TH1D*)wjets ->Get("FR/00_QCD/h_Ele_tight_lowpt_weighted" + elejetet);
  TH1D* h_wjets_Ele_tight_highpt  = (TH1D*)wjets ->Get("FR/00_QCD/h_Ele_tight_highpt" + elejetet);
  TH1D* h_wjets_Ele_tight_highpt_weighted  = (TH1D*)wjets ->Get("FR/00_QCD/h_Ele_tight_highpt_weighted" + elejetet);

  TH1D* h_zjets_Ele_tight_lowpt  = (TH1D*)zjets ->Get("FR/00_QCD/h_Ele_tight_lowpt" + elejetet);
  TH1D* h_zjets_Ele_tight_lowpt_weighted  = (TH1D*)zjets ->Get("FR/00_QCD/h_Ele_tight_lowpt_weighted" + elejetet);
  TH1D* h_zjets_Ele_tight_highpt  = (TH1D*)zjets ->Get("FR/00_QCD/h_Ele_tight_highpt" + elejetet);
  TH1D* h_zjets_Ele_tight_highpt_weighted  = (TH1D*)zjets ->Get("FR/00_QCD/h_Ele_tight_highpt_weighted" + elejetet);

  
  printf("\n \n ==========================================================================");
  printf("\n ================================ YIELDS ==================================");
  printf("\n ========================================================================== \n");

  // Prescales applied for each year as in nanoFakes.C

  if (year == 2016) {
    printf("      * HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 (14.851/pb) \n");
    printf("      * HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 (62.808/pb) \n");
    printf("      * HLT_Mu8_TrkIsoVVL (7.801/pb) \n");
    printf("      * HLT_Mu17_TrkIsoVVL (216.748/pb) \n");
  }
  else if (year == 2017) {
    printf("      * HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 (3.973/pb) \n");
    //    printf("      * HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 (27.699/pb) \n");
    printf("      * HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 (43.469/pb) \n");
    printf("      * HLT_Mu8_TrkIsoVVL (2.903/pb) \n");
    printf("      * HLT_Mu17_TrkIsoVVL (65.944/pb) \n");
  }
  else if (year == 2018) {
    printf("      * HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 (6.412/pb) \n");
    //    printf("      * HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 (38.849/pb) \n");
    printf("      * HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 (38.906/pb) \n");
    printf("      * HLT_Mu8_TrkIsoVVL (8.561/pb) \n");
    printf("      * HLT_Mu17_TrkIsoVVL (45.781/pb) \n");
  }


  printf("========================================================================== \n");

  printf("\n");

  printf("& & Data & \\multicolumn{3}{c|}{W+jets} & \\multicolumn{3}{c}{Z+jets} \\\\ \n");
  printf("& Trigger & & W/o weight & With & Ratio & W/o weight & With & Ratio \\\\ \n");
  printf("\\hline \n");

  printf("\\multirow{2}{*}{Loose muons}& low $p_T$ & %.0f & %.1f & %.1f & %.3f & %.1f & %.1f & %.3f \\\\ \n", h_data_Muon_loose_lowpt->Integral(-1, -1), h_wjets_Muon_loose_lowpt->Integral(-1, -1), h_wjets_Muon_loose_lowpt_weighted->Integral(-1, -1), (h_wjets_Muon_loose_lowpt_weighted->Integral(-1, -1)/h_wjets_Muon_loose_lowpt->Integral(-1, -1)), h_zjets_Muon_loose_lowpt->Integral(-1, -1), h_zjets_Muon_loose_lowpt_weighted->Integral(-1, -1), (h_zjets_Muon_loose_lowpt_weighted->Integral(-1, -1)/h_zjets_Muon_loose_lowpt->Integral(-1, -1)));
  printf("& high $p_T$ &  %.0f & %.1f & %.1f & %.3f & %.1f & %.1f & %.3f \\\\ \n", h_data_Muon_loose_highpt->Integral(-1, -1), h_wjets_Muon_loose_highpt->Integral(-1, -1), h_wjets_Muon_loose_highpt_weighted->Integral(-1, -1), (h_wjets_Muon_loose_highpt_weighted->Integral(-1, -1)/h_wjets_Muon_loose_highpt->Integral(-1, -1)), h_zjets_Muon_loose_highpt->Integral(-1, -1), h_zjets_Muon_loose_highpt_weighted->Integral(-1, -1), (h_zjets_Muon_loose_highpt_weighted->Integral(-1, -1)/h_zjets_Muon_loose_highpt->Integral(-1, -1)));
  printf("\\hline \n");

  printf("\\multirow{2}{*}{Tight muons}& low $p_T$ & %.0f & %.1f & %.1f & %.3f & %.1f & %.1f & %.3f \\\\ \n", h_data_Muon_tight_lowpt->Integral(-1, -1), h_wjets_Muon_tight_lowpt->Integral(-1, -1), h_wjets_Muon_tight_lowpt_weighted->Integral(-1, -1), (h_wjets_Muon_tight_lowpt_weighted->Integral(-1, -1)/h_wjets_Muon_tight_lowpt->Integral(-1, -1)), h_zjets_Muon_tight_lowpt->Integral(-1, -1), h_zjets_Muon_tight_lowpt_weighted->Integral(-1, -1), (h_zjets_Muon_tight_lowpt_weighted->Integral(-1, -1)/h_zjets_Muon_tight_lowpt->Integral(-1, -1)));
  printf("& high $p_T$ &  %.0f & %.1f & %.1f & %.3f & %.1f & %.1f & %.3f \\\\ \n", h_data_Muon_tight_highpt->Integral(-1, -1), h_wjets_Muon_tight_highpt->Integral(-1, -1), h_wjets_Muon_tight_highpt_weighted->Integral(-1, -1), (h_wjets_Muon_tight_highpt_weighted->Integral(-1, -1)/h_wjets_Muon_tight_highpt->Integral(-1, -1)), h_zjets_Muon_tight_highpt->Integral(-1, -1), h_zjets_Muon_tight_highpt_weighted->Integral(-1, -1), (h_zjets_Muon_tight_highpt_weighted->Integral(-1, -1)/h_zjets_Muon_tight_highpt->Integral(-1, -1)));
  printf("\\hline \n");

  printf("\\multirow{2}{*}{Loose Electrons}& low $p_T$ & %.0f & %.1f & %.1f & %.3f & %.1f & %.1f & %.3f \\\\ \n", h_data_Ele_loose_lowpt->Integral(-1, -1), h_wjets_Ele_loose_lowpt->Integral(-1, -1), h_wjets_Ele_loose_lowpt_weighted->Integral(-1, -1), (h_wjets_Ele_loose_lowpt_weighted->Integral(-1, -1)/h_wjets_Ele_loose_lowpt->Integral(-1, -1)), h_zjets_Ele_loose_lowpt->Integral(-1, -1), h_zjets_Ele_loose_lowpt_weighted->Integral(-1, -1), (h_zjets_Ele_loose_lowpt_weighted->Integral(-1, -1)/h_zjets_Ele_loose_lowpt->Integral(-1, -1)));
  printf("& high $p_T$ &  %.0f & %.1f & %.1f & %.3f & %.1f & %.1f & %.3f \\\\ \n", h_data_Ele_loose_highpt->Integral(-1, -1), h_wjets_Ele_loose_highpt->Integral(-1, -1), h_wjets_Ele_loose_highpt_weighted->Integral(-1, -1), (h_wjets_Ele_loose_highpt_weighted->Integral(-1, -1)/h_wjets_Ele_loose_highpt->Integral(-1, -1)), h_zjets_Ele_loose_highpt->Integral(-1, -1), h_zjets_Ele_loose_highpt_weighted->Integral(-1, -1), (h_zjets_Ele_loose_highpt_weighted->Integral(-1, -1)/h_zjets_Ele_loose_highpt->Integral(-1, -1)));
  printf("\\hline \n");

  printf("\\multirow{2}{*}{Tight electrons}& low $p_T$ & %.0f & %.1f & %.1f & %.3f & %.1f & %.1f & %.3f \\\\ \n", h_data_Ele_tight_lowpt->Integral(-1, -1), h_wjets_Ele_tight_lowpt->Integral(-1, -1), h_wjets_Ele_tight_lowpt_weighted->Integral(-1, -1), (h_wjets_Ele_tight_lowpt_weighted->Integral(-1, -1)/h_wjets_Ele_tight_lowpt->Integral(-1, -1)), h_zjets_Ele_tight_lowpt->Integral(-1, -1), h_zjets_Ele_tight_lowpt_weighted->Integral(-1, -1), (h_zjets_Ele_tight_lowpt_weighted->Integral(-1, -1)/h_zjets_Ele_tight_lowpt->Integral(-1, -1)));
  printf("& high $p_T$ &  %.0f & %.1f & %.1f & %.3f & %.1f & %.1f & %.3f \\\\ \n", h_data_Ele_tight_highpt->Integral(-1, -1), h_wjets_Ele_tight_highpt->Integral(-1, -1), h_wjets_Ele_tight_highpt_weighted->Integral(-1, -1), (h_wjets_Ele_tight_highpt_weighted->Integral(-1, -1)/h_wjets_Ele_tight_highpt->Integral(-1, -1)), h_zjets_Ele_tight_highpt->Integral(-1, -1), h_zjets_Ele_tight_highpt_weighted->Integral(-1, -1), (h_zjets_Ele_tight_highpt_weighted->Integral(-1, -1)/h_zjets_Ele_tight_highpt->Integral(-1, -1)));

  printf("\n \n");

}
