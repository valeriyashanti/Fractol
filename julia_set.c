/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:53:13 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 18:34:13 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		juliya_set(int x, int y, t_fr *fr)
{
	fr->z_re = 1.5 * (x - WIDTH / 2) / (0.5 * fr->scale * WIDTH) + fr->m_x;
	fr->z_im = (y - HEIGHT / 2) / (0.5 * fr->scale * HEIGHT) + fr->m_y;
	fr->iter = 0;
	while ((fr->z_re * fr->z_re + fr->z_im * \
	fr->z_im <= 2 * 2) && (fr->iter < fr->max_iter))
	{
		fr->x_tmp = fr->z_re * fr->z_re - fr->z_im * fr->z_im + fr->mouse_x;
		fr->z_im = 2 * fr->z_re * fr->z_im + fr->mouse_y;
		fr->z_re = fr->x_tmp;
		fr->iter = fr->iter + 1;
	}
	fr->color = fr->coloring(fr);
	fr->img.data[y * WIDTH + x] = fr->color;
}
