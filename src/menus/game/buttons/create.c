/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create.c
*/

#include "menus.h"

void destroy_gbuttons(game_buttons_t *gb)
{
    sfRectangleShape_destroy(gb->border);
    sfRenderTexture_destroy(gb->rtex);
    sfClock_destroy(gb->tip_clock);
    sfRectangleShape_destroy(gb->tooltip_box);
    sfText_destroy(gb->tooltip);
    for (int i = 0; i < NB_BUTTONS; i++)
        destroy_button(gb->buttons[i]);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(gb->background));
    sfSprite_destroy(gb->background);
    free(gb);
}

void draw_box(button_t *but, sfRenderTexture *rtex)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, but->size);
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineColor(shape, sfWhite);
    sfRectangleShape_setPosition(shape, but->pos);
    sfRectangleShape_setOutlineThickness(shape, but->size.x * 0.05);
    sfRectangleShape_setOrigin(shape,
    (sfVector2f){but->size.x * 0.5, but->size.y * 0.5});
    sfRenderTexture_drawRectangleShape(rtex, shape, NULL);
    sfRectangleShape_destroy(shape);
}

sfSprite *draw_gb(game_t *ga)
{
    game_buttons_t *g = ga->gb;
    sfVector2u tex_size = sfRenderTexture_getSize(g->rtex);
    sfVector2f pos = {tex_size.x * 0.2, tex_size.y * 0.2 - g->y_offset};

    sfRenderTexture_clear(g->rtex, sfBlack);
    sfRenderTexture_drawSprite(g->rtex, g->background, NULL);
    for (int i = 0; i < NB_BUTTONS;) {
        for (int j = 0; j < 3 && i < NB_BUTTONS; j++, i++) {
            sfSprite_setPosition(g->buttons[i]->sprite, pos);
            g->buttons[i]->pos = pos;
            draw_button_to_rtex(g->buttons[i], g->rtex);
            if (i == g->selected)
                draw_box(g->buttons[i], g->rtex);
            pos.x += tex_size.x * 0.3;
        }
        pos.x = tex_size.x * 0.2;
        pos.y += tex_size.y * 0.37;
    }
    sfRenderTexture_display(g->rtex);
    return init_sprite_from_texture(sfRenderTexture_getTexture(g->rtex));
}

void create_gb_buttons(game_buttons_t *gb, sfVector2f size)
{
    sfVector2f n_size = {size.x * gb_size[0], size.x * gb_size[0]};
    void (*actions[NB_BUTTONS])(void *) = {
        NULL, NULL, NULL,
        NULL, NULL, switch_brush_type,
        restart_map, save_game, quit_game,
        pause_game, add_hour, sub_hour,
        get_help
    };

    for (int i = 0; i < NB_BUTTONS; i++) {
        gb->buttons[i] = init_button(global_texture(), gb_rects[i],
        (sfVector2f){0, 0}, n_size, "", actions[i]);
        center_sprite(gb->buttons[i]->sprite);
    }
}

game_buttons_t *create_buttons(sfVector2f size)
{
    game_buttons_t *g = malloc(sizeof(game_buttons_t));
    sfIntRect tmp = hider_rect;
    sfTexture *tex = sfTexture_createFromFile(TEXTURE, &tmp);

    g->rtex = sfRenderTexture_create(size.x, size.y, 0);
    create_gb_buttons(g, size);
    g->border = create_rectangle((sfVector2f){1, 1}, sfWhite, NULL);
    g->selected = 0;
    g->tip_clock = sfClock_create();
    create_tooltip(g, size);
    g->mouse_pos = (sfVector2f){0, 0};
    sfTexture_setRepeated(tex, 1);
    g->background = init_sprite_from_texture(tex);
    sfSprite_setTextureRect(g->background, (sfIntRect){0, 0, size.x, size.y});
    g->y_offset = 0;
    return g;
}
