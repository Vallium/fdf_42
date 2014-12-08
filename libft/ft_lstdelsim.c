/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelsim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:43:53 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/08 15:39:48 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdelsim(t_list **alst)
{
	if (*alst)
	{
		ft_lstdelsim(&(*alst)->next);
		ft_lstdelonesim(alst);
	}
}
