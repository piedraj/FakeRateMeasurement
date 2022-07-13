#include <TCanvas.h>
#include <TChain.h>
#include <TString.h>


//------------------------------------------------------------------------------
//
// Simple macro that draws the weight applied on W+jets MC events, both for
// electrons (pdgId = 11) and muons (pdgId = 13). A rough fake selection has
// been applied.
//
//------------------------------------------------------------------------------
void debugWeights()
{
  // Read
  //----------------------------------------------------------------------------
  TChain* chain = new TChain("Events");

  TString filename2017 = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer20UL17_106x_nAODv9_Full2017v9/MCl1loose2017v9__fakeSelKinMC/nanoLatino_WJetsToLNu-LO__part";

  TString filename2018 = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer20UL18_106x_nAODv9_Full2018v9/MCl1loose2018v9__fakeSelKinMC/nanoLatino_WJetsToLNu-LO__part";

//for (int i=1; i<81; i++) chain->Add(Form("%s%d.root", filename2017.Data(), i));
  for (int i=1; i<94; i++) chain->Add(Form("%s%d.root", filename2018.Data(), i));


  // Draw
  //----------------------------------------------------------------------------
  TCanvas* c1 = new TCanvas("c1", "c1");

  c1->SetLogy();

//chain->Draw("baseW*Generator_weight*puWeight/1e3","(abs(Lepton_pdgId[0]) == 11) && (Lepton_pt[0] > 25.) && (fabs(Lepton_eta[0]) < 2.5) && (mtw1 < 20.) && (PuppiMET_pt < 20.) && (HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 > 0.5)");
  chain->Draw("baseW*Generator_weight*puWeight/1e3","(abs(Lepton_pdgId[0]) == 13) && (Lepton_pt[0] > 20.) && (fabs(Lepton_eta[0]) < 2.4) && (mtw1 < 20.) && (PuppiMET_pt < 20.) && (HLT_Mu17_TrkIsoVVL > 0.5)");

  c1->SaveAs("fast.png");
}
