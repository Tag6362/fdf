/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:31 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 15:12:54 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_maker(char *info, t_point *point)
{
	char	**tmp;

	tmp = ft_split(info, ',');
	if (!tmp[1])
		point->color = 0xFFFFFF;
	else
		point->color = ft_atou_hexa(tmp[1]);
	point->alt = ft_atoi(tmp[0]);
	ft_free_strs(tmp);
}

t_point	**map_making(char *path, int *dims, int fd)
{
	int		i;
	int		j;
	t_point	**map;
	char	*line;
	char	**splitted_line;

	map = map_malloc(dims[0], dims[1]);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (i < dims[0])
	{
		j = -1;
		line = get_next_line(fd);
		splitted_line = ft_split(line, ' ');
		while (++j < dims[1])
			pixel_maker(splitted_line[j], &map[i][j]);
		free(line);
		ft_free_strs(splitted_line);
		i++;
	}
	return (close(fd), map);
}

static void	iso_aux(int ***pts, int *dims, double ang, int *i)
{
	if (i[0] == 0)
	{
		if (i[1] != 0)
		{			
			pts[i[0]][i[1]][0] = pts[i[0]][i[1] - 1][0] + dims[2] * cos(ang);
			pts[i[0]][i[1]][1] = pts[i[0]][i[1] - 1][1] - dims[2] * sin(ang);
		}
	}
	else
	{
		if (i[1] == 0)
		{
			pts[i[0]][i[1]][0] = pts[i[0] - 1][i[1]][0] + dims[2] * cos(ang);
			pts[i[0]][i[1]][1] = pts[i[0] - 1][i[1]][1] + dims[2] * sin(ang);
		}
		else
		{
			pts[i[0]][i[1]][0] = pts[i[0]][i[1] - 1][0] + dims[2] * cos(ang);
			pts[i[0]][i[1]][1] = pts[i[0]][i[1] - 1][1] - dims[2] * sin(ang);
		}
	}
}

void	iso(int ***pts, int *dims, double ang)
{
	int	i;
	int	j;
	int	ind[2];

	i = 0;
	while (i < dims[0])
	{
		j = 0;
		while (j < dims[1])
		{
			ind[0] = i;
			ind[1] = j;
			iso_aux(pts, dims, ang, ind);
			j++;
		}
		i++;
	}
}

void	alt_adding(int ***pts, int *dims, t_point **map, int scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < dims[0])
	{
		j = 0;
		while (j < dims[1])
		{
			pts[i][j][1] -= map[i][j].alt * scale;
			j++;
		}
		i++;
	}
}
