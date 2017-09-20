/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:07:24 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 15:07:26 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cylinder	*ft_init_cyl(t_vertex o, t_vertex d, t_rgb color, double radius)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->ray.o = o;
	cylinder->ray.d = d;
	cylinder->r = radius;
	cylinder->r2 = cylinder->r * cylinder->r;
	cylinder->color = color;
	cylinder->n = 30;
	cylinder->amb_int = 0.1;
	cylinder->dif_int = 1;
	cylinder->spc_int = 1;
	return (cylinder);
}

void		ft_add_cyl(t_objs *scene, t_ray ray, t_rgb color, double radius)
{
	t_objs *ptr;

	ptr = NULL;
	ptr = ft_find_empty(scene, ptr);
	ptr->obj = ft_init_cyl(ray.o, ray.d, color, radius);
	ptr->ft_inter = ft_cylinder_intersect;
	ptr->ft_info = ft_get_info_cylinder;
}

void		ft_get_info_cylinder(t_rt *rt, t_ray *ray, t_objs *ptr)
{
	t_cylinder	*cyl;
	t_vertex	a;
	t_vertex	gip;
	t_vertex	bn;
	t_vertex	tmp;

	cyl = ptr->obj;
	tmp = ft_m_v_d(ray->d, rt->t);
	rt->inter = ft_sum_vec(ray->o, tmp);
	gip = ft_sub_vec(rt->inter, cyl->ray.o);
	a = ft_m_v_d(cyl->ray.d, ft_dot(gip, cyl->ray.d));
	bn = ft_sub_vec(gip, a);
	rt->norm = ft_normalized_vector(bn);
	rt->rgb = cyl->color;
	rt->n = cyl->n;
	rt->amb_int = cyl->amb_int;
	rt->dif_int = cyl->dif_int;
	rt->spc_int = cyl->spc_int;
}

int			ft_cylinder_intersect(t_rt *rt, t_ray *ray, t_objs *ptr)
{
	struct s_cylinder_param p;

	p.cyl = ptr->obj;
	p.oc = ft_sub_vec(ray->o, p.cyl->ray.o);
	p.av = ft_sub_vec(ray->d, ft_m_v_d(p.cyl->ray.d,
	ft_dot(ray->d, p.cyl->ray.d)));
	p.cv = ft_sub_vec(p.oc, ft_m_v_d(p.cyl->ray.d, ft_dot(p.oc, p.cyl->ray.d)));
	p.a = ft_dot(p.av, p.av);
	p.b = 2 * ft_dot(p.av, p.cv);
	p.c = ft_dot(p.cv, p.cv) - p.cyl->r2;
	p.disc = p.b * p.b - 4 * p.a * p.c;
	if (p.disc < 1e-6)
		return (FALSE);
	p.disc = sqrt(p.disc);
	p.t0 = (-p.b + p.disc) / (2 * p.a);
	p.t1 = (-p.b - p.disc) / (2 * p.a);
	p.t0 = (p.t0 < p.t1 && (p.t0 > 0 || p.t1 > 0)) ? p.t0 : p.t1;
	if (p.t0 > 1e-6 && p.t0 < rt->t)
	{
		rt->t = p.t0;
		return (TRUE);
	}
	return (FALSE);
}
