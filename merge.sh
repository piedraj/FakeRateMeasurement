#!/bin/bash

if [ $# -lt 2 ] ; then
    echo "  "
    echo "  ./merge.sh  <year>       <leptonid>"
    echo "  ./merge.sh  2016_HIPM    cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90_SS_tthmva_70"
    echo "  ./merge.sh  2016_noHIPM  cut_Tight80x_tthmva_80__mvaFall17V2Iso_WP90_SS_tthmva_70"
    echo "  ./merge.sh  2016_HIPM    cut_Tight80x__mvaFall17V2Iso_WP90_SS"
    echo "  ./merge.sh  2016_noHIPM  cut_Tight80x__mvaFall17V2Iso_WP90_SS"
    echo "  "
    exit -1
fi

YEAR="$1"
LEPTONID="$2"


pushd results

hadd -f -k hadd_wjets.root nanoLatino_WJetsToLNu*.root
hadd -f -k hadd_zjets.root nanoLatino_DYJetsToLL*.root
hadd -f -k hadd_data.root  nanoLatino_*_Run201*.root

mkdir -p $YEAR/$LEPTONID

mv hadd* $YEAR/$LEPTONID/.

rm nanoLatino*

popd

rm -rf jobs

rm piedra.cc


