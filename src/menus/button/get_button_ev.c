/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** get_button_ev.c
*/

#include "menus.h"

bool is_on_button(sfVector2f pos, button_t *b)
{
    sfFloatRect bounds = {
        b->pos.x - b->size.x / 2.0, b->pos.y - b->size.y / 2.0,
        b->size.x, b->size.y
    };
    if (sfFloatRect_contains(&bounds, pos.x, pos.y))
        return true;
    return false;
}

void check_button_move(button_t **buttons, int nb_button, sfEvent move)
{
    sfVector2f pos = {move.mouseMove.x, move.mouseMove.y};
    for (int i = 0; i < nb_button; i++)
        hover_button(buttons[i], is_on_button(pos, buttons[i]));
}

void check_button_press(button_t **buttons, int nb_button, sfEvent press)
{
    sfVector2f pos = {press.mouseButton.x, press.mouseButton.y};
    for (int i = 0; i < nb_button; i++)
        press_button(buttons[i], is_on_button(pos, buttons[i]));
}

int button_at(button_t **buttons, int nb_button, sfEvent release)
{
    sfVector2f pos = {release.mouseButton.x, release.mouseButton.y};
    for (int i = 0; i < nb_button; i++)
        if (is_on_button(pos, buttons[i]))
            return i;
    return -1;
}
