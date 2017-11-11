/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetchecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:50:36 by bhalderm          #+#    #+#             */
/*   Updated: 2017/11/10 18:40:16 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tetchecker(char *strs, char letter)
{
	if (strs[0] && strs[0] == '#')
	{
		strs[0] = letter;
		return (1 + ft_tetchecker(strs - 1, letter) +
				ft_tetchecker(strs + 1, letter) +
					ft_tetchecker(strs + 5, letter));
	}
	else
		return (0);
}

int		ft_validblock(char *str)
{
	static int i = 0;
	static int d = 0;
	static int ln = 0;
	static int h = 0;

	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		if (str[i] == '.' || str[i] == '#')
			d++;
		if (str[i] == '#')
			h++;
		if (str[i] == '\n')
			ln++;
		if ((i + 1) % 21 == 0)
			if (str[i] != '\n')
				return (0);
		i++;
	}
	if (d % 16 != 0)
		return (0);
	if (h % 4 != 0 || h == 0)
		return (0);
	if ((ln + 1) % 5 != 0)
		return (0);
	return (((i + 1) % 21 != 0) ? 0 : 1);
}

void	ft_validpiece(char *str, char letter)
{
	int	count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#' && ft_tetchecker(&str[i], letter) != 4)
		{
			ft_putstr_fd("error\n", 1);
			exit(0);
		}
		i++;
		count++;
	}
}
