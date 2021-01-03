/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_di_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:26:55 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:19:15 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

int		processing_d_width_minus_precison(t_fnc_data *data, int negative)
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
	if (!(str = create_filled_string(data->width -
	ft_strlen(data->string), ' ')))
		return (-1);
	if (!(data->string = strjoin_back(data->string, str)))
		return (memory_allocation_error_free(str));
	free(str);
	return (1);
}

int		processing_d_width_precision(t_fnc_data *data, int negative)
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
	if (data->zero && data->amount_precision < 0)
		if (!(str = create_filled_string(data->width -
		ft_strlen(data->string), '0')))
			return (-1);
	if (!(data->zero && data->amount_precision < 0))
		if (!(str = create_filled_string(data->width -
		ft_strlen(data->string), ' ')))
			return (-1);
	if (!(data->string = strjoin_front(data->string, str)))
		return (memory_allocation_error_free(str));
	free(str);
	return (1);
}

int		processing_d_width_minus(t_fnc_data *data, int negative)
{
	char *str;

	if (negative)
		if (!(data->string = strjoin_front(data->string, "-")))
			return (-1);
	if (!(str = create_filled_string(data->width -
	ft_strlen(data->string), ' ')))
		return (-1);
	if (!(data->string = strjoin_back(data->string, str)))
		return (memory_allocation_error_free(str));
	free(str);
	return (1);
}

int		processing_d_width_zero(t_fnc_data *data, int negative)
{
	char *str;

	if (!(str = create_filled_string(data->width -
	ft_strlen(data->string), '0')))
		return (-1);
	if (!(data->string = strjoin_front(data->string, str)))
		return (memory_allocation_error_free(str));
	free(str);
	if (negative && data->string[0] == '0')
		data->string[0] = '-';
	if (negative && data->string[0] != '0' && data->string[0] != '-')
		if (!(data->string = strjoin_front(data->string, "-")))
			return (-1);
	return (1);
}

int		processing_d_width_flag(t_fnc_data *data, int negative)
{
	char *str;

	if (data->precision && data->minus)
		return (processing_d_width_minus_precison(data, negative));
	if (data->precision && !(data->minus))
		return (processing_d_width_precision(data, negative));
	if (data->minus)
		return (processing_d_width_minus(data, negative));
	if (data->zero)
		return (processing_d_width_zero(data, negative));
	else
	{
		if (negative)
			if (!(data->string = strjoin_front(data->string, "-")))
				return (-1);
		if (!(str = create_filled_string(data->width -
		ft_strlen(data->string), ' ')))
			return (-1);
		if (!(data->string = strjoin_front(data->string, str)))
			return (memory_allocation_error_free(str));
		free(str);
		return (1);
	}
}
