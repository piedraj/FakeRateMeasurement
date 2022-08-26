#!/bin/bash

# 2016_HIPM
root -l -b -q 'getFakeRate.C("2016_HIPM","cut_Tight80x__mvaFall17V2Iso_WP90_tthmva_70")'
root -l -b -q 'getFakeRate.C("2016_HIPM","cut_Tight80x__mvaFall17V2Iso_WP90_SS")'
root -l -b -q 'getFakeRate.C("2016_HIPM","cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90")'
root -l -b -q 'getFakeRate.C("2016_HIPM","cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90_SS_tthmva_70")'

# 2016_noHIPM
root -l -b -q 'getFakeRate.C("2016_noHIPM","cut_Tight80x__mvaFall17V2Iso_WP90_tthmva_70")'
root -l -b -q 'getFakeRate.C("2016_noHIPM","cut_Tight80x__mvaFall17V2Iso_WP90_SS")'
root -l -b -q 'getFakeRate.C("2016_noHIPM","cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90")'
root -l -b -q 'getFakeRate.C("2016_noHIPM","cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90_SS_tthmva_70")'

# 2017
root -l -b -q 'getFakeRate.C("2017","cut_Tight_HWWW__mvaFall17V2Iso_WP90_tthmva_70")'
root -l -b -q 'getFakeRate.C("2017","cut_Tight_HWWW__mvaFall17V2Iso_WP90_SS")'
root -l -b -q 'getFakeRate.C("2017","cut_Tight_HWWW_tthmva_80__mvaFall17V2Iso_WP90")'
root -l -b -q 'getFakeRate.C("2017","cut_Tight_HWWW_tthmva_80__mvaFall17V2Iso_WP90_SS_tthmva_70")'

# 2018
root -l -b -q 'getFakeRate.C("2018","cut_Tight_HWWW__mvaFall17V2Iso_WP90_tthmva_70")'
root -l -b -q 'getFakeRate.C("2018","cut_Tight_HWWW__mvaFall17V2Iso_WP90_SS")'
root -l -b -q 'getFakeRate.C("2018","cut_Tight_HWWW_tthmva_80__mvaFall17V2Iso_WP90")'
root -l -b -q 'getFakeRate.C("2018","cut_Tight_HWWW_tthmva_80__mvaFall17V2Iso_WP90_SS_tthmva_70")'

