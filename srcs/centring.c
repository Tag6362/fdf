/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:18:16 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 17:56:52 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int find_y_hyp(t_point **map, int height, int width, t_data *img)
{
	return (100000);
}


static int find_x_hyp(int height, int width, t_data *img)
{
	int	hyp;
	int ratio;
	
	hyp = 1;
	if (height > width)
		ratio = 1 + height / width;
	else
		ratio = 1 + width / height;
	while (ratio * width * (cos(img->angle) * hyp) < WINDOW_X - img->x)
	{
		hyp++;	
	}
	return (hyp);
}

int	***init_tab(t_point ***map, int **dims, t_data *img, const char *map_name)
{
	char	*path;
	int 	***points;
	int		*height;
	int 	*width;
	int		hyp;

	height = &((*dims)[0]);
	width = &((*dims)[1]);
	path = ft_strjoin("test_maps/", map_name);
	ft_printf("Accessing %s...\n", path);
	if (get_height(path, height) == -2 || get_width(path, width) == -2)
		return (perror("Problem in file\n"), free(path), NULL);
	ft_printf("%dx%d\n", *height, *width);
	*map = map_making(path, *dims, 1);
	free(path);
	points = ft_calloc_int_tab_3(*height, *width, 2);
	if (!points)
		return (perror("Problem with creating tab"), free(path), NULL);
	img->x = WINDOW_X * (1.0 / 8.0);
	img->y = WINDOW_Y * (7.0 / 8.0);
	(*(img->dims))[2] = find_x_hyp(*height, *width, img);
	hyp = find_y_hyp(*map, *height, *width, img);
	if (hyp < (*(img->dims))[2])
		(*(img->dims))[2] = hyp;
	points[0][0][0] = img->x;
	points[0][0][1] = img->y;
	return (points);
	// ft_printf("%dx%d with hyp %d\n", x, y, hyp);
}
