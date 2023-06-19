#!/bin/bash
path=$(dirname "$0")
cd "$path"
gcc -c *.c
gcc -shared -o liball.so *.o
