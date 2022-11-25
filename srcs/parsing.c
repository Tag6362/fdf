/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:38:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/25 10:52:41 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_number(int fd, int *line_number)
{
	int		i;
	int		ind;
	char	*buffer;

	ind = 0;
	buffer = ft_calloc(4097, 1);
	if (!buffer)
		return (-2);
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
		return (-2);
	return (free(buffer), 1);
}


// int	parsing(int fd, t_point *map, int line_number, int *line_len)
// {
// 	const char	*tmp;
// 	const char	*tmp2;
// 	const char	*tmp3;
// 	const char	**strs;
// 	const char	**pxl;
// 	int			i;
// 	int			j;
// 	int			k;

// 	k = 0;
// 	j = 0;
// 	i = 0;
// 	tmp = get_next_line(fd);
// 	tmp2 = ft_strtrim(tmp, "\n");
// 	free(tmp);
// 	strs = ft_split(tmp2, ' ');
// 	while (strs[i])
// 		i++;
// 	map = ft_calloc(sizeof(t_point) * (i + 1));
// 	if (!map)
// 		return (-2);
// 	map[i] = NULL;

// 	while (strs[k])
// 	{
// 		pxl = ft_split(strs[k], ',');
// 		if (pxl[1] == NULL);
// 			map[j].color = 0xFF000000;
// 		else
// 			map[j].color = ft_atoi((const char *)pxl[1]);
// 		map[j].alt = ft_atoi((const char *)pxl[0])
// 		free(pxl);
// 		j++;
// 		k++;
// 	}
	
// 	i = 0;	
// 	free(tmp2);		
// 	tmp = get_next_line(fd);
// 	while (i < line_number)
// 	{
// 		tmp2 = ft_strtrim(tmp, "\n");
// 		free(tmp);
// 		strs = ft_split(tmp2, ' ');
// 		free(tmp2);
// 		while (strs[k])
// 		{
// 			pxl = ft_split(strs[k]);
// 			if (pxl[1] == NULL);
// 				map[j].color = 0xFF000000;
// 			else
// 				map[j].color = ft_atoi((const char *)pxl[1]);
// 			map[j].alt = ft_atoi((const char *)pxl[0])
// 			free(pxl);
// 			j++;
// 			k++;
// 		}
// 		tmp = get_next_line(fd);
// 		k = 0;
// 		i++;		
// 	}
// 	map[line_number] = NULL;
// 	return (-2);
// }



// int parsing(int fd, t_point **map, int line_number, int *line_len)
// {
// 	static char *tmp;
// 	static char **strs;
// 	int			i;
// 	int			j;

// 	j = 0;
// 	i = 0;
// 	tmp = get_next_line(fd);
// 	strs = ft_split(tmp, ' '); //Beware of the '\n' in the end, here it helps
// 	while (strs[*line_len])
// 		(*line_len)++; //The '\n' at the end gives the good nb
// 	(*line_len)--;
// 	// map = malloc(sizeof(t_point) * (line_number * (*line_len + 1) + 1));
// 	*map = ft_calloc((line_number * (*line_len) + 1), sizeof(t_point));
// 	if (!map)
// 		return (-2);
// 	// printf("MAP %p /MAP IN PARSING\n", map);
// 	// printf("CEST CA ? %d\n",  (line_number * (*line_len + 1) + 1));
// 	while (j < (*line_len))
// 	{
// 		printf("J %d /J\n", j);
// 		pixel_maker(*map, j, strs[j]);
// 	write(1, "aaa\n", 4);
// 		j++;
// 	}
// 	free(tmp);
// 	free(strs);
// 	// while (i < line_number)
// 	// {
// 	// 	j = 0;
// 	// 	tmp = get_next_line(fd);
// 	// 	strs = ft_split(tmp, ' ');
// 	// 	while (j < (*line_len))
// 	// 	{
// 	// 		pixel_maker(map, (*line_len) * i + j, strs[j]);
// 	// 		j++;
// 	// 	}
// 	// 	free(tmp);
// 	// 	free(strs);
// 	// 	i++;
// 	// }
// 	return (line_number * (*line_len + 1));
// }

void	pixel_maker(t_point *map, int ind, char *info)
{
	char **tmp;
	
	// printf("MAP %p /MAP\n", map);
	// printf("INFO %s /INFO\n", info);
	tmp = ft_split(info, ',');
	// 	write(1, "ccc\n", 4);
	if (!tmp[1])
	{	
		// printf("wtf\n");
		map[ind].color = 0xFF000000; //Arbitrary color chosen if no color
	}
	else
	{
		map[ind].color = ft_atou(tmp[1]);
	}
	map[ind].alt = ft_atoi(tmp[0]);
	ft_free_strs(tmp);
}

int parsing(int fd, t_point **map, int line_number, int *line_len)
{
	char *tmp;
	char **strs;
	int			i;
	int			j;

	j = 0;
	i = 1;
	tmp = get_next_line(fd);
	strs = ft_split(tmp, ' '); //Beware of the '\n' in the end, here it helps
	while (strs[*line_len])
		(*line_len)++; 
	(*line_len)--; // Removing thte \n 
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
	{
		j = 0;
		tmp = get_next_line(fd);
		strs = ft_split(tmp, ' ');
		while (j < (*line_len))
		{
			pixel_maker(*map, (*line_len) * i + j, strs[j]);
			j++;
		}
		free(tmp);
		ft_free_strs(strs);
		i++;
	}
	return (line_number * (*line_len + 1));
}


int	main(void)
{
	int		fd;
	t_point *map;
	int		line_number;
	int		line_len;
	
	line_number = 0;
	line_len = 0;
	fd = open("../test_maps/elem-col.fdf", O_RDONLY);
	if (fd == -1)
	{
		fd = write(1, "Problem with opening\n", 21); //added fd just to stop warns
		return (-1);
	}
	if (get_line_number(fd, &line_number) == -2)
		return (-2);
	close(fd);
	fd = open("../test_maps/elem-col.fdf", O_RDONLY);
	// write(1, "bbb\n", 4);
	int tmp = parsing(fd, &map, line_number, &line_len);
	printf("%d\n", tmp);
	close(fd);
	printf("---------------------------------------------------\n");
	int i, j;
	i = 0;
	j = 0;
	while (i < line_number)
	{
		j = 0;
		while (j < line_len)
		{
			printf("%lx ", map[i * line_len + j].color);
			j++;
		}
		printf("\n");
		i++;
	}
	free(map);
	printf("%x", 2147483647);
	return (0);
}
