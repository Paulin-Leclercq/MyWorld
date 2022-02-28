/*
** EPITECH PROJECT, 2022
** movement.c
** File description:
** movement
*/

#include "world.h"

void move_player(mat4x4 **mat_world)
{
    mat4x4 *mat_mov;
    mat4x4 *tmp;
    float vec[3] = {0, 0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        vec[2] = 0.5;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        vec[2] = -0.5;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        vec[0] = -0.5;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        vec[0] = 0.5;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        vec[1] = 0.5;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        vec[1] = -0.5;
    mat_mov = mat4x4_t(vec);
    tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
    mat4x4_destroy(mat_mov);
    mat4x4_destroy(*mat_world);
    *mat_world = tmp;
}

void move_cam(mat4x4 **mat_world)
{
    mat4x4 *tmp;
    mat4x4 *mat_mov = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyJ))
        mat_mov = mat4x4_ry(-PI / 180);
    if (sfKeyboard_isKeyPressed(sfKeyL))
        mat_mov = mat4x4_ry(PI / 180);
    if (sfKeyboard_isKeyPressed(sfKeyI))
        mat_mov = mat4x4_rx(-PI / 180);
    if (sfKeyboard_isKeyPressed(sfKeyK))
        mat_mov = mat4x4_rx(PI / 180);
    if (mat_mov != NULL) {
        tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        mat4x4_destroy(mat_mov);
        mat4x4_destroy(*mat_world);
        *mat_world = tmp;
    }
}

void move_angle(mat4x4 **mat_world)
{
    mat4x4 *mat_mov = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyW))
        mat_mov = mat4x4_rz(PI / 180);
    if (sfKeyboard_isKeyPressed(sfKeyX))
        mat_mov = mat4x4_rz(-PI / 180);
    if (mat_mov != NULL) {
        *mat_world = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        mat4x4_destroy(mat_mov);
    }
}

void move(mat4x4 **mat_world)
{
    move_player(mat_world);
    move_cam(mat_world);
    move_angle(mat_world);
}
