/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/22 13:50:32 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void plotLineHigh(t_data img, int *p1, int *p2, int color)
{
	int x, y, dx, dy, dist, xi;
	
	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	xi = 1;
	if (dy < 0)
	{
		xi = -1;
		dx = -dx;
	}
	dist = (2 * dx) - dy;
	x = p1[0];
	y = p1[1];
	while (y < p2[1])
	{
		my_mlx_pixel_put(&img, x, y, color);
		if (dist > 0)
		{
			x += xi;
			dist += (2 * (dx - dy));
		}
		else
			dist += 2 * dx;
		y++;
	}
	color++;
}

void plotLineLow(t_data img, int *p1, int *p2, int color)
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
		my_mlx_pixel_put(&img, x, y, color);
		if (dist > 0)
		{
			y += yi;
			dist += (2 * (dy - dx));
		}
		else
			dist += 2 * dy;
		x++;
		color++;
	}
}

void plotLine(t_data img, int *p1, int *p2, int color)
{
	if (abs(p2[1] - p2[1]) < abs(p2[0] - p1[0]))
	{
		if (p1[0] > p2[0])
			plotLineLow(img, p2, p1, color);
		else
			plotLineLow(img, p1, p2, color);
	}
	else
	{
		if (p1[1] > p2[1])
			plotLineHigh(img, p2, p1, color);
		else
			plotLineLow(img, p1, p2, color);
	}
}

int main (void)
{
	void 	*mlx;
	void 	*mlx_win;
	int		*p1;
	int		*p2;
	int		color;
	t_data	img;
	t_vars	vars;


	p1 = malloc(sizeof (int) * 2);
	p2 = malloc(sizeof (int) * 2);
	if (!p1 || !p2)
		return (-1);
	
	p1[0] = 0;
	p1[1] = 0;

	p2[0] = 1920;
	p2[1] = 1080;

	color = 0xFF0000;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Il est lent ce lait");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	plotLine(img, p1, p2, color);
	write(1, "aaaa\n", 5);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}