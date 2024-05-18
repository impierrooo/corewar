/*
** EPITECH PROJECT, 2023
** handle C
** File description:
** handles %X and it's flags
*/

#include "my.h"

int handle_xmaj(p_info_t *p_info, parser_t *parse)
{
    int counter = 0;
    int arg = va_arg(p_info->v_list, unsigned int);
    int rest = parse->width - 1;
    char *base = "0123456789ABCDEF";

    if (is_in('#', parse->flag))
        counter += my_putstr("0X");
    if (is_in('-', parse->flag))
        return counter + my_putnbr_base(arg, base) + display_rest(rest, ' ');
    if (is_in('0', parse->flag))
        return counter + display_rest(rest, '0') + my_putnbr_base(arg, base);
    return counter + display_rest(rest, ' ') + my_putnbr_base(arg, base);
}
