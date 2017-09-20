/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:13:50 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 16:13:51 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*ft_init_sphere(t_vertex ray_o, t_rgb color, double radius)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->center = ray_o;
	sphere->color = color;
	sphere->radius = radius;
	sphere->r2 = sphere->radius * sphere->radius;
	sphere->n = 10;
	sphere->amb_int = 0.1;
	sphere->dif_int = 1;
	sphere->spc_int = .5;
	return (sphere);
}

void		ft_add_sphere(t_objs *scene, t_vertex ray_o, t_rgb color, double r)
{
	t_objs		*ptr;

	ptr = NULL;
	ptr = ft_find_empty(scene, ptr);
	ptr->obj = ft_init_sphere(ray_o, color, r);
	ptr->ft_inter = ft_sphere_intersect;
	ptr->ft_info = ft_get_info_sphere;
}

void		ft_get_norm_sphere(t_rt *rt, t_objs *ptr)
{
	t_sphere	*s;

	s = ptr->obj;
	rt->norm = ft_sub_vec(rt->inter, s->center);
	rt->norm = ft_divide_vec_double(rt->norm, s->radius);
}

void		ft_get_info_sphere(t_rt *rt, t_ray *ray, t_objs *ptr)
{
	t_sphere	*s;
	t_vertex	tmp;

	s = ptr->obj;
	tmp = ft_m_v_d(ray->d, rt->t);
	rt->inter = ft_sum_vec(ray->o, tmp);
	ft_get_norm_sphere(rt, ptr);
	rt->rgb = s->color;
	rt->n = s->n;
	rt->amb_int = s->amb_int;
	rt->dif_int = s->dif_int;
	rt->spc_int = s->spc_int;
}

int			ft_sphere_intersect(t_rt *rt, t_ray *ray, t_objs *ptr)
{
	struct s_sphere_param	p;

	p.s = ptr->obj;
	p.oc = ft_sub_vec(ray->o, p.s->center);
	p.b = 2 * ft_dot(p.oc, ray->d);
	p.c = ft_dot(p.oc, p.oc) - p.s->r2;
	p.disc = p.b * p.b - 4 * p.c;
	if (p.disc < 1e-6)
		return (FALSE);
	p.disc = sqrt(p.disc);
	p.t0 = (-p.b - p.disc) / 2;
	p.t1 = (-p.b + p.disc) / 2;
	p.t0 = (p.t0 < p.t1 && (p.t0 > 0 || p.t1 > 0)) ? p.t0 : p.t1;
	if (p.t0 > 1e-6 && p.t0 < rt->t)
	{
		rt->t = p.t0;
		return (TRUE);
	}
	return (FALSE);
}
