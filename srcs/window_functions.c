/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:37:39 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 17:34:19 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_texts(t_data img)
{
	mlx_string_put(img.mlx, img.win, 0, 10, 0xFFFFFF, "===Keys===");
	mlx_string_put(img.mlx, img.win, 0, 25, 0xFFFFFF, "ESC to quit");
	mlx_string_put(img.mlx, img.win, 0, 40, 0xFFFFFF, "Scroll change zoom");
	mlx_string_put(img.mlx, img.win, 0, 55, 0xFFFFFF, "L/R Click to Move");
	mlx_string_put(img.mlx, img.win, 0, 70, 0xFFFFFF, "I/O to change altitude");
	mlx_string_put(img.mlx, img.win, 0, 85, 0xFFFFFF, "K/L to change rotation");
	mlx_string_put(img.mlx, img.win, 0, 100, 0xFFFFFF, "</> to change color");
	mlx_string_put(img.mlx, img.win, 0, 115, 0xFFFFFF, "WASD to keyboard move");
}
