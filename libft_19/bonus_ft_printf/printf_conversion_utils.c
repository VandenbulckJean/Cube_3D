/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:31 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:18:43 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

static int		get_size(unsigned long long int n, int base)
{
	int size;

	size = 1;
	while (n / base > 0)
	{
		size++;
		n /= base;
	}
	return (size);
}

static void		get_sign(long long int n,
	unsigned long long int *temp, int *sign)
{
	if (n < 0)
	{
		*temp = -n;
		*sign = 1;
	}
	else
		*temp = n;
}

char			*ft_itoa_base(long long int n, int base, char *basestr)
{
	int						sign;
	int						size;
	unsigned long long int	temp;
	char					*number;

	sign = 0;
	get_sign(n, &temp, &sign);
	size = get_size(temp, base);
	if (!(number = (char*)malloc(sizeof(char) * (size + sign + 1))))
		return (NULL);
	number[size + sign] = '\0';
	while (size)
	{
		number[size + sign - 1] = basestr[temp % base];
		temp /= base;
		size--;
	}
	if (sign == 1)
		number[0] = '-';
	return (number);
}

char			*ft_itoa_pointer(unsigned long long int n,
	int base, char *basestr)
{
	int				size;
	char			*number;

	size = get_size(n, base);
	if (!(number = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	number[size] = '\0';
	while (size)
	{
		number[size - 1] = basestr[n % base];
		n /= base;
		size--;
	}
	return (number);
}
