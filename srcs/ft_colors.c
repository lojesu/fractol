/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:01:45 by lojesu            #+#    #+#             */
/*   Updated: 2019/04/15 15:24:17 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_rgb_color(t_rgb *rgb, size_t count, t_val *val)
{
	if (val->mod == 10)
	{
		rgb->r = (count % 50) * 15;
		rgb->g = 0;
		rgb->b = 0;
	}
	else if (val->mod == 11)
	{
		rgb->r = 0;
		rgb->g = (count % 50) * 15;
		rgb->b = 0;
	}
	else if (val->mod == 12)
	{
		rgb->r = 0;
		rgb->g = 0;
		rgb->b = (count % 50) * 15;
	}
}

static void	ft_color_part_2(t_val *val, size_t count, t_rgb *rgb)
{
	if (val->mod == 3)
	{
		rgb->r = count % val->ite * 16;
		rgb->g = count % val->ite * 18;
		rgb->b = count % val->ite * 19;
	}
	else if (val->mod == 4)
	{
		rgb->r = count % 85 * 3;
		rgb->g = count % 85 * 3;
		rgb->b = count % 85 * 3;
	}
	else
		ft_rgb_color(rgb, count, val);
}

void		ft_color(t_win *win, t_val *val, size_t count, t_pos *pos)
{
	t_rgb	rgb;

	if (val->mod == 0)
	{
		rgb.r = (count % val->ite) * 15;
		rgb.g = (count % val->ite) * 15;
		rgb.b = (count % val->ite) * 15;
	}
	else if (val->mod == 1)
	{
		rgb.r = 255 - (count % 10) * 15;
		rgb.g = 255 - (count % 10) * 15;
		rgb.b = 255 - (count % 10) * 15;
	}
	else if (val->mod == 2)
	{
		rgb.r = count % val->ite * 12;
		rgb.g = count % val->ite * 8;
		rgb.b = count % val->ite * 9;
	}
	else
		ft_color_part_2(val, count, &rgb);
	ft_fill_pixel(win, pos->j, pos->i, rgb);
}
