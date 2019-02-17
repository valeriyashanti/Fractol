/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_coloring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:46:25 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 18:37:10 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_color(t_fr *fr)
{
	if (fr->iter > 99)
		return (0);
	if (fr->iter > 13)
		return (16777215);
	if (fr->iter > 2 && fr->iter < 13)
		return (65535);
	if (fr->iter <= 2)
		return (255);
	return (0);
}

int			color2(t_fr *fr)
{
	float part;

	part = (float)fr->iter / (float)fr->max_iter;
	if (part == 1.0)
		return (0xFFFFFF);
	return ((RGB(100, part * 255, 100)));
}

int			fr_coloring2(t_fr *fr)
{
	int r;
	int g;
	int b;

	(void)fr->max_iter;
	r = 100;
	g = (int)(fr->iter * 255.0 / 4.0);
	b = 100;
	return (RGB(r, g, b));
}

int			ft_coloring(t_fr *fr)
{
	if (fr->iter == fr->max_iter)
		return (0);
	else
	{
		return ((RGB(
			127.5 * (cos((double)fr->iter) + 1),
			127.5 * (sin((double)fr->iter) + 1),
			127.5 * (1 - sin((double)fr->iter)))));
	}
}

int			ft_coloring_blue_yellow(t_fr *fr)
{
	if (fr->iter == fr->max_iter)
		return (255);
	else
	{
		return ((RGB(
			127.5 * (sin((double)fr->iter) + 1),
			127.5 * (sin((double)fr->iter) + 1),
			127.5 * (1 - sin((double)fr->iter)))));
	}
}
