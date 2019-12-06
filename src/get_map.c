/*
** EPITECH PROJECT, 2019
** get_map
** File description:
** get_map func
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

long long get_byte_size(char const *filepath)
{
    struct stat *stat_buf = malloc(sizeof(struct stat));
    long long size;

    if (stat(filepath, stat_buf) == 0) {
        size = stat_buf->st_size;
    }
    free(stat_buf);
    return (size);
}

int get_width(char const *map)
{
    int i = -1;

    while (map[++i] != '\n');
    return (i);
}

int get_height(char const *map)
{
    int i = -1;
    int j = 0;

    while (map[++i] != '\0') {
        if (map[i] == '\n')
            j++;
    }
    return (j);
}

char *read_map(char const *filepath, long long size)
{
    char *buffer = malloc(size + 1);
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}