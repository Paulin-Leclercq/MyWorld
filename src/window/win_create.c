/*
** EPITECH PROJECT, 2022
** win_create.c
** File description:
** win_create
*/

#include "world.h"

void destroy_win2(win_t *win)
{
    sfClock_destroy(win->evt_clock);
    free(win->states);
    free(win->sounds);
    free(win->musics);
    free(win->params);
    free(win->tmp);
    free(win);
}

void destroy_win(win_t *win)
{
    sfRenderTexture_destroy(win->r_tex);
    sfConvexShape_destroy(win->convex);
    sfCircleShape_destroy(win->circle);
    sfVertexArray_destroy(win->array);
    sfTexture_destroy((sfTexture *)win->states->texture);
    for (int i = 0; i < NB_SOUNDS; i++) {
        sfSound_stop(win->sounds[i]);
        sfSoundBuffer_destroy((sfSoundBuffer *)
        sfSound_getBuffer(win->sounds[i]));
        sfSound_destroy(win->sounds[i]);
    }
    for (int i = 0; i < NB_MUSICS; i++) {
        sfMusic_stop(win->musics[i]);
        sfMusic_destroy(win->musics[i]);
    }
    destroy_win2(win);
}

void init_params(win_t *win, size_t size)
{
    win->evt_clock = sfClock_create();
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
    win->params->zoom = 1;
    win->params->hour = 0;
    win->params->day = DAY;
    win->params->pause = 0;
    win->params->is_fill = IS_FILL;
    win->params->is_outline = IS_OUTLINE;
}

win_t *win_create(size_t nb_trig, sfVector2f size)
{
    win_t *win = malloc(sizeof(win_t));
    sfIntRect rect = {0, 0, 2000, 2000};
    if (win == NULL)
        return NULL;
    my_memset(win, 0, sizeof(win_t));
    win->draw_fps = 0;
    win->states = malloc(sizeof(sfRenderStates));
    win->states->shader = 0;
    win->states->texture = sfTexture_createFromFile("assets/pat.png", &rect);
    win->states->blendMode = sfBlendNone;
    win->states->transform = sfTransform_Identity;
    win->settings.antialiasingLevel = ALIASING;
    win->destroy = destroy_win;
    win->draw_shape = draw_shape;
    win->draw_circle = draw_circle;
    win->r_tex = sfRenderTexture_create(size.x, size.y, 0);
    init_params(win, nb_trig);
    create_sounds(win);
    create_musics(win);
    return win;
}
