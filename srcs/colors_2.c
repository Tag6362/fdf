/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:22:17 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/23 14:33:32 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	add_shade(int trgb, float shade)
{
	int	r;
	int	g;
	int	b;

	r = ((unsigned char *)&trgb)[2] * (1 - shade);
	g = ((unsigned char *)&trgb)[1] * (1 - shade);
	b = ((unsigned char *)&trgb)[0] * (1 - shade);
	return (create_trgb(255, r, g, b));
}

int	color_opposite(int color)
{
	unsigned char	tab[4];

	tab[3] = 255;
	tab[2] = 255 - (color >> 16 & 0xFF);
	tab[1] = 255 - (color >> 8 & 0xFF);
	tab[0] = 255 -(color & 0xFF);
	return (*(int *)tab);
}

// int main(void)
// {
// 	int color = create_trgb(255, 0xff, 0xff, 0xff);

// 	printf("%x", add_shade(color, 0.5));
// 	return (0);
// }