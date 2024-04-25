#!/bin/sh

for test in tests/*
do
    echo "RUN $test"
    gcc "$test" vla.c -o ./test && ./test
    rm -f ./test
done