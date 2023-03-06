/*
** EPITECH PROJECT, 2022
** list.c
** File description:
** list
*/

#ifndef LIST_H
    #define LIST_H

typedef struct list {
    struct list *next;
    struct list *prev;
    void *data;
} list_t;

void append_node(list_t **begin, void *data);
void remove_node(list_t **begin, unsigned offset, void (*freer)(void *));

#endif
