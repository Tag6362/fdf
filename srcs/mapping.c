/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:50:19 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/30 18:15:31 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// static int	**get_plan_points(int hyp, int line_number, int line_len, int *ori)
// {
// 	int	**tab_points;
// 	int	i;

// 	tab_points = ft_calloc_int_tab_2(2, 2);
// 	if (!tab_points)
// 		return (NULL);
// 	tab_points[0][0] = ori[0];
// 	tab_points[0][1] = ori[1];
// 	tab_points[1][0] = ori[0];
// 	tab_points[1][1] = ori[1];
// 	i = 0;
// 	while (i++ < line_len)
// 	{
// 		tab_points[0][0] -= hyp * 0.866;
// 		tab_points[0][1] += hyp / 2;
// 	}
// 	i = 0;
// 	while (i++ < line_number)
// 	{
// 		tab_points[1][0] += hyp * 0.866;
// 		tab_points[1][1] += hyp / 2;
// 	}
// 	return (tab_points);
// }

static int	plot_length(int hyp, int *dims, int **pts, t_data img, t_point *map)
{
	int	tmp[2];
	int tmp2[2];
	int tmp3[2];
	int j;
	int	i;

	tmp3[0] = pts[0][0];
	tmp3[1] = pts[0][1];
	i = 0;
	j = 0;
	while (j < dims[1])
	{
		i = 0;
		while (i < dims[0])
		{
			if (i != 0)
			{
				pts[1][0] += hyp * 0.866;
				pts[1][1] += hyp / 2;
			}
			tmp2[0] = pts[1][0];
			tmp2[1] = pts[1][1];
			if (i != 0)
				plot_line(img, tmp, tmp2, (map + j * dims[1] + i)->color);	
			tmp[0] = pts[1][0];
			tmp[1] = pts[1][1];
			i++;
		}
		tmp3[0] -= hyp * 0.866;
		tmp3[1] += hyp / 2;
		pts[1][0] = tmp3[0];
		pts[1][1] = tmp3[1];
		j++;
	}
	return (i);
}

static int	plot_width(int hyp, int *dims, int **pts, t_data img, t_point *map)
{
	int	tmp[2];
	int tmp2[2];
	int tmp3[2];
	int j;
	int	i;

	tmp3[0] = pts[0][0];
	tmp3[1] = pts[0][1];
	i = 0;
	j = 0;
	while (j < dims[0])
	{
		i = 0;
		while (i < dims[1])
		{
			if (i != 0)
			{
				pts[1][0] -= hyp * 0.866;
				pts[1][1] += hyp / 2;
			}
			tmp2[0] = pts[1][0];
			tmp2[1] = pts[1][1];
			if (i != 0)
				plot_line(img, tmp2, tmp, (map + j * dims[0] + i)->color);	
			tmp[0] = pts[1][0];
			tmp[1] = pts[1][1];
			i++;
		}
		tmp3[0] += hyp * 0.866;
		tmp3[1] += hyp / 2;
		pts[1][0] = tmp3[0];
		pts[1][1] = tmp3[1];
		j++;
	}
	return (i);
}

int create_map(int hyp, int *dimensions, int *origin, t_data img, t_point *map)
{
	// int	**tab_subpoints;
	int	**tab_points;
	// int tmp[2];
	// int	i;

	// tab_subpoints = get_plan_points(hyp, dimensions[0], dimensions[1], origin);
	tab_points = ft_calloc_int_tab_2(3, 2);
	if (!tab_points)
		return (-1);
	tab_points[0][0] = origin[0];
	tab_points[0][1] = origin[1];
	tab_points[1][0] = origin[0];
	tab_points[1][1] = origin[1];
	tab_points[2][0] = origin[0];
	tab_points[2][1] = origin[1];
	plot_length(hyp, dimensions, tab_points, img, map);
	tab_points[0][0] = origin[0];
	tab_points[0][1] = origin[1];
	tab_points[1][0] = origin[0];
	tab_points[1][1] = origin[1];
	tab_points[2][0] = origin[0];
	tab_points[2][1] = origin[1];
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