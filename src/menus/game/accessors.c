/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** accessors.c
*/

#include "menus.h"

char const *get_level_name(window_t *win)
{
    game_t *g = win->menus[EDIT_MAP];
    map_select_t *ms = win->menus[MAP_SELECT];
    map_create_t *mc = win->menus[CREATE_MAP];

    if (g->is_selected)
        return sfText_getString(
        entry_at_list(ms->maps, ms->primary)->level_name);
    return get_text(mc->name);
}

size_t get_level_size(window_t *win)
{
    game_t *g = win->menus[EDIT_MAP];

    return g->win->map_size;
}
