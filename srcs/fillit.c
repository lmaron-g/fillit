#include "fillit.h"

void		delete_it(shape shape, char **map, int i, int j)
{
	int		coup;

	coup = 4;
	while (coup--)
		map[shape.x[coup] + j][shape.y[coup] + i] = '.';
}

int			place_it(shape shape, char **map, int i, int j)
{
	int coup;

	coup = 0;
	while (coup < 4)
	{
		if (map[shape.x[coup] + j][shape.y[coup] + i] != '.')
			return (0);
		coup++;
	}
	while (coup--)
		map[shape.x[coup] + j][shape.y[coup] + i] = shape.sign;
	return (1);
}

int			solve_it(char **map, shape shapes[], int stack)
{
	int		i;
	int		j;

	i = 0;
	while (i + shapes[stack].height <= rang)
	{
		j = 0;
		while (j + shapes[stack].widht <= rang)
		{
			if (place_it(shapes[stack], map, i, j))
			{
				if (stack == n - 1 || solve_it(map, shapes, stack + 1))
					return (1);
				else
					delete_it(shapes[stack], map, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}


void 		fill_it(shape shapes[])
{
	char	**map;
	int		stack;

	stack = 0;

	rang = ft_sqrt(4 * n);
	map = ft_create_map(16);
	while(!solve_it(map, shapes, stack))
		rang++;
	print_map(map, rang);
	free_map(&map);
}
