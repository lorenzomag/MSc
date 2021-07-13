#!/bin/bash

# If script is run, exit.
[[ $_ == $0 ]] && (echo "Script is being run as executable. Please source script instead." && exit) || printf "\nSetting environment variables:\n\n" 

export WORKSPACE_DIR="$PWD"
export DATASETS_DIR=$WORKSPACE_DIR"/datasets"
export TUTORIALS_DIR=$WORKSPACE_DIR"/tutorials"
export VCPKG_ROOT=$WORKSPACE_DIR"/vcpkg"
#export CURRENT_SIG_DATASET=$DATASETS_DIR"/mcsampletruth_allMasses_LcCutTruthMatched.root"
export CURRENT_BKG_DATASET=$DATASETS_DIR"/Data_Xic_WS1_addMVAresponse.root"
export CURRENT_SIG_DATASET=$DATASETS_DIR"/mcsampletruthDecFile26265973_LcCutTruthMatched.root"


printf "WORKSPACE_DIR\t\t=\t$WORKSPACE_DIR\n" 
printf "DATASETS_DIR\t\t=\t$DATASETS_DIR\n" 
printf "TUTORIALS_DIR\t\t=\t$TUTORIALS_DIR\n" 
printf "CURRENT_SIG_DATASET\t=\t$CURRENT_SIG_DATASET\n"
printf "CURRENT_BKG_DATASET\t=\t$CURRENT_BKG_DATASET\n"
