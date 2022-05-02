import json
import argparse
from logging import warning


parser = argparse.ArgumentParser()
parser.add_argument("set_numbers",metavar='N',type=int, nargs=2,
    help="Space-separated pair of set numbers")
args = parser.parse_args()

first_set = set()
second_set = set()

for i,set in enumerate(args.set_numbers):
    try:
        fileIn = open(f"set{set}.json")
    except IOError:
        warning(f"Could not open set{set}.json")
        exit(1)

    j = json.load(fileIn)
    
    if (i == 0):
        for feature in j["features"]:
            first_set.add(feature['expr'])
    else:
        for feature in j["features"]:
            second_set.add(feature['expr'])



def intersection(lst1, lst2):
    lst3 = {value for value in lst1 if value in lst2}
    return lst3


inter = intersection(first_set,second_set)

l1_only = sorted(list(first_set - inter),key=str.casefold)
l2_only = sorted(list(second_set - inter),key=str.casefold)
inter = sorted(inter,key=str.casefold)


def print_list(l):
    for i, it in enumerate(l):
        print(f"{i+1}\t{it}")
    print("\n")

print(f"In both set {args.set_numbers[0]} and {args.set_numbers[1]}:")
print_list(inter)
print(f"Only in set {args.set_numbers[0]}:")
print_list(l1_only)
print(f"Only in set {args.set_numbers[1]}:")
print_list(l2_only)