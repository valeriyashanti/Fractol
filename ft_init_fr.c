/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:12:28 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 18:59:47 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fractol_values(t_fr *fr, char **argv)
{
	fr->scale = 0.7;
	fr->argv = argv;
	fr->max_iter = 100;
	fr->off_x = 0;
	fr->off_y = 0;
	fr->coloring = &ft_coloring;
	fr->stop = 0;
	fr->mouse_x = 0;
	fr->mouse_y = 0;
}
