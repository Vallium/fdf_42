/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:46:38 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/29 18:04:57 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H

# define HEAD_H

# include "libft/includes/get_next_line.h"
# include <math.h>
# include <mlx.h>

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

int						key_hook(int keycode, t_env *e);
t_3dpos					**ft_read_map(int fd, char c);
t_3dpos					**ft_fill_tab(t_list *lst, t_3dpos pt);

#endif
