#!/bin/sh
cd "${0%/*}"
rm -rf html
rm -rf latex
doxygen Doxyfile
cd latex
make
cd ..

