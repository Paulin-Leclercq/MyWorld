/*
** EPITECH PROJECT, 2021
** my_str_move.c
** File description:
** my_str_move
*/

#include "my.h"
#include <stdlib.h>

char *my_str_move(char *str, int new_start)
{
    int len = my_strlen(str);
    int new_len = my_strlen(str + new_start);

    for (int i = 0; i <= new_len; i++)
        str[i] = str[new_start + i];
    for (int j = new_len; j < len; j++)
        str[j] = '\0';
    return str;
}
