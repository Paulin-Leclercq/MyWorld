/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "world.h"

int poll_window_ev(win_t *win, world_t *world)
{
    while (win->poll_event(win)) {
        // if (win->event.mouseWheelScroll.wheel == 1)
        //     world->s_br++;
        // if ((int)(win->event.mouseWheelScroll.wheel) == -1 && world->s_br > 0)
        //     world->s_br--;
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
            win->destroy(win);
            world->destroy(world);
            return 0;
        } else
            params(win, world);
    }
    return 1;
}

void free_lists(world_t *world)
{
    for (size_t i = 0; i < world->nb_meshes; i++)
        remove_node(world->meshes, 0, 0);
    for (size_t i = 0; i < world->nb_vertxs; i++)
        remove_node(world->vertxs, 0, 0);
    for (size_t i = 0; i < world->nb_trig; i++)
        remove_node(world->triangles, 0, 0);
    free(world->meshes);
    free(world->vertxs);
    free(world->triangles);
}

// int main(int ac, char **av)
// {
//     world_t *world = create_world();
//     win_t *win;
//     long long size = str_to_long(av[1]) + 1;

//     if (world == NULL || world->matrix == NULL)
//         return 84;
//     srand(time(NULL));
//     create_map(world, size);
//     set_light_source(world, size / 2, 1, 1000);
//     convert_to_array(world);
//     world->sortBuffer = malloc(sizeof(vecsort_t) * world->nb_trig);
//     world->sortBuffer2 = malloc(sizeof(vecsort_t) * world->nb_trig);
//     win = win_create(world->nb_trig);
//     win->map_size = size;
//     free_lists(world);
//     while (win->is_open(win)) {
//         // event
//         move(&world->matrix);

//         // draw
//         draw_meshes(world, win);
//         //create_minimap(world, win, size - 1);
//         win->display(win);

//         // events
//         if (!poll_window_ev(win, world))
//             return 0;
//     }
//     return 0;
// }
