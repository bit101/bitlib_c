#! /bin/bash

make dist

echo copying files...
mkdir -p $1
cp demo/main.c $1
cp demo/makefile $1
cp demo/sketch.c $1
cp demo/.gitignore $1
cp .clang_complete $1
cp -r dist/include $1
cp -r dist/libs $1
echo done!
