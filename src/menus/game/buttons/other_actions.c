/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** other_actions.c
*/

#include "menus.h"

void restart_map(void *win)
{
    window_t *w = win;
    game_t *g = w->menus[EDIT_MAP];

    refresh_map(g);
}

void create_tooltip(game_buttons_t *g, sfVector2f tex_size)
{
    g->tooltip = init_text("", tex_size.y * 0.075);
    sfText_setColor(g->tooltip, sfBlack);
    g->tooltip_box = create_rectangle((sfVector2f){1, 1}, sfYellow, NULL);
    g->tool_tip_enabled = false;
}

void get_help(void *win)
{
    window_t *w = win;
    game_t *g = w->menus[EDIT_MAP];

    g->gb->is_help = !g->gb->is_help;
    g->on_help = true;
}

void quit_game(void *win)
{
    set_next_win_state(win, HOME);
}

void switch_brush_type(void *win)
{
    window_t *w = win;
    game_t *g = w->menus[EDIT_MAP];
    minimap_t *mini = g->minimap;

    sfSprite_setTextureRect(g->gb->buttons[5]->sprite,
    gb_rects[5 + 9 * mini->is_circle]);
    mini->is_circle = !mini->is_circle;
}
