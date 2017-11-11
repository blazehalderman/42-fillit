/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:05:17 by bhalderm          #+#    #+#             */
/*   Updated: 2017/11/09 13:48:52 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_connect(char *str, int *piece, char letter)
{
	char *tmp;
	char **big;

	big = (char **)malloc(sizeof(char *) * 27);
	tmp = str;
	while (*tmp != '\0')
	{
		big[*piece] = ft_strnew(21);
		ft_strncpy(big[*piece], tmp, 21);
		ft_validpiece(big[*piece], letter++);
		*piece += 1;
		if (tmp[20] == '\0')
			break ;
		tmp += 21;
	}
	big[*piece] = NULL;
	return (big);
}
