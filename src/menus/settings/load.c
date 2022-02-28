/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** load.c
*/

#include <unistd.h>
#include <fcntl.h>
#include "menus.h"
#include <sys/stat.h>

void load_mode(int fd, settings_t *se)
{
    char mode;

    if (read(fd, &mode, 1) != 1)
        return;
    if (mode == 3)
        se->full_screen->is_checked = 1;
    else if (mode >= 0 && mode <= 2)
        se->resolution = mode;
}

void load_framerate(int fd, settings_t *se)
{
    char fram;

    if (read(fd, &fram, 1) != 1)
        return;
    if (fram >= 0 && fram <= 4)
        se->framerate = fram;
}

void load_vsync(int fd, settings_t *se)
{
    char vsync;

    if (read(fd, &vsync, 1) != 1)
        return;
    se->vsync->is_checked = vsync;
}

void load_musics(int fd, settings_t *se)
{
    char data[2];
    int c = read(fd, data, 2);

    if (c <= 0 || c > 2)
        return;
    if (data[0] >= 0 && data[0] <= 100)
    se->sfx_vol = data[0];
    if (c == 2 && data[1] >= 0 && data[1] <= 100)
        se->music_vol = data[1];
}

void load_settings(settings_t *se)
{
    int fd = open(SETTINGS_FILE, O_RDONLY);

    if (fd < 0)
        return;
    load_mode(fd, se);
    load_framerate(fd, se);
    load_vsync(fd, se);
    load_musics(fd, se);
}
