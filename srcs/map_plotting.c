/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plotting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:23:43 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/01 13:02:21 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"




// /* MARCHE POUR alt= 10 en 2,0, plus "grand" y en premier, aucun switch*/
// void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	plot_line(img, points[1], points[0], 0xFFFFFF);
// 	plot_line(img, points[2], points[1], 0xFFFFFF);

// 	plot_line(img, points[dims[0] + 1], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[dims[0] + 1], 0xFFFFFF);

// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0]], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 2], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[0], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0]], points[2 * dims[0]], 0xFFFFFF);
	
// 	plot_line(img, points[1], points[dims[0] + 1], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 1], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[2], points[dims[0] + 2], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[2 * dims[0] + 2], 0xFFFFFF);
	
// 	ft_printf("No segfault \n");
// }


// /* MARCHE POUR alt= 10 en 0,2, plus "grand" y en premier*/
// void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	plot_line(img, points[1], points[0], 0xFFFFFF);
// 	plot_line(img, points[1], points[2], 0xFFFFFF); //SWITCHED

// 	plot_line(img, points[dims[0] + 1], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[dims[0] + 1], 0xFFFFFF);

// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0]], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 2], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[0], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0]], points[2 * dims[0]], 0xFFFFFF);
	
// 	plot_line(img, points[1], points[dims[0] + 1], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 1], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[dims[0] + 2], points[2], 0xFFFFFF); //SWITCHED
// 	plot_line(img, points[dims[0] + 2], points[2 * dims[0] + 2], 0xFFFFFF);
	
// 	ft_printf("No segfault \n");
// }


// /* MARCHE POUR alt= 10 en 2,2 plus "grand" y en premier*/
// void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	plot_line(img, points[1], points[0], 0xFFFFFF);
// 	plot_line(img, points[2], points[1], 0xFFFFFF);

// 	plot_line(img, points[dims[0] + 1], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[dims[0] + 1], 0xFFFFFF);

// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0]], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0] + 2], 0xFFFFFF); //SWITCHED
	
// 	plot_line(img, points[0], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0]], points[2 * dims[0]], 0xFFFFFF);
	
// 	plot_line(img, points[1], points[dims[0] + 1], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 1], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[2], points[dims[0] + 2], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[2 * dims[0] + 2], 0xFFFFFF);
	
// 	ft_printf("No segfault \n");
// }

/* MARCHE POUR alt= 10 en 0,0 plus "grand" y en premier GRAND == VALEUR DANS TAB =/= PLUS HAUT*/
// void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	plot_line(img, points[1], points[0], 0xFFFFFF);
// 	plot_line(img, points[2], points[1], 0xFFFFFF);

// 	plot_line(img, points[dims[0] + 1], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[dims[0] + 1], 0xFFFFFF);

// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0]], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 2], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[dims[0]], points[0], 0xFFFFFF);//SWITCHED
// 	plot_line(img, points[dims[0]], points[2 * dims[0]], 0xFFFFFF);
	
// 	plot_line(img, points[1], points[dims[0] + 1], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 1], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[2], points[dims[0] + 2], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[2 * dims[0] + 2], 0xFFFFFF);
	
// 	ft_printf("No segfault \n");
// }


// /* MARCHE POUR ALT > 0 en 1,1 plus "grand" y en premier*/
// void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	plot_line(img, points[1], points[0], 0xFFFFFF);
// 	plot_line(img, points[2], points[1], 0xFFFFFF);

// 	plot_line(img, points[dims[0]], points[dims[0] + 1], 0xFFFFFF);//SWITCHED
// 	plot_line(img, points[dims[0] + 2], points[dims[0] + 1], 0xFFFFFF);

// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0]], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 2], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[0], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0]], points[2 * dims[0]], 0xFFFFFF);
	
// 	plot_line(img, points[1], points[dims[0] + 1], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 1], points[dims[0] + 1], 0xFFFFFF); //SWITCHED
	
// 	plot_line(img, points[2], points[dims[0] + 2], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[2 * dims[0] + 2], 0xFFFFFF);
	
// 	ft_printf("No segfault \n");
// }

// /* MARCHE POUR ALT < 0*/
// void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	plot_line(img, points[1], points[0], 0xFFFFFF);
// 	plot_line(img, points[2], points[1], 0xFFFFFF);

// 	plot_line(img, points[dims[0] + 1], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 1], points[dims[0] + 2], 0xFFFFFF);//SWITCHED

// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0]], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 2], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[0], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0]], points[2 * dims[0]], 0xFFFFFF);
	
// 	plot_line(img, points[dims[0] + 1], points[1], 0xFFFFFF); //SWITCHED
// 	plot_line(img, points[dims[0] + 1], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[2], points[dims[0] + 2], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[2 * dims[0] + 2], 0xFFFFFF);
	
// 	ft_printf("No segfault \n");
// }

/* MARCHE POUR ALT == 0*/
// void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	plot_line(img, points[1], points[0], 0xFFFFFF);
// 	plot_line(img, points[2], points[1], 0xFFFFFF);

// 	plot_line(img, points[dims[0] + 1], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[dims[0] + 1], 0xFFFFFF);

// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0]], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 2], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[0], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0]], points[2 * dims[0]], 0xFFFFFF);
	
// 	plot_line(img, points[1], points[dims[0] + 1], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 1], points[2 * dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[2], points[dims[0] + 2], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[2 * dims[0] + 2], 0xFFFFFF);
	
