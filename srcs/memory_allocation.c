/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:20:42 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 15:03:10 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	***ft_calloc_int_tab_3(int len_tab, int len_subtab, int len_subsubtab)
{
	int	i;
	int	j;
	int	***tab;

	tab = ft_calloc(len_tab, sizeof(int **));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len_tab)
	{
		j = 0;
		tab[i] = ft_calloc(len_subtab, sizeof(int *));
		if (!tab[i])
			return (ft_free_int_tab_3(tab, i - 1, len_subtab), NULL);
		while (j < len_subtab)
		{
			tab[i][j] = ft_calloc(len_subsubtab, sizeof(int));
			if (!tab[i][j])
				return (ft_free_int_tab_2(*tab, j - 1),
					ft_free_int_tab_3(tab, i - 1, len_subtab), NULL);
			j++;
		}
		i++;
	}
	return (tab);
}

t_point	**map_malloc(int height, int width)
{
	int		i;
	t_point	**map;

	i = 0;
	map = malloc(sizeof(t_point *) * height);
	if (!map)
		return (NULL);
	while (i < height)
	{
		map[i] = malloc(sizeof(t_point) * width);
		if (!map[i])
			return (free_map(map, i - 1), NULL);
		i++;
	}
	return (map);
}

// int main(void)
// {
// 	int i = 0;
// 	int j = 0;
// 	int len_tab = 3;
// 	int len_subtab = 5;
// 	int ***tab = ft_calloc_int_tab_3(len_tab, len_subtab, 1);

// 	while (i < len_tab)
// 	{
// 		j = 0;
// 		while (j < len_subtab)
// 		{
// 			tab[i][j][0] = i * j;
// 			j++;	
// 		}
// 		i++;
// 	}

// 	i = 0;
// 	while (i < len_tab)
// 	{
// 		j = 0;
// 		while (j < len_subtab)
// 		{
// 			printf("%d ", tab[i][j][0]);
// 			j++;	
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	ft_free_int_tab_3(tab, len_tab, len_subtab);
// }