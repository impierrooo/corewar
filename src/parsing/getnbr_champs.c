/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** getnbr_champs.c
*/

#include "project.h"

int getnbr_champs(int argc, char **argv)
{
    int result = 0;

    for (int i = 1; i < argc; i++) {
        result += (is_champion_path(argv[i]) == 1) ? 1 : 0;
    }
    return result;
}
