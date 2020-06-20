#! /bin/bash

make dist

echo copying files to system...
sudo mkdir -p /usr/include/bitlib
sudo cp -r ./dist/include/* /usr/include/bitlib
sudo cp ./dist/libs/libbitlib.so /usr/lib64/
