/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** events.c
*/

#include "menus.h"

void check_tool_bar_key(int code, window_t *win)
{
    game_t *ga = win->menus[EDIT_MAP];

    if (code == sfKeyT)
        switch_brush_type(win);
    if (code >= sfKeyNum1 && code <= sfKeyNum5) {
        ga->gb->selected = code - sfKeyNum1;
        ga->minimap->state = ga->gb->selected;
    } else if (code == sfKeyQuote) {
        ga->gb->selected = 3;
        ga->minimap->state = 3;
    }
}

void world_events(game_t *g, sfEvent ev, window_t *win)
{
    g->win->event = ev;
    if (ev.type == sfEvtMouseWheelScrolled &&
    mouse_pos(g->size, win) == WORLD) {
        g->win->params->zoom += 0.1 * ev.mouseWheelScroll.delta;
        if (g->win->params->zoom < 0.1)
            g->win->params->zoom = 0.1;
    }
    if (ev.type == sfEvtClosed)
        set_next_win_state(win, EXIT);
    else if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyEscape)
        set_next_win_state(win, HOME);
    else
        params(g->win, g->world, g);
    if (ev.type == sfEvtKeyPressed)
        check_tool_bar_key(ev.key.code, win);
    if (ev.type == sfEvtMouseButtonReleased &&
    ev.mouseButton.button == sfMouseLeft) {
        for (int i = 0; i < NB_SOUNDS; i++)
            sfSound_stop(g->win->sounds[i]);
    }
}

void minimap_events(game_t *g, sfEvent ev)
{
    if (ev.type == sfEvtMouseWheelScrolled) {
        if (ev.mouseWheelScroll.delta == 1)
            g->minimap->s_br++;
        if (ev.mouseWheelScroll.delta == -1 && g->minimap->s_br > 0)
            g->minimap->s_br--;
    }
    if (ev.type == sfEvtMouseMoved)
        g->minimap->mouse_pos = (sfVector2f){ev.mouseMove.x, ev.mouseMove.y};
}

mouse_pos_t mouse_pos(sfVector2f win_size, window_t *win)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->win);
    float minimap_dim = win_size.y * PART_OF_MINIMAP;

    if (pos.x < minimap_dim && pos.y < minimap_dim)
        return MINIMAP;
    else if (pos.x < minimap_dim)
        return BUTTONS;
    else
        return WORLD;
}

void game_events(window_t *win, sfEvent ev)
{
    game_t *g = win->menus[EDIT_MAP];
    int mouse = mouse_pos(g->size, win);
    if (ev.type == sfEvtKeyReleased && ev.key.code == sfKeyF11)
        fullscreen_mode(win);
    if (ev.type == sfEvtKeyReleased && ev.key.code == sfKeyF5)
        g->win->draw_fps = !g->win->draw_fps;
    world_events(g, ev, win);
    if (mouse == MINIMAP && !win->is_fullscreen)
        minimap_events(g, ev);
    if (mouse == BUTTONS && !win->is_fullscreen)
        gb_events(win, ev, (sfVector2f){0, g->size.y * PART_OF_MINIMAP});
    else
        g->gb->mouse_pos = (sfVector2f){-100, -100};
    if (ev.type == sfEvtMouseButtonReleased && !g->on_help)
        g->gb->is_help = false;
    if (ev.type == sfEvtMouseMoved)
        g->minimap->mouse_pos = (sfVector2f){ev.mouseMove.x, ev.mouseMove.y};
    if (ev.type == sfEvtKeyPressed &&
    ev.key.code == sfKeyS && ev.key.control)
        save_game(win);
}
