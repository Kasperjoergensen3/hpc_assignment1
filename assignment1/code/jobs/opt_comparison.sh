#!/bin/bash
#BSUB -J compare_compiler_optim
#BSUB -o outputs/_%J.out
#BSUB -e outputs/_%J.err
#BSUB -q hpcintro
#BSUB -W 8
#BSUB -R "rusage[mem=2048MB]"

mkdir -p outputs
mkdir -p data

sh ./jobs/compile_all.sh

TAGS="_O3 _default _O _O2 _Ofast"
DIMS="16 32 64 128 256 512 1024"
ORDERS="lib mnk mkn nkm nmk kmn knm"
for tag in $TAGS; do
    #empty the file opt_comparison.dat if it exists
    >data/opt_comparison$tag.dat

    #make double for loop to run the executables
    for dim in $DIMS; do
        for order in $ORDERS; do
            # Run the make command
            make run_driver DIMS="$dim $dim $dim" ORDER=$order V=0 TAG=$tag>> data/opt_comparison$tag.dat
        done
    done
done
