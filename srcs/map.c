#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

char	**ft_create_map(int size)
{
	char	**res;
	int		i;

	if (!(res = (char **)malloc(sizeof(char *) * (size + 1))))
		ft_error();
	i = 0;
	while (i < size)
	{
		if (!(res[i] = ft_strnew(size)))
			ft_error();
		ft_memset(res[i++], '.', size);
	}
	res[i] = NULL;
	return (res);
}

void	print_map(char **map, int rang)
{
	int i;

	i = 0;
	while (i < rang)
	{
		write(1, map[i++], rang);
		write(1, "\n", 1);
	}
}

void	free_map(char ***map)
{
	int	i;
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
