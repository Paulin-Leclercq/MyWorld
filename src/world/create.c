/*
** EPITECH PROJECT, 2022
** create.c
** File description:
** create
*/

#include "world.h"

void free_mesh(void *value)
{
    mesh_t *mesh = value;

    free(mesh->vertxs);
    free(mesh->trig);
    free(mesh);
}

void destroy_world(world_t *world)
{
    free(world->matrix);
    sfClock_destroy(world->clock);
    free(world->light_start);
    free(world->light_source);
    free(world);
}

void set_light_source(world_t *world, float x, float y, float z)
{
    world->light_start[0] = x;
    world->light_start[1] = y;
    world->light_start[2] = z;
    world->light_source[0] = x;
    world->light_source[1] = y;
    world->light_source[2] = z;
}

void add_mesh(world_t *world, mesh_t *mesh)
{
    triangle_t *tmp_trig;

    tmp_trig = mesh->trig;
    append_node(world->meshes, mesh);
    for (size_t i = 0; i < mesh->trig_size; i++) {
        tmp_trig[i].vertxs[0] += world->nb_vertxs;
        tmp_trig[i].vertxs[1] += world->nb_vertxs;
        tmp_trig[i].vertxs[2] += world->nb_vertxs;
    }
    for (size_t i = 0; i < mesh->nb_vertxs; i++)
        append_node(world->vertxs, &mesh->vertxs[i]);
    for (size_t i = 0; i < mesh->trig_size; i++)
        append_node(world->triangles, &tmp_trig[i]);
    world->nb_meshes++;
    world->nb_vertxs += mesh->nb_vertxs;
    world->nb_trig += mesh->trig_size;
}

world_t *create_world()
{
    world_t *world = malloc(sizeof(world_t));
    if (world == NULL)
        return NULL;
    world->nb_meshes = 0;
    world->nb_vertxs = 0;
    world->nb_trig = 0;
    world->meshes = malloc(sizeof(list_t *));
    *world->meshes = NULL;
    world->vertxs = malloc(sizeof(list_t *));
    *world->vertxs = NULL;
    world->triangles = malloc(sizeof(list_t *));
    *world->triangles = NULL;
    world->light_start = malloc(sizeof(float) * 3);
    world->light_source = malloc(sizeof(float) * 3);
    world->matrix = mat4x4_ry(PI);
    world->clock = sfClock_create();
    world->destroy = destroy_world;
    if (world->matrix == NULL)
        return NULL;
    return world;
}
