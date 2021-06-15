#!/bin/bash
nvcc --shared -o libculib.so culib.cu --compiler-options '-fPIC' 