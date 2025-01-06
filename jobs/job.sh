#!/bin/bash

# Output file
output_file="outputs/performance_results.csv"

# Clear the output file if it exists
>"$output_file"

# add a header to the output file
echo "m,n,k,time_lib,time_mnk,time_mkn,time_nkm,time_nmk,time_kmn,time_knm" >"$output_file"

make realclean
make depend
make

# m, n, k value list
m_values=(3 30 300 3000)
n_values=(4 40 400 4000)
k_values=(5 50 500 5000)
n_value_pairs=${#m_values[@]} # Number of m values

for i in $(seq 0 $((n_value_pairs - 1))); do
    m=${m_values[$i]}
    n=${n_values[$i]}
    k=${k_values[$i]}
    echo "Running ./project1 with m=$m, n=$n, k=$k"
    ./project1 "$m" "$n" "$k" $output_file
done

echo "Results saved to $output_file"
