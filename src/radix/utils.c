/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils
*/

#include "world.h"

void get_elems_2(va_list *list, int *i, int *bufsize)
{
    *i = va_arg(*list, int);
    *bufsize = va_arg(*list, int);
}

void get_elems_1(va_list *list, uint8_t **buffer,
size_t *type_size, size_t *offset_in_struct)
{
    *buffer = va_arg(*list, uint8_t *);
    *type_size = va_arg(*list, size_t);
    *offset_in_struct = va_arg(*list, size_t);
}

void triple_for(int *counts, size_t size, uint8_t *toSort, ...)
{
    va_list list;
    uint8_t *buffer;
    size_t type_size;
    size_t offset_in_struct;
    int i;
    int bufsize;

    va_start(list, toSort);
    get_elems_1(&list, &buffer, &type_size, &offset_in_struct);
    get_elems_2(&list, &i, &bufsize);
    for (size_t x = 0; x < size; x++)
        counts[*(toSort + x * type_size + offset_in_struct + i) + 1]++;
    for (int x = 1; x < bufsize; x++)
        counts[x] += counts[x - 1];
    for (size_t x = 0; x < size; x++) {
        my_memcpy(buffer + type_size *
        counts[*(toSort + x * type_size + offset_in_struct + i)]++,
        toSort + x * type_size, type_size);
    }
    va_end(list);
}

void final_for(uint8_t *buffer, uint8_t *toSort, size_t sizes[2],
size_t offset_in_struct)
{
    if (sizeof(int) % 2)
        my_memcpy(buffer, toSort, sizes[1] * sizes[0]);
    for (size_t x = 0; x < sizes[1]; x++)
        *(((uint8_t *)(toSort + (x * sizes[0]))) +
        offset_in_struct + sizeof(int) - 1) ^= 0b10000000;
}

void radix_sort(void *toSort2, size_t sizes[2],
size_t offset_in_struct, void *buffer2)
{
    uint8_t *toSort = toSort2;
    uint8_t *buffer = buffer2;
    int const bufsize = 256;
    int counts[257];
    uint8_t *tmp;

    for (size_t x = 0; x < sizes[1]; x++)
        *(toSort + x * sizes[0] + offset_in_struct + sizeof(int) - 1) ^= CONST;
    for (size_t i = 0; i < sizeof(int); i++) {
        my_memset(counts, 0, sizeof(counts));
        triple_for(counts, sizes[1], toSort, buffer, sizes[0],
        offset_in_struct, i, bufsize);
        tmp = toSort;
        toSort = buffer;
        buffer = tmp;
    }
    final_for(buffer, toSort, sizes, offset_in_struct);
}
