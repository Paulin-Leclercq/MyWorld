/*
** EPITECH PROJECT, 2022
** smooth_shader.c
** File description:
** smooth_shader
*/

#include "world.h"

size_t add_mid(world_t *world, tmp_shadow_t *tmp, float *mid, long *index)
{
    size_t size = tmp->size;
    long col = tmp->col;
    size_t count = 0;

    !is_out(world->nb_trig, size - 1, index[0], index[1]) ? *mid += world->
    a_triangles[(size - 1) * index[0] + index[1]].direction, count++ : 0;
    !is_out(world->nb_trig, size - 1, index[0], index[1] +
    (long)(world->nb_trig / 2)) && col < (long)(world->nb_trig / 2) ? *mid
    += world->a_triangles[(size - 1) * index[0] + index[1] +
    (long)(world->nb_trig / 2)].direction, count++ : 0;
    !is_out(world->nb_trig, size - 1, index[0], index[1] -
    (long)(world->nb_trig / 2)) && col >= (long)(world->nb_trig / 2) ? *mid
    += world->a_triangles[(size - 1) * index[0] + index[1] -
    (long)(world->nb_trig / 2)].direction, count++ : 0;
    return count;
}

void smooth_trig(void *param)
{
    tmp_shadow_t *tmp = param;
    world_t *world = tmp->world;
    size_t size = tmp->size;
    long line = tmp->line;
    long col = tmp->col;
    triangle_t *trig = &world->a_triangles[(size - 1) * line + col];
    float mid = trig->direction * 4;
    size_t count = 4;
    long index[2];

    for (long i = line - 1; i < line + 1; i++) {
        for (long j = col - 1; j < col + 1; j++) {
            index[0] = i;
            index[1] = j;
            count += add_mid(world, tmp, &mid, index);
        }
    }
    mid /= count;
    trig->direction = mid;

}

void for_loop(void *param)
{
    tmp_shadow_t *tmp = param;
    sfBool turn = tmp->turn;

    for (size_t i = (turn ? 0 : tmp->start);
    i < (turn ? tmp->size - 1 : tmp->end); i++) {
        for (size_t j = (turn ? tmp->start : 0);
        j < (turn ? tmp->end : tmp->size - 1); j++) {
            tmp->line = i;
            tmp->col = j;
            smooth_trig(tmp);
            tmp->col = j + tmp->world->nb_trig / 2;
            smooth_trig(tmp);
        }
    }
}

void launch_thread(tmp_shadow_t *tmp, tmp_shadow_t *tmp2
, win_t *win, sfBool start)
{
    sfThread *thread1 = sfThread_create(for_loop, tmp);
    sfThread *thread2 = sfThread_create(for_loop, tmp2);

    if (start) {
        tmp->start = 0;
        tmp->end = (win->map_size - 1)  * 0.5;
        tmp->turn = 0;
        tmp2->start = (win->map_size - 1)  * 0.5;
        tmp2->end = win->map_size - 1;
        tmp2->turn = 0;
    }
    sfThread_launch(thread1);
    sfThread_launch(thread2);
    sfThread_wait(thread1);
    sfThread_wait(thread2);
    sfThread_destroy(thread1);
    sfThread_destroy(thread2);
}

void smooth_shadow(world_t *world, win_t *win)
{
    tmp_shadow_t *tmp = malloc(sizeof(tmp_shadow_t));
    tmp_shadow_t *tmp2 = malloc(sizeof(tmp_shadow_t));

    tmp->world = world;
    tmp->size = win->map_size;
    tmp2->world = world;
    tmp2->size = win->map_size;
    for (size_t i = 0; i < world->nb_trig; i++)
        apply_shades(world, &world->a_triangles[i]);
    launch_thread(tmp, tmp2, win, 1);
    launch_thread(tmp, tmp2, win, 0);
    free(tmp2);
    free(tmp);
    for (size_t i = 0; i < world->nb_trig; i++)
        world->a_triangles[i].direction *= win->params->day ? 0.9 : 0.3;
}
