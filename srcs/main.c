/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:01:49 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/19 17:22:09 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_shape	shapes[26];

	if (argc == 2)
	{
		if (valid_file(argv[1]))
		{
			reader(argv[1], shapes);
			fill_it(shapes);
			return (0);
		}
		else
			print_error();
	}
	ft_putendl("usage: ./fillit input_file");
	return (0);
}
