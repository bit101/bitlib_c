#! /bin/bash

make dist

echo copying files...
mkdir -p $1/include
mkdir -p $1/libs
cp demo/main.c $1
cp demo/makefile $1
cp demo/sketch.c $1
cp .clang_complete $1
cp -r dist/include/* $1/include
cp -r dist/libs/* $1/libs
echo done!
