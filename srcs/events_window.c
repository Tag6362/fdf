/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 17:13:04 by tgernez          ###   ########.fr       */
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
{;
	if (button != 2)
		mouse_func(img, button, x, y);
	return (0);
}
