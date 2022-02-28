/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

#include <stdlib.h>
#include "my.h"

static int len_array(char * const *tab)
{
    int i = 0;

    for (i; tab[i] != NULL; i++) {
    }
    return (i);
}

char *my_show_word_array(char * const *tab)
{
    for (int i = 0; i < len_array(tab); i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
