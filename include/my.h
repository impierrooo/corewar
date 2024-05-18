/*
** EPITECH PROJECT, 2023
** my header file
** File description:
** lists all the librabry's functions in a header
*/

#ifndef MY_H
    #define MY_H
    #define UNUSED __attribute_maybe_unused__
    #include "my_printf.h"
    #include "str.h"

    #define FALSE 0
    #define TRUE 1
    #define SHORT_OVERFLOW 32767
    #define SHORT_SIZE 65536
    #define IS_NUMBER(c) ('0' <= (c) && (c) <= '9')

// number related functions

int power(int nb, int power);
int square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int nb);
int my_digit_count(int nb);
void my_sort_int_array(int *tab, int size);
void my_swap(int *a, int *b);

#endif /* _MY_H  */
