/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:20:54 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:18:29 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

static int			processing_d_precision_flag(t_fnc_data *data, int negative)
{
	char *str;

	if (!(str = create_filled_string(data->amount_precision -
	ft_strlen(data->string), '0')))
		return (-1);
	if (!(data->string = strjoin_front(data->string, str)))
		return (memory_allocation_error_free(str));
	free(str);
	if (negative)
		if (!(data->string = strjoin_front(data->string, "-")))
			return (-1);
	return (1);
}

int					processing_d_flags(t_fnc_data *data, int negative)
{
	if (data->width)
		return (processing_d_width_flag(data, negative));
	if (data->precision)
		return (processing_d_precision_flag(data, negative));
	if (negative)
		if (!(data->string = strjoin_front(data->string, "-")))
			return (-1);
	return (1);
}

static unsigned int	get_value(va_list saved_variables, int *negative)
{
	int				value;
	unsigned int	newvalue;

	value = va_arg(saved_variables, int);
	if (value < 0)
	{
		*negative = 1;
		newvalue = -value;
	}
	else
	{
		newvalue = value;
	}
	return (newvalue);
}

int					processing_d(t_fnc_data *data)
{
	char				*str;
	unsigned int		value;
	int					negative;

	negative = 0;
	value = get_value(data->saved_variables, &negative);
	if (!(data->precision && value == 0))
	{
		if (!(str = ft_itoa_base(value, 10, "0123456789")))
			return (-1);
		if (!(data->string = strjoin_back(data->string, str)))
			return (memory_allocation_error_free(str));
		free(str);
	}
	return (processing_d_flags(data, negative));
}
