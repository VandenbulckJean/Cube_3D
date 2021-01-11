#include "../include/cube.h"

void	load_textures(t_cube *cube)
{
	if (!(cube->north.imgptr = mlx_xpm_file_to_image(cube->ptr, cube->north.path, &cube->north.width, &cube->north.height)))
		handle_error("can't load north texture", cube);
	if (!(cube->south.imgptr = mlx_xpm_file_to_image(cube->ptr, cube->south.path, &cube->south.width, &cube->south.height)))
		handle_error("can't load south texture", cube);
	if (!(cube->west.imgptr = mlx_xpm_file_to_image(cube->ptr, cube->west.path, &cube->west.width, &cube->west.height)))
		handle_error("can't load west texture", cube);
	if (!(cube->east.imgptr = mlx_xpm_file_to_image(cube->ptr, cube->east.path, &cube->east.width, &cube->east.height)))
		handle_error("can't load east texture", cube);
	if (!(cube->sprite.imgptr = mlx_xpm_file_to_image(cube->ptr, cube->sprite.path, &cube->sprite.width, &cube->sprite.height)))
		handle_error("can't load sprite texture", cube);
}

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
	load_textures(cube);
	raycasting(cube);
}