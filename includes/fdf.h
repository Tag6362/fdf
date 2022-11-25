/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/25 11:20:25 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# define ON_KEYDOWN 2
# define ON_MOUSEDOWN 4
# define ON_DESTROY 17
# define NO_MASK 0L
# define KEYPRESS_MASK 1L<<0
# define BUTTONPRESS_MASK 1l<<2


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

typedef struct	s_point {
	int				alt;
	unsigned long	color;
}				t_point;

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
int key_listener(int keycode, t_vars *vars);
int on_destroy(t_vars *vars);
int on_mouse_down(int button, int x, int y, t_vars *vars);

/* Line Plotting */
void plotLine(t_data img, int *p1, int *p2, int color);

/* Memory */
void	**ft_free_strs(char **strs);
void	**ft_free_map(t_point **map, unsigned int len); //FIXME

/* ATOUL */
unsigned long ft_atoul_hexa(const char *str);
#endif
