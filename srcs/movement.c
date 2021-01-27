#include "../include/cube.h"

void	move_forward(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x + cube->cam.direction.x * Speed + (cube->cam.direction.x > 0 ? Glitchdist  : -Glitchdist))] != '1')
			cube->cam.pos.x += cube->cam.direction.x * Speed;
	if (cube->map.map[(int)(cube->cam.pos.y + cube->cam.direction.y * Speed + (cube->cam.direction.y > 0 ? Glitchdist : -Glitchdist))][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y += cube->cam.direction.y * Speed;
	raycasting(cube);
	cube->event.w_pressed = 0;
}

void	move_backward(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x - cube->cam.direction.x * Speed - (cube->cam.direction.x > 0 ? Glitchdist  : -Glitchdist))] != '1')
			cube->cam.pos.x -= cube->cam.direction.x * Speed;
	if (cube->map.map[(int)(cube->cam.pos.y - cube->cam.direction.y * Speed - (cube->cam.direction.y > 0 ? Glitchdist : -Glitchdist))][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y -= cube->cam.direction.y * Speed;
	cube->event.s_pressed = 0;
	raycasting(cube);
}

void	strafleft(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x + cube->cam.direction.y * Speed + (cube->cam.direction.y > 0 ? Glitchdist  : -Glitchdist))] != '1')
			cube->cam.pos.x += cube->cam.direction.y * Speed;
	if (cube->map.map[(int)(cube->cam.pos.y - cube->cam.direction.x * Speed - (cube->cam.direction.x > 0 ? Glitchdist : -Glitchdist))][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y -= cube->cam.direction.x * Speed;
	cube->event.a_pressed = 0;
	raycasting(cube);
}

void	strafright(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x - cube->cam.direction.y * Speed - (cube->cam.direction.y > 0 ? Glitchdist  : -Glitchdist))] != '1')
			cube->cam.pos.x -= cube->cam.direction.y * Speed;
	if (cube->map.map[(int)(cube->cam.pos.y + cube->cam.direction.x * Speed + (cube->cam.direction.x > 0 ? Glitchdist : -Glitchdist))][(int)cube->cam.pos.x] != '1')
			cube->cam.pos.y += cube->cam.direction.x * Speed;
	cube->event.d_pressed = 0;
	raycasting(cube);
}
