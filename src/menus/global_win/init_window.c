/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** init_window.c
*/

#include "menus.h"

void create_pointers(window_t *win)
{
    const sfTexture* (*dr[6])(void *) = {
        &draw_main_menu, NULL, &draw_settings, NULL, NULL, &draw_game
    };
    void (*ev[6])(window_t *, sfEvent) = {
        &main_menu_event, NULL, &settings_ev, &mc_event, NULL, &game_events
    };

    for (int i = 0; i < 6; i++) {
        win->draw[i] = dr[i];
        win->event[i] = ev[i];
    }
}

void create_basics(window_t *win)
{
    win->state = HOME;
    win->next_state = HOME;
    win->is_transition = 0;
    win->win = sfRenderWindow_create(
        (sfVideoMode){800, 600, 32}, "My world", sfClose, NULL);
    win->mode = (sfVideoMode){800, 600, 32};
    win->lum_clock = sfClock_create();
}

void create_settings(window_t *win)
{
    win->menus[2] = init_settings(win);
    load_settings(win->menus[2]);
    apply_settings(win->menus[2], win);
}

window_t *window_create(void)
{
    window_t *win = malloc(sizeof(window_t));

    create_pointers(win);
    create_basics(win);
    win->menus[0] = init_main_menu(global_texture(), (sfVector2f){800, 600});
    win->menus[3] = create_map_create((sfVector2f){800, 600});
    create_settings(win);
    return win;
}
