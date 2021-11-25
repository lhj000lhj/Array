#!/bin/bash
cmake -B build
cd build
echo "build is started..."
make -j8
echo "build is done"
cd ..
echo "test is started..."
./build/test/CStringBase
sleep 3s
./build/test/CStringSearch
sleep 3s
./build/test/CStringProcess
sleep 3s
echo "test is done"
echo "test log is writen in TestLog.txt"