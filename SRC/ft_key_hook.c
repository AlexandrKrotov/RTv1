/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:22:53 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/20 17:30:26 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_key_hook(int key, t_all *all)
{
	if (key == ESC)
		ft_exit();
	all->flags.redraw = TRUE;
	if (key == B)
		all->flags.aliasing = all->flags.aliasing == FALSE ? TRUE : FALSE;
	return (1);
}
