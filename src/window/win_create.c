/*
** EPITECH PROJECT, 2022
** win_create.c
** File description:
** win_create
*/

#include "world.h"

void destroy_win(win_t *win)
{
    sfRenderTexture_destroy(win->r_tex);
    sfConvexShape_destroy(win->convex);
    sfCircleShape_destroy(win->circle);
    free(win->params);
    free(win);
}

void init_params(win_t *win, size_t size)
{
    win->circle = sfCircleShape_create();
    win->convex = sfConvexShape_create();
    win->array = sfVertexArray_create();
    sfVertexArray_resize(win->array, size);
    win->tmp = malloc(sizeof(sfVertex));
    sfVertexArray_setPrimitiveType(win->array, sfTriangles);
    sfCircleShape_setRadius(win->circle, 8);
    sfConvexShape_setPointCount(win->convex, 3);
    sfConvexShape_setOutlineColor(win->convex, sfTransparent);
    win->params = malloc(sizeof(params_t));
    win->params->hour = 0;
    win->params->day = DAY;
    win->params->pause = 0;
    win->params->is_fill = IS_FILL;
    win->params->is_outline = IS_OUTLINE;
}

win_t *win_create(size_t nb_trig, sfVector2f size)
{
    win_t *win = malloc(sizeof(win_t));

    if (win == NULL)
        return NULL;
    memset(win, 0, sizeof(win_t));
    win->settings.antialiasingLevel = ALIASING;
    win->destroy = destroy_win;
    win->draw_shape = draw_shape;
    win->draw_circle = draw_circle;
    win->r_tex = sfRenderTexture_create(size.x, size.y, 0);
    init_params(win, nb_trig);
    return win;
}
