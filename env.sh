#!/bin/bash

# If script is run, exit.
[[ $_ == $0 ]] && (echo "Script is being run as executable. Please source script instead." && exit) || printf "\nSetting environment variables:\n\n" 

# Get Project's directories
export WORKSPACE_DIR="$PWD"
export DATASETS_DIR=$WORKSPACE_DIR"/datasets"
export SMALL_DATASETS_DIR=$WORKSPACE_DIR"/small_datasets"
export LOCAL_DATASETS_DIR=$WORKSPACE_DIR"/local_datasets"

# Set current datasets (MonteCarlo and Data)
export CURRENT_MC_DATASET=$DATASETS_DIR"/MC2016_AllMasses_MUMD_Xic_TMVAClassification_AllEvents_LcCut_PreselCuts_mID.root"
export CURRENT_SIG_DATASET=$CURRENT_MC_DATASET
export CURRENT_WS1_DATASET=$DATASETS_DIR"/WS1_Xic_TMVAClassification_Application_AllEvents_LcCut_PreselCuts.root"
export CURRENT_WS2_DATASET=$DATASETS_DIR"/WS2_2016_Xic_TMVAClassification_Application_AllEvents_LcCut_PreselCuts.root"
export CURRENT_WS3_DATASET=$DATASETS_DIR"/WS1_2016_Xic_TMVAClassification_Application_AllEvents_LcCut_PreselCuts.root" #temporary

export CURRENT_APPLICATION_DATASET=$DATASETS_DIR"/MC_WS2_2016_merged.root"

export SMALL_CURRENT_MC=$SMALL_DATASETS_DIR"/small_MC.root"
export SMALL_CURRENT_WS1=$SMALL_DATASETS_DIR"/small_WS1.root"
export SMALL_CURRENT_WS2=$SMALL_DATASETS_DIR"/small_WS2.root"
export SMALL_CURRENT_WS3=$SMALL_DATASETS_DIR"/small_WS3.root"



# Set CMake prefix path for installing libraries for project
export FETCHCONTENT_BASE_DIR=$WORKSPACE_DIR"/utils/_deps"
export CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH":"$WORKSPACE_DIR
export PATH=$PATH:$WORKSPACE_DIR"/TMVA_phase/bin"

# Set Database (Database of searches, features, and TMVA runs) location and filename 
export DATABASE_DIR=$WORKSPACE_DIR"/database"
export SQL_SCRIPTS=$DATABASE_DIR"/sql_scripts"
export DATABASE=$DATABASE_DIR"/searches.db"

# If Database is not found, initialise it
if [[ ! -f $DATABASE ]]; then
	CURRENT_DIR=$PWD
	cd $DATABASE_DIR
	source $DATABASE_DIR"/init_db.sh"
	cd $CURRENT_DIR
fi

# Print output
printf "WORKSPACE_DIR\t\t\t=\t$WORKSPACE_DIR\n" 
printf "DATASETS_DIR\t\t\t=\t$DATASETS_DIR\n"

printf "CURRENT_MC_DATASET\t\t=\t$CURRENT_MC_DATASET\n"
printf "CURRENT_WS1_DATASET\t\t=\t$CURRENT_WS1_DATASET\n"
printf "CURRENT_WS2_DATASET\t\t=\t$CURRENT_WS2_DATASET\n"
printf "CURRENT_SIG_DATASET\t\t=\t$CURRENT_SIG_DATASET\n"
printf "CURRENT_APPLICATION_DATASET\t=\t$CURRENT_APPLICATION_DATASET\n"
echo
