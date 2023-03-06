/*
** EPITECH PROJECT, 2022
** calc.c
** File description:
** calc
*/

#include "world.h"

void get_player_pos(world_t *world)
{
    mat4x4 *mat_inv = mat4x4_invert((float *)world->matrix);
    float *tmp = malloc(sizeof(float) * 3);

    world->p_pos[0] = 0;
    world->p_pos[1] = 0;
    world->p_pos[2] = 0;
    mat4x4_multiplyvector3(mat_inv, world->p_pos, tmp);
    world->p_pos[0] = tmp[0];
    world->p_pos[1] = tmp[1];
    world->p_pos[2] = tmp[2];
    free(mat_inv);
    free(tmp);
}

void get_player_dir(world_t *world)
{
    mat4x4 *mat_inv = mat4x4_invert((float *)world->matrix);
    float *tmp = malloc(sizeof(float) * 3);

    world->p_dir[0] = 0;
    world->p_dir[1] = 0;
    world->p_dir[2] = -1;
    mat4x4_multiplyvector3(mat_inv, world->p_dir, tmp);
    world->p_dir[0] = tmp[0] - world->p_pos[0];
    world->p_dir[1] = tmp[1] - world->p_pos[1];
    world->p_dir[2] = tmp[2] - world->p_pos[2];
    free(mat_inv);
    free(tmp);
}
