/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** checkbox.c
*/

#include "menus.h"

void destroy_check_box(check_box *c)
{
    sfText_destroy(c->text);
    sfSprite_destroy(c->check);
    sfSprite_destroy(c->box);
    free(c);
}

void scale_check_box(check_box *c, sfVector2f factors)
{
    sfSprite_setScale(c->box, factors);
    sfSprite_setScale(c->check, factors);
}

void set_box_pos(check_box *c, sfVector2f pos)
{
    sfSprite_setPosition(c->check, pos);
    sfSprite_setPosition(c->box, pos);
}

void draw_check_box(sfRenderTexture *rtex, check_box *c)
{
    sfRenderTexture_drawSprite(rtex, c->box, NULL);
    if (c->is_checked)
        sfRenderTexture_drawSprite(rtex, c->check, NULL);
    sfRenderTexture_drawText(rtex, c->text, NULL);
}

check_box *init_check_box(int check, char const *text, window_t *win)
{
    check_box *c = malloc(sizeof(check_box));

    c->is_checked = check;
    c->text = init_text(text, win->mode.width / 800.0 * 30);
    c->check = init_sprite(global_texture(),
    check_rect[0], (sfVector2f){1, 1});
    c->box = init_sprite(global_texture(),
    check_rect[1], (sfVector2f){1, 1});
    return c;
}
