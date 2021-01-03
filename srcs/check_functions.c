#include "cube.h"

static void		check_file_name(char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (len < 5)
		handle_error("File name incorrect");
	if (str[len-4] != '.' || str[len-3] != 'c' || str[len-2] != 'u' || str[len-1] != 'b')
		handle_error("File name incorrect");
}

static void		check_second_argument(char *str)
{
	if (!(ft_samestr("--save", str)))
		handle_error("Second argument must be --save");
}

void				check_arguments(int argc, char*argv[])
{
	if (argc == 1)
		handle_error("Enter at least an .rt file as first argument");
	if (argc == 2)
		check_file_name(argv[1]);
	if (argc == 3)
	{
		check_file_name(argv[1]);
		check_second_argument(argv[2]);
	}
	if (argc > 3)
		handle_error("Too many arguments");
}