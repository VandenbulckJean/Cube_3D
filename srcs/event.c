#include "cube.h"

int	check_event(t_cube *cube)
{
	if (cube->event.w_pressed)
	{
		if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x + cube->cam.direction.x * Speed)] != '1')
			cube->cam.pos.x += cube->cam.direction.x * Speed;
		if (cube->map.map[(int)(cube->cam.pos.y + cube->cam.direction.y * Speed)][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y += cube->cam.direction.y * Speed;
		cube->event.w_pressed = 0;
	}
	if (cube->event.s_pressed)
	{
		if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x - cube->cam.direction.x * Speed)] != '1')
			cube->cam.pos.x -= cube->cam.direction.x * Speed;
		if (cube->map.map[(int)(cube->cam.pos.y - cube->cam.direction.y * Speed)][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y -= cube->cam.direction.y * Speed;
		cube->event.s_pressed = 0;
	}
	if (cube->event.d_pressed)
	{
		if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x - cube->cam.direction.y * Speed)] != '1')
			cube->cam.pos.x += -cube->cam.direction.y * Speed;
		if (cube->map.map[(int)(cube->cam.pos.y - cube->cam.direction.x * Speed)][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y += cube->cam.direction.x * Speed;
		cube->event.d_pressed = 0;
	}
	if (cube->event.a_pressed)
	{
		if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x + cube->cam.direction.y * Speed)] != '1')
			cube->cam.pos.x += cube->cam.direction.y * Speed;
		if (cube->map.map[(int)(cube->cam.pos.y + cube->cam.direction.x * Speed)][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y += -cube->cam.direction.x * Speed;
		cube->event.a_pressed = 0;
	}
	if (cube->event.right_arow_pressed)
		rotation_pov(cube, 0);
	if (cube->event.left_arrow_pressed)
		rotation_pov(cube, 1);
	if (cube->wind.ptr)
		mlx_clear_window(cube->ptr, cube->wind.ptr);
	raycasting(cube);
	return (1);
}

int	do_on_press_event(int pressed_key, t_cube *cube)
{
	if (pressed_key == 13)
		cube->event.w_pressed = 1;
	if (pressed_key == 1)
		cube->event.s_pressed = 1;
	if (pressed_key == 2)
		cube->event.d_pressed = 1;
	if (pressed_key == 0)
		cube->event.a_pressed = 1;
	if (pressed_key == 124)
		cube->event.right_arow_pressed = 1;
	if (pressed_key == 123)
		cube->event.left_arrow_pressed = 1;
	return (1);
}

int	do_on_cross_release_event(t_cube *cube)
{
	handle_exit(cube);
	return (1);
}

int do_on_release_event(int pressed_key, t_cube *cube)
{
	if (pressed_key == 53 || pressed_key == 17)
		handle_exit(cube);
	return (1);
}

void	event_loop(t_cube *cube)
{
	mlx_hook(cube->wind.ptr, 2, 0, do_on_press_event, cube);
	mlx_hook(cube->wind.ptr, 3, 0, do_on_release_event, cube);
	mlx_hook(cube->wind.ptr, 17, 0, do_on_cross_release_event, cube);
	mlx_loop_hook(cube->ptr, check_event, cube);
	mlx_loop(cube->ptr);
}