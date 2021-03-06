// Constants
//------------------------------------------------------------------------------
const Int_t   njetet = 7;

const Float_t muojetarray[njetet] = {10, 15, 20, 25, 30, 35, 45};
const Float_t elejetarray[njetet] = {10, 15, 20, 25, 30, 35, 45};
const Float_t colors     [njetet] = {kRed, kRed+1, kRed+2, kRed+3, kRed+4, kRed+5, kRed+6};

const Float_t muoscale = -1.;
const Float_t elescale = -1.;

const Float_t year_lumi[3] = {36.3, 41.5, 59.7};


// Data members
//------------------------------------------------------------------------------
bool    setgrid      = true;
bool    Wsubtraction = true;
bool    Zsubtraction = true;

TFile*  dataFR;
TFile*  wjetsFR;
TFile*  zjetsFR;
TFile*  zjetsPR;

Int_t   year;

TString inputdir;
TString outputdir;
TString pngdir;
TString btagDirectory = "";


// Functions
//------------------------------------------------------------------------------
void     Cosmetics   (TH1D*       hist,
		      Option_t*   option,
		      TString     xtitle,
		      TString     ytitle,
		      Color_t     color,
		      Float_t     ymin = 0.0,
		      Float_t     ymax = 1.0);

void     DrawAllJetEt(TString     flavour,
		      TString     variable,
		      TString     xtitle,
		      Float_t     lepscale);

void     DrawFR      (TString     flavour,
		      TString     variable,
		      TString     xtitle,
		      Float_t     lepscale,
		      Float_t     jetet);

void     DrawPR      (TString     flavour,
		      TString     variable,
		      TString     xtitle);

void     WriteFR     (TString     flavour,
		      Float_t     lepscale,
		      Float_t     jetet);

void     WritePR     (TString     flavour);

void     DrawLatex   (Font_t      tfont,
		      Float_t     x,
		      Float_t     y,
		      Float_t     tsize,
		      Short_t     align,
		      const char* text,
		      Bool_t      setndc = true);

TLegend* DrawLegend  (Float_t     x1,
		      Float_t     y1,
		      TH1*        hist,
		      TString     label,
		      TString     option  = "p",
		      Float_t     tsize   = 0.035,
		      Float_t     xoffset = 0.184,
		      Float_t     yoffset = 0.043);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// root -l -b -q getFakeRate.C\(2017,-1,-1\)
// root -l -b -q getFakeRate.C\(2018,-1,-1\)
//
// root -l -b -q getFakeRate.C\(2017,35,25\)
// root -l -b -q getFakeRate.C\(2018,35,25\)
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void getFakeRate(Int_t   the_year     = 2017,
		 Float_t the_elejetet = 35,
		 Float_t the_muojetet = 25)
{
  year = the_year;

  inputdir  = Form("results/%d",  year);
  outputdir = Form("fakerate/%d", year);
  pngdir    = Form("png/%d",      year);

  gInterpreter->ExecuteMacro("PaperStyle.C");

  gSystem->mkdir(pngdir, kTRUE);

  gSystem->mkdir(outputdir, kTRUE);

  dataFR  = new TFile (inputdir + "/hadd_data.root",  "read");
  wjetsFR = new TFile (inputdir + "/hadd_wjets.root", "read");
  zjetsFR = new TFile (inputdir + "/hadd_zjets.root", "read");
  zjetsPR = new TFile (inputdir + "/hadd_zjets.root", "read");


  // Prompt rate
  //----------------------------------------------------------------------------
  WritePR("Ele");
  WritePR("Muon");

  DrawPR("Ele",  "pt",  "p_{T} [GeV]");
  DrawPR("Muon", "pt",  "p_{T} [GeV]");
  DrawPR("Ele",  "eta", "|#eta|");
  DrawPR("Muon", "eta", "|#eta|");


  // Electron fake rate
  //----------------------------------------------------------------------------
  if (the_elejetet > 0) {

    WriteFR("Ele", elescale, the_elejetet);

    DrawFR("Ele", "pt",  "p_{T} [GeV]", elescale, the_elejetet);
    DrawFR("Ele", "eta", "|#eta|",      elescale, the_elejetet);
  }
  else {
    for (Int_t i=0; i<njetet; i++) {

      WriteFR("Ele", elescale, elejetarray[i]);

      DrawFR("Ele", "pt",  "p_{T} [GeV]", elescale, elejetarray[i]);
      DrawFR("Ele", "eta", "|#eta|",      elescale, elejetarray[i]);
    }
  }


  // Muon fake rate
  //----------------------------------------------------------------------------
  if (the_muojetet > 0) {

    WriteFR("Muon", muoscale, the_muojetet);

    DrawFR("Muon", "pt",  "p_{T} [GeV]", muoscale, the_muojetet);
    DrawFR("Muon", "eta", "|#eta|",      muoscale, the_muojetet);
  }
  else {
    for (Int_t i=0; i<njetet; i++) {

      WriteFR("Muon", muoscale, muojetarray[i]);
      
      DrawFR("Muon", "pt",  "p_{T} [GeV]", muoscale, muojetarray[i]);
      DrawFR("Muon", "eta", "|#eta|",      muoscale, muojetarray[i]);
    }
  }


  // Draw all fake rates together
  //----------------------------------------------------------------------------
  if (the_elejetet < 0 && the_muojetet < 0) {
  
    DrawAllJetEt("Ele",  "pt",  "p_{T} [GeV]", elescale);
    DrawAllJetEt("Muon", "pt",  "p_{T} [GeV]", muoscale);
    DrawAllJetEt("Ele",  "eta", "|#eta|",      elescale);
    DrawAllJetEt("Muon", "eta", "|#eta|",      muoscale);
  }
}


