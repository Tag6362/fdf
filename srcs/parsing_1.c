/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:38:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/09 10:53:54 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	glo_scale(int op)
{
	static double scale = 1;
	
	if (op == 1)
	{
		scale += 1;		
		return (scale);
	}
	if (op == -1)
	{
		scale -= 1;
		return (scale);
	}
	return (scale);
}

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

int	***parsing(const char *map_name, int **dims, double angle, t_point ***map)
{
	char	*path;
	int		***points;
	int		*height;
	int 	*width;

	height = &((*dims)[0]);
	width = &((*dims)[1]);
	path = ft_strjoin("test_maps/", map_name);
	ft_printf("Accessing %s...\n", path);
	if (get_height(path, height) == -2 || get_width(path, width) == -2)
		return (perror("Problem in file\n"), free(path), NULL);
	ft_printf("%dx%d\n", *height, *width);
	points = ft_calloc_int_tab_3(*height, *width, 2);
	if (!points)
		return (perror("Problem with creating tab"), free(path), NULL);
	
	int		to_define[3];
	to_define[0] = 240; //START X
	to_define[1] = 740;	//START Y
	// (*dims)[2] = 20; //HYPOTHENUSE
	points[0][0][0] = to_define[0];
	points[0][0][1] = to_define[1];
	iso(points, *dims, angle);
	*map = map_making(path, *dims, 1);
	alt_adding(points, *dims, *map, glo_scale(0));
	ft_printf("Parsing Done !\n");
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
