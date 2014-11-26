/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:34:24 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/26 14:44:54 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

void				draw(void *mlx, void *win)
{
	t_pt			pt;

	pt.y = 100;
	while (pt.y++ <= 200)
	{
		pt.x = 100;
		while (pt.x++ <= 200)
		{
			mlx_pixel_put(mlx, win, pt.x, pt.y, 0xDD985C);
			usleep(500);
		}
	}
}

int					expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int					key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int					mouse_hook(int button, int x, int y, t_env *e)
{
	printf("Mouse = %d (%d:%d)\n", button, x, y);
	return (0);
}

int					main(int ac, char **av)
{
	t_env			e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
