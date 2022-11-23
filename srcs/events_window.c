/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/23 17:47:22 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_listener(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		return (mlx_destroy_window(vars->mlx, vars->win), exit(0), 0);
	return (0);
}

int on_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int on_mouse_down(int button, int x, int y, t_vars *vars)
{
	t_data		img;
	static int	p1[2];
	static int	p2[2];
	int			color = 0x00FF0000;

	printf("%d\n", button);
	if (button == 1)
	{
		p1[0] = x;
		p1[1] = y;
	}
	if (button == 3)
	{
		p2[0] = x;
		p2[1] = y;
	}
	if (p1[0] != 0 && p1[0] != 0)
	{
		
		img.img = mlx_new_image(vars->mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
		plotLine(img, p1, p2, color); //Bresenham Algortihm
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	}
	return (0);
}