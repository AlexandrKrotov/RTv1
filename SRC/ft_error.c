/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:13:29 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/20 17:06:54 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_putstr("Wrong scene name!\n");
		ft_putstr("Usage ./RTv1 \"scene\"\n");
		ft_putstr("Scene list: \n\t1)sphere\n\t2)plane\n\t3)cone\n");
		ft_putstr("\t4)cylinder\n\t5)scene1\n\t6)random\n\t7)multilight\n");
		ft_putstr("example: \"./RTv1 sphere\"\n");
		exit(error);
	}
	if (error == 11)
	{
		ft_putstr("Code error: 11. Wrong number of quantity for ft_blur.\n");
		exit(error);
	}
}
