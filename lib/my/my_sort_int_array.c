/*
** EPITECH PROJECT, 2021
** my_print_comb2.c
** File description:
** Sorts an integer array in ascending order.
*/

static void swap_ints(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}

static void compare_ints(int *array, int j)
{
    if (array[j] > array[j + 1])
        swap_ints(&array[j], &array[j + 1]);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            compare_ints(array, j);
        }
    }
}
