#include "cube.h"

void	check_resolution(char *str, t_cube *cube, int i)
{
	while (str[i])
		if (str[i++] != ' ')
			handle_error("Resolution line must only contain height and width.");
	if (cube->wind.x_res < 1)
		handle_error("the window width must be a positive number.");
	if (cube->wind.y_res < 1)
		handle_error("the window height must be a positive number.");
	/*if (cube->wind.x_res > X_MAX)
		cube->wind.x_res = X_MAX;
	if (cube->wind.y_res > Y_MAX)
		cube->wind.y_res = Y_MAX;*/
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

static void		check_file_name(char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (len < 5)
		handle_error("File name incorrect");
	if (str[len-4] != '.' || str[len-3] != 'c' || str[len-2] != 'u' || str[len-1] != 'b')
		handle_error("File name incorrect");
}

static void		check_second_argument(char *str)
{
	if (!(ft_samestr("--save", str)))
		handle_error("Second argument must be --save");
}

void				check_arguments(int argc, char*argv[])
{
	if (argc == 1)
		handle_error("Enter at least an .cub file as first argument");
	if (argc == 2)
		check_file_name(argv[1]);
	if (argc == 3)
	{
		check_file_name(argv[1]);
		check_second_argument(argv[2]);
	}
	if (argc > 3)
		handle_error("Too many arguments");
}