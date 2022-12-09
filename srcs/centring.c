/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:18:16 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 16:48:04 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int find_x_hyp(int height, int width, t_data *img)
{
	int	hyp;
	int ratio;
	
	hyp = 1;
	if (height > width)
		ratio = 1 + height / width;
	else
		ratio = 1 + width / height;
	while (ratio * width * (cos(img->angle) * hyp) < WINDOW_X - img->x)
	{
		hyp++;	
	}
	return (hyp);
}

int	*find_dims(t_point **map, int height, int width, t_data *img)
{
	img->x = WINDOW_X * (1.0 / 8.0);
	img->y = WINDOW_Y * (7.0 / 8.0);
	(*(img->dims))[2] = find_x_hyp(height, width, img);
	return (0);
	// ft_printf("%dx%d with hyp %d\n", x, y, hyp);
}
