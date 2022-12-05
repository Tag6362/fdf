/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:50:19 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/05 18:25:56 by tgernez          ###   ########.fr       */
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

// static void plot_length(int hyp, int *dims, int **pts, t_data img, t_point *map)
// {
// 	int	tmp[2];
// 	int tmp2[2];
// 	int tmp3[2];
// 	int j;
// 	int	i;

// 	tmp3[0] = pts[0][0];
// 	tmp3[1] = pts[0][1];
// 	i = 0;
// 	j = 0;
// 	while (i < dims[1])
// 	{
// 		j = 0;
// 		while (j < dims[0])
// 		{
// 			if (j != 0)
// 			{
// 				pts[1][0] += hyp * 0.866;
// 				pts[1][1] += hyp / 2;
// 			}
// 			tmp2[0] = pts[1][0];
// 			tmp2[1] = pts[1][1] + (map + i * dims[0] + j)->alt * 2;
// 			if (j != 0)
// 				plot_line(img, tmp, tmp2, (map + i * dims[0] + j)->color);	
// 			tmp[0] = tmp2[0];
// 			tmp[1] = tmp2[1];
// 			j++;
// 		}
// 		tmp3[0] -= hyp * 0.866;
// 		tmp3[1] += hyp / 2;
// 		pts[1][0] = tmp3[0];
// 		pts[1][1] = tmp3[1];
// 		i++;
// 	}
// }

// static void	plot_width(int hyp, int *dims, int **pts, t_data img, t_point *map)
// {
// 	int	tmp[2];
// 	int tmp2[2];
// 	int tmp3[2];
// 	int j;
// 	int	i;

// 	tmp3[0] = pts[0][0];
// 	tmp3[1] = pts[0][1];
// 	i = 0;
// 	j = 0;
// 	while (i < dims[1])
// 	{
// 		j = 0;
// 		while (j < dims[1])
// 		{
// 			if (j != 0)
// 			{
// 				pts[1][0] -= hyp * 0.866;
// 				pts[1][1] += hyp / 2;
// 			}
// 			tmp2[0] = pts[1][0];
// 			tmp2[1] = pts[1][1];
// 			if (i != 0)
// 				plot_line(img, tmp2, tmp, (map + i * dims[0] + j)->color);	
// 			tmp[0] = pts[1][0];
// 			tmp[1] = pts[1][1];
// 			j++;
// 		}
// 		tmp3[0] += hyp * 0.866;
// 		tmp3[1] += hyp / 2;
// 		pts[1][0] = tmp3[0];
// 		pts[1][1] = tmp3[1];
// 		i++;
// 	}
// }

// int	**create_tab(int hyp, int *dims, int *origin, t_point *map)
// {
// 	int	**tab_points;
// 	int	tmp[2];
// 	int	ind;
// 	int	i;
// 	int	j;

// 	tab_points = ft_calloc_int_tab_2(dims[0] * dims[1], 2);
// 	if (!tab_points)
// 		return (NULL);
// 	i = 0;
// 	tmp[0] = origin[0];
// 	tmp[1] = origin[1];
// 	while (i < dims[0])
// 	{
// 		j = 0;
// 		while (j < dims[1])
// 		{
// 			ind = i * dims[0] + j;
// 			tab_points[ind][0] = tmp[0];
// 			tab_points[ind][1] = tmp[1] - map[ind].alt * dims[2];
// 			tmp[0] -= round(hyp * 0.866);
// 			tmp[1] += round(hyp / 2);
// 			j++;	
// 		}
// 		origin[0] += round(hyp * 0.866);
// 		origin[1] += round(hyp / 2);
// 		tmp[0] = origin[0];
// 		tmp[1] = origin[1];
// 		i++;
// 	}
// 	return (tab_points);
// }

// int	**create_tab(int hyp, int line_number, int line_len, int *origin, t_point *map)
// {
// 	int	**tab_points;
// 	int	tmp[2];
// 	int	ind;
// 	int	i;
// 	int	j;
// 	int tmp2;

// 	tab_points = ft_calloc_int_tab_2(line_number * line_len, 2);
// 	if (!tab_points)
// 		return (NULL);
// 	i = 0;
// 	if (dims[1] > dims[0])
// 	{
// 		tmp2 = dims[0];
// 		dims[0] = dims[1];
// 		dims[1] = tmp2;
// 		tmp2 = 1;
// 	}
// 	tmp[0] = origin[0];
// 	tmp[1] = origin[1];
// 	while (i < dims[0])
// 	{
// 		j = 0;
// 		while (j < dims[1])
// 		{
// 			if (tmp2)
// 				ind = i * dims[1] + j;
// 			else
// 				ind = i * dims[0] + j;
// 			tab_points[ind][0] = tmp[0];
// 			tab_points[ind][1] = tmp[1] - map[ind].alt * dims[2];
// 			tmp[0] -= round(hyp * 0.866);
// 			tmp[1] += round(hyp / 2);
// 			j++;	
// 		}
// 		origin[0] += round(hyp * 0.866);
// 		origin[1] += round(hyp / 2);
// 		tmp[0] = origin[0];
// 		tmp[1] = origin[1];
// 		i++;
// 	}
// 	return (tab_points);
// }

// void read_tab_test(int **tab_points, int *dims)
// {
// 	int	i;
// 	int	j;
// 	int	ind;

// 	i = 0;
// 	while (i < dims[0])
// 	{
// 		j = 0;
// 		while (j < dims[1])
// 		{
// 			ind = i * dims[0] + j;
// 			ft_printf("%d: %d,%d ", ind, tab_points[ind][0], tab_points[ind][1]);
// 			j++;	
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}	
// }

// int create_map(int hyp, int *dimensions, int *origin, t_data img, t_point *map)
// {
// 	// int	**tab_subpoints;
// 	int	**tab_points;
// 	// int tmp[2];
// 	// int	i;

// 	// tab_subpoints = get_plan_points(hyp, dimensions[0], dimensions[1], origin);
// 	tab_points = ft_calloc_int_tab_2(dimensions[0] * dimensions[1], 2);
// 	if (!tab_points)
// 		return (-1);
// 	tab_points_filling(tab_points, origin, hyp, dimensions, map);
// 	// tab_points[0][0] = origin[0];
// 	// tab_points[0][1] = origin[1];
// 	// tab_points[1][0] = origin[0];
// 	// tab_points[1][1] = origin[1];
// 	// tab_points[2][0] = origin[0];
// 	// tab_points[2][1] = origin[1];
// 	// plot_length(hyp, dimensions, tab_points, img, map);
// 	// tab_points[0][0] = origin[0];
// 	// tab_points[0][1] = origin[1];
// 	// tab_points[1][0] = origin[0];
// 	// tab_points[1][1] = origin[1];
// 	// tab_points[2][0] = origin[0];
// 	// tab_points[2][1] = origin[1];
// 	// plot_width(hyp, dimensions, tab_points, img, map);

// 	// i = 0;
// 	// while (i < dimensions[1])
// 	// {
// 	// 	origin[0] -= hyp * 0.866;
// 	// 	origin[1] += hyp / 2;
// 	// 	c[0] -= hyp * 0.866;
// 	// 	c[1] += hyp / 2;
// 	// 	i++;
// 	// }
// 	//TODO FREE TABS
// 	return (1);
// }