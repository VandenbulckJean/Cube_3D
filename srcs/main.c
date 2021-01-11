#include "cube.h"

int main(int argc, char *argv[])
{
	t_cube	cube;

	check_arguments(argc, argv, &cube);
	parsing_file(&cube);

	initialisation(&cube);

	event_loop(&cube);
	return (0);
}
