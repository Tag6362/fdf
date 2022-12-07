/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 15:04:04 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_listener(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		return (mlx_destroy_window(vars->mlx, vars->win), exit(0), 0);
	return (0);
}

int	on_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

// int on_mouse_down(int button, int x, int y, t_vars *vars)
// {

// 	return (0);
// }