/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** static_event.c
*/

#include "menus.h"
#include "tooltips.h"

int get_button(game_buttons_t *gb)
{
    sfEvent ev;
    int but;

    ev.type = sfEvtMouseButtonReleased;
    ev.mouseButton.x = gb->mouse_pos.x;
    ev.mouseButton.y = gb->mouse_pos.y;
    but = button_at(gb->buttons, NB_BUTTONS, ev);
    if (but < 0 || but >= NB_BUTTONS)
        return -1;
    return but;
}

void draw_tooltip(game_t *ga, sfRenderTexture *rtex)
{
    int but;
    game_buttons_t *gb = ga->gb;
    sfFloatRect rect;
    float delta_y = sfRenderTexture_getSize(gb->rtex).y *
    (PART_OF_MINIMAP / (1 - PART_OF_MINIMAP));

    but = get_button(gb);
    if (but < 0)
        return;
    sfText_setString(gb->tooltip, tips[but]);
    sfText_setPosition(gb->tooltip, gb->mouse_pos);
    sfRectangleShape_setPosition(gb->tooltip_box, gb->mouse_pos);
    rect = sfText_getGlobalBounds(gb->tooltip);
    sfRectangleShape_setSize(gb->tooltip_box,
    (sfVector2f){rect.width, rect.height * 1.4});
    sfText_move(gb->tooltip, (sfVector2f){0, delta_y});
    sfRectangleShape_move(gb->tooltip_box, (sfVector2f){0, delta_y});
    sfRenderTexture_drawRectangleShape(rtex, gb->tooltip_box, NULL);
    sfRenderTexture_drawText(rtex, gb->tooltip, NULL);
}

void check_tooltip(game_t *ga)
{
    game_buttons_t *gb = ga->gb;

    if (sfClock_getElapsedTime(gb->tip_clock).microseconds
    < TOOLTIP_DURATION) {
        gb->tool_tip_enabled = false;
    } else
        gb->tool_tip_enabled = get_button(gb) >= 0 ? true : false;
}
