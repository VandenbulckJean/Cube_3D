#include "../include/cube.h"

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
	cube->sprite.stripe = cube->sprite.startx;
}

void	sprite_drawing_bis(t_cube *cube)
{
	int y;
	int pixelpos;

	cube->sprite.texture.hitx = (int)(256 * (cube->sprite.stripe - (-cube->sprite.width /
	2 + cube->sprite.centerstripe)) * cube->sprite.texture.width / cube->sprite.width) / 256;
	y = cube->sprite.starty;
	while(y < cube->sprite.endy)
	{
		cube->sprite.texture.hity = ((((y) * 256 - cube->wind.y_res * 128 +
		cube->sprite.height * 128) * cube->sprite.texture.height)
		/ cube->sprite.height) / 256;
		pixelpos = cube->sprite.stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * y;
		if (!(is_pixel_black(cube->sprite.texture)))
			set_samepixelcolor(cube, pixelpos, &cube->sprite.texture);
		y++;
	}
}

void	sprite_draw(t_cube *cube)
{
	while (cube->sprite.stripe < cube->sprite.endx)
	{
		if (cube->sprite.transform.y > 0 && cube->sprite.stripe> 0
		&& cube->sprite.stripe < cube->wind.x_res &&
		cube->sprite.transform.y < cube->cam.distbuffer[cube->sprite.stripe])
			sprite_drawing_bis(cube);
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
