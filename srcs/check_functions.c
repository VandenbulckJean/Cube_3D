#include "../include/cube.h"

void	check_resolution(t_cube *cube)
{
	int x;
	int y;
	
	if (!(cube->wind.res_line))
		handle_error_parsing("Window resolution line missing", cube);
	mlx_get_screen_size(cube->ptr, &x, &y);
	if (cube->wind.x_res < 1)
		handle_error_parsing("the window width must be a positive number", cube);
	if (cube->wind.y_res < 1)
		handle_error_parsing("the window height must be a positive number", cube);
	if (cube->wind.x_res > x)
		cube->wind.x_res = x;
	if (cube->wind.y_res > y)
		cube->wind.y_res = y;
}

void	check_color_value(t_color color, char *colorname, t_cube *cube)
{
	if (color.r > 255 || color.r < 0)
	{
		ft_printf("Error: %s red color must be a number between 0 et 255.\n", colorname);
		free_parsing(cube);
		exit(EXIT_FAILURE);
	}
	if (color.g > 255 || color.g < 0)
	{
		ft_printf("Error: %s green color must be a number between 0 et 255.\n", colorname);
		free_parsing(cube);
		exit(EXIT_FAILURE);
	}
	if (color.b > 255 || color.b < 0)
	{
		ft_printf("Error: %s blue color must be a number between 0 et 255.\n",
		colorname);
		free_parsing(cube);
		exit(EXIT_FAILURE);
	}
}

void	check_texture_path_given(t_texture texture,
char *texturename, t_cube *cube)
{
	if (!(texture.path))
	{
		free_parsing(cube);
		ft_printf("Error\nMissing %s texture path.", texturename);
		exit(EXIT_FAILURE);
	}
}

void	check_texture_path(t_texture texture, char *texturename, t_cube *cube)
{
	int i;
	int len;

	i = 0;
	check_texture_path_given(texture, texturename, cube);
	len = ft_strlen(texture.path);
	if (texture.path[len - 1] != 'm' || texture.path[len - 2] != 'p'
	|| texture.path[len - 3] != 'x' || texture.path[len - 4] != '.')
		handle_error_parsing("please enter xpm file for every texture", cube);
	while (texture.path[i])
	{
		if (is_space(texture.path[i]))
		{
			free_parsing(cube);
			ft_printf("Error\nPath incorrect for %s texture.", texturename);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_env_data(t_cube *cube)
{
	check_resolution(cube);
	if (!(cube->floor.line))
		handle_error_parsing("Missing floor color line", cube);
	check_color_value(cube->floor, "floor", cube);
	if (!(cube->ceiling.line))
		handle_error_parsing("Missing ceiling color line", cube);
	check_color_value(cube->ceiling, "ceiling", cube);
	check_texture_path(cube->north, "north", cube);
	check_texture_path(cube->south, "south", cube);
	check_texture_path(cube->east, "east", cube);
	check_texture_path(cube->west, "west", cube);
	check_texture_path(cube->sprite.texture, "sprite", cube);
}
