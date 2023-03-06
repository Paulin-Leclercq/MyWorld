/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** settings.c
*/

#include "menus.h"
#include "my.h"

sfVector2f conv(sfVector2f c, window_t *win)
{
    float nx = win->mode.width / 800.0 * c.x;
    float ny = win->mode.height / 600.0 * c.y;

    return (sfVector2f){nx, ny};
}

button_t *init_set_button(const sfIntRect rect)
{
    button_t *b = malloc(sizeof(button_t));

    b->is_hover = 0;
    b->is_press = 0;
    b->text = init_text("", 0);
    b->sprite = init_sprite(global_texture(), rect, (sfVector2f){1, 1});
    center_sprite(b->sprite);
    return b;
}

void init_all_settings_button(settings_t *se)
{
    se->framerate_button = init_set_button(settings_rects[2]);
    se->res_button = init_set_button(settings_rects[7]);
    se->sfx_minus = init_set_button(settings_rects[0]);
    se->sfx_plus = init_set_button(settings_rects[1]);
    se->music_minus = init_set_button(settings_rects[0]);
    se->music_plus = init_set_button(settings_rects[1]);
    se->sfx_vol_text = init_text("100", 2);
    se->music_vol_text = init_text("100", 2);
    se->sfx_text = init_text("SFX", 2);
    se->music_text = init_text("Musics", 2);
}

settings_t *init_settings(window_t *win)
{
    settings_t *se = malloc(sizeof(settings_t));

    se->vsync = init_check_box(0, "VSync", win);
    se->full_screen = init_check_box(0, "Fullscreen", win);
    se->sfx_vol = 100;
    se->music_vol = 100;
    se->framerate = 1;
    se->resolution = 0;
    se->back = init_set_button(settings_rects[10]);
    se->background = init_sprite(global_texture(),
    settings_rects[9], (sfVector2f){0, 0});
    se->rtex = sfRenderTexture_create(win->mode.width, win->mode.height, 0);
    init_all_settings_button(se);
    rescale_settings(se, win);
    update_all_texts(se);
    se->repeat_clock = sfClock_create();
    return se;
}
