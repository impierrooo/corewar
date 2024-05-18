/*
** EPITECH PROJECT, 2024
** general_lib
** File description:
** my_printf.h
*/

#ifndef PRINTF_H
    #define PRINTF_H
    #include <stdarg.h>

// Structures

// general Parser structure
typedef struct parser {
    char const *format;
    int start;
    int end;
    char *flag;
    int width;
    int precision;
    char *length_modifier;
    char *conversion;
} parser_t;

typedef struct tab {
    char *flag;
} tab_t;

// general printfs informations
typedef struct my_printf_infos {
    int total;
    va_list v_list;
} p_info_t;

// function pointer structure for the printf
typedef struct f_pointer {
    char flag;
    int (*funct)(p_info_t *, parser_t *);
} f_pointer_t;

// Pierre qui fait des structures poubelles frr
typedef struct mystructure {
    int count;
    int lenght_ent;
    int lenght;
    int i;
    int num_ent;
    int num_dec;
} mystruct_t;

// Functions

/* Handle functions */

int handle_c(p_info_t *p_info, parser_t *parse);
int handle_d(p_info_t *p_info, parser_t *parse);
int handle_e(p_info_t *p_info, parser_t *parse);
int handle_emaj(p_info_t *p_info, parser_t *parse);
int handle_f(p_info_t *p_info, parser_t *parse);
int handle_fmaj(p_info_t *p_info, parser_t *parse);
int handle_g(p_info_t *p_info, parser_t *parse);
int handle_gmaj(p_info_t *p_info, parser_t *parse);
int handle_i(p_info_t *p_info, parser_t *parse);
int handle_n(p_info_t *p_info, parser_t *parse);
int handle_o(p_info_t *p_info, parser_t *parse);
int handle_p(p_info_t *p_info, parser_t *parse);
int handle_percent(p_info_t *p_info, parser_t *parse);
int handle_s(p_info_t *p_info, parser_t *parse);
int handle_u(p_info_t *p_info, parser_t *parse);
int handle_x(p_info_t *p_info, parser_t *parse);
int handle_xmaj(p_info_t *p_info, parser_t *parse);

// put_nbr_funcs

int my_put_nbr(int nb);
int my_put_nbr_g(double nb, int precision);
int my_put_nbr_gmaj(double nb, int precision);
int my_put_float(double m, int precision);
int my_put_long_float(long double nb, int precision);
int my_put_nbr_plus(int nb);
int my_put_nbr_space(int nb);
int my_put_nbr_scientific_e(double nb, int precision);
int my_put_nbr_scientific_emaj(double nb, int precision);
int my_put_sh(short n);
int my_put_unsigned_int(unsigned int nbr);
int my_put_dec(int num_dec, int precision);
int my_put_unsigned_short(unsigned short n);
int my_putnbr_base(unsigned int nbr, char *base);
int my_put_ptr(long long);
int my_get_len_base(unsigned int nbr, char *base);

// Put char(s) funcs

int my_putchar(char c);
int my_putchar_error(char c);
int my_putstr(char const *str);
int my_putstr_error(char const *str);

// General funcs

int display_arg(char letter, p_info_t *p_info, parser_t *parse);
int display_rest(int rest, char c);
parser_t *my_parser(char const *format, int start);
int my_printf(char const *format, ...);

#endif /* PRINTF_H */
