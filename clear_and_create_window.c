/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_and_create_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:06:13 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 18:35:15 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fr_clear_and_create_window(t_fr *fr)
{
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	mlx_destroy_image(fr->mlx_ptr, fr->img.img_ptr);
	fr->img.img_ptr = mlx_new_image(fr->mlx_ptr, WIDTH, HEIGHT);
	p_h(fr);
}

void		ft_new_window(t_fr *fr)
{
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	fr->img.img_ptr = mlx_new_image(fr->mlx_ptr, WIDTH, HEIGHT);
	fr->img.data = (int*)mlx_get_data_addr(fr->img.img_ptr,\
	&fr->img.bpp, &fr->img.size_line, &fr->img.endian);
}
