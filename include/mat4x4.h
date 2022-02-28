/*
** EPITECH PROJECT, 2022
** mat4x4.h
** File description:
** mat4x4
*/

#ifndef __MAT4X4__
    #define __MAT4X4__

    #include "world.h"

struct mat4x4 {
    float val[16];
};

typedef struct mat4x4 mat4x4;

mat4x4 *mat4x4_create();
void mat4x4_destroy(mat4x4 *mat);

mat4x4 *mat4x4_multiplymat4x4(mat4x4 *mat1, mat4x4 *mat2);
float *mat4x4_multiplyvector4(mat4x4 *mat, float *vector);
float *mat4x4_multiplyvector3(mat4x4 *mat, float *vector, float *res);

mat4x4 *mat4x4_rx(float a);
mat4x4 *mat4x4_ry(float a);
mat4x4 *mat4x4_rz(float a);
mat4x4 *mat4x4_t(float *vector);
mat4x4 *mat4x4_scale(float s);

mat4x4 *mat4x4_invert(float *mat);

void normalize(float *vec);
float dotproduct3(float *vec1, float *vec2);
void crossproduct3(float *dest, float *vec1, float *vec2);

#endif
