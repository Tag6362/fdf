/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:32:28 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/08 14:48:17 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int up_alt(t_data img)
{
	char *map_name;

	map_name = ft_strdup(*img.map_name);
	glo_scale(1);
	parsing(*img.map_name, img.dims, img.angle, img.map);
	clear_image(img);
	ft_free_int_tab_3(*img.points, (*img.dims)[0], (*img.dims)[1]);
	free(*img.dims);
	free(map_name);
	return (0);
}
