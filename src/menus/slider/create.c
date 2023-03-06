/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create.c
*/

#include "menus.h"

void update_positions(slider_t *s)
{
    float percent = (s->value - s->min) / (float)(s->max - s->min);
    sfVector2f bef_size = {s->size.x * percent, s->size.y};
    sfVector2f aft_size = {s->size.x * (1 - percent), s->size.y};

    sfRectangleShape_setSize(s->before_cursor, bef_size);
    sfRectangleShape_setSize(s->after_cursor, aft_size);
    sfRectangleShape_setPosition(s->after_cursor, (sfVector2f){bef_size.x, 0});
    s->cursor->pos = (sfVector2f){bef_size.x, s->size.y * 0.5};
    sfSprite_setPosition(s->cursor->sprite, s->cursor->pos);
}

void rescale_slider(slider_t *s, sfVector2f new_size, sfVector2f new_pos)
{
    sfRenderTexture_destroy(s->rtex);
    s->rtex = sfRenderTexture_create(new_size.x, new_size.y, 0);
    s->size = new_size;
    s->but_size = (sfVector2f){new_size.x * 0.1, new_size.y};
    set_sprite_size(s->cursor->sprite, s->but_size);
    update_positions(s);
    s->pos = new_pos;
}

sfSprite *draw_slider(slider_t *s)
{
    sfSprite *sp;

    sfRenderTexture_clear(s->rtex, (sfColor){0, 0, 0, 0});
    sfRenderTexture_drawRectangleShape(s->rtex, s->before_cursor, NULL);
    sfRenderTexture_drawRectangleShape(s->rtex, s->after_cursor, NULL);
    sfRenderTexture_drawSprite(s->rtex, s->cursor->sprite, NULL);
    sfRenderTexture_display(s->rtex);
    sp = init_sprite_from_texture(sfRenderTexture_getTexture(s->rtex));
    sfSprite_setPosition(sp, s->pos);
    return sp;
}

sfRectangleShape *create_rectangle(sfVector2f size,
sfColor fill, sfTexture const *tex, ...)
{
    sfRectangleShape *s = sfRectangleShape_create();
    va_list va;

    va_start(va, tex);
    if (!tex)
        sfRectangleShape_setFillColor(s, fill);
    else {
        sfRectangleShape_setTexture(s, tex, 0);
        sfRectangleShape_setTextureRect(s, va_arg(va, sfIntRect));
    }
    sfRectangleShape_setSize(s, size);
    return s;
}

slider_t *create_slider(sfVector2f size,
sfVector2f bounds, int value, sfVector2f pos)
{
    slider_t *s = malloc(sizeof(slider_t));

    s->rtex = sfRenderTexture_create(size.x, size.y, 0);
    s->min = bounds.x;
    s->max = bounds.y;
    s->value = value;
    s->size = size;
    s->but_size = (sfVector2f){size.x * 0.1, size.y};
    s->cursor = init_button(global_texture(), slider_rects[0],
    (sfVector2f){0, 0}, s->but_size, "", NULL);
    center_sprite(s->cursor->sprite);
    s->before_cursor = create_rectangle((sfVector2f){1, 1},
    sfGreen, global_texture(), slider_rects[1]);
    s->after_cursor = create_rectangle((sfVector2f){1, 1},
    sfGrey, global_texture(), slider_rects[2]);
    s->pos = pos;
    rescale_slider(s, size, pos);
    return s;
}
