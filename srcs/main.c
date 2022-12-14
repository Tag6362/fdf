/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:53:46 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/16 19:16:10 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	create_window_and_image(t_data *img, int *dims)
{
	img->mlx = mlx_init();
	mlx_get_screen_size(img->mlx, &(dims[3]), &(dims[4]));
	img->win = mlx_new_window(img->mlx, dims[3], dims[4], "FDF Tgernez");
	img->img = mlx_new_image(img->mlx, dims[3], dims[4]);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->end);
	if (!(img->mlx || img->win || img->img || img->addr))
		return (0);
	return (1);
}

static void	image_and_hooks(t_data img)
{
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	render_texts(img);
	mlx_hook(img.win, ON_KEYDOWN, KEYPRESS_MASK, key_listener, &img);
	mlx_mouse_hook(img.win, mouse_listener, &img);
	mlx_hook(img.win, ON_DESTROY, NO_MASK, on_destroy, &img);
	mlx_loop(img.mlx);
}

static void	init_aux(t_data img, int ***points, int *dims, t_point **map)
{
	iso(points, dims, img.angle);
	alt_adding(points, dims, map, glo_scale(0));
	plot_points(img, points, dims);
	image_and_hooks(img);
}

static int	init(char *map_name)
{
	t_data	img;
	t_point	**map;
	int		***points;
	int		*dims;

	points = NULL;
	map = NULL;
	img.angle = (30 * PI) / 180;
	img.map = &map;
	img.points = &points;
	img.map_name = &map_name;
	dims = malloc(sizeof(int) * 5);
	if (!dims)
		return (-1);
	img.dims = &dims;
	if (!create_window_and_image(&img, dims))
		return (end_of_program(&img), -1);
	points = init_tab(&map, &dims, &img, map_name);
	if (!points)
		return (-1);
	init_aux(img, points, dims, map);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		init(av[1]);
	else
		ft_printf("Provide a map name please\n");
	return (0);
}
