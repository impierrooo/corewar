/*
** EPITECH PROJECT, 2023
** my sort int array
** File description:
** sorts an integer array in ascending order
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            my_swap(&array[j], &array[j + 1]);
        }
    }
}
