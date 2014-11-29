/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:17:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/29 22:27:25 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

t_pos			ft_3d_to_2d(t_3dpos dp1)
{
	t_pos		p1;

	p1.x = dp1.x - dp1.y;
	p1.y = dp1.z + (dp1.x / 2) + (dp1.y / 2);
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

void			ft_line_put(t_env env, t_pos p1, t_pos p2, t_color clr)
{
	t_line		line;

	line.inc.x = ((p2.x - p1.x) > 0) ? 1 : -1;
	line.inc.y = ((p2.y - p1.y) > 0) ? 1 : -1;
	line.dx = abs(p2.x - p1.x);
	line.dy = abs(p2.y - p1.y);
	line.p1 = p1;
	line.p2 = p2;
	line.clr = clr;
	if (line.dx > line.dy)
		ft_line_put_1(env, line);
	else
		ft_line_put_2(env, line);
}

void			ft_line_put_1(t_env env, t_line line)
{
	int			i;
	int			cumul;

	i = 1;
	cumul = line.dx / 2;
	while (i++ <= line.dx)
	{
		line.p1.x += line.inc.x;
		cumul += line.dy;
		if (cumul >= line.dx)
		{
			cumul -= line.dx;
			line.p1.y += line.inc.y;
		}
		ft_put_pixel(env, line.p1, line.clr);
	}
}

void			ft_line_put_2(t_env env, t_line line)
{
	int			i;
	int			cumul;

	i = 1;
	cumul = line.dy / 2;
	while (i++ <= line.dy)
	{
		line.p1.y += line.inc.y;
		cumul += line.dx;
		if (cumul >= line.dy)
		{
			cumul -= line.dy;
			line.p1.x += line.inc.x;
		}
		ft_put_pixel(env, line.p1, line.clr);
	}
}

void			ft_3d_line(t_env env, t_3dpos dp1, t_3dpos dp2, t_color clr)
{
	t_pos		p1;
	t_pos		p2;

	dp1.x = dp1.x * 20 + 800;
	dp1.y = dp1.y * 20 + 400;
	dp2.x = dp2.x * 20 + 800;
	dp2.y = dp2.y * 20 + 400;
	p1 = ft_3d_to_2d(dp1);
	p2 = ft_3d_to_2d(dp2);
	ft_line_put(env, p1, p2, clr);
}

void			ft_put_3d_tab(t_env env, t_3dpos **tab, t_color clr, t_pos max)
{
	int			x;
	int			y;

	y = 0;
	while (y + 1 < max.y)
	{
		x = 0;
		while (x + 1 < max.x)
		{
			ft_3d_line(env, tab[y][x], tab[y][x + 1], clr);
			ft_3d_line(env, tab[y][x], tab[y + 1][x], clr);
			x++;
		}
		y++;
	}
	y = 0;
	x = 0;
	while (y + 1 < max.y)
		ft_3d_line(env, tab[y++][max.x - 1], tab[y + 1][max.x - 1], clr);
	while (x + 1 < max.x)
		ft_3d_line(env, tab[max.y - 1][x++], tab[max.y - 1][x + 1], clr);
}

t_3dpos			**ft_fill_tab(t_list *lst, t_3dpos pt)
{
	t_3dpos		**tab;
	int			i;

	i = 0;
	tab = (t_3dpos**)malloc(sizeof(t_3dpos*) * pt.y);
	while (i < pt.y)
		tab[i++] = (t_3dpos*)malloc(sizeof(t_3dpos) * pt.x);
	while (lst->next)
	{
		pt = *((t_3dpos*)lst->content);
		pt.z = -pt.z;
		tab[pt.y][pt.x] = pt;
		lst = lst->next;
	}
	return (tab);
}

t_all			ft_read_map(int fd, char c)
{
	char		*tmp;
	char		**tabx;
	t_3dpos		pt;
	t_list		*lst;
	t_all		all;

	lst = NULL;
	pt.y = 0;
	while (get_next_line(fd, &tmp))
	{
		pt.x = 0;
		tabx = ft_strsplit(tmp, c);
		free(tmp);
		while (*tabx)
		{
			pt.z = ft_atoi(*tabx++);
			ft_lstadd(&lst, ft_lstnew(&pt, sizeof(t_3dpos)));
			pt.x++;
		}
		pt.y++;
	}
	all.tab = ft_fill_tab(lst, pt);
	all.max.x = pt.x;
	all.max.y = pt.y;
	return (all);
}

int				key_hook(int keycode, t_env *e)
{
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
