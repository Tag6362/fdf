/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:03:38 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 17:10:08 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	**ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i++] = NULL;
	}
	free(strs);
	return (NULL);
}

void	***ft_free_int_tab_3(int ***tab, int len_tab, int len_subtab)
{
	int	i;

	i = 0;
	while (i < len_tab)
	{
		ft_free_int_tab_2(tab[i], len_subtab);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (NULL);
}

void	**ft_free_int_tab_2(int **tab, int len_tab)
{
	int	i;

	i = 0;
	while (i < len_tab)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (NULL);
}

void	**free_map(t_point **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	return (NULL);
}
