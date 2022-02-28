/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** move_settings.c
*/

#include "menus.h"

static void move_buttons_se(settings_t *se, window_t *win)
{
    set_box_pos(se->full_screen,
    conv((sfVector2f){60, 108}, win));
    sfText_setPosition(se->full_screen->text,
    conv((sfVector2f){143, 120}, win));
    set_box_pos(se->vsync,
    conv((sfVector2f){470, 108}, win));
    sfText_setPosition(se->vsync->text,
    conv((sfVector2f){550, 120}, win));
    sfSprite_setPosition(se->framerate_button->sprite,
    conv((sfVector2f){605, 270}, win));
    sfSprite_setPosition(se->res_button->sprite,
    conv((sfVector2f){210, 270}, win));
}

static void move_sfx(settings_t *se, window_t *win)
{
    sfSprite_setPosition(se->sfx_minus->sprite, (sfVector2f)
    {win->mode.width * 0.4, win->mode.height * 0.62});
    sfSprite_setPosition(se->sfx_plus->sprite, (sfVector2f)
    {win->mode.width * 0.6, win->mode.height * 0.62});
    sfText_setPosition(se->sfx_vol_text, (sfVector2f)
    {win->mode.width * 0.5, win->mode.height * 0.62});
    sfText_setPosition(se->sfx_text, (sfVector2f)
    {win->mode.width * 0.3, win->mode.height * 0.62});
}

static void move_music(settings_t *se, window_t *win)
{
    sfSprite_setPosition(se->music_minus->sprite, (sfVector2f)
    {win->mode.width * 0.4, win->mode.height * 0.78});
    sfSprite_setPosition(se->music_plus->sprite, (sfVector2f)
    {win->mode.width * 0.6, win->mode.height * 0.78});
    sfText_setPosition(se->music_vol_text, (sfVector2f)
    {win->mode.width * 0.5, win->mode.height * 0.78});
    sfText_setPosition(se->music_text, (sfVector2f)
    {win->mode.width * 0.3, win->mode.height * 0.78});
}

void move_settings(settings_t *se, window_t *win)
{
    sfVector2f pos = {win->mode.width / 22.0, win->mode.width / 22.0};

    sfSprite_setPosition(se->background, pos);
    sfSprite_setPosition(se->back->sprite, pos);
    move_buttons_se(se, win);
    move_sfx(se, win);
    move_music(se, win);
}
