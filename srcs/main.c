/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/25 19:48:43 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void grid_printing(t_data img)
{
	int	i;
	int	j;
	int p1[2];
	int p2[2];
		
	j = 0;
	while (j < 1080)
	{
		p1[0] = 0;
		p1[1] = j;
		p2[0] = 1920;
		p2[1] = j;
		plot_line(img, p1, p2, 0x00FF0000);
		j += 100;
	}
	i = 1920;
	while (i > 0)
	{
		p1[0] = i;
		p1[1] = 1080;
		p2[0] = i;
		p2[1] = 0;
		plot_line(img, p1, p2, 0x00FF0000);
		i -= 100;
	}
}

int main (void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Il est lent ce lait");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	int p1[2];
	int p2[2];
	int hyp;

	hyp = 200;
	p1[0] = 500;
	printf("P1[0]:%d\n", p1[0]);
	p1[1] = 700;
	printf("P1[1]:%d\n", p1[1]);

	p2[0] = p1[0] + cos(0.524) * hyp;
	printf("P2[0]:%d\n", p2[0]);
	p2[1] = p1[1] + sin(0.524) * hyp;
	printf("P2[1]:%d\n", p2[1]);
	plot_line(img, p1, p2, 0xFFFFFF);
	printf("----------------------\n");

	p1[0] = p2[0];
	printf("P1[0]:%d\n", p1[0]);
	p1[1] = p2[1];
	printf("P1[1]:%d\n", p1[1]);


	p2[0] = p1[0] + cos(0.524) * hyp;
	printf("P2[0]:%d\n", p2[0]);
	p2[1] = p1[1] + sin(-0.524) * hyp;
	printf("P2[1]:%d\n", p2[1]);
	plot_line(img, p1, p2, 0xFFFFFF);
	printf("----------------------\n");

	p1[0] = 500;
	printf("P1[0]:%d\n", p1[0]);
	p1[1] = 700;
	printf("P1[1]:%d\n", p1[1]);

	p2[0] = p1[0] + cos(0.524) * hyp;
	printf("P2[0]:%d\n", p2[0]);
	p2[1] = p1[1] - sin(0.524) * hyp;
	printf("P2[1]:%d\n", p2[1]);
	plot_line(img, p1, p2, 0xFFFFFF);
	printf("----------------------\n");

	p1[0] = p2[0];
	printf("P1[0]:%d\n", p1[0]);
	p1[1] = p2[1];
	printf("P1[1]:%d\n", p1[1]);


	p2[0] = p1[0] + cos(0.524) * hyp;
	printf("P2[0]:%d\n", p2[0]);
	p2[1] = p1[1] + sin(0.524) * hyp;
	printf("P2[1]:%d\n", p2[1]);
	plot_line(img, p1, p2, 0xFFFFFF);
	printf("----------------------\n");

	







	p1[0] = 500;
	printf("P1[0]:%d\n", p1[0]);
	p1[1] = 800;
	printf("P1[1]:%d\n", p1[1]);

	p2[0] = p1[0] + cos(0.524) * hyp;
	printf("P2[0]:%d\n", p2[0]);
	p2[1] = p1[1] + sin(0.524) * hyp;
	printf("P2[1]:%d\n", p2[1]);
	plot_line(img, p1, p2, 0xFFFFFF);
	printf("----------------------\n");

	p1[0] = p2[0];
	printf("P1[0]:%d\n", p1[0]);
	p1[1] = p2[1];
	printf("P1[1]:%d\n", p1[1]);


	p2[0] = p1[0] + cos(0.524) * hyp;
	printf("P2[0]:%d\n", p2[0]);
	p2[1] = p1[1] + sin(-0.524) * hyp;
	printf("P2[1]:%d\n", p2[1]);
	plot_line(img, p1, p2, 0xFFFFFF);
	printf("----------------------\n");

	p1[0] = 500;
	printf("P1[0]:%d\n", p1[0]);
	p1[1] = 800;
	printf("P1[1]:%d\n", p1[1]);

	p2[0] = p1[0] + cos(0.524) * hyp;
	printf("P2[0]:%d\n", p2[0]);
	p2[1] = p1[1] - sin(0.524) * hyp;
	printf("P2[1]:%d\n", p2[1]);
	plot_line(img, p1, p2, 0xFFFFFF);
	printf("----------------------\n");

	p1[0] = p2[0];
	printf("P1[0]:%d\n", p1[0]);
	p1[1] = p2[1];
	printf("P1[1]:%d\n", p1[1]);


	p2[0] = p1[0] + cos(0.524) * hyp;
	printf("P2[0]:%d\n", p2[0]);
	p2[1] = p1[1] + sin(0.524) * hyp;
	printf("P2[1]:%d\n", p2[1]);
	plot_line(img, p1, p2, 0xFFFFFF);
	printf("----------------------\n");

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &vars);
	mlx_hook(vars.win, ON_DESTROY, NO_MASK, on_destroy, &vars);
	// mlx_hook(vars.win, ON_MOUSEDOWN, BUTTONPRESS_MASK, on_mouse_down, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

// void grid_printing(t_data img)
// {
// 	int	i;
// 	int	j;
// 	int p1[2];
// 	int p2[2];
		
// 	j = 0;
// 	while (j < 1080)
// 	{
// 		p1[0] = 0;
// 		p1[1] = j;
// 		p2[0] = 1920;
// 		p2[1] = j;
// 		plot_line(img, p1, p2, 0x00FF0000);
// 		j += 100;
// 	}
// 	i = 1920;
// 	while (i > 0)
// 	{
// 		p1[0] = i;
// 		p1[1] = 1080;
// 		p2[0] = i;
// 		p2[1] = 0;
// 		plot_line(img, p1, p2, 0x00FF0000);
// 		i -= 100;
// 	}
// }

// int main (void)
// {
// 	t_vars	vars;
// 	t_data	img;


// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Il est lent ce lait");
// 	img.img = mlx_new_image(vars.mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
// 	grid_printing(img);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_hook(vars.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &vars);
// 	mlx_hook(vars.win, ON_DESTROY, NO_MASK, on_destroy, &vars);
// 	mlx_hook(vars.win, ON_MOUSEDOWN, BUTTONPRESS_MASK, on_mouse_down, &vars);
// 	mlx_loop(vars.mlx);
// 	return (0);
// }