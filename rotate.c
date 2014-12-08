/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 20:41:15 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/08 20:41:33 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			rot_hor(t_all *all)
{
	all->r -= 0.1;
	all->re = 1;
}

void			rot_ahor(t_all *all)
{
	all->r += 0.1;
	all->re = 1;
}

void			height_up(t_all *all)
{
	all->alt += 1;
	all->re = 1;
}

void			height_down(t_all *all)
{
	if (all->alt)
		all->alt -= 1;
	all->re = 1;
}
