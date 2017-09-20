/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:17:38 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 16:34:38 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_change_scene(t_all *all, char *scene)
{
	if (!ft_strcmp(scene, "sphere"))
		ft_scene_init_sphere(all);
	else if (!ft_strcmp(scene, "plane"))
		ft_scene_init_plane(all);
	else if (!ft_strcmp(scene, "cone"))
		ft_scene_init_cone(all);
	else if (!ft_strcmp(scene, "cylinder"))
		ft_scene_init_cylinder(all);
	else if (!ft_strcmp(scene, "scene1"))
		ft_init_scene_1(all);
	else if (!ft_strcmp(scene, "random"))
		ft_init_scene_2(all);
	else if (!ft_strcmp(scene, "multilight"))
		ft_init_multilight(all);
	else
		ft_error(1);
}

void	ft_mlx_loops(t_all *all)
{
	mlx_mouse_hook(all->mlx->wnd, ft_mouse_hook, all);
	mlx_hook(all->mlx->wnd, 6, 1L << 6, ft_mouse_cord, all);
	mlx_hook(all->mlx->wnd, 2, 3, ft_key_hook, all);
	mlx_hook(all->mlx->wnd, 17, 1L << 17, ft_exit, NULL);
	mlx_loop_hook(all->mlx->mlx, ft_render, all);
	mlx_loop(all->mlx->mlx);
}

void	lets_start(char *scene)
{
	t_all	all;

	init_all(&all);
	ft_change_scene(&all, scene);
	ft_render(&all);
	ft_mlx_loops(&all);
}

int		main(int ac, char **av)
{
	int		stime;
	long	ltime;

	ltime = time(NULL);
	stime = (unsigned int)ltime / 2;
	srand((UC)stime);
	if (ac != 2)
		ft_error(1);
	else
		lets_start(av[1]);
	return (0);
}
