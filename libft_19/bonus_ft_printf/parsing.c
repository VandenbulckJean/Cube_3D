/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:27 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:24:09 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

static void	get_precision(t_fnc_data *data, int *start, int *range, char *entry)
{
	data->precision = 1;
	(*start)++;
	(*range)--;
	if (entry[*start] == '*')
	{
		data->amount_precision = va_arg(data->saved_variables, int);
		(*start)++;
		(*range)--;
	}
	else
	{
		while (isnumber(entry[*start]) && *range)
		{
			data->amount_precision = (data->amount_precision * 10)
			+ entry[*start] - '0';
			(*start)++;
			(*range)--;
		}
	}
	if (data->amount_precision < 0)
		data->precision = 0;
}

static void	get_width(t_fnc_data *data, int *start, int *range, char *entry)
{
	while (isnumber(entry[*start]) && *range)
	{
		data->width = (data->width * 10) + entry[*start] - '0';
		(*start)++;
		(*range)--;
	}
}

static void	get_width_star(t_fnc_data *data,
	int *start, int *range)
{
	int star_value;

	star_value = va_arg(data->saved_variables, int);
	if (star_value < 0)
	{
		data->minus = 1;
		star_value = -star_value;
	}
	data->width = star_value;
	(*start)++;
	(*range)--;
}

static int	resolve(t_fnc_data *data)
{
	if (data->conversion == 'c')
		return (processing_c(data));
	if (data->conversion == 's')
		return (processing_s(data));
	if (data->conversion == 'p')
		return (processing_p(data));
	if (data->conversion == 'd' || data->conversion == 'i')
		return (processing_d(data));
	if (data->conversion == 'u')
		return (processing_u(data));
	if (data->conversion == 'x')
		return (processing_x(data));
	if (data->conversion == 'X')
		return (processing_cap_x(data));
	if (data->conversion == '%')
		return (processing_percent(data));
	return (-2);
}

int			parsing(t_fnc_data *data, int start, int range, char *entry)
{
	data->conversion = entry[start + range];
	while (range)
	{
		if (entry[start] == '.')
			get_precision(data, &start, &range, entry);
		if ((entry[start] >= '1' && entry[start] <= '9') && range)
			get_width(data, &start, &range, entry);
		if (entry[start] == '-' && range)
		{
			data->minus = 1;
			start++;
			range--;
		}
		if (entry[start] == '0' && range)
		{
			data->zero = 1;
			start++;
			range--;
		}
		if (entry[start] == '*' && range)
			get_width_star(data, &start, &range);
	}
	return (resolve(data));
}
