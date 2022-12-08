/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:48:22 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/08 14:58:51 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void clear_image(t_data img)
{
	int	p1[2];
	int	p2[2];
	int	i;

	i = 0;
	p1[0] = 0;
	p1[1] = 0;
	p2[0] = WINDOW_X;
	p2[1] = 0;
	while (i < WINDOW_Y)
	{
		plot_line(&img, p1, p2, 0x000000);
		p1[1]++;
		p2[1]++;
		i++;
	}
}