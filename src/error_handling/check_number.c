/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_number.c
*/

#include "project.h"

int check_number(char *str, int *result)
{
    if (my_str_isnum(str) == 0 || str[0] == '-')
        return HEADER_ERROR;
    *result = my_getnbr(str);
    return 0;
}
