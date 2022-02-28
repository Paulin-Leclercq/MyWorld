/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** sound_evt.c
*/

#include "menus.h"
#include <stdarg.h>

void update_vol(float vol, char const *format, ...)
{
    va_list list;
    void *v;

    va_start(list, format);
    for (int i = 0; format[i]; i++) {
        v = va_arg(list, void *);
        if (!v)
            continue;
        if (format[i] == 's')
            sfSound_setVolume(v, vol);
        if (format[i] == 'm')
            sfMusic_setVolume(v, vol);
    }
    va_end(list);
}

void sfx_minus(settings_t *se, window_t *win)
{
    if (se->sfx_vol == 0)
        return;
    se->sfx_vol--;
    update_vol(se->sfx_vol, "");
    //win->lpick->launch_sound, win->oof, win->coin, win->death_sound);
}

void sfx_plus(settings_t *se, window_t *win)
{
    if (se->sfx_vol == 100)
        return;
    se->sfx_vol++;
    update_vol(se->sfx_vol, "");
    //win->lpick->launch_sound, win->oof, win->coin, win->death_sound);
}

void music_minus(settings_t *se, window_t *win)
{
    if (se->music_vol == 0)
        return;
    se->music_vol--;
    update_vol(se->music_vol, "");//, win->lobby_music);
}

void music_plus(settings_t *se, window_t *win)
{
    if (se->music_vol == 100)
        return;
    se->music_vol++;
    update_vol(se->music_vol, "");//, win->lobby_music);
}
