/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

int my_is_alphanum(char const str)
{
    if (str >= 'a' && str <= 'z')
        return 1;
    if (str >= 'A' && str <= 'Z')
        return 1;
    if (str >= '0' && str <= '9')
        return 1;
    return 0;
}
