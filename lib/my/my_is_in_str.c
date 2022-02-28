/*
** EPITECH PROJECT, 2021
** my_is_in_str.c
** File description:
** my_is_in_str
*/

int is_in_str(char to_find, char const *str)
{
    int char_in_str = 0;

    for (int j = 0; str[j] != '\0'; j++)
        char_in_str += (to_find == str[j]) ? 1 : 0;
    if (char_in_str == 0)
        return 0;
    return 1;
}
