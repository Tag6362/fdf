/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/21 16:03:54 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"

typedef struct	s_struct {
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

#endif
