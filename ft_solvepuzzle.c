/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvepuzzle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:13:53 by bhalderm          #+#    #+#             */
/*   Updated: 2017/11/10 16:45:30 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_grid(int piece)
{
	int i;

	i = 1;
	while (i * i < piece * 4)
		i++;
	return (i);
}

void	ft_fillgrid(int mapsize, char *grid)
{
	int i;

	i = -1;
	while (++i < (mapsize * (mapsize + 1)))
	{
		if (i % (mapsize + 1) == mapsize)
			grid[i] = '\n';
		else
			grid[i] = '.';
	}
	grid[i] = '\0';
}

char	*ft_locate(char *array)
{
	while (*array && (*array == '.' || *array == '\n'))
		array++;
	return (array);
}

int		ft_solvepuzzle(char *grid, char **array, int mapsize, int piece)
{
	char	*block;
	int		piececount;
	int		i;

	i = -1;
	if (array[0] == '\0')
		return (1);
	block = ft_locate(*array);
	while (grid[++i])
	{
		piececount = ft_poscheck(&grid[i], block, mapsize);
		if (piececount != 4)
			ft_posremove(&grid[i], block, mapsize);
		else
		{
			if (piece == (current_letter(array[0]) - 64))
				return (1);
			if (!ft_solvepuzzle(grid, &(array[1]), mapsize, piece))
				ft_posremove(&grid[i], block, mapsize);
			else
				return (1);
		}
	}
	return (0);
}

void	ft_mapmaker(char *grid, char **array, int mapsize, int piece)
{
	ft_fillgrid(mapsize, grid);
	while (ft_solvepuzzle(grid, array, mapsize, piece) != 1)
	{
		free(grid);
		mapsize++;
		grid = ft_strnew(mapsize * (mapsize + 1));
		ft_fillgrid(mapsize, grid);
	}
	ft_putstr(grid);
	free(grid);
}
