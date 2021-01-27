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
	define_sprite_pos(cube);
}

int		is_pixel_black(t_texture texture)
{
	int pixelpos;

	pixelpos = texture.hitx * texture.img.bpp / 8 + texture.img.size_line * (int)texture.hity;
	if (texture.img.address[pixelpos] == 0 && texture.img.address[pixelpos + 1] == 0 && texture.img.address[pixelpos + 2] == 0)
		return (1);
	return (0);
}

int		count_sprites(t_cube *cube)
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

void	ord_sprites(t_cube *cube)
{
	int			tmp;
	int			i;
	int			change;

	change = 1;
	while (change)
	{
		change = 0;
		i = 1;
		while (i < cube->sprite.amount)
		{
			if (is_first_closer(cube->sprite.tab[cube->sprite.order[i - 1]], cube->sprite.tab[cube->sprite.order[i]], cube->cam.pos))
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