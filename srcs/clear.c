/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:48:22 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 16:48:51 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_data img, int *dims)
{
	int	p1[2];
	int	p2[2];
	int	i;

	i = 0;
	p1[0] = 0;
	p1[1] = 0;
	p2[0] = dims[3];
	p2[1] = 0;
	while (i < dims[4])
	{
		plot_line(&img, p1, p2, 0x000000);
		p1[1]++;
		p2[1]++;
		i++;
	}
}

void	end_of_program(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	ft_free_int_tab_3(*(img->points), (*(img->dims))[0], (*(img->dims))[1]);
	free(*(img->dims));
	exit(0);
}
