#!/bin/sh
#BSUB -J part2
#BSUB -o outputs/_%J.out
#BSUB -e outputs/_%J.err
#BSUB -q hpcintro
#BSUB -W 60
#BSUB -R "rusage[mem=2048MB]"
#BSUB -n 1
#BSUB -R "select[model == XeonE5_2650v4]"
#BSUB -R "span[hosts=1] affinity[socket(1)]"

TAG="O3"
DATAFILENAME="data/part2/permuatition_compare_large_k.dat"
>$DATAFILENAME

#compile relevant files
make TAG=$(TAG) OPT="-g -O3" #Optimization level 3
make clean

mkdir -p outputs data/part2 # ensure that the directories exist

DIMS="16 32 64 128 256 512 1024 2048 4096 8192 16384 32768"
ORDERS="lib mnk mkn nkm nmk kmn knm"

#make double for loop to run the executables
for dim in $DIMS; do
    for order in $ORDERS; do
        # Run the make command
        make run_driver DIMS="$128 $128 $dim" ORDER=$order V=0 TAG=$TAG >>$DATAFILENAME
    done
done

