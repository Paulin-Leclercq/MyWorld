/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** events.c
*/

#include "menus.h"

void world_events(game_t *g, sfEvent ev, window_t *win)
{
    g->win->event = ev;
    if (ev.type == sfEvtClosed) {
        set_next_win_state(win, EXIT);
    } else if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyEscape)
        set_next_win_state(win, HOME);
    else
        params(g->win, g->world);
}

void minimap_clicks(game_t *g)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        g->minimap->actions[g->minimap->state](g->world, g->minimap);
        smooth_shadow(g->world, g->win);
        update_color(g->world);
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

    world_events(g, ev, win);
    if (mouse == MINIMAP)
        minimap_events(g, ev);
    if (ev.type == sfEvtMouseMoved)
        g->minimap->mouse_pos = (sfVector2f){ev.mouseMove.x, ev.mouseMove.y};
}
