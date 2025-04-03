#!/bin/bash

if [ $# -ne 1 ]; then
	exit 1
fi

n=$1

if ! [[ "$n" =~ ^[0-9]+$ ]]; then
	exit 1
fi

numbers=()
for ((i=0; i<n; i++)); do
	numbers+=($((RANDOM % 100)))
	# numbers+=($((RANDOM % 2147483647)))
done

input_string="${numbers[*]}"
./PmergeMe $input_string

