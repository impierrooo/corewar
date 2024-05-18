/*
** EPITECH PROJECT, 2023
** my compute power
** File description:
** calculates pwer recursively
*/

int power(int nb, int p)
{
    if (p == 1) {
        return nb;
    }
    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    }
    if (nb > (214748647 / p)) {
        return 0;
    }
    return power(nb, p - 1) * nb;
}
