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

void	handle_error(char *string, t_cube *cube)
{
	destroy_map(cube);
	ft_printf("Error: %s\n", string);
	exit(EXIT_FAILURE);
}