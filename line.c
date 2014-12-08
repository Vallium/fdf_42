/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:36:03 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/05 15:36:07 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			ft_line_put(t_all *all, t_pos p1, t_pos p2)
{
	t_line		line;

	line.inc.x = ((p2.x - p1.x) > 0) ? 1 : -1;
	line.inc.y = ((p2.y - p1.y) > 0) ? 1 : -1;
	line.dx = abs(p2.x - p1.x);
	line.dy = abs(p2.y - p1.y);
	line.p1 = p1;
	line.p2 = p2;
	ft_put_pxl_img(all, line.p1);
	if (line.dx > line.dy)
		ft_line_put_1(all, line);
	else
		ft_line_put_2(all, line);
}

void			ft_line_put_1(t_all *all, t_line line)
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
		ft_put_pxl_img(all, line.p1);
	}
}

void			ft_line_put_2(t_all *all, t_line line)
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
		ft_put_pxl_img(all, line.p1);
	}
}

void			ft_3d_line(t_all *all, t_3dpos dp1, t_3dpos dp2)
{
	t_pos		p1;
	t_pos		p2;

	dp1.x = dp1.x * all->zoom;
	dp1.y = dp1.y * all->zoom;
	dp2.x = dp2.x * all->zoom;
	dp2.y = dp2.y * all->zoom;
	dp1.z *= all->alt;
	dp2.z *= all->alt;
	color_alt(all, dp1.z);
	p1 = ft_3d_to_2d(dp1, all);
	p2 = ft_3d_to_2d(dp2, all);
	p1.x += all->posimg.x;
	p1.y += all->posimg.y;
	p2.x += all->posimg.x;
	p2.y += all->posimg.y;
	ft_line_put(all, p1, p2);
}
