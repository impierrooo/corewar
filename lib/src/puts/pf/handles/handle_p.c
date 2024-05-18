/*
** EPITECH PROJECT, 2023
** handle p
** File description:
** handles %p and it's flags
*/

#include "my.h"

int handle_p(p_info_t *p_info, parser_t *parse)
{
    long long arg = va_arg(p_info->v_list, long long);
    int rest = parse->width - 1;

    if (is_in('-', parse->flag))
        return my_put_ptr(arg) + display_rest(rest, ' ');
    return display_rest(rest, ' ') + my_put_ptr(arg);
}
