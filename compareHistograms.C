#include <TCanvas.h>
#include <TFile.h>
#include <TH1D.h>
#include <THStack.h>
#include <TString.h>


void DrawHistograms(TString hname);

void SetHistogram  (TH1D*   hist,
		    Color_t color,
		    Style_t fstyle,
		    Style_t mstyle,
		    Width_t lwidth,
		    Int_t   ngroup = 0);

TFile* data_file;
TFile* wjets_file;
TFile* zjets_file;


//------------------------------------------------------------------------------
//
// compareHistograms.C
//
//------------------------------------------------------------------------------
void compareHistograms()
{
  data_file  = new TFile("results/debug/2016_HIPM/cut_Tight80x__mvaFall17V2Iso_WP90_tthmva_70/hadd_data.root",  "read");
  wjets_file = new TFile("results/debug/2016_HIPM/cut_Tight80x__mvaFall17V2Iso_WP90_tthmva_70/hadd_wjets.root", "read");
  zjets_file = new TFile("results/debug/2016_HIPM/cut_Tight80x__mvaFall17V2Iso_WP90_tthmva_70/hadd_zjets.root", "read");

  DrawHistograms("h_Ele_loose_met_35GeV");
  DrawHistograms("h_Ele_tight_met_35GeV");

  DrawHistograms("h_Ele_loose_mtw1_35GeV");
  DrawHistograms("h_Ele_tight_mtw1_35GeV");

  DrawHistograms("h_Muon_loose_met_25GeV");
  DrawHistograms("h_Muon_tight_met_25GeV");

  DrawHistograms("h_Muon_loose_mtw1_25GeV");
  DrawHistograms("h_Muon_tight_mtw1_25GeV");
}


//------------------------------------------------------------------------------
// DrawHistograms
//------------------------------------------------------------------------------
void DrawHistograms(TString hname)
{
  TH1D* data_hist  = (TH1D*)data_file ->Get("FR/02_Debug/" + hname);
  TH1D* wjets_hist = (TH1D*)wjets_file->Get("FR/02_Debug/" + hname);
  TH1D* zjets_hist = (TH1D*)zjets_file->Get("FR/02_Debug/" + hname);

  SetHistogram(data_hist,  kBlack,      0, kFullCircle, 1, 4);
  SetHistogram(wjets_hist, kGray+1,  1001, kFullCircle, 1, 4);
  SetHistogram(zjets_hist, kGreen+2, 1001, kFullCircle, 1, 4);

  THStack* mcstack = new THStack("mcstack_" + hname, "mcstack_" + hname);

  mcstack->Add(wjets_hist);
  mcstack->Add(zjets_hist);

  TCanvas* canvas = new TCanvas("canvas_" + hname, "canvas_" + hname);

  data_hist->Draw("ep");
  mcstack->Draw("hist,same");

  canvas->SaveAs(hname + ".png");
}


//------------------------------------------------------------------------------
// SetHistogram
//------------------------------------------------------------------------------
void SetHistogram(TH1D*   hist,
		  Color_t color,
		  Style_t fstyle,
		  Style_t mstyle,
		  Width_t lwidth,
		  Int_t   ngroup)
{
  hist->SetFillColor(color );
  hist->SetFillStyle(fstyle);

  hist->SetLineColor(color );
  hist->SetLineWidth(lwidth);

  hist->SetMarkerColor(color );
  hist->SetMarkerStyle(mstyle);

  if (ngroup > 0) hist->Rebin(ngroup);
}
