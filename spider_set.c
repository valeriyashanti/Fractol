/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:21:39 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 19:00:30 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_coordinates(int x, int y, t_fr *fr)
{
	fr->z_re = 1.5 * (x - WIDTH / 2) / (0.5 * fr->scale * WIDTH) + fr->m_x;
	fr->z_im = (y - HEIGHT / 2) / (0.5 * fr->scale * HEIGHT) + fr->m_y;
	fr->iter = 0;
	fr->c_re = fr->z_re;
	fr->c_im = fr->z_im;
}

void		set_spider(int x, int y, t_fr *fr)
{
	double zx;
	double zy;
	double cx;
	double cy;

	init_coordinates(x, y, fr);
	while ((fr->z_re * fr->z_re + fr->z_im * fr->z_im) \
	<= 2 && (fr->iter < fr->max_iter))
	{
		zx = fr->z_re;
		zy = fr->z_im;
		cx = fr->c_re;
		cy = fr->c_im;
		fr->z_re = (zx * zx) - (zy * zy) + fr->c_re;
		fr->z_im = 2 * zy * zy + fr->c_im;
		fr->c_re = cx / 2 + fr->z_re;
		fr->c_im = cy / 2 + fr->z_im;
		fr->iter += 1;
	}
	fr->color = fr->coloring(fr);
	fr->img.data[y * WIDTH + x] = fr->color;
}
