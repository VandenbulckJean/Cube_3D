#include "../include/cube.h"

static void		set_value_bmp(unsigned char *string, int i)
{
	string[0] = (unsigned char)(i);
	string[1] = (unsigned char)(i >> 8);
	string[2] = (unsigned char)(i >> 16);
	string[3] = (unsigned char)(i >> 24);
}

static int		bmp_header(t_cube *cube, int fd, int size)
{
	int				i;
	unsigned char	bmpheader[54];

	i = 0;
	while (i < 54)
		bmpheader[i++] = 0;
	bmpheader[0] = (unsigned char)('B');
	bmpheader[1] = (unsigned char)('M');
	set_value_bmp(bmpheader + 2, size);
	bmpheader[10] = (unsigned char)(54);
	bmpheader[14] = (unsigned char)(40);
	set_value_bmp(bmpheader + 18, cube->wind.x_res);
	set_value_bmp(bmpheader + 22, cube->wind.y_res);
	bmpheader[27] = (unsigned char)(1);
	bmpheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpheader, 54) < 0));
}

static int		rgb_data(t_cube *cube, int x, int y)
{
	int		rgb;
	int		color;

	color = *(int*)(cube->next_img.address
			+ (4 * cube->wind.x_res * (cube->wind.y_res - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int		bmp_data(t_cube *cube, int fd, int n)
{
	const unsigned char		mall[3] = {0, 0, 0};
	int						i;
	int						j;
	int						rgb;

	i = -1;
	while (++i < cube->wind.y_res)
	{
		j = -1;
		while (++j < cube->wind.x_res)
		{
			rgb = rgb_data(cube, j, i);
			if ((write(fd, &rgb, 3) < 0))
				return (0);
			if (n > 0 && write(fd, &mall, n) < 0)
				return (0);
		}
	}
	return (1);
}

void			make_bmp(t_cube *cube)
{
	int		fd;
	int		size;
	int		i;

	i = (4 - (cube->wind.x_res * 3) % 4) % 4;
	size = 54 + (3 * (cube->wind.x_res + i) * cube->wind.y_res);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT
		| O_TRUNC | O_APPEND, 0666)) < 0)
		return (handle_error("fail open bmp fd", cube));
	if (!bmp_header(cube, fd, size))
		return (handle_error("fail bmp header", cube));
	if (!bmp_data(cube, fd, i))
		return (handle_error("fail bmp data write", cube));
	close(fd);
	handle_exit(cube);
}