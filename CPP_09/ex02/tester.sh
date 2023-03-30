#!/bin/bash

clear
make re

if [ $# -eq 2 ];
then
	echo "Valid number of Args."
else
	echo "Invalid number os Args."
	exit 1
fi

if [ -e "PmergeMe" ];
then
	./PmergeMe `shuf -i 1-$1 -n $2 | tr "\n" " "`
fi

make fclean
