#!/bin/sh 
rm ../build/suse_X86/run.exe 
make
cd ../build/suse_X86/ 
./run.exe 
cd ../../src/
