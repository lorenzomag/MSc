#!/bin/bash

# If script is run, exit.
[[ $_ == $0 ]] && (echo "Script is being run as executable. Please source script instead." && exit) || printf "\nSetting environment variables:\n\n" 

export WORKSPACE_DIR="$PWD"
export DATASETS_DIR="/eos/lhcb/user/f/feoliva/public"
export TUTORIALS_DIR=$WORKSPACE_DIR"/tutorials"
export CURRENT_SIG_DATASET=$DATASETS_DIR"/MC_Xi_DecFile26265970_CutLcMVAresponse_TruthMatched.root"
export CURRENT_BKG_DATASET=$DATASETS_DIR"/Data_Xic_WS1_addMVAresponse.root"


printf "WORKSPACE_DIR\t\t=\t$WORKSPACE_DIR\n" 
printf "DATASETS_DIR\t\t=\t$DATASETS_DIR\n" 
printf "TUTORIALS_DIR\t\t=\t$TUTORIALS_DIR\n" 
printf "CURRENT_SIG_DATASET\t=\t$CURRENT_SIG_DATASET\n"
printf "CURRENT_BKG_DATASET\t=\t$CURRENT_BKG_DATASET\n"

lsetup "views LCG_100_LHCB_6 x86_64-centos7-gcc9-opt"
