#include "cube.h"

int ft_samestr(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i++])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

int			is_map_line(char *str)
{
	int i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!(isinstr("012 NESW", str[i])))
			return (0);
		i++;
	}
	return (1);
}

int			is_correct_path_char(char c)
{
	if (ft_isprint(c) && c != ' ')
		return (1);
	return (0);
}

int			atoi_cube(char *str, int *i, int *result)
{
	int sign;
	int check;

	*result = 0;
	sign = 0;
	while(str[*i] && str[*i] == ' ')
		(*i)++;
	if (str[*i] && str[*i] == '-')
	{
		sign++;
		(*i)++;
	}
	check = *i;
	while(isnumber(str[*i]))
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
		if (*result > 2000)
		{
			while(isnumber(str[*i]))
				(*i)++;
			break;
		}
	}
	if (sign)
		*result = -(*result);
	if (check == *i)
		return (0);
	return (1);
}