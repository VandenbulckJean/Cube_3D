/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_uxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:20 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:18:38 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

int	processing_u(t_fnc_data *data)
{
	char			*str;
	unsigned int	value;

	value = va_arg(data->saved_variables, unsigned int);
	if (data->precision && value == 0)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (-1);
		str[1] = '\0';
	}
	else
	{
		if (!(str = ft_itoa_base(value, 10, "0123456789")))
			return (-1);
		if (!(data->string = strjoin_back(data->string, str)))
			return (memory_allocation_error_free(str));
	}
	free(str);
	return (processing_d_flags(data, 0));
}

int	processing_x(t_fnc_data *data)
{
	char			*str;
	unsigned int	value;

	value = va_arg(data->saved_variables, unsigned int);
	if (data->precision && value == 0)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (-1);
		str[1] = '\0';
	}
	else
	{
		if (!(str = ft_itoa_base(value, 16, "0123456789abcdef")))
			return (-1);
		if (!(data->string = strjoin_back(data->string, str)))
			return (memory_allocation_error_free(str));
	}
	free(str);
	return (processing_d_flags(data, 0));
}

int	processing_cap_x(t_fnc_data *data)
{
	char			*str;
	unsigned int	value;

	value = va_arg(data->saved_variables, unsigned int);
	if (data->precision && value == 0)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (-1);
		str[1] = '\0';
	}
	else
	{
		if (!(str = ft_itoa_base(value, 16, "0123456789ABCDEF")))
			return (-1);
		if (!(data->string = strjoin_back(data->string, str)))
			return (memory_allocation_error_free(str));
	}
	free(str);
	return (processing_d_flags(data, 0));
}
