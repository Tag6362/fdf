/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/07 15:52:53 by tgernez          ###   ########.fr       */
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
# define WINDOW_X 1920
# define WINDOW_Y 1080


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

/* Events Window */
int	key_listener(int keycode, t_vars *vars);
int	on_destroy(t_vars *vars);
int	on_mouse_down(int button, int x, int y, t_vars *vars);

/* Plotting */
void	plot_points(t_data img, int ***pts, int *dims, t_point **map);

/* Memory Cleaning*/
void	**ft_free_strs(char **strs);
void	**ft_free_int_tab_2(int **tab, int len_tab);
void	***ft_free_int_tab_3(int ***tab, int len_tab, int len_subtab);
void	**free_map(t_point **map, int height);

/* Memory Allocation */
int		***ft_calloc_int_tab_3(int len_tab, int len_subtab, int len_subsubtab);
t_point **map_malloc(int height, int width);

/* Atoul */
unsigned int	ft_atou_hexa(const char *str);

/* Parsing 1 */
int		***parsing(const char *map_name, int *h, int *w, t_point ***map);

/* Parsing 2 */
t_point	**map_making(char *path, int *dims, int fd);
void	iso(int ***pts, int *dims, double ang);
void	alt_adding(int ***pts, int *dims, t_point **map, int scale);

/* Centring */
int *find_start_coords(t_point **map, int height, int width, double angle);


/* Merci a Danil de savoir lire*/
#endif
