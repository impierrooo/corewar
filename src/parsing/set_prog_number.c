/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_prog_number.c
*/

#include "project.h"

int set_prog_number(char **argv, int argc, int *i, champion_t *champion)
{
    int prog_number = 0;
    int flag = 0;

    if (*i + 1 > argc)
        return HEADER_ERROR;
    (*i)++;
    for (int k = *i; k < argc && flag == 0; k++) {
        if (is_champion_path(argv[k]) == 1)
            flag = 1;
    }
    if (flag == 0 || check_number(argv[*i], &prog_number) != 0)
        return HEADER_ERROR;
    if (prog_number < 0)
        return HEADER_ERROR;
    champion->id = prog_number;
    champion->registers[0] = champion->id;
    return SET_PROG_NBR;
}
