#!/bin/sh

rm -rf build
mkdir -p bulid
cd bulid
cmake .. -DENABLE_TESTING=ON
make

