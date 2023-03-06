/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "world.h"

void free_lists(world_t *world)
{
    for (size_t i = 0; i < world->nb_meshes; i++)
        remove_node(world->meshes, 0, free);
    for (size_t i = 0; i < world->nb_vertxs; i++)
        remove_node(world->vertxs, 0, 0);
    for (size_t i = 0; i < world->nb_trig; i++)
        remove_node(world->triangles, 0, i ? 0 : free);
    free(world->meshes);
    free(world->vertxs);
    free(world->triangles);
}
