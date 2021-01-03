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

typedef struct		s_cube
{
	void			*ptr;
	t_window		wind;
}					t_cube;

//utils
void	handle_error(char *string);
int ft_samestr(char *s1, char *s2);
void				check_arguments(int argc, char*argv[]);


#endif