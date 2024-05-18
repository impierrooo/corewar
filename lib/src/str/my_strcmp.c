/*
** EPITECH PROJECT, 2023
** my str compare
** File description:
** compare 2 strings using ASCII table
** to ignore differences between uppercase and lowercase:
** ((letter_s2 >= 65 && letter_s2 <= 90) ? 32 : 0)
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (; *s1 && *s2 && (*s1 == *s2); s1++)
        ++s2;
    if (*s2 == '\0' || *s1 == '\0')
        return 0;
    return *s1 - *s2;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int j = 0; (s1[j] || s2[j]) && j < n; j++)
        if (s1[j] != s2[j])
            return (s1[j] - s2[j]);
    return 0;
}
