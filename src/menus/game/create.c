/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create.c
*/

#include "menus.h"

void draw_world(game_t *g)
{
    sfSprite *s;

    draw_meshes(g->world, g->win);
    draw_fps(g->win);
    sfRenderTexture_display(g->win->r_tex);
    s = init_sprite_from_texture(sfRenderTexture_getTexture(g->win->r_tex));
    sfSprite_setPosition(s, (sfVector2f){g->size.y * PART_OF_MINIMAP, 0});
    sfRenderTexture_drawSprite(g->rtex, s, NULL);
    sfSprite_destroy(s);
    sfRenderTexture_clear(g->win->r_tex, sfBlack);
}

void draw_minimap_to_game(game_t *g)
{
    sfSprite *s;

    draw_minimap(g->minimap, g->world, g->dimension - 1);
    s = init_sprite_from_texture(sfRenderTexture_getTexture(g->minimap->rtex));
    sfSprite_scale(s, (sfVector2f){1, -1});
    sfSprite_setPosition(s, (sfVector2f){0, g->size.y * PART_OF_MINIMAP});
    sfRenderTexture_drawSprite(g->rtex, s, NULL);
    sfSprite_destroy(s);
    sfRenderTexture_clear(g->minimap->rtex, sfBlack);
}

const sfTexture *draw_game(void *game)
{
    game_t *g = game;

    sfRenderTexture_clear(g->rtex, sfBlack);
    draw_world(g);
    draw_minimap_to_game(g);
    sfRenderTexture_display(g->rtex);
    return sfRenderTexture_getTexture(g->rtex);
}

game_t *create_game(unsigned size, sfVector2f win_size)
{
    game_t *g = malloc(sizeof(game_t));
    world_t *world;

    size++;
    g->rtex = sfRenderTexture_create(win_size.x, win_size.y, 0);
    g->world = create_world();
    world = g->world;
    create_map(world, size);
    set_light_source(world, size / 2.0, 1, 1000);
    convert_to_array(world);
    world->sortBuffer = malloc(sizeof(vecsort_t) * world->nb_trig);
    world->sortBuffer2 = malloc(sizeof(vecsort_t) * world->nb_trig);
    g->win = win_create(world->nb_trig,
    (sfVector2f){win_size.x - win_size.y * PART_OF_MINIMAP, win_size.y});
    g->win->map_size = size;
    free_lists(world);
    g->size = win_size;
    g->minimap = create_minimap((sfVector2f)
    {win_size.y * PART_OF_MINIMAP, win_size.y * PART_OF_MINIMAP}, size);
    g->dimension = size;
    return g;
}
