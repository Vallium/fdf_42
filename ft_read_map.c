/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:09:24 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/28 15:51:06 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	}
}
