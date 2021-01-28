/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movementbis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:10:55 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/28 13:36:35 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	rotation_left_pov(t_cube *cube)
{
	double buffdirx;
	double buffplanex;

	buffdirx = cube->cam.direction.x;
	buffplanex = cube->cam.plane.x;
	cube->cam.direction.x = (buffdirx * cos(-ALPHA)) -
	(cube->cam.direction.y * sin(-ALPHA));
	cube->cam.direction.y = (buffdirx * sin(-ALPHA)) +
	(cube->cam.direction.y * cos(-ALPHA));
	cube->cam.plane.x = (buffplanex * cos(-ALPHA)) -
	(cube->cam.plane.y * sin(-ALPHA));
	cube->cam.plane.y = (buffplanex * sin(-ALPHA)) +
	(cube->cam.plane.y * cos(-ALPHA));
	cube->event.left_arrow_pressed = 0;
	raycasting(cube);
}

void	rotation_right_pov(t_cube *cube)
{
	double buffdirx;
	double buffplanex;

	buffdirx = cube->cam.direction.x;
	buffplanex = cube->cam.plane.x;
	cube->cam.direction.x = (buffdirx * cos(ALPHA)) -
	(cube->cam.direction.y * sin(ALPHA));
	cube->cam.direction.y = (buffdirx * sin(ALPHA)) +
	(cube->cam.direction.y * cos(ALPHA));
	cube->cam.plane.x = (buffplanex * cos(ALPHA)) -
	(cube->cam.plane.y * sin(ALPHA));
	cube->cam.plane.y = (buffplanex * sin(ALPHA)) +
	(cube->cam.plane.y * cos(ALPHA));
	cube->event.right_arow_pressed = 0;
	raycasting(cube);
}
