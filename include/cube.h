#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../minilibx_metal/mlx.h"
#include "../libft_19/libft_bonus.h"
# define Speed 0.08
# define Alpha 0.1
# define Glitchdist 0.2

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef	struct		s_window
{
	int				x_res;
	int				y_res;
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

typedef struct		s_cam
{
	t_vecteur		pos;
	t_vecteur		direction;
	t_vecteur		plane;
	t_vecteur		raydir;
	t_vecteur		deltadist;
	t_vecteur		sidedist;
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
	int				line;
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
	t_texture		sprite;
	t_map			map;
	t_cam			cam;
	t_img			current_img;
	t_img			next_img;
	t_keyboard		event;
}					t_cube;

//utils
void				handle_error(char *string, t_cube *cube);
int					ft_samestr(char *s1, char *s2);
int					atoi_cube(char *str, int *i, int *result);
int					is_correct_path_char(char c);
int					is_map_line(char *str);
void				set_pixel_color(t_cube *cube, int pixelpos, t_color color);

//checks

void				check_resolution(char *str, t_cube *cube, int i);
void				check_arguments(int argc, char*argv[], t_cube *cube);
void				check_color_value(char *str, t_color color, int i, char *error);
void				check_texture(t_texture texture, char *error);

//parsing

void					parsing_file(t_cube *cube);

//Raycasting
void	get_object_limits(t_cube *cube);
void	draw_stripe(t_cube *cube);
void	raycasting(t_cube *cube);
void	rotation_pov(t_cube *cube, int is_left);
void	refreshscreen(t_cube *cube);

//init
void	initialisation(t_cube *cube);

//event
void	event_loop(t_cube *cube);
void	handle_exit(t_cube *cube);

//movement
void	move_forward(t_cube *cube);
void	move_backward(t_cube *cube);
void	strafleft(t_cube *cube);
void	strafright(t_cube *cube);

#endif