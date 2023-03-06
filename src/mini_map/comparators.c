/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** comparators.c
*/

#include <math.h>

int comp_circle(int i_x, int j_y, int s_br)
{
    return (sqrt(pow(i_x, 2) + pow(j_y, 2)) <= s_br) ? 1 : 0;
}

int comp_rectangle(int i_x, int j_y, int s_br)
{
    return (i_x + j_y + s_br) ? 1 : 1;
}
