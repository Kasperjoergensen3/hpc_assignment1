#write to file

# open, clear and write to file
>data/dwarfdump.txt

dwarfdump lib/libmatmult_default.so | grep produce >>data/dwarfdump.txt
dwarfdump lib/libmatmult_O.so | grep produce >>data/dwarfdump.txt
dwarfdump lib/libmatmult_O2.so | grep produce >>data/dwarfdump.txt
dwarfdump lib/libmatmult_O3.so | grep produce >>data/dwarfdump.txt
dwarfdump lib/libmatmult_Ofast.so | grep produce >>data/dwarfdump.txt
