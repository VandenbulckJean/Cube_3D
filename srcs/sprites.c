#include "../include/cube.h"

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

int		is_first_closer(t_vecteur s1, t_vecteur s2, t_vecteur pos)
{
	double dist1;
	double dist2;

	dist1 = ((pos.x - s1.x) * (pos.x - s1.x) + (pos.y - s1.y) * (pos.y - s1.y));
	dist2 = ((pos.x - s2.x) * (pos.x - s2.x) + (pos.y - s2.y) * (pos.y - s2.y));
	if (dist1 < dist2)
		return (1);
	return (0);
}

void	set_sprites_value(t_cube *cube, t_vecteur sprite)
{
	cube->sprite.campos.x = sprite.x - cube->cam.pos.x;
	cube->sprite.campos.y = sprite.y - cube->cam.pos.y;
	cube->sprite.invdet = 1.0 / (cube->cam.plane.x * cube->cam.direction.y - cube->cam.direction.x * cube->cam.plane.y);
	cube->sprite.transform.x = cube->sprite.invdet * (cube->cam.direction.y * cube->sprite.campos.x - cube->cam.direction.x * cube->sprite.campos.y);
	cube->sprite.transform.y = cube->sprite.invdet * (-cube->cam.plane.y * cube->sprite.campos.x + cube->cam.plane.x * cube->sprite.campos.y);
	cube->sprite.centerstripe = (int)((cube->wind.x_res / 2) * (1 + cube->sprite.transform.x / cube->sprite.transform.y));
	cube->sprite.height = abs((int)(cube->wind.y_res / cube->sprite.transform.y));
	cube->sprite.starty = -cube->sprite.height / 2 + cube->wind.y_res / 2;
	if (cube->sprite.starty < 0)
		cube->sprite.starty = 0;
	cube->sprite.endy = cube->sprite.height / 2 + cube->wind.y_res / 2;
	if (cube->sprite.endy >= cube->wind.y_res)
		cube->sprite.endy = cube->wind.y_res - 1;
	cube->sprite.width = abs((int)(cube->wind.y_res / cube->sprite.transform.y));
	cube->sprite.startx = -cube->sprite.width / 2 + cube->sprite.centerstripe;
	if (cube->sprite.startx < 0)
		cube->sprite.startx = 0;
	cube->sprite.endx = cube->sprite.width / 2 + cube->sprite.centerstripe;
	if (cube->sprite.endx >=  cube->wind.x_res)
		cube->sprite.endx = cube->wind.x_res - 1;
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

void	initialise_sprites(t_cube *cube)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	cube->sprite.amount = count_sprites(cube);
	if (!(cube->sprite.tab = malloc(sizeof(t_sprite) * cube->sprite.amount)))
		handle_error("can't malloc sprites", cube);
	if (!(cube->sprite.order = malloc(sizeof(int) * cube->sprite.amount)))
		handle_error("can't malloc sprites order", cube);
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

int		is_pixel_black(t_texture texture)
{
	int pixelpos;

	pixelpos = texture.hitx * texture.img.bpp / 8 + texture.img.size_line * (int)texture.hity;
	if (texture.img.address[pixelpos] == 0 && texture.img.address[pixelpos + 1] == 0 && texture.img.address[pixelpos + 2] == 0)
		return (1);
	return (0);
}

void	sprite_draw(t_cube *cube)
{
	int	y;
	int pixelpos;
	int d;

	cube->sprite.stripe = cube->sprite.startx;
	while (cube->sprite.stripe < cube->sprite.endx)
	{
		if (cube->sprite.transform.y > 0 && cube->sprite.stripe > 0 && cube->sprite.stripe < cube->wind.x_res && cube->sprite.transform.y < cube->cam.distbuffer[cube->sprite.stripe])
		{
			cube->sprite.texture.hitx = (int)(256 * (cube->sprite.stripe - (-cube->sprite.width / 2 + cube->sprite.centerstripe)) * cube->sprite.texture.width / cube->sprite.width) / 256;
			y = cube->sprite.starty;
			while(y < cube->sprite.endy)
			{
				d = (y) * 256 - cube->wind.y_res * 128 + cube->sprite.height * 128;
				cube->sprite.texture.hity = ((d * cube->sprite.texture.height) / cube->sprite.height) / 256;
				pixelpos = cube->sprite.stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * y;
				if (!(is_pixel_black(cube->sprite.texture)))
					set_samepixelcolor(cube, pixelpos, &cube->sprite.texture);
				y++;
			}
		}
		cube->sprite.stripe++;
	}
}

void	do_sprites(t_cube *cube)
{
	int i;

	i = 0;
	ord_sprites(cube);
	while (i < cube->sprite.amount)
	{
		set_sprites_value(cube, cube->sprite.tab[cube->sprite.order[i]]);
		sprite_draw(cube);
		i++;
	}
}