/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math_part2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:27:53 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 16:27:54 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ft_dot(t_vertex a, t_vertex b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double		ft_get_magnitude(t_vertex a)
{
	double	ret;

	ret = fabs(sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
	return (ret);
}

double		ft_cos_vector(t_vertex u, t_vertex v)
{
	double	a;
	double	b;
	double	c;

	a = ft_dot(u, v);
	b = ft_dot(u, u);
	c = ft_dot(v, v);
	return (a / (b * c));
}

t_vertex	ft_cross_vector(t_vertex a, t_vertex b)
{
	t_vertex ret;

	ret.x = (a.y * b.z) - (a.z * b.y);
	ret.y = (a.z * b.x) - (a.x * b.z);
	ret.z = (a.x * b.y) - (a.y * b.x);
	return (ret);
}

t_vertex	ft_reverse_vector(t_vertex a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
	return (a);
}
