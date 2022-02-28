/*
** EPITECH PROJECT, 2022
** load.c
** File description:
** load
*/

#include "world.h"

size_t add_vertex(char *buff, mesh_t *mesh, size_t vertex_index)
{
    char *nb_end = buff;

    buff += 2;
    mesh->vertxs[vertex_index].pos[0] = strtof(buff, &nb_end);
    buff = nb_end;
    mesh->vertxs[vertex_index].pos[1] = strtof(buff, &nb_end);
    buff = nb_end;
    mesh->vertxs[vertex_index].pos[2] = strtof(buff, &nb_end);
    buff = nb_end;
    return vertex_index + 1;
}

size_t add_trig(char *buff, mesh_t *mesh, size_t trig_index)
{
    char *nb_end = buff;
    triangle_t *trig = &mesh->trig[trig_index];

    buff += 2;
    for (int i = 0; i < 3; i++) {
        trig->vertxs[i] = strtol(buff, &nb_end, 0) - 1;
        trig->ptrs[i] = &mesh->vertxs[trig->vertxs[i]];
        buff = nb_end;
        while (buff[1] && buff[0] != ' ')
            buff++;
    }
    trig->color = sfWhite;
    trig->mesh_ptr = mesh;
    return trig_index + 1;
}

void add_pts_trig(char *buff, FILE *file, mesh_t *mesh)
{
    size_t tmp = 0;
    size_t trig_index = 0;
    size_t vertx_index = 0;
    char *tmp_buff = NULL;

    while (1) {
        buff = NULL;
        if (getline(&buff, &tmp, file) < 1)
            break;
        tmp_buff = buff;
        if (buff[0] == 'v')
            vertx_index = add_vertex(buff, mesh, vertx_index);
        if (buff[0] == 'f')
            trig_index = add_trig(buff, mesh, trig_index);
        free(tmp_buff);
    }
    free(buff);
}

void count_occ(mesh_t *mesh, FILE *file, char *buff)
{
    size_t tmp = 0;

    while (1) {
        buff = NULL;
        if (getline(&buff, &tmp, file) < 1)
            break;
        if (buff[0] == 'v')
            mesh->nb_vertxs++;
        if (buff[0] == 'f')
            mesh->trig_size++;
        free(buff);
    }
    free(buff);
    mesh->vertxs = malloc(sizeof(vertex_t) * mesh->nb_vertxs);
    mesh->trig = malloc(sizeof(triangle_t) * mesh->trig_size);
}

mesh_t *load_from_file(char *path)
{
    char *buff = NULL;
    FILE *file = fopen(path, "r");
    mesh_t *mesh = create_mesh(0, 0, 0, 0, 0);

    if (!file || !mesh)
        return NULL;
    count_occ(mesh, file, buff);
    rewind(file);
    add_pts_trig(buff, file, mesh);
    fclose(file);
    return mesh;
}
