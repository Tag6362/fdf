/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:45 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/19 19:15:39 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# define PI 3.141592
# define ON_KEYDOWN 2
# define ON_MOUSEDOWN 4
# define ON_DESTROY 17
# define NO_MASK 0L
# define KEYPRESS_MASK 1L
# define BUTTONPRESS_MASK 4L

typedef struct s_point {
	int				alt;
	unsigned int	color;
}				t_point;

typedef struct s_data {
	void	*img;
	void	*addr;
	int		bpp;
	int		llen;
	int		end;
	void	*mlx;
	void	*win;
	double	angle;
	t_point	***map;
	int		****points;
	int		**dims;
	char	**map_name;
	int		x;
	int		y;
}				t_data;

/* ---PROTOS--- */
/* Main */
void			put_image_and_hooks(t_data img);

/* Events Window */
int				key_listener(int keycode, t_data *img);
int				on_destroy(t_data *img);
int				mouse_listener(int button, int x, int y, t_data *img);

/* Plotting 1 */
void			plot_points(t_data img, int ***pts, int *dims);
void			mlx_spp(t_data *data, int x, int y, int color);

/* Plotting 2 */
void			plot_line_deg_1(t_data *img, int ***pts, int *dims,
					t_point **map);
void			plot_line_deg_2(t_data *img, int ***pts, int *dims,
					t_point **map);

/* Plotting 3*/
void			plot_line(t_data *img, int *p1, int *p2, unsigned int color);

/* Memory Cleaning */
void			**ft_free_strs(char **strs);
void			**ft_free_int_tab_2(int **tab, int len_tab);
void			***ft_free_int_tab_3(int ***tab, int len_tab, int len_subtab);
void			**free_map(t_point **map, int height);

/* Memory Allocation */
int				***ft_calloc_int_tab_3(int len_tab, int len_subtab,
					int len_subsubtab);
t_point			**map_malloc(int height, int width);

/* Atoul */
unsigned int	ft_atou_hexa(const char *str);

/* Parsing 1 */
int				***parsing(const char *map_n, int **dims, double angle,
					t_point ***map);
double			glo_scale(int op);
int				get_width(const char *path_to_map, int *width);
int				get_height(const char *path_to_map, int *height);

/* Parsing 2 */
t_point			**map_making(const char *path, int *dims, int fd);
void			iso(int ***pts, int *dims, double ang);
void			alt_adding(int ***pts, int *dims, t_point **map, double scale);

/* Centring */
int				***init_tab(t_point ***map, int **dims, t_data *img,
					const char *map_name);

/* Mouse Functions */
int				mouse_func(t_data *img, int button, int x, int y);

/* Clear */
void			clear_image(t_data img, int *dims);
void			end_of_program(t_data *img);
void			free_win_img(t_data *img);

/* Window functions */
void			render_texts(t_data img);

/* Tests */
void			print_tab_3(int ***points, int height, int width);

/* Keyboard transforms */
void			keyboard_move(t_data *img, int keycode);
void			keyboard_alt(t_data *img, int keycode);
void			keyboard_perspective(t_data *img, int keycode);
void			keyboard_color(t_data *img, int keycode);

/*
Merci a Danil de savoir lire

Le fait que scroller trop vers le bas retourne la map est connu, et
volontairement laisse en tant que feature

*/
#endif
