/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:17:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/29 18:05:34 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

t_3dpos				**ft_fill_tab(t_list *lst, t_3dpos pt)
{
	t_3dpos			**tab;
	int				i;

	i = 0;
	tab = (t_3dpos**)malloc(sizeof(t_3dpos*) * pt.x);
	while (i < pt.x)
		tab[i++] = (t_3dpos*)malloc(sizeof(t_3dpos) * pt.y);
	while (lst->next)
	{
		pt = *((t_3dpos*)lst->content);
		printf("%d %d = %d\n", pt.x, pt.y, pt.z);
		tab[pt.x][pt.y] = pt;
		lst = lst->next;
	}
	return (tab);
}

t_3dpos				**ft_read_map(int fd, char c)
{
	char			*tmp;
	char			**tabx;
	t_3dpos			pt;
	t_3dpos			**tab;
	t_list			*lst;

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
	return (tab);
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
	t_3dpos			**tab;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 2400, 1200, "F_D_F");
	mlx_key_hook(env.win, key_hook, &env);
	fd = open("42.fdf", O_RDONLY);
	tab = ft_read_map(fd, ' ');
	mlx_loop(env.mlx);
	return (0);
}
