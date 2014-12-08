/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:49:35 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/05 15:50:06 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			move_up(t_all *all)
{
	all->posimg.y -= 5;
	all->re = 1;
}

void			move_down(t_all *all)
{
	all->posimg.y += 5;
	all->re = 1;
}

void			move_left(t_all *all)
{
	all->posimg.x -= 5;
	all->re = 1;
}

void			move_right(t_all *all)
{
	all->posimg.x += 5;
	all->re = 1;
}
