#!/bin/bash

echo "Running Betty"
sleep 2
betty *.h *.c
sleep 1
echo "Compiling..."
sleep 2
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
echo "Compilation complete!"
