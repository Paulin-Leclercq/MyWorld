/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** help.c
*/

#include <unistd.h>

int usage(void)
{
    write(1,
    "MyWorld - A 3D simulation.\n\n"
    "USAGE\n"
    "    ./my_world [map]\n"
    "    map: Optional argument to load a map.\n\n"
    "HOW TO PLAY\n"
    "    Create or select your map using the associated menus.\n"
    "    You can also customize the window settings.\n\n"
    "IN GAME\n"
    "    Use the Z, Q, S, D keys to move on the map.\n"
    "    Use the A / E keys to move the camera down / up.\n"
    "    Use the I, J, K, L keys to turn the camera.\n"
    "    Use F3 to display the map in X-RAY mode.\n"
    "    Use F5 to display the FPS.\n"
    "    Use F11 to display the 3D map in the whole screen.\n", 506);
    return 0;
}
