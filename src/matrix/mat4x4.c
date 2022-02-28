/*
** EPITECH PROJECT, 2022
** mat4x4.c
** File description:
** mat4x4
*/

#include "world.h"

typedef union {
    float f;
    uint32_t i;
} un_t;

float q_rsqrt(float number)
{
    un_t conv = {.f = number};

    conv.i  = 0x5f3759df - (conv.i >> 1);
    conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
    return conv.f;
}

void normalize(float *vec)
{
    float magnitude_squared = vec[0] *
    vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
    float invsqrt = q_rsqrt(magnitude_squared);

    vec[0] *= invsqrt;
    vec[1] *= invsqrt;
    vec[2] *= invsqrt;
}

mat4x4 *mat4x4_multiplymat4x4(mat4x4 *mat1, mat4x4 *mat2)
{
    mat4x4 *mat = malloc(sizeof(mat4x4));

    for (int col = 0; col < 4; col++) {
        for (int line = 0; line < 4; line++) {
            mat->val[line*4 + col] = mat1->val[line*4 + 0] * mat2->val[0*4 +
            col] + mat1->val[line*4 + 1] * mat2->val[1*4 + col] + mat1->val[
            line*4 + 2] * mat2->val[2*4 + col] + mat1->val[line*4 + 3] *mat2
            ->val[3*4 + col];
        }
    }
    return mat;
}

float *mat4x4_multiplyvector4(mat4x4 *mat, float *vector)
{
    float *res = malloc(sizeof(float) * 4);

    res[0] = vector[0] * mat->val[0] + vector[1] * mat->val[4]
    + vector[2] * mat->val[8] + vector[3] * mat->val[12];
    res[1] = vector[0] * mat->val[1] + vector[1] * mat->val[5]
    + vector[2] * mat->val[9] + vector[3] * mat->val[13];
    res[2] = vector[0] * mat->val[2] + vector[1] * mat->val[6]
    + vector[2] * mat->val[10] + vector[3] * mat->val[14];
    res[3] = vector[0] * mat->val[3] + vector[1] * mat->val[7]
    + vector[2] * mat->val[11] + vector[3] * mat->val[15];
    return res;
}

float *mat4x4_multiplyvector3(mat4x4 *mat, float *vector, float *res)
{
    res[0] = vector[0] * mat->val[0] + vector[1] * mat->val[4]
    + vector[2] * mat->val[8] + mat->val[12];
    res[1] = vector[0] * mat->val[1] + vector[1] * mat->val[5]
    + vector[2] * mat->val[9] + mat->val[13];
    res[2] = vector[0] * mat->val[2] + vector[1] * mat->val[6]
    + vector[2] * mat->val[10] + mat->val[14];
    return res;
}
