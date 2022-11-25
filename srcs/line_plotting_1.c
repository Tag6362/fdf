/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_plotting_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:47:33 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/25 15:28:39 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void plot_line_low(t_data img, int *p1, int *p2, unsigned int color)
{
	int x, y, dx, dy, dist, yi;
	
	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	dist = (2 * dy) - dx;
	x = p1[0];
	y = p1[1];
	while (x < p2[0])
	{
		mlx_spp(&img, x, y, color);
		if (dist > 0)
		{
			y += yi;
			dist += (2 * (dy - dx));
		}
		else
			dist += 2 * dy;
		x++;
	}
}

void plot_line_high(t_data img, int *p1, int *p2, unsigned int color)
{
	int x, y, dx, dy, dist, xi;
	
	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	dist = (2 * dx) - dy;
	x = p1[0];
	y = p1[1];
	while (y < p2[1])
	{
		mlx_spp(&img, x, y, color);
		if (dist > 0)
		{
			x += xi;
			dist += (2 * (dx - dy));
		}
		else
			dist += 2 * dx;
		y++;
	}
}

// static void	mlx_spp(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
// 	*(unsigned int *)dst = color;
// }


// static void plotLineLow(t_data img, int *p1, int *p2, int color)
// {
// 	int x, y, dx, dy, dist, yi;
	
// 	dx = p2[0] - p1[0];
// 	dy = p2[1] - p1[1];
// 	yi = 1;
// 	if (dy < 0)
// 	{
// 		yi = -1;
// 		dy = -dy;
// 	}
// 	dist = (2 * dy) - dx;
// 	x = p1[0];
// 	y = p1[1];
// 	while (x < p2[0])
// 	{
// 		mlx_spp(&img, x, y, color);
// 		if (dist > 0)
// 		{
// 			y += yi;
// 			dist += (2 * (dy - dx));
// 		}
// 		else
// 			dist += 2 * dy;
// 		x++;
// 	}
// }

// static void plotLineHigh(t_data img, int *p1, int *p2, int color)
// {
// 	int x, y, dx, dy, dist, xi;
	
// 	dx = p2[0] - p1[0];
// 	dy = p2[1] - p1[1];
// 	xi = 1;
// 	if (dy < 0)
// 	{
// 		xi = -1;
// 		dx = -dx;
// 	}
// 	dist = (2 * dx) - dy;
// 	x = p1[0];
// 	y = p1[1];
// 	while (y < p2[1])
// 	{
// 		mlx_spp(&img, x, y, color);
// 		if (dist > 0)
// 		{
// 			x += xi;
// 			dist += (2 * (dx - dy));
// 		}
// 		else
// 			dist += 2 * dx;
// 		y++;
// 	}
// }

// void plotLine(t_data img, int *p1, int *p2, int color)
// {
// 	if (abs(p2[1] - p2[1]) < abs(p2[0] - p1[0]))
// 	{
// 		if (p1[0] > p2[0])
// 			plotLineLow(img, p2, p1, color);
// 		else
// 			plotLineLow(img, p1, p2, color);
// 	}
// 	else
// 	{
// 		if (p1[1] > p2[1])
// 			plotLineHigh(img, p2, p1, color);
// 		else
// 			plotLineLow(img, p1, p2, color);
// 	}
// }
