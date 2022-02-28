/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create.c
*/

#include "menus.h"

void destroy_line_edit(line_edit_t *le)
{
    sfRectangleShape_destroy(le->background);
    sfText_destroy(le->text);
    sfRenderTexture_destroy(le->rtex);
    free(le);
}

sfSprite *draw_line_edit(line_edit_t *le, sfVector2f pos)
{
    sfSprite *s;

    sfRenderTexture_clear(le->rtex, sfBlack);
    sfRenderTexture_drawRectangleShape(le->rtex, le->background, NULL);
    sfRenderTexture_drawText(le->rtex, le->text, NULL);
    sfRenderTexture_display(le->rtex);
    s = init_sprite_from_texture(sfRenderTexture_getTexture(le->rtex));
    sfSprite_setPosition(s, pos);
    return s;
}

void scale_line_edit(line_edit_t *le, sfVector2f size)
{
    sfRenderTexture_destroy(le->rtex);
    le->rtex = sfRenderTexture_create(size.x, size.y, 0);
    sfRectangleShape_setSize(le->background, size);
    sfText_setCharacterSize(le->text, size.y * 0.72);
    sfText_setPosition(le->text, (sfVector2f){size.x * 0.02, size.x * 0.012});
}

line_edit_t *create_line_edit(sfVector2f size, char const *def)
{
    line_edit_t *le = malloc(sizeof(line_edit_t));

    le->background = create_rectangle(size, sfGrey, NULL);
    le->rtex = sfRenderTexture_create(size.x, size.y, 0);
    le->text = init_text(def, size.y * 0.72);
    return le;
}
