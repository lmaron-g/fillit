/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:41:03 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/19 17:30:54 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_sqrt(int nbr)
{
	int		i;

	i = 1;
	while (i * i < nbr)
		i++;
	return (i);
}

static int	valid_tetro(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 35)
		{
			if (i < 18 && 34 < map[i + 1] && map[i + 1] < 46)
				map[i]++;
			if (i < 14 && 34 < map[i + 5] && map[i + 5] < 46)
				map[i]++;
			if (i > 0 && 34 < map[i - 1] && map[i - 1] < 46)
				map[i]++;
			if (i > 4 && 34 < map[i - 5] && map[i - 5] < 46)
				map[i]++;
			if (map[i] == 35)
				return (0);
		}
		i++;
	}
	while (*map)
		if (*map++ > 36)
			return (1);
	return (0);
}

static int	valid_map(char *map)
{
	int		i;
	int		line_f;
	int		dot;
	int		hash;

	i = 0;
	dot = 0;
	hash = 0;
	line_f = 0;
	while (map[i] == '.' || map[i] == '#' || map[i] == '\n')
	{
		if ((i + 1) % 5 == 0)
			if (map[i] == '\n')
				line_f++;
		if (map[i] == '.')
			dot++;
		if (map[i++] == '#')
			hash++;
	}
	if ((map[20] == '\n' || map[20] == '\0') && line_f == 4 && dot == 12 && hash == 4)
		if (valid_tetro(map))
			return (1);
	return (0);
}

int			valid_file(char *path)
{
	int		fd;
	int		bytes;
	char	buf[22];

	fd = open(path, O_RDONLY);
	if (fd < 3 || read(fd, buf, 0) < 0)
		return (0);
	while ((bytes = read(fd, buf, 21)))
	{
		if (bytes != 21 && bytes != 20)
			return (0);
		buf[bytes] = '\0';
		if (!valid_map(buf))
			return (0);
	}
	close(fd);
	return (1);
}
