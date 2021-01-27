/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsingbis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:18:35 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/27 15:18:36 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int					is_map_closed(int y, int x, char **map)
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

int					check_map(char **map)
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

static void			get_pos_bis(t_cube *cube, char c)
{
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

void				get_pos(t_cube *cube, int x, int y, char c)
{
	if (cube->cam.pos.x != -1 || cube->cam.pos.y != -1)
		handle_error_parsing("There can be only one starting point", cube);
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
	get_pos_bis(cube, c);
}
