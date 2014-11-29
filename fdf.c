/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:34:24 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/29 15:33:35 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

void				pixel_put(t_env env, t_pt pt)
{
	mlx_pixel_put(env.mlx, env.win, pt.x, pt.y, 0xDD985C);
}

void				print_tab(t_env env);

void				draw_lign(t_env env, t_pt pti, t_pt ptf)
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;

	dx = ptf.x - pti.x;
	dy = ptf.y - pti.y;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dx > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	i = 0;
	pixel_put(env, pti);
	if (dx > dy)
	{
		cumul = dx / 2;
		while (i++ <= dx)
		{
			pti.x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				pti.y += yinc;
			}
			pixel_put(env, pti);
		}
	}
	else
	{
		cumul = dy / 2;
		while (i++ <= dy)
		{
			pti.y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				pti.x += xinc;
			}
			pixel_put(env, pti);
		}
	}
}

/*
int					main(int ac, char **av)
{
	t_env			e;
	t_pt			pti;
	t_pt			ptf;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_key_hook(e.win, key_hook, &e);
	pti.x = 110;
	pti.y = 75;
	ptf.x = 10;
	ptf.y = 85;
	draw_lign(e, pti, ptf);
	mlx_loop(e.mlx);
	return (0);
}
*/
