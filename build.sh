#!/bin/sh

rm -rf build
mkdir -p build
cd build
cmake .. -DENABLE_TESTING=ON
make

