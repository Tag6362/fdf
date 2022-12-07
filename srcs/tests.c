/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:06:57 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 14:10:35 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    line_test(int *p1, int *p2, t_data *img)
{

    p1[0] = 400;
    p1[1] = 400;
	p2[0] = 10;
	p2[1] = 10;
	while (p2[0] <= 800)
	{
        plot_line(img, p1, p2, 0xFFFFFF);
		++(p2[0]);
	}
	while (p2[1] <= 800)
	{
        plot_line(img, p1, p2, 0xFFFFFF);
		++(p2[1]);
	}
	while (p2[0] >= 10)
	{
        plot_line(img, p1, p2, 0xFFFFFF);
		--(p2[0]);
	}
	while (p2[1] >= 10)
	{
        plot_line(img, p1, p2, 0xFFFFFF);
		--(p2[1]);
	}
}

void	print_tab_3(int ***points, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%d,%d ", points[i][j][0], points[i][j][1]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}