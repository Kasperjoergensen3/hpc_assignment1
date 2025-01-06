#!/bin/bash

# Output file
output_file="outputs/performance_results.csv"

# Clear the output file if it exists
>"$output_file"

# Compile the project
make realclean
make depend
make

# Run the project with different m, n, k values
# m, n, k value list
m_values=(3 30 300)
n_values=(4 40 400)
k_values=(5 50 500)
n_value_pairs=${#m_values[@]} # Number of m values

for i in $(seq 0 $((n_value_pairs - 1))); do
    m=${m_values[$i]}
    n=${n_values[$i]}
    k=${k_values[$i]}
    echo "Running ./project1 with m=$m, n=$n, k=$k"
    ./project1 "$m" "$n" "$k" "$output_file"
done

echo "Results saved to $output_file"