//------------------------------------------------------------------------------
// DrawAllJetEt
//------------------------------------------------------------------------------
void DrawAllJetEt(TString flavour,
		  TString variable,
		  TString xtitle,
		  Float_t lepscale)
{
  Float_t jetet;

  TString title1 = Form("%s fake rate considering various jet p_{T}", flavour.Data());    

  TCanvas* canvas1 = new TCanvas(title1 + " " + variable, title1 + " " + variable);
  
  canvas1->SetGridx(setgrid);
  canvas1->SetGridy(setgrid);
  canvas1->cd();

  for (Int_t i=0; i<njetet; i++) {

    jetet = (flavour == "Ele") ? elejetarray[i] : muojetarray[i];

    TString suffix = Form("%s_bin_%.0fGeV", variable.Data(), jetet);


    // Read loose and tight histograms
    //--------------------------------------------------------------------------
    TH1D* h_loose_data  = (TH1D*)dataFR ->Get(btagDirectory + "FR/00_QCD/h_" + flavour + "_loose_" + suffix);
    TH1D* h_loose_zjets = (TH1D*)zjetsFR->Get(btagDirectory + "FR/00_QCD/h_" + flavour + "_loose_" + suffix);
    TH1D* h_loose_wjets = (TH1D*)wjetsFR->Get(btagDirectory + "FR/00_QCD/h_" + flavour + "_loose_" + suffix);
    TH1D* h_tight_data  = (TH1D*)dataFR ->Get(btagDirectory + "FR/00_QCD/h_" + flavour + "_tight_" + suffix);
    TH1D* h_tight_zjets = (TH1D*)zjetsFR->Get(btagDirectory + "FR/00_QCD/h_" + flavour + "_tight_" + suffix);
    TH1D* h_tight_wjets = (TH1D*)wjetsFR->Get(btagDirectory + "FR/00_QCD/h_" + flavour + "_tight_" + suffix);


    // Prepare fake rate histograms
    //--------------------------------------------------------------------------
    TH1D* h_FR_EWK             = (TH1D*)h_tight_data->Clone("h_" + flavour + "_FR_EWK_"             + variable);
    TH1D* h_FR_EWK_denominator = (TH1D*)h_loose_data->Clone("h_" + flavour + "_FR_EWK_denominator_" + variable);


    // Do the math
    //--------------------------------------------------------------------------
    if (Zsubtraction) h_FR_EWK->Add(h_tight_zjets, lepscale);
    if (Wsubtraction) h_FR_EWK->Add(h_tight_wjets, lepscale);
    
    if (Zsubtraction) h_FR_EWK_denominator->Add(h_loose_zjets, lepscale);
    if (Wsubtraction) h_FR_EWK_denominator->Add(h_loose_wjets, lepscale);
    
    h_FR_EWK->Divide(h_FR_EWK_denominator);

    Cosmetics(h_FR_EWK, "ep,same", xtitle, title1, colors[i]);

    DrawLegend(0.22, 0.58+(0.042*i), h_FR_EWK, Form("%.0f GeV threshold", jetet));
  }


  // Save
  //----------------------------------------------------------------------------
  canvas1->SaveAs(Form("%s/%s_FR_%s_combined.png",
		       pngdir.Data(),
		       flavour.Data(),
		       variable.Data()));
}


