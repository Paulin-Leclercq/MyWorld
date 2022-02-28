/*
** EPITECH PROJECT, 2022
** Workshop3D v4.0
** File description:
** perlin
*/

#include "world.h"

float ***fill_gradient(int x, int y)
{
    float ***gradient = malloc(sizeof(float **) * (x + 1));
    int j = 0;

    for (int i = 0; i < x; i++) {
        gradient[i] = malloc(sizeof(float *) * (y + 1));
        for (j = 0; j < y; j++) {
            gradient[i][j] = malloc(sizeof(float) * 2);
            gradient[i][j][0] = ((rand() % 5000) / 2500.0 - 1);
            gradient[i][j][1] = ((rand() % 5000) / 2500.0 - 1);
        }
        gradient[i][j] = 0;
    }
    gradient[y] = 0;
    return gradient;
}

float lerp(float a, float b, float w)
{
    return (1.0 - w)*a + w*b;
}

float dot_grid_gradient(int ix, int iy, float x, float y)
{
    static float ***gradient = 0;
    float dx = x - (float)ix;
    float dy = y - (float)iy;

    if (!gradient)
        gradient = fill_gradient(128, 128);
    return (dx * gradient[iy % 128][ix % 128][0] + dy *
    gradient[iy % 128][ix % 128][1]);
}

float apply_perlin(float x, float y)
{
    int x0 = (int)x;
    int x1 = x0 + 1;
    int y0 = (int)y;
    int y1 = y0 + 1;
    float sx = x - (float)x0;
    float sy = y - (float)y0;
    float n0;
    float n1;
    float ix0;
    float ix1;
    float value;

    n0 = dot_grid_gradient(x0, y0, x, y);
    n1 = dot_grid_gradient(x1, y0, x, y);
    ix0 = lerp(n0, n1, sx);
    n0 = dot_grid_gradient(x0, y1, x, y);
    n1 = dot_grid_gradient(x1, y1, x, y);
    ix1 = lerp(n0, n1, sx);
    value = lerp(ix0, ix1, sy);
    return value;
}
