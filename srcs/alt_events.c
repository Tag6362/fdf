/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:31:22 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 14:33:59 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void up_alt(t_data *img)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	glo_scale(1);
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}

void down_alt(t_data *img)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	glo_scale(-1);
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}