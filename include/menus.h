/*
** EPITECH PROJECT, 2022
** my world
** File description:
** menu.h
*/

#ifndef MENU_H
    #define MENU_H

    #define BACKGROUND_FRAMES 1

    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include "world.h"

    #define true 1
    #define false 0
    #define bool int

    #define FONT "minecraft.ttf"
    #define TEXTURE "truc.png"

    #define ALL_FLAGS S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH
    #define GROW_FACTOR 1.05
    #define MAIN_MENU_TXT_FACTOR 0.7
    #define SETTINGS_FILE ".conf"
    #define PART_OF_MINIMAP 0.6

typedef struct {
    sfSprite *box;
    sfSprite *check;
    sfText *text;
    int is_checked;
} check_box;

typedef struct {
    sfText *text;
    sfSprite *sprite;
    int is_press;
    int is_hover;
    sfVector2f pos;
    sfVector2f size;
    void (*action)(void *);
} button_t;

typedef struct {
    check_box *vsync;
    check_box *full_screen;

    button_t *framerate_button;
    button_t *res_button;

    sfText *sfx_vol_text;
    sfText *sfx_text;
    button_t *sfx_plus;
    button_t *sfx_minus;

    sfText *music_vol_text;
    sfText *music_text;
    button_t *music_plus;
    button_t *music_minus;

    button_t *back;
    sfSprite *background;

    sfRenderTexture *rtex;

    sfClock *repeat_clock;

    int sfx_vol;
    int music_vol;
    int framerate;
    int resolution;
} settings_t;

static const sfIntRect button_rect = {
    1, 1, 1, 1
};

static const sfIntRect main_background_rects[BACKGROUND_FRAMES] = {
    {0, 0, 1, 1}
};

// size factors
static const float main_buts_sf[4][2] = {
    {0.7, 0.12}, {0.7, 0.12}, {0.33, 0.12}, {0.33, 0.12}
};
// pos factors
static const float main_buts_pf[4][2] = {
    {0.5, 0.4}, {0.5, 0.6}, {0.313, 0.8}, {0.687, 0.8}
};

typedef struct win {
    int state;
    int next_state;
    bool is_transition;

    void *menus[6];
    // void *map_select;
    // void *settings;
    // void *create_level;
    // void *how_to_play;
    // void *home;
    // void *game;

    const sfTexture* (*draw[6])(void *);
    void (*event[6])(struct win *, sfEvent ev);
    void (*update[6])(void *);

    sfClock *lum_clock;

    sfVideoMode mode;

    int framerate;

    sfRenderWindow *win;
} window_t;

typedef enum {WORLD, MINIMAP, BUTTONS} mouse_pos_t;

typedef enum {
    HOME, MAP_SELECT, SETTINGS, CREATE_MAP,
    HOW_TO_PLAY, EDIT_MAP, EXIT
} state_t;

typedef struct {
    sfRenderTexture *rtex;

    button_t *cursor;
    sfRectangleShape *before_cursor;
    sfRectangleShape *after_cursor;

    int max;
    int min;
    int value;
    sfVector2f size;
    sfVector2f but_size;
    sfVector2f pos;
} slider_t;

typedef struct {
    button_t *buttons[4];
    sfSprite *background;
    sfRenderTexture *text;
} main_menu_t;

void factor_color(sfSprite *s, float factor);
void hover_button(button_t *b, int is_on);
void press_button(button_t *b, int is_press);
sfFont *global_font(void);
sfTexture *global_texture(void);
sfSprite *init_sprite_from_texture(sfTexture const *t);
sfText *init_text(char const *str, int charSize);
void set_sprite_size(sfSprite *s, sfVector2f size);
sfSprite *init_sprite(sfTexture *t, sfIntRect rect, sfVector2f size);
button_t *init_button(sfTexture *t, sfIntRect rect, sfVector2f pos,
sfVector2f size, char const *str, void (*action)(void *));
bool is_on_button(sfVector2f pos, button_t *b);
void check_button_move(button_t **buttons, int nb_button, sfEvent move);
void check_button_press(button_t **buttons, int nb_button, sfEvent press);
int button_at(button_t **buttons, int nb_button, sfEvent release);
void set_next_win_state(window_t *win, int next);
void main_menu_release(main_menu_t *m, sfEvent ev, window_t *win);
void main_menu_event(window_t *win, sfEvent ev);
sfVector2f get_sprite_size(sfSprite *s);
void center_sprite(sfSprite *s);
void scale_main_buttons(button_t *buttons[4], sfVector2f winSize);
void move_main_buttons(button_t *buttons[4], sfVector2f winSize);
main_menu_t *init_main_menu(sfTexture *t, sfVector2f winSize);
void draw_button_to_rtex(button_t *b, sfRenderTexture *rtex);
const sfTexture *draw_main_menu(void *menu);
window_t *window_create(void);
void destroy_home(main_menu_t *menu);
void win_destroy(window_t *win);
void switch_color_dir(window_t *win, int *dir);
void reset_lum(window_t *win, int *dir, sfColor *lum);
void update_lum(sfColor *lum, int *fac);
void update_transition(window_t *win, sfSprite *s);
void draw(window_t *win);
void poll_events(window_t *win);
int main(void);
void center_text(sfText *t);

// check box
void scale_check_box(check_box *c, sfVector2f factors);
void set_box_pos(check_box *c, sfVector2f pos);
void draw_check_box(sfRenderTexture *rtex, check_box *c);
check_box *init_check_box(int check, char const *text, window_t *win);

