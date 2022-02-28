/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

static int compare_len_n(char const *s1, char const *s2)
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

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    if (n > i)
        return (compare_len_n(s1, s2));
    return (0);
}
