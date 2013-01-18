/*
** struct.h for strucy in /home/lecler_i//afs/local/igraph/tp-3
**
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
**
** Started on  Tue Nov 20 15:14:02 2012 thomas leclercq
** Last update Fri Jan 18 22:37:19 2013 thomas leclercq
*/

#ifndef __WOLF_H__
#define __WOLF_H__


#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include "my.h"
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <mlx.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <sys/time.h>

#define NB_CAST 960
#define P_X 960
#define P_Y 960
#define B_SIZE 640
#define RAD(angle) ((angle) / 180.0 * 3.141592654)
#define ABS(int) ((int < 0) ? -int : int)

#define UP 400
#define RIGHT 401
#define DOWN 402
#define LEFT 403

#define BLUE 0x3236FF
#define WHITE 0xFFFFFF
#define RED 0xFF0004

#define SKY 0x383838
#define FLOOR 0x707070

#define KEY_UP 0
#define KEY_DOWN 1
#define KEY_LEFT 2
#define KEY_RIGHT 3
#define KEY_ACTION 4
#define KEY_SPACE 5
#define KEY_EXIT 6
#define KEY_SHIFT 7
#define KEY_1 8
#define KEY_2 9
#define KEY_3 10
#define KEY_4 11

#include "sound/fmod/inc/fmod.h"
#include "sound/fmod/inc/fmod_errors.h" 

/* 49 50 51 */


#define ACTION_DOOR 0

typedef struct		s_p_infos
{
  double		height;
  int			fov;
  int			x;
  int			y;
  int			angle;
  int			weapon;
}t_p_infos;

typedef struct		s_block
{
  int			code;
  int			y;
  int			x;
  char			*str;
  char			wall;
  char			crossable;
  struct s_texture	*texture[4];
  struct s_texture	*mask[4];
  int			angle_tp;
  int			y_tp;
  int			x_tp;
  struct s_texture	*item;
}t_block;

typedef struct		s_map
{
  t_block		***tab;
  char			*path;
  int			h;
  int			w;
  t_block		*spawn;
  char			*bg;
  struct s_win		*win;
  struct s_img		*img;
}t_map;

typedef struct		s_win
{
  void			*id;
  char			*name;
  int			w;
  int			h;
}t_win;

typedef struct		s_sound
{
  FMOD_SOUND		*sound;
}t_sound;

typedef struct		s_sprites
{
  struct s_block	*block;
  int			distance;
  struct s_sprites	*next;
}t_sprites;

typedef struct		s_img
{
  void			*img_ptr;
  char			*data;
  int			w;
  int			h;
  int			bpp;
  int			sizeline;
  int			endian;
}t_img;

typedef struct		s_conf
{
  char			*name;
  char			**content;
  struct s_config	*next;
}t_conf;

typedef struct		s_texture
{
  char			alias;
  char			*path;
  struct s_img		*img;
  struct s_texture	*next;
}t_texture;

typedef struct		s_weapon
{
  int			id;
  int			ammo;
  FMOD_SOUND		*use_sound;
  FMOD_SOUND		*switch_sound;
  struct s_img		*img[10];
  struct s_img		*ui;
}t_weapon;

typedef struct		s_interface
{
  struct s_img		*face[3];
  struct s_img		*actions[1];
  struct s_img		*main;
  struct s_img		*load;
}t_interface;

typedef struct		s_vec
{
  char			check;
  int			nb;
  int			x;
  int			y;
  int			distance;
  float			angle;
  float			offset;
  int			facing;
  int			height;
  struct s_block	*block;
}t_vec;

typedef struct		s_draw
{
  float			rap_y;
  float			rap_x;
  int			ecart;
  t_img			*texture;
  t_img			*mask;
}t_draw;

typedef struct		s_key
{
  int			keycode;
  int			state;
  struct s_key		*next;
}t_key;

typedef struct		s_xdisplay
{
  Display		*dpy;
  Window		root_window;
}t_xdisplay;

