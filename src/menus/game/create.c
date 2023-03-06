/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create.c
*/

#include "menus.h"

void destroy_game_struct(game_t *game)
{
    destroy_gbuttons(game->gb);
    destroy_minimap(game->minimap);
    sfRenderTexture_destroy(game->rtex);
    sfSprite_destroy(game->how_to_play);
    game->world->destroy(game->world);
    game->win->destroy(game->win);
    game->win = 0;
    game->world = 0;
    sfClock_destroy(game->save_clock);
    sfSprite_destroy(game->save_sprite);
    free(game);
}

void create_other(game_t *g, unsigned size, sfVector2f win_size)
{
    g->size = win_size;
    g->on_help = false;
    g->minimap = create_minimap((sfVector2f){win_size.y * PART_OF_MINIMAP,
    win_size.y * PART_OF_MINIMAP}, size);
    g->dimension = size;
    g->gb = create_buttons((sfVector2f){win_size.y * PART_OF_MINIMAP,
    win_size.y * (1 - PART_OF_MINIMAP)});
    g->how_to_play = init_sprite(global_texture(), vomi_rect,
    (sfVector2f){win_size.x * 0.7, win_size.x * 0.7 / 1.45698924731});
    center_sprite(g->how_to_play);
    sfSprite_setPosition(g->how_to_play,
    (sfVector2f){win_size.x / 2.0, win_size.y / 2.0});
}

void start_world(game_t *g)
{
    world_t *world;
    sfVector2f win_size = g->size;

    get_gradient(1);
    g->world = create_world();
    g->gb->is_help = false;
    world = g->world;
    create_map(world, g->dimension);
    set_light_source(world, g->dimension / 2.0, 1, 1000);
    convert_to_array(world);
    world->sortBuffer = malloc(sizeof(vecsort_t) * world->nb_trig);
    world->sortBuffer2 = malloc(sizeof(vecsort_t) * world->nb_trig);
    g->win = win_create(world->nb_trig,
    (sfVector2f){win_size.x - win_size.y * PART_OF_MINIMAP, win_size.y});
    g->win->map_size = g->dimension;
    smooth_shadow(world, g->win);
    sfVertexArray_setPrimitiveType(g->win->array, sfTriangles);
    free_lists(world);
}

void set_volume(game_t *g, settings_t *se)
{
    update_vol(se->music_vol, se->sfx_vol, "ms",
    g->win->musics[0], g->win->sounds[0]);
}

game_t *create_game(unsigned size, sfVector2f win_size,
int is_selected, settings_t *se)
{
    game_t *g = malloc(sizeof(game_t));
    create_other(g, size, win_size);
    size++;
    g->rtex = sfRenderTexture_create(win_size.x, win_size.y, 0);
    start_world(g);
    g->is_selected = is_selected;
    g->is_from_file = 0;
    g->has_saved = 0;
    g->save_clock = sfClock_create();
    g->save_sprite = sfSprite_create();
    sfSprite_setTexture(g->save_sprite, global_texture(), 0);
    sfSprite_setTextureRect(g->save_sprite, save_rect[0]);
    sfSprite_setPosition(g->save_sprite,
    (sfVector2f){win_size.y * 0.65, win_size.y * 0.05});
    set_sprite_size(g->save_sprite,
    (sfVector2f){win_size.x * 0.35, win_size.x * 0.35 * 0.16987179487});
    set_volume(g, se);
    return g;
}
