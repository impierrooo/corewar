/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_header.c
*/

#include "project.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static
int check_header_infos(header_t *header)
{
    if (header->magic != COREWAR_EXEC_MAGIC) {
        my_putstr_error("Wrong magic number.\n");
        return 84;
    }
    return 0;
}

header_t *get_header(char *filename)
{
    int fd = open(filename, O_RDONLY);
    header_t *header = malloc(sizeof(header_t));

    if (fd == -1) {
        my_putstr_error("Couldn't open file.\n");
        return NULL;
    }
    if (read(fd, header, sizeof(header_t)) == -1) {
        my_putstr_error("Couldn't read file.\n");
        close(fd);
        return NULL;
    }
    close(fd);
    header->magic = my_htobe(header->magic);
    header->prog_size = my_htobe(header->prog_size);
    if (check_header_infos(header) != 0)
        return NULL;
    return header;
}