typedef struct		s_infos
{
  void			*mlx_ptr;
  t_win			*win;
  t_img			*img;
  t_map			*map;
  t_conf		*conf;
  t_p_infos		*p_infos;
  t_texture		*texture;
  t_interface		*ui;
  t_weapon		*weapons[3];
  int			keys[13][2];
  int			cur_weap_anim;
  int			action_possible;
  t_xdisplay		x11_display;
  FMOD_SYSTEM		*system_sound;
}t_infos;

/* DRAW/BASICS.C */
int		pos_in_img(t_img *img, int x, int y);
int		char_to_color(char *tab);
void		my_pixel_put_to_image(t_img *img, int x, int y, int color);
void		draw_sky_floor(t_img *img);

/* DRAW/WALLS.C */
void		balayage_walls(t_infos *infos);
int		hor_walls(t_p_infos *p_infos, t_map *map, float angle, t_vec *vec);
int		ver_walls(t_p_infos *p_infos, t_map *map, float angle, t_vec *vec);
int		draw_walls(t_infos *infos, t_vec vec);
int		draw_walls_col(t_infos *infos, int x, t_vec vec, t_draw inf);

/* FREE.C */
void		free_map(t_map *map);
void		free_win(t_win *win);
void		free_img(t_img *img);
void		free_p_infos(t_p_infos *p_infos);
void		my_exit(t_infos *infos);

/* WEAPONS.C */
t_weapon		*create_pistol(t_infos *infos);
t_weapon		*create_knife(t_infos *infos);
void			*create_weapons(t_infos *infos);
int			shoot(t_infos *infos);
int			switch_weapon(t_infos *infos, int weapon);

/* CASTING.C */
int			dir(float angle, int bool);
int			calc_distance(t_p_infos *p_infos, int x, int y);
int			calc_dist(t_infos *infos);

/* PARSING/MAP1.C */
int			open_map(char *path);
int			my_cnt_lines(char *path);
t_texture		*find_texture(t_texture *texture, char alias, t_texture *def);
t_block			fill_block(t_block *blck, int y, int x, t_infos *infos);
t_block			*generate_block(char *str, int y, int x, t_infos *infos);
t_block			***create_tab(t_map *map, char *path, t_infos *infos, int fd);
t_map			*pars_map(char *path, t_infos *infos);
char			*get_next_line(int fd);


int			key_press(int keycode, t_infos *infos);
int			key_release(int keycode, t_infos *infos);
/* int			mlx_key_pulse_press(t_win_list *win,int (*funct)(),void *param); */
/* int			mlx_key_pulse_release(t_win_list *win,int (*funct)(),void *param); */
long			getTicks();

/* MAIN.c */
int     wolf(int argc, char **argv);

/* EVENTS.c */
int	calc_pos(t_infos *infos, float move);
void	refresh(t_infos *infos);
void	event(t_infos *infos);
void	balayage_walls(t_infos *infos);
void	check_collision(int y, int x, t_block ***block);
void	collision(int y, int x, t_block *block);
float   check_angle(float angle);


/* SOUND.C */
FMOD_SOUND      *create_sound(FMOD_SYSTEM *system, char *path, int boucle);
int             play_sound(FMOD_SYSTEM *system, FMOD_SOUND *sound);


t_win		*create_win(void *mlx_ptr, int width, int height, char *name);
t_img		*create_img(void *mlx_ptr, int width, int height);
t_interface	*create_interface(void *mlx_ptr);
t_infos		*create_infos(char **argv);
t_p_infos	*create_p_infos(t_infos *infos);


void    draw_sky_floor(t_img *img);
void    draw_square(t_img *img, int y, int x, int size, int color);

t_img           *create_texture_img(void *mlx_ptr, char *path);

int		mouse_motion(int x, int y, t_infos *infos);
int		mouse_event(int button, int x, int y, t_infos *infos);

t_texture	*create_texture(void *mlx_ptr, char alias, char *path);

int             key_press(int keycode, t_infos *infos);
int             key_release(int keycode, t_infos *infos);
void	        mouse_click(int button, t_xdisplay x_display);


#endif
