/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:02:13 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/19 13:02:15 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int			ago(int x[], int c, int index)
{
	index--;
	while (index >= 0)
	{
		if (x[index] == c)
			return (1);
		index--;
	}
	return (0);
}

static int			get_side(int x[])
{
	int				i;
	int				unic;

	i = 0;
	unic = 0;
	while (i < 4)
	{
		if (!ago(x, x[i], i))
			unic++;
		i++;
	}
	return (unic);
}

static void			move_to_left(t_shape *shape)
{
	while (shape->x[0] != 0 && shape->x[1] != 0 && \
								shape->x[2] != 0 && shape->x[3] != 0)
	{
		shape->x[0]--;
		shape->x[1]--;
		shape->x[2]--;
		shape->x[3]--;
	}
	while (shape->y[0] != 0 && shape->y[1] != 0 && \
							shape->y[2] != 0 && shape->y[3] != 0)
	{
		shape->y[0]--;
		shape->y[1]--;
		shape->y[2]--;
		shape->y[3]--;
	}
}

static void			read_shape(char *map, t_shape shapes[])
{
	int				i;
	int				coup;

	i = 0;
	coup = 0;
	while (map[i])
	{
		if (map[i] == '#')
		{
			shapes[g_count_sh].x[coup] = i % 5;
			shapes[g_count_sh].y[coup] = i / 5;
			coup++;
		}
		i++;
	}
	shapes[g_count_sh].widht = get_side(shapes[g_count_sh].x);
	shapes[g_count_sh].height = get_side(shapes[g_count_sh].y);
	shapes[g_count_sh].sign = g_count_sh + 65;
	move_to_left(&shapes[g_count_sh]);
	g_count_sh++;
}

int					reader(char *path, t_shape shapes[])
{
	int				fd;
	int				bytes;
	char			buf[22];

	g_count_sh = 0;
	fd = open(path, O_RDONLY);
	if (fd < 3 || read(fd, buf, 0) < 0)
		return (0);
	while ((bytes = read(fd, buf, 21)))
	{
		if (bytes != 21 && bytes != 20)
			print_error();
		buf[bytes] = '\0';
		read_shape(buf, shapes);
	}
	close(fd);
	return (1);
}
