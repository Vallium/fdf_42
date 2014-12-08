/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 22:34:44 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/05 11:08:48 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			color_alt(t_all *all, int z)
{
	if (all->alt == 0)
		all->img.clrline = 0x7FC6BC;
	else if ((-z / all->alt) <= -2)
		all->img.clrline = 0x4BB5C1;
	else if ((-z / all->alt) <= 0)
		all->img.clrline = 0x7FC6BC;
	else if ((-z / all->alt) <= 4)
		all->img.clrline = 0x93B550;
	else if ((-z / all->alt) <= 6)
		all->img.clrline = 0x98CC50;
	else if ((-z / all->alt) <= 8)
		all->img.clrline = 0xB39167;
	else if ((-z / all->alt) <= 10)
		all->img.clrline = 0xBA9D7A;
	else if ((-z / all->alt) <= 12)
		all->img.clrline = 0xCAA986;
	else
		all->img.clrline = 0xEDF7F2;
}

t_pos			ft_3d_to_2d(t_3dpos dp1, t_all *all)
{
	t_pos		p1;

	dp1.x -= sqrt((all->map.max.x * all->map.max.x * all->zoom) +
		(all->map.max.y * all->map.max.y * all->zoom) / 2);
	dp1.y -= sqrt((all->map.max.x * all->map.max.x * all->zoom) +
		(all->map.max.y * all->map.max.y * all->zoom) / 2);
	dp1.x = dp1.x * cos(all->r) - dp1.y * sin(all->r);
	dp1.y = dp1.x * sin(all->r) + dp1.y * cos(all->r);
	p1.x = dp1.x - dp1.y;
	p1.y = dp1.z + (dp1.x / 2.0) + (dp1.y / 2.0);
	return (p1);
}

void			ft_put_pxl_img(t_all *all, t_pos pt)
{
	if (pt.x > 0 && pt.x < WIN_SZ_X && pt.y > 0 && pt.y < WIN_SZ_Y)
		ft_memcpy(&all->img.data[(pt.x * 4) + (pt.y * all->img.sizeline)],\
				&(all->img.clrline), (size_t)(sizeof(int)));
}

void			ft_put_3d_map(t_all *all)
{
	int			x;
	int			y;

	y = 0;
	color_alt(all, all->map.map[0][0].z);
	while (y < (all->map.max.y - 1))
	{
		x = 0;
		while (x < (all->map.max.x - 1))
		{
			ft_3d_line(all, all->map.map[y][x], all->map.map[y][x + 1]);
			ft_3d_line(all, all->map.map[y][x], all->map.map[y + 1][x]);
			x++;
		}
		y++;
	}
	ft_put_linesub(all);
}

void			ft_put_linesub(t_all *all)
{
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (y + 1 < all->map.max.y)
	{
		ft_3d_line(all, all->map.map[y][all->map.max.x - 1],\
				all->map.map[y + 1][all->map.max.x - 1]);
		y++;
	}
	while (x + 1 < all->map.max.x)
	{
		ft_3d_line(all, all->map.map[all->map.max.y - 1][x],\
				all->map.map[all->map.max.y - 1][x + 1]);
		x++;
	}
}
