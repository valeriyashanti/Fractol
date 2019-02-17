/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:09:46 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/05 15:50:50 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1200
# define HEIGHT 800
# define X1		-2.1
# define X2		0.6
# define Y1		-1.2
# define Y2		1.2
# define THREADS 16
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "math.h"
# include "mlx.h"
# include "libft.h"
# include <pthread.h>
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_line;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_fr
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	double		scale;
	double		c_re;
	double		c_im;
	double		z_re;
	double		z_im;
	int			iter;
	int			max_iter;
	double		x_tmp;
	double		y_tmp;
	int			color;
	char		**argv;
	int			mouse;
	double		mouse_x;
	double		mouse_y;
	int			stop;
	int			thread_j_max;
	int			thread_j_min;
	void		*set;
	double		off_x;
	double		off_y;
	double		m_x;
	double		m_y;
	int			(*coloring)(struct s_fr *fr);
	void		(*get_set)(int x, int y, struct s_fr *fr);
}				t_fr;

void			ft_new_window(t_fr *fr);
int				ft_fractol_kind(char **argv, t_fr *fr);
void			mandelbrot_set(int x, int y, t_fr *fr);
void			ft_check_error(char *str);
void			set_burning(int x, int y, t_fr *fr);
int				deal_key(int key, t_fr *fr);
int				on_mouse_move(int x, int y, t_fr *fr);
int				on_mouse_release(int button, int x, int y, t_fr *fr);
int				on_mouse_press(int button, int x, int y, t_fr *fr);
void			fr_clear_and_create_window(t_fr *fr);
int				ft_color(t_fr *fr);
int				color2(t_fr *fr);
int				p_h(t_fr *fr);
void			get_color(int x, int y, t_fr *fr);
int				ft_coloring_lsd(t_fr *th);
int				fr_coloring2(t_fr *fr);
int				ft_coloring(t_fr *fr);
int				ft_coloring_blue_yellow(t_fr *fr);
int				ft_validate(int argc);
void			ft_init_fractol_values(t_fr *fr, char **argv);
void			set_carpet(int x, int y, t_fr *fr);
void			set_spider(int x, int y, t_fr *fr);
void			lambda_mandelbrot(int x, int y, t_fr *fr);
void			sea_horse(int x, int y, t_fr *fr);
void			*get_set(t_fr *fr);
void			juliya_set(int x, int y, t_fr *fr);
void			set_umbrella(int x, int y, t_fr *fr);
void			init_coordinates(int x, int y, t_fr *fr);

#endif
