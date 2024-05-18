/*
** EPITECH PROJECT, 2023
** handles n
** File description:
** handles %n and it's potential flags
*/

#include "my.h"
#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>

int handle_n(p_info_t *p_info, parser_t *parse)
{
    int *n = malloc(sizeof(int));

    if (is_in('h', parse->flag))
        *n = va_arg(p_info->v_list, int);
    if (is_in('l', parse->flag))
        *n = va_arg(p_info->v_list, long int);
    if (is_in('j', parse->flag))
        *n = va_arg(p_info->v_list, intmax_t);
    if (is_in('z', parse->flag) || is_in('Z', parse->flag))
        *n = va_arg(p_info->v_list, size_t);
    if (is_in('t', parse->flag))
        *n = va_arg(p_info->v_list, ptrdiff_t);
    n = va_arg(p_info->v_list, int *);
    *n = p_info->total;
    return 0;
}
