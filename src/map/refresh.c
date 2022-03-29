/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** refresh
*/

#include "world.h"
#include "menus.h"

void reload(game_t *game)
{
    game->world->destroy(game->world);
    game->win->destroy(game->win);
    start_world(game);
}

void modify_data(void **data, void *new)
{
    free(*data);
    *data = new;
}

void refresh_map(game_t *game)
{
    mat4x4 *mat_world = mat4x4_create();
    params_t *par = malloc(sizeof(params_t));
    float *light_source = malloc(sizeof(float) * 3);
    float *light_start = malloc(sizeof(float) * 3);

    my_memcpy(light_source, game->world->light_source, sizeof(float) * 3);
    my_memcpy(light_start, game->world->light_start, sizeof(float) * 3);
    my_memcpy(par, game->win->params, sizeof(params_t));
    my_memcpy(mat_world, game->world->matrix, sizeof(mat4x4));
    reload(game);
    modify_data((void **)&game->world->matrix, mat_world);
    modify_data((void **)&game->win->params, par);
    modify_data((void **)&game->world->light_source, light_source);
    modify_data((void **)&game->world->light_start, light_start);
    smooth_shadow(game->world, game->win);
    sfMusic_play(game->win->musics[0]);
}

void free_loop_pe(float ***gradient, int i)
{
    for (int j = 0; j < 128; j++)
        free(gradient[i][j]);
}
