#include "../include/cube.h"

int ft_samestr(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i++])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

int			is_map_line(char *str)
{
	int i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!(isinstr("012 NESW", str[i])))
			return (0);
		i++;
	}
	return (1);
}

int			is_correct_path_char(char c)
{
	if (ft_isprint(c) && c != ' ')
		return (1);
	return (0);
}

int			atoi_cube(char *str, int *i, int *result)
{
	int sign;
	int check;

	*result = 0;
	sign = 0;
	while(str[*i] && str[*i] == ' ')
		(*i)++;
	if (str[*i] && str[*i] == '-')
	{
		sign++;
		(*i)++;
	}
	check = *i;
	while(isnumber(str[*i]))
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
		if (*result > 2000)
		{
			while(isnumber(str[*i]))
				(*i)++;
			break;
		}
	}
	if (sign)
		*result = -(*result);
	if (check == *i)
		return (0);
	return (1);
}

void	set_pixel_color(t_cube *cube, int pixelpos, t_color color)
{
	cube->next_img.address[pixelpos] = color.b;
	cube->next_img.address[pixelpos + 1] = color.g;
	cube->next_img.address[pixelpos + 2] = color.r;
}

void	set_samepixelcolor(t_cube *cube, int pixelpos, t_texture *texture)
{
	int pixelpos_texture;
	texture->hity += texture->step;
	pixelpos_texture = texture->hitx * texture->img.bpp / 8 + texture->img.size_line * (int)texture->hity;
	cube->next_img.address[pixelpos] = texture->img.address[pixelpos_texture];
	cube->next_img.address[pixelpos + 1] = texture->img.address[pixelpos_texture + 1];
	cube->next_img.address[pixelpos + 2] = texture->img.address[pixelpos_texture + 2];
}

void	draw_wall_texture(t_cube *cube)
{
	int pixelpos;
	int i;

	i = cube->cam.objectstart;
	while (i < cube->cam.objectend)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		if (cube->cam.side == 0 && cube->cam.raydir.x < 0)
		{
			set_samepixelcolor(cube, pixelpos, &cube->west);
		}
		else if (cube->cam.side == 0 && cube->cam.raydir.x > 0)
		{
			set_samepixelcolor(cube, pixelpos, &cube->east);
		}
		else if (cube->cam.side == 1 && cube->cam.raydir.y < 0)
		{
			set_samepixelcolor(cube, pixelpos, &cube->north);
		}
		else if (cube->cam.side == 1 && cube->cam.raydir.y > 0)
		{
			set_samepixelcolor(cube, pixelpos, &cube->south);
		}
		i++;
	}	
}

void	refreshscreen(t_cube *cube)
{
	raycasting(cube);
}

int	is_space(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	return (0);
}