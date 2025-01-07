#remove all the executables and results
make realclean

#different optimization levels
make TAG=_default              #No optimization
make TAG=_O OPT="-g O1"        #Optimization level 2
make TAG=_O2 OPT="-g O2"       #Optimization level 2
make TAG=_O3 OPT="-g O3"       #Optimization level 3
make TAG=_Ofast OPT="-g Ofast" #Optimization level fast

#remove all the object files
make clean

dwarfdump lib/libmatmult_default.so | grep produce
dwarfdump lib/libmatmult_O.so | grep produce
dwarfdump lib/libmatmult_O2.so | grep produce
dwarfdump lib/libmatmult_O3.so | grep produce
dwarfdump lib/libmatmult_Ofast.so | grep produce
