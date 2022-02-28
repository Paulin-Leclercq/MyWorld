/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

static char *lowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 91 && str[i] > 64)
            str[i] += 32;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int charac = 0;

    lowcase(str);
    if (str[0] == '\0')
        return (str);
    if (str[0] > 96 && str[0] < 123)
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i - 1] < 48 || str[i - 1] > 57 && str[i - 1] < 65)
            charac = 1;
        if (str[i - 1] > 90 && str[i - 1] < 97 || str[i - 1] > 122)
            charac = 1;
        if (str[i] > 96 && str[i] < 123 && charac == 1) {
            str[i] -= 32;
        }
        charac = 0;
    }
    return (str);
}
