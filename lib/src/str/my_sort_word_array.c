/*
** EPITECH PROJECT, 2023
** my sort word array
** File description:
** sorts a word array
*/

#include "my.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int swap(char **arr, int j)
{
    char *temp = arr[j];

    if (my_strcmp(arr[j], arr[j + 1]) > 0) {
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        return 1;
    }
    return 0;
}

void my_sort_word_array(char **arr, int size)
{
    int n = size;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            swap(arr, j);
        }
    }
}
