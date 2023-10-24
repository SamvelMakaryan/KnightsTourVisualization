#!/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

cd build

cmake ..

make

if [ $? -eq 0 ]; then
    ./KnightsTour
else
    echo "Build failed. KnightsTour executable was not created."
fi

