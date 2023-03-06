/*
** EPITECH PROJECT, 2022
** Workshop3D v4.0
** File description:
** create
*/

#include "world.h"

float get_max_height(triangle_t trig)
{
    float max = trig.ptrs[0]->pos[1];

    for (int i = 1; i < 3; i++) {
        if (trig.ptrs[i]->pos[1] > max)
            max = trig.ptrs[i]->pos[1];
    }
    return max;
}

void change_color(mesh_t *mesh, size_t size, size_t i, size_t j)
{
    float height = get_max_height(mesh->trig[((size - 1) * i + j)]);

    if (height > 12)
        mesh->trig[((size - 1) * i + j)].color = sfWhite;
    if (height < -10)
        mesh->trig[((size - 1) * i + j)].color = sfBlue;
    height = get_max_height(mesh->trig[((size - 1) * i + j) +
    mesh->trig_size / 2]);
    if (height > 12)
        mesh->trig[((size - 1) * i + j) + mesh->trig_size / 2].color = sfWhite;
    if (height < -10)
        mesh->trig[((size - 1) * i + j) + mesh->trig_size / 2].color = sfBlue;
}

void add_map_trig(mesh_t *mesh, size_t size, triangle_t trig)
{
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1; j++) {
            trig.vertxs[0] = size * i + j;
            trig.vertxs[1] = size * i + j + 1;
            trig.vertxs[2] = size * (i + 1) + j;
            trig.ptrs[0] = &mesh->vertxs[size * i + j];
            trig.ptrs[1] = &mesh->vertxs[size * i + j + 1];
            trig.ptrs[2] = &mesh->vertxs[size * (i + 1) + j];
            mesh->trig[((size - 1) * i + j)] = trig;
            trig.vertxs[0] = size * (i + 1) + j;
            trig.vertxs[1] = size * i + j + 1;
            trig.vertxs[2] = size * (i + 1) + j + 1;
            trig.ptrs[0] = &mesh->vertxs[size * (i + 1) + j];
            trig.ptrs[1] = &mesh->vertxs[size * i + j + 1];
            trig.ptrs[2] = &mesh->vertxs[ size * (i + 1) + j + 1];
            mesh->trig[((size - 1) * i + j) + mesh->trig_size / 2] = trig;
        }
    }
}

void calculate_height(vertex_t *vertex, size_t i, size_t j)
{
    vertex->pos[0] = i * 1.5;
    vertex->pos[1] = 0;
    for (int height = 0; height < 7; height++) {
        vertex->pos[1] +=
        apply_perlin((float)(i * 1.5) / (1.1 * pow(2, height)),
        (float)(j * 1.5) / (1.1 * pow(2, height))) * pow(2, height);
    }
    vertex->pos[2] = j * 1.5;
}

void create_map(world_t *world, size_t size)
{
    vertex_t vertex;
    triangle_t trig;
    mesh_t *mesh = malloc(sizeof(mesh_t));
    trig.mesh_ptr = mesh;
    trig.color = sfGreen;
    mesh->is_selected = 0;
    mesh->nb_vertxs = size * size;
    mesh->trig_size = (size - 1) * (size - 1) * 2;
    mesh->vertxs = malloc(sizeof(vertex_t) * mesh->nb_vertxs);
    mesh->trig = malloc(sizeof(triangle_t) * mesh->trig_size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            calculate_height(&vertex, i, j);
            mesh->vertxs[size * i + j] = vertex;
        }
    }
    add_map_trig(mesh, size, trig);
    smooth(mesh, size);
    add_mesh(world, mesh);
    add_background(world);
}
