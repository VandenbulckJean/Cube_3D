#include "../include/cube.h"

void	move_forward(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x + cube->cam.direction.x * Speed + (cube->cam.direction.x > 0 ? Glitchdist  : -Glitchdist))] != '1')
			cube->cam.pos.x += cube->cam.direction.x * Speed;
	if (cube->map.map[(int)(cube->cam.pos.y + cube->cam.direction.y * Speed + (cube->cam.direction.y > 0 ? Glitchdist : -Glitchdist))][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y += cube->cam.direction.y * Speed;
	refreshscreen(cube);
	cube->event.w_pressed = 0;
}

void	move_backward(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x - cube->cam.direction.x * Speed - (cube->cam.direction.x > 0 ? Glitchdist  : -Glitchdist))] != '1')
			cube->cam.pos.x -= cube->cam.direction.x * Speed;
	if (cube->map.map[(int)(cube->cam.pos.y - cube->cam.direction.y * Speed - (cube->cam.direction.y > 0 ? Glitchdist : -Glitchdist))][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y -= cube->cam.direction.y * Speed;
	cube->event.s_pressed = 0;
	refreshscreen(cube);
}

void	starfleft(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x + cube->cam.direction.y * Speed + (cube->cam.direction.x > 0 ? Glitchdist  : -Glitchdist))] != '1')
			cube->cam.pos.x += cube->cam.direction.y * Speed;
	if (cube->map.map[(int)(cube->cam.pos.y + cube->cam.direction.x * Speed + (cube->cam.direction.y > 0 ? Glitchdist : -Glitchdist))][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y += -cube->cam.direction.x * Speed;
	cube->event.a_pressed = 0;
	refreshscreen(cube);
}

void	strafright(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x - cube->cam.direction.y * Speed - (cube->cam.direction.x > 0 ? Glitchdist  : -Glitchdist))] != '1')
			cube->cam.pos.x += -cube->cam.direction.y * Speed;
	if (cube->map.map[(int)(cube->cam.pos.y - cube->cam.direction.x * Speed - (cube->cam.direction.y > 0 ? Glitchdist : -Glitchdist))][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y += cube->cam.direction.x * Speed;
	cube->event.d_pressed = 0;
	refreshscreen(cube);
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
	refreshscreen(cube);
}