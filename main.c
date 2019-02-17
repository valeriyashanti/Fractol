/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:07:51 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/04 10:28:48 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fr	*fr;

	ft_validate(argc);
	if (!(fr = (t_fr*)malloc(sizeof(t_fr))))
		ft_check_error("Malloc error");
	fr->mlx_ptr = mlx_init();
	ft_init_fractol_values(fr, argv);
	ft_new_window(fr);
	if (ft_fractol_kind(argv, fr) == 0)
		ft_check_error("usage");
	p_h(fr);
	mlx_hook(fr->win_ptr, 2, 0, deal_key, fr);
	mlx_hook(fr->win_ptr, 4, 0, on_mouse_press, fr);
	mlx_hook(fr->win_ptr, 5, 0, on_mouse_release, fr);
	mlx_hook(fr->win_ptr, 6, 0, on_mouse_move, fr);
	mlx_loop(fr);
	return (0);
}
