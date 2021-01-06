#include "cube.h"

int main(int argc, char *argv[])
{
	t_cube	cube;

	check_arguments(argc, argv);
	if (!(cube.ptr = mlx_init()))
		handle_error("fail to initialize mlx.");
	parsing_file(&cube, argv[1]);

	
	return (0);
}
