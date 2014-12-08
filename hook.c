/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:34:21 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/05 15:34:24 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

int				loop_hook(t_all *all)
{
	if (all->re)
	{
		ft_bzero(all->img.data, WIN_SZ_X * WIN_SZ_Y * 4);
		ft_put_3d_map(all);
		mlx_put_image_to_window(all->env.mlx, all->env.win,\
				all->img.img, 0, 0);
		all->re = 0;
	}
	return (0);
}

int				key_hook(int keycode, t_all *all)
{
	printf("Keycode = %d\n", keycode);
	if (keycode == 65307)
		exit (0);
	if (keycode == 65362)
		move_up(all);
	if (keycode == 65364)
		move_down(all);
	if (keycode == 65361)
		move_left(all);
	if (keycode == 65363)
		move_right(all);
	if (keycode == 'u')
	{	
		all->alt += 1;
		all->re = 1;
	}
	if (keycode == 'd')
	{
		if (all->alt)
			all->alt -= 1;
		all->re = 1;
	}
	return (0);
}

int				mouse_hook(int button, int x, int y, t_all *all)
{
	printf("Button = %d, x = %d, y = %d\n", button, x, y);
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
