/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 22:35:11 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/08 15:41:36 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>

void			ft_free_map(t_map map)
{
	while (map.max.y--)
		free(map.map[map.max.y]);
	free(map.map);
}

t_3dpos			**ft_fill_map(t_list *lst, t_3dpos pt)
{
	t_3dpos		**tab;
	int			i;

	i = 0;
	tab = (t_3dpos**)malloc(sizeof(t_3dpos*) * pt.y);
	while (i < pt.y)
		tab[i++] = (t_3dpos*)malloc(sizeof(t_3dpos) * pt.x);
	while (lst)
	{
		pt = *((t_3dpos*)lst->content);
		pt.z = -pt.z;
		tab[pt.y][pt.x] = pt;
		lst = lst->next;
	}
	ft_lstdelsim(&lst);
	return (tab);
}

t_map			ft_read_map(int fd, char c)
{
	char		*tmp;
	char		**tabx;
	t_3dpos		pt;
	t_list		*lst;
	t_map		map;

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
	map.map = ft_fill_map(lst, pt);
	map.max.x = pt.x;
	map.max.y = pt.y;
	return (map);
}
