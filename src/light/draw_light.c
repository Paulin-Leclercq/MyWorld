/*
** EPITECH PROJECT, 2022
** Workshop3D v4.0
** File description:
** draw
*/

#include "world.h"

void if_rota_left(world_t *world, win_t *win, mat4x4 *mat_mov, float *tmp2)
{
    for (int i = 0; i < 3; i++)
        world->light_source[i] = world->light_start[i];
    win->params->day = !win->params->day;
    win->params->hour = win->params->day ? 16 : 6;
    free(mat_mov);
    mat_mov = mat4x4_rx(win->params->day ? 16 * -PI / 16.5 : 6 * -PI / 7);
    mat4x4_multiplyvector3(mat_mov, world->light_source, tmp2);
    free(world->light_source);
    world->light_source = tmp2;
}

void rota_left(world_t *world, win_t *win)
{
    float *tmp = malloc(sizeof(float) * 3);
    float *tmp2 = malloc(sizeof(float) * 3);
    mat4x4 *mat_mov = mat4x4_rx(win->params->day ? PI / 16.5 : PI / 7);
    mat4x4_multiplyvector3(mat_mov, world->light_source, tmp);
    free(world->light_source);
    world->light_source = tmp;
    win->params->hour--;
    if (world->light_source[1] < 0)
        if_rota_left(world, win, mat_mov, tmp2);
    else
        free(tmp2);
    smooth_shadow(world, win);
    free(mat_mov);
}

void rota_right(world_t *world, win_t *win)
{
    float *tmp = malloc(sizeof(float) * 3);
    mat4x4 *mat_mov = mat4x4_rx(win->params->day ? -PI / 16.5 : -PI / 7);

    mat4x4_multiplyvector3(mat_mov, world->light_source, tmp);
    free(world->light_source);
    world->light_source = tmp;
    win->params->hour++;
    if (world->light_source[1] < 1) {
        world->light_source[0] = world->light_start[0];
        world->light_source[1] = world->light_start[1];
        world->light_source[2] = world->light_start[2];
        win->params->day = !win->params->day;
        win->params->hour = 0;
    }
    smooth_shadow(world, win);
    free(mat_mov);
}

void move_light(world_t *world, win_t *win)
{
    float *tmp = malloc(sizeof(float) * 3);
    mat4x4 *mat_mov = mat4x4_rx((win->params->day ? -PI / 82 : -PI / 35) / 30);

    mat4x4_multiplyvector3(mat_mov, world->light_source, tmp);
    sfClock_restart(world->clock);
    free(world->light_source);
    world->light_source = tmp;
    win->params->hour++;
    if (world->light_source[1] < 1) {
        world->light_source[0] = world->light_start[0];
        world->light_source[1] = world->light_start[1];
        world->light_source[2] = world->light_start[2];
        win->params->day = !win->params->day;
        win->params->hour = 0;
    }
    smooth_shadow(world, win);
    free(mat_mov);
}

void draw_light(world_t *world, win_t *win)
{
    float *vertx = malloc(sizeof(float) * 3);

    mat4x4_multiplyvector3(world->matrix, world->light_source, vertx);
    vertx[0] /= vertx[2];
    vertx[1] /= vertx[2];
    vertx[0] += 1;
    vertx[1] += 1;
    vertx[0] *= 400;
    vertx[1] *= 400;
    sfCircleShape_setFillColor(win->circle,
    win->params->day ? sfYellow : sfWhite);
    sfCircleShape_setPosition(win->circle, (sfVector2f) {vertx[0], vertx[1]});
    sfRenderTexture_drawCircleShape(win->r_tex, win->circle, 0);
    free(vertx);
}
