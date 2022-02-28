/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** visu_updates.c
*/

#include "menus.h"
#include "my.h"
#include <math.h>

void update_all_texts(settings_t *se)
{
    char *str;

    sfSprite_setTextureRect(se->res_button->sprite,
    settings_rects[se->resolution + 7]);
    sfSprite_setTextureRect(se->framerate_button->sprite,
    settings_rects[se->framerate + 2]);
    str = long_to_str(se->sfx_vol);
    sfText_setString(se->sfx_vol_text, str);
    free(str);
    str = long_to_str(se->music_vol);
    sfText_setString(se->music_vol_text, str);
    free(str);
}

void reset_set_buttons(settings_t *se)
{
    button_t *buttons[9] = {se->back, NULL, NULL, se->res_button,
    se->framerate_button, se->sfx_minus, se->sfx_plus,
    se->music_minus, se->music_plus};

    for (int i = 0; i < 9; i++) {
        if (i == 1 || i == 2)
            continue;
        hover_button(buttons[i], 0);
        press_button(buttons[i], 0);
    }
}
