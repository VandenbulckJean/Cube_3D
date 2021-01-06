#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../minilibx_metal/mlx.h"
#include "../libft_19/libft_bonus.h"

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

typedef struct		s_pos
{
	float			x;
	float			y;
}					t_pos;

typedef struct 		s_texture
{
	char			*path;
}					t_texture;

typedef struct s_map
{
	int		**map;
}				t_map;

typedef struct		s_cube
{
	void			*ptr;
	t_window		wind;
	t_color			floor;
	t_color			ceiling;
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_texture		sprite;
	t_pos			pos;
	t_map			map;
}					t_cube;

//utils
void				handle_error(char *string);
int					ft_samestr(char *s1, char *s2);
int					atoi_cube(char *str, int *i, int *result);

//checks

void				check_resolution(char *str, t_cube *cube, int i);
void				check_arguments(int argc, char*argv[]);
void	check_color_value(char *str, t_color color, int i, char *error);

//parsing

void					parsing_file(t_cube *cube, char *filename);


#endif