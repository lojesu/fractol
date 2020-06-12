/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:58:39 by lojesu            #+#    #+#             */
/*   Updated: 2019/05/02 17:23:47 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_rgb_to_char(t_rgb *rgb)
{
	if (rgb->r > 127)
		rgb->r = rgb->r - 256;
	if (rgb->g > 127)
		rgb->g = rgb->g - 256;
	if (rgb->r > 127)
		rgb->b = rgb->b - 256;
}

void	ft_fill_pixel(t_win *win, int x, int y, t_rgb rgb)
{
	int	pix_x;
	int	pix_y;
	int	pix_colors;
	int	i;

	i = 0;
	pix_x = win->endian + 4 * x;
	pix_y = win->endian + 4 * WIDTH * y;
	pix_colors = pix_x + pix_y;
	ft_rgb_to_char(&rgb);
	while (i < 4)
	{
		if (i == 0)
			win->img_str[pix_colors] = rgb.b;
		if (i == 1)
			win->img_str[pix_colors] = rgb.g;
		if (i == 2)
			win->img_str[pix_colors] = rgb.r;
		pix_colors++;
		i++;
	}
}
