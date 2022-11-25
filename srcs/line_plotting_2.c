/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_plotting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:20:12 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/25 17:24:13 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_spp(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	plot_line_vertical(t_data img, int *p1, int *p2, unsigned int col)
{
	int	start_y;
	int	end_y;
	int	x;
	
	x = p1[0];
	start_y = p1[1];
	end_y = p2[1];
	while (start_y <= end_y)
	{
		mlx_spp(&img, x, start_y, col);
		start_y++;
	}
}


void plot_line(t_data img, int *p1, int *p2, int color)
{
	if (abs(p2[1] - p1[1]) < abs(p2[0] - p1[0]))
	{
		if (p1[0] > p2[0])
			plot_line_high(img, p2, p1, color);
		else
			plot_line_low(img, p1, p2, color);
	}
	else if (p1[0] == p2[0])
	{
		if (p1[1] > p2[1])
			plot_line_vertical(img, p2, p1, color);
		else
			plot_line_vertical(img, p1, p2, color);
	}
	else
	{
		if (p1[1] > p2[1])
			plot_line_high(img, p2, p1, color);
		else
			plot_line_low(img, p1, p2, color);
	}
}