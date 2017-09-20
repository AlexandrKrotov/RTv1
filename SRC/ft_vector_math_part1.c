/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:21:03 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 16:21:04 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vertex	ft_sum_vec(t_vertex a, t_vertex b)
{
	t_vertex	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vertex	ft_sub_vec(t_vertex a, t_vertex b)
{
	t_vertex	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_vertex	ft_normalized_vector(t_vertex a)
{
	t_vertex	ret;
	double		b;

	b = ft_get_magnitude(a);
	ret.x = a.x / b;
	ret.y = a.y / b;
	ret.z = a.z / b;
	return (ret);
}

t_vertex	ft_divide_vec_double(t_vertex a, double b)
{
	t_vertex	ret;

	ret.x = a.x / b;
	ret.y = a.y / b;
	ret.z = a.z / b;
	return (ret);
}

t_vertex	ft_m_v_d(t_vertex a, double b)
{
	t_vertex	ret;

	ret.x = a.x * b;
	ret.y = a.y * b;
	ret.z = a.z * b;
	return (ret);
}
