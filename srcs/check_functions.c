#include "../include/cube.h"

void	check_texture(t_texture texture, char *error)
{
	int i;

	i = 0;
	while (texture.path[i])
	{
		if (!(is_correct_path_char(texture.path[i])))
		{
			ft_printf("Error: path incorrect for %s texture.", error);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_resolution(char *str, t_cube *cube, int i)
{
	int x;
	int y;
	
	mlx_get_screen_size(cube->ptr, &x, &y);
	while (str[i])
		if (str[i++] != ' ')
			handle_error("Resolution line must only contain height and width.", cube);
	if (cube->wind.x_res < 1)
		handle_error("the window width must be a positive number.", cube);
	if (cube->wind.y_res < 1)
		handle_error("the window height must be a positive number.", cube);
	if (cube->wind.x_res > x)
		cube->wind.x_res = x;
	if (cube->wind.y_res > y)
		cube->wind.y_res = y;
}

void	check_color_value(char *str, t_color color, int i, char *error)
{
	while (str[i])
		if (str[i++] != ' ')
		{
			ft_printf("Error: %s line must only contain red green and blue values.\n", error);
			exit(EXIT_FAILURE);
		}
	if (color.r > 255 || color.r < 0)
	{
		ft_printf("Error: %s red color must be a number between 0 et 255.\n", error);
		exit(EXIT_FAILURE);
	}
	if (color.g > 255 || color.g < 0)
	{
		ft_printf("Error: %s green color must be a number between 0 et 255.\n", error);
		exit(EXIT_FAILURE);
	}
	if (color.b > 255 || color.b < 0)
	{
		ft_printf("Error: %s blue color must be a number between 0 et 255.\n", error);
		exit(EXIT_FAILURE);
	}
}

static void		check_file_name(char *str, t_cube *cube)
{
	int len;

	len = (int)ft_strlen(str);
	if (len < 5)
		handle_error("File name incorrect", cube);
	if (str[len-4] != '.' || str[len-3] != 'c' || str[len-2] != 'u' || str[len-1] != 'b')
		handle_error("File name incorrect", cube);
	if (!(cube->filename = ft_strdup(str)))
		handle_error("malloc filename", cube);

}

static void		check_second_argument(char *str, t_cube *cube)
{
	if (!(ft_samestr("--save", str)))
		handle_error("Second argument must be --save", cube);
}

void				check_arguments(int argc, char*argv[], t_cube *cube)
{
	if (argc == 1)
		handle_error("Enter at least an .cub file as first argument", cube);
	if (argc == 2)
		check_file_name(argv[1], cube);
	if (argc == 3)
	{
		check_file_name(argv[1], cube);
		check_second_argument(argv[2], cube);
	}
	if (argc > 3)
		handle_error("Too many arguments", cube);
}