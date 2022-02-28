/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "world.h"
#include "menus.h"

void save_map(game_t *game, const char* filename, unsigned int size)
{
    world_t *world = game->world;
    char *map = malloc(sizeof(char) * 8);
    int fd = 0;
    strcpy(map, "./map/");
    fd = open(str_concat(2, map, filename), O_WRONLY | O_CREAT | O_TRUNC
    , ALL_FLAGS);
    write(fd, &size, sizeof(unsigned int));
    for (unsigned int i = 0; i < (size) * (size); i++)
        write(fd, &(world->a_vertxs[i]->pos[1]), sizeof(float));
}

unsigned int read_map(game_t *game, const char* filename)
{
    unsigned int size;
    world_t *world = game->world;
    char *map = malloc(sizeof(char) * 8);
    int fd = 0;
    strcpy(map, "./map/");
    fd = open(str_concat(2, map, filename), O_RDONLY);
    read(fd, &size, sizeof(unsigned int));
    create_map(world, size);
    set_light_source(world, size / 2.0, 1, 1000);
    convert_to_array(world);
    for (unsigned int i = 0; i < (size) * (size); i++)
        read(fd, &(world->a_vertxs[i]->pos[1]), sizeof(float));
    return size;
}