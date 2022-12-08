/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/08 15:00:03 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_listener(int keycode, t_data *img)
{
	if (keycode == 65307)
		return (mlx_destroy_window(img->mlx, img->win), exit(0), 0);
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
	// if (button == 1) //Left Click
	// 	zoom(void);
	// if (button == 3) //Right Click
	// 	dezoom(void);
	if (button == 4) // Scroll Up
		up_alt(*img);
	// if (button == 5) // Scroll Down
	// 	down_alt(*img);
	ft_printf("%d\n", button);
	return (0);
}

// int on_mouse_down(int button, int x, int y, t_vars *vars)
// {

// 	return (0);
// }