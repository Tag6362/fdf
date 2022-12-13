/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:32:28 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/13 17:43:15 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int zoom(t_data *img, int x, int y)
{
	img->x = x;
	img->y = y;
	(*img->dims)[2] += 2;		
	return (0);
}

static int dezoom(t_data *img, int x, int y)
{
	img->x = x;
	img->y = y;	(*img->dims)[2] -= 2;	
	return (0);
}

int	mouse_func(t_data *img, int button, int x, int y)
{
	char	*map_name;

	map_name = ft_strdup(*img->map_name);
	clear_image(*img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	ft_printf("x : %d, y : %d\n", img->x, img->y);
	ft_printf("hyp : %d\n", (*img->dims)[2]);
	if (button == 1)
		glo_scale(1);
	if (button == 3)
		glo_scale(-1);
	if (button == 4)
		zoom(img, x, y);
	if (button == 5)
		dezoom(img, x, y);
	iso(*(img->points), *(img->dims), img->angle);
	alt_adding(*(img->points), *(img->dims), *(img->map), glo_scale(0));
	plot_points(*img, *(img->points), *img->dims);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
	free(map_name);
	return (0);
}

// int up_alt(t_data *img)
// {

// 	return (0);
// }

// int down_alt(t_data *img)
// {
// 	char	*map_name;
// 	int		***points;

// 	map_name = ft_strdup(*img->map_name);
// 	glo_scale(-1);
// 	clear_image(*img);
// 	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
// 	if (!img->has_changed)
// 		ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
// 	img->has_changed = 1;
// 	points = parsing(map_name, img->dims, img->angle, img->map);
// 	img->points = &points;
// 	plot_points(*img, points, *img->dims);
// 	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
// 	render_texts(*img);
// 	free(map_name);
// 	return (0);
// }
