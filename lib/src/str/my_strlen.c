/*
** EPITECH PROJECT, 2023
** my strlen
** File description:
** return the lenght of a string
*/

int my_strlen(char const *str)
{
    int length = 0;

    if (!str)
        return 0;
    while (str[length] != '\0') {
        length += 1;
    }
    return length;
}
