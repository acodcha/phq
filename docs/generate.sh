#!/bin/sh
cd "${0%/*}"
./clear.sh
doxygen Doxyfile
cd latex
make
cd ..

