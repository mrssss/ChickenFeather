#!/usr/bin/env bash

set -x -e

mkdir build
mkdir /output
cd build

cmake ../src
cmake --build .

