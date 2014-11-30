/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:17:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/30 18:44:25 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

t_pos			ft_3d_to_2d(t_3dpos dp1)
{
	t_pos		p1;

	p1.x = dp1.x - dp1.y;
	p1.y = dp1.z + (dp1.x / 2.0) + (dp1.y / 2.0);
	return (p1);
}

int				ft_color_to_int(t_color clr)
{
	int			c;

	c = clr.r;
	c = c << 8;
	c += clr.g;
	c = c << 8;
	c += clr.b;
	return (c);
}

void			ft_put_pixel(t_env env, t_pos point, t_color clr)
{
	mlx_pixel_put(env.mlx, env.win, point.x, point.y, ft_color_to_int(clr));
}

int				key_hook(int keycode, t_env *e)
{
	printf("|%d = %c|\n", keycode, keycode);
	if (keycode == 65307)
		exit (0);
	return (0);
}

int				main(void)
{
	int			fd;
	t_env		env;
	t_color		blue = {0, 0, 0xFF};
	t_all		all;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_SIZE_X, WIN_SIZE_Y, "F_D_F");
	mlx_key_hook(env.win, key_hook, &env);
	fd = open("42.fdf", O_RDONLY);
	all = ft_read_map(fd, ' ');
	ft_put_3d_tab(env, all.tab, blue, all.max);
	mlx_loop(env.mlx);
	return (0);
}
