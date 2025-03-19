#!/bin/bash

END="\e[0m"
TEXT="\e[96m"

if [ $# -lt 1 ]; then
	OFILE="test.txt"
	touch $OFILE
	echo "hello" >> $OFILE
	echo "bonjour" >> $OFILE
	echo "hellobonjourhellobonjour" >> $OFILE
	echo "		bonjour			hello" >> $OFILE
else
	OFILE=$1
fi

if [ $# -lt 2 ]; then
	FIND="hello"
else
	FIND=$2
fi

if [ $# -lt 3 ]; then
	REPLACE="BONJOURRR"
else
	REPLACE=$3
fi

RFILE=$OFILE 
RFILE+=".replace"

make re

printf "${TEXT}Program output:${END}\n\t"
./replace $OFILE $FIND $REPLACE
if [ $? -eq 0 ]; then
	printf "\n${TEXT}checking occurrence of s1 and s2:${END}\n\t"

	A=$(cat ./$OFILE | grep -o $FIND | wc -l)
	B=$(cat ./$RFILE | grep -o $FIND | wc -l)
	C=$(cat ./$OFILE | grep -o $REPLACE | wc -l)
	D=$(cat ./$RFILE | grep -o $REPLACE | wc -l)

	echo $FIND " is present " $A " times in " $OFILE
	echo $FIND " is present " $B " times in " $RFILE
	echo $REPLACE " is present " $C " times in " $OFILE
	echo $REPLACE " is now present " $D " times in " $RFILE
else
	printf "\n${TEXT}Program gave an error, no checking needed${END}\n"
fi