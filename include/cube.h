#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../minilibx_metal/mlx.h"
#include "../libft_19/libft_bonus.h"
# define Speed 0.1
# define Alpha 0.1
# define Glitchdist 0.2

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				line;
}					t_color;

typedef	struct		s_window
{
	int				x_res;
	int				y_res;
	int				res_line;
	void			*ptr;
}					t_window;

typedef struct		s_img
{
	unsigned char	*address;
	void			*ptr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_vecteur
{
	double			x;
	double			y;
}					t_vecteur;

typedef struct 		s_texture
{
	char			*path;
	t_img			img;
	int				width;
	int				height;
	int				hitx;
	double 			hity;
	double			step;
}					t_texture;

typedef struct		s_keyboard
{
	int				w_pressed;
	int				a_pressed;
	int				s_pressed;
	int				d_pressed;
	int				right_arow_pressed;
	int				left_arrow_pressed;
}					t_keyboard;

typedef struct		s_sprite
{
	t_vecteur		*tab;
	int				*order;
	int				amount;
	t_vecteur		campos;
	double			invdet;
	int				stripe;
	int				height;
	int				width;
	int				centerstripe;
	t_vecteur		transform;
	int				startx;
	int				starty;
	int				endx;
	int				endy;
	t_texture		texture;

}					t_sprite;

typedef struct		s_cam
{
	t_vecteur		pos;
	t_vecteur		direction;
	t_vecteur		plane;
	t_vecteur		raydir;
	t_vecteur		deltadist;
	t_vecteur		sidedist;
	double			*distbuffer;
	double			walldist;
	double			camx;
	t_vecteur		step;
	int				objectheight;
	int				objectstart;
	int				objectend;
	int				side;
	int				p_stripe;
	int				hit;
	double			wallhitx;

}					t_cam;

typedef struct		s_map
{
	char 			**map;
	t_vecteur		pos;
}					t_map;

typedef struct		s_cube
{
	void			*ptr;
	char			*filename;
	t_window		wind;
	t_color			floor;
	t_color			ceiling;
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_map			map;
	t_sprite		sprite;
	t_cam			cam;
	t_img			next_img;
	t_keyboard		event;
}					t_cube;

//utils
void				handle_error(char *string, t_cube *cube);
void				atoi_cube(char *str, int *i, int *result);
int					check_if_number(char *str, int i);
int					is_empty_line(char *str);
int					ft_samestr(char *s1, char *s2);
int					is_map_line(char *str);
void				set_pixel_color(t_cube *cube, int pixelpos, t_color color);
void				set_samepixelcolor(t_cube *cube, int pixelpos, t_texture *texture);
void				draw_wall_texture(t_cube *cube);
int					is_space(char c);
int					is_first_closer(t_vecteur s1, t_vecteur s2, t_vecteur pos);

//sprites
int					count_sprites(t_cube *cube);
void				ord_sprites(t_cube *cube);
int					is_pixel_black(t_texture texture);
void				initialise_sprites(t_cube *cube);

//checks
void				check_env_data(t_cube *cube);
void				check_arguments(int argc, char*argv[], char **filename);
int					check_map(char **map);

//parsing

void				parsing_env_data(t_cube *cube);
void				get_color_floor(char *str, t_cube *cube);
void				get_color_ceiling(char *str, t_cube *cube);
void				parsing_map(t_cube *cube);

//Raycasting
void				get_object_limits(t_cube *cube);
void				draw_stripe(t_cube *cube);
void				raycasting(t_cube *cube);
void				rotation_pov(t_cube *cube, int is_left);
void				refreshscreen(t_cube *cube);
void				get_wall_hit_x(t_cube *cube);

//init
void				initialisation(t_cube *cube);
void				init_values_parsing(t_cube *cube);

//event
void				event_loop(t_cube *cube);
void				handle_exit(t_cube *cube);

//movement
void				move_forward(t_cube *cube);
void				move_backward(t_cube *cube);
void				strafleft(t_cube *cube);
void				strafright(t_cube *cube);

//sprite
void				initialise_sprites(t_cube *cube);
void				do_sprites(t_cube *cube);

//exit
void				print_error_exit(char *error);
void				handle_error_parsing(char * error, t_cube *cube);
void				handle_missing_color(char *missingcolors, char *colorname, t_cube *cube);
void				free_parsing(t_cube *cube);

void			make_bmp(t_cube *cube);
#endif