//------------------------------------------------------------------------------
// DrawFR
//------------------------------------------------------------------------------
void DrawFR(TString flavour,
	    TString variable,
	    TString xtitle,
	    Float_t lepscale,
	    Float_t jetet)
{
  TString suffix = Form("%s_bin_%.0fGeV", variable.Data(), jetet);


  // Read loose and tight histograms
  //----------------------------------------------------------------------------
  TH1D* h_loose_data  = (TH1D*)dataFR ->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix);
  TH1D* h_loose_zjets = (TH1D*)zjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix);
  TH1D* h_loose_wjets = (TH1D*)wjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix);
  TH1D* h_tight_data  = (TH1D*)dataFR ->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix);
  TH1D* h_tight_zjets = (TH1D*)zjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix);
  TH1D* h_tight_wjets = (TH1D*)wjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix);


  // Debug
  //----------------------------------------------------------------------------
  if (variable.EqualTo("pt"))
    {
      TString suffix_raw = Form("%s_bin_raw_%.0fGeV", variable.Data(), jetet);

      TH1D* h_loose_data_raw  = (TH1D*)dataFR ->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix_raw);
      TH1D* h_loose_zjets_raw = (TH1D*)zjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix_raw);
      TH1D* h_loose_wjets_raw = (TH1D*)wjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix_raw);
      TH1D* h_tight_data_raw  = (TH1D*)dataFR ->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix_raw);
      TH1D* h_tight_zjets_raw = (TH1D*)zjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix_raw);
      TH1D* h_tight_wjets_raw = (TH1D*)wjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix_raw);

      printf("\n  %d W+jets %s %s when jet pt > %.0f GeV\n\n",
	     year, flavour.Data(), variable.Data(), jetet);

      printf("  %s bin LOOSE  raw weight | TIGHT   raw weight\n",
	     variable.Data());

      for (Int_t ibin=1; ibin<=h_loose_data->GetNbinsX(); ibin++) {

	printf(" [%.0f,%.0f]      %5.0f  %.3f |       %5.0f  %.3f\n",
	       h_loose_wjets->GetBinLowEdge(ibin),
	       h_loose_wjets->GetBinLowEdge(ibin+1),
	       h_loose_wjets_raw->GetBinContent(ibin),
	       h_loose_wjets->GetBinContent(ibin) / h_loose_wjets_raw->GetBinContent(ibin),
	       h_tight_wjets_raw->GetBinContent(ibin),
	       h_tight_wjets->GetBinContent(ibin) / h_tight_wjets_raw->GetBinContent(ibin));
      }
      
      printf("\n");
    }


  // Make EWK correction histograms
  //----------------------------------------------------------------------------
  TH1D* h_tight_correction = (TH1D*)h_tight_zjets->Clone("h_" + flavour + "_FR_" + variable);
  TH1D* h_loose_correction = (TH1D*)h_loose_zjets->Clone("h_" + flavour + "_FR_" + variable);
  TH1D* h_EWKrel_tight     = (TH1D*)h_tight_data ->Clone("h_" + flavour + "_FR_" + variable);
  TH1D* h_EWKrel_loose     = (TH1D*)h_loose_data ->Clone("h_" + flavour + "_FR_" + variable);
  
  h_tight_correction->Add(h_tight_wjets, 1);  // tight_correction = tight_zjets + tight_wjets
  h_loose_correction->Add(h_loose_wjets, 1);  // loose_correction = loose_zjets + loose_wjets

  h_EWKrel_tight->Divide(h_tight_correction, h_tight_data);  // EWKrel_tight = tight_correction / tight_data
  h_EWKrel_loose->Divide(h_loose_correction, h_loose_data);  // EWKrel_loose = loose_correction / loose_data
 

  // Prepare fake rate histograms
  //----------------------------------------------------------------------------
  TH1D* h_FR                 = (TH1D*)h_tight_data->Clone("h_" + flavour + "_FR_"                 + variable);
  TH1D* h_FR_denominator     = (TH1D*)h_loose_data->Clone("h_" + flavour + "_FR_denominator_"     + variable);
  TH1D* h_FR_EWK             = (TH1D*)h_tight_data->Clone("h_" + flavour + "_FR_EWK_"             + variable);
  TH1D* h_FR_EWK_denominator = (TH1D*)h_loose_data->Clone("h_" + flavour + "_FR_EWK_denominator_" + variable);


  // Do the math
  //----------------------------------------------------------------------------
  h_FR->Divide(h_FR_denominator);

  if (Zsubtraction) h_FR_EWK->Add(h_tight_zjets, lepscale);
  if (Wsubtraction) h_FR_EWK->Add(h_tight_wjets, lepscale);

  if (Zsubtraction) h_FR_EWK_denominator->Add(h_loose_zjets, lepscale);
  if (Wsubtraction) h_FR_EWK_denominator->Add(h_loose_wjets, lepscale);

  h_FR_EWK->Divide(h_FR_EWK_denominator);


  // Draw fake rate
  //----------------------------------------------------------------------------
  TString title1 = Form("%s fake rate when jet p_{T} > %.0f GeV", flavour.Data(), jetet);

  TCanvas* canvas1 = new TCanvas(title1 + " " + variable, title1 + " " +  variable);
      
  canvas1->SetGridx(setgrid);
  canvas1->SetGridy(setgrid);
  
  Cosmetics(h_FR,     "ep",      xtitle, title1, kBlack);
  Cosmetics(h_FR_EWK, "ep,same", xtitle, title1, kRed+1);

  DrawLatex(42, 0.940, 0.945, 0.045, 31, Form("%.1f fb^{-1} (13 TeV)", year_lumi[year-2016]));

  DrawLegend(0.22, 0.845, h_FR,     "Without EWK correction");
  DrawLegend(0.22, 0.800, h_FR_EWK, "With EWK correction");

  canvas1->SaveAs(Form("%s/%s_FR_%s_%.0fGeV.png", pngdir.Data(), flavour.Data(), variable.Data(), jetet));


  // Draw EWK correction
  //----------------------------------------------------------------------------
  TString title2 = Form("%s EWK correction when jet p_{T} > %.0f GeV", flavour.Data(), jetet);

  TCanvas* canvas2 = new TCanvas(title2 + " " + variable, title2 + " " + variable);

  canvas2->SetGridx(setgrid);
  canvas2->SetGridy(setgrid);

  Cosmetics(h_EWKrel_tight, "ep",      xtitle, title2, kBlack);
  Cosmetics(h_EWKrel_loose, "ep,same", xtitle, title2, kRed+1);

  DrawLegend(0.22, 0.845, h_EWKrel_tight, "tight EWK / tight data");
  DrawLegend(0.22, 0.800, h_EWKrel_loose, "loose EWK / loose data");

  DrawLatex(42, 0.940, 0.945, 0.045, 31, Form("%.1f fb^{-1} (13 TeV)", year_lumi[year-2016]));

  canvas2->SaveAs(Form("%s/%s_EWKrel_%s_%.0fGeV.png", pngdir.Data(), flavour.Data(), variable.Data(), jetet));


  // Draw tight histograms
  //----------------------------------------------------------------------------
  TString title3 = Form("%s tight histograms when jet p_{T} > %.0f GeV", flavour.Data(), jetet);

  TCanvas* canvas3 = new TCanvas(title3 + " " + variable, title3 + " " + variable);

  canvas3->SetGridx(setgrid);
  canvas3->SetGridy(setgrid);

  Cosmetics(h_tight_data,  "ep",      xtitle, title3, kBlack, 0, -999);
  Cosmetics(h_tight_zjets, "ep,same", xtitle, title3, kRed+1, 0, -999);
  Cosmetics(h_tight_wjets, "ep,same", xtitle, title3, kBlue,  0, -999);
  
  if (variable.Contains("pt"))
    {
      DrawLegend(0.67, 0.845, h_tight_data,  "tight data");
      DrawLegend(0.67, 0.800, h_tight_zjets, "tight Z+jets");
      DrawLegend(0.67, 0.755, h_tight_wjets, "tight W+jets");
    }

  DrawLatex(42, 0.940, 0.945, 0.045, 31, Form("%.1f fb^{-1} (13 TeV)", year_lumi[year-2016]));

  canvas3->SaveAs(Form("%s/%s_tight-histograms_%s_%.0fGeV.png", pngdir.Data(), flavour.Data(), variable.Data(), jetet));


  // Draw loose histograms
  //----------------------------------------------------------------------------
  TString title4 = Form("%s loose histograms when jet p_{T} > %.0f GeV", flavour.Data(), jetet);

  TCanvas* canvas4 = new TCanvas(title4 + " " + variable, title4 + " " + variable);

  canvas4->SetGridx(setgrid);
  canvas4->SetGridy(setgrid);

  Cosmetics(h_loose_data,  "ep",      xtitle, title4, kBlack, 0, -999);
  Cosmetics(h_loose_zjets, "ep,same", xtitle, title4, kRed+1, 0, -999);
  Cosmetics(h_loose_wjets, "ep,same", xtitle, title4, kBlue,  0, -999);

  if (variable.Contains("pt"))
    {
      DrawLegend(0.67, 0.845, h_loose_data,  "loose data");
      DrawLegend(0.67, 0.800, h_loose_zjets, "loose Z+jets");
      DrawLegend(0.67, 0.755, h_loose_wjets, "loose W+jets");
    }

  DrawLatex(42, 0.940, 0.945, 0.045, 31, Form("%.1f fb^{-1} (13 TeV)", year_lumi[year-2016]));

  canvas4->SaveAs(Form("%s/%s_loose-histograms_%s_%.0fGeV.png", pngdir.Data(), flavour.Data(), variable.Data(), jetet));
}


