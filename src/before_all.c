/*
** EPITECH PROJECT, 2019
** before_all.c
** File description:
** Sokoban
*/

#include "my.h"
#include "check_char.h"

__attribute__((constructor)) void before_all(int ac, char **av)
{
    if (ac != 2)
        exit(84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        usage();
        exit(0);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == - 1)
        exit(84);
    stat(av[1], &sb);
    if (sb.st_size == 0)
        exit(84);
    buffer = malloc(sb.st_size + 1);
    buffer[sb.st_size] = '\0';
    read(fd, buffer, sb.st_size + 1);
    close(fd);
    for (int i = 0; buffer[i]; i++) {
        if (CHECK_CHAR(buffer[i]))
            exit(84);
    }
}
