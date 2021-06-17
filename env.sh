#!/bin/bash

# If script is run, exit.
[[ $_ == $0 ]] && (echo "Script is being run as executable. Please source script instead." && exit) || printf "\nSetting environment variables:\n\n" 

export WORKSPACE_DIR="$PWD"
export DATASETS_DIR=$WORKSPACE_DIR"/datasets"
export TUTORIALS_DIR=$WORKSPACE_DIR"/tutorials"

export CURRENT_DATASET=$DATASETS_DIR"/MC_Xi_DecFile26265970_Beam6500GeV-2016-MagDown-Nu1.6-25ns-Pythia8.root"


printf "WORKSPACE_DIR\t=\t$WORKSPACE_DIR\n" 
printf "DATASETS_DIR\t=\t$DATASETS_DIR\n" 
printf "TUTORIALS_DIR\t=\t$TUTORIALS_DIR\n" 
printf "CURRENT_DATASET\t=\t$CURRENT_DATASET\n"
