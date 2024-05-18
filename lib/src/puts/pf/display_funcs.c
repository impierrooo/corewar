/*
** EPITECH PROJECT, 2023
** display_funcs
** File description:
** regroup all the display funcs
*/

#include "my.h"
#include <stdlib.h>

static const
f_pointer_t PRINTF_FUNCS[] = {{'c', &(handle_c)},
    {'s', &(handle_s)},
    {'i', &(handle_i)},
    {'d', &(handle_d)},
    {'%', &(handle_percent)},
    {'u', &(handle_u)},
    {'o', &(handle_o)},
    {'x', &(handle_x)},
    {'X', &(handle_xmaj)},
    {'p', &(handle_p)},
    {'f', &(handle_f)},
    {'F', &(handle_fmaj)},
    {'e', &(handle_e)},
    {'E', &(handle_emaj)},
    {'g', &(handle_g)},
    {'G', &(handle_gmaj)},
    {'a', NULL},
    {'A', NULL},
    {'0', NULL}};

int display_rest(int rest, char c)
{
    int j = 0;

    while (j < rest) {
        my_putchar(c);
        j ++;
    }
    return j;
}

int display_arg(char letter, p_info_t *p_info, parser_t *parse)
{
    int j = 0;
    char flag = PRINTF_FUNCS[j].flag;

    if (letter == 'n') {
        handle_n(p_info, parse);
        return 0;
    }
    while (PRINTF_FUNCS[j].flag != '0') {
        if (letter == PRINTF_FUNCS[j].flag) {
            return PRINTF_FUNCS[j].funct(p_info, parse);
        }
        j ++;
    }
    if (flag == '0')
        return -6548275;
    return 0;
}
