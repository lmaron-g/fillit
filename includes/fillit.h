/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:01:18 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/19 17:31:10 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

#define RESET	"\033[0m"

int				g_count_sh;
int				g_rang;

typedef struct	s_shape
{
	int			x[4];
	int			y[4];
	int			height;
	int			widht;
	char		sign;
}				t_shape;

void			fill_it(t_shape shapes[]);
int				reader(char *path, t_shape shapes[]);
void			print_map(char **map, int rang);
void			print_error(void);
int				valid_file(char *path);
int				ft_sqrt(int nbr);
void			free_map(char ***map);
char			**create_map(int size);

#endif
