/*
** EPITECH PROJECT, 2021
** world_menus
** File description:
** main_menu.c
*/

#include "menus.h"
#include "main_menu.h"

void main_menu_release(main_menu_t *m, sfEvent ev, window_t *win)
{
    int win_act[4] = {MAP_SELECT, CREATE_MAP, SETTINGS, EXIT};
    int action = button_at(m->buttons, 4, ev);

    for (int i = 0; i < 4; i++) {
        hover_button(m->buttons[i], 0);
        press_button(m->buttons[i], 0);
    }
    if (action < 0)
        return;
    set_next_win_state(win, win_act[action]);
}

void main_menu_event(window_t *win, sfEvent ev)
{
    main_menu_t *m = win->menus[0];
    if (ev.type == sfEvtMouseMoved)
        check_button_move(m->buttons, 4, ev);
    if (ev.type == sfEvtMouseButtonPressed)
        check_button_press(m->buttons, 4, ev);
    if (ev.type == sfEvtMouseButtonReleased)
        main_menu_release(m, ev, win);
}

void destroy_home(main_menu_t *menu)
{
    sfRenderTexture_destroy(menu->text);
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(menu->buttons[i]->sprite);
        sfText_destroy(menu->buttons[i]->text);
        free(menu->buttons[i]);
    }
    free(menu);
}

const sfTexture *draw_main_menu(window_t *win)
{
    main_menu_t *menu = win->menus[HOME];
    sfRenderTexture_clear(menu->text, sfBlack);

    draw_spectator_to_rtex(win->spec, menu->text, 0, 1);
    for (int i = 0; i < 4; i++)
        draw_button_to_rtex(menu->buttons[i], menu->text);
    sfRenderTexture_display(menu->text);
    return sfRenderTexture_getTexture(menu->text);
}

main_menu_t *init_main_menu(sfTexture *t, sfVector2f winSize)
{
    main_menu_t *m = malloc(sizeof(main_menu_t));

    m->text = sfRenderTexture_create(winSize.x, winSize.y, 0);
    for (int i = 0; i < 4; i++)
        m->buttons[i] = init_button(t, button_rects[i / 2],
        (sfVector2f){1, 1}, (sfVector2f){1, 1}, button_texts[i], NULL);
    scale_main_buttons(m->buttons, winSize);
    move_main_buttons(m->buttons, winSize);
    return m;
}
