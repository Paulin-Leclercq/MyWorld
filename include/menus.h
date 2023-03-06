/*
** EPITECH PROJECT, 2022
** my world
** File description:
** menu.h
*/

#ifndef MENU_H
    #define MENU_H

    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include "world.h"

// constants

    #define true 1
    #define false 0
    #define bool int

    #define FONT "assets/minecraft.ttf"
    #define TEXTURE "assets/texture.png"

    #define ALL_FLAGS S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH
    #define GROW_FACTOR 1.05
    #define MAIN_MENU_TXT_FACTOR 0.7
    #define PART_OF_MINIMAP 0.6
    #define SETTINGS_FILE ".conf"
    #define REPEAT_DELAY 500000
    #define BACKGROUND_SETTINGS 0
    #define BACK_SETTINGS 0
    #define TOOLTIP_DURATION 350000
    #define ENTRY_Y_SPAN 0.12
    #define ENTRY_SPACING 1.35
    #define BOUNDS(s) (sfSprite_getGlobalBounds(s))
    #define ENTRY_Y_SPAN 0.12

    #define SAVE_MAX_TIME 3000000

    #define MAP_STRING (get_level_name(win))

    #define MAP_SIZE (get_level_size(win))

    #define IS_WORLD_CLICK (win->state == EDIT_MAP &&\
    (mouse_pos(win_size, win) == WORLD || ev.type == sfEvtMouseButtonReleased))

    #define SPECTATOR_SIZE 64
    #define MIN(x, y) ((x) < (y) ? (x) : (y))

    #define SPECTATOR_TIME 1000000 / 25.0

    #define RESCALE_SPECTATOR(s, ns) sfRenderTexture_destroy(s->win->r_tex); \
    s->win->r_tex = sfRenderTexture_create(ns.x, ns.y, 0);

    #define LINEEDIT_TIME 400000
    #define NB_BUTTONS 13
    #define DOUBLE_CLICK_DELAY 500000

static const sfColor sfGrey = {
    128, 128, 128, 255
};

static const sfColor SEMI_COLOR = {
    127, 127, 127, 255
};
static const sfColor SEMI_TRANSP = {
    127, 127, 127, 127
};
static const sfVector2f DEFAULT_2F = {
    1, 1
};

typedef enum {
    WORLD, MINIMAP, BUTTONS
} mouse_pos_t;

// structures

typedef struct dirent dirent_t;

typedef struct {
    world_t *world;
    win_t *win;
    sfClock *time;
} spectator_t;

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

typedef struct win {
    int state;
    int next_state;
    bool is_transition;

    void *menus[6];

    const sfTexture* (*draw[6])(struct win *);
    void (*event[6])(struct win *, sfEvent ev);
    void (*update[6])(void *);

    sfClock *lum_clock;

    sfVideoMode mode;

    int framerate;

    sfRenderWindow *win;
    sfVector2i tmp_pos;

    spectator_t *spec;
    int is_fullscreen;
} window_t;

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

typedef struct {
    sfRenderTexture *rtex;
    sfRectangleShape *background;
    sfClock *underscore;
    sfText *text;
    int has_underscore;
} line_edit_t;

typedef struct {
    button_t *buttons[4];

    sfRenderTexture *rtex;

    sfText *name_prompt;
    line_edit_t *name;

    sfText *size;
    slider_t *size_slider;

} map_create_t;

typedef struct {
    button_t *buttons[NB_BUTTONS];
    sfSprite *background;
    sfRenderTexture *rtex;
    sfClock *tip_clock;
    sfRectangleShape *border;
    sfRectangleShape *tooltip_box;
    sfText *tooltip;
    sfVector2f mouse_pos;
    int selected;
    int tool_tip_enabled;
    float y_offset;
    bool is_help;
} game_buttons_t;

typedef struct {
    sfRenderTexture *rtex;
    world_t *world;
    win_t *win;
    sfVector2f size;
    minimap_t *minimap;
    game_buttons_t *gb;
    sfClock *save_clock;
    sfSprite *save_sprite;
    sfSprite *how_to_play;
    char *file;
    int dimension;
    int is_selected;
    int is_from_file;
    int has_saved;
    bool on_help;
} game_t;

