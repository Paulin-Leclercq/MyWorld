/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** globals.c
*/

#include "menus.h"

sfFont *global_font(void)
{
    static sfFont *f = 0;
    static int has_return = 0;

    if (!has_return) {
        has_return = 1;
        f = sfFont_createFromFile(FONT);
    }
    return f;
}

sfTexture *global_texture(void)
{
    static sfTexture *t = 0;
    static int has_return = 0;

    if (!has_return) {
        t = sfTexture_createFromFile(TEXTURE, NULL);
        has_return = 1;
    }
    return t;
}
