#!/bin/bash

# If script is run, exit.
[[ $_ == $0 ]] && (echo "Script is being run as executable. Please source script instead." && exit) || printf "\nSetting environment variables:\n\n" 

# Get Project's directories
export WORKSPACE_DIR="$PWD"
export DATASETS_DIR="/eos/lhcb/user/f/feoliva/public"

# Set current datasets (MonteCarlo and Data)
export CURRENT_SIG_DATASET=$DATASETS_DIR"/Data_2016_RS_LcMVA.root"
export CURRENT_MC_DATASET=$DATASETS_DIR"/MC_2016_LcMVA.root"
export CURRENT_WS1_DATASET=$DATASETS_DIR"/Data_2016_MD_WS1_LcMVA_LcPiCuts.root"
export CURRENT_WS2_DATASET=$DATASETS_DIR"/Data_2016_MD_WS2_LcMVA_LcPiCuts.root"


# Set CMake prefix path for installing libraries for project
export CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH":"$WORKSPACE_DIR

# Set Database (Database of searches, features, and TMVA runs) location and filename
export DATABASE_DIR=$WORKSPACE_DIR"/database"
export DATABASE=$DATABASE_DIR"/searches.db"

# If Database is not found, initialise it
if [[ ! -f $DATABASE ]]; then
        CURRENT_DIR=$PWD
        cd $DATABASE_DIR
        source $DATABASE_DIR"/init_db.sh"
        cd $CURRENT_DIR
fi


# Print output
printf "WORKSPACE_DIR\t\t=\t$WORKSPACE_DIR\n"

printf "DATASETS_DIR\t\t=\t$DATASETS_DIR\n"

printf "CURRENT_MC_DATASET\t=\t$CURRENT_MC_DATASET\n"
printf "CURRENT_WS1_DATASET\t=\t$CURRENT_WS1_DATASET\n"
printf "CURRENT_WS2_DATASET\t=\t$CURRENT_WS2_DATASET\n"
printf "CURRENT_SIG_DATASET\t=\t$CURRENT_SIG_DATASET\n"
echo

source /cvmfs/sft.cern.ch/lcg/views/setupViews.sh LCG_100_LHCB_6 x86_64-centos7-gcc9-opt
