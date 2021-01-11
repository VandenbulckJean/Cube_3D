#include "cube.h"

void	get_object_limits(t_cube *cube)
{
	cube->cam.objectheight = (int)((double)cube->wind.y_res / cube->cam.walldist);
	cube->cam.objectstart = -cube->cam.objectheight / 2 + cube->wind.y_res / 2;
	if (cube->cam.objectstart < 0)
		cube->cam.objectstart = 0;
	cube->cam.objectend = cube->cam.objectheight / 2 + cube->wind.y_res / 2;
	if (cube->cam.objectend >= cube->wind.y_res)
		cube->cam.objectend = cube->wind.y_res - 1;
	/*if (pos->side == 0)
		pos->wallx = pos->posy + cube->cam.walldist * pos->raydiry;
	else
		pos->wallx = pos->posx + cube->cam.walldist * pos->raydirx;
	pos->wallx -= floor((pos->wallx));
	pos->tex_x = (int)(pos->wallx * pos->txt->width[0]);
	if (pos->side == 0 && pos->raydirx > 0)
		pos->tex_x = pos->txt->width[0] - pos->tex_x - 1;
	if (pos->side == 1 && pos->raydiry < 0)
		pos->tex_x = pos->txt->width[0] - pos->tex_x - 1;
	pos->step = 1.0 * (double)pos->txt->height[0] / (double)cube->cam.objectheight;*/
}

void	draw_stripe(t_cube *cube)
{
	int i;
	int j;
	t_color red;
	t_color blue;
	int pixelpos;

	i = 0;
	j = cube->cam.p_stripe;
	red.r = 200;
	red.g = 0;
	red.b = 0;
	blue.r = 0;
	blue.g = 0;
	blue.b = 200;
	while (i < cube->cam.objectstart)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		set_pixel_color(cube, pixelpos, cube->ceiling);
		i++;
	}
	while (i < cube->cam.objectend)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		if (cube->cam.side == 0 && cube->cam.raydir.x < 0)
			set_pixel_color(cube, pixelpos, red);
		else if (cube->cam.side == 0 && cube->cam.raydir.x > 0)
			set_pixel_color(cube, pixelpos, blue);
		else if (cube->cam.side == 1 && cube->cam.raydir.y < 0)
			set_pixel_color(cube, pixelpos, red);
		else if (cube->cam.side == 1 && cube->cam.raydir.y > 0)
			set_pixel_color(cube, pixelpos, blue);
		i++;
	}
	while (i < cube->wind.y_res)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		set_pixel_color(cube, pixelpos, cube->floor);
		i++;
	}
}

void	rotation_pov(t_cube *cube, int is_left)
{
	double buffdirx;
	double buffplanex;

	buffdirx = cube->cam.direction.x;
	buffplanex = cube->cam.plane.x;
	if (is_left)
	{
		cube->cam.direction.x = (buffdirx * cos(-Alpha)) - (cube->cam.direction.y * sin(-Alpha));
		cube->cam.direction.y = (buffdirx * sin(-Alpha)) + (cube->cam.direction.y * cos(-Alpha));
		cube->cam.plane.x = (buffplanex * cos(-Alpha)) - (cube->cam.plane.y * sin(-Alpha));
		cube->cam.plane.y = (buffplanex * sin(-Alpha)) + (cube->cam.plane.y * cos(-Alpha));
		cube->event.left_arrow_pressed = 0;
	}
	else
	{
		cube->cam.direction.x = (buffdirx * cos(Alpha)) - (cube->cam.direction.y * sin(Alpha));
		cube->cam.direction.y = (buffdirx * sin(Alpha)) + (cube->cam.direction.y * cos(Alpha));
		cube->cam.plane.x = (buffplanex * cos(Alpha)) - (cube->cam.plane.y * sin(Alpha));
		cube->cam.plane.y = (buffplanex * sin(Alpha)) + (cube->cam.plane.y * cos(Alpha));
		cube->event.right_arow_pressed = 0;
	}
}