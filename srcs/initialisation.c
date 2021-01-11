#include "cube.h"

void	init_event_key(t_cube *cube)
{
	cube->event.w_pressed = 0;
	cube->event.s_pressed = 0;
	cube->event.a_pressed = 0;
	cube->event.d_pressed = 0;
	cube->event.right_arow_pressed = 0;
	cube->event.left_arrow_pressed = 0;
}

void	initialisation(t_cube *cube)
{
	init_event_key(cube);
	if (!(cube->ptr = mlx_init()))
		handle_error("fail to initialize mlx.", cube);
	if (!(cube->wind.ptr = mlx_new_window(cube->ptr, cube->wind.x_res, cube->wind.y_res, "Cube 3D")))
		handle_error("fail to build window", cube);
	cube->next_img.ptr = mlx_new_image(cube->ptr, cube->wind.x_res, cube->wind.y_res);
	cube->next_img.address = (unsigned char*)mlx_get_data_addr(cube->next_img.ptr, &cube->next_img.bpp, &cube->next_img.size_line, &cube->next_img.endian);
	raycasting(cube);
}