/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** hex_to_int.c
*/

#include "project.h"
#include <stdlib.h>

char *get_from_arena(char *arena, int size)
{
    char *temp = NULL;

    if (size < 1)
        return NULL;
    temp = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++)
        temp[i] = '\0';
    temp[size] = '\0';
    my_strncat(temp, arena, size);
    return temp;
}

char *get_byte(char *arena)
{
    char *result = malloc(sizeof(char) * 3);

    result[0] = *arena;
    result[1] = *(arena + 1);
    result[2] = '\0';
    return result;
}

// /!\ frees it's paramter
int hex_to_int(char *hex)
{
    int decimal = 0;
    int length = my_strlen(hex);
    int turn = 0;

    if (hex == NULL)
        return 0;
    for (int i = length - 1; i > -1; i--) {
        if (hex[i] >= '0' && hex[i] <= '9')
            decimal += (hex[i] - '0') * power(16, turn);
        if (hex[i] >= 'a' && hex[i] <= 'f')
            decimal += (hex[i] - 'a' + 10) * power(16, turn);
        turn++;
    }
    free(hex);
    return decimal;
}
