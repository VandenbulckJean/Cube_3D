#include "../include/cube.h"

int			is_map_closed(int y, int x, char **map)
{
	if (map[y + 1] == NULL)
		return (0);
	if ((int)ft_strlen(map[y - 1]) <= x)
		return (0);
	if ((int)ft_strlen(map[y + 1]) <= x)
		return (0);
	if ((int)ft_strlen(map[y]) == x)
		return (0);
	if (x == 0)
		return (0);
	if (y == 0)
		return (0);
	
	if (!(isinstr("012NSEW", map[y - 1][x])))
		return (0);
	if (!(isinstr("012NSEW", map[y - 1][x])))
		return (0);
	if (!(isinstr("012NSEW", map[y][x - 1])))
		return (0);
	if (!(isinstr("012NSEW", map[y][x + 1])))
		return (0);
	return (1);
}

int			check_map(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (isinstr("02NSEW", map[y][x]))
				if (!(is_map_closed(y, x, map)))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}