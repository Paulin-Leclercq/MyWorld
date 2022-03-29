/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** draw.c
*/

#include "menus.h"

void draw_has_saved(game_t *g)
{
    if (sfClock_getElapsedTime(g->save_clock).microseconds > SAVE_MAX_TIME) {
        g->has_saved = 0;
        return;
    }
    sfRenderTexture_drawSprite(g->rtex, g->save_sprite, NULL);
}

void draw_world(game_t *g, int is_fullscreen)
{
    sfSprite *s;

    draw_back(g->world, g->win);
    draw_meshes(g->world, g->win);
    draw_fps(g->win);
    sfRenderTexture_display(g->win->r_tex);
    s = init_sprite_from_texture(sfRenderTexture_getTexture(g->win->r_tex));
    if (!is_fullscreen)
        sfSprite_setPosition(s, (sfVector2f){g->size.y * PART_OF_MINIMAP, 0});
    sfRenderTexture_drawSprite(g->rtex, s, NULL);
    sfSprite_destroy(s);
    sfRenderTexture_clear(g->win->r_tex, sfBlack);
}

void draw_minimap_to_game(game_t *g)
{
    sfSprite *s;

    sfRenderTexture_clear(g->minimap->rtex, sfBlack);
    draw_minimap(g->minimap, g->world, g->dimension - 1, 1);
    sfRenderTexture_display(g->minimap->rtex);
    s = init_sprite_from_texture(sfRenderTexture_getTexture(g->minimap->rtex));
    sfRenderTexture_drawSprite(g->rtex, s, NULL);
    sfSprite_destroy(s);
}

void draw_gb_to_rtex(game_t *g)
{
    sfSprite *s = draw_gb(g);

    sfSprite_setPosition(s, (sfVector2f){0, g->size.y * PART_OF_MINIMAP});
    sfRenderTexture_drawSprite(g->rtex, s, NULL);
    sfSprite_destroy(s);
    if (g->gb->tool_tip_enabled)
        draw_tooltip(g, g->rtex);
}

const sfTexture *draw_game(window_t *win)
{
    game_t *g = win->menus[EDIT_MAP];

    sfRenderTexture_clear(g->rtex, sfBlack);
    draw_world(g, win->is_fullscreen);
    if (!win->is_fullscreen) {
        draw_minimap_to_game(g);
        draw_gb_to_rtex(g);
    }
    if (g->has_saved)
        draw_has_saved(g);
    if (g->gb->is_help)
        sfRenderTexture_drawSprite(g->rtex, g->how_to_play, NULL);
    sfRenderTexture_display(g->rtex);
    return sfRenderTexture_getTexture(g->rtex);
}
