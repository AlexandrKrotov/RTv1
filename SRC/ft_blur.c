/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:19:17 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 14:19:19 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_set_color(const char *data_in, t_rgb *color, int x, int y)
{
	char	*ptr;

	ptr = (char *)(data_in + y * SIZE_LINE + x * 4);
	ft_ptr_to_rgb(ptr, color);
	return (1);
}

int		init_color_arr(const char *data_in, const t_cord *xy, t_rgb *color)
{
	int		size;

	size = 0;
	size += ft_set_color(data_in, &color[0], xy->x, xy->y);
	if (xy->y - 1 >= 0)
		size += ft_set_color(data_in, &color[1], xy->x, xy->y);
	if (xy->y - 1 >= 0 && xy->x + 1 < D_WIDTH)
		size += ft_set_color(data_in, &color[2], xy->x + 1, xy->y - 1);
	if (xy->x + 1 < D_WIDTH)
		size += ft_set_color(data_in, &color[3], xy->x + 1, xy->y);
	if (xy->y + 1 < D_HEIGHT && xy->x + 1 < D_WIDTH)
		size += ft_set_color(data_in, &color[4], xy->x + 1, xy->y + 1);
	if (xy->y + 1 < D_HEIGHT)
		size += ft_set_color(data_in, &color[5], xy->x, xy->y + 1);
	if (xy->y + 1 < D_HEIGHT && xy->x - 1 >= 0)
		size += ft_set_color(data_in, &color[6], xy->x - 1, xy->y + 1);
	if (xy->x - 1 >= 0)
		size += ft_set_color(data_in, &color[7], xy->x - 1, xy->y);
	if (xy->y - 1 >= 0 && xy->x - 1 >= 0)
		size += ft_set_color(data_in, &color[8], xy->x - 1, xy->y - 1);
	return (size);
}

void	calc_mid_color(char *data_o, t_rgb *color, int size, const t_cord *xy)
{
	t_irgb	mid;
	int		i;
	char	*ptr;

	mid = (t_irgb){0, 0, 0};
	i = 0;
	while (i <= 8)
	{
		mid.r += color[i].r;
		mid.g += color[i].g;
		mid.b += color[i].b;
		i++;
	}
	mid.r /= size;
	mid.g /= size;
	mid.b /= size;
	ptr = (data_o + xy->y * SIZE_LINE + xy->x * 4);
	ptr[0] = (char)mid.b;
	ptr[1] = (char)mid.g;
	ptr[2] = (char)mid.r;
}

void	ft_one_loop(const char *data_in, char *data_out)
{
	t_cord	*xy;
	t_rgb	color[8];
	int		size;

	xy = malloc(sizeof(t_cord));
	xy->y = 0;
	while (xy->y < D_HEIGHT)
	{
		xy->x = 0;
		while (xy->x < D_WIDTH)
		{
			ft_bzero_rgb_arr(color, 8);
			size = init_color_arr(data_in, xy, color);
			calc_mid_color(data_out, color, size, xy);
			xy->x++;
		}
		xy->y++;
	}
	free(xy);
}

void	ft_blur(char *data_in, int n)
{
	char	*data_out;

	data_out = malloc(sizeof(char) * D_HEIGHT * SIZE_LINE);
	if (n % 2 != 0)
		ft_error(11);
	while (n > 0)
	{
		ft_one_loop(data_in, data_out);
		ft_memcpy(data_in, data_out, (size_t)(D_HEIGHT * SIZE_LINE));
		n -= 2;
	}
	free(data_out);
}
