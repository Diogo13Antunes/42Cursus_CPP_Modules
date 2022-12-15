#!/bin/bash

PROGRAM_NAME="conversor"
NBR_TESTS=1

make re
clear
printf "\033[1;32m"
printf "/////////////////////////////////////////\n"
printf "////////////// EX00 TESTER //////////////\n"
printf "/////////////////////////////////////////\n"
printf "\n"
printf "\x1b[0m"

tester()
{
	printf "\033[1;38m"
	printf "Test [%d] - %s [%s]\n" $NBR_TESTS "$1" "$2"
	./$PROGRAM_NAME "$2" >test_$NBR_TESTS.txt
	cat test_$NBR_TESTS.txt
	printf "\n"
	printf "\x1b[0m"
	((NBR_TESTS=NBR_TESTS+1))
}

tester "Simple Character:" "a"
tester "Simple Character:" "*"
tester "Simple Character:" " "
tester "Number:" "1"
tester "Number:" "0"
tester "Number:" "-1"
tester "Max Char:" "127"
tester "Max Int:" "2147483647"
tester "Max Int + 1:" "2147483648"
tester "Min Int:" "-2147483648"
tester "Min Int - 1:" "-2147483649"
tester "Edge Case:" "-inff"
tester "Edge Case:" "-inf"
tester "Edge Case:" "+inff"
tester "Edge Case:" "+inf"
tester "Edge Case:" "nanf"
tester "Edge Case:" "nan"
tester "Decimal Number" "3.5"
tester "Decimal Number" "3.5f"
tester "Decimal Number" "3.51"
tester "Decimal Number" "3.51f"
tester "Decimal Number" "-1.5"
tester "Decimal Number" "-1.5f"
tester "Decimal Number" "-1.51"
tester "Decimal Number" "-1.51f"
tester "Decimal Number" "42.5f"
tester "Decimal Number" "-33.1f"
tester "Decimal Number" "33.1f"
tester "Decimal Number" "4800.1f"
tester "Decimal Number" "-4800.1f"

make fclean
