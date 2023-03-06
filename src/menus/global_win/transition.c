/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** transition.c
*/

#include "menus.h"

void switch_color_dir(window_t *win, int *dir)
{
    game_t *g = win->menus[EDIT_MAP];

    if (win->state == EDIT_MAP) {
        if (win->next_state == EXIT)
            save_game(win);
        if (win->next_state == HOME || win->next_state == EXIT)
            destroy_game_struct(win->menus[EDIT_MAP]);
        win->is_fullscreen = 0;
    }
    if (win->next_state == MAP_SELECT)
        init_entries(win->menus[MAP_SELECT],
        (sfVector2f){win->mode.width, win->mode.height});
    if (win->next_state == EDIT_MAP)
        sfMusic_play(g->win->musics[0]);
    win->state = win->next_state;
    *dir = -1;
    if (win->state == EXIT)
        sfRenderWindow_close(win->win);
}

void reset_lum(window_t *win, int *dir, sfColor *lum)
{
    *dir = 1;
    win->is_transition = false;
    *lum = (sfColor){255, 255, 255, 255};
}

void update_lum(sfColor *lum, int *fac)
{
    lum->a -= *fac;
    lum->b -= *fac;
    lum->r -= *fac;
    lum->g -= *fac;
}

void update_transition(window_t *win, sfSprite *s)
{
    static bool dir = 1;
    int fac = dir * 24;
    static sfColor lum = {255, 255, 255, 255};

    if (win->is_transition &&
    sfClock_getElapsedTime(win->lum_clock).microseconds > 33333) {
        if (lum.a == 39)
            switch_color_dir(win, &dir);
        update_lum(&lum, &fac);
        sfSprite_setColor(s, lum);
        if (dir == -1 && lum.a == 255)
            reset_lum(win, &dir, &lum);
        sfClock_restart(win->lum_clock);
    }
    sfSprite_setColor(s, lum);
}
