/*
** EPITECH PROJECT, 2023
** handle f
** File description:
** handles f and it's flags
*/

#include "my.h"

int handle_fmaj(p_info_t *p_info, parser_t *parse)
{
    double arg = va_arg(p_info->v_list, double);
    int precision = parse->precision;

    if (precision >= 0) {
        if (is_in('l', parse->length_modifier))
            return my_put_long_float(arg, precision);
        return my_put_float(arg, precision);
    }
    if (precision < 0) {
        if (is_in('l', parse->length_modifier))
            return my_put_long_float(arg, 6);
        return my_put_float(arg, 6);
    }
    return 0;
}
