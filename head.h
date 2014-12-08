/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:46:38 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/29 21:16:41 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H

# define HEAD_H

# define WIN_SIZE_X 2400
# define WIN_SIZE_Y 1200

# include "libft/includes/get_next_line.h"
# include <math.h>
# include <mlx.h>

typedef unsigned char	t_byte;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_3dpos
{
	int			x;
	int			y;
	int			z;
}				t_3dpos;

typedef struct	s_all
{
	t_3dpos		**tab;
	t_pos		max;
}				t_all;

typedef struct	s_color
{
	t_byte		r;
	t_byte		g;
	t_byte		b;
}				t_color;

typedef struct	s_line
{
	t_pos		p1;
	t_pos		p2;
	t_color		clr;
	t_pos		inc;
	int			dx;
	int			dy;
}				t_line;

int				key_hook(int keycode);
int				ft_color_to_int(t_color c);
void			ft_put_pixel(t_env env, t_pos point, t_color c);
void			ft_line_put(t_env env, t_pos p1, t_pos p2, t_color clr);
void			ft_line_put_1(t_env env, t_line line);
void			ft_line_put_2(t_env env, t_line line);
void			ft_put_linesub(t_env env, t_3dpos **tab, t_color c, t_pos max);
void			ft_3d_line(t_env env, t_3dpos dp1, t_3dpos dp2, t_color clr);
void			ft_put_3d_tab(t_env env, t_3dpos **tab, t_color c, t_pos max);
t_pos			ft_3d_to_2d(t_3dpos dp1);
t_all			ft_read_map(int fd, char c);
t_3dpos			**ft_fill_tab(t_list *lst, t_3dpos pt);
void			ft_3d_line_small(t_env env, t_3dpos dp1, t_3dpos dp2, t_color clr);

#endif
