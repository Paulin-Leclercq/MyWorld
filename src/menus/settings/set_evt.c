/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** set_evt.c
*/

#include "menus.h"

void settings_ev(window_t *win, sfEvent ev)
{
    if (ev.type == sfEvtMouseMoved)
        manage_settings_hover(&ev, win);
    if (ev.type == sfEvtMouseButtonPressed)
        manage_settings_press(&ev, win);
    if (ev.type == sfEvtMouseButtonReleased)
        manage_settings_release(&ev, win);
}

void draw_set_button(sfRenderTexture *r, button_t *b)
{
    sfRenderTexture_drawSprite(r, b->sprite, NULL);
}

const sfTexture *draw_settings(window_t *win)
{
    settings_t *se = win->menus[SETTINGS];

    sfRenderTexture_clear(se->rtex, sfBlack);
    draw_spectator_to_rtex(win->spec, se->rtex, 1, 1);
    sfRenderTexture_drawSprite(se->rtex, se->background, NULL);
    draw_set_button(se->rtex, se->back);
    draw_check_box(se->rtex, se->full_screen);
    draw_check_box(se->rtex, se->vsync);
    draw_set_button(se->rtex, se->framerate_button);
    draw_set_button(se->rtex, se->res_button);
    draw_set_button(se->rtex, se->sfx_minus);
    draw_set_button(se->rtex, se->sfx_plus);
    draw_set_button(se->rtex, se->music_minus);
    draw_set_button(se->rtex, se->music_plus);
    sfRenderTexture_drawText(se->rtex, se->sfx_text, NULL);
    sfRenderTexture_drawText(se->rtex, se->music_text, NULL);
    sfRenderTexture_drawText(se->rtex, se->sfx_vol_text, NULL);
    sfRenderTexture_drawText(se->rtex, se->music_vol_text, NULL);
    sfRenderTexture_display(se->rtex);
    return sfRenderTexture_getTexture(se->rtex);
}
