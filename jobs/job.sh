#!/bin/bash

# Output file
output_file="outputs/excer1_results.txt"
extracted_output_file="outputs/excer1_results.csv"

# Clear the output file if it exists
>"$output_file"

make realclean
make depend
make

# Nested for loops for i and j
for i in {0..10}; do
    for j in {0..10}; do
        echo "Running ./excer1 with i=$i and j=$j" | tee -a "$output_file"
        ./excer1 "$i" "$j" >>"$output_file"
        echo "" >>"$output_file" # Add a newline for clarity
    done
done

echo "Results saved to $output_file"
python python_scripts/extract_results.py "$output_file" "$extracted_output_file"
