/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int special_chrac(char *str, int *i, l_spec *spec, int end)
{
    if (is_in_str(str[(*i)], "-+ #0") && end < 2) {
        add_flags(str, (*i), spec);
        return 1;
    }
    if (is_in_str(str[(*i)], "123456789") && end < 2) {
        (*i) += add_width(str, (*i), spec);
        return 2;
    }
    if (str[(*i)] == '.' && end < 3) {
        (*i) += add_prec(str, (*i) + 1, spec);
        return 3;
    }
    if (is_in_str(str[(*i)], "hljztL") && end < 4) {
        (*i) += add_length(str, (*i), spec);
        return 4;
    }
    return -1;
}

int find_modulo(char *str, int start, va_list list_arg)
{
    int i = start + 1;
    int end = 0;
    l_spec *spec = malloc(sizeof(l_spec));

    spec->str = malloc(sizeof(char));
    for (; str[i] != '\0'; i++) {
        if (is_in_str(str[i], "-+ #0123456789.hljztLdiscupoxXbS%") == 0
        || end == -1) {
            my_putchar('%');
            return 0;
        }
        if (is_in_str(str[i], "-+ #0123456789.hljztL"))
            end = special_chrac(str, &i, spec, end);
        if (is_in_str(str[i], "discupoxXbS%")) {
            spec->spec_char = str[i];
            str_switch(spec, list_arg);
            break;
        }
    }
    return i - start;
}

int my_printf(char *str, ...)
{
    int i = 0;
    va_list list_arg;

    if (str == 0 || my_strlen(str) == 0)
        return 0;
    va_start(list_arg, str);
    for (; str[i] != '\0'; i++) {
        if (str[i] != '%')
            my_putchar(str[i]);
        else
            i += find_modulo(str, i, list_arg);
    }
    va_end(list_arg);
    return 0;
}
