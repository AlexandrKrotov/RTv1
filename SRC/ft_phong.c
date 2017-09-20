/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:49:11 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 15:49:12 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_rgb		ft_phong_ambiand(const t_rt *rt, t_rgb *color)
{
	t_rgb ret;

	ret.r = (unsigned char)(color->r * rt->amb_int);
	ret.g = (unsigned char)(color->g * rt->amb_int);
	ret.b = (unsigned char)(color->b * rt->amb_int);
	return (ret);
}

t_rgb		ft_phong_diffuse(const t_rt *rt, t_vertex l, t_rgb *color)
{
	t_rgb	ret;
	double	dif_fact;

	dif_fact = fmax(0.0, ft_dot(ft_reverse_vector(l), rt->norm));
	ret.r = (unsigned char)(dif_fact * color->r);
	ret.g = (unsigned char)(dif_fact * color->g);
	ret.b = (unsigned char)(dif_fact * color->b);
	return (ret);
}

t_rgb		ft_phong_specular(const t_rt *rt, t_vertex l, t_vertex v)
{
	t_vertex	r;
	t_rgb		ret;
	double		spc_fact;

	r = ft_reflect_vector(l, rt->norm);
	r = ft_normalized_vector(r);
	spc_fact = pow(fmax(0.0, ft_dot(v, r)), rt->n);
	ret.r = (unsigned char)(255 * spc_fact);
	ret.g = (unsigned char)(255 * spc_fact);
	ret.b = (unsigned char)(255 * spc_fact);
	ret.opacity = 0;
	return (ret);
}

t_phong		ft_phong(const t_rt *rt, t_rgb *color, t_vertex light, t_vertex cam)
{
	t_vertex	l;
	t_vertex	v;
	t_phong		phong;

	v = ft_sub_vec(rt->inter, cam);
	v = ft_normalized_vector(v);
	l = ft_sub_vec(rt->inter, light);
	l = ft_normalized_vector(l);
	phong.amb = ft_phong_ambiand(rt, color);
	phong.dif = ft_phong_diffuse(rt, l, color);
	phong.spc = ft_phong_specular(rt, l, v);
	return (phong);
}
