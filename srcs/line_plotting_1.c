/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_plotting_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:47:33 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/01 16:28:29 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	plot_line(t_data *img, int *p1, int *p2, unsigned int color)
// {
// 	int			e2;
// 	int			err;
// 	const int	dx = abs(p2[0] - p1[0]);
// 	const int	dy = -abs(p2[1] - p1[1]);
// 	const int	sx = -1 + 2 * (p1[0] < p2[0]);
// 	const int	sy = -1 + 2 * (p1[1] < p2[1]);

// 	err = dx + dy;
// 	while (1)
// 	{
// 		mlx_spp(img, p1[0], p1[1], color);
// 		if (p1[0] == p2[0] && p1[1] == p2[1])
// 			break ;
// 		e2 = 2 * err;
// 		if (e2 >= dy)
// 		{
// 			err += dy;
// 			p1[0] += sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			err += dx;
// 			p1[1] += sy;
// 		}
// 	}
// }

void	plot_line(t_data *img, int *p1, int *p2, unsigned int color)
{
	if (abs(p2[0] - p1[0]) > abs(p2[1] - p1[1]))
	{
		if (p2[0] > p1[0])
		{
			ft_printf("Bres Plot 1 \n");
			bres_plot_low(img, p1, p2, color);
		}
		else
		{
			ft_printf("Bres Plot 2 \n");
			bres_plot_low(img, p2, p1, color);
		}
	}
	else
	{
		if (p2[1] > p1[1])
		{
			ft_printf("Bres Plot Inv 1\n");
			bres_plot_high(img, p1, p2, color);
		}			
		else
		{
			ft_printf("Bres Plot Inv 2\n");
			bres_plot_high(img, p2, p1, color);
		}
	}
}

int	rev_points_x(int **p1, int **p2)
{
	int	tmp;

	if ((*p1)[0] > (*p2)[0])
	{
		tmp = (*p1)[0];
		(*p1)[0] = (*p2)[0];
		(*p2)[0] = tmp;
		tmp = (*p1)[1];
		(*p1)[1] = (*p2)[1];
		(*p2)[1] = tmp;
		return (1);
	}
	return (0);
}

int	rev_points_y(int **p1, int **p2)
{
	int	tmp;

	if ((*p1)[1] > (*p2)[1])
	{
		tmp = (*p1)[0];
		(*p1)[0] = (*p2)[0];
		(*p2)[0] = tmp;
		tmp = (*p1)[1];
		(*p1)[1] = (*p2)[1];
		(*p2)[1] = tmp;
		return (1);
	}
	return (0);
}

void	bres_plot_low(t_data *img, int *p1, int *p2, unsigned int color)
{
	int	x;
	int	y;
	int	bres_val;
	int	sign_delta_y;
	int	delta_x;
	int delta_y;

	delta_x = p2[0] - p1[0];
	delta_y = p2[1] - p1[1];
	sign_delta_y = 1;
	// sign_delta_y = 1 - (p2[1] - p1[1] < 0) * 2;
	if (delta_y < 0)
	{
		sign_delta_y = -1;
		delta_y = -delta_y;
	}
	bres_val = (2 * delta_y) - delta_x;
	x = p1[0] - 1;
	y = p1[1];
	while (++x < p2[0])
	{
		mlx_spp(img, x, y, color);
		if (bres_val > 0)
		{
			y += sign_delta_y;
			bres_val += 2 * (delta_y - delta_x);
		}
		else
		{
			bres_val += 2 * delta_y;
		}
	}
}


void	bres_plot_high(t_data *img, int *p1, int *p2, unsigned int color)
{
	int	x;
	int	y;
	int	delta_x;
	int delta_y;
	int	bres_val;
	int	sign_delta_x;

	delta_x = p2[0] - p1[0];
	delta_y = p2[1] - p1[1];
	// sign_delta_x = 1 - (p2[0] - p1[0] < 0) * 2;
	sign_delta_x = 1;
	if (delta_x < 0)
	{
		delta_x = -delta_x;
		sign_delta_x = -1;
	}
	bres_val = (2 * delta_x) - delta_y;
	x = p1[0];
	y = p1[1] - 1;
	while (++y < p2[1])
	{
		mlx_spp(img, x, y, color);
		if (bres_val > 0)
		{
			x += sign_delta_x;
			bres_val += 2 * (delta_x - delta_y);
		}
		else
		{
			bres_val += 2 * delta_x;
		}
	}
}

// int main(void)
// {
// 	int *a;
// 	int *b;

// 	a = malloc(sizeof(int) * 2);
// 	b = malloc(sizeof(int) * 2);
// 	a[0] = 100;
// 	a[1] = 50;
// 	b[0] = 50;
// 	b[1] = 200;
// 	rev_points_x(&a, &b);
// 	printf("%d,%d | %d,%d\n", a[0], a[1], b[0], b[1]);

// 	free(a); free(b);
// }