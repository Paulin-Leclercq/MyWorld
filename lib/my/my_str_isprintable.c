/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 33 || str[i] > 126)
            return (0);
    }
    return (1);
}
