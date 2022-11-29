/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:50:19 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/29 17:11:23 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static int	**get_plan_points(int hyp, int line_number, int line_len, int *ori)
{
	int	**tab_points;
	int	i;

	tab_points = ft_calloc_int_tab_2(2, 2);
	if (!tab_points)
		return (NULL);
	tab_points[0][0] = ori[0];
	tab_points[0][1] = ori[1];
	tab_points[1][0] = ori[0];
	tab_points[1][1] = ori[1];
	i = 0;
	while (i++ < line_len)
	{
		tab_points[0][0] -= hyp * 0.866;
		tab_points[0][1] += hyp / 2;
	}
	i = 0;
	while (i++ < line_number)
	{
		tab_points[1][0] += hyp * 0.866;
		tab_points[1][1] += hyp / 2;
	}
	return (tab_points);
}

static int	plot_length(int hyp, int *dims, int **pts, t_data img, t_point *map)
{
	int	tmp[2];
	int tmp2[2];
	// int	ind;
	int	i;

	tmp[0] = pts[0][0];
	tmp[1] = pts[0][1];
	i = 0;
	plot_line(img, pts[1], tmp, map->color);
	while (i < dims[0])
	{
		tmp[0] += hyp * 0.866;
		tmp[1] += hyp / 2;
		pts[1][0] += hyp * 0.866;
		pts[1][1] += hyp / 2;
		tmp2[0] = pts[1][0];
		tmp2[1] = pts[1][1];
		plot_line(img, tmp2, tmp, map->color);
		write(1, "AAA\n", 4);
		i++;
	}
	return (i);
}

static int	plot_width(int hyp, int *dims, int **pts, t_data img, t_point *map)
{
	int	tmp[2];
	int tmp2[2];
	// int	ind;
	int	i;

	tmp[0] = pts[0][0];
	tmp[1] = pts[0][1];
	i = 0;
	plot_line(img, tmp, pts[2], map->color);
	while (i < dims[1])
	{
		tmp[0] -= hyp * 0.866;
		tmp[1] += hyp / 2;
		pts[2][0] -= hyp * 0.866;
		pts[2][1] += hyp / 2;
		tmp2[0] = pts[2][0];
		tmp2[1] = pts[2][1]; //ADD ALT
		plot_line(img, tmp, tmp2, map->color);
		write(1, "AAA\n", 4);
		i++;
	}
	return (i);
}

int create_map(int hyp, int *dimensions, int *origin, t_data img, t_point *map)
{
	int	**tab_subpoints;
	int	**tab_points;
	// int tmp[2];
	// int	i;

	tab_subpoints = get_plan_points(hyp, dimensions[0], dimensions[1], origin);
	tab_points = ft_calloc_int_tab_2(3, 2);
	if (!tab_subpoints || !tab_points)
		return (-1);
	tab_points[0][0] = origin[0];
	tab_points[0][1] = origin[1];
	tab_points[1][0] = tab_subpoints[0][0];
	tab_points[1][1] = tab_subpoints[0][1];
	tab_points[2][0] = tab_subpoints[1][0];
	tab_points[2][1] = tab_subpoints[1][1];
	plot_length(hyp, dimensions, tab_points, img, map);
	plot_width(hyp, dimensions, tab_points, img, map);

	// i = 0;
	// while (i < dimensions[1])
	// {
	// 	origin[0] -= hyp * 0.866;
	// 	origin[1] += hyp / 2;
	// 	c[0] -= hyp * 0.866;
	// 	c[1] += hyp / 2;
	// 	i++;
	// }
	//TODO FREE TABS
	return (1);
}