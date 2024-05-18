/*
** EPITECH PROJECT, 2023
** handle c
** File description:
** handles %c and it's flags
*/

#include "my.h"

int handle_c(p_info_t *p_info, parser_t *parse)
{
    char arg = va_arg(p_info->v_list, int);
    int rest = parse->width - 1;

    if (is_in('-', parse->flag))
        return my_putchar(arg) + display_rest(rest, ' ');
    return display_rest(rest, ' ') + my_putchar(arg);
}
