/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:09:24 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/29 16:22:15 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

t_3dpos				**ft_fill_tab(t_list *lst, t_3dpos pt)
{
	t_3dpos			**tab;

	tab = (t_3dpos**)malloc(sizeof(t_3dpos*) * pt.x);
	while (pt.x)
		tab[pt.x--] = (t_3dpos*)malloc(sizeof(t_3dpos) * pt.y);
	while (lst)
	{
		pt = *((t_3dpos*)lst->content);
		printf("%d %d = %d\n" ,pt.x, pt.y, pt.z);
		tab[pt.x][pt.y] = pt;
		lst = lst->next;
	}
	return (tab);
}

t_3dpos				**ft_read_map(char c)
{
	char			**tmp;
	char			**tabx;
	int				fd;
	t_3dpos			pt;
	t_3dpos			**tab;
	t_list			*lst;

	fd = open("42.fdf", O_RDONLY);
	pt.y = 0;
	while (get_next_line(fd, tmp))
	{
		pt.x = 0;
		tabx = ft_strsplit((const char *)tmp, c);
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
