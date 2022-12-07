/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:38:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 13:56:35 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// t_point	*parsing(const char *map_name, int *height, int *width)
// {
// 	int		fd;
// 	t_point	*map;
// 	char	*path_to_map;

// 	*height = 0;
// 	*width = 0;
// 	path_to_map = ft_strjoin("test_maps/", map_name);
// 	ft_printf("Accessing %s...\n", path_to_map);
// 	if (get_line_number(path_to_map, height) == -2)
// 		return (ft_printf("Wrong path\n"), free(path_to_map), NULL);
// 	ft_printf("Done!\n");
// 	fd = open(path_to_map, O_RDONLY);
// 	mapper(fd, &map, height, width);
// 	close(fd);
// 	free(path_to_map);

// 	int i = 0;
// 	int j = 0;
// 	while (i < *height)
// 	{
// 		j = 0;
// 		while (j < *width)
// 		{
// 			ft_printf("%d ", (map + i * *height + j)->alt);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// 	return (map);
// }
static void	basic_placing(int ***points, int height, int width, int *to_define)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	hyp;

	i = 0;
	x = to_define[0];
	y = to_define[1];
	hyp = to_define[2];
	while (i < height)
	{
		j = 0;
		x = to_define[0];
		while (j < width)
		{
			points[i][j][0] = x;
			points[i][j][1] = y;
			x += hyp;
			j++;
		}
		y += hyp;
		i++;
	}
}

static void	print_tab_3(int ***points, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%d,%d ", points[i][j][0], points[i][j][1]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

// static void	iso(int ***points, int height, int width, int hyp, double angle)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			if (j == 0 && i > 0)
// 			{
// 				points[i][j][0] = points[i - 1][j][0] + hyp * cos(angle);
// 				ft_printf("Moved\n");
				
// 			}
// 			else if (i > 0)
// 				points[i][j][0] = points[i - 1][j][0] - hyp * cos(angle);
// 			else
// 				points[i][j][0] -= hyp * cos(angle);
// 			points[i][j][1] += hyp * sin(angle);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	auxiliary(int fd, int height, int width, int i, t_point **map)
// {
// 	int		j;
// 	char	*tmp;
// 	char	**strs;

// 	j = 0;
// 	tmp = get_next_line(fd);
// 	strs = ft_split(tmp, ' ');
// 	// ft_printf("Start loop\n");
// 	while (j < width)
// 	{
// 		pixel_maker(*map, width * i + j, strs[j]);
// 		j++;
// 	}
// 	// ft_printf("End loop\n");
// 	free(tmp);
// 	ft_free_strs(strs);
// }

// static int	mapper(int fd, t_point **map, int *height, int *width)
// {
// 	char	*tmp;
// 	char	**strs;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 0;
// 	tmp = get_next_line(fd);
// 	strs = ft_split(tmp, ' ');
// 	while (strs[*width])
// 		(*width)++;
// 	*map = ft_calloc(((*height) * (*width)), sizeof(t_point));
// 	if (!map)
// 		return (-2);
// 	while (j < (*width))
// 	{
// 		pixel_maker(*map, j, strs[j]);
// 		j++;
// 	}
// 	free(tmp);
// 	ft_free_strs(strs);
// 	ft_printf("Map size: %dx%d\n", *height, *width);
// 	while (++i < (*height))
// 		auxiliary(fd, (*height), (*width), i, map);
// 	return (1);
// }

static void	pixel_maker(char *info, t_point *point)
{
	char	**tmp;

	// ft_printf("INFO %s /INFO\n", info);
	tmp = ft_split(info, ',');
	if (!tmp[1])
		point->color = 0xFFFFFF;
	else
		point->color = ft_atou_hexa(tmp[1]);
	// ft_printf("IND %d /IND\n", ind);
	// ft_printf("VAL TMP %d\n", ft_atoi(tmp[0]));
	point->alt = ft_atoi(tmp[0]);
	ft_free_strs(tmp);
}

static t_point	**map_making(char *path, int *dims)
{
	int	i;
	int	j;
	t_point **map;
	char	*line;
	char	**splitted_line;
	int fd;

	map = map_malloc(dims[0], dims[1]);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (i < dims[0])
	{
		j = 0;
		// ft_printf("LINE %s /LINE\n", line);
		line = get_next_line(fd);
		splitted_line = ft_split(line, ' ');
		while (j < dims[1])
		{
			pixel_maker(splitted_line[j], &map[i][j]);
			// ft_printf("ALT i=%d, j=%d, %d\n", i, j, map[i][j].alt);
			j++;
		}
		free(line);
		ft_free_strs(splitted_line);
		i++;
	}
	close(fd);
	return (map);
}

static void	iso_aux(int ***pts, int *dims, double ang, int i, int j)
{
	if (i == 0)
	{
		if (j != 0)
		{			
			pts[i][j][0] = pts[i][j - 1][0] + dims[2] * cos(ang);
			pts[i][j][1] = pts[i][j - 1][1] - dims[2] * sin(ang); 
		}
	}
	else
	{
		if (j == 0)
		{
			pts[i][j][0] = pts[i - 1][j][0] + dims[2] * cos(ang);
			pts[i][j][1] = pts[i - 1][j][1] + dims[2] * sin(ang);

		}
		else
		{
			pts[i][j][0] = pts[i][j - 1][0] + dims[2] * cos(ang);
			pts[i][j][1] = pts[i][j - 1][1] - dims[2] * sin(ang); 

		}
	}
}

static void	iso(int ***pts, int *dims, double ang)
{
	int	i;
	int	j;

	i = 0;
	while (i < dims[0])
	{
		j = 0;
		while (j < dims[1])
		{
			iso_aux(pts, dims, ang, i, j);
			j++;
		}
		i++;
	}
}

static void alt_adding(int ***pts, int *dims, t_point **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < dims[0])
	{
		j = 0;
		while (j < dims[1])
		{
			// ft_printf("map[%d][%d].alt=%d\n", i, j, map[i][j].alt);
			pts[i][j][1] -= map[i][j].alt * 2;
			j++;
		}
		i++;
	}
}
// static void	print_tab_3(int ***points, int height, int width)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			ft_printf("%d,%d ", points[i][j][0], points[i][j][1]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }

