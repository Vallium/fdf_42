/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:46:38 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/26 17:41:36 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft/libft.h"
# include <math.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_pt
{
	int				x;
	int				y;
}					t_pt;

typedef struct		s_pt_mouse
{
	int				x;
	int				y;
}					t_pt_mouse;

#endif
