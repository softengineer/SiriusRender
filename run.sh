#!/bin/bash

cd build
cmake ..
make
if [ $? -eq 0 ]; then
echo "running app ...."
./siriusrender
fi
