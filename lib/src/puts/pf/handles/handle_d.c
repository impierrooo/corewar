/*
** EPITECH PROJECT, 2023
** handle i
** File description:
** handles %i and it's flags and length modifiers
*/

#include "my.h"
#include <stdio.h>

int handle_d(p_info_t *p_info, parser_t *parse)
{
    int arg = va_arg(p_info->v_list, int);
    int len_num = my_digit_count(arg);
    int rest = parse->width - len_num;
    int counter = 0;

    if (is_in('+', parse->flag)) {
        if (is_in('-', parse->flag)) {
            return my_put_nbr_plus(arg) + display_rest(rest, ' ');
        } else
            return display_rest(rest, ' ') + my_put_nbr_plus(arg);
    }
    if (is_in(' ', parse->flag) && arg > 0)
        counter += my_putchar(' ');
    if (is_in('-', parse->flag))
        return counter + my_put_nbr(arg) + display_rest(rest, ' ');
    if (is_in('0', parse->flag))
        return counter + display_rest(rest, '0') + my_put_nbr(arg);
    return counter + display_rest(rest, ' ') + my_put_nbr(arg);
}