// truc
void rescale_all(window_t *win);

// settings
sfSprite *get_settings_sprite(window_t *win);
void move_settings(settings_t *se, window_t *win);
void go_back(settings_t *se, window_t *win);
void update_full_screen(settings_t *se, window_t *win);
void update_vsync(settings_t *se, window_t *win);
void update_res(settings_t *se, window_t *win);
void update_framerate(settings_t *se, window_t *win);
void rescale_settings(settings_t *se, window_t *win);
sfFloatRect bounds(sfSprite *s);
sfVector2f conv(sfVector2f c, window_t *win);
int get_set_button_at(settings_t *se, sfEvent *ev);
void manage_settings_hover(sfEvent *ev, window_t *win);
void manage_settings_press(sfEvent *ev, window_t *win);
void manage_settings_release(sfEvent *ev, window_t *win);
void reset_set_buttons(settings_t *se);
void update_all_texts(settings_t *se);
void sfx_minus(settings_t *se, window_t *win);
void sfx_plus(settings_t *se, window_t *win);
void music_minus(settings_t *se, window_t *win);
void music_plus(settings_t *se, window_t *win);
void update_vol(float vol, char const *format, ...);
void settings_ev(window_t *win, sfEvent ev);
const sfTexture *draw_settings(void *se);
settings_t *init_settings(window_t *win);
void check_sound_repeat(window_t *win, sfEvent *ev);
void scale_main_menu(main_menu_t *m, window_t *win);
void destroy_settings(settings_t *se);
void destroy_button(button_t *b);
void save_settings(settings_t *se);
void load_settings(settings_t *se);
void apply_settings(settings_t *se, window_t *win);

static const sfIntRect settings_rects[10] = {
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1}
};

static const sfVideoMode available_modes[] = {
    {800, 600, 32},
    {1024, 800, 32},
    {1920, 1080, 32}
};

static const int available_framerates[] = {
    30, 60, 90, 120, 144
};

//maps
//     #define MAP_X_FACTOR 0.5
//     #define MAP_Y_FACTOR 0.2

// void rescale_map(map_t *m, sfVector2f win_size);
// sfRectangleShape *map_sprite(map_t *m);
// map_t *create_map(sfVector2f win_size, char const *file);

// static const sfIntRect thumbnail_rect = {
//     0, 0, 1, 1
// };

// typedef struct {
//     sfText *name;
//     char *file;
//     sfRenderTexture *rtex;
//     sfSprite *thumbnail;
// } map_t;

// line edit
typedef struct {
    sfRenderTexture *rtex;
    sfRectangleShape *background;
    sfText *text;
} line_edit_t;

void scale_line_edit(line_edit_t *le, sfVector2f size);
sfSprite *draw_line_edit(line_edit_t *le, sfVector2f pos);
line_edit_t *create_line_edit(sfVector2f size, char const *def);

// map select
sfRectangleShape *rectangle_from_texture(sfTexture const *tex);

// map create

typedef struct {
    // increase / decrease size, launch, cancel
    button_t *buttons[4];

    sfRenderTexture *rtex;

    sfText *name_prompt;
    line_edit_t *name;

    sfText *size;
    slider_t *size_slider;

} map_create_t;

map_create_t *create_map_create(sfVector2f win_size);
void scale_mc(map_create_t *mc, sfVector2f win_size);
const sfTexture *draw_mc(map_create_t *mc, sfVector2f ws);

static const sfIntRect mc_rects[] = {
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {1, 0, 1, 1},
    {1, 0, 1, 1}
};

void increase_size(void *w);
void decrease_size(void *w);
void launch_size(void *w);
void mc_go_back(void *w);

// slider

static const sfIntRect cursor_rect = {
    1, 0, 1, 1
};

static const sfColor sfGrey = {128, 128, 128, 255};

slider_t *create_slider(sfVector2f size,
sfVector2f bounds, int value, sfVector2f pos);
sfSprite *draw_slider(slider_t *s);
void rescale_slider(slider_t *s, sfVector2f new_size, sfVector2f new_pos);
void slider_event(slider_t *s, sfEvent ev);
void update_positions(slider_t *s);
void destroy_slider(slider_t *s);
sfRectangleShape *create_rectangle(sfVector2f size,
sfColor fill, sfTexture const *tex);

char *str_concat(int nb_str, ...);
void line_edit_event(line_edit_t *le, sfEvent ev);
void mc_event(window_t *mc, sfEvent ev);
void update_size_text(sfText *size, slider_t *slider);
void scale_mc(map_create_t *mc, sfVector2f win_size);
void destroy_line_edit(line_edit_t *le);
void destroy_slider(slider_t *s);
void release_mc(map_create_t *mc, int index, window_t *win);
void destroy_check_box(check_box *c);
void destroy_mc(map_create_t *mc);

// game
typedef struct {
    sfRenderTexture *rtex;
    world_t *world;
    win_t *win;
    sfVector2f size;
    minimap_t *minimap;
    int dimension;
} game_t;

game_t *create_game(unsigned size, sfVector2f win_size);
const sfTexture *draw_game(void *game);
void game_events(window_t *win, sfEvent ev);
void minimap_clicks(game_t *g);
mouse_pos_t mouse_pos(sfVector2f win_size, window_t *win);

void save_map(game_t *game, const char* filename, unsigned int size);
unsigned int read_map(game_t *game, const char* filename);
#endif
