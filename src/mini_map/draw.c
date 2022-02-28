/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** draw.c
*/

#include "world.h"

void app_point(float x, float y, minimap_t *map)
{
    map->tmp->position = (sfVector2f){x, y};
    sfVertexArray_append(map->array, *map->tmp);
}

void where_minimap(world_t *world, minimap_t *map, long long size)
{
    float nb = height / (float)(size);
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));
    float xx;
    float yy;
    if (x < 0 || y < 0 || x > size || y > size)
        return;
    xx = world->a_vertxs[x * (size + 1) + y]->pos[0] / 1.5;
    yy = world->a_vertxs[x * (size + 1) + y]->pos[2] / 1.5;
    map->tmp->color = sfWhite;
    app_point((xx - map->s_br) * nb, (yy + map->s_br) * nb, map);
    app_point((xx - map->s_br) * nb, (yy - map->s_br) * nb, map);
    app_point((xx + map->s_br) * nb, (yy - map->s_br) * nb, map);
    app_point((xx + map->s_br) * nb, (yy + map->s_br) * nb, map);
    app_point((xx - map->s_br) * nb, (yy + map->s_br) * nb, map);
    sfVertexArray_setPrimitiveType(map->array, sfLinesStrip);
    sfRenderTexture_drawVertexArray(map->rtex, map->array, 0);
    sfVertexArray_clear(map->array);
}

void add_color(int i, minimap_t *map, world_t *world)
{
    float direction = world->a_triangles[i].direction;

    map->tmp->color = world->a_triangles[i].color;
    map->tmp->color.r *= direction;
    map->tmp->color.g *= direction;
    map->tmp->color.b *= direction;
}

void draw_minimap(minimap_t *map, world_t *world, int size)
{
    float nb = map->size.y / (float)(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            add_color(i * size + j, map, world);
            app_point(nb * i, nb * (size - j - 1), map);
            app_point(nb * (i + 1), nb * (size - j - 1), map);
            app_point(nb * i, nb * (size - j), map);
            add_color(i * size + j + size * size, map, world);
            app_point(nb * (i + 1), nb * (size - j), map);
            app_point(nb * (i + 1), nb * (size - j - 1), map);
            app_point(nb * i, nb * (size - j), map);
        }
    }
    sfVertexArray_setPrimitiveType(map->array, sfTriangles);
    sfRenderTexture_drawVertexArray(map->rtex, map->array, 0);
    sfVertexArray_clear(map->array);
    where_minimap(world, map, size);
}
