/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** my_memset.c
*/

#include "world.h"

void my_memset(void *data, int type, size_t n)
{
    char *t = data;

    for (size_t i = 0; i < n; i++)
        t[i] = type;
}

void my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    char const *s = src;

    for (size_t i = 0; i < n; i++)
        d[i] = s[i];
}

int my_memcmp(void *aa, void *bb, size_t size)
{
    char *a = aa;
    char *b = bb;

    for (size_t i = 0; i < size; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
