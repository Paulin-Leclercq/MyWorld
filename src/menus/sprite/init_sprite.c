/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** init_sprite.c
*/

#include "menus.h"

sfSprite *init_sprite(sfTexture *t, sfIntRect rect, sfVector2f size)
{
    sfSprite *s = sfSprite_create();

    sfSprite_setTexture(s, t, 0);
    sfSprite_setTextureRect(s, rect);
    set_sprite_size(s, size);
    return s;
}

sfSprite *init_sprite_from_texture(sfTexture const *t)
{
    sfSprite *s = sfSprite_create();

    sfSprite_setTexture(s, t, 0);
    return s;
}

sfText *init_text(char const *str, int charSize)
{
    sfText *t = sfText_create();

    sfText_setFont(t, global_font());
    sfText_setCharacterSize(t, charSize);
    sfText_setString(t, str);
    return t;
}
