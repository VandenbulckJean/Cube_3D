/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:28:45 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/28 13:36:19 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	move_forward(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x +
	cube->cam.direction.x * SPEED + (cube->cam.direction.x
	> 0 ? GLITCHDIST : -GLITCHDIST))] != '1')
		cube->cam.pos.x += cube->cam.direction.x * SPEED;
	if (cube->map.map[(int)(cube->cam.pos.y + cube->cam.direction.y *
	SPEED + (cube->cam.direction.y > 0 ? GLITCHDIST :
	-GLITCHDIST))][(int)cube->cam.pos.x] != '1')
		cube->cam.pos.y += cube->cam.direction.y * SPEED;
	cube->event.w_pressed = 0;
	raycasting(cube);
}

void	move_backward(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x -
	cube->cam.direction.x * SPEED - (cube->cam.direction.x
	> 0 ? GLITCHDIST : -GLITCHDIST))] != '1')
		cube->cam.pos.x -= cube->cam.direction.x * SPEED;
	if (cube->map.map[(int)(cube->cam.pos.y - cube->cam.direction.y *
	SPEED - (cube->cam.direction.y > 0 ? GLITCHDIST :
	-GLITCHDIST))][(int)cube->cam.pos.x] != '1')
		cube->cam.pos.y -= cube->cam.direction.y * SPEED;
	cube->event.s_pressed = 0;
	raycasting(cube);
}

void	strafleft(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x +
	cube->cam.direction.y * SPEED + (cube->cam.direction.y >
	0 ? GLITCHDIST : -GLITCHDIST))] != '1')
		cube->cam.pos.x += cube->cam.direction.y * SPEED;
	if (cube->map.map[(int)(cube->cam.pos.y - cube->cam.direction.x *
	SPEED - (cube->cam.direction.x > 0 ? GLITCHDIST :
	-GLITCHDIST))][(int)cube->cam.pos.x] != '1')
		cube->cam.pos.y -= cube->cam.direction.x * SPEED;
	cube->event.a_pressed = 0;
	raycasting(cube);
}

void	strafright(t_cube *cube)
{
	if (cube->map.map[(int)cube->cam.pos.y][(int)(cube->cam.pos.x -
	cube->cam.direction.y * SPEED - (cube->cam.direction.y
	> 0 ? GLITCHDIST : -GLITCHDIST))] != '1')
		cube->cam.pos.x -= cube->cam.direction.y * SPEED;
	if (cube->map.map[(int)(cube->cam.pos.y + cube->cam.direction.x *
	SPEED + (cube->cam.direction.x > 0 ? GLITCHDIST :
	-GLITCHDIST))][(int)cube->cam.pos.x] != '1')
		cube->cam.pos.y += cube->cam.direction.x * SPEED;
	cube->event.d_pressed = 0;
	raycasting(cube);
}
