#!/bin/sh

rm -rf build
mkdir -p bulid
cd bulid
cmake ..
make

