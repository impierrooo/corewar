/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_address.c
*/

#include "project.h"

int set_address(char **argv, int argc, int *i, champion_t *champion)
{
    int address = 0;
    int flag = 0;

    if (*i + 1 > argc)
        return HEADER_ERROR;
    (*i)++;
    for (int k = *i; k < argc && flag == 0; k++) {
        if (is_champion_path(argv[k]) == 1)
            flag = 1;
    }
    if (flag == 0 || check_number(argv[*i], &address) != 0)
        return HEADER_ERROR;
    if (address < 0)
        return HEADER_ERROR;
    champion->address = address;
    return SET_ADDRESS;
}
