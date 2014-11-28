/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:09:24 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/28 16:30:59 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3dpos				ft_read_map(char c)
{
	char			**tmp;
	char			**tabx;
	int				fd;
	int				x;
	int				y;
	int				z;
	t_3dpos			pt;

	fd = open("42.fdf", O_RDONLY);
	*tmp = ft_strnew(0);
	y = 0;
	while (get_next_line(fd, tmp))
	{
		ft_lstnew(&pt, sizeof(t_3dpos));
		x = 0;
		tabx = ft_strsplit((const char *)tmp, c);
		while (**tabx)
		{
			z = ft_atoi(*tabx);
			*tabx++;
			y++;
		}
		x++;
	}
}
