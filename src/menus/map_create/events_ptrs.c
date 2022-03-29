/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** events_ptrs.c
*/

#include "menus.h"

void increase_size(void *w)
{
    window_t *win = w;
    map_create_t *mc = win->menus[CREATE_MAP];
    slider_t *s = mc->size_slider;
    float step = s->size.x / (s->max - s->min);

    mc->size_slider->value -= 1;
    if (mc->size_slider->value < mc->size_slider->min)
        mc->size_slider->value = mc->size_slider->min;
    else {
        sfSprite_move(s->cursor->sprite, (sfVector2f){-step, 0});
        s->cursor->pos.x -= step;
    }
    update_positions(mc->size_slider);
    update_size_text(mc->size, mc->size_slider);
}

void decrease_size(void *w)
{
    window_t *win = w;
    map_create_t *mc = win->menus[CREATE_MAP];
    slider_t *s = mc->size_slider;
    float step = s->size.x / (s->max - s->min);

    mc->size_slider->value += 1;
    if (mc->size_slider->value > mc->size_slider->max)
        mc->size_slider->value = mc->size_slider->max;
    else {
        sfSprite_move(s->cursor->sprite, (sfVector2f){step, 0});
        s->cursor->pos.x += step;
    }
    update_positions(mc->size_slider);
    update_size_text(mc->size, mc->size_slider);
}

void launch_size(void *w)
{
    window_t *win = w;
    map_create_t *mc = win->menus[CREATE_MAP];
    sfVector2u s = sfRenderTexture_getSize(mc->rtex);
    win->menus[EDIT_MAP] = create_game(mc->size_slider->value,
    (sfVector2f){s.x, s.y}, 0, win->menus[SETTINGS]);
    set_next_win_state(win, EDIT_MAP);
}

void mc_go_back(void *w)
{
    window_t *win = w;
    set_next_win_state(win, HOME);
}

void mc_event(window_t *win, sfEvent ev)
{
    map_create_t *mc = win->menus[3];

    if (ev.type == sfEvtMouseButtonPressed)
        check_button_press(mc->buttons, 4, ev);
    if (ev.type == sfEvtMouseMoved)
        check_button_move(mc->buttons, 4, ev);
    if (ev.type == sfEvtMouseButtonReleased)
        release_mc(mc, button_at(mc->buttons, 4, ev), win);
    if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyEnter)
        launch_size(win);
    line_edit_event(mc->name, ev);
    slider_event(mc->size_slider, ev);
}
