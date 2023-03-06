/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** sound_evt.c
*/

#include "menus.h"
#include <stdarg.h>

void update_vol(float m_vol, float s_vol, char const *format, ...)
{
    va_list list;
    void *v;

    va_start(list, format);
    for (int i = 0; format[i]; i++) {
        v = va_arg(list, void *);
        if (!v)
            continue;
        if (format[i] == 's')
            sfSound_setVolume(v, s_vol);
        if (format[i] == 'm')
            sfMusic_setVolume(v, m_vol);
    }
    va_end(list);
}

void sfx_minus(settings_t *se)
{
    if (se->sfx_vol == 0)
        return;
    se->sfx_vol--;
}

void sfx_plus(settings_t *se)
{
    if (se->sfx_vol == 100)
        return;
    se->sfx_vol++;
}

void music_minus(settings_t *se)
{
    if (se->music_vol == 0)
        return;
    se->music_vol--;
}

void music_plus(settings_t *se)
{
    if (se->music_vol == 100)
        return;
    se->music_vol++;
}
