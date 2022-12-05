/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:38:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/05 18:30:31 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



// static void	pixel_maker(t_point *map, int ind, char *info)
// {
// 	char	**tmp;

// 	tmp = ft_split(info, ',');
// 	if (!tmp[1])
// 		(map + ind)->color = 0xFFFFFF;
// 	else
// 		(map + ind)->color = ft_atou_hexa(tmp[1]);
// 	// ft_printf("IND %d /IND\n", ind);
// 	(map + ind)->alt = ft_atoi(tmp[0]);
// 	ft_free_strs(tmp);
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
	*width = 0;
	while (buff_splitted[(*width)])
		(*width)++;
	free(buff);
	ft_free_strs(buff_splitted);
	close(fd);
	return (1);
}

static int get_height(const char *path_to_map, int *height)
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

t_point	*parsing(const char *map_name, int *height, int *width)
{
	t_point	*map;
	char	*path;

	path = ft_strjoin("test_maps/", map_name);
	ft_printf("Accessing %s...\n", path);
	if (get_height(path, height) == -2 || get_width(path, width) == -2)
		return (perror("Problem in file\n"), free(path), NULL);
	printf("%dx%d\n", *height, *width);
	map = NULL;
	free(path);
	return (map);
}

// int	main(void)
// {
// 	t_point	*map;
// 	int		line_number;
// 	int		line_len;

// 	map = parsing("elem-col.fdf", &line_number, &line_len);
// 	printf("%dx%d\n", line_len, line_number);
// 	printf("%X", (map + 32)->color);
// 	free(map);
// 	return (0);
// }
