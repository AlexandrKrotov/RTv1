/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:15:41 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 15:15:42 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init_scene(t_all *all)
{
	all->scene = malloc(sizeof(t_objs));
	all->scene->obj = NULL;
	all->scene->ft_inter = NULL;
	all->scene->ft_info = NULL;
	all->scene->next = NULL;
}

void	ft_init_light(t_all *all)
{
	all->light = malloc(sizeof(t_vertex));
	all->light->o = NULL;
	all->light->next = NULL;
}

void	init_all(t_all *all)
{
	all->mlx = malloc(sizeof(t_mlx));
	all->mlx->mlx = mlx_init();
	all->mlx->wnd = mlx_new_window(all->mlx->mlx, D_WIDTH, D_HEIGHT, D_NAME);
	all->dsp.dsp_w = D_WIDTH;
	all->dsp.dsp_h = D_HEIGHT;
	all->dsp.half_h = all->dsp.dsp_h / 2;
	all->dsp.half_w = all->dsp.dsp_w / 2;
	all->dsp.rend_hs = -all->dsp.half_h;
	all->dsp.rend_he = all->dsp.half_h;
	all->dsp.rend_ws = -all->dsp.half_w;
	all->dsp.rend_we = all->dsp.half_w;
	all->cam = (t_vertex){0, 0, -1000};
	all->light_default = all->cam;
	all->light = NULL;
	all->trans.zoom = 0;
	all->trans.shift = 0;
	all->rt.rgb = (t_rgb){0, 0, 0, 0};
	all->rt.norm = (t_vertex){0, 0, 0};
	all->flags.redraw = TRUE;
	all->flags.aliasing = FALSE;
	ft_init_scene(all);
	ft_init_light(all);
}
