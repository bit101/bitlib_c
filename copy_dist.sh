#! /bin/bash

make dist

echo copying files...
mkdir -p $1/include
mkdir -p $1/libs
cp -r dist/include/* $1/include
cp -r dist/libs/* $1/libs
echo done!
