/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** sprite_modif.c
*/

#include "menus.h"

void draw_button_to_rtex(button_t *b, sfRenderTexture *rtex)
{
    sfRenderTexture_drawSprite(rtex, b->sprite, NULL);
    center_text(b->text);
    sfText_setPosition(b->text, b->pos);
    sfRenderTexture_drawText(rtex, b->text, NULL);
}

void set_sprite_size(sfSprite *s, sfVector2f size)
{
    sfIntRect tex_size = s ? sfSprite_getTextureRect(s) :
    (sfIntRect){0, 0, 0, 0};
    sfVector2f scale;
    sfVector2f actu_size;

    if (!tex_size.width || !tex_size.height)
        return;
    scale = sfSprite_getScale(s);
    actu_size = (sfVector2f){tex_size.width * scale.x,
    tex_size.height * scale.y};
    sfSprite_scale(s, (sfVector2f){size.x / actu_size.x,
    size.y / actu_size.y});
}

void center_text(sfText *t)
{
    sfFloatRect r = sfText_getLocalBounds(t);

    sfVector2f origin = {
        r.width / 2.0, sfText_getCharacterSize(t) * 0.65
    };
    sfText_setOrigin(t, origin);
}

sfVector2f get_sprite_size(sfSprite *s)
{
    sfIntRect r = sfSprite_getTextureRect(s);
    sfVector2f size = {r.width, r.height};
    sfVector2f scale = sfSprite_getScale(s);

    size.x *= scale.x;
    size.y *= scale.y;
    return size;
}

void center_sprite(sfSprite *s)
{
    sfIntRect r = sfSprite_getTextureRect(s);
    sfVector2f origin = {
        r.width / 2.0, r.height / 2.0
    };
    sfSprite_setOrigin(s, origin);
}
