import csv
import sys

# Input and output file names
input_file = sys.argv[1]
output_file = sys.argv[2]

# Open the input file and parse its contents
with open(input_file, "r") as infile, open(output_file, "w", newline="") as outfile:
    # Create a CSV writer object
    writer = csv.writer(outfile)

    # Write the header row
    writer.writerow(["i", "j", "sum"])

    # Initialize variables
    i, j, total_sum = None, None, None

    # Read and parse the file line by line
    for line in infile:
        line = line.strip()

        # Look for the line containing i and j
        if line.startswith("Running ./excer1"):
            parts = line.split()
            i = parts[3][2]
            j = parts[5][2]

        # Look for the line containing the sum
        elif line.startswith("The sum of"):
            parts = line.split()
            total_sum = parts[-1]

            # Write the parsed values to the CSV file
            writer.writerow([i, j, total_sum])
