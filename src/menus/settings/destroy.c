/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** destroy.c
*/

#include "menus.h"

void destroy_buttons(settings_t *se)
{
    destroy_button(se->back);
    destroy_button(se->framerate_button);
    destroy_button(se->music_minus);
    destroy_button(se->music_plus);
    destroy_button(se->sfx_plus);
    destroy_button(se->sfx_minus);
    destroy_button(se->res_button);
}

void destroy_settings(settings_t *se)
{
    sfRenderTexture_destroy(se->rtex);
    sfSprite_destroy(se->background);

    sfText_destroy(se->music_text);
    sfText_destroy(se->sfx_text);
    sfText_destroy(se->sfx_vol_text);
    sfText_destroy(se->music_vol_text);
    sfClock_destroy(se->repeat_clock);

    destroy_buttons(se);
    destroy_check_box(se->full_screen);
    destroy_check_box(se->vsync);
    free(se);
}
