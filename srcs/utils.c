#include "../include/cube.h"

int	is_space(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int				is_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(is_space(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int			check_if_number(char *str, int i)
{
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && str[i] == '-')
		i++;
	if (str[i] && isnumber(str[i]))
		return(0);
	return (1);
}

void		atoi_cube(char *str, int *i, int *result)
{
	int sign;

	*result = 0;
	sign = 0;
	while(str[*i] && is_space(str[*i]))
		(*i)++;
	if (str[(*i)] == '-')
	{
		sign++;
		(*i)++;
	}
	while(isnumber(str[*i]))
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
		if (*result > (INT_MAX / 100))
		{
			while(isnumber(str[*i]))
				(*i)++;
			break;
		}
	}
	if (sign)
		*result = -(*result);
}

int		is_first_closer(t_vecteur s1, t_vecteur s2, t_vecteur pos)
{
	double dist1;
	double dist2;

	dist1 = ((pos.x - s1.x) * (pos.x - s1.x) + (pos.y - s1.y) * (pos.y - s1.y));
	dist2 = ((pos.x - s2.x) * (pos.x - s2.x) + (pos.y - s2.y) * (pos.y - s2.y));
	if (dist1 < dist2)
		return (1);
	return (0);
}