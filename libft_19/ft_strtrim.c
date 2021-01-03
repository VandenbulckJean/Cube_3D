/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:36:32 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/15 09:30:44 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_in_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int		get_start(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (s1[i] && is_in_set(s1[i], set) == 1)
		i++;
	return (i);
}

int		get_end(char const *s1, char const *set)
{
	size_t i;

	i = ft_strlen(s1);
	i--;
	while (i && is_in_set(s1[i], set) == 1)
		i--;
	return ((int)i);
}

char	*str_cp(char const *s1, char *str, int start, int end)
{
	int i;

	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (0);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end == 0)
	{
		if (!(str = malloc(sizeof(char))))
			return (NULL);
		str_cp(s1, str, start, end);
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * ((end - start) + 2))))
		return (NULL);
	str_cp(s1, str, start, end);
	return (str);
}
