#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

#include <stdio.h>

int				n;
int				rang;

typedef struct	s_shape
{
	int			x[4];
	int			y[4];
	int			height;
	int			widht;
	char		sign;
}				shape;

void 			fill_it(shape shapes[]);
int				reader(char *path, shape shapes[]);
void			print_map(char **map, int rang);
void			ft_error(void);
int				valid_file(char *path);
int				ft_sqrt(int nbr);
void			free_map(char ***map);
char			**ft_create_map(int size);

#endif
