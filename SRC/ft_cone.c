/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:54:38 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 15:00:21 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone		*ft_init_cone(t_vertex ray_o, t_vertex ray_d, t_rgb color, double a)
{
	t_cone	*cone;

	cone = malloc(sizeof(t_cone));
	cone->ray.o = ray_o;
	cone->ray.d = ray_d;
	cone->color = color;
	cone->alpha = a;
	cone->rad = cone->alpha * M_PI / 180;
	cone->cos2 = cos(cone->rad) * cos(cone->rad);
	cone->sin2 = sin(cone->rad) * sin(cone->rad);
	cone->n = 20;
	cone->amb_int = 0.1;
	cone->dif_int = 1;
	cone->spc_int = 1;
	return (cone);
}

void		ft_add_cone(t_objs *scene, t_ray ray, t_rgb color, double angle)
{
	t_objs *ptr;

	ptr = NULL;
	ptr = ft_find_empty(scene, ptr);
	ptr->obj = ft_init_cone(ray.o, ray.d, color, angle);
	ptr->ft_inter = ft_cone_intersect;
	ptr->ft_info = ft_get_info_cone;
}

void		ft_get_info_cone(t_rt *rt, t_ray *ray, t_objs *ptr)
{
	t_cone		*con;
	t_vertex	a;
	t_vertex	b;
	t_vertex	scaled;
	t_vertex	tmp;

	con = ptr->obj;
	tmp = ft_m_v_d(ray->d, rt->t);
	rt->inter = ft_sum_vec(ray->o, tmp);
	b = ft_sub_vec(rt->inter, con->ray.o);
	a = ft_m_v_d(con->ray.d, ft_cos_vector(b, con->ray.d));
	rt->norm = ft_sub_vec(b, a);
	scaled = ft_cross_vector(b, rt->norm);
	rt->norm = ft_cross_vector(scaled, b);
	rt->norm = ft_normalized_vector(rt->norm);
	rt->rgb = con->color;
	rt->n = con->n;
	rt->amb_int = con->amb_int;
	rt->dif_int = con->dif_int;
	rt->spc_int = con->spc_int;
}

int			ft_cone_intersect(t_rt *rt, t_ray *ray, t_objs *ptr)
{
	struct s_cone_param		p;

	p.con = ptr->obj;
	p.oc = ft_sub_vec(ray->o, p.con->ray.o);
	p.dot_v = ft_dot(ray->d, p.con->ray.d);
	p.dot_p = ft_dot(p.oc, p.con->ray.d);
	p.av = ft_sub_vec(ray->d, ft_m_v_d(p.con->ray.d, p.dot_v));
	p.cv = ft_sub_vec(p.oc, ft_m_v_d(p.con->ray.d, p.dot_p));
	p.a = p.con->cos2 * ft_dot(p.av, p.av) - p.con->sin2 * (p.dot_v * p.dot_v);
	p.b = 2 * p.con->cos2 * ft_dot(p.av, p.cv) -
										2 * p.con->sin2 * (p.dot_v) * (p.dot_p);
	p.c = p.con->cos2 * ft_dot(p.cv, p.cv) - p.con->sin2 * (p.dot_p * p.dot_p);
	p.disc = p.b * p.b - 4 * p.a * p.c;
	if (p.disc < 1e-6)
		return (FALSE);
	p.disc = sqrt(p.disc);
	p.t0 = (-p.b - p.disc) / (2 * p.a);
	p.t1 = (-p.b + p.disc) / (2 * p.a);
	p.t0 = (p.t0 < p.t1 && (p.t0 > 0 || p.t1 > 0)) ? p.t0 : p.t1;
	if (p.t0 > 1e-6 && p.t0 < rt->t)
	{
		rt->t = p.t0;
		return (TRUE);
	}
	return (FALSE);
}
