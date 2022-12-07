/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:18:16 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 15:52:08 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int *find_start_coords(t_point **map, int height, int width, double angle)
{
	int	x;
	int	y;
	int	hyp;
	int	i;

	x = WINDOW_X * (1.0 / 8.0);
	y = WINDOW_Y * (7.0 / 8.0);
	hyp = 1;
	while (2 * (cos(angle) * hyp) < WINDOW_X - x) // 2 is arbritrary, consider a ratop between height and width instea
	{
		hyp++;	
	}
	ft_printf("%dx%d", x, y);
}