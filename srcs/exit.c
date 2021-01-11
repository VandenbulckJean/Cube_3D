#include "cube.h"

void	destroy_map(t_cube *cube)
{
	int i;

	i = 0;
	while (i < cube->map.line)
	{
		if (cube->map.map[i])
			free(cube->map.map[i]);
		i++;
	}
	if (cube->map.map)
		free(cube->map.map);
}

void	free_texture_path(t_cube *cube)
{
	if (cube->north.path)
		free(cube->north.path);
	if (cube->south.path)
		free(cube->south.path);
	if (cube->west.path)
		free(cube->west.path);
	if (cube->east.path)
		free(cube->east.path);
	if (cube->sprite.path)
		free(cube->sprite.path);
}

void	handle_error(char *string, t_cube *cube)
{
	destroy_map(cube);
	if (cube->filename)
		free(cube->filename);
	free_texture_path(cube);
	ft_printf("Error: %s\n", string);
	exit(EXIT_FAILURE);
}

void	handle_exit(t_cube *cube)
{
	destroy_map(cube);
	if (cube->filename)
		free(cube->filename);
	free_texture_path(cube);
	exit(EXIT_SUCCESS);
}