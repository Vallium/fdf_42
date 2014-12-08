/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:46:38 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/04 22:22:49 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H

# define HEAD_H

# define WIN_SZ_X 2560
# define WIN_SZ_Y 1440
# define POS_IMG_X 950
# define POS_IMG_Y -50

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

typedef struct	s_map
{
	t_3dpos		**map;
	t_pos		max;
}				t_map;

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
	t_pos		inc;
	int			dx;
	int			dy;
}				t_line;

typedef struct	s_img
{
	int			*img;
	int			bpp;
	int			sizeline;
	int			endian;
	int			clrline;
	char		*data;
}				t_img;

typedef struct	s_all
{
	t_env		env;
	t_map		map;
	t_img		img;
	size_t		re;
	int			alt;
	int			zoom;
	t_pos		posimg;
}				t_all;

int				key_hook(int keycode, t_all *all);
int				mouse_hook(int button, int x, int y, t_all *all);
int				loop_hook(t_all *all);
int				ft_clr_to_int(t_color c);
void			ft_put_pxl_img(t_all *all, t_pos pt);
void			ft_line_put(t_all *all, t_pos p1, t_pos p2);
void			ft_line_put_1(t_all *all, t_line line);
void			ft_line_put_2(t_all *all, t_line line);
void			ft_put_linesub(t_all *all);
void			ft_3d_line(t_all *all, t_3dpos dp1, t_3dpos dp2);
void			ft_put_3d_map(t_all *all);
void			move_up(t_all *all);
void			move_down(t_all *all);
void			move_left(t_all *all);
void			move_right(t_all *all);
t_all			*ft_all_init(t_all *all);
t_pos			ft_3d_to_2d(t_3dpos dp1);
t_map			ft_read_map(int fd, char c);
t_3dpos			**ft_fill_map(t_list *lst, t_3dpos pt);

#endif