static int	get_width(const char *path_to_map, int *width)
{
	int		fd;
	char	*buff;
	char	**buff_splitted;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		return (-2);
	buff = get_next_line(fd);
	buff_splitted = ft_split(buff, ' ');
	free(buff);
	*width = 0;
	while (buff_splitted[(*width)])
		(*width)++;
	while (buff)
	{
		buff = get_next_line(fd);
		free(buff);
	}
	ft_free_strs(buff_splitted);
	close(fd);
	return (1);
}

static int	get_height(const char *path_to_map, int *height)
{
	int		fd;
	char	*buff;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		return (-2);
	buff = get_next_line(fd);
	*height = 0;
	while (buff)
	{
		(*height)++;
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	close(fd);
	return (1);
}

int	***parsing(const char *map_name, int *height, int *width)
{
	char	*path;
	int		***points;
	t_point	**map;

	path = ft_strjoin("test_maps/", map_name);
	ft_printf("Accessing %s...\n", path);
	if (get_height(path, height) == -2 || get_width(path, width) == -2)
		return (perror("Problem in file\n"), free(path), NULL);
	ft_printf("%dx%d\n", *height, *width);
	points = ft_calloc_int_tab_3(*height, *width, 2);
	if (!points)
		return (perror("Problem with creating tab"), free(path), NULL);
	

	int		to_define[3];
	int		dims[3];
	to_define[0] = 500; //START X
	to_define[1] = 500;	//START Y
	// basic_placing(points, *height, *width, to_define)
	dims[0] = *height;
	dims[1] = *width;
	dims[2] = 3;
	points[0][0][0] = to_define[0];
	points[0][0][1] = to_define[1];
	iso(points, dims, (30 * PI) / 180);
	map = map_making(path, dims);
	alt_adding(points, dims, map);
	// print_tab_3(points, *height, *width);
	return (free(path), points);
}

// int	main(void)
// {
// 	t_point	**map;
// 	int		dims[2];
// 	int i = 0;
// 	int j = 0;

// 	dims[0] = 3;
// 	dims[1] = 3;
// 	map = map_making("../test_maps/small_pyra.fdf", dims);
// 	while (i < dims[0])
// 	{
// 		j = 0;
// 		while (j < dims[1])
// 		{
// 			ft_printf("map[%d][%d].alt = %d ", i, j, map[i][j].alt);
// 			// ft_printf("map[%d][%d].color = %u ", i, j, map[i][j].color);
// 			j++;			
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}	
// 	free(map);
// 	return (0);
// }
