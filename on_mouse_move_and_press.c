/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move_and_press.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:40:02 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/04 10:24:54 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fr_scale(t_fr *fr)
{
	if (fr->max_iter > 73)
		fr->max_iter -= 3;
}

int			on_mouse_press(int button, int x, int y, t_fr *fr)
{
	if (x >= 0 && x <= 2000 && y >= 0 && y <= 1200)
	{
		if (button == 4)
		{
			fr->m_x += (((x > WIDTH / 2) ? ((double)x / (double)\
			WIDTH - 0.5) : -(0.5 - (double)x / (double)WIDTH)) / fr->scale);
            
			fr->m_y += (((y > HEIGHT / 2) ? 0.67 * ((double)y / \
			(double)HEIGHT - 0.5) : -0.67 * (0.5 - \
			(double)y / (double)HEIGHT)) / fr->scale);
			fr->scale *= 1.5;
			fr->max_iter += 3;
		}
		if (button == 5 && fr->scale > 0)
		{
			fr_scale(fr);
			fr->scale /= 1.5;
			fr->m_x -= (((x > WIDTH / 2) ? ((double)x / (double)WIDTH - 0.5) \
			: -(0.5 - (double)x / (double)WIDTH)) / fr->scale);
            
			fr->m_y -= (((y > HEIGHT / 2) ? 0.67 * ((double)y / (double)HEIGHT\
			- 0.5) : -0.67 * (0.5 - (double)y / (double)HEIGHT)) / fr->scale);
		}
		if (button == 4 || button == 5)
			fr_clear_and_create_window(fr);
	}
	return (0);
}

int			on_mouse_release(int button, int x, int y, t_fr *fr)
{
	(void)button;
	(void)x;
	(void)y;
	fr->mouse = 0;
	return (0);
}

int			on_mouse_move(int x, int y, t_fr *fr)
{
	if ((y >= 0 && y < HEIGHT) \
		&& (x >= 0 && x <= WIDTH))
	{
		if (fr->get_set == juliya_set && fr->stop == 0)
		{
			fr->mouse_x = (((double)x - WIDTH / 2.0) / WIDTH);
			fr->mouse_y = (((double)(HEIGHT / 2.0 - y)) / WIDTH);
			fr_clear_and_create_window(fr);
		}
	}
	return (0);
}
