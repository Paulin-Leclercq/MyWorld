/*
** EPITECH PROJECT, 2021
** my_char_to_str.c
** File description:
** my_char_to_str
*/

#include <stdlib.h>
#include "my.h"

char *my_char_to_str(char charac)
{
    char *str = my_strset(2);

    str[0] = charac;
    return str;
}
