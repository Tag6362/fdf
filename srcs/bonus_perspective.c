/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_perspective.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:09:39 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 14:09:55 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	basic_placing(int ***points, int height, int width, int *to_define)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	hyp;

	i = 0;
	x = to_define[0];
	y = to_define[1];
	hyp = to_define[2];
	while (i < height)
	{
		j = 0;
		x = to_define[0];
		while (j < width)
		{
			points[i][j][0] = x;
			points[i][j][1] = y;
			x += hyp;
			j++;
		}
		y += hyp;
		i++;
	}
}
