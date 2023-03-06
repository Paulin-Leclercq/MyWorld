/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** scale.c
*/

#include "menus.h"

void scale_main_buttons(button_t *buttons[4], sfVector2f winSize)
{
    sfVector2f size;

    for (int i = 0; i < 4; i++) {
        size.x = winSize.x * main_buts_sf[i][0];
        size.y = winSize.y * main_buts_sf[i][1];
        buttons[i]->size = size;
        set_sprite_size(buttons[i]->sprite, size);
        center_sprite(buttons[i]->sprite);
        sfText_setCharacterSize(buttons[i]->text,
        size.y * MAIN_MENU_TXT_FACTOR);
        center_text(buttons[i]->text);
    }
}

void move_main_buttons(button_t *buttons[4], sfVector2f winSize)
{
    sfVector2f pos;

    for (int i = 0; i < 4; i++) {
        pos.x = winSize.x * main_buts_pf[i][0];
        pos.y = winSize.y * main_buts_pf[i][1];
        buttons[i]->pos = pos;
        sfSprite_setPosition(buttons[i]->sprite, pos);
        sfText_setPosition(buttons[i]->text, pos);
    }
}

void scale_main_menu(main_menu_t *m, window_t *win)
{
    sfVector2f win_size = {win->mode.width, win->mode.height};

    sfRenderTexture_destroy(m->text);
    m->text = sfRenderTexture_create(win_size.x, win_size.y, 0);
    move_main_buttons(m->buttons, win_size);
    scale_main_buttons(m->buttons, win_size);
}
