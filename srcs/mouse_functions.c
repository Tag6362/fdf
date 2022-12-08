/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:32:28 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/08 15:03:14 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int up_alt(t_data img)
{
	char	*map_name;
	int		***points;

	map_name = ft_strdup(*img.map_name);
	glo_scale(1);
	parsing(*img.map_name, img.dims, img.angle, img.map);
	clear_image(img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
	points = parsing(map_name, img.dims, img.angle, img.map);
	img.points = &points;
	free(*img.dims);
	free(map_name);
	return (0);
}
