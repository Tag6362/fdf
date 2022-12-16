/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:15:09 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 14:23:29 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void move_up(t_data *img)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	(*img->points)[0][0][1] -= 10;
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}

void move_left(t_data *img)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	(*img->points)[0][0][0] -= 10;
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}

void move_down(t_data *img)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	(*img->points)[0][0][1] += 10;
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}

void move_right(t_data *img)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	(*img->points)[0][0][0] += 10;
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}