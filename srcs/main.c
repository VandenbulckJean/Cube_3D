#include "cube.h"

void	getnextimg(void)
{

}

int main(int argc, char *argv[])
{
	t_cube	cube;

	check_arguments(argc, argv);
	if (!(cube.ptr = mlx_init()))
		handle_error("fail to initialize mlx.");

	
	return (0);
}

int			atoi_minirt(char *str, int *i, int *result)
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

static void		get_resolution(char *str, t_cube *cube)
{
	int i;

	i = 1;
	if(!(atoi_minirt(str, &i, &cube->wind.x_res)))
		handle_error("Please enter height and width for window.\nBoth being positive entire numbers.");
	if(!(atoi_minirt(str, &i, &cube->wind.y_res)))
		handle_error("Please enter height for window. It must be a positive entire number.");
	check_resolution(str, rt, i);
}

int	parsing_file(t_cube *cube, char *filename)
{
	char *filedata;
	int fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		handle_error("Can't read .rt file");
	while(get_next_line(fd, &filedata))
	{
		if (filedata[0] == 'R')
			get_resolution(filedata, cube);
	}
}