/*
** EPITECH PROJECT, 2023
** radar
** File description:
** is_existing file.c
*/

#include "my.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int is_existing_file(char *filepath)
{
    struct stat sd;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return 0;
    close(fd);
    if (stat(filepath, &sd) == -1)
        return 0;
    if (sd.st_size == 0)
        return 0;
    return 1;
}
