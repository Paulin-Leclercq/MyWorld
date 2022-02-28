/*
** EPITECH PROJECT, 2022
** smooth.c
** File description:
** smooth
*/

#include "world.h"

sfBool is_out(size_t max, size_t size, long i, long j)
{
    if (size * i + j >= max && size * i + j > 0)
        return sfTrue;
    return sfFalse;
}

void smooth_point(mesh_t *mesh, size_t size, long line, long col)
{
    vertex_t *vertex = &mesh->vertxs[size * line + col];
    float mid = vertex->pos[1] * 4;
    size_t count = 4;

    for (long i = line - 1; i < line + 1; i++) {
        for (long j = col - 1; j < col + 1; j++) {
            !is_out(mesh->nb_vertxs, size, i, j) ? mid +=
            mesh->vertxs[size * i + j].pos[1], count++ : 0;
        }
    }
    mid /= count;
    vertex->pos[1] = mid;
}

void smooth(mesh_t *mesh, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++)
            smooth_point(mesh, size, i, j);
    }
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1; j++)
            change_color(mesh, size, i, j);
    }
}
