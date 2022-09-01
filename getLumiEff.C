Bool_t highpt = true;

TFile* data;
TFile* zjets;
TFile* wjets;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// root -l -b -q 'getLumiEff.C("2016_HIPM")'
// root -l -b -q 'getLumiEff.C("2016_noHIPM")'
// root -l -b -q 'getLumiEff.C("2017")'
// root -l -b -q 'getLumiEff.C("2018")'
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void getLumiEff(TString year = "2016_HIPM")
{
  if (year.Contains("2016"))
    {
      data  = new TFile("results/" + year + "/cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90/hadd_data.root",  "read");
      zjets = new TFile("results/" + year + "/cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90/hadd_zjets.root", "read");
      wjets = new TFile("results/" + year + "/cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90/hadd_wjets.root", "read");
    }
  else
    {
      data  = new TFile("results/" + year + "/cut_Tight_HWWW_tthmva_80__mvaFall17V2Iso_WP90/hadd_data.root",  "read");
      zjets = new TFile("results/" + year + "/cut_Tight_HWWW_tthmva_80__mvaFall17V2Iso_WP90/hadd_zjets.root", "read");
      wjets = new TFile("results/" + year + "/cut_Tight_HWWW_tthmva_80__mvaFall17V2Iso_WP90/hadd_wjets.root", "read");
    }


  // Get pt vs. m2l histograms
  //----------------------------------------------------------------------------
  TH2D* h2_Ele_loose_pt_m2l_ZRegion_data = (TH2D*)data->Get("FR/01_Zpeak/h_Ele_loose_pt_m2l_35GeV");
  TH2D* h2_Ele_tight_pt_m2l_ZRegion_data = (TH2D*)data->Get("FR/01_Zpeak/h_Ele_tight_pt_m2l_35GeV");
  TH2D* h2_Muo_loose_pt_m2l_ZRegion_data = (TH2D*)data->Get("FR/01_Zpeak/h_Muon_loose_pt_m2l_25GeV");
  TH2D* h2_Muo_tight_pt_m2l_ZRegion_data = (TH2D*)data->Get("FR/01_Zpeak/h_Muon_tight_pt_m2l_25GeV");

  TH2D* h2_Ele_loose_pt_m2l_ZRegion_zjets = (TH2D*)zjets->Get("FR/01_Zpeak/h_Ele_loose_pt_m2l_35GeV");
  TH2D* h2_Ele_tight_pt_m2l_ZRegion_zjets = (TH2D*)zjets->Get("FR/01_Zpeak/h_Ele_tight_pt_m2l_35GeV");
  TH2D* h2_Muo_loose_pt_m2l_ZRegion_zjets = (TH2D*)zjets->Get("FR/01_Zpeak/h_Muon_loose_pt_m2l_25GeV");
  TH2D* h2_Muo_tight_pt_m2l_ZRegion_zjets = (TH2D*)zjets->Get("FR/01_Zpeak/h_Muon_tight_pt_m2l_25GeV");

  TH2D* h2_Ele_loose_pt_m2l_ZRegion_wjets = (TH2D*)wjets->Get("FR/01_Zpeak/h_Ele_loose_pt_m2l_35GeV");
  TH2D* h2_Ele_tight_pt_m2l_ZRegion_wjets = (TH2D*)wjets->Get("FR/01_Zpeak/h_Ele_tight_pt_m2l_35GeV");
  TH2D* h2_Muo_loose_pt_m2l_ZRegion_wjets = (TH2D*)wjets->Get("FR/01_Zpeak/h_Muon_loose_pt_m2l_25GeV");
  TH2D* h2_Muo_tight_pt_m2l_ZRegion_wjets = (TH2D*)wjets->Get("FR/01_Zpeak/h_Muon_tight_pt_m2l_25GeV");


  // Get the dilepton invariant mass
  //----------------------------------------------------------------------------
  Int_t bin_ele_ptmin = -1;
  Int_t bin_muo_ptmin = -1;

  Int_t bin_ele_ptmax = -1;
  Int_t bin_muo_ptmax = -1;

  if (highpt)
    {
      bin_ele_ptmin = h2_Ele_tight_pt_m2l_ZRegion_data->ProjectionY()->FindBin(25.);
      bin_muo_ptmin = h2_Muo_tight_pt_m2l_ZRegion_data->ProjectionY()->FindBin(20.);
    }
  else
    {
      bin_ele_ptmax = h2_Ele_tight_pt_m2l_ZRegion_data->ProjectionY()->FindBin(25.) - 1;
      bin_muo_ptmax = h2_Muo_tight_pt_m2l_ZRegion_data->ProjectionY()->FindBin(20.) - 1;
    }  

  TH1D* h_Ele_loose_m2l_ZRegion_data = (TH1D*)h2_Ele_loose_pt_m2l_ZRegion_data->ProjectionX("Ele loose m2l data", bin_ele_ptmin, bin_ele_ptmax);
  TH1D* h_Ele_tight_m2l_ZRegion_data = (TH1D*)h2_Ele_tight_pt_m2l_ZRegion_data->ProjectionX("Ele tight m2l data", bin_ele_ptmin, bin_ele_ptmax);
  TH1D* h_Muo_loose_m2l_ZRegion_data = (TH1D*)h2_Muo_loose_pt_m2l_ZRegion_data->ProjectionX("Muo loose m2l data", bin_muo_ptmin, bin_muo_ptmax);
  TH1D* h_Muo_tight_m2l_ZRegion_data = (TH1D*)h2_Muo_tight_pt_m2l_ZRegion_data->ProjectionX("Muo tight m2l data", bin_muo_ptmin, bin_muo_ptmax);

  TH1D* h_Ele_loose_m2l_ZRegion_zjets = (TH1D*)h2_Ele_loose_pt_m2l_ZRegion_zjets->ProjectionX("Ele loose m2l zjets", bin_ele_ptmin, bin_ele_ptmax);
  TH1D* h_Ele_tight_m2l_ZRegion_zjets = (TH1D*)h2_Ele_tight_pt_m2l_ZRegion_zjets->ProjectionX("Ele tight m2l zjets", bin_ele_ptmin, bin_ele_ptmax);
  TH1D* h_Muo_loose_m2l_ZRegion_zjets = (TH1D*)h2_Muo_loose_pt_m2l_ZRegion_zjets->ProjectionX("Muo loose m2l zjets", bin_muo_ptmin, bin_muo_ptmax);
  TH1D* h_Muo_tight_m2l_ZRegion_zjets = (TH1D*)h2_Muo_tight_pt_m2l_ZRegion_zjets->ProjectionX("Muo tight m2l zjets", bin_muo_ptmin, bin_muo_ptmax);

  TH1D* h_Ele_loose_m2l_ZRegion_wjets = (TH1D*)h2_Ele_loose_pt_m2l_ZRegion_wjets->ProjectionX("Ele loose m2l wjets", bin_ele_ptmin, bin_ele_ptmax);
  TH1D* h_Ele_tight_m2l_ZRegion_wjets = (TH1D*)h2_Ele_tight_pt_m2l_ZRegion_wjets->ProjectionX("Ele tight m2l wjets", bin_ele_ptmin, bin_ele_ptmax);
  TH1D* h_Muo_loose_m2l_ZRegion_wjets = (TH1D*)h2_Muo_loose_pt_m2l_ZRegion_wjets->ProjectionX("Muo loose m2l wjets", bin_muo_ptmin, bin_muo_ptmax);
  TH1D* h_Muo_tight_m2l_ZRegion_wjets = (TH1D*)h2_Muo_tight_pt_m2l_ZRegion_wjets->ProjectionX("Muo tight m2l wjets", bin_muo_ptmin, bin_muo_ptmax);


  // Get the Z-peak yields
  //----------------------------------------------------------------------------
  Int_t bin_zmin = h_Ele_loose_m2l_ZRegion_data->FindBin(76.);
  Int_t bin_zmax = h_Ele_loose_m2l_ZRegion_data->FindBin(106.);

  Float_t ele_loose_data = h_Ele_loose_m2l_ZRegion_data->Integral(bin_zmin, bin_zmax);
  Float_t ele_tight_data = h_Ele_tight_m2l_ZRegion_data->Integral(bin_zmin, bin_zmax);
  Float_t muo_loose_data = h_Muo_loose_m2l_ZRegion_data->Integral(bin_zmin, bin_zmax);
  Float_t muo_tight_data = h_Muo_tight_m2l_ZRegion_data->Integral(bin_zmin, bin_zmax);
  
  Float_t ele_loose_zjets = h_Ele_loose_m2l_ZRegion_zjets->Integral(bin_zmin, bin_zmax);
  Float_t ele_tight_zjets = h_Ele_tight_m2l_ZRegion_zjets->Integral(bin_zmin, bin_zmax);
  Float_t muo_loose_zjets = h_Muo_loose_m2l_ZRegion_zjets->Integral(bin_zmin, bin_zmax);
  Float_t muo_tight_zjets = h_Muo_tight_m2l_ZRegion_zjets->Integral(bin_zmin, bin_zmax);

  Float_t ele_loose_wjets = max(0., h_Ele_loose_m2l_ZRegion_wjets->Integral(bin_zmin, bin_zmax));
  Float_t ele_tight_wjets = max(0., h_Ele_tight_m2l_ZRegion_wjets->Integral(bin_zmin, bin_zmax));
  Float_t muo_loose_wjets = max(0., h_Muo_loose_m2l_ZRegion_wjets->Integral(bin_zmin, bin_zmax));
  Float_t muo_tight_wjets = max(0., h_Muo_tight_m2l_ZRegion_wjets->Integral(bin_zmin, bin_zmax));


  // Print the results
  //----------------------------------------------------------------------------
  Float_t ele_loose_ratio = ele_loose_data / (ele_loose_zjets + ele_loose_wjets);
  Float_t ele_tight_ratio = ele_tight_data / (ele_tight_zjets + ele_tight_wjets);
  Float_t muo_loose_ratio = muo_loose_data / (muo_loose_zjets + muo_loose_wjets);
  Float_t muo_tight_ratio = muo_loose_data / (muo_tight_zjets + muo_tight_wjets);

  printf("\n");
  printf(" %-11s      |  data  Z+jets  W+jets  | data/MC\n", year.Data());
  printf("------------------+------------------------+---------\n");
  printf(" Loose electrons  | %5.0f   %5.0f   %5.0f  |   %.2f\n", ele_loose_data, ele_loose_zjets, ele_loose_wjets, ele_loose_ratio);
  printf(" Loose muons      | %5.0f   %5.0f   %5.0f  |   %.2f\n", muo_loose_data, muo_loose_zjets, muo_loose_wjets, muo_loose_ratio);
  printf("------------------+------------------------+---------\n");
  printf(" Tight electrons  | %5.0f   %5.0f   %5.0f  |   %.2f\n", ele_tight_data, ele_tight_zjets, ele_tight_wjets, ele_tight_ratio);
  printf(" Tight muons      | %5.0f   %5.0f   %5.0f  |   %.2f\n", muo_tight_data, muo_tight_zjets, muo_tight_wjets, muo_tight_ratio);
  printf("\n");
}
