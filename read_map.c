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

void			ft_dir_err(t_all *all, int erno)
{
	if (erno == -1)
	{
		free(all);
		ft_putstr_fd("fdf: The file you tried to open is a directory. ", 2);
		ft_putendl_fd("Put a valid map as argument.", 2);
		exit (0);
	}
}

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

void			ft_read_map(t_all *all, int fd, char c)
{
	char		*tmp;
	char		**tabx;
	t_list		*lst;
	int			erno;

	lst = NULL;
	all->map.max.y = 0;
	while ((erno = get_next_line(fd, &tmp)))
	{
		ft_dir_err(all, erno);
		all->map.max.x = 0;
		tabx = ft_strsplit(tmp, c);
		free(tmp);
		while (*tabx)
		{
			all->map.max.z = ft_atoi(*tabx);
			ft_lstadd(&lst, ft_lstnew(&all->map.max, sizeof(t_3dpos)));
			all->map.max.x++;
			free(*tabx++);
		}
		all->map.max.y++;
	}
	all->map.map = ft_fill_map(lst, all->map.max);
}
