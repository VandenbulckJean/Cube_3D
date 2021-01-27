/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:30:47 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/27 16:30:48 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int			getcolorvalue(char *str,
t_color *color, char *colorname, t_cube *cube)
{
	int i;

	i = 1;
	if (check_if_number(str, i))
		handle_missing_color("red, green and blue", colorname, cube);
	atoi_cube(str, &i, &color->r);
	if (str[i] == ',')
		i++;
	if (check_if_number(str, i))
		handle_missing_color("green and blue", colorname, cube);
	atoi_cube(str, &i, &color->g);
	if (str[i] == ',')
		i++;
	if (check_if_number(str, i))
		handle_missing_color("blue", colorname, cube);
	atoi_cube(str, &i, &color->b);
	return (i);
}

void		get_color_floor(char *str, t_cube *cube)
{
	int i;

	i = 1;
	cube->floor.line = 1;
	while (str[i] && !(isnumber(str[i])) && str[i] != '-')
	{
		if (!(is_space(str[i++])))
			handle_error_parsing(
			"Floor line must only contain red, green and blue values", cube);
	}
	i = getcolorvalue(str, &cube->floor, "floor", cube);
	while (str[i])
		if (!(is_space(str[i++])))
			handle_error_parsing(
			"Floor line must only contain red, green and blue values", cube);
}

void		get_color_ceiling(char *str, t_cube *cube)
{
	int i;

	i = 1;
	cube->ceiling.line = 1;
	while (str[i] && !(isnumber(str[i])) && str[i] != '-')
	{
		if (!(is_space(str[i++])))
			handle_error_parsing(
			"ceiling line must only contain red , reen and blue values", cube);
	}
	i = getcolorvalue(str, &cube->ceiling, "ceiling", cube);
	while (str[i])
		if (!(is_space(str[i++])))
			handle_error_parsing(
			"Ceiling line must only contain red, green and blue values", cube);
}
