/*
** EPITECH PROJECT, 2023
** my find primes sup
** File description:
** find the next primary number
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = 1;

    while (i > 0) {
        if (my_is_prime(nb + i) == 1) {
            return (nb + i);
        }
        i ++;
    }
    if (my_is_prime(nb) == 0) {
        return 0;
    }
    return nb;
}
