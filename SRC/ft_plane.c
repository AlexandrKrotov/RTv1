/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:07:12 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 16:08:21 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane		*ft_init_plane(t_vertex ray_o, t_vertex ray_d, t_rgb color)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	plane->ray.d = ray_d;
	plane->ray.o = ray_o;
	plane->color = color;
	plane->n = 10;
	plane->amb_int = 0.1;
	plane->dif_int = 0.6;
	plane->spc_int = 1;
	return (plane);
}

void		ft_add_plane(t_objs *scene, t_vertex o, t_vertex d, t_rgb color)
{
	t_objs		*ptr;

	ptr = NULL;
	ptr = ft_find_empty(scene, ptr);
	ptr->obj = ft_init_plane(o, d, color);
	ptr->ft_inter = ft_plane_intersect;
	ptr->ft_info = ft_get_info_plane;
}

void		ft_get_info_plane(t_rt *rt, t_ray *ray, t_objs *ptr)
{
	t_plane		*p;
	t_vertex	tmp;

	p = ptr->obj;
	rt->rgb = p->color;
	tmp = ft_m_v_d(ray->d, rt->t);
	rt->inter = ft_sum_vec(ray->o, tmp);
	rt->norm = p->ray.d;
	rt->n = p->n;
	rt->amb_int = p->amb_int;
	rt->dif_int = p->dif_int;
	rt->spc_int = p->spc_int;
}

int			ft_plane_intersect(t_rt *rt, t_ray *ray, t_objs *ptr)
{
	t_plane		*p;
	t_vertex	oc;
	double		b;
	double		t;

	p = ptr->obj;
	b = (ft_dot(ray->d, p->ray.d));
	if (b != 0)
	{
		oc = ft_sub_vec(p->ray.o, ray->o);
		t = ft_dot(oc, p->ray.d);
		t = (t / b);
	}
	else
		return (FALSE);
	if (t > 1e-6 && t < rt->t)
	{
		rt->t = t - 1e-6;
		return (TRUE);
	}
	return (FALSE);
}
