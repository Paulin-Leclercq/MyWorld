/*
** EPITECH PROJECT, 2021
** loop_sub_div.c
** File description:
** loop_sub_div.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *negative_div(char *nb2)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(nb2) + 3));
    for (int i = 0; i < my_strlen(nb2) + 3; tmp[i] = '\0', i++);
    tmp[0] = '-';
    nb2 = my_strcat(tmp, nb2);
    return nb2;
}

void loop_sub_div(char **end, char *av2, int h, char **tmp_char)
{
    char *verif = negative_div(av2);
    char *verif2 = ope((*tmp_char), verif);
    if (verif2[0] == '-') {
        (*end)[h] = '0';
    }
    if (verif2[0] == '0') {
        my_strcpy((*tmp_char), "0");
        (*end)[h] = '1';
    }
    for (int j = 1; verif2[0] != '-'; verif2 = ope((*tmp_char), verif), j++) {
        (*tmp_char) = verif2;
        (*end)[h] = j + 48;
    }
    free(verif2);
    free(verif);
}

char *infdiv(char *nb1, char *nb2, char *end)
{
    int j = 0;
    char *tmp_char = malloc(sizeof(char) * (my_strlen(nb1) + 1));
    char *free_tmpchar = tmp_char;
    for (int i = 0; i < (my_strlen(nb1) + 1); tmp_char[i] = '\0', i++);
    for (int i = 0; nb2[i] != '\0'; i++)
        if (nb2[i] != '0' && nb2[i] != '-' && nb2[i] != '+')
            j++;
    if (j == 0) {
        write(2, "error", 6);
    }
    for (int i = 0; nb1[i] != '\0'; i++) {
        tmp_char[my_strlen(tmp_char)] = nb1[i];
        tmp_char[my_strlen(tmp_char)] = '\0';
        loop_sub_div(&end, nb2, i, &tmp_char);
    }
    while (end[0] == '0')
        end = end + 1;
    free(free_tmpchar);
    return end;
}

int divneg(char **av1, char **av2)
{
    int boolneg = 0;

    if ((*av1)[0] == '-' && (*av2)[0] != '-') {
        (*av1)++;
        boolneg = 1;
    }
    if ((*av1)[0] != '-' && (*av2)[0] == '-') {
        (*av2)++;
        boolneg = 1;
    }
    if ((*av1)[0] == '-' && (*av2)[0] == '-') {
        (*av1)++;
        (*av2)++;
    }
    return boolneg;
}

char *divbistro(char *nb1, char *nb2)
{
    char *end = malloc(sizeof(char) * (my_strlen(nb1) + 1));
    char *tmp_end = end;
    int boolneg = 0;

    for (int i = 0; i < my_strlen(nb1) + 1; end[i] = '\0', i++);
    boolneg = divneg(&nb1, &nb2);
    end = infdiv(nb1, nb2, end);
    if (my_strlen(end) == 0) {
        free(tmp_end);
        return my_strdup("0");
    }
    if (boolneg == 1 && my_strcmp(end, my_strdup("error")) != 0)
        end = negative_div(end);
    return end;
}
