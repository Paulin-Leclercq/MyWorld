/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** save.c
*/

#include <unistd.h>
#include <fcntl.h>
#include "menus.h"
#include <sys/stat.h>

static void save_mode(int fd, settings_t *se)
{
    char res = se->resolution;

    if (se->full_screen->is_checked)
        res = 3;
    write(fd, &res, 1);
}

static void save_framerate(int fd, settings_t *se)
{
    char fram = se->framerate;

    write(fd, &fram, 1);
}

static void save_vsync(int fd, settings_t *se)
{
    char vsync = se->vsync->is_checked;

    write(fd, &vsync, 1);
}

static void save_musics(int fd, settings_t *se)
{
    char vol[2] = {se->sfx_vol, se->music_vol};

    write(fd, vol, 2);
}

void save_settings(settings_t *se)
{
    int fd = open(SETTINGS_FILE, O_WRONLY | O_CREAT | O_TRUNC, ALL_FLAGS);

    if (fd < 0)
        return;
    save_mode(fd, se);
    save_framerate(fd, se);
    save_vsync(fd, se);
    save_musics(fd, se);
}
