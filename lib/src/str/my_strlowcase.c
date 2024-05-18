/*
** EPITECH PROJECT, 2023
** str low case
** File description:
** puts every letter of every word in it in lowercase.
*/

static void my_charlowcase(char *ptr)
{
    if (*ptr != '\0')
        if (*ptr >= 65 && *ptr <= 90)
            *ptr += 32;
}

char *my_strlowcase(char *str)
{
    if (*str >= 65 && *str <= 90)
        *str += 32;
    for (char *ptr = str; *ptr != '\0'; ptr++)
        my_charlowcase(ptr);
    return str;
}
