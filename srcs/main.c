/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/01 16:28:04 by tgernez          ###   ########.fr       */
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

// int	**get_plan_points(int hyp, int line_number, int line_len, int *start_point)
// {
// 	int	**tab_points;
// 	int	i;
// 	//ADD INIT FOR TAB[0] and TAB[1] from STARTPOINT
// 	tab_points = ft_calloc_int_tab_2(2, 2);
// 	if (!tab_points)
// 		return (NULL);
// 	tab_points[0][0] = start_point[0];
// 	tab_points[0][1] = start_point[1];
// 	tab_points[1][0] = start_point[0];
// 	tab_points[1][1] = start_point[1];
// 	i = 0;
// 	while (i++ < line_len)
// 	{
// 		tab_points[0][0] -= hyp * 0.866;
// 		tab_points[0][1] += hyp / 2;
// 	}
// 	i = 0;
// 	while (i++ < line_number)
// 	{
// 		tab_points[1][0] += hyp * 0.866;
// 		tab_points[1][1] += hyp / 2;
// 	}
// 	return (tab_points);
// }


void    line_test(int *p1, int *p2, t_data *img)
{

    p1[0] = 400;
    p1[1] = 400;

	p2[0] = 10;
	p2[1] = 10;
	while (p2[0] <= 800)
	{
        plot_line(img, p1, p2, 0xFFFFFF);

		++(p2[0]);
	}
	while (p2[1] <= 800)
	{
        plot_line(img, p1, p2, 0xFFFFFF);

		++(p2[1]);
	}
	while (p2[0] >= 10)
	{
        plot_line(img, p1, p2, 0xFFFFFF);

		--(p2[0]);
	}
	while (p2[1] >= 10)
	{
        plot_line(img, p1, p2, 0xFFFFFF);

		--(p2[1]);
	}
	// while (p2[1])
    
}

int main (int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_point	*map;
	int		line_number;
	int		line_len;
	int		**points;

	int hyp = 50;
	int *a;
	int *b;
	// int c[2];
	int dimensions[3];
	
	a = malloc(sizeof(int) * 2);
	b = malloc(sizeof(int) * 2);

	// c[0] = a[0];
	// c[1] = a[1];

	if (ac > 1)
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, WINDOW_X, WINDOW_Y, "Il est lent ce lait");
		img.img = mlx_new_image(vars.mlx, WINDOW_X, WINDOW_Y);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
		line_test(a, b, &img);
		// map = parsing(av[1], &line_number, &line_len);
		// tab_points = get_plan_points(hyp, line_number, line_len, a);
		// b[0] = tab_points[0][0];
		// b[1] = tab_points[0][1];
		// c[0] = tab_points[1][0];
		// c[1] = tab_points[1][1];
		// ft_printf("C[x]=%d, C[y]=%d\n", c[0], c[1]);
		// dimensions[0] = line_number;
		// dimensions[1] = line_len;
		// dimensions[2] = 20; //SCALE
		// points = create_tab(hyp, dimensions, a, map);
		// read_tab_test(points, dimensions);
		// plot_map(img, map, dimensions, hyp, points);
		// create_map(hyp, dimensions, a, img, map);
		// plot_line(img, b, a, 0xFFFFFF); //BLEU
		// plot_line(img, a, c, 0xFFFFFF); //JAUNE
		// int i = 0;
		// while (i < line_number)
		// {
		// 	// ft_printf("A[x]=%d, A[y]=%d\n", a[0], a[1]);
		// 	// ft_printf("B[x]=%d, B[y]=%d\n", b[0], b[1]);
		// 	a[0] += hyp * 0.866;
		// 	a[1] += hyp / 2;
		// 	b[0] += hyp * 0.866;
		// 	b[1] += hyp / 2;
		// 	plot_line(img, b, a, 0xFFFFFF);
		// 	i++;
		// }
		// a[0] = 600;
		// a[1] = 100;
		// i = 0;
		// while (i < line_len)
		// {
		// 	ft_printf("A[x]=%d, A[y]=%d\n", a[0], a[1]);
		// 	ft_printf("C[x]=%d, C[y]=%d\n", c[0], c[1]);
		// 	a[0] -= hyp * 0.866;
		// 	a[1] += hyp / 2;
		// 	c[0] -= hyp * 0.866;
		// 	c[1] += hyp / 2;
		// 	plot_line(img, a, c, 0xFFFFFF);
		// 	i++;
		// }
		// b[0] = 650;
		// b[1] = 310;
		// plot_line(img, a, b , 0xFFFFFF);
		// b[0] = 650;
		// b[1] = 290;
		// plot_line(img, a, b , 0xFFFFFF);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &vars);
		mlx_hook(vars.win, ON_DESTROY, NO_MASK, on_destroy, &vars);
		free(map);
		mlx_loop(vars.mlx);
	}
	else
		ft_printf("Provide a map name please\n");
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
// 	int hyp = 30;
// 	int line_number;
// 	int line_len;
// 	int	i;
// 	int j;
// 	int ind;
// 	int p1[2];
// 	int p2[2];
// 	int tmp[2];
// 	int color = 0xFFFFFF;

// 	i = 0;
// 	j = 0;
// 	if (ac > 1)
// 	{
// 		vars.mlx = mlx_init();
// 		vars.win = mlx_new_window(vars.mlx, WINDOW_X, WINDOW_Y, "Il est lent ce lait");
// 		img.img = mlx_new_image(vars.mlx, WINDOW_X, WINDOW_Y);
// 		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);	
// 		map = parsing(av[1], &line_number, &line_len);
// 		while (i < line_number)
// 		{
// 			j = 0;
// 			p1[0] = 100 + hyp * i;
// 			p1[1] = 333 + 18 * i;
// 			while (j < line_len)
// 			{
// 				p2[0] = p1[0] + hyp * 0.866;
// 				p2[1] = p1[1] - hyp / 2;
// 				if (j == 0)
// 				{
// 					tmp[0] = p1[0];
// 					tmp[1] = p1[1];
// 				}
// 				// printf("P1[0]: %d\n", p1[0]);
// 				ind = i * line_len + j;
// 				plot_line(img, p1, p2, color--);
// 				p1[0] = p2[0];
// 				p1[1] = p2[1];	
// 				j++;
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		j = 0;
// 		hyp = sqrt(power(tmp[0] - 100, 2) + power(tmp[1] - 133, 2)) 
// 			/ (line_number);
// 		printf("HYPO %d HYPO \n", hyp);
// 		p1[0] = 100;
// 		p1[1] = 333;
// 		p2[0] = tmp[0];
// 		p2[1] = tmp[1];
// 		plot_line(img, p1, p2, 0xFF0000);
// 		printf("Line len is %d\n", line_len);
// 		while (i < line_len - 1)
// 		{
// 			p1[0] += hyp * 0.866;
// 			p1[1] -= hyp / 2;
// 			p2[0] += hyp * 0.866;
// 			p2[1] -= hyp / 2;
// 			printf("I %d /I\n", i);
// 			plot_line(img, p1, p2, 0xFF0000); 
// 			i++;
// 		}
// 		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 		mlx_hook(vars.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &vars);
// 		mlx_hook(vars.win, ON_DESTROY, NO_MASK, on_destroy, &vars);
// 		free(map);
// 		mlx_loop(vars.mlx);
// 	}
// 	return (0);
// }

