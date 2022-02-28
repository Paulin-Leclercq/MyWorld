/*
** EPITECH PROJECT, 2022
** Workshop3D v4.0
** File description:
** convert
*/

#include "world.h"

void convert_to_array(world_t *world)
{
    list_t *tmp = *world->vertxs;

    world->projected = malloc(sizeof(vertex_t) * world->nb_vertxs);
    world->a_vertxs = malloc(sizeof(vertex_t *) * world->nb_vertxs);
    world->a_triangles = malloc(sizeof(triangle_t) * world->nb_trig);
    for (size_t i = 0; i < world->nb_vertxs; i++, tmp = tmp->next) {
        world->a_vertxs[i] = tmp->data;
        if (world->a_vertxs[i]->pos[1] < -10)
            world->a_vertxs[i]->pos[1] = -10;
    }
    tmp = *world->triangles;
    for (size_t i = 0; i < world->nb_trig; i++, tmp = tmp->next)
        world->a_triangles[i] = *(triangle_t *)tmp->data;
}
