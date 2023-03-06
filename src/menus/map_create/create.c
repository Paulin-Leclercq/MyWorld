/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create.c
*/

#include "menus.h"
#include "my.h"

void scale_map_create(map_create_t *mc, sfVector2f ws)
{
    sfVector2f new_size;
    sfRenderTexture_destroy(mc->rtex);
    mc->rtex = sfRenderTexture_create(ws.x, ws.y, 0);
    sfText_setCharacterSize(mc->name_prompt,
    ws.y * MAIN_MENU_TXT_FACTOR * 0.13);
    sfText_setCharacterSize(mc->size,
    ws.y * MAIN_MENU_TXT_FACTOR * 0.13);
    scale_line_edit(mc->name,
    (sfVector2f){ws.x * 0.9, ws.y * 0.2});
    rescale_slider(mc->size_slider, (sfVector2f){ws.x * 0.55, ws.y * 0.1},
    (sfVector2f){ws.x * 0.205, ws.y * 0.64});
    for (int i = 0; i < 4; i++) {
        new_size = (sfVector2f){ws.x * mc_size_fac[i][0],
        ws.y * mc_size_fac[i][1]};
        if (i < 2)
            new_size.y = new_size.x;
        set_sprite_size(mc->buttons[i]->sprite, new_size);
        mc->buttons[i]->size = new_size;
        center_sprite(mc->buttons[i]->sprite);
    }
}

void move_mc(map_create_t *mc, sfVector2f ws)
{
    sfVector2f new_pos;

    sfText_setPosition(mc->name_prompt,
    (sfVector2f){ws.x * 0.28, ws.y * 0.07});
    sfText_setPosition(mc->size, (sfVector2f){ws.x * 0.33, ws.y * 0.5});
    for (int i = 0; i < 4; i++) {
        new_pos = (sfVector2f){ws.x * mc_pos_fac[i][0],
        ws.y * mc_pos_fac[i][1]};
        sfSprite_setPosition(mc->buttons[i]->sprite, new_pos);
        mc->buttons[i]->pos = new_pos;
    }
}

void scale_mc(map_create_t *mc, sfVector2f win_size)
{
    scale_map_create(mc, win_size);
    for (int i = 2; i < 4; i++) {
        sfText_setCharacterSize(mc->buttons[i]->text, win_size.y * 0.07);
        center_text(mc->buttons[i]->text);
    }
    move_mc(mc, win_size);
}

void update_size_text(sfText *size, slider_t *slider)
{
    int value = slider->value;
    char *str = long_to_str(value);
    char *final = str_concat(3, str, "x", str);

    free(str);
    sfText_setString(size, final);
    free(final);
}

map_create_t *create_map_create(sfVector2f win_size)
{
    map_create_t *mc = malloc(sizeof(map_create_t));
    char *txts[4] = {"", "", "Cancel", "Create"};
    void (*ptrs[4])(void *) = {
        increase_size, decrease_size, mc_go_back, launch_size
    };

    mc->rtex = sfRenderTexture_create(win_size.x, win_size.y, 0);
    mc->name_prompt =
    init_text("Map name", win_size.y * MAIN_MENU_TXT_FACTOR);
    mc->name = create_line_edit(
    (sfVector2f){win_size.x * 0.8, win_size.y * 0.2}, "World_8");
    mc->size = init_text("64x64", win_size.y * MAIN_MENU_TXT_FACTOR);
    mc->size_slider = create_slider(
    (sfVector2f){win_size.x * 0.8, win_size.y * 0.2},
    (sfVector2f){16, 256}, 64, (sfVector2f){1, 1});
    for (int i = 0; i < 4; i++)
        mc->buttons[i] = init_button(global_texture(),
        mc_rects[i], DEFAULT_2F, DEFAULT_2F, txts[i], ptrs[i]);
    scale_mc(mc, win_size);
    return mc;
}
