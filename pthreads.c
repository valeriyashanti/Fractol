/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:07:02 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/04 10:25:49 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			p_h(t_fr *fr)
{
	pthread_t	tid[THREADS];
	int			i;
	int			thread;
	t_fr		tab[THREADS];

	i = 0;
	thread = HEIGHT / THREADS;
	while (i < THREADS)
	{
		ft_memcpy((void*)&tab[i], (void*)fr, sizeof(t_fr));
		tab[i].thread_j_max = (i + 1) * thread;
		tab[i].thread_j_min = i * thread;
		pthread_create(&tid[i], NULL, (void*)get_set, &tab[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img.img_ptr, 0, 0);
	return (0);
}
