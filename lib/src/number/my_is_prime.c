/*
** EPITECH PROJECT, 2023
** my is prime
** File description:
** control if a number is a primary or not
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1) {
        return 0;
    }
    while (i != nb) {
        if ((nb % i) == 0) {
            return 0;
        }
        i ++;
    }
    return 1;
}
