#!/bin/bash

usage() { echo "Usage: $0 -f <FEATURE SET> [-h <HYPERP. SET>] [<LIST OF TMVA METHODS>]" 1>&2; exit 1; }

while getopts ":f:h:" o; do
    case "${o}" in
        f)
            FEATURE_SET=${OPTARG}
            ;;
        h)
            HYPERPARAM_SET=${OPTARG}
            ;;
        *)
            usage
            ;;
    esac
done
shift $((OPTIND-1))

METHODS=$@

if [ -z "${FEATURE_SET}" ]; then
    usage
fi

if [ -z "${HYPERPARAM_SET}" ]; then
    HYPERPARAM_SET=1
fi

output_dir="runs/run_fs${FEATURE_SET}_hp${HYPERPARAM_SET}/"

feature_set_config="feature_sets/set${FEATURE_SET}.json"
# hpyerparameter_set_config="hyperparam_sets/set${HYPERPARAM_SET}.json"

cp "${feature_set_config}" "${output_dir}feature_settings.json"
cp TMVAClassification ${output_dir}

cd ${output_dir}

./TMVAClassification $METHODS