/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** release.c
*/

#include "menus.h"

void remove_level(map_select_t *m, int level)
{
    map_entry_t *me = entry_at_list(m->maps, level);
    char *l_name = str_concat(2, "./map/", sfText_getString(me->level_name));
    char *png_name = str_concat(3, "./map/.",
    sfText_getString(me->level_name), ".png");
    int f_1 = open(l_name, O_TRUNC);
    int f_2 = open(png_name, O_TRUNC);

    m->primary = -1;
    init_entries(m, m->size);
    free(l_name);
    free(png_name);
    if (f_1 >= 0)
        close(f_1);
    if (f_2 >= 0)
        close(f_2);
}

map_entry_t *entry_at_list(list_t *l, int index)
{
    for (int i = 0; i < index; i++)
        l = l->next;
    return l->data;
}

void load_map(char const *map, window_t *win)
{
    unsigned size = map_size(map);

    win->menus[EDIT_MAP] = create_game(size,
    (sfVector2f){win->mode.width, win->mode.height}, 1, win->menus[SETTINGS]);
    read_map(win->menus[EDIT_MAP], map);
    set_next_win_state(win, EDIT_MAP);
    update_color(((game_t *)(win->menus[EDIT_MAP]))->world);
}

void manage_release(map_select_t *m, sfEvent ev, window_t *win)
{
    int but;
    sfVector2f pos = {ev.mouseButton.x, ev.mouseButton.y};
    for (int i = 0; i < 3; i++)
        press_button(m->buttons[i], false);
    ev.mouseButton.x = pos.x;
    ev.mouseButton.y = pos.y;
    but = button_at(m->buttons, 3, ev);
    if (but < 0) {
        if (recolor_buttons(m, pos) >= 0)
            load_map(sfText_getString(entry_at_list
            (m->maps, m->primary)->level_name), win);
    } else {
        if (but == 0)
            set_next_win_state(win, HOME);
        if (but == 1 && m->primary >= 0)
            remove_level(m, m->primary);
        if (but == 2 && m->primary >= 0)
            load_map(sfText_getString(entry_at_list
            (m->maps, m->primary)->level_name), win);
    }
}
