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

	i = 0;
	while (i < g_rang)
	{
		write(1, map[i++], g_rang);
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
