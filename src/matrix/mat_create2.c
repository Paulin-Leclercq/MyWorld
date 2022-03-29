/*
** EPITECH PROJECT, 2022
** mat_create2.c
** File description:
** mat_create2
*/

#include "world.h"

float dotproduct3(float *vec1, float *vec2)
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

void crossproduct3(float *dest, float *vec1, float *vec2)
{
    dest[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    dest[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    dest[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
}

mat4x4 *mat4x4_scale(float s)
{
    mat4x4 *mat = mat4x4_create();

    mat->val[0] = s;
    mat->val[5] = s;
    mat->val[10] = s;
    mat->val[15] = 1;
    return mat;
}

mat4x4 *mat4x4_create(void)
{
    mat4x4 *mat = malloc(sizeof(mat4x4));

    my_memset(mat, 0, sizeof(mat4x4));
    mat->val[0] = 1;
    mat->val[5] = 1;
    mat->val[10] = 1;
    mat->val[15] = 1;
    return mat;
}

void mat4x4_destroy(mat4x4 *mat)
{
    free(mat);
}
