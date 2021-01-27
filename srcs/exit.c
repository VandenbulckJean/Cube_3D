/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:57:08 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/27 16:57:09 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	print_error_exit(char *error)
{
	ft_printf("Error\n%s.", error);
	exit(EXIT_FAILURE);
}

void	handle_error_parsing(char * error, t_cube *cube)
{
	free_parsing(cube);
	print_error_exit(error);
}

void	handle_missing_color(char *missingcolors, char *colorname, t_cube *cube)
{
	free_parsing(cube);
	ft_printf("Error\nMissing %s values in %s line.", missingcolors, colorname);
	exit(EXIT_FAILURE);
}

void	handle_error(char *string, t_cube *cube)
{
	free_parsing(cube);
	free_motor_variables(cube);
	destroy_images(cube);
	print_error_exit(string);
}

void	handle_exit(t_cube *cube)
{
	free_parsing(cube);
	free_motor_variables(cube);
	destroy_images(cube);
	exit(EXIT_SUCCESS);
}