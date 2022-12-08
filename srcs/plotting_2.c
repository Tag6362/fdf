/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotting_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:14:31 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/08 12:18:34 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bres_plot_low_dg(t_data *img, int *p1, int *p2, unsigned int color)
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
		if (bres_val > 0 && color++ > 0)
		{
			y += sign_delta_y;
			bres_val += 2 * (delta_y - (p2[0] - p1[0]));
		}
		else
			bres_val += 2 * delta_y;
	}
}

static void	bres_plot_high_dg(t_data *img, int *p1, int *p2, unsigned int color)
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
		if (bres_val > 0 && color-- > 0)
		{
			x += sign_delta_x;
			bres_val += 2 * (delta_x - (p2[1] - p1[1]));
		}
		else
			bres_val += 2 * delta_x;
	}
}

void plot_line_deg_1(t_data *img, int ***pts, int *dims, t_point **map)
{
	int				i;
	int				j;
	int				*p1;
	int				*p2;
	unsigned int	color;

	i = dims[0];
	j = dims[1];
	color = map[i][j].color;
	p1 = pts[i][j];
	p2 = pts[i][j + 1];
	// ft_printf("Entring 1\n");
	if (abs(p2[0] - p1[0]) > abs(p2[1] - p1[1]))
	{
		if (p2[0] > p1[0])
			bres_plot_low_dg(img, p1, p2, color);
		else
			bres_plot_low_dg(img, p2, p1, color);
	}
	else
	{
		if (p2[1] > p1[1])
			bres_plot_high_dg(img, p1, p2, color);
		else
			bres_plot_high_dg(img, p2, p1, color);
	}
	// ft_printf("Leaving 1\n");
}

void plot_line_deg_2(t_data *img, int ***pts, int *dims, t_point **map)
{
	int				i;
	int				j;
	int				*p1;
	int				*p2;
	unsigned int	color;

	i = dims[0];
	j = dims[1];
	color = map[i][j].color;
	p1 = pts[i][j];
	p2 = pts[i + 1][j];
	// ft_printf("Entring 2\n");
	if (abs(p2[0] - p1[0]) > abs(p2[1] - p1[1]))
	{
		if (p2[0] > p1[0])
			bres_plot_low_dg(img, p1, p2, color);
		else
			bres_plot_low_dg(img, p2, p1, color);
	}
	else
	{
		if (p2[1] > p1[1])
			bres_plot_high_dg(img, p1, p2, color);
		else
			bres_plot_high_dg(img, p2, p1, color);
	}
	// ft_printf("Leaving 2\n");
}
