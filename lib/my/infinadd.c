/*
** EPITECH PROJECT, 2021
** infinadd
** File description:
** infinadd
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *inf_display(char *result, int isneg, int i)
{
    char *tmp = malloc(sizeof(char) * (3 + my_strlen(result + 1)));
    for (int i = 0; i < 3 + my_strlen(result + 1); tmp[i] = '\0', i++);
    tmp[0] = '-';
    result[0] = (result[0] == 0) ? '0' : result[0];
    (result[0] == 1 || result[0] == -1) ? result[0] += '0' : 0;
    my_str_move(result, count_zero(result));
    if (my_strlen(result) == 0) {
        free(result);
        return my_strdup("0");
    }
    if (isneg == 1) {
        my_strcat(tmp, result);
        free(result);
        result = tmp;
        return (result);
    }
    free(tmp);
    return (result);
}

void carry(char **result, int size)
{
    if ((*result)[size] / 10 != 0) {
        (*result)[size] = (*result)[size] % 10;
        (*result)[size - 1] = 1;
    }
    (*result)[size] += '0';
}

void add_end_nbr(int i, char **result, int size, char *tab)
{
    for (; i != 0; i--, size--) {
        (*result)[size] += tab[i - 1] - '0';
        carry(result, size);
    }
}

char *infinadd(char *first, char *second, int isneg)
{
    int size = (my_strlen(first) < my_strlen(second))
    ? my_strlen(second) : my_strlen(first);
    char *result = malloc(sizeof(char) * (size + 3));
    int j = my_strlen(second);
    int i = my_strlen(first);

    for (int h = 0; h != size + 3; result[h] = '\0', h++);
    for (; i != 0 && j != 0; i--, j--, size--) {
        result[size] += first[i - 1] - '0' + second[j - 1] - '0';
        carry(&result, size);
    }
    add_end_nbr(i, &result, size, first);
    add_end_nbr(j, &result, size, second);
    if (my_strlen(result) > 0)
        return (inf_display(result, isneg, 0));
    else
        return (inf_display(result, isneg, 1));
}

char *ope(char *nb1, char *nb2)
{
    int i = (nb1[0] == '+' || nb1[0] == '-') ? 1 : 0;
    int j = (nb2[0] == '+' || nb2[0] == '-') ? 1 : 0;

    if ((nb1[0] == '-' && nb2[0] == '-')) {
        if (my_str_isnum(nb1 + 1) && my_str_isnum(nb2 + 1))
            return (infinadd(nb1 + 1, nb2 + 1, 1));
    }
    if (((nb1[0] != '-' && nb2[0] == '-') ||
    (nb1[0] == '-' && nb2[0] != '-'))) {
        if (my_str_isnum(nb1 + i) && my_str_isnum(nb2 + j))
            return (infinsub(nb1 + i, nb2 + j, nb2[0] == '-' ? '-' : 0));
    }
    if (my_str_isnum(nb1 + i) && my_str_isnum(nb2 + j))
        return (infinadd(nb1 + i, nb2 + j, 0));
}
