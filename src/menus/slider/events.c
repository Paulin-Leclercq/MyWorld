/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** events.c
*/

#include "menus.h"

void slider_pressed(slider_t *s, sfEvent ev)
{
    sfVector2f pos = (sfVector2f){ev.mouseButton.x, ev.mouseButton.y};

    if (is_on_button(pos, s->cursor))
        press_button(s->cursor, true);
    else
        press_button(s->cursor, false);
}

int evalute_from_sprite(slider_t *s)
{
    return (s->max - s->min) * (s->cursor->pos.x / s->size.x) + s->min;
}

void slider_moved(slider_t *s, double pos)
{
    float y = s->size.y * 0.5 + s->pos.y;
    sfVector2f po = {pos, y};
    sfVector2f po2;

    if (s->cursor->is_press) {
        sfSprite_setPosition(s->cursor->sprite, po);
        sfSprite_move(s->cursor->sprite, (sfVector2f){-s->pos.x, - s->pos.y});
        po2 = sfSprite_getPosition(s->cursor->sprite);
        if (po2.x < 0) {
            po.x = s->pos.x;
            sfSprite_setPosition(s->cursor->sprite, (sfVector2f){0, po2.y});
        }
        if (po2.x > s->size.x) {
            po.x = s->size.x + s->pos.x;
            sfSprite_setPosition(s->cursor->sprite,
            (sfVector2f){s->size.x, po2.y});
        }
        s->cursor->pos = po;
    }
}

void slider_event(slider_t *s, sfEvent ev)
{
    s->cursor->pos.x += s->pos.x;
    s->cursor->pos.y += s->pos.y;

    if (ev.type == sfEvtMouseButtonPressed)
        slider_pressed(s, ev);
    if (ev.type == sfEvtMouseButtonReleased)
        press_button(s->cursor, false);
    if (ev.type == sfEvtMouseMoved)
        slider_moved(s, ev.mouseMove.x);

    s->cursor->pos.x -= s->pos.x;
    s->cursor->pos.y -= s->pos.y;
    s->value = evalute_from_sprite(s);
    update_positions(s);
}
