/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** save_from_file.c
*/

#include "menus.h"

unsigned map_size_from_file(char const *file)
{
    char const *str = file;
    int fd = open(str, O_RDONLY);
    unsigned size = 64;

    if (fd >= 0)
        read(fd, &size, sizeof(unsigned));
    close(fd);
    return size;
}

int save_from_file(game_t *g)
{
    int fd = open(g->file, O_WRONLY | O_TRUNC);
    world_t *world = g->world;
    unsigned size = g->win->map_size;
    unsigned s = size * size;

    if (fd < 0)
        return 0;
    write(fd, &size, sizeof(unsigned int));
    for (unsigned long i = 0; i < s; i++)
        write(fd, &(world->a_vertxs[i]->pos[1]), sizeof(float));
    close(fd);
    return 1;
}

int load_game_from_file(game_t *g, const char *filename)
{
    unsigned int size;
    world_t *world = g->world;
    char const *path = filename;
    int fd = open(path, O_RDONLY);
    unsigned long s;

    read(fd, &size, sizeof(unsigned int));
    g->win->map_size = size;
    g->minimap->map_size = size;
    s = size * size;
    for (unsigned long i = 0; i < s; i++)
        read(fd, &(world->a_vertxs[i]->pos[1]), sizeof(float));
    close(fd);
    g->is_from_file = 1;
    g->file = (char *)filename;
    return size;
}
