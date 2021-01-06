#include "cube.h"

void	createnextimg(t_cube *cube)
{
	cube->next_img.ptr = mlx_new_image(cube->ptr, cube->wind.x_res, cube->wind.y_res);
	cube->next_img.address = (unsigned char*)mlx_get_data_addr(cube->next_img.ptr, &cube->next_img.bpp, &cube->next_img.size_line, &cube->next_img.endian);
}
void	createwindow(t_cube *cube)
{
	if (!(cube->wind.ptr = mlx_new_window(cube->ptr, cube->wind.x_res, cube->wind.y_res, "Cube 3D")))
		handle_error("fail to build window", cube);
	createnextimg(cube);
	mlx_put_image_to_window(cube->ptr, cube->wind.ptr, cube->next_img.ptr, 0, 0);
	mlx_loop(cube->ptr);
}

int main(int argc, char *argv[])
{
	t_cube	cube;

	check_arguments(argc, argv, &cube);
	cube.filename = ft_strdup(argv[1]);
	if (!(cube.ptr = mlx_init()))
		handle_error("fail to initialize mlx.", &cube);
	parsing_file(&cube);
	createwindow(&cube);
	return (0);
}
