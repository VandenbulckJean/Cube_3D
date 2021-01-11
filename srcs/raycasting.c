#include "cube.h"

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

void	get_hit_pos(t_cube *cube)
{
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
		if (cube->map.map[(int)cube->map.pos.y][(int)cube->map.pos.x] == '1')
			cube->cam.hit = 1;
	}
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
	mlx_put_image_to_window(cube->ptr, cube->wind.ptr, cube->next_img.ptr, 0, 0);
}