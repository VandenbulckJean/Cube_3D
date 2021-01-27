/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:18:47 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/27 17:18:48 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static void		check_file_name(char *argv, char **filename)
{
	int len;

	len = (int)ft_strlen(argv);
	if (len < 5)
		print_error_exit("File name incorrect");
	if (argv[len - 4] != '.' || argv[len - 3] != 'c' ||
	argv[len - 2] != 'u' || argv[len - 1] != 'b')
		print_error_exit("File must have .cub extension");
	if (!(*filename = ft_strdup(argv)))
		print_error_exit("Can't malloc filename");
}

static void		check_second_argument(char *str)
{
	if (!(ft_samestr("--save", str)))
		print_error_exit("Second argument must be --save");
}

void			check_arguments(int argc, char *argv[], char **filename)
{
	if (argc == 1)
		print_error_exit("Enter at least an .cub file as first argument");
	if (argc > 3)
		print_error_exit("Too many arguments");
	if (argc == 3)
		check_second_argument(argv[2]);
	check_file_name(argv[1], filename);
}
