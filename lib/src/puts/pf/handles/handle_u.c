/*
** EPITECH PROJECT, 2023
** handle u
** File description:
** handles %u and it's flags
*/

#include "my.h"

int handle_u(p_info_t *p_info, parser_t *parse)
{
    unsigned int arg = va_arg(p_info->v_list, unsigned int);
    int len_num = my_digit_count(arg);
    int rest = parse->width - len_num;

    if (is_in('-', parse->flag)) {
        if (is_in('h', parse->length_modifier))
            return my_put_unsigned_short(arg) + display_rest(rest, ' ');
        return my_put_unsigned_int(arg) + display_rest(rest, ' ');
    }
    if (is_in('0', parse->flag)) {
        if (is_in('h', parse->length_modifier))
            return my_put_unsigned_short(arg) + display_rest(rest, ' ');
        return display_rest(rest, '0') + my_put_unsigned_int(arg);
    }
    return display_rest(rest, ' ') + my_put_unsigned_int(arg);
}
