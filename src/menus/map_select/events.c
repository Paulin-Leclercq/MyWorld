/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** events.c
*/

#include "menus.h"

sfFloatRect get_entry_rect(map_entry_t *m, sfVector2f pos)
{
    sfSprite *s = draw_entry(m);
    sfFloatRect rect;

    sfSprite_setPosition(s, pos);
    rect = sfSprite_getGlobalBounds(s);
    sfSprite_destroy(s);
    return rect;
}

int entry_at(map_select_t *m, sfVector2f m_pos)
{
    list_t *start = m->maps;
    sfVector2f pos = {m->size.x * 0.2, m->size.y * 0.2 - m->x_start};
    sfFloatRect rect;
    int i = 0;

    if (!start)
        return -1;
    do {
        rect = get_entry_rect(start->data, pos);
        if (sfFloatRect_contains(&rect,
        m_pos.x + rect.width * 0.15, m_pos.y + rect.height))
            return i;
        pos.y += m->size.y * ENTRY_Y_SPAN * ENTRY_SPACING;
        start = start->next;
        i++;
    } while (start != m->maps);
    return -1;
}

static void manage_move(map_select_t *m, sfEvent ev)
{
    sfVector2f pos = {ev.mouseMove.x, ev.mouseMove.y};
    check_button_move(m->buttons, 3 - (m->primary < 0 ? 2 : 0), ev);
    ev.type = sfEvtMouseButtonReleased;
    ev.mouseButton.x = pos.x;
    ev.mouseButton.y = pos.y;
    if (button_at(m->buttons, 3, ev) < 0)
        m->secondary = entry_at(m, pos);
    else
        m->secondary = -1;
}

void map_select_events(window_t *w, sfEvent ev)
{
    map_select_t *m = w->menus[MAP_SELECT];

    if (ev.type == sfEvtMouseMoved)
        manage_move(m, ev);
    if (ev.type == sfEvtMouseButtonPressed)
        check_button_press(m->buttons, 3 - (m->primary < 0 ? 2 : 0), ev);
    if (ev.type == sfEvtMouseButtonReleased)
        manage_release(m, ev, w);
    if (ev.type == sfEvtMouseWheelScrolled) {
        m->x_start -= ev.mouseWheelScroll.delta * 20;
        if (m->x_start < 0)
            m->x_start = 0;
    }
}

unsigned map_size(char const *map)
{
    char *str = str_concat(2, "./map/", map);
    int fd = open(str, O_RDONLY);
    unsigned size = 64;

    if (fd >= 0)
        read(fd, &size, sizeof(unsigned));
    free(str);
    close(fd);
    return size;
}