//------------------------------------------------------------------------------
// DrawPR
//------------------------------------------------------------------------------
void DrawPR(TString flavour,
	    TString variable,
	    TString xtitle)
{
  TH1D* h_loose_zjets = (TH1D*)zjetsPR -> Get("PR/00/h_" + flavour + "_loose_" + variable + "_PR");
  TH1D* h_tight_zjets = (TH1D*)zjetsPR -> Get("PR/00/h_" + flavour + "_tight_" + variable + "_PR");

  TH1D* h_PR = (TH1D*)h_tight_zjets->Clone("h_" + flavour + "_PR_" + variable);
      
  h_PR->Divide(h_tight_zjets, h_loose_zjets);


  // Draw
  //----------------------------------------------------------------------------
  TString title = flavour + " prompt rate";

  TCanvas* canvas = new TCanvas(title + " " + variable, title + " " + variable);
      
  canvas->SetGridx(setgrid);
  canvas->SetGridy(setgrid);

  Cosmetics(h_PR, "ep", xtitle, title, kBlack);


  // Save
  //----------------------------------------------------------------------------
  canvas->SaveAs(Form("%s/%s_PR_%s.png", pngdir.Data(), flavour.Data(), variable.Data()));
}


//------------------------------------------------------------------------------
// WriteFR
//------------------------------------------------------------------------------
void WriteFR(TString flavour,
	     Float_t lepscale,
	     Float_t jetet)
{
  TString suffix = Form("pt_eta_bin_%.0fGeV", jetet);

  
  // Read loose and tight histograms
  //----------------------------------------------------------------------------
  TH2D* h_loose_data  = (TH2D*)dataFR ->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix);
  TH2D* h_loose_zjets = (TH2D*)zjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix);
  TH2D* h_loose_wjets = (TH2D*)wjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_loose_" + suffix);
  TH2D* h_tight_data  = (TH2D*)dataFR ->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix);
  TH2D* h_tight_zjets = (TH2D*)zjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix);
  TH2D* h_tight_wjets = (TH2D*)wjetsFR->Get(btagDirectory+"FR/00_QCD/h_" + flavour + "_tight_" + suffix);


  // Prepare fake rate histograms
  //----------------------------------------------------------------------------
  TH2D* h_FR                 = (TH2D*)h_tight_data->Clone("h_" + flavour + "_FR");
  TH2D* h_FR_numerator       = (TH2D*)h_tight_data->Clone("h_" + flavour + "_FR_numerator");
  TH2D* h_FR_denominator     = (TH2D*)h_loose_data->Clone("h_" + flavour + "_FR_denominator");
  TH2D* h_FR_EWK             = (TH2D*)h_tight_data->Clone("h_" + flavour + "_FR_EWK");
  TH2D* h_FR_EWK_numerator   = (TH2D*)h_tight_data->Clone("h_" + flavour + "_FR_EWK_numerator");
  TH2D* h_FR_EWK_denominator = (TH2D*)h_loose_data->Clone("h_" + flavour + "_FR_EWK_denominator");


  // Do the math
  //----------------------------------------------------------------------------
  h_FR->Divide(h_FR_numerator, h_FR_denominator);

  if (Zsubtraction) h_FR_EWK_numerator->Add(h_tight_zjets, lepscale);
  if (Wsubtraction) h_FR_EWK_numerator->Add(h_tight_wjets, lepscale);

  if (Zsubtraction) h_FR_EWK_denominator->Add(h_loose_zjets, lepscale);
  if (Wsubtraction) h_FR_EWK_denominator->Add(h_loose_wjets, lepscale);

  h_FR_EWK->Divide(h_FR_EWK_numerator, h_FR_EWK_denominator);


  // Write
  //----------------------------------------------------------------------------
  TFile *file = new TFile(Form("%s/%sFR_jet%0.f.root",
			       outputdir.Data(),
			       flavour.Data(),
			       jetet),
			  "recreate");

  h_FR            ->Write("FR_pT_eta");
  h_FR_numerator  ->Write("FR_pT_eta_numerator");
  h_FR_denominator->Write("FR_pT_eta_denominator");

  h_FR_EWK            ->Write("FR_pT_eta_EWKcorr");
  h_FR_EWK_numerator  ->Write("FR_pT_eta_EWKcorr_numerator");
  h_FR_EWK_denominator->Write("FR_pT_eta_EWKcorr_denominator");

  file->Close();
}


