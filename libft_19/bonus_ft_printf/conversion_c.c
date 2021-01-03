/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:20:49 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:18:08 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

static int	processing_c_precison_flag(void)
{
	return (-10);
}

static int	processing_c_zero_flag(void)
{
	return (-11);
}

static int	processing_c_width_minus_flag(t_fnc_data *data)
{
	char	*str;

	if (!(str = create_filled_string(data->width - 1, ' ')))
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

static int	processing_c_flags(t_fnc_data *data)
{
	if (data->precision && data->amount_precision != 0)
		return (processing_c_precison_flag());
	if (data->zero)
		return (processing_c_zero_flag());
	if (data->width)
		return (processing_c_width_minus_flag(data));
	return (1);
}

int			processing_c(t_fnc_data *data)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (-1);
	str[0] = va_arg(data->saved_variables, int);
	str[1] = '\0';
	if (str[0] == '\0')
	{
		data->writtenchars++;
		data->iszeroascii = 1;
	}
	free(data->string);
	data->string = str;
	return (processing_c_flags(data));
}
