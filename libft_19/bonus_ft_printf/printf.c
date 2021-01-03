/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:58 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:18:50 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

static int		setzero(t_fnc_data *data)
{
	data->amount_precision = 0;
	data->precision = 0;
	data->minus = 0;
	data->width = 0;
	data->zero = 0;
	data->conversion = 0;
	data->iszeroascii = 0;
	if (!(data->string = malloc(sizeof(char))))
	{
		free(data);
		return (0);
	}
	(data->string)[0] = '\0';
	return (1);
}

static void		write_count_free(t_fnc_data *data)
{
	if (data->iszeroascii && data->minus)
		write(1, "\0", 1);
	putstr(data->string);
	if (data->iszeroascii && !(data->minus))
		write(1, "\0", 1);
	data->writtenchars = data->writtenchars + ft_strlen(data->string);
	free(data->string);
}

static void		write_count(char c, t_fnc_data *data)
{
	write(1, &c, 1);
	data->writtenchars++;
}

static int		entry_processing(char *entry, t_fnc_data *data)
{
	int i;
	int start;

	i = 0;
	data->writtenchars = 0;
	while (entry[i])
	{
		while (entry[i] && entry[i] != '%')
			write_count(entry[i++], data);
		if (entry[i] && entry[i] == '%')
		{
			start = ++i;
			if (!(setzero(data)))
				return (-1);
			while (!(isinstr("cspdiuxX%", entry[i])) && entry[i])
				if (!(isinstr("-.*0123456789", entry[i++])))
					return (free_string_return(data, 0));
			if (parsing(data, start, i++ - start, entry) == -1)
				return (free_string_return(data, -1));
			write_count_free(data);
		}
	}
	return (data->writtenchars);
}

int				ft_printf(const char *entry, ...)
{
	t_fnc_data	*data;
	int			return_value;

	return_value = 0;
	if (!(entry == NULL))
	{
		if (!(data = malloc(sizeof(t_fnc_data))))
			return (-1);
		va_start(data->saved_variables, entry);
		return_value = entry_processing((char *)entry, data);
		va_end(data->saved_variables);
		free(data);
	}
	return (return_value);
}
