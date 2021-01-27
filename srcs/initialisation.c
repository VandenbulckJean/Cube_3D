#include "../include/cube.h"

void	init_texture(t_cube *cube)
{
	if (!(cube->north.img.address = (unsigned char*)mlx_get_data_addr(
	cube->north.img.ptr, &cube->north.img.bpp,
	&cube->north.img.size_line, &cube->north.img.endian)))
		handle_error("can't get north texture data", cube);
	if (!(cube->south.img.address = (unsigned char*)mlx_get_data_addr(
	cube->south.img.ptr, &cube->south.img.bpp,
	&cube->south.img.size_line, &cube->south.img.endian)))
		handle_error("can't get south texture data", cube);
	if (!(cube->west.img.address = (unsigned char*)mlx_get_data_addr(
	cube->west.img.ptr, &cube->west.img.bpp,
	&cube->west.img.size_line, &cube->west.img.endian)))
		handle_error("can't get west texture data", cube);
	if (!(cube->east.img.address = (unsigned char*)mlx_get_data_addr(
	cube->east.img.ptr, &cube->east.img.bpp,
	&cube->east.img.size_line, &cube->east.img.endian)))
		handle_error("can't get east texture data", cube);
	if (!(cube->sprite.texture.img.address = (unsigned char*)mlx_get_data_addr(
	cube->sprite.texture.img.ptr, &cube->sprite.texture.img.bpp,
	&cube->sprite.texture.img.size_line, &cube->sprite.texture.img.endian)))
		handle_error("can't get sprite texture data", cube);
}

void	load_textures(t_cube *cube)
{
	if (!(cube->north.img.ptr = mlx_xpm_file_to_image(cube->ptr,
	cube->north.path, &cube->north.width, &cube->north.height)))
		handle_error("can't load north texture", cube);
	if (!(cube->south.img.ptr = mlx_xpm_file_to_image(cube->ptr,
	cube->south.path, &cube->south.width, &cube->south.height)))
		handle_error("can't load south texture", cube);
	if (!(cube->west.img.ptr = mlx_xpm_file_to_image(cube->ptr,
	cube->west.path, &cube->west.width, &cube->west.height)))
		handle_error("can't load west texture", cube);
	if (!(cube->east.img.ptr = mlx_xpm_file_to_image(cube->ptr,
	cube->east.path, &cube->east.width, &cube->east.height)))
		handle_error("can't load east texture", cube);
	if (!(cube->sprite.texture.img.ptr =
	mlx_xpm_file_to_image(cube->ptr, cube->sprite.texture.path,
	&cube->sprite.texture.width, &cube->sprite.texture.height)))
		handle_error("can't load sprite texture", cube);
	init_texture(cube);
}

void	initit_motor_values(t_cube *cube)
{
	cube->next_img.ptr = NULL;
	cube->north.img.ptr = NULL;
	cube->south.img.ptr = NULL;
	cube->west.img.ptr = NULL;
	cube->east.img.ptr = NULL;
	cube->sprite.texture.img.ptr = NULL;
	cube->event.w_pressed = 0;
	cube->event.s_pressed = 0;
	cube->event.a_pressed = 0;
	cube->event.d_pressed = 0;
	cube->event.right_arow_pressed = 0;
	cube->event.left_arrow_pressed = 0;
	cube->sprite.order = NULL;
	cube->sprite.tab = NULL;
}

void	initialisation(t_cube *cube)
{
	initit_motor_values(cube);
	if (!(cube->wind.ptr = mlx_new_window(cube->ptr,
	cube->wind.x_res, cube->wind.y_res, "Cube 3D")))
		handle_error_parsing("Fail to build window", cube);
	if (!(cube->next_img.ptr = mlx_new_image(cube->ptr,
	cube->wind.x_res, cube->wind.y_res)))
		handle_error("Fail to build image", cube);
	cube->next_img.address =
	(unsigned char*)mlx_get_data_addr(cube->next_img.ptr,
	&cube->next_img.bpp, &cube->next_img.size_line, &cube->next_img.endian);
	load_textures(cube);
	initialise_sprites(cube);
	raycasting(cube);
}

void	init_values_parsing(t_cube *cube)
{
	cube->wind.x_res = 0;
	cube->wind.y_res = 0;
	cube->wind.res_line = 0;
	cube->floor.r = 0;
	cube->floor.g = 0;
	cube->floor.b = 0;
	cube->floor.line = 0;
	cube->ceiling.r = 0;
	cube->ceiling.g = 0;
	cube->ceiling.b = 0;
	cube->ceiling.line = 0;
	cube->north.path = NULL;
	cube->south.path = NULL;
	cube->east.path = NULL;
	cube->west.path = NULL;
	cube->sprite.texture.path = NULL;
	cube->map.map = NULL;
	cube->cam.distbuffer = NULL;
}
