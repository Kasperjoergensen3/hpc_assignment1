import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import sys
import argparse
from pathlib import Path

root = Path(__file__).resolve().parents[1]


def main(args):
    # read csv file using pandas
    data = pd.read_csv(args.csv_file)

    # plot the data
    print(data.head())

    x = data.values[:, 0]
    y = data.values[:, 3:]
    colnames = data.columns[3:]
    colnames = [name.split("_")[-1] for name in colnames]

    plt.figure()
    for i in range(y.shape[1]):
        plt.plot(x, y[:, i], label=colnames[i])
    plt.xlabel("x")
    plt.ylabel("runtime (s)")
    plt.legend()
    plt.savefig(root.joinpath("figures/performance.png"))


if __name__ == "__main__":
    # parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--csv_file", help="Path to the csv file")
    args = parser.parse_args()

    # call main function
    main(args)
