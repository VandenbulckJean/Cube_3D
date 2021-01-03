/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:14 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/18 15:37:14 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

static int	processing_s_zero_flag(void)
{
	return (-12);
}

static int	processing_s_precision_flag(t_fnc_data *data)
{
	if (data->amount_precision <
	(int)ft_strlen(data->string) && data->amount_precision >= 0)
		if (!(data->string = truncstr(data->string, data->amount_precision)))
			return (-1);
	return (1);
}

static int	processing_s_width_minus_flag(t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width -
	ft_strlen(data->string), ' ')))
		return (-1);
	if (data->minus)
	{
		if (!(data->string = strjoin_back(data->string, str)))
			return (memory_allocation_error_free(str));
	}
	else
	{
		if (!(data->string = strjoin_front(data->string, str)))
			return (memory_allocation_error_free(str));
	}
	return (1);
}

static int	processing_s_flags(t_fnc_data *data)
{
	if (data->zero)
		return (processing_s_zero_flag());
	if (data->precision)
		if (processing_s_precision_flag(data) == -1)
			return (-1);
	if (data->width)
		return (processing_s_width_minus_flag(data));
	return (1);
}

int			processing_s(t_fnc_data *data)
{
	char *str;

	if (!(str = ft_strdup(va_arg(data->saved_variables, char*))))
		return (-1);
	if (!(data->string = strjoin_back(data->string, str)))
		return (memory_allocation_error_free(str));
	free(str);
	return (processing_s_flags(data));
}
