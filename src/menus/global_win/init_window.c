/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** init_window.c
*/

#include "menus.h"

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
}

void create_pointers(window_t *win)
{
    const sfTexture* (*dr[6])(window_t *) = {
        &draw_main_menu, &draw_select,
        &draw_settings, &draw_mc, NULL, &draw_game
    };
    void (*ev[6])(window_t *, sfEvent) = {
        &main_menu_event, &map_select_events, &settings_ev,
        &mc_event, NULL, &game_events
    };
    for (int i = 0; i < 6; i++) {
        win->draw[i] = dr[i];
        win->event[i] = ev[i];
    }
    create_basics(win);
    create_settings(win);
}

window_t *window_create(int ac, char **av)
{
    window_t *win = malloc(sizeof(window_t));
    sfVector2f size = {800, 600};
    create_pointers(win);
    if (ac == 2) {
        if (!is_file_valid(av[1]))
            return NULL;
        win->state = EDIT_MAP;
        win->menus[EDIT_MAP] = create_game(map_size_from_file(av[1]),
        size, 0, win->menus[SETTINGS]);
        load_game_from_file(win->menus[EDIT_MAP], av[1]);
        update_color(((game_t *)(win->menus[EDIT_MAP]))->world);
    } else if (ac > 2)
        return NULL;
    win->menus[0] = init_main_menu(global_texture(), size);
    win->menus[3] = create_map_create(size);
    win->menus[MAP_SELECT] = create_map_select(size);
    win->spec = create_spectator(size);
    apply_settings(win->menus[2], win);
    return win;
}
