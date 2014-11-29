/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:17:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/29 20:16:07 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

t_pos	ft_3d_to_2d(t_3dpos dp1)
{
	// float cst1 = 1;
	// float cst2 = 1;
	t_pos p1;

	p1.x = dp1.x - dp1.y;
	p1.y = dp1.z + (dp1.x / 2) + (dp1.y / 2);

	return (p1);
}

int		ft_color_to_int(t_color color)
{
	int c;

	c = color.r;
	c = c << 8;
	c += color.g;
	c = c << 8;
	c += color.b;
	return (c);
}

void	ft_put_pixel(t_env env, t_pos point, t_color color)
{
	mlx_pixel_put(env.mlx, env.win, point.x, point.y, ft_color_to_int(color));
}

void	ft_line_put(t_env env, t_pos p1, t_pos p2, t_color color)
{
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;

	p2.x -= p1.x;
	p2.y -= p1.y;
	xinc = (p2.x > 0) ? 1 : -1;
	yinc = (p2.y > 0) ? 1 : -1;
	p2.x = abs(p2.x);
	p2.y = abs(p2.y);
  	ft_put_pixel(env, p1, color);
  	i = 1;
  	if (p2.x > p2.y)
  	{
    	cumul = p2.x / 2 ;
    	while (i <= p2.x)
    	{
			p1.x += xinc ;
			cumul += p2.y ;
			if ( cumul >= p2.x )
			{
				cumul -= p2.x ;
				p1.y += yinc;
			}
    	  	ft_put_pixel(env, p1, color); 
 			i++;
 		}
 	}
    else
    {
    	cumul = p2.y / 2;
    	while (i <= p2.y)
    	{
			p1.y += yinc;
			cumul += p2.x;
			if ( cumul >= p2.y )
			{
				cumul -= p2.y;
				p1.x += xinc;
			}
				ft_put_pixel(env, p1, color);
			i++;
  		}
	}
}

void	ft_3d_line_put(t_env env, t_3dpos dp1, t_3dpos dp2, t_color color)
{
	t_pos p1;
	t_pos p2;

	dp1.x = dp1.x * 20 + 800;
	dp1.y = dp1.y * 20 + 400;
	//dp1.z *= 102
	dp2.x = dp2.x * 20 + 800;
	dp2.y = dp2.y * 20 + 400;
	//dp2.z *= 10;
	p1 = ft_3d_to_2d(dp1);
	p2 = ft_3d_to_2d(dp2);
	ft_line_put(env, p1, p2, color);
}

void	ft_put_3d_tab(t_env env, t_3dpos **tab, t_color color, t_pos max)
{
	int x;
	int y;



	y = 0;
	while (y + 1 < max.y)
	{
		x = 0;

		while (x + 1 < max.x)
		{
			ft_3d_line_put(env, tab[y][x], tab[y][x + 1], color);
			ft_3d_line_put(env, tab[y][x], tab[y + 1][x], color);	
			x++;
		}
		y++;
	}
	y = 0;
	x = 0;
	while (y + 1 < max.y)
	{
		ft_3d_line_put(env, tab[y][max.x - 1], tab[y + 1][max.x - 1], color);
		y++;
	}
	while (x + 1 < max.x)
	{
		ft_3d_line_put(env, tab[max.y - 1][x], tab[max.y - 1][x + 1], color);
		x++;
	}
}

t_3dpos				**ft_fill_tab(t_list *lst, t_3dpos pt)
{
	t_3dpos			**tab;
	int				i;

	i = 0;
	tab = (t_3dpos**)malloc(sizeof(t_3dpos*) * pt.y);
	while (i < pt.y)
		tab[i++] = (t_3dpos*)malloc(sizeof(t_3dpos) * pt.x);
	while (lst->next)
	{
		pt = *((t_3dpos*)lst->content);
//		printf("%d %d = %d\n", pt.x, pt.y, pt.z);
		pt.z = -pt.z;
		tab[pt.y][pt.x] = pt;
		lst = lst->next;
	}
	return (tab);
}

t_all				ft_read_map(int fd, char c)
{
	char			*tmp;
	char			**tabx;
	t_3dpos			pt;
	t_3dpos			**tab;
	t_list			*lst;
	t_all			all;

	lst = NULL;
	pt.y = 0;
	while (get_next_line(fd, &tmp))
	{
		pt.x = 0;
		tabx = ft_strsplit(tmp, c);
		while (*tabx)
		{
			pt.z = ft_atoi(*tabx);
			ft_lstadd(&lst, ft_lstnew(&pt, sizeof(t_3dpos)));
			tabx++;
			pt.x++;
		}
		pt.y++;
	}
	tab = ft_fill_tab(lst, pt);
	all.tab = tab;
	all.max.x = pt.x;
	all.max.y = pt.y;
	return (all);
}

int					key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit (0);
	return (0);
}

int					main(void)
{
	int				fd;
	t_env			env;
	t_color			blue = {0, 0, 0xFF};
	t_all			all;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 2400, 1200, "F_D_F");
	mlx_key_hook(env.win, key_hook, &env);
	fd = open("42.fdf", O_RDONLY);
	all = ft_read_map(fd, ' ');
	ft_put_3d_tab(env, all.tab, blue, all.max);
	mlx_loop(env.mlx);
	return (0);
}
