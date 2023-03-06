/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** settings_events.c
*/

#include "menus.h"

void check_sound_repeat(window_t *win, sfEvent *ev)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && win->state == SETTINGS &&
    sfClock_getElapsedTime(win->lum_clock).microseconds > 1000000 / 25.0 &&
    sfClock_getElapsedTime(
    ((settings_t *)win->menus[2])->repeat_clock).microseconds > REPEAT_DELAY) {
        ev->mouseButton.x = sfMouse_getPositionRenderWindow(win->win).x;
        ev->mouseButton.y = sfMouse_getPositionRenderWindow(win->win).y;
        ev->type = sfEvtResized;
        if (get_set_button_at(win->menus[2], ev) <= 4)
            return;
        manage_settings_press(ev, win);
        update_all_texts(win->menus[2]);
        sfClock_restart(win->lum_clock);
    }
}

int get_set_button_at(settings_t *se, sfEvent *ev)
{
    sfFloatRect all_bounds[9] = {BOUNDS(se->back->sprite),
    BOUNDS(se->full_screen->box), BOUNDS(se->vsync->box),
    BOUNDS(se->res_button->sprite), BOUNDS(se->framerate_button->sprite),
    BOUNDS(se->sfx_minus->sprite), BOUNDS(se->sfx_plus->sprite),
    BOUNDS(se->music_minus->sprite), BOUNDS(se->music_plus->sprite)
    };
    sfVector2f pos = ev->type == sfEvtMouseMoved ?
    (sfVector2f){ev->mouseMove.x, ev->mouseMove.y} :
    (sfVector2f){ev->mouseButton.x, ev->mouseButton.y};

    for (int i = 0; i < 9; i++)
        if (sfFloatRect_contains(&all_bounds[i],
        pos.x, pos.y))
            return i;
    return -1;
}

void manage_settings_hover(sfEvent *ev, window_t *win)
{
    settings_t *se = win->menus[2];
    button_t *buttons[9] = {se->back, NULL, NULL, se->res_button,
    se->framerate_button, se->sfx_minus, se->sfx_plus,
    se->music_minus, se->music_plus};
    int tmp = get_set_button_at(se, ev);

    if (tmp < 0 || buttons[tmp] == NULL ||
    (tmp == 3 && se->full_screen->is_checked)) {
        reset_set_buttons(se);
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft))
        press_button(buttons[tmp], 1);
    else
        hover_button(buttons[tmp], 1);
}

void manage_settings_press(sfEvent *ev, window_t *win)
{
    settings_t *se = win->menus[2];
    button_t *buttons[9] = {se->back, NULL, NULL, se->res_button,
    se->framerate_button, se->sfx_minus, se->sfx_plus,
    se->music_minus, se->music_plus};
    int tmp = get_set_button_at(se, ev);
    void (*actions[9])(settings_t *) = {
        NULL, NULL, NULL,
        NULL, NULL, sfx_minus,
        sfx_plus, music_minus, music_plus
    };
    if (tmp < 0 || buttons[tmp] == NULL || (tmp == 3 &&
    se->full_screen->is_checked) || (tmp <= 4 && ev->type == sfEvtResized)) {
        reset_set_buttons(se);
        return;
    }
    if (actions[tmp])
        actions[tmp](se);
    press_button(buttons[tmp], 1);
    if (ev->type != sfEvtResized || tmp <= 4)
        sfClock_restart(se->repeat_clock);
}

void manage_settings_release(sfEvent *ev, window_t *win)
{
    settings_t *se = win->menus[2];
    int tmp = get_set_button_at(se, ev);
    void (*actions[9])(settings_t *, window_t *) = {
        go_back, update_full_screen, update_vsync,
        update_res, update_framerate, NULL,
        NULL, NULL, NULL
    };

    reset_set_buttons(se);
    if (tmp < 0 ||
    (tmp == 3 && se->full_screen->is_checked))
        return;
    if (actions[tmp])
        actions[tmp](se, win);
    update_all_texts(se);
}
