/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 123 && str[i] > 96)
            str[i] -= 32;
    }
    return (str);
}
