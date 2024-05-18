/*
** EPITECH PROJECT, 2023
** my swap
** File description:
** swap the content of two integer
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
