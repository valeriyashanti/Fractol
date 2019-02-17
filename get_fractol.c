/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:20:38 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/03 18:59:44 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*get_set(t_fr *fr)
{
	int i;

	while (fr->thread_j_min < fr->thread_j_max)
	{
		i = 0;
		while (i != WIDTH)
		{
			fr->get_set(i, fr->thread_j_min, fr);
			i++;
		}
		fr->thread_j_min++;
	}
	pthread_exit(0);
	return (0);
}
