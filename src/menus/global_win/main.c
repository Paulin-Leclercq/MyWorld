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
    destroy_spectator(win->spec);
    destroy_map_select(win->menus[MAP_SELECT]);
    free(win);
}

void draw(window_t *win)
{
    const sfTexture* tex = win->draw[win->state](win);
    sfSprite *s = init_sprite_from_texture(tex);

    sfSprite_setTexture(s, sfTexture_copy(sfSprite_getTexture(s)), 0);
    if (win->is_transition)
        update_transition(win, s);
    sfRenderWindow_clear(win->win, sfBlack);
    sfRenderWindow_drawSprite(win->win, s, NULL);
    sfRenderWindow_display(win->win);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(s));
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
            win->next_state = EXIT;
        if (!win->is_transition)
            win->event[win->state](win, ev);
        if (IS_WORLD_CLICK)
            world_clicks(win, ev);
    }
    if (win->state == SETTINGS)
        check_sound_repeat(win, &ev);
    if (win->state == EDIT_MAP) {
        move(((game_t *)win->menus[EDIT_MAP])->world
        , ((game_t *)win->menus[EDIT_MAP])->win);
        if (mouse_pos(win_size, win) == MINIMAP)
            apply_minimap_brush(win->menus[EDIT_MAP]);
        if (!win->is_fullscreen)
            check_tooltip(win->menus[EDIT_MAP]);
    }
}

int main(int ac, char **av)
{
    window_t *win;

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage();
    if (!global_texture() || !global_font())
        return 84;
    win = window_create(ac, av);
    if (!win)
        return 84;
    srand(rand_seed());
    win->is_fullscreen = 0;
    while (sfRenderWindow_isOpen(win->win)) {
        poll_events(win);
        draw(win);
    }
    win_destroy(win);
    clear_textures();
    sfFont_destroy(global_font());
    sfTexture_destroy(global_texture());
    return 0;
}
