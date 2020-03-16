#!/bin/sh
cd "${0%/*}"
mkdir -p -m 755 files
cd files
echo "Running CMake..."
cmake -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../ ../../../
echo "Compiling with $(nproc) processors..."
make -j $(nproc)
echo "Compilation complete."

