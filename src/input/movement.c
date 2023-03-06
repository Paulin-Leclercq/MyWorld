/*
** EPITECH PROJECT, 2022
** movement.c
** File description:
** movement
*/

#include "world.h"

static sfBool is_key(int code)
{
    return sfKeyboard_isKeyPressed(code);
}

void move_player(mat4x4 **mat_world, double factor)
{
    mat4x4 *mat_mov;
    mat4x4 *tmp;
    float vec[3] = {0, 0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        vec[2] = factor;
    if (is_key(sfKeyS) && !is_key(sfKeyLControl) && !is_key(sfKeyRControl))
        vec[2] = -factor;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        vec[0] = -factor;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        vec[0] = factor;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        vec[1] = factor;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        vec[1] = -factor;
    mat_mov = mat4x4_t(vec);
    tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
    mat4x4_destroy(mat_mov);
    mat4x4_destroy(*mat_world);
    *mat_world = tmp;
}

void move_cam(mat4x4 **mat_world, double factor)
{
    mat4x4 *tmp;
    mat4x4 *mat_mov = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyJ))
        mat_mov = mat4x4_ry(-PI / 90 * factor);
    if (sfKeyboard_isKeyPressed(sfKeyL))
        mat_mov = mat4x4_ry(PI / 90 * factor);
    if (sfKeyboard_isKeyPressed(sfKeyI))
        mat_mov = mat4x4_rx(-PI / 90 * factor);
    if (sfKeyboard_isKeyPressed(sfKeyK))
        mat_mov = mat4x4_rx(PI / 90 * factor);
    if (mat_mov) {
        tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        mat4x4_destroy(mat_mov);
        mat4x4_destroy(*mat_world);
        *mat_world = tmp;
    }
}

void move_angle(mat4x4 **mat_world, double factor)
{
    mat4x4 *mat_mov = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyW))
        mat_mov = mat4x4_rz(PI / 90 * factor);
    if (sfKeyboard_isKeyPressed(sfKeyX))
        mat_mov = mat4x4_rz(-PI / 90 * factor);
    if (mat_mov != NULL) {
        *mat_world = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        mat4x4_destroy(mat_mov);
    }
}

void move(world_t *world, win_t *win)
{
    double factor = sfClock_getElapsedTime(win->evt_clock).microseconds;

    factor /= 30000.0;
    move_player(&world->matrix, factor);
    move_cam(&world->matrix, factor);
    move_angle(&world->matrix, factor);
    sfClock_restart(win->evt_clock);
}
