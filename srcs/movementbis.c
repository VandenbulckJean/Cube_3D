/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movementbis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:10:55 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/27 17:10:56 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	rotation_left_pov(t_cube *cube)
{
	double buffdirx;
	double buffplanex;

	buffdirx = cube->cam.direction.x;
	buffplanex = cube->cam.plane.x;
	cube->cam.direction.x = (buffdirx * cos(-Alpha)) -
	(cube->cam.direction.y * sin(-Alpha));
	cube->cam.direction.y = (buffdirx * sin(-Alpha)) +
	(cube->cam.direction.y * cos(-Alpha));
	cube->cam.plane.x = (buffplanex * cos(-Alpha)) -
	(cube->cam.plane.y * sin(-Alpha));
	cube->cam.plane.y = (buffplanex * sin(-Alpha)) +
	(cube->cam.plane.y * cos(-Alpha));
	cube->event.left_arrow_pressed = 0;
	raycasting(cube);
}

void	rotation_right_pov(t_cube *cube)
{
	double buffdirx;
	double buffplanex;

	buffdirx = cube->cam.direction.x;
	buffplanex = cube->cam.plane.x;
	cube->cam.direction.x = (buffdirx * cos(Alpha)) -
	(cube->cam.direction.y * sin(Alpha));
	cube->cam.direction.y = (buffdirx * sin(Alpha)) +
	(cube->cam.direction.y * cos(Alpha));
	cube->cam.plane.x = (buffplanex * cos(Alpha)) -
	(cube->cam.plane.y * sin(Alpha));
	cube->cam.plane.y = (buffplanex * sin(Alpha)) +
	(cube->cam.plane.y * cos(Alpha));
	cube->event.right_arow_pressed = 0;
	raycasting(cube);
}
