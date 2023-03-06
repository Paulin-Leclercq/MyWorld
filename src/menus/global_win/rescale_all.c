/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** rescale_all.c
*/

#include "menus.h"

void rescale_all(window_t *win)
{
    sfVector2f size = {win->mode.width, win->mode.height};
    rescale_settings(win->menus[2], win);
    scale_main_menu(win->menus[0], win);
    scale_mc(win->menus[3], size);
    scale_select(win->menus[MAP_SELECT], size);
    RESCALE_SPECTATOR(win->spec, size);
}
