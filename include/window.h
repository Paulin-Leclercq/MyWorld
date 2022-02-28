/*
** EPITECH PROJECT, 2022
** window.h
** File description:
** window
*/

#ifndef WINDOW_H
    #define WINDOW_H

    #include "world.h"

    #define VSYNC 1
    #define FPS 144
    #define ALIASING 8

static const sfVideoMode mode = {1600, 800, 32};

static const sfUint32 STYLE = sfResize | sfClose;

typedef struct window_t {
    sfEvent event;
    sfVertex *tmp;
    size_t map_size;
    params_t *params;
    sfCircleShape *circle;
    sfConvexShape *convex;
    sfVertexArray *array;
    sfContextSettings settings;
    sfBool (*is_open)(struct window_t *win);
    sfBool (*poll_event)(struct window_t *win);
    void (*destroy)(struct window_t *win);
    void (*display)(struct window_t *win);
    void (*draw_shape)(struct window_t *win, size_t nb, ...);
    void (*draw_circle)(struct window_t *win, size_t nb, ...);
    sfRenderTexture *r_tex;
} win_t;

win_t *win_create(size_t nb_trig, sfVector2f size);
void display(win_t *win);
void draw_shape(win_t *win, size_t nb, ...);
void draw_circle(win_t *win, size_t nb, ...);
void draw_rtex_to_win(sfRenderTexture *t, sfRenderWindow *w);

#endif
