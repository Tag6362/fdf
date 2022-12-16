/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 14:29:35 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_listener(int keycode, t_data *img)
{
	if (keycode == 65307)
		end_of_program(img);
	else if (keycode == 119)
		move_up(img);
	else if (keycode == 97)
		move_left(img);
	else if (keycode == 115)
		move_down(img);
	else if (keycode == 100)
		move_right(img);
	else if (keycode == 105) // I
		up_alt(img);
	else if (keycode == 111) // O
		down_alt(img);
	ft_printf("KEYCODE %d\n", keycode);
	return (0);
}

int	on_destroy(t_data *img)
{
	end_of_program(img);
	return (0);
}

int mouse_listener(int button, int x, int y, t_data *img)
{
	if (button != 2)
		mouse_func(img, button, x, y);
	return (0);
}
