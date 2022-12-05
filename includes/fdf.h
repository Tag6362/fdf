/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/05 17:20:22 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# define PI 3.142857
# define ON_KEYDOWN 2
# define ON_MOUSEDOWN 4
# define ON_DESTROY 17
# define NO_MASK 0L
# define KEYPRESS_MASK 1L<<0
# define BUTTONPRESS_MASK 1l<<2
# define WINDOW_X 1500
# define WINDOW_Y 900


typedef struct	s_data {
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
	unsigned int	color;
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
int	add_shade(int trgb, float shade);
int	color_opposite(int color);

/* Events Window */
int	key_listener(int keycode, t_vars *vars);
int	on_destroy(t_vars *vars);
int	on_mouse_down(int button, int x, int y, t_vars *vars);

/* Line Plotting 1*/

void	plot_line(t_data *img, int *p1, int *p2, unsigned int color);
void	bres_plot_high(t_data *img, int *p1, int *p2, unsigned int color);
void	bres_plot_low(t_data *img, int *p1, int *p2, unsigned int color);

/* Line Plotting 2*/
void	plot_line_vertical(t_data img, int *p1, int *p2, unsigned int col);
void	mlx_spp(t_data *data, int x, int y, int color);

/* Memory Cleaning*/
void	**ft_free_strs(char **strs);
void	**ft_free_int_tab_2(int **tab, int len_tab);

/* Memory Allocation */
int	**ft_calloc_int_tab_2(int len_tab, int len_subtab);

/* Atoul */
unsigned int	ft_atou_hexa(const char *str);

/* Parsing */
t_point	*parsing(const char *map_name, int *line_number, int *line_len);

/* Math functions*/
long	power(int nb, int power);
int	ft_rev_bigger(int *a, int *b);

/* Mapping */
int create_map(int hyp, int *dimensions, int *origin, t_data img, t_point *map);
int	**create_tab(int hyp, int *dims, int *origin, t_point *map);
void read_tab_test(int **tab_points, int *dims);

/* Map Plotting */
void	plot_map(t_data img, t_point *map, int *dims, int hyp, int **points);

/* Ft_int_biggest_first */
int	ft_int_biggest_first(int *a, int *b);

/* Merci a Danil de savoir lire*/
#endif
