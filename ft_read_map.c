/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:09:24 by aalliot           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/11/28 15:51:06 by aalliot          ###   ########.fr       */
=======
/*   Updated: 2014/11/28 19:38:19 by aalliot          ###   ########.fr       */
>>>>>>> 88b8666a8d9e241a572014f61946fdc0753bcd6b
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

<<<<<<< HEAD
t_3dpos				ft_read_map()
{
	char			**tmp;
	int				fd;
	int				x;
	int				y;
	int				z;
	t_3dpos			pt;

	fd = open("42.fdf", O_RDONLY);
	*tmp = ft_strnew(0);
	while (get_next_line(fd, tmp))
	{
=======
t_3dpos				*fill_tab(t_list *lst, t_3dpos pt)
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
	return (*tab);
}

t_3dpos				ft_read_map(char c)
{
	char			**tmp;
	char			**tabx;
	int				fd;
	t_3dpos			pt;
	t_list			*lst;

	fd = open("42.fdf", O_RDONLY);
	*tmp = ft_strnew(0);
	pt.y = 0;
	while (get_next_line(fd, tmp))
	{
		pt.x = 0;
		tabx = ft_strsplit((const char *)tmp, c);
		while (*tabx)
		{
			pt.z = ft_atoi(*tabx);
			ft_lstadd(&lst, ft_lstnew(&pt, sizeof(t_3dpos)));
			*tabx++;
			pt.x++;
		}
		pt.y++;
>>>>>>> 88b8666a8d9e241a572014f61946fdc0753bcd6b
	}
}
