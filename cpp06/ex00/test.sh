#!/bin/bash

RESET="\033[0m"
YEL="\033[33m"
BLU="\033[34m"

make -s
echo -e "${YEL}\nvalid chars\n${BLU}-------${RESET}"
./converter \'c\' \'*\' \'1\' \'~\'
echo -e "${YEL}\nnon printable chars\n${BLU}-------${RESET}"
./converter \'$(printf '\001')\' \'"$(printf '\177')"\' "' '"
echo -e "${YEL}\ninvalid char\n${BLU}-------${RESET}"
./converter a - .
echo -e "${YEL}\nvalid ints\n${BLU}-------${RESET}"
./converter 42 +2147483647 -2147483648 -00001 00000000000000000000000000000
echo -e "${YEL}\ninvalid ints\n${BLU}-------${RESET}"
./converter --1 ++1  2147483648 -2147483649 10000000000000000000000000
echo -e "${YEL}\nvalid floats\n${BLU}-------${RESET}"
./converter 123.12345f 00001.1f 000000.012345678f -2147483648.0f
./converter 340282346638528859811704183484516925440.0f
echo -e "${YEL}\ninvalid floats\n${BLU}-------${RESET}"
./converter 000000.0123456789f -2147483648.1f
echo -e "${YEL}\nvalid doubles\n${BLU}-------${RESET}"
./converter -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
./converter 123.1234 00.2345678901234567 123.12345678
echo -e "${YEL}\ninvalid doubles\n${BLU}-------${RESET}"
./converter 1.23456789012345678 127832446.1626152587 -0.1111111111111111111 
echo -e "${YEL}\nfor science and for fun\n${BLU}-------${RESET}"
./converter inff -inf +inf nan nanf
echo -e "${YEL}\nextra invalids\n${BLU}-------${RESET}"
./converter 1.1ff 1.1.1 +nan