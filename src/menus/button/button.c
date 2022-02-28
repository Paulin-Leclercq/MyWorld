/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** init_button.c
*/

#include "menus.h"

void destroy_button(button_t *b)
{
    sfSprite_destroy(b->sprite);
    sfText_destroy(b->text);
    free(b);
}

void factor_color(sfSprite *s, float factor)
{
    sfColor c = sfSprite_getColor(s);

    c.r *= factor;
    c.g *= factor;
    c.b *= factor;
    sfSprite_setColor(s, c);
}

void hover_button(button_t *b, int is_on)
{
    if (is_on == b->is_hover)
        return;
    if (is_on)
        sfSprite_scale(b->sprite, (sfVector2f){GROW_FACTOR, GROW_FACTOR});
    else
        sfSprite_scale(b->sprite,
        (sfVector2f){1.0 / GROW_FACTOR , 1.0 / GROW_FACTOR});
    b->is_hover = is_on;
}

void press_button(button_t *b, int is_press)
{
    if (is_press == b->is_press)
        return;
    if (is_press) {
        hover_button(b, false);
        factor_color(b->sprite, 0.5);
    } else {
        hover_button(b, true);
        factor_color(b->sprite, 2.0);
    }
    b->is_press = is_press;
}

button_t *init_button(sfTexture *t, sfIntRect rect,
sfVector2f pos, sfVector2f size, char const *str, void (*action)(void *))
{
    button_t *n = malloc(sizeof(button_t));

    n->is_hover = 0;
    n->is_press = 0;
    n->pos = pos;
    n->size = size;
    n->text = init_text(str, size.y * MAIN_MENU_TXT_FACTOR);
    n->sprite = init_sprite(t, rect, size);
    n->action = action;
    return n;
}
