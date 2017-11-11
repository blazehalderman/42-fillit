/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poscheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:13:41 by bhalderm          #+#    #+#             */
/*   Updated: 2017/11/09 15:18:59 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_poscheck(char *array, char *block, int mapsize)
{
	if ((block[0] && block[0] > 64) && array[0] == '.')
	{
		array[0] = block[0];
		if (block[5])
			return (1 + ft_poscheck(array + 1, block + 1, mapsize) +
					ft_poscheck(array - 1, block - 1, mapsize) +
						ft_poscheck(array + mapsize + 1, block + 5, mapsize));
		else
			return (1 + ft_poscheck(array + 1, block + 1, mapsize) +
				ft_poscheck(array - 1, block - 1, mapsize));
	}
	else
		return (0);
}

void	ft_posremove(char *array, char *block, int mapsize)
{
	if (array[0] == block[0] && array[0] != '\n')
	{
		array[0] = '.';
		ft_posremove(array - mapsize - 1, block, mapsize);
		ft_posremove(array + 1, block, mapsize);
		ft_posremove(array - 1, block, mapsize);
		ft_posremove(array + mapsize + 1, block, mapsize);
	}
}

char	current_letter(char *array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		if (array[i] == '\n' && array[i] == '.')
			i++;
		return (array[i]);
	}
	return (0);
}
