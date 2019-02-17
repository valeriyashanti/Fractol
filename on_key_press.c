/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:14:17 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/04 10:25:45 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_position(int key, t_fr *fr)
{
	if (key == 126)
		fr->m_y += 0.05;
	if (key == 125)
		fr->m_y -= 0.05;
	if (key == 124)
		fr->m_x -= 0.05;
	if (key == 123)
		fr->m_x += 0.05;
}

void		change_colors(int key, t_fr *fr)
{
	if (key == 12)
		fr->coloring = &ft_coloring_lsd;
	if (key == 13)
		fr->coloring = &ft_coloring;
	if (key == 14)
		fr->coloring = &fr_coloring2;
	if (key == 15)
		fr->coloring = &ft_coloring_blue_yellow;
	if (key == 16)
		fr->coloring = &ft_color;
	if (key == 17)
		fr->coloring = &color2;
}

int			deal_key(int key, t_fr *fr)
{
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	change_colors(key, fr);
	change_position(key, fr);
	if (key == 53)
		ft_check_error("Good jooob!");
	if (key == 24)
		fr->max_iter += 50;
	if (key == 257)
	{
		if (fr->stop == 0)
			fr->stop = 1;
		else
			fr->stop = 0;
	}
	fr_clear_and_create_window(fr);
	return (0);
}
