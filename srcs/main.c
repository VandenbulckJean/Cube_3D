/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:40:26 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/27 16:40:27 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static void		parsing_file(t_cube *cube)
{
	init_values_parsing(cube);
	parsing_env_data(cube);
	check_env_data(cube);
	parsing_map(cube);
	if (!(check_map(cube->map.map)))
		handle_error_parsing("Map is not correct", cube);
}

int				main(int argc, char *argv[])
{
	t_cube	cube;

	ft_bzero(&cube, sizeof(t_cube));
	check_arguments(argc, argv, &cube.filename);
	if (!(cube.ptr = mlx_init()))
		print_error_exit("fail to initialize mlx.");
	parsing_file(&cube);
	initialisation(&cube);
	if (argc == 3)
		make_bmp(&cube);
	event_loop(&cube);
}
