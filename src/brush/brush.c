/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "world.h"

#define P_HEIGT(world, i, size) world->a_vertxs \
[i * (size) + (size - j)]->pos[1]

void average_br_next(world_t *world, minimap_t *map, int tmp)
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
            > -10) ? (P_HEIGT(world, i, size) = (P_HEIGT(world, i, size) + tmp)
            / 2): 0;
        }
    }
}

void average_br(world_t *world, minimap_t *map)
{
    float nb = map->size.y / (float)(map->map_size);
    int size = map->map_size;
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));
    int tmp = 0;
    int count = 0;
    if (x < 0 || y < 0 || x > size || y > size)
        return;
    for (int i = x - map->s_br; i < x + map->s_br; i++) {
        if (i < 0 || i >= size)
            continue;
        for (int j = y - map->s_br; j < y + map->s_br; j++) {
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            > -10) ? tmp += P_HEIGT(world, i, size), count++: 0;
        }
    }
    if (count == 0)
        return;
    tmp /= count;
    average_br_next(world, map, tmp);
}

void average_w_br_next(world_t *world, minimap_t *map, int tmp)
{
    float nb = map->size.y / (float)(map->map_size);
    int size = map->map_size;
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));

    for (int i = x - map->s_br; i < x + map->s_br; i++) {
        if (i < 0 || i >= size)
            continue;
        for (int j = y - map->s_br; j < y + map->s_br; j++) {
            ((size - j) >= 0 && (size - j) < (size)) ?
            (P_HEIGT(world, i, size) = (P_HEIGT(world, i, size) + tmp) / 2): 0;
        }
    }
}

void average_w_br(world_t *world, minimap_t *map)
{
    float nb = map->size.y / (float)(map->map_size);
    int size = map->map_size;
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));
    int tmp = 0;
    int count = 0;
    if (x < 0 || y < 0 || x > size || y > size)
        return;
    for (int i = x - map->s_br; i < x + map->s_br; i++) {
        if (i < 0 || i >= size)
            continue;
        for (int j = y - map->s_br; j < y + map->s_br; j++) {
            ((size - j) >= 0 && (size - j) < (size)) ?
            tmp += P_HEIGT(world, i, size), count++ : 0;
        }
    }
    if (count == 0)
        return;
    tmp /= count;
    average_w_br_next(world, map, tmp);
}
