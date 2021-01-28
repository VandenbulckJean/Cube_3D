/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:49:48 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/28 13:29:48 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static void		define_sprite_pos(t_cube *cube)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	while (cube->map.map[y])
	{
		x = 0;
		while (cube->map.map[y][x])
		{
			if (cube->map.map[y][x] == '2')
			{
				cube->sprite.tab[i].x = x + 0.5;
				cube->sprite.tab[i].y = y + 0.5;
				cube->sprite.order[i] = i;
				i++;
			}
			x++;
		}
		y++;
	}
}

void			initialise_sprites(t_cube *cube)
{
	cube->sprite.amount = count_sprites(cube);
	if (!(cube->sprite.tab = malloc(sizeof(t_sprite) * cube->sprite.amount)))
		handle_error("can't malloc sprites", cube);
	if (!(cube->sprite.order = malloc(sizeof(int) * cube->sprite.amount)))
		handle_error("can't malloc sprites order", cube);
	if (!(cube->sprite.dist = malloc(sizeof(double) * cube->sprite.amount)))
		handle_error("can't malloc sprites distances", cube);
	define_sprite_pos(cube);
}

int				count_sprites(t_cube *cube)
{
	int	x;
	int	y;
	int i;

	y = 0;
	i = 0;
	while (cube->map.map[y] != NULL)
	{
		x = 0;
		while (cube->map.map[y][x])
		{
			if (cube->map.map[y][x] == '2')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void			get_sprite_distances(t_cube *cube, t_vecteur pos)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < cube->sprite.amount)
	{
		x = cube->sprite.tab[i].x;
		y = cube->sprite.tab[i].y;
		cube->sprite.dist[i] = ((pos.x - x) * (pos.x - x)
		+ (pos.y - y) * (pos.y - y));
		i++;
	}
}

void			ord_sprites(t_cube *cube)
{
	int			tmp;
	int			i;
	int			change;

	change = 1;
	get_sprite_distances(cube, cube->cam.pos);
	while (change)
	{
		change = 0;
		i = 1;
		while (i < cube->sprite.amount)
		{
			if (cube->sprite.dist[cube->sprite.order[i - 1]]
			< cube->sprite.dist[cube->sprite.order[i]])
			{
				tmp = cube->sprite.order[i];
				cube->sprite.order[i] = cube->sprite.order[i - 1];
				cube->sprite.order[i - 1] = tmp;
				change = 1;
			}
			i++;
		}
	}
}
