#!/bin/bash

# If script is run, exit.
[[ $_ == $0 ]] && (echo "Script is being run as executable. Please source script instead." && exit) || printf "\nSetting environment variables:\n\n" 

# Get Project's directories
export WORKSPACE_DIR="$PWD"
export DATASETS_DIR=$WORKSPACE_DIR"/datasets"

# Set current datasets (MonteCarlo and Data)
export CURRENT_SIG_DATASET=$DATASETS_DIR"/DATA_2016_RS_LcCut.root"
export CURRENT_MC_DATASET=$DATASETS_DIR"/LcKPiMC_allVars_mID.root"
export CURRENT_WS1_DATASET=$DATASETS_DIR"/Data_WS1_LcCut.root"
export CURRENT_WS2_DATASET=$DATASETS_DIR"/Data_WS2_LcCut.root"

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
