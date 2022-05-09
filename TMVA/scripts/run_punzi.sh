#!/bin/bash

usage() { echo "Usage: $0 -f <FEATURE SET> [-h <HYPERP. SET = 1>]" 1>&2; exit 1; }

while getopts ":f:h:c:" o; do
    case "${o}" in
        f)
            FEATURE_SET=${OPTARG}
            ;;
        h)
            HYPERPARAM_SET=${OPTARG}
            ;;
        c)
            PUNZI_CUT=${OPTARG}
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

if [ -z "${PUNZI_CUT}" ]; then
    PUNZI_CUT=0
fi

output_dir="runs/run_fs${FEATURE_SET}_hp${HYPERPARAM_SET}/"


cp get_punzi.C ${output_dir}

cd ${output_dir}

root "get_punzi.C(${PUNZI_CUT})" -b -e ".q"