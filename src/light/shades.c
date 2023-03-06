/*
** EPITECH PROJECT, 2022
** Workshop3D v3.0
** File description:
** shades
*/

#include "world.h"

float calculate_shades(float vecs[2][3], float *light, vertex_t *vertxs)
{
    float direction;
    float normale[3];
    float light_dir[3] = {
    light[0] - (vertxs[0].pos[0] + vertxs[1].pos[0] + vertxs[2].pos[0]) * 0.33,
    light[1] - (vertxs[0].pos[1] + vertxs[1].pos[1] + vertxs[2].pos[1]) * 0.33,
    light[2] -
    (vertxs[0].pos[2] + vertxs[1].pos[2] + vertxs[2].pos[2]) * 0.33};

    crossproduct3(normale, vecs[0], vecs[1]);
    normalize(normale);
    normalize(light_dir);
    direction = dotproduct3(normale, light_dir);
    if (direction < 0)
        direction = 0;
    return direction;
}

float apply_shades(world_t *world, triangle_t *tri)
{
    vertex_t vertxs[3] = {*tri->ptrs[0], *tri->ptrs[1], *tri->ptrs[2]};
    float vecs[2][3] = {
    {vertxs[0].pos[0] - vertxs[1].pos[0],
    vertxs[0].pos[1] - vertxs[1].pos[1],
    vertxs[0].pos[2] - vertxs[1].pos[2]},
    {vertxs[0].pos[0] - vertxs[2].pos[0],
    vertxs[0].pos[1] - vertxs[2].pos[1],
    vertxs[0].pos[2] - vertxs[2].pos[2]}};

    tri->direction = calculate_shades(vecs, world->light_source, vertxs);
    return tri->direction;
}
