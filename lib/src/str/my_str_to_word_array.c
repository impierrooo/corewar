/*
** EPITECH PROJECT, 2023
** my str to word array
** File description:
** transforms a string in an array
** arythmétique des pointeurs et "slices"
*/

#include "my.h"
#include <stdlib.h>

static int get_nbr_words(char *str, char *separator)
{
    int result = 0;
    int i = 1;

    while (i < my_strlen(str)) {
        result += is_in(str[i], separator);
        i ++;
    }
    if (is_in(str[i], separator))
        return result;
    return result + 1;
}

static int get_size(char *str, char sep)
{
    int i = 0;

    for (; str[i] != sep && str[i] != '\n'; i++);
    if (i == 0 && str[i] != '\0' && str[i] != '\n')
        return get_size(str + 1, sep) + 1;
    return i;
}

static int get_word_size(char *str, char *separator)
{
    int i = 0;

    while (str[i] && str[i] != '\0' && !is_in(str[i], separator)) {
        i ++;
    }
    return i;
}

char **my_str_to_word_array(char *str, char *separators)
{
    int decal = 0;
    int word_size = 0;
    int size = get_nbr_words(str, separators);
    char **dest = malloc(sizeof(char *) * (size + 1));

    if (dest == NULL || !str)
        return NULL;
    for (int j = 0; str[j] && decal < size - 1; j += word_size + 1) {
        word_size = get_word_size(str + j, separators);
        if (word_size == 0)
            continue;
        dest[decal] = my_strndup(str + j, word_size);
        decal ++;
    }
    if (size == 1)
        dest[0] = my_strdup(str);
    dest[size] = NULL;
    return dest;
}

char **str_to_arr(char *str, char sep)
{
    int decal = 0;
    int j = 0;
    int size = get_nbr_words(str, " \n");
    char **dest = malloc(sizeof(char *) * (size + 1));

    while (decal < size - 1 && str[j] != '\n' &&
    (str[j] != '#' && str[j + 1] != '#')) {
        dest[decal] = my_strndup(str + j, get_size(str + j, sep));
        j += get_size(str + j, sep) + 1;
        decal ++;
    }
    dest[size] = NULL;
    return dest;
}
