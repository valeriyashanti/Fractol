/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:07:22 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/04 10:28:41 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_check_error(char *str)
{
	if (!(ft_strcmp("usage", str)))
	{
		ft_putendl("usage : Mandelbrot_set \
		[m]\tJulia_set [j]\tBurning_ship [b]");
		ft_putendl("        Lam_mandelbrot \
		[l]\tSea_horse [h]\tSpider_set   [s]");
		ft_putendl("        Set_carpet     \
		[c]\tSet_umbrella [u]");
	}
	else
		ft_putendl(str);
	exit(0);
}

int			ft_fractol_kind(char **argv, t_fr *fr)
{
	if (!(ft_strcmp("j", argv[1])))
		fr->get_set = juliya_set;
	else if (!(ft_strcmp("m", argv[1])))
		fr->get_set = mandelbrot_set;
	else if (!(ft_strcmp("b", argv[1])))
		fr->get_set = set_burning;
	else if (!(ft_strcmp("h", argv[1])))
		fr->get_set = sea_horse;
	else if (!(ft_strcmp("l", argv[1])))
		fr->get_set = lambda_mandelbrot;
	else if (!(ft_strcmp("s", argv[1])))
		fr->get_set = set_spider;
	else if (!(ft_strcmp("c", argv[1])))
		fr->get_set = set_carpet;
	else if (!(ft_strcmp("u", argv[1])))
		fr->get_set = set_umbrella;
	else
		return (0);
	return (1);
}

int			ft_validate(int argc)
{
	if (argc > 2)
		ft_check_error("Nope! Just one window Dude!");
	if (argc < 2)
	{
		ft_check_error("usage");
	}
	return (1);
}
