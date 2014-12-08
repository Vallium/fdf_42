/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:34:21 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/08 12:49:30 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int				loop_hook(t_all *all)
{
	if (all->re)
	{
		if (all->re == -1)
			ft_free_all(all);
		ft_bzero(all->img.data, WIN_SZ_X * WIN_SZ_Y * 4);
		ft_put_3d_map(all);
		mlx_put_image_to_window(all->env.mlx, all->env.win,\
				all->img.img, 0, 0);
		mlx_string_put(all->env.mlx, all->env.win, 10, 20, 0x98CD00,\
			"+------ F D F ------+");
		mlx_string_put(all->env.mlx, all->env.win, 10, 40, 0x98CD00,\
			"Height change : +/- .");
		mlx_string_put(all->env.mlx, all->env.win, 10, 60, 0x98CD00,\
			"Zoom : Scroll mouse .");
		mlx_string_put(all->env.mlx, all->env.win, 10, 80, 0x98CD00,\
			"Navigation : Arrows .");
		mlx_string_put(all->env.mlx, all->env.win, 10, 100, 0x98CD00,\
			"Rot : -Clock: 9     .");
		mlx_string_put(all->env.mlx, all->env.win, 10, 120, 0x98CD00,\
			"      -AntiClock: 8 .");
		all->re = 0;
	}
	return (0);
}

int				key_hook(int keycode, t_all *all)
{
	if (keycode == 65307)
		all->re = -1;
	if (keycode == 65362)
		move_up(all);
	if (keycode == 65364)
		move_down(all);
	if (keycode == 65361)
		move_left(all);
	if (keycode == 65363)
		move_right(all);
	if (keycode == 65451)
		height_up(all);
	if (keycode == 65453)
		height_down(all);
	if (keycode == 65464)
		rot_hor(all);
	if (keycode == 65465)
		rot_ahor(all);
	return (0);
}

int				mouse_hook(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		all->zoom++;
		all->alt++;
		all->re = 1;
	}
	if (button == 5)
	{
		if (all->alt)
			all->alt--;
		if (all->zoom)
			all->zoom--;
		all->re = 1;
	}
	return (0);
}

int				expose_hook(t_all *all)
{
	mlx_put_image_to_window(all->env.mlx, all->env.win,\
		all->img.img, 0, 0);
	mlx_string_put(all->env.mlx, all->env.win, 10, 20, 0x98CD00,\
		"Height change : +/-.");
	mlx_string_put(all->env.mlx, all->env.win, 10, 40, 0x98CD00,\
		"Zoom : Scroll mouse.");
	mlx_string_put(all->env.mlx, all->env.win, 10, 60, 0x98CD00,\
		"Navigation : Arrows.");
	return (0);
}
