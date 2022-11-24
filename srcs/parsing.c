/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:38:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/24 12:08:20 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_number(int fd, int *line_number)
{
	int		i;
	int		ind;
	char	*buffer;

	ind = 0;
	buffer = ft_calloc(9, 1);
	if (!buffer)
		return (-2);
	ind = read(fd, buffer, 8);
	while (ind != -1 && ind)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				(*line_number)++;
			i++;
		}
		ind = read(fd, buffer, 8);
	}
	if (ind == -1)
		return (-2);
	return (free(buffer), 1);
}

int	parsing(int fd, char ***plateau, char ***colors, int line_number)
{
	const char	*tmp;
	const char	*tmp2;
	char		**strs;
	int			i;
	(void)colors;

	i = 0;
	plateau = ft_calloc(line_number, sizeof(char **));
	colors = ft_calloc(line_number, sizeof(char **));
	if (!plateau || !colors)
		return (-2);
	// printf("%p\n", plateau);
	tmp = get_next_line(fd);
	// printf("TMP IN PARSING %s /TMP IN PARSING\n", tmp);
	while (i < line_number)
	{
		tmp2 = ft_strtrim(tmp, "\n");
		// printf("TMP2 IN PARSING %s /TMP2 IN PARSING\n", tmp2);
		free((char *)tmp);
		// strs = 
	// write(1, "aaaaa\n", 6);
		// printf("I IN PARSING % d /I IN PARSING\n", i);
		plateau[i] = ft_split(tmp2, ' ');
		printf("%s\n", plateau[i][2]);
		free((char *)tmp2);
		tmp = get_next_line(fd);
		i++;
	}
	return (1);
}

int	main(void)
{
	int	fd;
	char	***plateau;
	char	***colors;
	int		line_number;
	
	line_number = 0;
	fd = open("../test_maps/elem.fdf", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Problem with opening\n", 21);
		return (-1);
	}
	if (get_line_number(fd, &line_number) == -2)
		return (-2);
	// printf("Line Number %d\n", line_number);
	close(fd);
	fd = open("../test_maps/elem-col.fdf", O_RDONLY);
	parsing(fd, plateau, colors, line_number);
	// printf("%s\n", plateau[0][0]);
	close(fd);
}
