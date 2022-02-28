/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

static int compare_len(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0') {
        i++;
    }
    while (s2[j] != '\0') {
        j++;
    }
    return (i - j);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    for (i; s1[i] != '\0' && s2[j] != '\0'; i++) {
        if (s1[i] > s2[j])
            return (1);
        else if (s1[i] < s2[j])
            return (-1);
        j++;
    }
    return (compare_len(s1, s2));
}
