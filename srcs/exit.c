#include "../include/cube.h"

void	destroy_map(t_cube *cube)
{
	int i;

	i = 0;
	if (cube->map.map)
	{
		while (cube->map.map[i])
		{
			free(cube->map.map[i]);
			i++;
		}
		free(cube->map.map);
	}
}

void	free_parsing(t_cube *cube)
{
	free(cube->filename);
	if (cube->cam.distbuffer)
		free(cube->cam.distbuffer);
	if (cube->north.path)
		free(cube->north.path);
	if (cube->south.path)
		free(cube->south.path);
	if (cube->east.path)
		free(cube->east.path);
	if (cube->west.path)
		free(cube->west.path);
	if (cube->sprite.texture.path)
		free(cube->sprite.texture.path);
	destroy_map(cube);
}

void	print_error_exit(char *error)
{
	ft_printf("Error\n%s.", error);
	exit(EXIT_FAILURE);
}

void	handle_error_parsing(char * error, t_cube *cube)
{
	free_parsing(cube);
	print_error_exit(error);
}

void	handle_missing_color(char *missingcolors, char *colorname, t_cube *cube)
{
	free_parsing(cube);
	ft_printf("Error\nMissing %s values in %s line.", missingcolors, colorname);
	exit(EXIT_FAILURE);
}

void	destroy_images(t_cube *cube)
{
	if (cube->next_img.ptr)
		mlx_destroy_image(cube->ptr, cube->next_img.ptr);
	if (cube->north.img.ptr)
		mlx_destroy_image(cube->ptr, cube->north.img.ptr);
	if (cube->south.img.ptr)
		mlx_destroy_image(cube->ptr, cube->south.img.ptr);
	if (cube->east.img.ptr)
		mlx_destroy_image(cube->ptr, cube->east.img.ptr);
	if (cube->west.img.ptr)
		mlx_destroy_image(cube->ptr, cube->west.img.ptr);
	if (cube->sprite.texture.img.ptr)
		mlx_destroy_image(cube->ptr, cube->sprite.texture.img.ptr);
	mlx_destroy_window(cube->ptr, cube->wind.ptr);
}

void	free_motor_variables(t_cube *cube)
{
	if (cube->sprite.tab)
		free(cube->sprite.tab);
	if (cube->sprite.order)
		free(cube->sprite.order);
}

void	handle_error(char *string, t_cube *cube)
{
	free_parsing(cube);
	free_motor_variables(cube);
	destroy_images(cube);
	print_error_exit(string);
}

void	handle_exit(t_cube *cube)
{
	free_parsing(cube);
	free_motor_variables(cube);
	destroy_images(cube);
	exit(EXIT_SUCCESS);
}