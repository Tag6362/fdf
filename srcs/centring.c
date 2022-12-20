/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:18:16 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/20 11:43:59 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_y_hyp(int height, int width, t_data *img)
{
	int	hyp;
	int	ratio;

	hyp = 1;
	if (height > width)
		ratio = 1 + height / width;
	else
		ratio = 1 + width / height;
	while (ratio * width * (cos(PI / 2.0 - img->angle) * hyp) < img->y)
	{
		hyp++;
	}
	return (hyp);
}

static int	find_x_hyp(int height, int width, t_data *img, int *dims)
{
	int	hyp;
	int	ratio;

	hyp = 1;
	if (height > width)
		ratio = 1 + height / width;
	else
		ratio = 1 + width / height;
	while (ratio * width * (cos(img->angle) * hyp) < dims[3] - img->x)
	{
		hyp++;
	}
	return (hyp);
}

int	***init_tab(t_point ***map, int **dims, t_data *img, const char *map_name)
{
	int		***points;
	int		*height;
	int		*width;
	int		hyp;

	height = &((*dims)[0]);
	width = &((*dims)[1]);
	if (get_height(map_name, height) == -2 || get_width(map_name, width) == -2)
		return (perror("Problem in file\n"), end_of_program(img), NULL);
	*map = map_making(map_name, *dims, 1);
	points = ft_calloc_int_tab_3(*height, *width, 2);
	if (!(points && *map))
		return (perror("Problem in map/tab"), end_of_program(img), NULL);
	img->x = (*dims)[3] * (1.0 / 8.0);
	img->y = (*dims)[4] * (5.0 / 8.0);
	(*(img->dims))[2] = find_x_hyp(*height, *width, img, *dims);
	hyp = find_y_hyp(*height, *width, img);
	if (hyp <= 3 && (*(img->dims))[2] <= 3)
		(*(img->dims))[2] = 3;
	else if (hyp < (*(img->dims))[2])
		(*(img->dims))[2] = hyp;
	points[0][0][0] = img->x;
	points[0][0][1] = img->y;
	return (points);
}
