/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** apply.c
*/

#include "menus.h"

void recreate_render_texture(window_t *win)
{
    sfRenderTexture_destroy(((main_menu_t *)win->menus[0])->text);
    ((main_menu_t *)win->menus[0])->text =
    sfRenderTexture_create(win->mode.width, win->mode.height, 0);

    sfRenderTexture_destroy(((settings_t *)win->menus[2])->rtex);
    ((settings_t *)win->menus[2])->rtex =
    sfRenderTexture_create(win->mode.width, win->mode.height, 0);
}

void apply_mode(settings_t *se, window_t *win)
{
    bool is_fullscreen = se->full_screen->is_checked;

    if (is_fullscreen) {
        sfSprite_setColor(se->res_button->sprite,
        (sfColor){127, 127, 127, 255});
        win->mode = sfVideoMode_getDesktopMode();
    }
    else
        win->mode = available_modes[se->resolution];
    recreate_render_texture(win);
    sfRenderWindow_destroy(win->win);
    win->win = sfRenderWindow_create(win->mode, "My world",
    is_fullscreen ? sfFullscreen : sfClose, NULL);
    rescale_all(win);
}

void apply_musics(window_t *win, settings_t *se)
{
    se->sfx_vol++;
    sfx_minus(se, win);

    se->music_vol++;
    music_minus(se, win);
}

void apply_settings(settings_t *se, window_t *win)
{
    apply_mode(se, win);
    sfRenderWindow_setFramerateLimit(win->win,
    available_framerates[se->framerate]);
    sfRenderWindow_setVerticalSyncEnabled(win->win, se->vsync->is_checked);
    apply_musics(win, se);
    update_all_texts(se);
}
