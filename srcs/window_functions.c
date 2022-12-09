/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:37:39 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 10:46:10 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void render_texts(t_data img)
{
	ft_printf("Rendering Texts\n");
	mlx_string_put(img.mlx, img.win, 0, 10, 0xFFFFFF, "===Keys===");
	mlx_string_put(img.mlx, img.win, 0, 25, 0xFFFFFF, "ESC to quit");
	mlx_string_put(img.mlx, img.win, 0, 40, 0xFFFFFF, "Scroll Up to Alt++");
	mlx_string_put(img.mlx, img.win, 0, 55, 0xFFFFFF, "Scroll Down to Alt--");
	mlx_string_put(img.mlx, img.win, 0, 70, 0xFFFFFF, "Left Click to Zoom");
	mlx_string_put(img.mlx, img.win, 0, 85, 0xFFFFFF, "Right Click to Dezoom");
}