/*
** EPITECH PROJECT, 2023
** my str upcase
** File description:
** puts every letter of every word in it in uppercase
*/

static void my_charcapitalize(char *ptr)
{
    if (*ptr != '\0')
        if (*ptr >= 97 && *ptr <= 122)
            *ptr -= 32;
}

char *my_strupcase(char *str)
{
    if (*str >= 97 && *str <= 122)
        *str -= 32;
    for (char *ptr = str; *ptr != '\0'; ptr++)
        my_charcapitalize(ptr);
    return str;
}
