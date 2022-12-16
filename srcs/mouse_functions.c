/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:32:28 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 16:55:00 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(t_data *img)
{
	(*img->dims)[2] += 2;
}

static void	dezoom(t_data *img)
{
	(*img->dims)[2] -= 2;
}

static void	move(t_data *img, int x, int y)
{
	(*img->points)[0][0][0] = x;
	(*img->points)[0][0][1] = y;
}

int	mouse_func(t_data *img, int button, int x, int y)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (button == 1)
		move(img, x, y);
	if (button == 3)
		move(img, x, y);
	if (button == 4)
		zoom(img);
	if (button == 5)
		dezoom(img);
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
	return (0);
}
