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
		handle_error("Please enter height and width for window.\nBoth being positive entire numbers.", cube);
	if (!(atoi_cube(str, &i, &cube->wind.y_res)))
		handle_error("Please enter height for window. It must be a positive entire number.", cube);
	check_resolution(str, cube, i);
}

static void		get_no_texture(char *str, t_cube *cube)
{
	get_path(str, &cube->north);
	check_texture(cube->north, "north");
}

static void		get_so_texture(char *str, t_cube *cube)
{
	get_path(str, &cube->south);
	check_texture(cube->south, "south");
}

static void		get_we_texture(char *str, t_cube *cube)
{
	get_path(str, &cube->west);
	check_texture(cube->west, "west");
}

static void		get_ea_texture(char *str, t_cube *cube)
{
	get_path(str, &cube->east);
	check_texture(cube->east, "east");
}

static void		get_sprite_texture(char *str, t_cube *cube)
{
	get_path(str, &cube->sprite);
	check_texture(cube->sprite, "sprite");
}

static void		get_data(char *filedata, t_cube *cube)
{
	if (filedata[0] == 'R')
		get_resolution(filedata, cube);
	if (filedata[0] == 'F')
		get_color_floor(filedata, cube);
	if (filedata[0] == 'C')
		get_color_ceiling(filedata, cube);
	if (filedata[0] == 'N' && filedata[1] == 'O')
		get_no_texture(filedata, cube);
	if (filedata[0] == 'S' && filedata[1] == 'O')
		get_so_texture(filedata, cube);
	if (filedata[0] == 'W' && filedata[1] == 'E')
		get_we_texture(filedata, cube);
	if (filedata[0] == 'E' && filedata[1] == 'A')
		get_ea_texture(filedata, cube);
	if (filedata[0] == 'S')
		get_sprite_texture(filedata, cube);
}

void			data_parsing(t_cube *cube, char *filedata, int *i, int fd)
{
	if (!(is_map_line(filedata)) && *i)
		{
			free(filedata);
			close(fd);
			handle_error("map entry incorrect.", cube);
		}
		get_data(filedata, cube);
		if (is_map_line(filedata))
			(*i)++;
		if (filedata)
			free(filedata);
}

void				get_map_line(t_cube *cube)
{
	int fd;
	char *filedata;
	int i;

	i = 0;
	if ((fd = open(cube->filename, O_RDONLY)) == -1)
		handle_error("Can't read .rt file", cube);
	while(get_next_line(fd, &filedata))
	{
		while (is_map_line(filedata) && ft_strlen(filedata))
		{
			i++;
			free(filedata);
			get_next_line(fd, &filedata);
		}
		if (filedata)
			free(filedata);
	}
	close(fd);
	cube->map.line = i;
	if (!(cube->map.map = malloc(sizeof(char*) * cube->map.line)))
		handle_error("can't malloc map", cube);
}

void			get_map(t_cube *cube)
{
	int fd;
	char *filedata;
	int i;

	i = 0;
	get_map_line(cube);
	if ((fd = open(cube->filename, O_RDONLY)) == -1)
		handle_error("Can't read .rt file", cube);
	while(get_next_line(fd, &filedata))
	{
		while (is_map_line(filedata) && ft_strlen(filedata))
		{
			if (!(cube->map.map[i] = ft_strdup(filedata)))
			{
				close (fd);
				handle_error("can't malloc map line", cube);
			}
			i++;
			free(filedata);
			get_next_line(fd, &filedata);
		}
		if (filedata)
			free(filedata);
	}
	close(fd);
}

void			get_pos(t_cube *cube, int x, int y, char c)
{
	if (cube->cam.pos.x != -1 || cube->cam.pos.y != -1)
		handle_error("there can be only one starting point", cube);
	cube->cam.pos.x = (double)x + 0.5;
	cube->cam.pos.y = (double)y + 0.5;
	if (c == 'N')
	{
		cube->cam.direction.x = 0;
		cube->cam.direction.y = -1;
		cube->cam.plane.x = 0.66;
		cube->cam.plane.y = 0;
	}
	if (c == 'S')
	{
		cube->cam.direction.x = 0;
		cube->cam.direction.y = 1;
		cube->cam.plane.x = -0.66;
		cube->cam.plane.y = 0;
	}
	if (c == 'E')
	{
		cube->cam.direction.x = 1;
		cube->cam.direction.y = 0;
		cube->cam.plane.x = 0;
		cube->cam.plane.y = 0.66;
	}
	if (c == 'W')
	{
		cube->cam.direction.x = -1;
		cube->cam.direction.y = 0;
		cube->cam.plane.x = 0;
		cube->cam.plane.y = -0.66;
	}
}

void			get_nsew(t_cube *cube)
{
	int y;
	int x;

	y = 0;
	cube->cam.pos.x = -1;
	cube->cam.pos.y = -1;
	while(y < cube->map.line)
	{
		x = 0;
		while (cube->map.map[y][x])
		{
			if (isinstr("NSEW", cube->map.map[y][x]))
				get_pos(cube, x, y, cube->map.map[y][x]);
			x++;
		}
		y++;
	}
	if (cube->cam.pos.x == -1)
		handle_error("You must add a starting point in map", cube);
}

void			parsing_file(t_cube *cube)
{
	char *filedata;
	int fd;
	int i;

	i = 0;
	if ((fd = open(cube->filename, O_RDONLY)) == -1)
		handle_error("Can't read .rt file", cube);
	while(get_next_line(fd, &filedata))
	{
		data_parsing(cube, filedata, &i, fd);
	}
	data_parsing(cube, filedata, &i, fd);
	close(fd);
	get_map(cube);
	get_nsew(cube);
}