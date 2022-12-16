/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 16:46:51 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_listener(int keycode, t_data *img)
{
	if (keycode == 65307)
		end_of_program(img);
	else if (keycode == 119 || keycode == 97
		|| keycode == 115 || keycode == 100)
		keyboard_move(img, keycode);
	else if (keycode == 105 || keycode == 111)
		keyboard_alt(img, keycode);
	else if (keycode == 107 || keycode == 108)
		keyboard_perspective(img, keycode);
	else if (keycode == 44 || keycode == 46)
		keyboard_color(img, keycode);
	return (0);
}

int	on_destroy(t_data *img)
{
	end_of_program(img);
	return (0);
}

int	mouse_listener(int button, int x, int y, t_data *img)
{
	if (button != 2)
		mouse_func(img, button, x, y);
	return (0);
}
