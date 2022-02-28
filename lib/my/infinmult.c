/*
** EPITECH PROJECT, 2021
** infinmult.c
** File description:
** infinmult
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void modulo(char *result, int j, int i)
{
    result[j + i] += result[j + i + 1] / 10;
    result[j + i + 1] = result[j + i + 1] % 10;
}

char *mult(char *nb1, char *nb2)
{
    int len1 = my_strlen(nb1) - count_zero(nb1);
    int len2 = my_strlen(nb2) - count_zero(nb2);
    char *result = malloc(sizeof(char) * (len1 + len2 + 1));
    char *tmp;

    for (int i = 0; i < len1 + len2 + 1; result[i] = '\0', i++);
    nb1 = nb1 + count_zero(nb1);
    nb2 = nb2 + count_zero(nb2);
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            result[i + j + 1] += (nb1[i] - '0') * (nb2[j] - '0');
            modulo(result, j, i);
        }
    }
    for (int j = 0; j < len1 + len2; j++)
        result[j] += '0';
    result = my_str_move(result, count_zero(result));
    return result;
}

int errors(char *nb1, char *nb2)
{
    if (count_zero(nb2) == my_strlen(nb2))
        return (1);
    if (count_zero(nb1) == my_strlen(nb1))
        return (1);
    return (0);
}

char *infinmult(char *nb1, char *nb2)
{
    int neg1 = 0;
    int neg2 = 0;
    char *neg = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 1));
    char *tmp;
    for (int i = 0; i < my_strlen(nb1) + my_strlen(nb2) + 1; neg[i] = '\0'
    , i++);
    if (errors(nb1, nb2) == 1)
        return my_strdup("0");
    if (nb1[0] == '-' && nb2[0] != '-' || nb2[0] == '-' && nb1[0] != '-') {
        neg[0] = '-';
        neg1 += (nb1[0] == '-') ? 1 : 0;
        neg2 += (nb2[0] == '-') ? 1 : 0;
    }
    tmp = mult(nb1 + neg1, nb2 + neg2);
    if (is_base_nb('-', neg) == 1)
        return (my_strcat(neg, tmp));
    else {
        free(neg);
        return tmp;
    }
}
