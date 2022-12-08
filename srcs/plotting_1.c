/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotting_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:47:33 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/08 15:00:28 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	mlx_spp(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->llen + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	bres_plot_low(t_data *img, int *p1, int *p2, unsigned int color)
{
	int	x;
	int	y;
	int	bres_val;
	int	sign_delta_y;
	int	delta_y;

	delta_y = abs(p2[1] - p1[1]);
	sign_delta_y = 1 - (p2[1] - p1[1] < 0) * 2;
	bres_val = (2 * delta_y) - (p2[0] - p1[0]);
	x = p1[0] - 1;
	y = p1[1];
	while (++x < p2[0])
	{
		mlx_spp(img, x, y, color);
		if (bres_val > 0)
		{
			y += sign_delta_y;
			bres_val += 2 * (delta_y - (p2[0] - p1[0]));
		}
		else
			bres_val += 2 * delta_y;
	}
}

static void	bres_plot_high(t_data *img, int *p1, int *p2, unsigned int color)
{
	int	x;
	int	y;
	int	delta_x;
	int	bres_val;
	int	sign_delta_x;

	delta_x = abs(p2[0] - p1[0]);
	sign_delta_x = 1 - (p2[0] - p1[0] < 0) * 2;
	bres_val = (2 * delta_x) - (p2[1] - p1[1]);
	x = p1[0];
	y = p1[1] - 1;
	while (++y < p2[1])
	{
		mlx_spp(img, x, y, color);
		if (bres_val > 0)
		{
			x += sign_delta_x;
			bres_val += 2 * (delta_x - (p2[1] - p1[1]));
		}
		else
			bres_val += 2 * delta_x;
	}
}

void	plot_line(t_data *img, int *p1, int *p2, unsigned int color)
{
	if (abs(p2[0] - p1[0]) > abs(p2[1] - p1[1]))
	{
		if (p2[0] > p1[0])
			bres_plot_low(img, p1, p2, color);
		else
			bres_plot_low(img, p2, p1, color);
	}
	else
	{
		if (p2[1] > p1[1])
			bres_plot_high(img, p1, p2, color);
		else
			bres_plot_high(img, p2, p1, color);
	}
}

void	plot_points(t_data img, int ***pts, int *dims, t_point **map)
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
			if (j < dims[1] - 1)
			{
				if (map[i][j].color == map[i][j + 1].color)
					plot_line(&img, pts[i][j], pts[i][j + 1], map[i][j].color);
				else
					plot_line_deg_1(&img, pts, ind, map);
			}
			if (i < dims[0] - 1)
			{
				if (map[i][j].color == map[i + 1][j].color)
					plot_line(&img, pts[i][j], pts[i + 1][j], map[i][j].color);
				else 
					plot_line_deg_2(&img, pts, ind, map);
			}	
			j++;
		}
		i++;
	}
}