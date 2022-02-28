/*
** EPITECH PROJECT, 2021
** my_memset.c
** File description:
** my_memset
*/

#include <stdlib.h>

int **my_dbintarrayset(int len_malloc)
{
    int **str = malloc(sizeof(int *) * len_malloc);

    for (int i = 0; i < len_malloc; str[i] = 0, i++);
    return str;
}

    int *my_intarrayset(int len_malloc)
{
    int *str = malloc(sizeof(int) * len_malloc);

    for (int i = 0; i < len_malloc; str[i] = 0, i++);
    return str;
}

    char **my_dbstrset(int len_malloc)
{
    char **str = malloc(sizeof(char *) * len_malloc);

    for (int i = 0; i < len_malloc; str[i] = 0, i++);
    return str;
}

char *my_strset(int len_malloc)
{
    char *str = malloc(sizeof(char) * len_malloc);

    for (int i = 0; i < len_malloc; str[i] = 0, i++);
    return str;
}
