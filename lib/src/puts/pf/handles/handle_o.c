/*
** EPITECH PROJECT, 2023
** handle o
** File description:
** handles %o and it's flags
*/

#include "my.h"

int handle_o(p_info_t *p_info, parser_t *parse)
{
    int arg = va_arg(p_info->v_list, unsigned int);
    int rest = parse->width - 1;

    if (is_in('-', parse->flag))
        return my_putnbr_base(arg, "01234567") + display_rest(rest, ' ');
    if (is_in('0', parse->flag))
        return display_rest(rest, '0') + my_putnbr_base(arg, "01234567");
    return display_rest(rest, ' ') + my_putnbr_base(arg, "01234567");
}
