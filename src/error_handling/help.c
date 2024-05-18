/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** help.c
*/

#include "project.h"

int help(char **argv, int argc)
{
    if (argc < 2)
        return HEADER_ERROR;
    if (my_strcmp(argv[1], "-h") != 0 && my_strcmp(argv[1], "--help") != 0)
        return HEADER_ERROR;
    my_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number]");
    my_putstr("[-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n-dump nbr_cycle dumps the memory after the ");
    my_putstr("nbr_cycle execution (if the round isn't\nalready over) ");
    my_putstr("with the following format: 32 bytes/line in hexadecimal (");
    my_putstr("A0BCDEFE1DD3...)\n-n prog_number sets the next program's ");
    my_putstr("number. By default, the first free number in the\nparameter ");
    my_putstr("order\n-a load_address sets the next program's loading add");
    my_putstr("ress. When no address is specified,\noptimize the addresses");
    my_putstr(" so that the processes are as far away from each other as\n");
    my_putstr("possible. The addresses are MEM_SIZE modulo.\n");
    return 0;
}
