/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);

    for (int i = 0; i < len_src && i < nb; i++) {
        dest[len_dest] = src[i];
        len_dest++;
    }
    dest[len_dest + 1] = '\0';
    return (dest);
}
