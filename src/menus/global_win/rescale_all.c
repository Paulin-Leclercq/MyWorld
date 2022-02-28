/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** rescale_all.c
*/

#include "menus.h"

void rescale_all(window_t *win)
{
    rescale_settings(win->menus[2], win);
    scale_main_menu(win->menus[0], win);
    scale_mc(win->menus[3], (sfVector2f){win->mode.width, win->mode.height});
}
