/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** is_champion_path.c
*/

#include "project.h"
#include <fcntl.h>
#include <unistd.h>

int is_champion_path(char *path)
{
    int fd = 0;
    header_t header;

    if (!is_existing_file(path))
        return HEADER_ERROR;
    fd = open(path, O_RDONLY);
    if (read(fd, &header, sizeof(header_t)) == -1) {
        my_putstr_error("Couldn't read file.\n");
        close(fd);
        return HEADER_ERROR;
    }
    close(fd);
    header.magic = my_htobe(header.magic);
    header.prog_size = my_htobe(header.prog_size);
    if (header.magic != COREWAR_EXEC_MAGIC)
        return HEADER_ERROR;
    return 1;
}
