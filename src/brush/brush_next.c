/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "world.h"

void update_color(world_t *world)
{
    float height;

    for (size_t i = 0; i < world->nb_trig; i++) {
        height = get_max_height(world->a_triangles[i]);
        if (height > 12)
            world->a_triangles[i].color = sfWhite;
        if (height <= -10)
            world->a_triangles[i].color = sfBlue;
        if (height <= 12 && height > -10)
            world->a_triangles[i].color = sfGreen;
    }
}

void up_br(world_t *world, minimap_t *map, int (*comp)(int, int, int))
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
            < 80) && comp(i - x, j - y, map->s_br) ?
            world->a_vertxs[i * (size) + (size - j)]->pos[1] += BRUSH_DIR : 0;
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            > 80) ? P_HEIGT(world, i, size) = 80 : 0;
        }
    }
}

void down_br(world_t *world, minimap_t *map, int (*comp)(int, int, int))
{
    float nb = map->size.y / (float)(map->map_size);
    int size = (int)map->map_size;
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb)) + 1;
    if (x < 0 || y < 0 || x > size || y > size)
        return;
    for (int i = x - map->s_br; i < x + map->s_br; i++) {
        if (i < 0 || i >= size)
            continue;
        for (int j = y - map->s_br; j < y + map->s_br; j++) {
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            > -10) && comp(i - x, j - y, map->s_br) ?
            P_HEIGT(world, i, size) -= BRUSH_DIR : 0;
            ((size - j) >= 0 && (size - j) < (size) && P_HEIGT(world, i, size)
            < -10) ? P_HEIGT(world, i, size) = -10 : 0;
        }
    }
}

void average_d_br_next(world_t *world, minimap_t *map,
int tmp, int (*comp)(int, int, int))
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
            > -10) && comp(i - x, j - y, map->s_br) ?
            (P_HEIGT(world, i, size) = (P_HEIGT(world, i, size) * 10 + tmp)
            / 11) : 0;
        }
    }
}

void average_d_br(world_t *world, minimap_t *map, int (*comp)(int, int, int))
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
            > -10 && P_HEIGT(world, i, size) < tmp) &&
            comp(i - x, j - y, map->s_br) ?
            tmp = P_HEIGT(world, i, size) : 0;
        }
    }
    average_d_br_next(world, map, tmp, comp);
}
