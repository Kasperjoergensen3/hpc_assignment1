#!/bin/sh

#write to dat file
mkdir -p data

#empty the file opt_comparison.dat if it exists
>data/opt_comparison.dat

DIMS = 100 200 300 400 500 600 700 800 900 1000
ORDERS = lib mnk mkn nkm nmk knm kmn

#make double for loop to run the executables
for dim in $DIMS; do
    for order in $ORDERS; do
        make run_driver DIM=$dim ORDER=$order >>data/opt_comparison.dat
