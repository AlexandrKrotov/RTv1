/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:23:15 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 15:23:16 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_calc_light_init(t_all *all, int *size, t_rgb *m, t_irgb *c_int)
{
	*size = 0;
	*c_int = (t_irgb){0, 0, 0};
	*m = (t_rgb){0, 0, 0, 0};
	all->flags.shadow = 0;
}

void		ft_not_shadow(const t_all *all, const t_light *ptr, t_rgb *max)
{
	max->r = (UC)fmin(((all->phong.amb.r
		+ all->phong.dif.r
		+ all->phong.spc.r * all->rt.spc_int)
		* ptr->power), 255);
	max->g = (UC)fmin(((all->phong.amb.g
						+ all->phong.dif.g
						+ all->phong.spc.g * all->rt.spc_int)
						* ptr->power), 255);
	max->b = (UC)fmin(((all->phong.amb.b
						+ all->phong.dif.b
						+ all->phong.spc.b * all->rt.spc_int)
						* ptr->power), 255);
	max->opacity = 0;
}

void		ft_calc_shadow(const t_all *all, t_rgb *max)
{
	*max = all->phong.dif;
	*max = (t_rgb) {(UC)(max->r * SHADOW),
					(UC)(max->g * SHADOW),
					(UC)(max->b * SHADOW), 0};
}

void		ft_sum_light(t_all *all, t_light *ptr, t_irgb *c_int, t_rgb *max)
{
	all->flags.shadow = ft_shadow_ray(all, ptr);
	if (!all->flags.shadow)
		ft_not_shadow(all, ptr, max);
	else
		ft_calc_shadow(all, max);
	c_int->r += max->r;
	c_int->g += max->g;
	c_int->b += max->b;
}

t_rgb		ft_light_calc(t_all *all, t_rgb *color)
{
	int			size;
	t_light		*ptr;
	t_irgb		color_int;
	t_rgb		max;

	ptr = all->light;
	ft_calc_light_init(all, &size, &max, &color_int);
	while (ptr != NULL)
	{
		size++;
		all->phong = ft_phong(&all->rt, color, *ptr->o, all->cam);
		ft_sum_light(all, ptr, &color_int, &max);
		ptr = ptr->next;
	}
	if (size == 0)
	{
		all->phong = ft_phong(&all->rt, color, all->light_default, all->cam);
		return (all->phong.amb);
	}
	max.r = (UC)fmin(255, color_int.r);
	max.g = (UC)(int)fmin(255, color_int.g);
	max.b = (UC)fmin(255, color_int.b);
	return (max);
}
