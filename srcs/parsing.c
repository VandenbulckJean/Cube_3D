#include "../include/cube.h"

static void		get_resolution(char *str, t_cube *cube)
{
	int i;

	i = 1;
	cube->wind.res_line = 1;
	while (str[i] && !(isnumber(str[i])) && str[i] != '-')
	{
		if (!(is_space(str[i++])))
			handle_error_parsing("Resolution line must only contain height and width", cube);
	}
	if (check_if_number(str, i))
		handle_error_parsing("Please enter height and width for window.\nBoth being positive entire numbers", cube);
	atoi_cube(str, &i, &cube->wind.x_res);
	if (check_if_number(str, i))
		handle_error_parsing("Please enter height for window. It must be a positive entire number", cube);
	atoi_cube(str, &i, &cube->wind.y_res);
	while (str[i])
		if (str[i++] != ' ')
			handle_error_parsing("Resolution line must only contain height and width", cube);
	if (!(cube->cam.distbuffer = malloc(sizeof(double) * cube->wind.x_res)))
		handle_error_parsing("can't malloc distance buffer", cube);
}

static void		get_path(char *str, t_texture *texture)
{
	int i;

	i = 2;
	while (is_space(str[i]))
		i++;
	texture->path = ft_strdup(str + i);
}

static void			parsing_data(t_cube *cube, char *filedata)
{
	if (filedata[0] == 'R' && is_space(filedata[1]))
		get_resolution(filedata, cube);
	else if (filedata[0] == 'F' && is_space(filedata[1]))
		get_color_floor(filedata, cube);
	else if (filedata[0] == 'C' && is_space(filedata[1]))
		get_color_ceiling(filedata, cube);
	else if (filedata[0] == 'N' && filedata[1] == 'O' && is_space(filedata[2]))
		get_path(filedata, &cube->north);
	else if (filedata[0] == 'S' && filedata[1] == 'O' && is_space(filedata[2]))
		get_path(filedata, &cube->south);
	else if (filedata[0] == 'W' && filedata[1] == 'E' && is_space(filedata[2]))
		get_path(filedata, &cube->west);
	else if (filedata[0] == 'E' && filedata[1] == 'A' && is_space(filedata[2]))
		get_path(filedata, &cube->east);
	else if (filedata[0] == 'S' && is_space(filedata[1]))
		get_path(filedata, &cube->sprite.texture);
	else
	{
		if (!(is_empty_line(filedata)))
			handle_error_parsing(".cub file contain unreadable line", cube);	
	}
}

void			parsing_env_data(t_cube *cube)
{
	char	*filedata;
	int		fd;
	int		i;
	int		check;

	i = 0;
	if ((fd = open(cube->filename, O_RDONLY)) == -1)
		handle_error_parsing("Can't open .cub file", cube);
	while ((check = get_next_line(fd, &filedata) != 2))
	{
		if (check == -1)
			handle_error_parsing("get next line alloc", cube);
		if (is_map_line(filedata))
			free(filedata);
		else
		{
			parsing_data(cube, filedata);
			free(filedata);
		}
	}
	close(fd);
}
