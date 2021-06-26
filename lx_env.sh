#!/bin/bash

# If script is run, exit.
[[ $_ == $0 ]] && (echo "Script is being run as executable. Please source script instead." && exit) || printf "\nSetting environment variables:\n\n" 

export WORKSPACE_DIR="$PWD"
export DATASETS_DIR="/eos/lhcb/user/f/feoliva/public"
export TUTORIALS_DIR=$WORKSPACE_DIR"/tutorials"
export CURRENT_SIG_DATASET=$DATASETS_DIR"/MC_production_XicStSt+/MC_Xi_DecFile26265970_Beam6500GeV-2016-MagDown-Nu1.6-25ns-Pythia8.root"
export CURRENT_BKG_DATASET=$DATASETS_DIR"/Data_1000files2016_WSfixed.root"


printf "WORKSPACE_DIR\t\t=\t$WORKSPACE_DIR\n" 
printf "DATASETS_DIR\t\t=\t$DATASETS_DIR\n" 
printf "TUTORIALS_DIR\t\t=\t$TUTORIALS_DIR\n" 
printf "CURRENT_SIG_DATASET\t=\t$CURRENT_SIG_DATASET\n"
printf "CURRENT_BKG_DATASET\t=\t$CURRENT_BKG_DATASET\n"
