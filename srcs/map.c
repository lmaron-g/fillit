/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:02:01 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/19 13:02:04 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*g_colors[] = {
	"\033[2;40m",
	"\033[2;41m",
	"\033[2;42m",
	"\033[2;43m",
	"\033[2;44m",
	"\033[2;45m",
	"\033[2;46m",
	"\033[2;47m",
	"\033[7;40m",
	"\033[7;41m",
	"\033[7;42m",
	"\033[7;43m",
	"\033[7;44m",
	"\033[7;45m",
	"\033[7;46m",
	"\033[7;47m",
};

void		print_error(void)
{
	ft_putendl("error");
	exit(0);
}

char		**create_map(int size)
{
	char	**res;
	int		i;

	if (!(res = (char **)malloc(sizeof(char *) * (size + 1))))
		print_error();
	i = 0;
	while (i < size)
	{
		if (!(res[i] = ft_strnew(size)))
			print_error();
		ft_memset(res[i++], '.', size);
	}
	res[i] = 0;
	return (res);
}

void		print_map(char **map, int g_rang)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_rang)
	{
		j = -1;
		while (++j < g_rang)
		{
			if ('A' <= map[i][j] && map[i][j] <= 'Z')
				ft_putstr(g_colors[map[i][j] % 16]);
			write(1, &(map[i][j]), 1);
			ft_putstr(RESET);
		}
		write(1, "\n", 1);
	}
}

void		free_map(char ***map)
{
	int		i;
	char	**mapi;

	i = 0;
	mapi = *map;
	while (mapi[i])
	{
		free(mapi[i]);
		mapi[i++] = 0;
	}
	free(mapi);
	map = 0;
}