typedef struct {
    sfRenderTexture *rtex;
    sfSprite *icon;
    sfText *level_name;
} map_entry_t;

typedef struct {
    button_t *buttons[3];
    sfSprite *background;
    sfRenderTexture *rtex;
    list_t *maps;
    sfRectangleShape *box;
    sfSprite *hider;
    sfVector2f size;
    sfClock *double_click;
    int primary;
    int secondary;
    float x_start;
    int has_clicked;
} map_select_t;

// int rects
static const sfIntRect icon_rect = {
    0, 671, 648, 648
};
static const sfIntRect background_rect = {
    0, 0, 1, 1
};
static const sfIntRect but_rects[3] = {
    {0, 81, 315, 80},
    {0, 81, 315, 80},
    {0, 81, 315, 80}
};
static const sfIntRect vomi_rect = {
    1046, 560, 542, 372
};
static const sfIntRect hider_rect = {
    82, 241, 128, 128
};
static const sfIntRect button_rects[4] = {
    {0, 1, 630, 80},
    {0, 81, 315, 80}
};
static const sfIntRect settings_rects[11] = {
    {160, 161, 80, 80},
    {240, 161, 80, 80},
    {320, 81, 709, 118},
    {320, 199, 709, 118},
    {320, 317, 709, 118},
    {320, 435, 709, 118},
    {320, 553, 709, 118},
    {1028, 81, 709, 118},
    {1028, 199, 709, 118},
    {1028, 317, 709, 118},
    {80, 161, 80, 80}
};
static const sfIntRect gb_rects[] = {
    {648, 671, 80, 80},
    {808, 671, 80, 80},
    {648, 751, 80, 80},
    {728, 671, 80, 80},
    {728, 751, 80, 80},
    {808, 751, 80, 80},
    {888, 751, 80, 80},
    {648, 831, 80, 80},
    {728, 831, 80, 80},
    {808, 831, 80, 80},
    {648, 911, 80, 80},
    {728, 911, 80, 80},
    {808, 911, 80, 80},
    {888, 831, 80, 80},
    {888, 671, 80, 80},
};
static const sfIntRect line_edit_rect = {
    1029, 435, 808, 88
};
static const sfIntRect mc_rects[] = {
    {160, 161, 80, 80},
    {240, 161, 80, 80},
    {0, 81, 315, 80},
    {0, 81, 315, 80}
};
static const sfIntRect slider_rects[3] = {
    {630, 0, 32, 80},
    {662, 0, 382 / 2, 80},
    {662 + 382 / 2, 0, 382 / 2, 80}
};
static const sfIntRect check_rect[2] = {
    {0, 241, 82, 80},
    {0, 161, 80, 80}
};
static const sfIntRect game_button_rects[] = {
    {0, 0, 1, 1}
};
static const sfIntRect cone_rect = {
    0, 369, 128, 128
};
static const sfIntRect save_rect[2] = {
    {648, 991, 624, 106},
    {648, 1097, 624, 106}
};

// settings
static const sfVideoMode available_modes[] = {
    {800, 600, 32},
    {1024, 800, 32},
    {1920, 1080, 32}
};
static const int available_framerates[] = {
    30, 60, 90, 120, 144
};

// size factors
static const float main_buts_sf[4][2] = {
    {0.7, 0.12}, {0.7, 0.12}, {0.33, 0.12}, {0.33, 0.12}
};
static const float select_sf[2] = {0.27, 0.1};
static const float gb_size[2] = {0.22, 0.22};
static const float mc_size_fac[4][2] = {
    {0.06, 0.06}, {0.06, 0.1}, {0.23, 0.1}, {0.23, 0.1}
};

