/*
** EPITECH PROJECT, 2023
** handle i
** File description:
** handles %i and it's flags and length modifiers
*/

#include "my.h"

static
int case_h_minus(parser_t *parse, int counter, int arg, int rest)
{
    if (is_in('h', parse->length_modifier))
        return counter + my_put_sh(arg) + display_rest(rest, ' ');
    return counter + my_put_nbr(arg) + display_rest(rest, ' ');
}

static
int case_h_zero(parser_t *parse, int counter, int arg, int rest)
{
    if (is_in('h', parse->length_modifier))
        return counter + display_rest(rest, '0') + my_put_sh(arg);
    return counter + display_rest(rest, '0') + my_put_nbr(arg);
}

int handle_i(p_info_t *p_info, parser_t *parse)
{
    int arg = va_arg(p_info->v_list, int);
    int len_num = my_digit_count(arg);
    int rest = parse->width - len_num;
    int counter = 0;

    if (is_in('+', parse->flag)) {
        if (is_in('h', parse->length_modifier))
            return display_rest(rest, ' ') + my_putchar('+') + my_put_sh(arg);
        return display_rest(rest, ' ') + my_put_nbr_plus(arg);
    }
    if (is_in(' ', parse->flag) && arg > 0)
        counter += my_putchar(' ');
    if (is_in('-', parse->flag))
        return case_h_minus(parse, counter, arg, rest);
    if (is_in('0', parse->flag))
        return case_h_zero(parse, counter, arg, rest);
    return counter + display_rest(rest, ' ') + my_put_nbr(arg);
}
