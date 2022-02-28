/*
** EPITECH PROJECT, 2022
** mat_invert.c
** File description:
** mat_invert
*/

#include "world.h"

void make_calc_3(float *val, float *inv)
{
    inv[12] = -val[4] * val[9] * val[14] + val[4] * val[10] * val[13] + val
    [8] * val[5] * val[14] - val[8] * val[6] * val[13] - val[12] * val[5] * val
    [10] + val[12] * val[6] * val[9];
    inv[13] = val[0] * val[9] * val[14] - val[0] * val[10] * val[13] - val
    [8] * val[1] * val[14] + val[8] * val[2] * val[13] + val[12] * val[1] * val
    [10] - val[12] * val[2] * val[9];
    inv[14] = -val[0] * val[5] * val[14] + val[0] * val[6] * val[13] + val
    [4] * val[1] * val[14] - val[4] * val[2] * val[13] - val[12] * val[1] * val
    [6] + val[12] * val[2] * val[5];
    inv[15] = val[0] * val[5] * val[10] - val[0] * val[6] * val[9] - val[4]
    * val[1] * val[10] + val[4] * val[2] * val[9] + val[8] * val[1] * val[6] -
    val[8] * val[2] * val[5];
}

void make_calc_2(float *val, float *inv)
{
    inv[6] = -val[0] * val[6] * val[15] + val[0] * val[7] * val[14] + val[4]
    * val[2] * val[15] - val[4]* val[3] * val[14] - val[12] * val[2] * val[7] +
    val[12] * val[3] * val[6];
    inv[7] = val[0] * val[6] * val[11] - val[0] * val[7] * val[10] - val[4]
    * val[2] * val[11] + val[4]* val[3] * val[10] + val[8] * val[2] * val[7] -
    val[8] * val[3] * val[6];
    inv[8] = val[4] * val[9] * val[15] - val[4] * val[11] * val[13] - val[8]
    * val[5] * val[15] + val[8] * val[7] * val[13] + val[12] * val[5] * val[11]
    - val[12] * val[7] * val[9];
    inv[9] = -val[0] * val[9] * val[15] + val[0] * val[11] * val[13] + val
    [8] * val[1] * val[15] - val[8] * val[3] * val[13] - val[12] * val[1] * val
    [11] + val[12] * val[3] * val[9];
    inv[10] = val[0] * val[5] * val[15] - val[0] * val[7] * val[13] - val[4]
    * val[1] * val[15] + val[4]* val[3] * val[13] + val[12] * val[1] * val[7] -
    val[12] * val[3] * val[5];
    inv[11] = -val[0] * val[5] * val[11] + val[0] * val[7] * val[9] + val[4]
    * val[1] * val[11] - val[4] * val[3] * val[9] - val[8] * val[1] * val[7] +
    val[8] * val[3] * val[5];
}

void make_calc(float *val, float *inv)
{
    inv[0] = val[5] * val[10] * val[15] - val[5] * val[11] * val[14] - val
    [9] * val[6] * val[15] + val[9] * val[7] * val[14] + val[13] * val[6] *
    val[11] - val[13] * val[7] * val[10];
    inv[1] = -val[1] * val[10] * val[15] + val[1] * val[11] * val[14] + val
    [9] * val[2] * val[15] - val[9] * val[3] * val[14] - val[13] * val[2] * val
    [11] + val[13] * val[3] * val[10];
    inv[2] = val[1] * val[6] * val[15] - val[1] * val[7] * val[14] - val[5]
    * val[2] * val[15] + val[5]* val[3] * val[14] + val[13] * val[2] * val[7] -
    val[13] * val[3] * val[6];
    inv[3] = -val[1] * val[6] * val[11] + val[1] * val[7] * val[10] + val[5]
    * val[2] * val[11] - val[5] * val[3] * val[10] - val[9] * val[2] * val[7] +
    val[9] * val[3] * val[6];
    inv[4] = -val[4] * val[10] * val[15] + val[4] * val[11] * val[14] + val
    [8] * val[6] * val[15] - val[8] * val[7] * val[14] - val[12] * val[6] * val
    [11] + val[12] * val[7] * val[10];
    inv[5] = val[0] * val[10] * val[15] - val[0] * val[11] * val[14] - val
    [8] * val[2] * val[15] + val[8] * val[3] * val[14] + val[12] * val[2] * val
    [11] - val[12] * val[3] * val[10];
}

mat4x4 *mat4x4_invert(float *val)
{
    mat4x4 *matrix = mat4x4_create();
    float *inv = malloc(sizeof(float) * 17);
    float det;

    if (inv == NULL)
        return NULL;
    make_calc(val, inv);
    make_calc_2(val, inv);
    make_calc_3(val, inv);
    det = val[0] * inv[0] + val[1] * inv[4] +
    val[2] * inv[8] + val[3] * inv[12];
    if (det == 0) {
        free(inv);
        return matrix;
    }
    det = 1.0 / det;
    for (int i = 0; i < 16; i++)
        matrix->val[i] = inv[i] * det;
    free(inv);
    return matrix;
}
