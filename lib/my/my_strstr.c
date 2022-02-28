/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

static int compare_str(char *str, char const *to_find)
{
    int j = 0;
    int find_length = 0;

    while (to_find[find_length] != '\0') {
        find_length++;
    }
    for (j = 0; j < find_length; j++) {
        if (str[j] != to_find[j])
            return (0);
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    if (to_find[0] == '\0')
        return (0);
    while (str[i] != '\0') {
        if (compare_str(&str[i + 1], to_find) == 1)
            return (&str[i + 1]);
        i++;
    }
    return (0);
}
