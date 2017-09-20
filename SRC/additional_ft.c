/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 18:17:17 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 18:17:19 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_objs	*ft_find_empty(t_objs *scene, t_objs *ptr)
{
	if (scene->obj == NULL)
		ptr = scene;
	else
	{
		ptr = scene;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(t_objs));
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (ptr);
}

void	ft_bzero_rgb_arr(t_rgb *color, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		color[i] = (t_rgb){0, 0, 0, 0};
		i++;
	}
}

void	ft_ptr_to_rgb(char *ptr, t_rgb *rgb)
{
	rgb->b = (unsigned char)(256 + *ptr++);
	rgb->g = (unsigned char)(256 + *ptr++);
	rgb->r = (unsigned char)(256 + *ptr);
	rgb->opacity = 0;
}
