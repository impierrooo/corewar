/*
** EPITECH PROJECT, 2023
** my parser
** File description:
** parses throught the format string
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static const tab_t flags[] = {{"+"}, {"#"}, {"0"}, {"-"}, {" "}, {"F"}};
static const tab_t length_mod[] = {{"h"}, {"l"}, {"q"}, {"L"}, {"j"},
    {"z"}, {"Z"}, {"t"}, {"0"}};
static const tab_t conversion[] = {{"s"}, {"i"}, {"d"}, {"%"}, {"o"}, {"x"},
    {"X"}, {"p"}, {"f"}, {"u"}, {"e"}, {"E"}, {"0"}};

static
int my_flen(char const *format, int start)
{
    int len = start;

    while (format[len] != '\0' && format[len] != '%') {
        len ++;
    }
    return len - start - 1;
}

static
int my_get_flag(parser_t *parse)
{
    int nb_flags = 0;
    int i = 0;
    int j = 0;

    while (my_strcmp(flags[i].flag, "F") != 0) {
        if (*flags[i].flag == parse->format[j]) {
            my_strcat(parse->flag, flags[i].flag);
            nb_flags ++;
            j++;
        }
        i ++;
    }
    return nb_flags;
}

static
int my_get_length_modifier(parser_t *parse, int start)
{
    int nb_lm = 0;
    int i = 0;

    while (my_strcmp(length_mod[i].flag, "0") != 0) {
        if (*length_mod[i].flag == parse->format[start + nb_lm + 1]) {
            my_strcat(parse->length_modifier, length_mod[i].flag);
            nb_lm ++;
        }
        i ++;
    }
    return nb_lm;
}

static
int my_get_conversion(parser_t *parse, int start)
{
    int i = 0;
    char c = parse->format[start];

    while (my_strcmp(conversion[i].flag, "0") != 0) {
        if (*conversion[i].flag == c) {
            my_strcat(parse->conversion, conversion[i].flag);
            return 1;
        }
        i ++;
    }
    return 0;
}

static
parser_t *init_parser(char const *format, int start)
{
    parser_t *parse = malloc(sizeof(parser_t));

    parse->format = format;
    parse->start = start;
    parse->end = my_flen(format, start);
    parse->flag = malloc(sizeof(char) * 6);
    parse->flag[5] = '\0';
    parse->width = 0;
    parse->precision = -1;
    parse->length_modifier = malloc(sizeof(char) * 11);
    parse->length_modifier[10] = '\0';
    parse->conversion = malloc(sizeof(char) * 13);
    parse->conversion[12] = '\0';
    return parse;
}

parser_t *my_parser(char const *format, int starter)
{
    parser_t *parse = init_parser(format, starter);
    int i = starter;

    i += my_get_flag(parse) + 1;
    if (format[i] >= 48 && format[i] <= 57) {
        parse->width = my_getnbr(format + i);
        i += my_digit_count(parse->width);
    }
    if (format[i] == '.') {
        parse->precision = my_getnbr(format + i);
        i += my_digit_count(parse->precision);
    }
    i += my_get_length_modifier(parse, i) + 1;
    i += my_get_conversion(parse, i);
    return parse;
}
