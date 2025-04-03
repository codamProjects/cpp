#!/bin/bash

./RPN "8 9 +"         # Result: 17
./RPN "9 1 -"         # Result: 8
./RPN "9 9 *"         # Result: 81
./RPN "8 2 /"         # Result: 4

./RPN "3 4 + 2 *"     # Result: 14
./RPN "7 8 * 9 +"     # Result: 65
./RPN "6 2 / 3 *"     # Result: 9
./RPN "9 8 + 3 /"     # Result: 5

./RPN "10 2 +"        # Error: number >= 10
./RPN "-10 2 +"       # Error: number < 0
./RPN "5 0 /"         # Error: division by zero
./RPN "1"             # Result: 1
./RPN "1 +"           # Error: not enough operands for operator
./RPN "1 2 &"         # Error: invalid operator
./RPN ""              # Error: empty input

./RPN "1 2 3 + +"     # Result: 6
./RPN "9 8 7 * +"     # Result: 65
./RPN "5 4 3 - +"     # Result: 6
./RPN "6 5 4 * /"     # Result: 0

./RPN "3 4 + 5 * 3 -" # Result: 32
./RPN "8 3 2 * +"     # Result: 14
./RPN "9 3 / 2 * 4 +" # Result: 10
./RPN "7 2 * 3 +"     # Result: 17

./RPN "3    2    +"    # Result: 5
./RPN " 3 2 + "        # Result: 5
./RPN "32+"            # Error: invalid format


#max int, Result = 2147483647
./RPN "9 2 * 1 + 7 * 5 * 4 * 3 + 5 * 8 * 2 + 5 * 8 * 8 * 2 + 7 * 9 * 1 +"

#min int, Result = -2147483648
./RPN "9 2 * 1 + 7 * 5 * 4 * 3 + 5 * 8 * 2 + 5 * 8 * 8 * 2 + 7 * 9 * -1 * 2 -"

#overflow +
./RPN "9 2 * 1 + 7 * 5 * 4 * 3 + 5 * 8 * 2 + 5 * 8 * 8 * 2 + 7 * 9 * 1 + 9 +"

#underflow -
./RPN "9 2 * 1 + 7 * 5 * 4 * 3 + 5 * 8 * 2 + 5 * 8 * 8 * 2 + 7 * 9 * -1 * 2 - 6 -"

#overflow *
./RPN "9 2 * 1 + 7 * 5 * 4 * 3 + 5 * 8 * 2 + 5 * 8 * 8 * 2 + 7 * 9 * 2 *"

#underflow *
./RPN "9 2 * 1 + 7 * 5 * 4 * 3 + 5 * 8 * 2 + 5 * 8 * 8 * 2 + 7 * 9 * -4 *"
