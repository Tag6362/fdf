/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/23 15:00:05 by tgernez          ###   ########.fr       */
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
	int		line_len;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/* ---PROTOS--- */
/* Main */

/* Colors 1*/
int create_trgb(int t, int r, int g, int b);
int get_t(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);

/* Colors 2*/
int add_shade(int trgb, float shade);
int color_opposite(int color);

/* Events Window */
int mlx_close(int keycode, t_vars *vars);

/* Line Plotting */
void plotLine(t_data img, int *p1, int *p2, int color);

#endif
