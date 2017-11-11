/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:31:01 by bhalderm          #+#    #+#             */
/*   Updated: 2017/11/10 16:45:43 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_orafile(char *av)
{
	size_t	i;
	int		fd;
	char	buf;
	char	*str;

	i = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &buf, 1))
		i++;
	if (i >= 546)
	{
		ft_putstr_fd("error\n", 1);
		exit(0);
	}
	str = ft_strnew(i);
	i = 0;
	close(fd);
	fd = open(av, O_RDONLY);
	while (read(fd, &buf, 1))
		str[i++] = buf;
	close(fd);
	return (str);
}

int		main(int argc, char **argv)
{
	char	*str;
	char	**array;
	int		mapsize;
	int		piece;
	char	*grid;

	if (argc == 2)
	{
		str = ft_orafile(argv[1]);
		array = ft_pmalloc(str, &piece);
		mapsize = ft_grid(piece);
		grid = ft_strnew(mapsize * (mapsize + 1));
		ft_mapmaker(grid, array, mapsize, piece);
	}
	ft_putchar_fd('\n', 1);
	return (0);
}
