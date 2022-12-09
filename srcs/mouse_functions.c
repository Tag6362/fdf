/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:32:28 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 15:40:49 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int up_alt(t_data *img)
{
	char	*map_name;
	int		***points;

	map_name = ft_strdup(*img->map_name);
	glo_scale(1);
	clear_image(*img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (!img->has_changed)
		ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	img->has_changed = 1;
	points = parsing(map_name, img->dims, img->angle, img->map);
	img->points = &points;
	plot_points(*img, points, *img->dims, *img->map);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
	// ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	free(map_name);
	return (0);
}

int down_alt(t_data *img)
{
	char	*map_name;
	int		***points;

	map_name = ft_strdup(*img->map_name);
	glo_scale(-1);
	clear_image(*img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (!img->has_changed)
		ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	img->has_changed = 1;
	points = parsing(map_name, img->dims, img->angle, img->map);
	img->points = &points;
	plot_points(*img, points, *img->dims, *img->map);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
	// ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	free(map_name);
	return (0);
}

int zoom(t_data *img)
{
	char	*map_name;
	int		***points;

	map_name = ft_strdup(*img->map_name);
	(*img->dims)[2] += 2;
	clear_image(*img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (!img->has_changed)
		ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	img->has_changed = 1;
	points = parsing(map_name, img->dims, img->angle, img->map);
	img->points = &points;
	plot_points(*img, points, *img->dims, *img->map);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
	// ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	free(map_name);
	return (0);
}

int dezoom(t_data *img)
{
	char	*map_name;
	int		***points;

	map_name = ft_strdup(*img->map_name);
	(*img->dims)[2] -= 2;
	clear_image(*img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (!img->has_changed)
		ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	img->has_changed = 1;
	points = parsing(map_name, img->dims, img->angle, img->map);
	img->points = &points;
	plot_points(*img, points, *img->dims, *img->map);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	render_texts(*img);
	// ft_free_int_tab_3(*img->points, (*img->dims)[0], (*img->dims)[1]);
	free(map_name);
	return (0);
}


// int up_alt(t_data img)
// {
// 	char	*map_name;
// 	int		***points;

// 	map_name = ft_strdup(*img.map_name);
// 	glo_scale(1);
// 	clear_image(img);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	if (!img.has_changed)
// 	{
// 		ft_printf("HAS CHANGED %d /HAS_CHANGED\n", img.has_changed);
// 		ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
// 	}
// 	points = parsing(map_name, img.dims, img.angle, img.map);
// 	img.points = &points;
// 	plot_points(img, points, *img.dims, *img.map);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	render_texts(img);
// 	// ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
// 	free(map_name);
// 	return (0);
// }

// int down_alt(t_data img)
// {
// 	char	*map_name;
// 	int		***points;

// 	map_name = ft_strdup(*img.map_name);
// 	glo_scale(-1);
// 	clear_image(img);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	if (!img.has_changed)
// 	{
// 		ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
// 		img.has_changed = 1;
// 	}
// 	points = parsing(map_name, img.dims, img.angle, img.map);
// 	img.points = &points;
// 	plot_points(img, points, *img.dims, *img.map);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	render_texts(img);
// 	// ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
// 	free(map_name);
// 	return (0);
// }

// int zoom(t_data img)
// {
// 	char	*map_name;
// 	int		***points;

// 	map_name = ft_strdup(*img.map_name);
// 	(*img.dims)[2] += 2;
// 	clear_image(img);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	if (!img.has_changed)
// 	{
// 		ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
// 		img.has_changed = 1;
// 	}
// 	points = parsing(map_name, img.dims, img.angle, img.map);
// 	img.points = &points;
// 	plot_points(img, points, *img.dims, *img.map);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	render_texts(img);
// 	// ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
// 	free(map_name);
// 	return (0);
// }

// int dezoom(t_data img)
// {
// 	char	*map_name;
// 	int		***points;

// 	map_name = ft_strdup(*img.map_name);
// 	(*img.dims)[2] -= 2;
// 	clear_image(img);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	if (!img.has_changed)
// 	{
// 		ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
// 		img.has_changed = 1;
// 	}
// 	points = parsing(map_name, img.dims, img.angle, img.map);
// 	img.points = &points;
// 	plot_points(img, points, *img.dims, *img.map);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	render_texts(img);
// 	// ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
// 	free(map_name);
// 	return (0);
// }