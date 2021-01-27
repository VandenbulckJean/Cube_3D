/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:30:15 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/27 16:30:16 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int		check_event(t_cube *cube)
{
	if (cube->event.right_arow_pressed && cube->event.w_pressed)
	{
		printf("coucou\n");
	}
	if (cube->event.w_pressed)
		move_forward(cube);
	if (cube->event.s_pressed)
		move_backward(cube);
	if (cube->event.d_pressed)
		strafright(cube);
	if (cube->event.a_pressed)
		strafleft(cube);
	if (cube->event.right_arow_pressed)
		rotation_right_pov(cube);
	if (cube->event.left_arrow_pressed)
		rotation_left_pov(cube);
	return (1);
}

int		do_on_press_event(int pressed_key, t_cube *cube)
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

int		do_on_cross_release_event(t_cube *cube)
{
	handle_exit(cube);
	return (1);
}

int		do_on_release_event(int pressed_key, t_cube *cube)
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
