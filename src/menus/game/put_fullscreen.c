/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** put_fullscreen.c
*/

#include "menus.h"

void fullscreen_mode(window_t *win)
{
    game_t *g = win->menus[EDIT_MAP];
    sfVector2f win_size = {win->mode.width, win->mode.height};

    win->is_fullscreen = !win->is_fullscreen;
    sfRenderTexture_destroy(g->win->r_tex);
    if (win->is_fullscreen)
        g->win->r_tex = sfRenderTexture_create(win_size.x, win_size.y, 0);
    else
        g->win->r_tex = sfRenderTexture_create(win_size.x -
        win_size.y * PART_OF_MINIMAP, win_size.y, 0);
}
