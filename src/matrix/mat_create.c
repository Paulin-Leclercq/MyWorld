/*
** EPITECH PROJECT, 2022
** mat_create.c
** File description:
** mat_create
*/

#include "world.h"

mat4x4 *mat4x4_rx(float a)
{
    mat4x4 *mat = mat4x4_create();

    mat->val[5] = cosf(a);
    mat->val[6] = sinf(a);
    mat->val[9] = -sinf(a);
    mat->val[10] = cosf(a);
    return mat;
}

mat4x4 *mat4x4_ry(float a)
{
    mat4x4 *mat = mat4x4_create();

    mat->val[0] = cosf(a);
    mat->val[2] = sinf(a);
    mat->val[8] = -sinf(a);
    mat->val[10] = cosf(a);
    return mat;
}

mat4x4 *mat4x4_rz(float a)
{
    mat4x4 *mat = mat4x4_create();

    mat->val[0] = cosf(a);
    mat->val[1] = sinf(a);
    mat->val[4] = -sinf(a);
    mat->val[5] = cosf(a);
    return mat;
}

mat4x4 *mat4x4_t(float *vector)
{
    mat4x4 *mat = mat4x4_create();

    mat->val[12] = vector[0];
    mat->val[13] = vector[1];
    mat->val[14] = vector[2];
    return mat;
}
