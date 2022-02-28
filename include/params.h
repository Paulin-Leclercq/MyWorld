/*
** EPITECH PROJECT, 2022
** Workshop3D
** File description:
** params
*/

#ifndef PARAMS_H_
    #define PARAMS_H_

    #include "world.h"

    #define DAY 1
    #define IS_FILL sfTrue
    #define IS_OUTLINE sfFalse

static const float day_light[17] = {
0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75,
0.8, 0.75, 0.7, 0.65, 0.6, 0.55, 0.5, 0.45, 0.4};

static const float night_light[7] = {
0.35, 0.3, 0.25, 0.2, 0.25, 0.3, 0.35};

typedef struct params_struct {
    int hour;
    sfBool day;
    sfBool pause;
    sfBool is_fill;
    sfBool is_outline;
} params_t;

#endif
