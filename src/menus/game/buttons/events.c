/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** events.c
*/

#include "menus.h"

void press_evt(game_buttons_t *g, sfEvent ev, sfVector2f pos)
{
    ev.mouseButton.x -= pos.x;
    ev.mouseButton.y -= pos.y;
    check_button_press(g->buttons, NB_BUTTONS, ev);
}

void move_evt(game_buttons_t *g, sfEvent ev, sfVector2f pos)
{
    ev.mouseMove.x -= pos.x;
    ev.mouseMove.y -= pos.y;
    g->mouse_pos = (sfVector2f){ev.mouseMove.x, ev.mouseMove.y};
    check_button_move(g->buttons, NB_BUTTONS, ev);
}

void action(int type, game_t *ga)
{
    if (type == 6)
        ga->win->params->pause = !ga->win->params->pause;
    if (type == 7)
        rota_left(ga->world, ga->win);
    if (type == 8)
        rota_right(ga->world, ga->win);
}

void release_evt(game_t *ga, sfEvent ev, sfVector2f pos, window_t *win)
{
    game_buttons_t *g = ga->gb;
    int tmp;

    ev.mouseButton.x -= pos.x;
    ev.mouseButton.y -= pos.y;
    tmp = button_at(g->buttons, NB_BUTTONS, ev);
    for (int i = 0; i < NB_BUTTONS; i++)
        press_button(g->buttons[i], false);
    if (tmp < 0)
        return;
    if (!(g->buttons[tmp]->action)) {
        g->selected = tmp;
        ga->minimap->state = tmp;
    } else
        g->buttons[tmp]->action(win);
}

void gb_events(window_t *win, sfEvent ev, sfVector2f pos)
{
    game_t *ga = win->menus[EDIT_MAP];
    game_buttons_t *g = ga->gb;

    ga->on_help = false;
    if (ev.type == sfEvtMouseButtonPressed)
        press_evt(g, ev, pos);
    if (ev.type == sfEvtMouseMoved)
        move_evt(g, ev, pos);
    if (ev.type == sfEvtMouseButtonReleased)
        release_evt(ga, ev, pos, win);
    if (ev.type >= 9 && ev.type <= 11) {
        sfClock_restart(g->tip_clock);
        g->tool_tip_enabled = false;
    }
    if (ev.type == sfEvtMouseWheelScrolled) {
        g->y_offset -= ev.mouseWheelScroll.delta * 10;
        if (g->y_offset < 0)
            g->y_offset = 0;
    }
}
