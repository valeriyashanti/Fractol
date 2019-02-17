/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_coloring2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:48:02 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 12:10:16 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_coloring_lsd(t_fr *th)
{
	if (th->iter == th->max_iter)
		return (0xFF0000);
	else
	{
		return ((RGB(
			127.5 * (cos((double)th->iter) + 1),
			127.5 * (sin((double)th->iter) + 1),
			127.5 * (1 - cos((double)th->iter)))));
	}
	return (0);
}
