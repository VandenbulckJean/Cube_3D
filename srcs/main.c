#include "../include/cube.h"

int main(int argc, char *argv[])
{
	t_cube	cube;
	ft_bzero(&cube, sizeof(t_cube));
	check_arguments(argc, argv, &cube);
	parsing_file(&cube);

	initialisation(&cube);
	event_loop(&cube);
	return (0);
}