// 	ft_printf("No segfault \n");
// }
// void plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < dims[1])
// 	{
// 		j = 0;
// 		while (j < dims[0])
// 		{
// 			if (j < dims[0] - 1) //pas derniere colone
// 			{
// 				if ((points[i * dims[0] + j][1] > points[i * dims[0] + (j + 1)][1]))
// 					plot_line(img, points[i * dims[0] + j], points[i * dims[0] + (j + 1)], 0xFFFFFF);
// 				else
// 					plot_line(img, points[i * dims[0] + (j + 1)], points[i * dims[0] + j], 0xFFFFFF);
// 			}
// 			if (i < dims[1] - 1) //pas derniere ligne
// 			{
// 				if ((points[i * dims[0] + j][1] > points[(i + 1) * dims[0] + j][1]) && (points[i * dims[0] + j][0] < points[(i + 1) * dims[0] + j][0]))
// 					plot_line(img, points[i * dims[0] + j], points[(i + 1) * dims[0] + j], 0x00FF00);
// 				else if ((points[i * dims[0] + j][1] < points[(i + 1) * dims[0] + j][1]) && (points[i * dims[0] + j][0] < points[(i + 1) * dims[0] + j][0]))
// 					plot_line(img, points[(i + 1) * dims[0] + j], points[i * dims[0] + j], 0xFF00FF);
// 				else
// 					plot_line(img, points[i * dims[0] + j], points[(i + 1) * dims[0] + j], 0xFF00FF);


// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }






















// void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points)
// {
// 	// ft_printf("%d,%d ", points[0][0], points[0][1]);
// 	plot_line(img, points[1], points[0], 0xFFFFFF);
// 	plot_line(img, points[2], points[1], 0xFFFFFF);
// 	// plot_line(img, points[3], points[2], 0xFFFFFF);
// 	// plot_line(img, points[4], points[3], 0xFFFFFF);
// 	// plot_line(img, points[5], points[4], 0xFFFFFF);

// 	plot_line(img, points[dims[0]], points[dims[0] + 1], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[dims[0] + 1], 0xFFFFFF);
// 	// plot_line(img, points[dims[0] + 3], points[dims[0] + 2], 0xFFFFFF);
// 	// plot_line(img, points[dims[0] + 4], points[dims[0] + 3],  0xFFFFFF);
// 	// plot_line(img, points[dims[0] + 5], points[dims[0] + 4],  0xFFFFFF);

// 	plot_line(img, points[2 * dims[0] + 1], points[2 * dims[0]], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 2], points[2 * dims[0] + 1], 0xFFFFFF);
// 	// plot_line(img, points[2 * dims[0] + 3], points[2 * dims[0] + 2], 0xFFFFFF);
// 	// plot_line(img, points[2 * dims[0] + 4], points[2 * dims[0] + 3],  0xFFFFFF);
// 	// plot_line(img, points[2 * dims[0] + 5], points[2 * dims[0] + 4],  0xFFFFFF);
		
// 	// plot_line(img, points[3 * dims[0] + 1], points[3 * dims[0]], 0xFFFFFF);
// 	// plot_line(img, points[3 * dims[0] + 2], points[3 * dims[0] + 1], 0xFFFFFF);
// 	// plot_line(img, points[3 * dims[0] + 3], points[3 * dims[0] + 2], 0xFFFFFF);
// 	// plot_line(img, points[3 * dims[0] + 4], points[3 * dims[0] + 3],  0xFFFFFF);
// 	// plot_line(img, points[3 * dims[0] + 5], points[3 * dims[0] + 4],  0xFFFFFF);
	
// 	// plot_line(img, points[4 * dims[0] + 1], points[4 * dims[0]], 0xFFFFFF);
// 	// plot_line(img, points[4 * dims[0] + 2], points[4 * dims[0] + 1], 0xFFFFFF);
// 	// plot_line(img, points[4 * dims[0] + 3], points[4 * dims[0] + 2], 0xFFFFFF);
// 	// plot_line(img, points[4 * dims[0] + 4], points[4 * dims[0] + 3],  0xFFFFFF);
// 	// plot_line(img, points[4 * dims[0] + 5], points[4 * dims[0] + 4],  0xFFFFFF);
	
// 	// plot_line(img, points[5 * dims[0] + 1], points[5 * dims[0]], 0xFFFFFF);
// 	// plot_line(img, points[5 * dims[0] + 2], points[5 * dims[0] + 1], 0xFFFFFF);
// 	// plot_line(img, points[5 * dims[0] + 3], points[5 * dims[0] + 2], 0xFFFFFF);
// 	// plot_line(img, points[5 * dims[0] + 4], points[5 * dims[0] + 3],  0xFFFFFF);
// 	// plot_line(img, points[5 * dims[0] + 5], points[5 * dims[0] + 4],  0xFFFFFF);
// 	// plot_line(img, points[5 * dims[0] + 6], points[5 * dims[0] + 5],  0xFFFFFF);
// 	// plot_line(img, points[5 * dims[0] + 7], points[5 * dims[0] + 6],  0xFFFFFF);
// 	// plot_line(img, points[5 * dims[0] + 8], points[5 * dims[0] + 7],  0xFFFFFF);
	
// 	plot_line(img, points[0], points[dims[0]], 0xFFFFFF);
// 	plot_line(img, points[dims[0]], points[2 * dims[0]], 0xFFFFFF);
	
// 	plot_line(img, points[1], points[dims[0] + 1], 0xFFFFFF);
// 	plot_line(img, points[2 * dims[0] + 1], points[dims[0] + 1], 0xFFFFFF);
	
// 	plot_line(img, points[2], points[dims[0] + 2], 0xFFFFFF);
// 	plot_line(img, points[dims[0] + 2], points[2 * dims[0] + 2], 0xFFFFFF);
	
// 	ft_printf("No segfault \n");
// }