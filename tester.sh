##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## base makefile
##

## ---------------- ##
##    Color codes   ##
## ---------------- ##

BLACK="\e[30m" #
RED="\e[31m" #
GREEN="\e[32m" #
YELLOW="\e[33m" #  Standard
BLUE="\e[34m" #  colors
MAGENTA="\e[35m" #
CYAN="\e[36m" #
WHITE="\e[37m" #

BGT_BLACK="\e[90m" #
BGT_RED="\e[91m" #
BGT_GREEN="\e[92m" #
BGT_YELLOW="\e[93m" #  Bright
BGT_BLUE="\e[94m" #  colors
BGT_MAGENTA="\e[95m" #
BGT_CYAN="\e[96m" #
BGT_WHITE="\e[97m" #

BOLD="\e[1m" #
ITALIC="\e[3m" #  Text decorations
UNDERLINE="\e[4m" #

RESET="\e[0m"

declare -i current=1

# Check if file is present
if [ ! -f "corewar" ]; then
    echo "corewar binary not found"
    exit 1
fi

## test 1
echo -ne "|$current| text after -dump flag"
./corewar -dump text champions/bill.cor champions/pdd.cor 1>&2 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 2
echo -ne "|$current| text after -a flag"
./corewar -a text champions/bill.cor champions/pdd.cor 1>&2 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 3
echo -ne "|$current| text after -n flag"
./corewar -n text champions/bill.cor champions/pdd.cor 1>&2 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 4
echo -ne "|$current| no argument between -a and -n flag"
./corewar -a -n 5 champions/bill.cor champions/pdd.cor 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 5
echo -ne "|$current| no argument -a flag and champion"
./corewar -a champions/bill.cor champions/pdd.cor 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 6
echo -ne "|$current| no argument between -n flag and champion"
./corewar -n champions/bill.cor champions/pdd.cor 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 7
echo -ne "|$current| lots of flags"
./corewar -dump -a 100 -n 200 champions/bill.cor -n 300 -a 400 champions/pdd.cor 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

echo -ne "|$current| no flags"
./corewar champions/bill.cor champions/pdd.cor 1>/dev/null 2>/dev/null
if [[ $? != 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 8
echo -ne "|$current| flag after last champion"
./corewar -a 100 -n 200 champions/bill.cor -n 300 -a 400 champions/pdd.cor -a 200 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 9
echo -ne "|$current| other flag after last champion"
./corewar -a 100 -n 200 champions/bill.cor -n 300 -a 400 champions/pdd.cor -n 200 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 10
echo -ne "|$current| mutiple flags after last champion"
./corewar -a 100 -n 200 champions/bill.cor -n 300 -a 400 champions/pdd.cor -a 200 -n 40 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 8
echo -ne "|$current| all flags after last champion"
./corewar -a 100 -n 200 champions/bill.cor -n 300 -a 400 champions/pdd.cor -a 200 -dump 400 -n 65 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 11
echo -ne "|$current| too much champions"
./corewar champions/bill.cor champions/pdd.cor champions/abel.cor champions/tyron.cor champions/bill.cor 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 12
echo -ne "|$current| not enought champions"
./corewar champions/bill.cor 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi

current+=1

## test 13
echo -ne "|$current| file wich is not a champion"
./corewar -a 100 -n 200 champions/bill.s -n 300 -a 400 champions/pdd.cor -a 200 1>/dev/null 2>/dev/null
if [[ $? -eq 84 ]]; then
    echo -e $BOLD $GREEN "OK" $RESET
    else
        echo -e $BOLD $RED "KO" $RESET
fi