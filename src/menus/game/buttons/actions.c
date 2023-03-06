/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** actions.c
*/

#include "menus.h"

void save_game(void *w)
{
    window_t *win = w;
    game_t *g = win->menus[EDIT_MAP];

    if (g->has_saved)
        return;
    g->has_saved = (g->is_from_file ?
    save_from_file(g) : save_map(g, MAP_STRING, MAP_SIZE)) + 1;
    sfClock_restart(g->save_clock);
    if (win->next_state != EDIT_MAP)
        g->has_saved = 0;
    sfSprite_setTextureRect(g->save_sprite, save_rect[g->has_saved - 1]);
}

void add_hour(void *win)
{
    window_t *w = win;
    game_t *ga = w->menus[EDIT_MAP];

    rota_right(ga->world, ga->win);
}

void sub_hour(void *win)
{
    window_t *w = win;
    game_t *ga = w->menus[EDIT_MAP];

    rota_left(ga->world, ga->win);
}

void pause_game(void *win)
{
    window_t *w = win;
    game_t *ga = w->menus[EDIT_MAP];

    ga->win->params->pause = !ga->win->params->pause;
    sfSprite_setTextureRect(ga->gb->buttons[9]->sprite,
    gb_rects[9 + 4 * ga->win->params->pause]);
}
