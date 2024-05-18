/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_dump.c
*/

#include "project.h"

int set_dump(char **argv, int argc, int *i, corewar_t *corewar)
{
    int nbr_cycles = 0;

    if (*i + 1 > argc)
        return HEADER_ERROR;
    (*i)++;
    if (check_number(argv[*i], &nbr_cycles) != 0)
        return HEADER_ERROR;
    if (nbr_cycles < 0)
        return HEADER_ERROR;
    corewar->remaining_cycles = nbr_cycles;
    return SET_DUMP;
}
