/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef __PROTO__
    #define __PROTO__

    #include <math.h>
    #include <time.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <stddef.h>
    #include <stdarg.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Types.h>
    #include <SFML/Window/Keyboard.h>
    #include "params.h"
    #include "window.h"
    #include "mat4x4.h"
    #include "mesh.h"
    #include "list.h"
    #include "my.h"

    #define PI 3.14159265359
    #define CONST 0b10000000

    #define NB_ACTIONS 5

    #define ABS(nb) ((nb) < 0 ? -(nb) : (nb))

    #define P_HEIGT(world, i, size) \
    world->a_vertxs[i * (size) + (size - j)]->pos[1]

    #define IS_BLUE(color) my_memcmp(&color, &sfBlue, sizeof(sfColor))
    #define IS_GREEN(color) my_memcmp(&color, &sfGreen, sizeof(sfColor))
    #define IS_WHITE(color) my_memcmp(&color, &sfWhite, sizeof(sfColor))

    #define BRUSH_DIR (map->is_circle ? \
    (map->s_br - sqrt(pow(i - x, 2) + pow(j - y, 2))) / 10.0 : 1)

static const sfVector2f snow[3] = {
    {0, 0}, {1000, 1000}, {0, 1000}
};

static const sfVector2f grass[3] = {
    {1000, 0}, {2000, 0}, {1000, 1000}
};

static const sfVector2f water[3] = {
    {0, 0}, {1000, 1000}, {1000, 0}
};

typedef union {
    float f;
    uint32_t i;
} un_t;

typedef struct world_struct {
    vecsort_t *sortBuffer;
    vecsort_t *sortBuffer2;
    mat4x4 *matrix;
    sfClock *clock;
    list_t **meshes;
    list_t **vertxs;
    list_t **triangles;
    vertex_t **a_vertxs;
    vertex_t *projected;
    triangle_t *a_triangles;
    size_t nb_vertxs;
    size_t nb_meshes;
    size_t nb_trig;
    float p_pos[3];
    float p_dir[3];
    float *light_start;
    float *light_source;
    void (*destroy)(struct world_struct *world);
    sfConvexShape *back;
    float moy_dir;
} world_t;

typedef struct tmp_struct {
    world_t *world;
    size_t size;
    long line;
    long col;
    size_t end;
    size_t start;
    sfBool turn;
} tmp_shadow_t;

typedef struct minimap {
    void (*actions[NB_ACTIONS])(world_t *,
    struct minimap *, int (*)(int, int, int));
    sfRenderTexture *rtex;
    sfVertexArray *array;
    sfVertex *tmp;
    sfVector2f size;
    sfVector2f mouse_pos;
    sfCircleShape *circle;
    sfClock *time;
    sfSprite *vision;
    int s_br;
    int state;
    int map_size;
    int is_circle;
} minimap_t;

static const float height = 800.0;

void app_point(float x, float y, minimap_t *map);
void move(world_t *world, win_t *win);
void radix_sort(void *toSort2, size_t sizes[2],
size_t offset_in_struct, void *buffer2);
world_t *create_world(void);
void add_mesh(world_t *world, mesh_t *mesh);
void draw_meshes(world_t *world, win_t *win);
void project_meshes(world_t *world, float delta);
void sort_vertxs(world_t *world);
list_t *get_from_index(list_t **begin, size_t index, size_t len_list);
mesh_t *load_from_file(char *file);
float apply_shades(world_t *world, triangle_t *tri);
float get_direction(vertex_t *pts);
void set_light_source(world_t *world, float x, float y, float z);
void move_light(world_t *world, win_t *win);
void draw_light(world_t *world, win_t *win);
void convert_to_array(world_t *world);
void create_map(world_t *world, size_t size);
float apply_perlin(float x, float y);
void draw_minimap(minimap_t *map, world_t *world, int size, sfBool draw_pos);
minimap_t *create_minimap(sfVector2f size, int map_size);
sfColor center_vertxs(vertex_t *vertxs, triangle_t *tri, win_t *win);
void rota_right(world_t *world, win_t *win);
void rota_left(world_t *world, win_t *win);
void change_color(mesh_t *mesh, size_t size, size_t i, size_t j);
void smooth(mesh_t *mesh, size_t size);
void smooth_shadow(world_t *world, win_t *win);
sfBool is_out(size_t max, size_t size, long i, long j);
void up_br(world_t *world, minimap_t *map, int (*comp)(int, int, int));
void down_br(world_t *world, minimap_t *map, int (*comp)(int, int, int));
void free_mesh(void *value);
void average_br(world_t *world, minimap_t *map, int (*comp)(int, int, int));
void average_w_br(world_t *world, minimap_t *map, int (*comp)(int, int, int));
void average_d_br(world_t *world, minimap_t *map, int (*comp)(int, int, int));
void free_lists(world_t *world);
void draw_fps(win_t *w);
void update_color(world_t *world);
float get_max_height(triangle_t trig);
float ***get_gradient(sfBool reset);
void add_background(world_t *world);
void draw_triangle(vertex_t vertxs[3], triangle_t *tri, win_t *win);
void draw_back(world_t *world, win_t *win);
void my_memset(void *data, int type, size_t n);
void my_memcpy(void *dest, const void *src, size_t n);
void get_player_pos(world_t *world);
void get_player_dir(world_t *world);
void where_minimap(world_t *world, minimap_t *map, long long size);
void where_minimap_square(world_t *world, minimap_t *map, long long size);
void free_loop_pe(float ***gradient, int i);
int my_memcmp(void *aa, void *bb, size_t size);

#endif
