/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** my_strdup.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int size;
    char *dest;
    int i = 0;

    size = my_strlen(src);
    dest = malloc(sizeof(char) * size + 1);
    while (i < size) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
