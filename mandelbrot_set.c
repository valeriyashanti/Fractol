/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:10:34 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 18:47:16 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot_set(int x, int y, t_fr *fr)
{
	fr->c_re = 1.5 * (x - WIDTH / 2) / (0.5 * fr->scale * WIDTH) + fr->m_x;
	fr->c_im = (y - HEIGHT / 2) / (0.5 * fr->scale * HEIGHT) + fr->m_y;
	fr->z_re = 0.0;
	fr->z_im = 0.0;
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
