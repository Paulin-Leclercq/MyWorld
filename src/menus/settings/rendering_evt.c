/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** rendering_evt.c
*/

#include "menus.h"

void go_back(settings_t *se, window_t *win)
{
    win->is_transition = se->full_screen ? 1 : 1;
    win->next_state = HOME;
}

void update_full_screen(settings_t *se, window_t *win)
{
    se->full_screen->is_checked = !se->full_screen->is_checked;
    sfRenderWindow_destroy(win->win);
    if (se->full_screen->is_checked) {
        win->mode = sfVideoMode_getDesktopMode();
        win->win = sfRenderWindow_create(win->mode,
        "My world", sfFullscreen, NULL);
        sfSprite_setColor(se->res_button->sprite,
        (sfColor){127, 127, 127, 255});
    } else {
        win->mode = available_modes[se->resolution];
        win->win = sfRenderWindow_create(win->mode,
        "My runner", sfClose, NULL);
        sfSprite_setColor(se->res_button->sprite,
        (sfColor){255, 255, 255, 255});
    }
    sfRenderWindow_setFramerateLimit(win->win,
    available_framerates[se->framerate]);
    rescale_all(win);
}

void update_vsync(settings_t *se, window_t *win)
{
    se->vsync->is_checked = !se->vsync->is_checked;
    sfRenderWindow_setVerticalSyncEnabled(win->win, se->vsync->is_checked);
}

void update_res(settings_t *se, window_t *win)
{
    se->resolution++;
    if (se->resolution > 2)
        se->resolution = 0;
    sfRenderWindow_destroy(win->win);
    win->mode = available_modes[se->resolution];
    win->win = sfRenderWindow_create(win->mode,
    "My world", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win->win,
    available_framerates[se->framerate]);
    rescale_all(win);
}

void update_framerate(settings_t *se, window_t *win)
{
    se->framerate++;
    if (se->framerate > 4)
        se->framerate = 0;
    win->framerate = available_framerates[se->framerate];
    sfRenderWindow_setFramerateLimit(win->win, win->framerate);
}
