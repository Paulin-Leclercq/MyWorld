/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "world.h"

#define P_HEIGT(world, i, size) world->a_vertxs \
[i * (size) + (size - j)]->pos[1]

void update_color(world_t *world)
{
    float height;

    for (size_t i = 0; i < world->nb_trig; i++) {
        height = get_max_height(world->a_triangles[i]);
        if (height > 12)
            world->a_triangles[i].color = sfWhite;
        else if (height <= -10)
            world->a_triangles[i].color = sfBlue;
        else
            world->a_triangles[i].color = sfGreen;
    }
}

void up_br(world_t *world, minimap_t *map)
{
    float nb = map->size.y / (float)(map->map_size);
    int size = map->map_size;
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));
    if (x < 0 || y < 0 || x > size || y > size)
        return;
    for (int i = x - map->s_br; i < x + map->s_br; i++) {
        if (i < 0 || i >= size)
            continue;
        for (int j = y - map->s_br; j < y + map->s_br; j++) {
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            < 40) ? world->a_vertxs[i * (size) + (size - j)]->pos[1] += 1 : 0;
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            > 40) ? P_HEIGT(world, i, size) = 40 : 0;
        }
    }
}

void down_br(world_t *world, minimap_t *map)
{
    float nb = map->size.y / (float)(map->map_size);
    int size = (int)map->map_size;
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));
    if (x < 0 || y < 0 || x > size || y > size)
        return;
    for (int i = x - map->s_br; i < x + map->s_br; i++) {
        if (i < 0 || i >= size)
            continue;
        for (int j = y - map->s_br; j < y + map->s_br; j++) {
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            > -10) ? P_HEIGT(world, i, size) -= 1 : 0;
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            < -10) ? P_HEIGT(world, i, size) = -10 : 0;
        }
    }
}

void average_d_br_next(world_t *world, minimap_t *map, int tmp)
{

    float nb = map->size.y / (float)(map->map_size);
    int size = map->map_size;
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));
    for (int i = x - map->s_br; i < x + map->s_br; i++) {
        if (i < 0 || i >= size)
            continue;
        for (int j = y - map->s_br; j < y + map->s_br; j++) {
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            > -10) ?
            (P_HEIGT(world, i, size) = (P_HEIGT(world, i, size) + tmp) / 2): 0;
        }
    }
}

void average_d_br(world_t *world, minimap_t *map)
{
    float nb = map->size.y / (float)(map->map_size);
    int size = map->map_size;
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));
    int tmp = 41;
    if (x < 0 || y < 0 || x > size || y > size)
        return;
    for (int i = x - map->s_br; i < x + map->s_br; i++) {
        if (i < 0 || i >= size)
            continue;
        for (int j = y - map->s_br; j < y + map->s_br; j++) {
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            > -10 && P_HEIGT(world, i, size) < tmp) ?
            tmp = P_HEIGT(world, i, size): 0;
        }
    }
    average_d_br_next(world, map, tmp);
}
