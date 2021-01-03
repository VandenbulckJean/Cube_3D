/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:34:38 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/13 11:00:12 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_size(unsigned int n)
{
	int size;

	size = 1;
	while (n / 10 > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

void			get_sign(int n, unsigned int *temp, int *sign)
{
	if (n < 0)
	{
		*temp = -n;
		*sign = 1;
	}
	else
		*temp = n;
}

char			*ft_itoa(int n)
{
	int				sign;
	int				size;
	unsigned int	temp;
	char			*number;

	sign = 0;
	get_sign(n, &temp, &sign);
	size = get_size(temp);
	if (!(number = (char*)malloc(sizeof(char) * (size + sign + 1))))
		return (NULL);
	number[size + sign] = '\0';
	while (size)
	{
		number[size + sign - 1] = temp % 10 + '0';
		temp /= 10;
		size--;
	}
	if (sign == 1)
		number[0] = '-';
	return (number);
}
