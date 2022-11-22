/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/22 11:29:28 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void plotLineHigh(t_data img, int x0, int y0, int x1, int y1)
{
	int x, y, dx, dy, dist, xi;
	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dy < 0)
	{
		xi = -1;
		dx = -dx;
	}
	dist = (2 * dx) - dy;
	x = x0;
	y = y0;
	while (y < y1)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
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

void plotLineLow(t_data img, int x0, int y0, int x1, int y1)
{
	int x, y, dx, dy, dist, yi;
	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	dist = (2 * dy) - dx;
	x = x0;
	y = y0;
	while (x < x1)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
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

void plotLine(t_data img, int x0, int y0, int x1, int y1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			plotLineLow(img, x1, y1, x0, y0);
		else
			plotLineLow(img, x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			plotLineHigh(img, x1, y1, x0, y0);
		else
			plotLineLow(img, x0, y0, x1, y1);
	}
}

int main (void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Il est lent ce lait");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	plotLine(img, 1920, 1080, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}