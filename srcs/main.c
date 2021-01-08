#include "cube.h"


void	set_pixel_color(t_cube *cube, int pixelpos, t_color color)
{
	cube->next_img.address[pixelpos] = color.b;
	cube->next_img.address[pixelpos + 1] = color.g;
	cube->next_img.address[pixelpos + 2] = color.r;
}

void	draw_stripe(t_cube *cube)
{
	int i;
	int j;
	t_color red;
	int pixelpos;

	i = 0;
	j = cube->cam.p_stripe;
	red.r = 200;
	red.g = 0;
	red.b = 0;
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
			set_pixel_color(cube, pixelpos, red);
		else if (cube->cam.side == 1 && cube->cam.raydir.y < 0)
			set_pixel_color(cube, pixelpos, red);
		else if (cube->cam.side == 1 && cube->cam.raydir.y > 0)
			set_pixel_color(cube, pixelpos, red);
		i++;
	}
	while (i < cube->wind.y_res)
	{
		pixelpos = cube->cam.p_stripe * cube->next_img.bpp / 8 + cube->next_img.size_line * i;
		set_pixel_color(cube, pixelpos, cube->floor);
		i++;
	}
}

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

void	get_hit_distance(t_cube *cube)
{
	if (cube->cam.side == 0)
	{
		cube->cam.walldist = (cube->map.pos.x - cube->cam.pos.x +
						(1 - (int)cube->cam.step.x) / 2) / cube->cam.raydir.x;
	}
	else
	{
		cube->cam.walldist = (cube->map.pos.y - cube->cam.pos.y +
							(1 - cube->cam.step.y) / 2) / cube->cam.raydir.y;
	}
}

void	get_hit_pos(t_cube *cube)
{
	//int i = 0;
	while (cube->cam.hit == 0)
	{
		if (cube->cam.sidedist.x < cube->cam.sidedist.y)
		{
			cube->cam.sidedist.x += cube->cam.deltadist.x;
			cube->map.pos.x += cube->cam.step.x;
			cube->cam.side = 0;
		}
		else
		{
			cube->cam.sidedist.y += cube->cam.deltadist.y;
			cube->map.pos.y += cube->cam.step.y;
			cube->cam.side = 1;
		}
			//printf("sidedist : x : %f %f y : %f %f %d\n", cube->cam.sidedist.x, cube->cam.deltadist.x, cube->cam.sidedist.y, cube->cam.deltadist.y, cube->cam.p_stripe);
		if (cube->map.map[(int)cube->map.pos.y][(int)cube->map.pos.x] != '0')
			cube->cam.hit = 1;
	}
	/*cube->map.map[(int)cube->map.pos.y][(int)cube->map.pos.x] = 'F';
	while (i < cube->map.line)
	{
		printf("%s\n", cube->map.map[i]);
		i++;
	}*/
}

void	get_cam_values(t_cube *cube)
{
	cube->cam.hit = 0;
	cube->cam.camx = 2 * cube->cam.p_stripe / (double)cube->wind.x_res - 1;
	cube->cam.raydir.x = cube->cam.direction.x + cube->cam.plane.x * cube->cam.camx;
	cube->cam.raydir.y = cube->cam.direction.y + cube->cam.plane.y * cube->cam.camx;
	cube->map.pos.x = (int)cube->cam.pos.x;
	cube->map.pos.y = (int)cube->cam.pos.y;
	cube->cam.deltadist.x = fabs(1 / cube->cam.raydir.x);
	cube->cam.deltadist.y = fabs(1 / cube->cam.raydir.y);
}

void	get_side_dist(t_cube *cube)
{
	if (cube->cam.raydir.x < 0)
	{
		cube->cam.step.x = -1;
		cube->cam.sidedist.x = (cube->cam.pos.x - cube->map.pos.x) * cube->cam.deltadist.x;
	}
	else
	{
		cube->cam.step.x = 1;
		cube->cam.sidedist.x = (cube->map.pos.x + 1.0 - cube->cam.pos.x) * cube->cam.deltadist.x;
	}
	if (cube->cam.raydir.y < 0)
	{
		cube->cam.step.y = -1;
		cube->cam.sidedist.y = (cube->cam.pos.y - cube->map.pos.y) * cube->cam.deltadist.y;
	}
	else
	{
		cube->cam.step.y = 1;
		cube->cam.sidedist.y = (cube->map.pos.y + 1.0 - cube->cam.pos.y) * cube->cam.deltadist.y;
	}
}

void	raycasting(t_cube *cube)
{
	cube->cam.p_stripe = 0;
	while (cube->cam.p_stripe < cube->wind.x_res)
	{
		get_cam_values(cube);
		get_side_dist(cube);
		get_hit_pos(cube);
		get_hit_distance(cube);
		get_object_limits(cube);
		draw_stripe(cube);
		cube->cam.p_stripe++;
	}
}

void	createnextimg(t_cube *cube)
{
	cube->next_img.ptr = mlx_new_image(cube->ptr, cube->wind.x_res, cube->wind.y_res);
	cube->next_img.address = (unsigned char*)mlx_get_data_addr(cube->next_img.ptr, &cube->next_img.bpp, &cube->next_img.size_line, &cube->next_img.endian);
	raycasting(cube);
}

int	do_on_event(int pressed_key, t_cube *cube)
{
	printf("%d\n", pressed_key);
	(void)cube;
	return (1);
}

void	event_loop(t_cube *cube)
{
	mlx_key_hook(cube->wind.ptr, do_on_event, cube);
	mlx_loop(cube->ptr);
}
void	createwindow(t_cube *cube)
{
	if (!(cube->wind.ptr = mlx_new_window(cube->ptr, cube->wind.x_res, cube->wind.y_res, "Cube 3D")))
		handle_error("fail to build window", cube);
	createnextimg(cube);
	mlx_put_image_to_window(cube->ptr, cube->wind.ptr, cube->next_img.ptr, 0, 0);
}

int main(int argc, char *argv[])
{
	t_cube	cube;

	cube.fov = 180;
	check_arguments(argc, argv, &cube);
	cube.filename = ft_strdup(argv[1]);
	if (!(cube.ptr = mlx_init()))
		handle_error("fail to initialize mlx.", &cube);
	parsing_file(&cube);
	createwindow(&cube);
	event_loop(&cube);
	return (0);
}
