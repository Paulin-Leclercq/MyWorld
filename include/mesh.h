/*
** EPITECH PROJECT, 2022
** mesh.h
** File description:
** mesh
*/

#ifndef MESH_H_
    #define MESH_H_

    #include "world.h"

typedef struct vertex {
    float pos[3];
} vertex_t;

typedef struct triangle {
    int vertxs[3];
    float direction;
    sfColor color;
    vertex_t *ptrs[3];
    void *mesh_ptr;
} triangle_t;

typedef struct vecsort {
    triangle_t *data;
    int id;
} vecsort_t;

typedef struct mesh {
    triangle_t *trig;
    size_t trig_size;
    vertex_t *vertxs;
    size_t nb_vertxs;
    sfBool is_selected;
} mesh_t;

mesh_t *create_mesh(size_t nb_vertxs, vertex_t *mesh_vertxs,
size_t trig_size, ...);

#endif
