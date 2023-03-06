/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** double_click.c
*/

#include "menus.h"

int check_double_click(map_select_t *m, int entry_clicked)
{
    int clicked = entry_clicked;
    bool is_time_good =
    sfClock_getElapsedTime(m->double_click).microseconds < DOUBLE_CLICK_DELAY;

    if (clicked >= 0) {
        if (clicked != m->primary) {
            sfClock_restart(m->double_click);
            m->has_clicked = 1;
        }
        if (clicked == m->primary && is_time_good)
            return 1;
        if (clicked == m->primary && !is_time_good) {
            m->has_clicked = 0;
            sfClock_restart(m->double_click);
        }
    } else
        m->has_clicked = 0;
    return 0;
}

int recolor_buttons(map_select_t *m, sfVector2f pos)
{
    int clicked = entry_at(m, pos);

    if (check_double_click(m, clicked))
        return clicked;
    m->primary = entry_at(m, pos);
    for (int i = 1; i < 3; i++) {
        sfSprite_setColor(m->buttons[i]->sprite,
        m->primary >= 0 ? sfWhite : SEMI_COLOR);
        sfText_setFillColor(m->buttons[i]->text,
        m->primary >= 0 ? sfWhite : SEMI_COLOR);
    }
    return -1;
}
