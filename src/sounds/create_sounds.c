/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create_sounds
*/

#include "world.h"

void create_musics(win_t *win)
{
    win->musics = malloc(sizeof(sfMusic *) * NB_MUSICS);

    win->musics[0] = sfMusic_createFromFile("sounds/day.ogg");
    for (int i = 0; i < NB_MUSICS; i++)
        sfMusic_setLoop(win->musics[i], 1);
}

void create_sounds(win_t *win)
{
    win->sounds = malloc(sizeof(sfSound *) * NB_SOUNDS);

    for (int i = 0; i < NB_SOUNDS; i++)
        win->sounds[i] = sfSound_create();
    for (int i = 0; i < NB_SOUNDS; i++)
        sfSound_setLoop(win->sounds[i], 1);
    sfSound_setBuffer(win->sounds[0],
    sfSoundBuffer_createFromFile("sounds/build.ogg"));
}
