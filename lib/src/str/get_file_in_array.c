/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** get_file_in_array.c
*/

#include "my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>

static unsigned int get_nb_line(char *content)
{
    unsigned int result = 0;

    if (!content)
        return 0;
    for (int i = 0; content[i] != '\0'; i ++) {
        if (content[i] == '\n')
            result ++;
    }
    return result;
}

static unsigned int get_len_line(char *content, int start)
{
    int i = start;

    if (!content || start > my_strlen(content))
        return 0;
    while (content[i] != '\0') {
        if (content[i] == '\n')
            return i - start;
        i ++;
    }
    return (i - start);
}

char *get_file_in_string(char *filepath)
{
    struct stat sd;
    int fd;
    char *buffer;
    int size;

    fd = open(filepath, O_RDONLY);
    if (fd == -1 || stat(filepath, &sd) == -1)
        return NULL;
    size = sd.st_size;
    if (size == 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    return buffer;
}

char **get_file_in_str_array(char *filepath)
{
    char *content = get_file_in_string(filepath);
    int start = 0;
    int nb_line = get_nb_line(content);
    int len_line = 0;
    char **result;

    result = malloc(sizeof(char *) * (nb_line + 1));
    for (int i = 0; i < nb_line; i ++) {
        len_line = get_len_line(content, start);
        result[i] = malloc(sizeof(char) * (len_line + 1));
        for (int j = 0; j < len_line; j ++) {
            result[i][j] = content[start + j];
        }
        result[i][len_line] = '\0';
        start += get_len_line(content, start) + 1;
    }
    result[nb_line] = NULL;
    return result;
}
