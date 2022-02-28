/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** main.c
*/

#include "menus.h"

void win_destroy(window_t *win)
{
    sfRenderWindow_destroy(win->win);
    destroy_home(win->menus[0]);
    save_settings(win->menus[2]);
    destroy_settings(win->menus[2]);
    sfClock_destroy(win->lum_clock);
    destroy_mc(win->menus[3]);
    free(win);
}

void draw(window_t *win)
{
    const sfTexture* tex = (win->state == CREATE_MAP) ? draw_mc(win->menus[3],
    (sfVector2f){win->mode.width, win->mode.height}) :
    win->draw[win->state](win->menus[win->state]);
    sfSprite *s = init_sprite_from_texture(tex);

    if (win->is_transition)
        update_transition(win, s);
    sfRenderWindow_clear(win->win, sfBlack);
    sfRenderWindow_drawSprite(win->win, s, NULL);
    sfRenderWindow_display(win->win);
    sfSprite_destroy(s);
}

void set_next_win_state(window_t *win, int next)
{
    win->next_state = next;
    win->is_transition = true;
}

void poll_events(window_t *win)
{
    sfEvent ev;
    sfVector2f win_size = {win->mode.width, win->mode.height};
    while (sfRenderWindow_pollEvent(win->win, &ev)) {
        if (ev.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
        if (!win->is_transition)
            win->event[win->state](win, ev);
    }
    if (win->state == SETTINGS)
        check_sound_repeat(win, &ev);
    if (win->state == EDIT_MAP) {
        if (sfKeyboard_isKeyPressed(sfKeyS) && (sfKeyboard_isKeyPressed
        (sfKeyLControl) || sfKeyboard_isKeyPressed(sfKeyRControl)))
            save_map(win->menus[EDIT_MAP], sfText_getString(((map_create_t *)
            win->menus[CREATE_MAP])->name->text), ((game_t *)win->menus
            [EDIT_MAP])->win->map_size);
        move(&(((game_t *)win->menus[EDIT_MAP])->world->matrix));
        if (mouse_pos(win_size, win) == MINIMAP)
            minimap_clicks(win->menus[EDIT_MAP]);
    }
}

int main(void)
{
    window_t *win = window_create();

    srand((unsigned)(unsigned long)(&win));
    while (sfRenderWindow_isOpen(win->win)) {
        poll_events(win);
        draw(win);
    }
    win_destroy(win);
    sfFont_destroy(global_font());
    sfTexture_destroy(global_texture());
    return 0;
}