//------------------------------------------------------------------------------
// WritePR
//------------------------------------------------------------------------------
void WritePR(TString flavour)
{
  TH2D* h_loose_zjets = (TH2D*)zjetsPR->Get("PR/00/h_" + flavour + "_loose_pt_eta_PR");
  TH2D* h_tight_zjets = (TH2D*)zjetsPR->Get("PR/00/h_" + flavour + "_tight_pt_eta_PR");

  TH2D* h_PR = (TH2D*)h_tight_zjets->Clone("h_" + flavour + "_signal_pt_eta_bin");

  h_PR->Divide(h_tight_zjets, h_loose_zjets);


  // Write
  //----------------------------------------------------------------------------
  TFile* file = new TFile(Form("%s/%sPR.root",
			       outputdir.Data(),
			       flavour.Data()),
			  "recreate");

  h_PR->Write();
  
  file->Close();
}


//------------------------------------------------------------------------------
// DrawLatex
//------------------------------------------------------------------------------
void DrawLatex(Font_t      tfont,
	       Float_t     x,
	       Float_t     y,
	       Float_t     tsize,
	       Short_t     align,
	       const char* text,
	       Bool_t      setndc)
{
  TLatex* tl = new TLatex(x, y, text);

  tl->SetNDC      (setndc);
  tl->SetTextAlign( align);
  tl->SetTextFont ( tfont);
  tl->SetTextSize ( tsize);

  tl->Draw("same");
}


