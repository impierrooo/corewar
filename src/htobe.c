/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** htobe.c
*/

int my_htobe(int num)
{
    int swapped = ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) |
    ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);

    return swapped;
}
