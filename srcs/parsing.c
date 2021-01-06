#include "cube.h"

void	getcolorvalue(char *str, int *i, t_color *color, char *error)
{
	if (!(atoi_cube(str, i, &color->r)))
	{
	ft_printf("Missing red green and blue colors in %s.\n", error);
	exit(EXIT_FAILURE);
	}
	if (str[*i] == ',')
		(*i)++;
	if (!(atoi_cube(str, i, &color->g)))
	{
		ft_printf("Missing green and blue colors in %s.\n", error);
		exit(EXIT_FAILURE);
	}
	if (str[*i] == ',')
		(*i)++;
	if (!(atoi_cube(str, i, &color->b)))
	{
		ft_printf("Missing blue color in %s.\n", error);
		exit(EXIT_FAILURE);
	}
}

static void		get_path(char *str, t_texture *texture)
{
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	texture->path = ft_strdup(str + i);
}

static void		get_color_floor(char *str, t_cube *cube)
{
	int i;

	i = 1;
	getcolorvalue(str, &i, &cube->floor, "floor line");
	check_color_value(str, cube->floor, i, "floor");
}

static void		get_color_ceiling(char *str, t_cube *cube)
{
	int i;

	i = 1;
	getcolorvalue(str, &i, &cube->ceiling, "ceiling line");
	check_color_value(str, cube->ceiling, i, "ceiling");
}

static void		get_resolution(char *str, t_cube *cube)
{
	int i;

	i = 1;
	if (!(atoi_cube(str, &i, &cube->wind.x_res)))
		handle_error("Please enter height and width for window.\nBoth being positive entire numbers.");
	if (!(atoi_cube(str, &i, &cube->wind.y_res)))
		handle_error("Please enter height for window. It must be a positive entire number.");
	check_resolution(str, cube, i);
}

static void		get_data(char *filedata, t_cube *cube)
{
	if (filedata[0] == 'R')
		get_resolution(filedata, cube);
	if (filedata[0] == 'F')
		get_color_floor(filedata, cube);
	if (filedata[0] == 'C')
		get_color_ceiling(filedata, cube);
}

void			parsing_file(t_cube *cube, char *filename)
{
	char *filedata;
	int fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		handle_error("Can't read .rt file");
	while(get_next_line(fd, &filedata))
	{
		get_data(filedata, cube);
	}
}