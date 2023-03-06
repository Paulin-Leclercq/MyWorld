/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** release.c
*/

#include "menus.h"

const sfTexture *draw_mc(window_t *win)
{
    sfSprite *s;
    map_create_t *mc = win->menus[CREATE_MAP];
    sfVector2f ws = {win->mode.width, win->mode.height};

    sfRenderTexture_clear(mc->rtex, sfBlack);
    draw_spectator_to_rtex(win->spec, mc->rtex, 1, 1);
    sfRenderTexture_drawText(mc->rtex, mc->name_prompt, NULL);
    s = draw_line_edit(mc->name, (sfVector2f){ws.x * 0.04, ws.y * 0.23});
    sfRenderTexture_drawSprite(mc->rtex, s, NULL);
    sfSprite_destroy(s);
    update_size_text(mc->size, mc->size_slider);
    sfRenderTexture_drawText(mc->rtex, mc->size, NULL);
    s = draw_slider(mc->size_slider);
    sfRenderTexture_drawSprite(mc->rtex, s, NULL);
    sfSprite_destroy(s);
    for (int i = 0; i < 4; i++)
        draw_button_to_rtex(mc->buttons[i], mc->rtex);
    sfRenderTexture_display(mc->rtex);
    return (sfRenderTexture_getTexture(mc->rtex));
}

void destroy_mc(map_create_t *mc)
{
    destroy_line_edit(mc->name);
    sfText_destroy(mc->name_prompt);
    sfText_destroy(mc->size);
    destroy_slider(mc->size_slider);
    sfRenderTexture_destroy(mc->rtex);
    for (int i = 0; i < 4; i++)
        destroy_button(mc->buttons[i]);
    free(mc);
}

void release_mc(map_create_t *mc, int index, window_t *win)
{
    bool cont = index >= 0 ? mc->buttons[index]->is_press : false;

    for (int i = 0; i < 4; i++)
        press_button(mc->buttons[i], false);
    if (cont && index >= 0 && index < 4)
        mc->buttons[index]->action(win);
}
