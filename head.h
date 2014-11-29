/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:46:38 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/29 13:43:48 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H

# define HEAD_H

# include "libft/includes/get_next_line.h"
# include <math.h>

typedef struct			s_env
{
	void				*mlx;
	void				*win;
}						t_env;

typedef struct			s_pt
{
	int					x;
	int					y;
}						t_pt;

typedef struct			s_pt_mouse
{
	int					x;
	int					y;
}						t_pt_mouse;

typedef struct			s_3dpos
{
	int					x;
	int					y;
	int					z;
}						t_3dpos;

#endif
