/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** fps.c
*/

#include "world.h"
#include "my.h"
#include <math.h>

int int_to_str(int x, char str[], int d)
{
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
    while (i < d)
        str[i++] = '0';
    str[i] = '\0';
    my_revstr(str);
    return i;
}

void ftoa(float n, char* res, int afterpoint)
{
    int ipart = (int)n;
    float fpart = n - (float)ipart;
    int i = int_to_str(ipart, res, 0);

    if (afterpoint != 0) {
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint);
        int_to_str((int)fpart, res + i + 1, afterpoint);
    }
}

void append(char **str, char *buf, int is_free)
{
    char *tmp = *str;
    int len = my_strlen(tmp) + my_strlen(buf);
    char *new = malloc(sizeof(char) * (len + 1));

    my_strcpy(new, tmp);
    my_strcat(new, buf);
    new[len] = '\0';
    if (is_free)
        free(tmp);
    *str = new;
}

void init_graph(sfClock **c, sfText **t, win_t *w)
{
    sfVector2u size = sfRenderTexture_getSize(w->r_tex);
    if (!(*t)) {
        *c = sfClock_create();
        *t = sfText_create();
        sfText_setFont(*t, sfFont_createFromFile("pusab.otf"));
    }
    sfText_setCharacterSize(*t, size.x / 30.0);
    sfText_setPosition(*t, (sfVector2f){size.x * 0.8, 0});
}

void draw_fps(win_t *w)
{
    static sfClock *c = NULL;
    static sfText *t = NULL;
    static sfTime last_time = {0};
    float fps;
    char *fps_str = malloc(7);

    init_graph(&c, &t, w);
    fps = 1000000.0 /
    (sfClock_getElapsedTime(c).microseconds - last_time.microseconds);
    ftoa(fps, fps_str, 2);
    last_time = sfClock_getElapsedTime(c);
    append(&fps_str, " FPS", 1);
    if (sfClock_getElapsedTime(c).microseconds > 500000) {
        sfText_setString(t, fps_str);
        sfClock_restart(c);
    }
    sfRenderTexture_drawText(w->r_tex, t, NULL);
}
