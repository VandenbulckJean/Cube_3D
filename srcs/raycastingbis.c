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