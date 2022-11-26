/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/26 03:00:51 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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
// 		i -= 500;
// 	}
// }

int main (int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_point *map;
	int hyp = 50;
	int line_number;
	int line_len;
	int	i;
	int j;
	int p1[2];
	int p2[2];

	i = 0;
	j = 0;
	if (ac > 1)
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, WINDOW_X, WINDOW_Y, "Il est lent ce lait");
		img.img = mlx_new_image(vars.mlx, WINDOW_X, WINDOW_Y);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);	
		map = parsing(av[1], &line_number, &line_len);
		ft_printf("Map size: %dx%d\n", line_len, line_number);
		p1[0] = 100;
		p1[1] = 333;
		p2[1] = 533;
		while (i < line_number)
		{
			j = 0;
			while (j < line_len)
			{
				p2[0] = p1[0] + hyp * 0.866;
				p2[1] = p2[1] + hyp / 2;
				printf("P1[0]: %d\n", p1[0]);
				plot_line(img, p1, p2, 0xFFFFFF);
				p1[0] = p2[0];
				p2[1] = p2[1];
				j++;
			}
			i++;
			p1[0] = 100 + hyp * i;
			p1[1] = 333 - 8 * i;

		}
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &vars);
		mlx_hook(vars.win, ON_DESTROY, NO_MASK, on_destroy, &vars);
		free(map);
		mlx_loop(vars.mlx);
	}
	return (0);
}


// // void grid_printing(t_data img)
// // {
// // 	int	i;
// // 	int	j;
// // 	int p1[2];
// // 	int p2[2];
		
// // 	j = 0;
// // 	while (j < 1080)
// // 	{
// // 		p1[0] = 0;
// // 		p1[1] = j;
// // 		p2[0] = 1920;
// // 		p2[1] = j;
// // 		plot_line(img, p1, p2, 0x00FF0000);
// // 		j += 100;
// // 	}
// // 	i = 1920;
// // 	while (i > 0)
// // 	{
// // 		p1[0] = i;
// // 		p1[1] = 1080;
// // 		p2[0] = i;
// // 		p2[1] = 0;
// // 		plot_line(img, p1, p2, 0x00FF0000);
// // 		i -= 500;
// // 	}
// // }

// int main (int ac, char **av)
// {
// 	t_vars	vars;
// 	t_data	img;
// 	t_point *map;
// 	int line_number;
// 	int line_len;
// 	int	i;
// 	int	j;
// 	int p1[2];
// 	int p2[2];

// 	i = 0;
// 	j = 1;
// 	if (ac > 1)
// 	{
// 		vars.mlx = mlx_init();
// 		vars.win = mlx_new_window(vars.mlx, WINDOW_X, WINDOW_Y, "Il est lent ce lait");
// 		img.img = mlx_new_image(vars.mlx, WINDOW_X, WINDOW_Y);
// 		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);	
// 		mlx_hook(vars.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &vars);
// 		mlx_hook(vars.win, ON_DESTROY, NO_MASK, on_destroy, &vars);
// 		map = parsing(av[1], &line_number, &line_len);
// 		ft_printf("Map size: %dx%d\n", line_len, line_number);
// 		// printf("%X", (map + 99)->color);
// 		// while (i < line_len)
// 		// {
// 		// 	j = 1;
// 		// 	p1[1] = i * 10;
// 		// 	p2[1] = i * 10;
// 		// 	while (j < line_len + 1)
// 		// 	{
// 		// 		p1[0] = j * 10;
// 		// 		p2[0] = j * 20;
// 		// 		plot_line(img, p1, p2, (map + (j - 1) + (i - 1) * line_len)->color);
// 		// 		j++;
// 		// 	}
// 		// 	i++;
// 		// }
		
// 		// mlx_hook(vars.win, ON_MOUSEDOWN, BUTTONPRESS_MASK, on_mouse_down, &vars);
// 		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 		free(map);
// 		mlx_loop(vars.mlx);
// 	}
// 	return (0);
// }
