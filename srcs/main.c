/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/23 15:20:19 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main (void)
{
	int		*p1;
	int		*p2;
	int		color;
	t_data	img;
	t_vars	vars;


	p1 = malloc(sizeof (int) * 2);
	p2 = malloc(sizeof (int) * 2);
	if (!p1 || !p2)
		return (-1);
	
	p1[0] = 0;
	p1[1] = 0;

	p2[0] = 1920;
	p2[1] = 1080;

	
	color = 0x00FF0000;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Il est lent ce lait");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	plotLine(img, p1, p2, color); //Bresenham Algortihm
	p1[0] = 0;
	p1[1] = 1080;
	p2[0] = 1920;
	p2[1] = 0;
	plotLine(img, p1, p2, color); //Bresenham Algortihm
	// write(1, "aaaa\n", 5);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}