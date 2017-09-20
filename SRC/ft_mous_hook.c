/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mous_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:46:47 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/20 17:31:35 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_mouse_cord(int x, int y, t_all *all)
{
	all->x = x;
	all->y = y;
	return (y);
}

int		ft_mouse_hook(int key, int x, int y, t_all *all)
{
	x = y;
	y = x;
	key = 0;
	all->flags.redraw = TRUE;
	return (y);
}
