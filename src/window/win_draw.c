/*
** EPITECH PROJECT, 2022
** win_draw.c
** File description:
** win_draw
*/

#include "world.h"
void draw_fps(win_t *w);

void draw_circle(win_t *win, size_t nb, ...)
{
    va_list list_arg;

    va_start(list_arg, nb);
    for (size_t i = 0; i < nb; i++) {
        sfRenderTexture_drawCircleShape(win->r_tex
        , va_arg(list_arg, sfCircleShape *), 0);
    }
    va_end(list_arg);
}

void draw_rtex_to_win(sfRenderTexture *t, sfRenderWindow *w)
{
    sfSprite *s = sfSprite_create();

    sfSprite_setPosition(s, (sfVector2f){800, 0});
    sfSprite_setTexture(s, sfRenderTexture_getTexture(t), 0);
    sfRenderWindow_drawSprite(w, s, NULL);
}

void draw_shape(win_t *win, size_t nb, ...)
{
    va_list list_arg;

    va_start(list_arg, nb);
    for (size_t i = 0; i < nb; i++) {
        sfRenderTexture_drawConvexShape(win->r_tex,
        va_arg(list_arg, sfConvexShape *), 0);
    }
    va_end(list_arg);
}
