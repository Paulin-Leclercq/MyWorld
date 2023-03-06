/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** textures.c
*/

#include "menus.h"

list_t *add_texture(sfTexture *tex)
{
    static list_t *list = 0;

    if (tex)
        append_node(&list, tex);
    return list;
}

void clear_textures(void)
{
    list_t *texs = add_texture(NULL);

    while (texs)
        remove_node(&texs, 0, (void (*)(void *))sfTexture_destroy);
}
