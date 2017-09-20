/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_light_spot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:18:27 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 14:18:28 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vertex	*ft_crete_light_node(t_vertex pos)
{
	t_vertex *ptr;

	ptr = malloc(sizeof(t_vertex));
	*ptr = (t_vertex)pos;
	return (ptr);
}

void		ft_add_light_lst(t_light *light, t_vertex pos, double power)
{
	t_light *ptr;

	if (light->o == NULL)
	{
		light->o = ft_crete_light_node(pos);
		light->power = power;
		light->next = NULL;
	}
	else
	{
		ptr = light;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(t_light));
		ptr = ptr->next;
		ptr->o = ft_crete_light_node(pos);
		ptr->power = power;
		ptr->next = NULL;
	}
}
