/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_index.c
*/

#include "project.h"

int get_index(char *byte)
{
    int result = hex_to_int(byte);

    if (result > SHORT_OVERFLOW)
        result -= SHORT_SIZE;
    result += (result > 0) ? 4 : -4;
    return result;
}
