Estimation of the luminosities necessary to compute the fake rates.

# Reference links

[Current recommendations for luminosity estimations](https://twiki.cern.ch/twiki/bin/view/CMS/TWikiLUM#CurRec) from the Luminosity Physics Object Group.

    https://twiki.cern.ch/twiki/bin/view/CMS/TWikiLUM#CurRec

Run ranges used in the (UL) [latino production](https://github.com/latinos/LatinoAnalysis/blob/UL_production/NanoGardener/python/framework/Productions_cfg.py#L632) from the golden JSON files.

    https://github.com/latinos/LatinoAnalysis/blob/UL_production/NanoGardener/python/framework/Productions_cfg.py#L632

Trigger bits and [luminosity](https://github.com/latinos/LatinoAnalysis/blob/UL_production/NanoGardener/python/data/TrigMaker_cfg.py).

    https://github.com/latinos/LatinoAnalysis/blob/UL_production/NanoGardener/python/data/TrigMaker_cfg.py

# Run 2

    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /fb -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/Legacy_2018/Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON.txt
    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /fb -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/Legacy_2017/Cert_294927-306462_13TeV_UL2017_Collisions17_GoldenJSON.txt
    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /fb -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Legacy_2016/Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON.txt

# 2016_HIPM

    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /pb -i Cert_271036-284044_13TeV_Legacy2016_HIPM_Collisions16_JSON.txt --hltpath "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v*"
    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /pb -i Cert_271036-284044_13TeV_Legacy2016_HIPM_Collisions16_JSON.txt --hltpath "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v*"
    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /pb -i Cert_271036-284044_13TeV_Legacy2016_HIPM_Collisions16_JSON.txt --hltpath "HLT_Mu8_TrkIsoVVL_v*"
    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /pb -i Cert_271036-284044_13TeV_Legacy2016_HIPM_Collisions16_JSON.txt --hltpath "HLT_Mu17_TrkIsoVVL_v*"

| Trigger                                  | Luminosity [1/pb] |
| :---                                     |              ---: |
| HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 |            11.028 |
| HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 |            52.768 |
| HLT_Mu8_TrkIsoVVL                        |             6.584 |
| HLT_Mu17_TrkIsoVVL                       |           192.064 |

# 2016_noHIPM

    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /pb -i Cert_271036-284044_13TeV_Legacy2016_noHIPM_Collisions16_JSON.txt --hltpath "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v*"
    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /pb -i Cert_271036-284044_13TeV_Legacy2016_noHIPM_Collisions16_JSON.txt --hltpath "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v*"
    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /pb -i Cert_271036-284044_13TeV_Legacy2016_noHIPM_Collisions16_JSON.txt --hltpath "HLT_Mu8_TrkIsoVVL_v*"
    brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_PHYSICS.json -u /pb -i Cert_271036-284044_13TeV_Legacy2016_noHIPM_Collisions16_JSON.txt --hltpath "HLT_Mu17_TrkIsoVVL_v*"

| Trigger                                  | Luminosity [1/pb] |
| :---                                     |              ---: |
| HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 |             3.980 |
| HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 |            10.699 |
| HLT_Mu8_TrkIsoVVL                        |             1.297 |
| HLT_Mu17_TrkIsoVVL                       |            26.873 |
