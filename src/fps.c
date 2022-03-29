/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** fps.c
*/

#include "world.h"
#include "my.h"
#include <math.h>
#include "menus.h"

char *ftoa(float n, int afterpoint)
{
    int ipart = ABS((int)n);
    float fpart = ABS(n - (float)ipart);
    char *ip = long_to_str(ipart);
    char *fp = long_to_str(fpart * pow(10, afterpoint));
    char *res;

    if (afterpoint != 0) {
        res = str_concat(3, ip, ".", fp);
        free(ip);
    } else
        res = ip;
    free(fp);
    return res;
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
        sfText_setFont(*t, global_font());
    }
    sfText_setCharacterSize(*t, size.x / 27.0);
    sfText_setPosition(*t, (sfVector2f){size.x * 0.8, 0});
}

void draw_fps(win_t *w)
{
    static sfClock *c = NULL;
    static sfText *t = NULL;
    static sfTime last_time = {0};
    float fps;
    char *fps_str;

    init_graph(&c, &t, w);
    fps = 1000000.0 /
    (sfClock_getElapsedTime(c).microseconds - last_time.microseconds);
    fps_str = ftoa(fps, 2);
    last_time = sfClock_getElapsedTime(c);
    append(&fps_str, " FPS", 1);
    if (sfClock_getElapsedTime(c).microseconds > 500000) {
        sfText_setString(t, fps_str);
        sfClock_restart(c);
    }
    free(fps_str);
    if (w->draw_fps)
        sfRenderTexture_drawText(w->r_tex, t, NULL);
}
