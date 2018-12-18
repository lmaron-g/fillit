#include "fillit.h"
#include <stdio.h>

int 		main(int argc, char **argv)
{
	shape	shapes[26];

	if (argc == 2)
	{
		if (valid_file(argv[1]))
		{
			reader(argv[1], shapes);
			fill_it(shapes);
			return (0);
		}
	}
	ft_putendl("usage: ./fillit input_file");
	return (1);
}
