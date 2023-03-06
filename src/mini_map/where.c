/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** where.c
*/

#include "world.h"

void app_point(float x, float y, minimap_t *map)
{
    map->tmp->position = (sfVector2f){x, y};
    sfVertexArray_append(map->array, *map->tmp);
}

void where_minimap_square(world_t *world, minimap_t *map, long long size)
{
    float nb = map->size.y / (float)(size);
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

void where_minimap(world_t *world, minimap_t *map, long long size)
{
    float nb = map->size.y / (float)(size);
    int x = (int)(round(map->mouse_pos.x / nb));
    int y = (int)(round(map->mouse_pos.y / nb));
    float xx;
    float yy;

    sfCircleShape_setRadius(map->circle, map->s_br * nb);
    if (x < 0 || y < 0 || x > size || y > size)
        return;
    xx = world->a_vertxs[x * (size + 1) + y]->pos[0] / 1.5;
    yy = world->a_vertxs[x * (size + 1) + y]->pos[2] / 1.5;
    sfCircleShape_setPosition(map->circle, (sfVector2f)
    {(xx - map->s_br) * nb, (yy - map->s_br) * nb});
    sfRenderTexture_drawCircleShape(map->rtex, map->circle, 0);
}
