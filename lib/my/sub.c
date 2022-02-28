/*
** EPITECH PROJECT, 2021
** infinsub
** File description:
** infinsub
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void neg(char **result, int size)
{
    if ((*result)[size] < 0) {
        (*result)[size] += 10;
        (*result)[size - 1] = -1;
    }
    (*result)[size] += '0';
}

char *sub(char *first, char *second, int isneg)
{
    int size = my_strlen(first);
    char *result = malloc(sizeof(char) * (size + 4));
    int j = my_strlen(second);
    int i = my_strlen(first);

    for (int h = 0; h != size + 4; result[h] = '\0', h++);
    for (; i != 0 && j != 0; i--, j--, size--) {
        result[size] += (first[i - 1] - '0') - (second[j - 1] - '0');
        neg(&result, size);
    }
    add_end_nbr_neg(i, &result, size, first);
    return (inf_display(result, isneg, 1));
}

char *comp(char *frst, char *sec, char c)
{
    char *zerochar = my_strdup("0");
    if (my_strcmp(frst, sec) > 0)
        return sub(frst, sec, c == '-' ? 0 : 1);
    if (my_strcmp(frst, sec) < 0)
        return sub(sec, frst, c == '-' ? 1 : 0);
    frst = my_strcpy(frst, zerochar);
    free(zerochar);
    return (frst);
}

char *infinsub(char *frst, char *sec, char c)
{
    for (; frst[0] == '0'; frst++);
    for (; sec[0] == '0'; sec++);
    if (my_strlen(frst) > my_strlen(sec))
        return sub(frst, sec, (c == '-' ? 0 : 1));
    if (my_strlen(frst) < my_strlen(sec)) {
        return (sub(sec, frst, c == '-' ? 1 : 0));
    }
    return comp(frst, sec, c);
}
