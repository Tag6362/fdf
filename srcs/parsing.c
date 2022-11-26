/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:38:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/26 18:01:47 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_line_number(char *path_to_map, int *line_number)
{
	int	fd;
	char *tmp;

	fd = open(path_to_map, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		(*line_number)++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
	return (1);
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
	ft_printf("Map size: %dx%d\n", *line_len, line_number);
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
	path_to_map = ft_strjoin("test_maps/", map_name);
	ft_printf("Accessing %s...\n", path_to_map);
	if (get_line_number(path_to_map, line_number) == -2)
		return (ft_printf("Wrong path\n"), free(path_to_map), NULL);
	ft_printf("Done!\n");
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
// 	printf("%dx%d\n", line_len, line_number);
// 	printf("%X", (map + 32)->color);
// 	free(map);
// 	return (0);
// }
