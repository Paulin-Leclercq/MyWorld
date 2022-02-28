/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** destroy.c
*/

#include "menus.h"

void destroy_slider(slider_t *s)
{
    sfRenderTexture_destroy(s->rtex);

    sfRectangleShape_destroy(s->after_cursor);
    sfRectangleShape_destroy(s->before_cursor);
    destroy_button(s->cursor);
    free(s);
}
