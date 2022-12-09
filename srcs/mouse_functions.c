/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:32:28 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 17:13:13 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_func(t_data *img, int button, int x, int y)
{
	char	*map_name;
	int		***points;

	map_name = ft_strdup(*img->map_name);
	if (!img->has_changed)
		ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	img->has_changed = 1;
	clear_image(*img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (button == 1)
		glo_scale(1);
	if (button == 3)
		glo_scale(-1);
	if (button == 4)
		(*img->dims)[2] += 2;
	if (button == 5)
		(*img->dims)[2] -= 2;
	points = parsing(map_name, img->dims, img->angle, img->map);
	img->points = &points;
	plot_points(*img, points, *img->dims);
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

// int zoom(t_data *img)
// {
// 	char	*map_name;
// 	int		***points;

// 	map_name = ft_strdup(*img->map_name);
// 	(*img->dims)[2] += 2;
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

// int dezoom(t_data *img)
// {
// 	char	*map_name;
// 	int		***points;

// 	map_name = ft_strdup(*img->map_name);
// 	(*img->dims)[2] -= 2;
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
