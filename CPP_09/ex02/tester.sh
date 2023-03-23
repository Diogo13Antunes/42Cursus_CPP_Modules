#!/bin/bash

clear
make re

if [ $# -eq 2 ];
then
	echo "Valid number of Args."i
else
	echo "Invalid number os Args."
	exit 1
fi

var1=$1
var2=$2

if [$var1 -gt $var2];
then
	echo "The Fisrt arg mus be bigger than the second."
	exit 1
fi

if [ -e "PmergeMe" ];
then
	./PmergeMe `shuf -i 1-$1 -n $2 | tr "\n" " "`
fi

make fclean

