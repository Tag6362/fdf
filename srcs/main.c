/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/08 14:11:41 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void create_window_and_image(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WINDOW_X, WINDOW_Y, "C'est court");
	img->img = mlx_new_image(img->mlx, WINDOW_X, WINDOW_Y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->end);
}

void image_and_hooks(t_data img)
{
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_string_put(img.mlx, img.win, 0, 10, 0xFFFFFF, "===Keys===");
	mlx_string_put(img.mlx, img.win, 0, 25, 0xFFFFFF, "ESC to quit");
	mlx_string_put(img.mlx, img.win, 0, 40, 0xFFFFFF, "Scroll Up to Alt++");
	mlx_string_put(img.mlx, img.win, 0, 55, 0xFFFFFF, "Scroll Down to Alt--");
	mlx_string_put(img.mlx, img.win, 0, 70, 0xFFFFFF, "Left Click to Zoom");
	mlx_string_put(img.mlx, img.win, 0, 85, 0xFFFFFF, "Right Click to Dezoom");
	mlx_hook(img.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &img);
	mlx_mouse_hook(img.win, mouse_listener, &img);
	mlx_hook(img.win, ON_DESTROY, NO_MASK, on_destroy, &img);
	mlx_loop(img.mlx);
}

int	init(char *map_name)
{
	t_data	img;
	t_point	**map;
	int		***points;
	int		*dims;
	
	img.angle = (30 * PI) / 180;
	img.dims = &dims;
	img.map = &map;
	img.points = &points;
	img.map_name = &map_name;
	dims = malloc(sizeof(int) * 3);
	if (!dims)
		return (-1);
	create_window_and_image(&img);
	points = parsing(map_name, &dims, img.angle, &map);
	plot_points(img, points, dims, map);
	find_start_coords(map, dims[0], dims[1], img.angle);
	image_and_hooks(img);
	free(dims);
}

int main (int ac, char **av)
{
	if (ac > 1)
		init(av[1]);
	else
		ft_printf("Provide a map name please\n");
	return (0);
}
