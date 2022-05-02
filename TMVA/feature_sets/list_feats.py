import json
import argparse
from logging import warning

parser = argparse.ArgumentParser()
parser.add_argument("set_numbers",metavar='N',type=int, nargs='+',
    help="Space-separated list of set numbers")
args = parser.parse_args()

def print_list(l):
    for i, it in enumerate(l):
        print(f"{i+1}\t{it}")
    print("\n")

for set in args.set_numbers:
    feat_list = []
    try:
        fileIn = open(f"set{set}.json")
    except IOError:
        warning(f"Could not open set{set}.json")
        exit(1)

    print(f"\n\nFeatures in set{set}.json:")
    j = json.load(fileIn)
    
    for feature in j["features"]:
        feat_list.append(feature["expr"])
    
    print_list(sorted(feat_list,key=str.casefold))