/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:20:42 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/28 10:27:12 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **ft_calloc_int_tab_2(int len_tab, int len_subtab)
{
	int	i;
	int	**tab;

	tab = ft_calloc(len_tab, sizeof(int *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len_tab)
	{
		tab[i] = ft_calloc(len_subtab, sizeof(int));
		if (!tab[i])
			return (ft_free_int_tab_2(tab, i - 1), NULL);
		i++;
	}
	return (tab);
}