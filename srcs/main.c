/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/23 17:25:50 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main (void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Il est lent ce lait");
	mlx_hook(vars.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &vars);
	mlx_hook(vars.win, ON_DESTROY, NO_MASK, on_destroy, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, BUTTONPRESS_MASK, on_mouse_down, &vars);
	mlx_loop(vars.mlx);
	return (0);
}