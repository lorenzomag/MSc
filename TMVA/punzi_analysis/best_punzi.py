import pandas as pd
import numpy as np
import os

workspace_dir = f"{os.environ.get('WORKSPACE_DIR')}/TMVA"
feature_sets_to_analyse = range(1, 11)
hyperparams_to_analyse = [1]


def main():
    ds = fetch_dataset()
    for massID in range(5):
        best_punzi(ds, massID)
        print()


def best_punzi(ds, massID=0):
    if massID == 0:
        print("-----------> Overall best performances: ")
    if massID in [1, 2, 3, 4]:
        print(f"-----------> Best performances for mass case {massID}: ")
        ds = ds[ds["Mass ID"] == massID]

    sorted_ds = ds.sort_values(by="Max Punzi", ascending=False)
    print(sorted_ds.head(5))


def fetch_dataset():
    ds = pd.DataFrame()

    for fs in feature_sets_to_analyse:
        for hp in hyperparams_to_analyse:
            try:
                ds_temp = pd.read_csv(
                    f"{workspace_dir}/runs/run_fs{fs}_hp{hp}/punzi/punzi.csv", header=0)
            except:
                continue
            ds_new = ds_temp.assign(feature_set=fs).assign(hyperparam_set=hp)
            ds = pd.concat([ds, ds_new], ignore_index=True)

    # Remove leading spaces in column names
    ds.columns = [x.strip() for x in ds.columns]

    ds.to_csv(f"{workspace_dir}/punzi_analysis/all_punzi.csv")
    return ds


if __name__ == "__main__":
    main()
