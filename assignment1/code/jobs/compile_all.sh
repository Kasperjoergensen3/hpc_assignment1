#!/bin/sh
#remove all the executables and results
make realclean

#different optimization levels
make TAG=default               #No optimization
make TAG=O OPT="-g -O"         #Optimization level 1
make TAG=O2 OPT="-g -O2"       #Optimization level 2
make TAG=O3 OPT="-g -O3"       #Optimization level 3
make TAG=Ofast OPT="-g -Ofast" #Optimization level fast

#remove all the object files
make clean
