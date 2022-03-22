#!/bin/bash

binary="$1"
test_time="$2"

i=1
while [ $i -le $test_time ];
do
    ./make_test.o > input.txt
    ./solver.o < input.txt > ans.txt
    ./$binary < input.txt > output.txt
    diff output.txt ans.txt
    if [ $? -eq 0 ]; then
        echo "[test$i] OK "
    else
        echo "[test$i] Failed"
        exit 1
    fi
    i=$(($i+1))
done