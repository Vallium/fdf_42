/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 22:34:44 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/30 18:39:59 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
	ft_put_pixel(env, line.p1, line.clr);
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
//	dp1.z *= 10;
//	dp2.z *= 10;
	p1 = ft_3d_to_2d(dp1);
	p2 = ft_3d_to_2d(dp2);
	ft_line_put(env, p1, p2, clr);
}

void			ft_put_3d_tab(t_env env, t_3dpos **tab, t_color clr, t_pos max)
{
	int			x;
	int			y;

	y = 0;
//	ft_3d_line(env, tab[0][0], tab[10][5], clr);
	while (y < (max.y - 1))
	{
		x = 0;
		while (x < (max.x - 1))
		{
			ft_3d_line(env, tab[y][x], tab[y][x + 1], clr);
			ft_3d_line(env, tab[y][x], tab[y + 1][x], clr);
			x++;
		}
		y++;
	}
	ft_put_linesub(env, tab, clr, max);
}

void			ft_put_linesub(t_env env, t_3dpos **tab, t_color c, t_pos max)
{
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (y + 1 < max.y)
	{
		ft_3d_line(env, tab[y][max.x - 1], tab[y + 1][max.x - 1], c);
		y++;
	}
	while (x + 1 < max.x)
	{
		ft_3d_line(env, tab[max.y - 1][x], tab[max.y - 1][x + 1], c);
		x++;
	}
}
