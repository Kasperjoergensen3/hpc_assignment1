import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import sys
import argparse


def main(args):
    # read csv file using pandas
    data = pd.read_csv(args.csv_file)

    # plot the data


if __name__ == "__main__":
    # parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("csv_file", help="Path to the csv file")
    args = parser.parse_args()

    # call main function
    main(args)
