/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** draw.c
*/

#include "world.h"

void add_color(int i, minimap_t *map, world_t *world)
{
    float direction = world->a_triangles[i].direction;

    map->tmp->color = world->a_triangles[i].color;
    map->tmp->color.r *= direction;
    map->tmp->color.g *= direction;
    map->tmp->color.b *= direction;
}

static void clear_mini(minimap_t *map,
sfBool draw_pos, world_t *world, int size)
{
    sfVertexArray_setPrimitiveType(map->array, sfTriangles);
    sfRenderTexture_drawVertexArray(map->rtex, map->array, 0);
    sfVertexArray_clear(map->array);
    if (!draw_pos)
        return;
    sfRenderTexture_drawSprite(map->rtex, map->vision, 0);
    if (map->is_circle)
        where_minimap(world, map, size);
    else
        where_minimap_square(world, map, size);
}

void draw_minimap(minimap_t *map, world_t *world, int size, sfBool draw_pos)
{
    float nb = map->size.y / (float)(size);
    get_player_pos(world);
    get_player_dir(world);
    sfSprite_setPosition(map->vision, (sfVector2f){world->p_pos[0] / 1.5 * nb
    , map->size.y - (world->p_pos[2] / 1.5 * nb)});
    sfSprite_setRotation(map->vision, world->p_dir[2] < 0 ? 180 : 0);
    sfSprite_rotate(map->vision, world->p_dir[0] *
    (world->p_dir[2] < 0 ? -90 : 90));
    for (int i = 0; i < size; i++)
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
    clear_mini(map, draw_pos, world, size);
}
