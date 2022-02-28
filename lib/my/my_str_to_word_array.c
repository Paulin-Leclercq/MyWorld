/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

#include <stdlib.h>
#include "my.h"

static char *add_word(char *tmp, char const *str, int start, int end)
{
    int i = 0;
    for (start; start < end; start++) {
        tmp[i] = str[start];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char **my_str_to_word_array(char const *str)
{
    char **tmp = malloc(sizeof(char *) * my_strlen(str));
    int count = 0;
    int start = 0;
    int word = 0;
    for (int i = 0; i <= my_strlen(str); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a'
        && str[i] <= 'z' || str[i] >= '0' && str[i] <= '9') && word == 0) {
            start = i;
            word = 1;
        }
        if ((str[i] <= 'A' || str[i] >= 'Z') && !(str[i] >= 'a' && str[i]
        <= 'z') && !(str[i] >= '0' && str[i] <= '9') && word == 1) {
            tmp[count] = malloc(sizeof(char) * (i - start + 1));
            tmp[count] = add_word(tmp[count], str, start, i);
            count++;
            word = 0;
        }
    }
    tmp[count] = 0;
    return (tmp);
}
