#!/bin/sh

rootdir=$(pwd)
mkdir -p $buildpath
cd $buildpath; cmake $rootdir; cmake --build .