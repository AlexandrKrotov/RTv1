/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Init_scene_part1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:16:20 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/20 19:23:25 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_scene_init_sphere(t_all *all)
{
	ft_add_light_lst(all->light, (t_vertex){500, -200, -700}, 0.7);
	ft_add_sphere(all->scene,
		(t_vertex){0, 0, 150},
			(t_rgb){255, 69, 0, 0}, 100);
}

void	ft_scene_init_plane(t_all *all)
{
	ft_add_light_lst(all->light, (t_vertex){500, -200, -700}, 0.5);
	ft_add_plane(all->scene, (t_vertex){0, 0, 2000},
		(t_vertex){0, 0, -1},
		(t_rgb){192, 192, 192, 0});
}

void	ft_scene_init_cone(t_all *all)
{
	ft_add_light_lst(all->light, (t_vertex){500, -200, -700}, 1);
	ft_add_cone(all->scene,
		(t_ray){{0, 0, 100}, {0, -1, 0}},
		(t_rgb){212, 175, 55, 0}, 30);
	ft_add_plane(all->scene,
		(t_vertex){0, 200, 0},
		(t_vertex){0, -1, 0},
		(t_rgb){192, 192, 192, 0});
}

void	ft_scene_init_cylinder(t_all *all)
{
	ft_add_light_lst(all->light, (t_vertex){500, 0, -700}, 1);
	ft_add_cyl(all->scene,
		(t_ray){{0, 0, 0}, {0, 1, 0}},
		(t_rgb) {21, 64, 85, 0}, 35);
}

void	ft_init_scene_1(t_all *all)
{
	ft_add_light_lst(all->light, (t_vertex){-300, -500, -700}, 0.5);
	ft_add_plane(all->scene, (t_vertex){0, 0, 2000},
		(t_vertex){0, 0, -1},
		(t_rgb){255, 255, 255, 0});
	ft_add_plane(all->scene,
		(t_vertex){400, 0, 0},
		(t_vertex){-1, 0, 0},
		(t_rgb){255, 255, 255, 0});
	ft_add_plane(all->scene,
		(t_vertex){0, 300, 0},
		(t_vertex){0, -1, 0},
		(t_rgb){100, 100, 100, 0});
	ft_add_cone(all->scene,
		(t_ray){{200, 0, 100}, {0, -1, 0}},
		(t_rgb){155, 155, 0, 0}, 20);
	ft_add_cyl(all->scene,
		(t_ray){{0, 0, 300}, {1, 0, 0}},
		(t_rgb) {21, 64, 85, 0}, 30);
	ft_add_sphere(all->scene,
		(t_vertex){-100, -100, 100},
		(t_rgb){255, 0, 0, 0}, 75);
	ft_add_sphere(all->scene,
		(t_vertex){0, 50, 100},
		(t_rgb){0, 255, 0, 0}, 50);
}