// pos factors
static const float main_buts_pf[4][2] = {
    {0.5, 0.4}, {0.5, 0.6}, {0.313, 0.8}, {0.687, 0.8}
};
static const float select_pf[3][2] = {
    {0.18, 0.9}, {0.5, 0.9}, {0.82, 0.9}
};
static const float gb_pos[10][2] = {
    {0.1925, 0.1925}, {0.5, 0.1925}, {0.8, 0.1925},
    {0.1925, 0.5}, {0.5, 0.5}, {0.8, 0.5},
    {0.1425, 0.8}, {0.38, 0.8}, {0.61, 0.8}, {0.85, 0.8}
};
static const float mc_pos_fac[4][2] = {
    {0.15, 0.69}, {0.805, 0.69}, {0.6, 0.9}, {0.85, 0.9}
};

void factor_color(sfSprite *s, float factor, sfText *text);
void hover_button(button_t *b, int is_on);
void press_button(button_t *b, int is_press);
sfFont *global_font(void);
sfTexture *global_texture(void);
sfSprite *init_sprite_from_texture(sfTexture const *t);
sfText *init_text(char const *str, int charSize);
void set_sprite_size(sfSprite *s, sfVector2f size);
sfSprite *init_sprite(sfTexture *t, sfIntRect rect, sfVector2f size);
button_t *init_button(sfTexture *t, sfIntRect rect, sfVector2f pos, ...);
bool is_on_button(sfVector2f pos, button_t *b);
void check_button_move(button_t **buttons, int nb_button, sfEvent move);
void check_button_press(button_t **buttons, int nb_button, sfEvent press);
int button_at(button_t **buttons, int nb_button, sfEvent release);
void set_next_win_state(window_t *win, int next);
void main_menu_release(main_menu_t *m, sfEvent ev, window_t *win);
void main_menu_event(window_t *win, sfEvent ev);
list_t *add_texture(sfTexture *tex);
void clear_textures(void);
sfVector2f get_sprite_size(sfSprite *s);
void center_sprite(sfSprite *s);
void scale_main_buttons(button_t *buttons[4], sfVector2f winSize);
void move_main_buttons(button_t *buttons[4], sfVector2f winSize);
main_menu_t *init_main_menu(sfTexture *t, sfVector2f winSize);
void draw_button_to_rtex(button_t *b, sfRenderTexture *rtex);
const sfTexture *draw_main_menu(window_t *win);
window_t *window_create(int ac, char **av);
void destroy_home(main_menu_t *menu);
void win_destroy(window_t *win);
void switch_color_dir(window_t *win, int *dir);
void reset_lum(window_t *win, int *dir, sfColor *lum);
void update_lum(sfColor *lum, int *fac);
void update_transition(window_t *win, sfSprite *s);
void draw(window_t *win);
void poll_events(window_t *win);
int main(int ac, char **av);
void center_text(sfText *t);
void scale_check_box(check_box *c, sfVector2f factors);
void set_box_pos(check_box *c, sfVector2f pos);
void draw_check_box(sfRenderTexture *rtex, check_box *c);
check_box *init_check_box(int check, char const *text, window_t *win);
void rescale_all(window_t *win);
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
void sfx_minus(settings_t *se);
void sfx_plus(settings_t *se);
void music_minus(settings_t *se);
void music_plus(settings_t *se);
void update_vol(float m_vol, float s_vol, char const *format, ...);
void settings_ev(window_t *win, sfEvent ev);
const sfTexture *draw_settings(window_t *win);
settings_t *init_settings(window_t *win);
void check_sound_repeat(window_t *win, sfEvent *ev);
void scale_main_menu(main_menu_t *m, window_t *win);
void destroy_settings(settings_t *se);
void destroy_button(button_t *b);
void save_settings(settings_t *se);
void load_settings(settings_t *se);
void apply_settings(settings_t *se, window_t *win);
void scale_line_edit(line_edit_t *le, sfVector2f size);
sfSprite *draw_line_edit(line_edit_t *le, sfVector2f pos);
line_edit_t *create_line_edit(sfVector2f size, char const *def);
sfRectangleShape *rectangle_from_texture(sfTexture const *tex);
map_create_t *create_map_create(sfVector2f win_size);
void scale_mc(map_create_t *mc, sfVector2f win_size);
const sfTexture *draw_mc(window_t *win);
void draw_hider(sfRenderTexture *rtex, sfSprite *hider, sfVector2f size);
void increase_size(void *w);
void decrease_size(void *w);
void launch_size(void *w);
void mc_go_back(void *w);
slider_t *create_slider(sfVector2f size,
sfVector2f bounds, int value, sfVector2f pos);
sfSprite *draw_slider(slider_t *s);
void rescale_slider(slider_t *s, sfVector2f new_size, sfVector2f new_pos);
void slider_event(slider_t *s, sfEvent ev);
void update_positions(slider_t *s);
void destroy_slider(slider_t *s);
sfRectangleShape *create_rectangle(sfVector2f size,
sfColor fill, sfTexture const *tex, ...);
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
game_t *create_game(unsigned size, sfVector2f win_size,
int is_selected, settings_t *se);
const sfTexture *draw_game(window_t *win);
void game_events(window_t *win, sfEvent ev);
mouse_pos_t mouse_pos(sfVector2f win_size, window_t *win);
void destroy_game_struct(game_t *game);
int save_map(game_t *game, const char *filename, unsigned int size);
unsigned int read_map(game_t *game, const char *filename);
sfSprite *draw_gb(game_t *ga);
game_buttons_t *create_buttons(sfVector2f size);
void gb_events(window_t *win, sfEvent ev, sfVector2f pos);
void draw_tooltip(game_t *ga, sfRenderTexture *rtex);
void check_tooltip(game_t *ga);
void world_clicks(window_t *win, sfEvent ev);
bool is_file_valid(char const *file);
map_select_t *create_map_select(sfVector2f size);
const sfTexture *draw_select(window_t *win);
void scale_select(map_select_t *m, sfVector2f size);
sfSprite *draw_entry(map_entry_t *m);
void map_select_events(window_t *m, sfEvent ev);
void refresh_map(game_t *game);
void start_world(game_t *g);
void destroy_gbuttons(game_buttons_t *gb);
void destroy_minimap(minimap_t *m);
void manage_release(map_select_t *m, sfEvent ev, window_t *win);
void scale_entry(map_entry_t *entry, sfVector2f size);
int entry_at(map_select_t *m, sfVector2f m_pos);
void destroy_map_select(map_select_t *map);
void init_entries(map_select_t *m, sfVector2f size);
void center_cam(mat4x4 **mat_world);
spectator_t *create_spectator(sfVector2f size);
void draw_spectator_to_rtex(spectator_t *s,
sfRenderTexture *rtex, sfBool dark, sfBool update);
void destroy_spectator(spectator_t *s);
void destroy_entry(void *entry);
void append_to_text(sfText *t, char c);
void remove_last_text(sfText *t);
const char *get_text(line_edit_t *le);
void save_game(void *w);
void add_hour(void *win);
void sub_hour(void *win);
void pause_game(void *win);
void create_tooltip(game_buttons_t *g, sfVector2f tex_size);
void get_help(void *win);
void quit_game(void *win);
void switch_brush_type(void *win);
unsigned rand_seed(void);
unsigned map_size(char const *map);
map_entry_t *entry_at_list(list_t *l, int index);
char const *get_level_name(window_t *win);
size_t get_level_size(window_t *win);
void restart_map(void *win);
int comp_rectangle(int i_x, int j_y, int s_br);
int comp_circle(int i_x, int j_y, int s_br);
void apply_minimap_brush(game_t *g);
void params(win_t *win, world_t *world, game_t *g);
int save_from_file(game_t *g);
int load_game_from_file(game_t *g, const char *filename);
unsigned map_size_from_file(char const *file);
int check_double_click(map_select_t *m, int entry_clicked);
int recolor_buttons(map_select_t *m, sfVector2f pos);
void set_volume(game_t *g, settings_t *se);
void fullscreen_mode(window_t *win);

#endif
