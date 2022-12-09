/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotting_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:47:33 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 17:11:25 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	corr_line(int *a, int *b)
{
	if (0 <= a[0] && a[0] <= WINDOW_X && 0 <= b[0] && b[0] <= WINDOW_X)
	{
		if (0 <= a[1] && a[1] <= WINDOW_Y && 0 <= b[1] && b[1] <= WINDOW_Y)
			return (1);
	}
	return (0);
}

static void	plot_points_aux(t_data img, int ***pts, int *ind, int *dims)
{
	int	i;
	int	j;
	t_point **map;

	i = ind[0];
	j = ind[1];
	map = *img.map;
	if (j < dims[1] - 1 && corr_line(pts[i][j], pts[i][j + 1]))
	{
		if (map[i][j].color == map[i][j + 1].color)
			plot_line(&img, pts[i][j], pts[i][j + 1], map[i][j].color);
		else
			plot_line_deg_1(&img, pts, ind, map);
	}
	if (i < dims[0] - 1 && corr_line(pts[i][j], pts[i + 1][j]))
	{
		if (map[i][j].color == map[i + 1][j].color)
			plot_line(&img, pts[i][j], pts[i + 1][j], map[i][j].color);
		else 
			plot_line_deg_2(&img, pts, ind, map);
	}	
}

void	plot_points(t_data img, int ***pts, int *dims)
{
	int	i;
	int	j;
	int ind[2];

	i = 0;
	while (i < dims[0])
	{
		j = 0;
		ind[0] = i;
		while (j < dims[1])
		{
			ind[1] = j;
			plot_points_aux(img, pts, ind, dims);
			j++;
		}
		i++;
	}
}