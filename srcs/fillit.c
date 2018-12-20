/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:01:37 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/19 13:01:40 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		delete_it(t_shape shape, char **map, int i, int j)
{
	int		coup;

	coup = 4;
	while (coup--)
		map[shape.y[coup] + i][shape.x[coup] + j] = '.';
}

int			place_it(t_shape shape, char **map, int i, int j)
{
	int coup;

	coup = 0;
	while (coup < 4)
	{
		if (map[shape.y[coup] + i][shape.x[coup] + j] != '.')
			return (0);
		coup++;
	}
	while (coup--)
		map[shape.y[coup] + i][shape.x[coup] + j] = shape.sign;
	return (1);
}

int			solve_it(char **map, t_shape shapes[], int stack)
{
	int		i;
	int		j;

	i = 0;
	while (i + shapes[stack].height <= g_rang)
	{
		j = 0;
		while (j + shapes[stack].widht <= g_rang)
		{
			if (place_it(shapes[stack], map, i, j))
			{
				if (stack == g_count_sh - 1 || solve_it(map, shapes, stack + 1))
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

void		fill_it(t_shape shapes[])
{
	char	**map;
	int		stack;

	stack = 0;
	g_rang = ft_sqrt(4 * g_count_sh);
	map = create_map(24);
	while (!solve_it(map, shapes, stack))
		if (g_rang++ > 24)
			break ;
	print_map(map, g_rang);
	free_map(&map);
}
