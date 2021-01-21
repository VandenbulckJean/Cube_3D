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

void	get_texture_hit_data(t_cube *cube, t_texture *texture)
{
	texture->hitx = (int)(cube->cam.wallhitx * (double)texture->width);
	texture->hitx = texture->width - texture->hitx- 1;
	texture->step = 1.0 * (double)texture->height / cube->cam.objectheight;
	texture->hity = (cube->cam.objectstart - cube->wind.y_res / 2 + cube->cam.objectheight / 2) * texture->step;
}

void	get_textures_hit_data(t_cube *cube)
{
	if (cube->cam.side == 0 && cube->cam.raydir.x < 0)
	{
		get_texture_hit_data(cube, &cube->west);
	}
	else if (cube->cam.side == 0 && cube->cam.raydir.x > 0)
	{
		get_texture_hit_data(cube, &cube->east);
	}
	else if (cube->cam.side == 1 && cube->cam.raydir.y < 0)
	{
		get_texture_hit_data(cube, &cube->north);
	}
	else if (cube->cam.side == 1 && cube->cam.raydir.y > 0)
	{
		get_texture_hit_data(cube, &cube->south);
	}
}

void	get_wall_hit_x(t_cube *cube)
{
	if (cube->cam.side == 0)
		cube->cam.wallhitx = cube->cam.pos.y + cube->cam.walldist * cube->cam.raydir.y;
	else
		cube->cam.wallhitx = cube->cam.pos.x + cube->cam.walldist * cube->cam.raydir.x;
	cube->cam.wallhitx -= floor(cube->cam.wallhitx);
	get_textures_hit_data(cube);
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
	draw_wall_texture(cube);
	i = cube->cam.objectend;
	while (i < cube->wind.y_res)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		set_pixel_color(cube, pixelpos, cube->floor);
		i++;
	}
}