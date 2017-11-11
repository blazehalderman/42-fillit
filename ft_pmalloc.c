/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:10:03 by bhalderm          #+#    #+#             */
/*   Updated: 2017/11/09 13:47:40 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_pmalloc(char *str, int *piece)
{
	char	**strs;

	if (!(ft_validblock(str)))
	{
		ft_putstr_fd("error\n", 1);
		exit(0);
	}
	strs = ft_connect(str, piece, 'A');
	return (strs);
}
