/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_fractols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:15:39 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 18:50:06 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_carpet(int x, int y, t_fr *fr)
{
	long double	xscale;
	long double	yscale;
	long double	xoff;
	long double	yoff;

	x = fabs((double)x) / 1;
	y = fabs((double)y) / 1;
	xscale = WIDTH / 3 + (fr->scale - 1);
	yscale = HEIGHT / 3 + (fr->scale - 1);
	xoff = 0;
	yoff = 0;
	fr->iter = -1;
	while (++fr->iter < fr->max_iter / 10)
	{
		if (x >= xscale + xoff && x <= xscale * 2 + xoff &&
			y >= yscale + yoff && y <= yscale * 2 + yoff)
			break ;
		xoff += ((int)(x / xscale) % 3) * xscale;
		yoff += ((int)(y / yscale) % 3) * yscale;
		xscale = WIDTH / (pow(3, fr->iter));
		yscale = HEIGHT / (pow(3, fr->iter));
	}
	fr->iter = fr->iter * 7;
	fr->color = fr->coloring(fr);
	fr->img.data[(int)y * WIDTH + (int)x] = fr->color;
}

void		lambda_mandelbrot(int x, int y, t_fr *fr)
{
	fr->c_re = 1.5 * (x - WIDTH / 2) / (0.5 * fr->scale * WIDTH) + fr->m_x;
	fr->c_im = (y - HEIGHT / 2) / (0.5 * fr->scale * HEIGHT) + fr->m_y;
	fr->z_re = 0.5;
	fr->z_im = 0.0;
	fr->iter = 0;
	while ((fr->z_re * fr->z_re + fr->z_im * \
	fr->z_im <= 2 * 2) && (fr->iter < fr->max_iter))
	{
		fr->x_tmp = fr->z_re - fr->z_re * fr->z_re + fr->z_im * fr->z_im;
		fr->y_tmp = fr->z_im - 2 * fr->z_re * fr->z_im;
		fr->z_im = fr->c_re * fr->y_tmp + fr->c_im * fr->x_tmp;
		fr->z_re = fr->c_re * fr->x_tmp - fr->c_im * fr->y_tmp;
		fr->iter = fr->iter + 1;
	}
	fr->color = fr->coloring(fr);
	fr->img.data[y * WIDTH + x] = fr->color;
}

void		sea_horse(int x, int y, t_fr *fr)
{
	fr->c_re = 1.5 * (x - WIDTH / 2) / (0.5 * fr->scale * WIDTH) + fr->m_x;
	fr->c_im = (y - HEIGHT / 2) / (0.5 * fr->scale * HEIGHT) + fr->m_y;
	fr->z_re = 0.5;
	fr->z_im = 1.0;
	fr->iter = 0;
	while ((fr->z_re * fr->z_re + fr->z_im * \
	fr->z_im <= 2 * 2) && (fr->iter < fr->max_iter))
	{
		fr->x_tmp = fr->z_re * fr->z_re - fr->z_im * fr->z_im + fr->c_re;
		fr->z_im = 2 * fr->z_re * fr->z_im + fr->c_im;
		fr->z_re = fr->x_tmp;
		fr->iter = fr->iter + 1;
	}
	fr->color = fr->coloring(fr);
	fr->img.data[y * WIDTH + x] = fr->color;
}

void		set_umbrella(int x, int y, t_fr *fr)
{
	fr->c_re = 1.5 * (x - WIDTH / 2) / (0.5 * fr->scale * WIDTH) + fr->m_x;
	fr->c_im = (y - HEIGHT / 2) / (0.5 * fr->scale * HEIGHT) + fr->m_y;
	fr->z_re = 0.0;
	fr->z_im = 0.0;
	fr->iter = 0;
	while ((pow(0.15, fr->z_im * fr->z_re) + fabs(fr->z_im) \
	* fabs(fr->z_re) <= 4) && (fr->iter < fr->max_iter))
	{
		fr->x_tmp = fr->z_re * fr->z_re - fr->z_im * fr->z_im + fr->c_re;
		fr->z_im = pow(0.15, (fr->z_re * fr->z_im)) + fabs(fr->c_im);
		fr->z_re = fr->x_tmp;
		fr->iter = fr->iter + 1;
	}
	fr->color = fr->coloring(fr);
	fr->img.data[y * WIDTH + x] = fr->color;
}
