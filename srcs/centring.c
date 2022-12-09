/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:18:16 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 12:30:49 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*find_dims(t_point **map, int height, int width, t_data *img)
{
	int dims[3];
	int	x;
	int	y;
	int	hyp;
	int hyp2;
	int	i;
	int	j;
	int ratio;

	x = WINDOW_X * (1.0 / 8.0);
	y = WINDOW_Y * (7.0 / 8.0);
	hyp = 1;
	hyp2 = 1;
	if (height > width)
		ratio = height / width;
	else
		ratio = width / height;
	while (2 * width * (cos(img->angle) * hyp) < WINDOW_X - x)
	{
		hyp++;	
	}
	(*(img->dims))[2] = hyp;
	ft_printf("%dx%d with hyp %d\n", x, y, hyp);
}
