/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math_part3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:28:00 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 16:28:01 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vertex	ft_reflect_vector(t_vertex a, t_vertex b)
{
	t_vertex ret;

	ret = ft_m_v_d(b, 2 * (ft_dot(a, b)));
	ret = ft_sub_vec(ret, a);
	return (ret);
}
