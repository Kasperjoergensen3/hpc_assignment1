#remove all the executables and results
make realclean

#different optimization levels
make TAG=_default               #No optimization
make TAG=_O OPT="-g -O"         #Optimization level 1
make TAG=_O2 OPT="-g -O2"       #Optimization level 2
make TAG=_O3 OPT="-g -O3"       #Optimization level 3
make TAG=_Ofast OPT="-g -Ofast" #Optimization level fast

#remove all the object files
make clean