//------------------------------------------------------------------------------
// DrawLegend
//------------------------------------------------------------------------------
TLegend* DrawLegend(Float_t x1,
		    Float_t y1,
		    TH1*    hist,
		    TString label,
		    TString option,
		    Float_t tsize,
		    Float_t xoffset,
		    Float_t yoffset)
{
  TLegend* legend = new TLegend(x1,
				y1,
				x1 + xoffset,
				y1 + yoffset);
  
  legend->SetBorderSize(    0);
  legend->SetFillColor (    0);
  legend->SetTextAlign (   12);
  legend->SetTextFont  (   42);
  legend->SetTextSize  (tsize);

  TString final_label = Form(" %s", label.Data());

  legend->AddEntry(hist, final_label.Data(), option.Data());
  legend->Draw();

  return legend;
}


//------------------------------------------------------------------------------
// Cosmetics
//------------------------------------------------------------------------------
void Cosmetics(TH1D*     hist,
	       Option_t* option,
	       TString   xtitle,
	       TString   ytitle,
	       Color_t   color,
	       Float_t   ymin,
	       Float_t   ymax)
{
  hist->Draw(option);

  hist->SetLineColor  (color);
  hist->SetLineWidth  (2);
  hist->SetMarkerColor(color);
  hist->SetMarkerStyle(kFullCircle);
  hist->SetTitle      ("");
  hist->SetXTitle     (xtitle);
  hist->SetYTitle     (ytitle);

  if (ymin > -999) hist->SetMinimum(ymin);
  if (ymax > -999) hist->SetMaximum(ymax);

  hist->GetXaxis()->SetTitleOffset(1.5);
  hist->GetYaxis()->SetTitleOffset(1.8);
}
