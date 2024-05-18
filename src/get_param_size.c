/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_param_size.c
*/

#include "project.h"
#include <stddef.h>

int get_param_size(char **param_type)
{
    int size = 0;

    for (int i = 0; i < 4; i++) {
        if (my_strcmp(param_type[i], REGISTER) == 0) {
            size += 1;
            continue;
        }
        if (my_strcmp(param_type[i], DIRECT) == 0) {
            size += DIR_SIZE;
            continue;
        }
        if (my_strcmp(param_type[i], INDIRECT) == 0) {
            size += IND_SIZE;
            continue;
        }
    }
    return size;
}
