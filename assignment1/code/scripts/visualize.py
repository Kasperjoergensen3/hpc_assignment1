#!/usr/bin/env python3

import sys
import matplotlib.pyplot as plt


def main():
    # Expect exactly two arguments: input data file and output plot filename
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input.dat> <output.png>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    data_by_function = {}

    # Read data lines from file
    with open(input_file, "r") as f:
        for line in f:
            line = line.strip()
            # Skip empty lines, comment lines, or header line
            if (not line) or line.startswith("#") or "memery" in line.lower():
                continue

            # Example line structure:
            # 6.000   2464.721   0   # matmult_lib
            parts = line.split()
            if len(parts) < 5:
                continue  # skip malformed lines

            memory_kb = float(parts[0])
            mflops = float(parts[1])
            # error    = float(parts[2])  # We won't use 'error' here
            func_name = parts[4]  # after '#'

            # Store data in a dictionary keyed by function name
            if func_name not in data_by_function:
                data_by_function[func_name] = []
            data_by_function[func_name].append((memory_kb, mflops))

    # Create the plot
    plt.figure(figsize=(8, 6))

    # Plot each function's data
    for func_name, values in data_by_function.items():
        # Sort points by memory (so lines connect in ascending order of memory)
        values.sort(key=lambda x: x[0])
        mem_vals = [v[0] for v in values]
        mflops_vals = [v[1] for v in values]

        plt.plot(mem_vals, mflops_vals, marker="o", label=func_name)

    # Use log2 scale on the x-axis
    plt.xscale("log", base=2)

    plt.xlabel("Memory (kB)")
    plt.ylabel("MFLOPS")
    plt.title("MFLOPS vs. Memory")
    plt.grid(True)
    plt.legend()

    # Save plot to file
    plt.savefig(output_file, dpi=300)


if __name__ == "__main__":
    main()
