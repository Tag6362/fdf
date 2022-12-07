/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 15:03:20 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main (int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_point	**map;
	int		height;
	int		width;
	int		***points;

	int *a;
	int dims[3];
	
	a = malloc(sizeof(int) * 2);
	if (ac > 1)
	{
		a[0] = 600;
		a[1] = 600;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, WINDOW_X, WINDOW_Y, "Il est lent ce lait");
		img.img = mlx_new_image(vars.mlx, WINDOW_X, WINDOW_Y);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
		points = parsing(av[1], &height, &width, &map);
		dims[0] = height;
		dims[1] = width;
		plot_points(img, points, dims, map);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &vars);
		mlx_hook(vars.win, ON_DESTROY, NO_MASK, on_destroy, &vars);
		mlx_loop(vars.mlx);
	}
	else
		ft_printf("Provide a map name please\n");
	free(a);
	return (0);
}
