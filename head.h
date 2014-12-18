/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:46:38 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/09 20:50:49 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H

# define HEAD_H

# define WIN_SZ_X 2880
# define WIN_SZ_Y 1800

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
	t_3dpos		max;
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
	int			re;
	int			alt;
	int			zoom;
	t_pos		posimg;
	float		adj;
	char		*name;
}				t_all;

int				key_hook(int keycode, t_all *all);
int				mouse_hook(int button, int x, int y, t_all *all);
int				loop_hook(t_all *all);
int				expose_hook(t_all *all);
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
void			alt_up(t_all *all);
void			alt_down(t_all *all);
void			adj_down(t_all *all);
void			adj_up(t_all *all);
void			cartridge(t_all *all);
void			ft_free_map(t_map map);
void			ft_free_all(t_all *all);
void			ft_ac_error(int ac);
void			ft_is_fd(int fd, char *av);
void			color_alt(t_all *all, int z);
void			ft_dir_err(t_all *all, int erno);
void			ft_read_map(t_all *all, int fd, char c);
t_all			*ft_all_init(t_all *all);
t_pos			ft_3d_to_2d(t_all *all, t_3dpos dp1);
t_3dpos			**ft_fill_map(t_list *lst, t_3dpos pt);

#endif
