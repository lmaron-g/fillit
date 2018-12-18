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

static void			move_to_left(shape *shape)
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

static void			read_shape(char *map, shape shapes[])
{
	int				i;
	int				coup;

	i = 0;
	coup = 0;
	while (map[i])
	{
		if (map[i] == '#')
		{
			shapes[n].x[coup] = i % 5;
			shapes[n].y[coup] = i / 5;
			coup++;
		}
		i++;
	}
	shapes[n].widht = get_side(shapes[n].x);
	shapes[n].height = get_side(shapes[n].y);
	shapes[n].sign = n + 65;
	move_to_left(&shapes[n]);
	n++;
}

int					reader(char *path, shape shapes[])
{
	int				fd;
	int				bytes;
	char			buf[22];

	n = 0;
	fd = open(path, O_RDONLY);
	if (fd < 3 || read(fd, buf, 0) < 0)
		return (0);
	while ((bytes = read(fd, buf, 21)))
	{
		if (bytes != 21 && bytes != 20)
			ft_error();
		buf[21] = '\0';
		read_shape(buf, shapes);
	}
	close(fd);
	return (n);
}
