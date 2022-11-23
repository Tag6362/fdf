/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:22:17 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/23 14:31:21 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb >> 24 & 0xFF);
}

int	get_r(int trgb)
{
	return (trgb >> 16 & 0xFF);
}

int	get_g(int trgb)
{
	return (trgb >> 8 & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

// int main(void)
// {
// 	int color = create_trgb(255, 0x10, 0x20, 0x30);

// 	printf("%x", color_opposite(color));
// 	return (0);

// }