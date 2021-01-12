#include "../include/cube.h"

void	get_object_limits(t_cube *cube)
{
	cube->cam.objectheight = (int)((double)cube->wind.y_res / cube->cam.walldist);
	cube->cam.objectstart = -cube->cam.objectheight / 2 + cube->wind.y_res / 2;
	if (cube->cam.objectstart < 0)
		cube->cam.objectstart = 0;
	cube->cam.objectend = cube->cam.objectheight / 2 + cube->wind.y_res / 2;
	if (cube->cam.objectend >= cube->wind.y_res)
		cube->cam.objectend = cube->wind.y_res - 1;
}

void	get_texture_hit_x(t_cube *cube)
{
	if (cube->cam.side == 0 && cube->cam.raydir.x < 0)
	{
		cube->west.hitx = (int)(cube->cam.wallhitx * (double)cube->west.width);
		cube->west.hitx = cube->west.width - cube->west.hitx - 1;
		cube->west.step = 1.0 * (double)cube->west.height / cube->cam.objectheight;
		cube->west.hity = (cube->cam.objectstart - cube->wind.y_res / 2 + cube->cam.objectheight / 2) * cube->west.step;
	}
	else if (cube->cam.side == 0 && cube->cam.raydir.x > 0)
	{
		cube->east.hitx = (int)(cube->cam.wallhitx * (double)cube->east.width);
		cube->east.hitx = cube->east.width - cube->east.hitx - 1;
		cube->east.step = 1.0 * cube->east.height / cube->cam.objectheight;
		cube->east.hity = (cube->cam.objectstart - cube->wind.y_res / 2 + cube->cam.objectheight / 2) * cube->east.step;
	}
	else if (cube->cam.side == 1 && cube->cam.raydir.y < 0)
	{
		cube->north.hitx = (int)(cube->cam.wallhitx * (double)cube->north.width);
		cube->north.hitx = cube->north.width - cube->north.hitx - 1;
		cube->north.step = 1.0 * cube->north.height / cube->cam.objectheight;
		cube->north.hity = (cube->cam.objectstart - cube->wind.y_res / 2 + cube->cam.objectheight / 2) * cube->north.step;

	}
	else if (cube->cam.side == 1 && cube->cam.raydir.y > 0)
	{
		cube->south.hitx = (int)(cube->cam.wallhitx * (double)cube->south.width);
		cube->south.hitx = cube->south.width - cube->south.hitx - 1;
		cube->south.step = 1.0 * cube->south.height / cube->cam.objectheight;
		cube->south.hity = (cube->cam.objectstart - cube->wind.y_res / 2 + cube->cam.objectheight / 2) * cube->south.step;

	}
}

void	get_wall_hit_x(t_cube *cube)
{
	if (cube->cam.side == 0)
		cube->cam.wallhitx = cube->cam.pos.y + cube->cam.walldist * cube->cam.raydir.y;
	else
		cube->cam.wallhitx = cube->cam.pos.x + cube->cam.walldist * cube->cam.raydir.x;
	cube->cam.wallhitx -= floor(cube->cam.wallhitx);
	get_texture_hit_x(cube);
}

void	set_samepixelcolor(t_cube *cube, int pixelposto, t_texture *texture)
{
	int pixelpos_texture;
	texture->hity += texture->step;
	pixelpos_texture = texture->hitx * texture->img.bpp / 8 + texture->img.size_line * (int)texture->hity;
	cube->next_img.address[pixelposto] = texture->img.address[pixelpos_texture];
	cube->next_img.address[pixelposto + 1] = texture->img.address[pixelpos_texture + 1];
	cube->next_img.address[pixelposto + 2] = texture->img.address[pixelpos_texture + 2];
}

void	draw_stripe(t_cube *cube)
{
	int i;
	int pixelpos;

	i = 0;
	while (i < cube->cam.objectstart)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		set_pixel_color(cube, pixelpos, cube->ceiling);
		i++;
	}
	get_wall_hit_x(cube);
	while (i < cube->cam.objectend)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		if (cube->cam.side == 0 && cube->cam.raydir.x < 0)
		{
			set_samepixelcolor(cube, pixelpos, &cube->west);
		}
		else if (cube->cam.side == 0 && cube->cam.raydir.x > 0)
		{
			set_samepixelcolor(cube, pixelpos, &cube->east);
		}
		else if (cube->cam.side == 1 && cube->cam.raydir.y < 0)
		{
			set_samepixelcolor(cube, pixelpos, &cube->north);
		}
		else if (cube->cam.side == 1 && cube->cam.raydir.y > 0)
		{
			set_samepixelcolor(cube, pixelpos, &cube->south);
		}
		i++;
	}
	while (i < cube->wind.y_res)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		set_pixel_color(cube, pixelpos, cube->floor);
		i++;
	}
}