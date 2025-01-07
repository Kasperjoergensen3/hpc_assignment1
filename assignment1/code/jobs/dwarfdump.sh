#!/bin/sh
#make data dir if it doesn't exist
mkdir -p data

#empty the file dwarfdump.txt if it exists
>data/dwarfdump.txt

echo "dwarfdump of executables" >>data/dwarfdump.txt
echo "=========================" >>data/dwarfdump.txt
echo "" >>data/dwarfdump.txt
echo "libmatmult_default.so" >>data/dwarfdump.txt
dwarfdump lib/libmatmult_default.so | grep produce >>data/dwarfdump.txt
echo "libmatmult_O.so" >>data/dwarfdump.txt
dwarfdump lib/libmatmult_O.so | grep produce >>data/dwarfdump.txt
echo "libmatmult_O2.so" >>data/dwarfdump.txt
dwarfdump lib/libmatmult_O2.so | grep produce >>data/dwarfdump.txt
echo "libmatmult_O3.so" >>data/dwarfdump.txt
dwarfdump lib/libmatmult_O3.so | grep produce >>data/dwarfdump.txt
echo "libmatmult_Ofast.so" >>data/dwarfdump.txt
dwarfdump lib/libmatmult_Ofast.so | grep produce >>data/dwarfdump.txt
