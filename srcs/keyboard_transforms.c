/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_transforms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:15:09 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 16:30:58 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyboard_move(t_data *img, int keycode)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (keycode == 119)
		(*img->points)[0][0][1] -= 10;
	else if (keycode == 97)
		(*img->points)[0][0][0] -= 10;
	else if (keycode == 115)
		(*img->points)[0][0][1] += 10;
	else if (keycode == 100)
		(*img->points)[0][0][0] += 10;
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}

void	keyboard_alt(t_data *img, int keycode)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (keycode == 105)
		glo_scale(1);
	else if (keycode == 111)
		glo_scale(-1);
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}

void	keyboard_perspective(t_data *img, int keycode)
{
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (keycode == 107)
		img->angle *= 1.2;
	else if (keycode == 108)
		img->angle *= 0.8;
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}

void	keyboard_color(t_data *img, int keycode)
{
	int		i;
	int		j;
	t_point	**map;

	i = -1;
	map = *(img->map);
	clear_image(*img, *(img->dims));
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	while (++i < (*(img->dims))[0])
	{
		j = -1;
		while (++j < (*(img->dims))[1])
		{	
			if (keycode == 44)
				map[i][j].color *= 1.2;
			else
				map[i][j].color *= 0.8;
		}
	}
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
}
