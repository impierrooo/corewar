/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** hexa_to_dec.c
*/

#include "project.h"
#include <stdlib.h>
#include <stdio.h>

char *hexa_to_bin(char *hex)
{
    int value = hex_to_int(hex);
    char *result = malloc(sizeof(char) * 9);

    for (int i = 0; i < 8; i++)
        result[i] = '0';
    result[8] = '\0';
    for (int i = 0; value > 0 && i < 8; i++) {
        result[i] = value % 2 == 0 ? '0' : '1';
        value /= 2;
    }
    my_revstr(result);
    return result;
}

char **separate_coding_byte(char *arena)
{
    char *temp = malloc(sizeof(char) * 3);
    char *bin = NULL;
    char **result = malloc(sizeof(char *) * 5);

    temp[0] = '\0';
    temp[1] = '\0';
    temp[2] = '\0';
    my_strncat(temp, arena, 2);
    bin = hexa_to_bin(temp);
    for (int i = 0; i < 4; i++)
        result[i] = my_strndup(bin + (i * 2), 2);
    result[4] = NULL;
    free(bin);
    return result;
}
