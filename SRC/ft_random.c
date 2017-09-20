/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:09:34 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 16:09:36 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_random_value(t_vertex *ver, t_rgb *color, int *size)
{
	ver->x = rand() % D_WIDTH - D_WIDTH / 2;
	ver->y = rand() % D_HEIGHT - D_HEIGHT / 2;
	ver->z = rand() % 1000;
	color->r = (UC)(rand() % 255);
	color->g = (UC)(rand() % 255);
	color->g = (UC)(rand() % 255);
	*size = rand() % 100 + 10;
}

void	ft_add_random_sphere(t_all *all)
{
	int			count;
	int			i;
	int			size;
	t_rgb		color;
	t_vertex	pos;

	count = rand() % 10 + 1;
	i = 0;
	while (i <= count)
	{
		ft_random_value(&pos, &color, &size);
		ft_add_sphere(all->scene,
					(t_vertex){pos.x, pos.y, pos.z},
					(t_rgb){color.r, color.g, color.b, 0}, size);
		i++;
	}
}
