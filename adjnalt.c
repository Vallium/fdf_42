/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjnalt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 18:18:52 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/09 18:18:54 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			alt_up(t_all *all)
{
	all->alt += 1;
	all->re = 1;
}

void			alt_down(t_all *all)
{
	if (all->alt)
		all->alt -= 1;
	all->re = 1;
}

void			adj_down(t_all *all)
{
	if (all->adj < 3.0)
		all->adj += 0.1;
	all->re = 1;
}

void			adj_up(t_all *all)
{
	if (all->adj > 1.0)
		all->adj -= 0.1;
	all->re = 1;
}
