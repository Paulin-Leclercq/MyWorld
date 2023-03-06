/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "world.h"
#include "menus.h"

void world_clicks_next(window_t *win)
{
    game_t *g = win->menus[EDIT_MAP];
    mat4x4 *tmp;
    mat4x4 **mat_world = &g->world->matrix;
    mat4x4 *mat_mov = NULL;
    sfVector2i new_pos = sfMouse_getPositionRenderWindow(win->win);
    mat_mov = mat4x4_rx((win->tmp_pos.y - new_pos.y) / 600.0);
    if (mat_mov != NULL) {
        tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        mat4x4_destroy(mat_mov);
        mat4x4_destroy(*mat_world);
        *mat_world = tmp;
    }
    mat_mov = mat4x4_ry((win->tmp_pos.x - new_pos.x) / 600.0);
    if (mat_mov != NULL) {
        tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        mat4x4_destroy(mat_mov);
        mat4x4_destroy(*mat_world);
        *mat_world = tmp;
    }
    win->tmp_pos = new_pos;
}

void world_clicks(window_t *win, sfEvent ev)
{
    static int is_click = 0;
    if (ev.type == sfEvtMouseButtonPressed) {
        win->tmp_pos = sfMouse_getPositionRenderWindow(win->win);
        is_click = 1;
    }
    if (ev.type == sfEvtMouseButtonReleased)
        is_click = 0;
    if (is_click == 1 && ev.type == sfEvtMouseMoved)
        world_clicks_next(win);
}
