/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:20:59 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:18:31 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

static int	processing_p_zero_flag(void)
{
	return (-13);
}

static int	processing_p_precision_flg(void)
{
	return (-14);
}

static int	processing_p_width_minus_flag(t_fnc_data *data)
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

static int	processing_p_flags(t_fnc_data *data)
{
	if (data->precision && data->amount_precision != 0)
		return (processing_p_precision_flg());
	if (data->zero)
		return (processing_p_zero_flag());
	if (data->width)
		return (processing_p_width_minus_flag(data));
	return (1);
}

int			processing_p(t_fnc_data *data)
{
	char					*str;
	unsigned long long int	value;

	value = va_arg(data->saved_variables, unsigned long long int);
	if (!(data->string = strjoin_back(data->string, "0x")))
		return (-1);
	if (!(data->precision && value == 0))
	{
		if (!(str = ft_itoa_pointer(value, 16, "0123456789abcdef")))
			return (-1);
		if (!(data->string = strjoin_back(data->string, str)))
			return (memory_allocation_error_free(str));
		free(str);
	}
	return (processing_p_flags(data));
}
