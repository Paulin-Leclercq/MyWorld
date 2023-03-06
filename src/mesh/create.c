/*
** EPITECH PROJECT, 2022
** create.c
** File description:
** create
*/

#include "world.h"

mesh_t *create_mesh(size_t nb_vertxs, vertex_t *mesh_vertxs,
size_t trig_size, ...)
{
    va_list list_arg;
    mesh_t *mesh = malloc(sizeof(mesh_t));

    va_start(list_arg, trig_size);
    if (mesh == NULL)
        return NULL;
    my_memset(mesh, 0, sizeof(mesh_t));
    mesh->nb_vertxs = nb_vertxs;
    mesh->vertxs = mesh_vertxs;
    mesh->trig_size = trig_size;
    mesh->trig = va_arg(list_arg, triangle_t *);
    mesh->is_selected = va_arg(list_arg, sfBool);
    va_end(list_arg);
    return mesh;
}
