/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

char *my_revstr(char *str)
{
    int length = 0;
    char tmp = ' ';

    while (str[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length - 1; i++) {
        tmp = str[i];
        str[i] = str[length - 1];
        str[length - 1] = tmp;
        length--;
    }
    return (str);
}
