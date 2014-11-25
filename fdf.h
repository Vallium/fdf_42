/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:46:38 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/25 19:41:33 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft/libft.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_3d
{
	int				x;
	int				y;
	int				z;
}					t_3d;

typedef struct		s_pt_mouse
{
	int				x;
	int				y;
}					t_pt_mouse;

#endif
