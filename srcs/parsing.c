/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:38:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/25 14:45:49 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_line_number(char *path_to_map, int *line_number)
{
	int		i;
	int		ind;
	char	*buffer;
	int		fd;

	fd = open(path_to_map, O_RDONLY);
	ind = 0;
	buffer = ft_calloc(4097, 1);
	if (!buffer)
		return (close(fd), -2);
	ind = read(fd, buffer, 4096);
	while (ind != -1 && ind)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				(*line_number)++;
			i++;
		}
		ind = read(fd, buffer, 4096);
	}
	if (ind == -1)
		return (close(fd), free(buffer), -2);
	return (close(fd), free(buffer), 1);
}

static void	pixel_maker(t_point *map, int ind, char *info)
{
	char	**tmp;

	tmp = ft_split(info, ',');
	if (!tmp[1])
		map[ind].color = 0x00FFFFFF;
	else
		map[ind].color = ft_atou_hexa(tmp[1]);
	map[ind].alt = ft_atoi(tmp[0]);
	ft_free_strs(tmp);
}

static void	auxiliary(int fd, int line_len, int i, t_point **map)
{
	int		j;
	char	*tmp;
	char	**strs;

	j = 0;
	tmp = get_next_line(fd);
	strs = ft_split(tmp, ' ');
	while (j < line_len)
	{
		pixel_maker(*map, line_len * i + j, strs[j]);
		j++;
	}
	free(tmp);
	ft_free_strs(strs);
}

static int	mapper(int fd, t_point **map, int line_number, int *line_len)
{
	char	*tmp;
	char	**strs;
	int		i;
	int		j;

	j = 0;
	i = 1;
	tmp = get_next_line(fd);
	strs = ft_split(tmp, ' ');
	while (strs[*line_len])
		(*line_len)++;
	(*line_len)--;
	*map = ft_calloc((line_number * (*line_len) + 1), sizeof(t_point));
	if (!map)
		return (-2);
	while (j < (*line_len))
	{
		pixel_maker(*map, j, strs[j]);
		j++;
	}
	free(tmp);
	ft_free_strs(strs);
	while (i < line_number)
		auxiliary(fd, *line_len, i++, map);
	return (1);
}

t_point	*parsing(const char *map_name, int *line_number, int *line_len)
{
	int		fd;
	t_point	*map;
	char	*path_to_map;

	*line_number = 0;
	*line_len = 0;
	path_to_map = ft_strjoin("../test_maps/", map_name);
	if (get_line_number(path_to_map, line_number) == -2)
		return (free(path_to_map), NULL);
	fd = open(path_to_map, O_RDONLY);
	mapper(fd, &map, *line_number, line_len);
	close(fd);
	free(path_to_map);
	return (map);
}

// int	main(void)
// {
// 	t_point	*map;
// 	int		line_number;
// 	int		line_len;

// 	map = parsing("elem-col.fdf", &line_number, &line_len);
// 	printf("%X", (map + 23)->color);
// 	free(map);
// 	return (0);
// }
