/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 15:41:19 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_listener(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
		return (0);
	}
	return (0);
}

int	on_destroy(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
	return (0);
}

int mouse_listener(int button, int x, int y, t_data *img)
{
	(void) x;
	(void) y;
	if (button == 1)
		zoom(img);
	if (button == 3)
		dezoom(img);
	if (button == 4)
		up_alt(img);
	if (button == 5) 
		down_alt(img);
	return (0);
}
