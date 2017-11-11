/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:31:28 by bhalderm          #+#    #+#             */
/*   Updated: 2017/11/10 15:53:48 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "libft/libft.h"

int		ft_grid(int piece);
int		ft_poscheck(char *array, char *block, int mapsize);
int		ft_validblock(char *str);
int		ft_tetchecker(char *strs, char letter);
int		ft_vaildation(int d, int ln, int i);
int		ft_solvepuzzle(char *grid, char **array, int mapsize, int piece);
char	*ft_orafile(char *av);
char	**ft_pmalloc(char *str, int *piece);
void	ft_fillgrid(int mapsize, char *grid);
void	ft_mapmaker(char *grid, char **array, int mapsize, int piece);
void	ft_validpiece(char *str, char letter);
void	ft_posremove(char *array, char *block, int mapsize);
char	current_letter(char *array);
char	**ft_connect(char *str, int *piece, char letter);

#endif
