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
    time = data.values[:, 3:]
    perf = (np.prod(data.values[:, :3].astype(float), axis=1) / time) * 2.0e-6
    colnames = data.columns[3:]
    colnames = [name.split("_")[-1] for name in colnames]

    fig, ax = plt.subplots(2, 1)
    for i in range(time.shape[1]):
        ax[0].plot(range(time.shape[0]), time[:, i], label=colnames[i])
    ax[0].set_xlabel("x")
    ax[0].set_ylabel("time (s)")
    ax[0].legend()
    for i in range(perf.shape[1]):
        ax[1].plot(range(time.shape[0]), perf[:, i], label=colnames[i])
    ax[1].set_xlabel("x")
    ax[1].set_ylabel("performance (GFLOPS)")
    ax[1].legend()
    plt.savefig(root.joinpath("figures/performance.png"))


if __name__ == "__main__":
    # parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--csv_file", help="Path to the csv file")
    args = parser.parse_args()

    # call main function
    main(args)
