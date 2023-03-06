/*
** EPITECH PROJECT, 2022
** params.c
** File description:
** params
*/

#include "world.h"
#include "menus.h"

void params(win_t *win, world_t *world, game_t *g)
{
    if (win->event.type == sfEvtKeyReleased) {
        if (win->event.key.code == sfKeyF3) {
            win->params->is_fill = win->params->is_fill == 0;
            win->params->is_outline = win->params->is_outline == 0;
        }
        if (win->event.key.code == sfKeyRight)
            rota_right(world, win);
        if (win->event.key.code == sfKeyLeft)
            rota_left(world, win);
        if (win->event.key.code == sfKeyP) {
            win->params->pause = !win->params->pause;
            sfSprite_setTextureRect(g->gb->buttons[9]->sprite,
            gb_rects[9 + 4 * g->win->params->pause]);
        }
        if (win->event.key.code == sfKeyR)
            refresh_map(g);
    }
}
