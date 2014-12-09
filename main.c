/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:17:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/12/04 22:23:52 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			ft_free_all(t_all *all)
{
	ft_free_map(all->map);
	mlx_destroy_image(all->env.mlx, all->img.img);
	free(all->env.mlx);
	free(all->env.win);
	free(all);
	exit (0);
}

t_all			*ft_all_init(t_all *all)
{
	all->re = 1;
	all->zoom = 20;
	all->alt = 1;
	all->posimg.y = WIN_SZ_Y / 8;
	all->posimg.x = WIN_SZ_X / 2;
	return (all);
}

void			ft_is_fd(int fd, char *av)
{
	if (fd == -1)
	{
		ft_putstr_fd("fdf: ", 2);
		ft_putstr_fd(&av[1], 2);
		ft_putendl_fd(": Does not exists or is invalid.", 2);
		exit (0);
	}
}

void			ft_ac_error(int ac)
{
	if (ac != 2)
	{
		ft_putendl_fd("fdf: Map missing, or please put only one argument.", 2);
		exit (0);
	}
}

int				main(int ac, char **av)
{
	int			fd;
	t_all		*all;

	ft_ac_error(ac);
	fd = open(av[1], O_RDONLY);
	ft_is_fd(fd, av[1]);
	all = (t_all*)malloc(sizeof(t_all));
	all->env.mlx = mlx_init();
	all->env.win = mlx_new_window(all->env.mlx, WIN_SZ_X, WIN_SZ_Y, "F_D_F");
	all = ft_all_init(all);
	all->name = av[1];
	all->map = ft_read_map(fd, ' ');
	all->img.img = mlx_new_image(all->env.mlx, WIN_SZ_X, WIN_SZ_Y);
	all->img.data = mlx_get_data_addr(all->img.img, &all->img.bpp,\
			&all->img.sizeline, &all->img.endian);
	mlx_key_hook(all->env.win, key_hook, all);
	mlx_mouse_hook(all->env.win, mouse_hook, all);
	mlx_loop_hook(all->env.mlx, loop_hook, all);
	mlx_expose_hook(all->env.win, expose_hook, all);
	mlx_loop(all->env.mlx);
	return (0);
}
